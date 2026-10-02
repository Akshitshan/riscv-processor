# Synthesis Results: RTL to GDSII on SKY130
 
This document covers what happened when I took the pipelined CPU from
being just a simulation to a physically synthesizable chip layout. I'm
writing this mostly in the order I actually did the work, including the
parts that didn't go smoothly the first time, because I think the debugging
is honestly more interesting than the final numbers.
 
## SKY130
 
I don't have access to a commercial EDA license or an FPGA board so i decided
to take a different route: build the processor and push it through a real open-source ASIC flow.

SKY130 is SkyWater Technology's actual 130nm process, released as an actual open-source PDK.
OpenLane wraps the real open-source tools that do each stage of the flow
(Yosys for synthesis, OpenROAD for placement and routing, Magic and KLayout for 
physical verification) into one pipeline so I wasn't manually stitching tools together.

## Setup decisions
 
A few choices in `config.json` i want to clarify:
 
- **`FP_SIZING: absolute`, `DIE_AREA: 0 0 1000 1000`**: I picked a
generous, oversized die area for the first run on purpose. I didn't
know yet how much space the design actually needed, and I'd rather
give placement and routing room to succeed on the first real attempt
than fight auto- sizing guesses. The design ended up settling at about
988 × 976 um comfortably inside that box.
- **`PL_TARGET_DENSITY: 0.45`**: how packed placement tries to be.
Too high could cause the routing to fail straight up but too low wastes area. 
0.45 is a conservative, widely-used starting point, and I didn't have a
reason to deviate from it for a first real design.
- **`SYNTH_STRATEGY: AREA 0`**: I optimized for area over raw speed for the 
first pass. I wanted to see the design synthesize correctly before I started 
asking it to also be fast.

## The synthesis compatibility debugging

Simulation and synthesis are doing two different jobs. Verilator just needs to run my 
design fast and tell me if the behaviour is right. Yosys on the other hand needs to turn 
my SV into actual logic gates that could exist on silicon and its a lot pickier about 
exactly how that SV is written. I hit multiple issues getting through synthesis that 
never once showed up as a failure in the simulation. I think this list is actually the 
most useful part of this whole document for anyone reading it technically, so I'll try 
to go through all of them.
 
### 1. `import package::*` in a module header
 
Yosys's SV frontend doesn't correctly parse an import statement placed between a
module's name and its port list. Verilator has no trouble with such syntax at all.

```systemverilog
module alu
    import riscv_pkg::*;     // this placement was breaking synthesis
(
    input logic [31:0] operand_a,
```

I fixed it by just not importing the package at all. Instead of using 
`import riscv_pkg::*`, I reference each constant directly with its full path, like `riscv_pkg::ALU_ADD`. 
It's a bit more typing, but it dodges the whole import- placement issue since there's nothing left to place.

While at it, I also swapped the `typedef enum` types in `riscv_pkg.sv` for plain `localparam` constants. 
That wasn't actually necessary for this particular bug. I only found that out a few 
bugs later (see #4), but it's a simpler way to share these values across files, so I kept the change.

### 2. `$readmemh` expecting a file that doesn't exist at synthesis time
 
`instr_mem.sv` loads the compiled test program from `program.hex` when the simulation 
starts. The problem was that Yosys was also trying to process that same file during 
synthesis and failed because there was no program to load. Which makes sense once you 
think about it, synthesis doesn't care what instructions are sitting in the memory. It
just needs to know that the memory exists as hardware. I fixed it by wrapping the load 
in a preprocessor guard so it only runs during simulation and is ignored during synthesis.
 
```systemverilog
`ifndef SYNTHESIS
    $readmemh("program.hex", mem);
`endif
```
 
Verilator never defines `SYNTHESIS`, so every test I had already written kept working exactly as before.
 
### 3. A latch- inference bug in `data_mem.sv`
 
This one's worth calling out because it was the first synthesis issue 
that was an actual hardware bug, not just a tooling problem. My read logic had 
two local signals, `byte_val` and `half_val`, that were only assigned inside certain 
branches of a `case` statement, with no default value at the top of the block. <br> 
Verilator had actually been warning me about this since Phase 2 in the form of
a `CASEINCOMPLETE` warning. I ignored it because the simulator never produced a wrong result.
Yosys wasn't willing to let it slide though: a signal with no defined value on every 
path turns into a **latch** in real hardware. Basically unwanted hardware that holds 
its previous value.<br> 
Fixed it by giving both signals a default at the top of the block, just like the 
signal right next to them already had.
 
### 4. The async reset bug
 
This was the hardest one, and I went down a couple of wrong paths 
before I found the actual cause.

The error was `Multiple edge sensitive events found for this signal!`,
thrown while Yosys was building the flip-flops for two of my four
pipeline register modules (`if_id_reg`, `id_ex_reg`), while the other
two (`ex_mem_reg`, `mem_wb_reg`) synthesized fine every time.

My first theory was that it was related to a custom enum type one of
the failing modules used. Removed the enum. Same error, same exact
signal. So that was wrong.

My second theory was a duplicate signal name conflicting across two
modules in the same file (`if_id_reg` and `id_ex_reg` both have a
`pc_out` port). Renamed it. Same error, just moved to a
different signal. Wrong again.

What actually helped was going back to the Yosys log and paying attention
to something I had been skipping over. There was a step called `PROC_ARST`
("detect async resets in processes"), which is supposed to print the reset 
signal it found. On every failing run, it printed nothing. On the two modules 
that worked fine, it printed `Found async reset \rst`.
 
The difference turned out to be pretty small. The working ones used a plain `if (rst)` 
for the reset while the failing ones used `if (rst || flush)`. Yosys' reset- detection 
pass expects the reset condition to be the reset signal by itself. Once flush was OR'd
into the condition, it couldn't tell which part was supposed to be the actual async 
reset, so it gave up and left two unresolved clock- edge events for the next pass to deal with.
 
The fix was splitting the condition into two separate branches:
 
```systemverilog
always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
        // real asynchronous rst alone
        .
        .
    end else if (flush) begin
        // ordinary synchronous control signal, not a reset
        .
        .
```

### 5. Max fanout (investigated but not chased further)
 
The final clean synthesis run reported 25 max- fanout violations
meaning a single gate was driving more downstream inputs than the configured
limit of 10. I went through the report: 23 of them are specifically named
clock buffers (`clkbuf_*`, `rebuffer*`, `split*`). These are automatically 
generated as part of the clock-tree infrastructure, so having them drive a large
number of endpoints is normal and intentional.<br>
The remaining 2 were unnamed internal nets sitting directly between named clock
buffers in the severity-sorted violation list. That makes it pretty strong
circumstantial evidence that they are part of the same clock infrastructure, although i cant
say that with complete certainty since optimization removed their original names.<br>
Most importantly I could not find a single violation that traced back to a signal I
actually wrote in the RTL. WNS and TNS also stayed at 0 across every run, so none of these violations
affected the designs timing or functional correctness.
 
## Final results
 
| Metric | Value |
|---|---|
| Process | SkyWater SKY130 (`sky130_fd_sc_hd`) |
| DRC violations | 0 |
| LVS errors | 0 |
| KLayout vs. Magic GDS diff | 0 |
| Total cells | 98,595 |
| Core area | ~0.965 mm² (988.54 × 976.48 µm) |
| Max fanout violations | 25 (23 confirmed clock tree, 2 likely) |
 
## Finding the real maximum clock frequency
 
I didn't want to report a frequency I hadn't actually tested. The
first clean run used a deliberately loose 20ns clock period (50 MHz)
as a safe first target. It passed with a lot of margin (critical path
only 5.77ns), which told me the real limit was somewhere well above
50 MHz but not exactly where.
 
Found the real number by tightening the clock period and re-running
the full flow at each step, treating it as a search rather than a
guess:
 
| Target clock period | Result | Critical path achieved |
|---|---|---|
| 20 ns (50 MHz) | Pass | 5.77 ns |
| 8 ns (125 MHz) | Pass | 5.19 ns |
| 4 ns (250 MHz) | Fail: setup violations, WNS = −1.03 ns | 5.13 ns |
 
The critical path barely moved between the 8ns and 4ns attempts (5.19
to 5.13), even though the tool was clearly working harder to try and hit 4ns.
That convergence is what tells me ~5.1–5.2ns is a real physical floor for this design on this process.
 
**Verified maximum frequency: ~192.7 MHz** (1/5.19ns), based on the
8ns run (the fastest clock period that still closed timing cleanly).
 