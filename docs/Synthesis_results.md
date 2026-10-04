# Synthesis Results: RTL to GDSII on SKY130

## Contents

- [Flow and tools](#flow-and-tools)
- [Setup decisions](#setup-decisions)
- [Synthesis compatibility bugs](#the-synthesis-compatibility-debugging)
  - [1. `import package::*` in a module header](#1-import-package-in-a-module-header)
  - [2. `$readmemh` expecting a file that doesn't exist at synthesis time](#2-readmemh-expecting-a-file-that-doesnt-exist-at-synthesis-time)
  - [3. A real latch in `data_mem.sv`](#3-a-latch-inference-bug-in-data_memsv)
  - [4. The async reset bug](#4-the-async-reset-bug)
  - [5. `initial` blocks are not hardware](#5-initial-blocks-are-not-hardware)
- [The first result was wrong](#the-first-result-was-wrong)
  - [The fix: synthesize the core without its memories](#the-fix-synthesize-the-core-without-its-memories)
  - [Two more bugs found while restructuring](#two-more-bugs-found-while-restructuring)
- [The first real result](#the-first-real-synthesis-result)
- [Finding the clock limit](#finding-the-clock-limit)
- [Final run (16 ns)](#final-run-16-ns)
- [What these results don't show](#what-these-results-dont-show)
- [What I'd do next](#what-id-do-next)

This document covers what happened when I took the pipelined CPU from
a simulation to a physically synthesized layout. I'm writing this mostly in
the order I did the work, including the parts that went wrong. The first result 
i got was wrong, and working out why taught me more than the final numbers did.
 
## Flow and tools
 
I don't have access to a commercial EDA license or an FPGA board, so I pushed the 
processor through an open-source ASIC flow instead. SKY130 is SkyWater's 130nm process, 
released as an open PDK. OpenLane wraps the tools for each stage (Yosys for synthesis, 
OpenROAD for placement and routing, Magic and KLayout for physical verification) into 
one pipeline, so I wasn't stitching tools together by hand.

Everything here comes from OpenLane 1.0.2 with the `sky130_fd_sc_hd` cell library. 
Timing numbers are from the flow's own signoff timing check at the typical corner, 
unless I've mentioned otherwise.

## Setup decisions

- **Die size:** My first runs used a fixed, oversized 1000 x 1000 um die
(`FP_SIZING: absolute`) bcz I didnt yet know how much area the design would need, and
I wanted placement and routing to have enough room to succeed. In later runs, I 
switched to relative sizing with a 35% utilization target (`FP_SIZING: relative`, `FP_CORE_UTIL: 35`),
letting OpenLane determine the die dimensions based on the design size. Since the 
final die area is therefore tied to the utilization setting, I use the standard-cell 
count as the more direct indicator of how large the actual logic is.

- **`PL_TARGET_DENSITY: 0.45`**: how packed placement tries to be. Too high 
could cause the routing to fail straight up but too low wastes area. 0.45 is a 
common starting point, and I didn't have a reason to move it.

- **`SYNTH_STRATEGY: AREA 0`**: optimized for area first. I wanted to see the 
design synthesize correctly before worrying abou the speed.

- **`ROUTING_CORES: 2`**: detailed routing of the full core ran out of memory twice 
on my 8 GB laptop, and each time it froze the whole WSL machine at the same step. I
eventually limited routing to 2 threads, gave WSL 5 GB of RAM plus 16 GB of swap, 
and closed everything else while the flow was running. It makes routing slower, 
but the trade-off is that the run actually finishes. A full run now takes about an hour.

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
 
### 3. A latch inference bug in `data_mem.sv`
 
This one was the first synthesis issue that was an actual hardware bug, not just a 
tooling problem. My read logic had two local signals, `byte_val` and `half_val`, 
that were only assigned inside certain branches of a `case` statement, with no default 
value at the top of the block. <br> 
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

### 5. `initial` blocks are not hardware
 
Three of my modules were using `initial` blocks to start in a known 
state: the register file, the branch predictor's valid bits, and the instruction 
cache's valid bits. The problem is that an `initial` block only exists in simulation.
It can make everything start cleanly in simulation, but a real chip doesn't magically 
run that code when it powers on. The hardware needs an actual reset mechanism if those
values have to start in a known state. For the predictor and the cache I added a proper
reset driven by the reset signal.<br>
A register file is a little different. It normally has no reset, the software is expected
to write a reg before using its value, and x0 is hardwired to zero anyway. So instead of 
adding unnecessary reset hardware, i kept the `inital` bloack only for simulation 
and wrapped it in the same `SYNTHESIS` guard so Yosys ignores it while building the HW.
 
## The first result was wrong

My first successful OpenLane run looked surprisingly good: 192.7 MHz at an 8 ns target, 
with zero DRC and timing violations. Later, reading `metrics.csv` for something else, 
I looked at the cell count properly. The design had about **98,600 cells in total**, but 
roughly **68,000 were decap cells**, **14,000 were filler** and **14,000 were well taps**, and none 
of those are logic. That left about **2,600 logic cells** for a CPU that includes a 32-bit 
multiplier and divider which did not make sense. The timing report also showed 68 output
pins driven by constant tie cells, which was another warning sign.

The problem came from my own fix from bug #2. I had disabled the `$readmemh` call during 
synthesis so that Yosys would not try to interpret the simulation-only memory initialization. 
However, this meant that the instruction memory contained only zeros during synthesis. 
To Yosys, every instruction the CPU could ever fetch was the constant zero, which decodes 
as an instruction that never writes a register, never touches memory and never branches.<br>
Because synthesis removes logic that can never affect the outputs, Yosys removed almost 
the entire CPU: the decoder, ALU, multiplier, divider, register file, data memory, 
forwarding and predictor training. What remained was roughly the program counter, its 
adder and the cache tag logic. The 192.7 MHz was the speed of that leftover. Every 
check in the flow passed, because the flow can only check the circuit it is given.
 
I removed the result from the reported performance numbers. The files from that run are 
in `docs/synthesis_data/1_invalid_cpu_optimized_away` as evidence of the problem.
 
### The fix: synthesize the core without its memories
 
A real processor core normally does not synthesize its memories as ordinary standard-cell 
logic. Instruction and data memories would typically be implemented as SRAM macros, which 
are separate physical blocks. Which is why I split the design into:
- `riscv_core.sv`: the CPU with an instruction port and a data port
- `riscv_pipeline.sv`: a thin wrapper which connects the core to behavioral `instr_mem` 
and `data_mem` for simulation. 

Every testbench still uses the wrapper, so verification required only a few updates to 
hierarchical signal paths. OpenLane synthesizes `riscv_core.sv` alone. Instructions now 
arrive on real input pins, so nothing can be constant-folded. 
The instruction cache was also modified so that its refill data comes through a port 
rather than directly accessing an internal behavioral memory.

### Two more bugs found while restructuring
 
While separating the core from its memories, I found two additional bugs simply by reading through the RTL. Neither had been exposed by my existing simulation programs.
 
- **AUIPC used the wrong operand:** AUIPC should calculate `PC + immediate`, but 
the ALU's first operand was selected by a condition that matched JAL, so it computed
`rs1 + immediate`. None of my programs used AUIPC.
- **Predictor aliasing could execute the wrong code:** The predictor has no tags, so
an instruction 256 bytes away from a trained branch could use the same table entry. The
predictor could then incorrectly predict that this unrelated instruction should be 'taken' 
and send the processor to the old branch's target and nothing ever corrected it, because
mispredictions were only checked for real branches. 
I fixed this by carrying the predicted target alongside each instruction through the 
pipeline. The EX stage now detects three cases: a wrong branch direction, a wrong predicted 
target, or a 'taken' prediction for an instruction that is not a branch.

I added `test_alias.s` and two AUIPC lines in `test_alu.s`, and both fail on the old RTL and pass on the new.
 
## The first real synthesis result
 
With the CPU actually present, the first complete run (100 ns target) looked very different from the earlier one.
 
| | Value |
|---|---|
| Logic cells after synthesis | 46,516 |
| Die | 1148 x 1148 um (1.36 mm2) |
| Worst path | 82.43 ns |
| Result | failed setup at 100 ns, worst slack -2.68 ns |
| DRC / LVS | 0 / 0 |
 
The worst path ended at the `dbg_mispredict` output pin. I did not inspect 
that path stage by stage, but the structure points at the combinational divider. 
A 32-bit divide built as one block of logic is dozens of subtractions in a row. 
My branch decision also used the ALU's zero flag and result bit, which sit behind 
the ALU's whole output mux, so timing analysis counted the divider as part of the 
path to that pin. The ALU was also carrying three separate 32 x 32 multipliers.
 
Made four changes:
 
1. **A multi-cycle divider** (`divider.sv`): It does restoring division one 
bit per clock, so a divide takes 33 cycles and the pipeline holds the divide in 
EX while it runs. I tested it with 13 directed cases (signs, divide by zero, and 
the -2^31 / -1 overflow case the spec defines) plus 2,000 random cases checked 
against a reference function, and it always takes the same number of cycles.

2. **One shared multiplier:** A single 33 x 33 signed multiplier now serves all 
four multiply instructions, with each operand sign-extended or zero-extended 
depending on the instruction.

3. **A dedicated branch comparator.** Branches no longer depend on the ALU's final
result. The branch operands are compared directly using dedicated comparison logic. 
This removes unnecessary ALU logic from the branch decision path.

4. **A dedicated JALR adder.** The jump target gets its own small adder.

The cost is that a divide now takes 33 cycles instead of one. I did not measure what 
that does to any program, since none of my test programs divides much. Because I made 
all four changes at once, I cannot say how much of the result comes from each.
 
| | Before (100 ns run) | After (16 ns run) |
|---|---|---|
| Logic cells after synthesis | 46,516 | 30,475 |
| Non-filler cells after placement and clock tree | 51,781 | 35,886 |
| Die | 1148 x 1148 um | 971 x 971 um |
| Worst path | 82.43 ns | 11.15 ns |

I expect most of the 16,000-cell drop to come from the divider and the multiplier sharing 
and most of the timing improvement to come from the divider and the comparator together, 
but I didn't test them separately.
 
## Finding the clock limit
 
I didn't want to report a frequency I hadn't tested, so I tightened the clock and reran 
the full flow each time. I started at 50 ns, which passed with a lot of room. For the 
next attempt I picked 14 ns from the worst-path arrival times of the earlier runs. 
It missed by 0.35 ns, and 16 ns passed.
 
| Target period | Result | Worst slack | Worst endpoint |
|---|---|---|---|
| 50 ns | pass | +27.84 ns | `dbg_mispredict` pin |
| 14 ns | **fail** | -0.35 ns | `dbg_mispredict` pin |
| 16 ns | pass | +1.40 ns | `dbg_mispredict` pin |
 
*A 20 ns run in between also passed (+4.64 ns). Its files are not in the repo.*
 
**Verified result: the core passes OpenLane's signoff timing check at 16 ns (62.5 MHz) at the typical corner, and fails at 14 ns.**
 
In all three runs the worst endpoint is the `dbg_mispredict` output pin and not a 
flip-flop. By default OpenLane reserves 20% of the clock period as outside delay 
on every output pin. For the 14 ns run, that means: **$14 * 20\% = 2.8 ns$**, which can be 
seen directly from the output external delay in the 14 ns report as well. <br>
The flip-flop endpoints that follow it in the 14 ns report all pass with at least 
0.61 ns of slack. `dbg_mispredict` is a debug signal for my testbench and a real chip 
wouldn't have it, so the core's internal limit is probably a little faster than 
14 to 16 ns suggests. I haven't verified that. Testing it would mean registering the 
debug outputs, which is a small RTL change plus another round of verification.
 
## Final run (16 ns)
 
| Metric | Value |
|---|---|
| Process | SkyWater SKY130 (`sky130_fd_sc_hd`) |
| Worst slack (typical corner) | +1.40 ns |
| Logic cells after synthesis | 30,475 |
| Total cells, including decap, tap and fill | 115,329 |
| Die | 971 x 971 um (0.975 mm2) |
| DRC violations | 0 |
| LVS errors | 0 |
| KLayout vs. Magic layout difference | none |
| Antenna violations | 131 pin, 109 net |
 
## What these results don't show
 
- **Two timing reports disagreed:** At 14 ns, OpenLane's main signoff check says 
the `dbg_mispredict` pin misses timing by 0.35 ns. Other reports from the same run 
say the same pin passes with 4.28 ns to spare. I couldn't find out why. I went with 
the main check, since it's the one that decides pass or fail in the flow, which is 
also why I only claim timing at the typical corner.

- **Antenna violations remain:** The signoff check finds 131 pin and 109 net antenna 
violations after detailed routing, and 123 and 95 in the earlier 100 ns run. A real 
tape-out would need these fixed. I haven't tried OpenLane's heuristic diode insertion. 
In other people's reports it trades antenna violations for many more fanout violations.

- **Max slew and max fanout warnings:** The flow warns about both in the final design. 
I didn't analyze them for this design. In the earlier invalid run, 23 of 25 fanout 
violations were clock-tree buffers.

- **No power result:** OpenLane's power report shows hundredths of a microwatt for 
this design, which isn't believable, because the flow has no real switching activity 
to work from. I left power out.

- **No memories in the numbers:** The instruction and data memories are behavioral 
models outside the synthesized core, so none of the area or timing includes memory.

## What I'd do next
 
- Register the debug outputs and rerun, to separate the core's internal limit from 
the pin timing budget.
- Track down the disagreement between the two timing analyses by running the 
same extracted parasitics through OpenSTA by hand with a single constraint file.
- Try diode insertion and report the antenna and fanout numbers side by side.
