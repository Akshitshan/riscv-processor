# Synthesis runs

Runs are numbered in the order they happened.

| Folder | Design | Clock target | Outcome |
|---|---|---|---|
| `1_invalid_cpu_optimized_away` | Instruction memory inside the synthesized design | 8 ns | **Not a valid result.** The memory was empty at synthesis, so the tool removed nearly all the logic and about 2,600 logic cells survived. Kept as evidence of the problem. |
| `2_baseline_single_cycle_divider_100ns_FAILED` | Core separated from its memories, single-cycle divider | 100 ns | Failed setup, worst slack -2.68 ns at the typical corner. 46,516 logic cells, worst path 82.43 ns. |
| `3_multicycle_divider_50ns_PASSED` | Multi-cycle divider, shared multiplier, dedicated branch comparator and JALR adder | 50 ns | No setup or hold violations at the typical corner, worst slack +27.84 ns. 30,475 logic cells. |
| `4_multicycle_divider_14ns_FAILED` | Same RTL | 14 ns | Misses by 0.35 ns at the typical corner. The only failing endpoint is the debug output pin `dbg_mispredict`. |
| `5_multicycle_divider_16ns_PASSED_FINAL` | Same RTL | 16 ns | No setup or hold violations at the typical corner, worst slack +1.40 ns. 0 DRC, 0 LVS, 131 pin and 109 net antenna violations. Includes the layout (`riscv_core.gds.gz`). |

All runs use OpenLane 1.0.2 and `sky130_fd_sc_hd`. The slack numbers 
come from the flow's signoff timing check at the typical corner (`timing_max.rpt.gz`).
