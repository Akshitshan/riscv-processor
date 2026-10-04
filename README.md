# RV32IM Pipelined Processor

A 5-stage pipelined RISC-V CPU (RV32IM), built from scratch in SystemVerilog,
with branch prediction, instruction caching and a multi-cycle divider. I verified it
against an independent python ISA model and took the design through a complete open-source
ASIC flow using the SKY130 process.

- Passes OpenLane's signoff timing check at **16 ns (62.5 MHz)** at the 
typical corner, and misses by 0.35 ns at 14 ns <br>
- **30,475 logic cells, 971 x 971 um die, 0 DRC and 0 LVS violations** <br>
- **186 register checks** across 6 test programs, all matching the Python reference model <br>
- **94.9%** branch prediction accuracy and **86.6%** instruction cache hit rate, 
measured on one small loop benchmark

[Architecture](#architecture) | [Verification](#verification) |
[Synthesis Results](docs/Synthesis_results.md) | 
[Bugs Found](docs/Synthesis_results.md#the-synthesis-compatibility-debugging) |
[Limitations](#limitations) | [Running it](#running-it)

## Architecture

![pipeline architecture](docs/Images/Pipeline_diagram.png)

A 5-stage pipeline (IF - ID - EX - MEM - WB). The CPU itself is `riscv_core.sv` and
has no memories inside of it. The instruction and data memories are behavioral models 
connected by `riscv_pipeline.sv`, a wrapper used for simulation.

- **Branch prediction** (`branch_predictor.sv`): a 2-bit saturating counter
predictor with a 64-entry BHT/BTB and no tags. The prediction takes place in the IF 
stage while the real outcome is found in the EX stage which trains the predictor 
and corrects the pipeline on a misprediction.
- **Instruction caching** (`icache.sv`): a direct-mapped cache with 16 one-word lines,
modeling a realistic main memory with a 5 cycle miss penalty and reusing the existing hazard-stall
mechanism instead of adding a new logic.
- **Multi-cycle divider** (`divider.sv`): one quotient bit per clock, 33 cycles per divide, 
with the pipeline holding the divide in EX. It replaced a single-cycle divider that made up 
about half of the ALU (see the synthesis results).

The branch predictor's prediction and target travel with each instruction from IF to EX so
they can be checked against the real outcome.

## Physical Layout

The final 16 ns run in KLayout. This is the layout OpenLane produced for `riscv_core.sv`.

![Full chip layout](docs/Images/KLayout.png)

Zoomed in, the uniform looking pattern above resolves into individual
standard cells.Each small rectangle is one logic gate (AND, flip-flop,
buffer, etc.) from the SKY130 standard cell library, arranged in rows.

![Zoomed cell detail](docs/Images/KLayout_zoomed.png)

Full synthesis methodology, the frequency sweep, and every bug hit along
the way are written up in [docs/Synthesis_results.md](docs/Synthesis_results.md).

## Verification

Correctness is checked against an independent software model of the CPU,
written separately in Python, that computes what every instruction 'should'
produce directly from the RISC-V specification. The RTL and the Python model 
were built independently of each other, so their agreement means its working perfectly.

- **`sw/rv32im_sim.py`**: a complete RV32IM behavioral model in Python,
used as the golden reference for every test
- **6 targeted test programs** (`sw/tests/`): ALU, pipeline hazards, branches, 
load/store, M-extension, and branch predictor aliasing, each for one of the categories
- **`sim/run_regression.py`**: compiles each test, runs it through both the RTL
(Verilator) and the Python model, and compares every register. **155/155 checks, all passing**
- **Isolated unit testbenches**: individual modules tested standalone, 
with no clock or pipeline dependency.
- **2 performance benchmarks** (`tb_branch_bench.sv` and `tb_icache_bench.sv`): measure
branch prediction accuracy and cache hit rate on a 20-iteration loop.

## Synthesis
 
The first synthesis result I got was wrong: the tool had removed almost the whole CPU, 
because the instruction memory inside the design was empty at synthesis time. Moving 
the memories out of the core fixed that, and the numbers below come from the corrected 
flow. The full account, including synthesis-only bugs that simulation never caught, 
is in [docs/Synthesis_results.md](docs/Synthesis_results.md).

| | First complete run (100 ns target) | Final (16 ns target) |
|---|---|---|
| Logic cells | 46,516 | 30,475 |
| Die | 1148 x 1148 um | 971 x 971 um |
| Worst path | 82.43 ns | 11.15 ns |
| Timing | failed at 100 ns | passes at 16 ns, fails at 14 ns |
 
The worst-slack endpoint in every run is a debug output pin, so the core's internal limit is probably somewhat faster than 16 ns. I did not verify that.

## Limitations
 
- No data cache. The instruction cache is direct-mapped with one-word lines, and its 5-cycle miss penalty is a model and not a real memory
- The branch predictor has no tags, so branches 256 bytes apart can share an entry. The pipeline corrects the resulting wrong guesses, but they cost cycles
- ECALL, EBREAK and the CSR instructions are not implemented and are treated as NOPs
- 131 pin and 109 net antenna violations remain after routing, so the layout is not tape-out clean
- The memories are behavioral models outside the synthesized core, and there is no power analysis
- Two timing analyses in the 14 ns run disagreed and I couldn't explain why. Details are in the synthesis results

## Running it
 
You need Verilator, the RISC-V GNU toolchain (`riscv64-unknown-elf-gcc`) and Python 3. From `sim/`:

```bash
make pipeline        # basic pipeline test
make regress         # full regression against the Python model
make unit-divider    # divider unit test (also unit-alu)
make branch-bench    # branch predictor benchmark
make icache-bench    # instruction cache benchmark
```

The synthesis files are in `docs/synthesis_data/`
