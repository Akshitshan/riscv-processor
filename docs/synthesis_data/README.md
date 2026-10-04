# Synthesis runs

Runs are numbered in the order they happened.

| Folder | Design | Clock target | Outcome |
|---|---|---|---|
| `1_invalid_cpu_optimized_away` | Instruction memory inside the synthesized design | 8 ns, 4 ns | **Not a valid result.** The memory was empty at synthesis, so the tool removed nearly all logic (roughly 2,600 logic cells survived). Kept as evidence of the problem. |
| `2_baseline_single_cycle_divider_100ns_FAILED` | Core separated from its memories, single-cycle divider | 100 ns | Failed timing, worst slack -6.65 ns. About 46,500 logic cells, worst path 82 ns. |
| `3_multicycle_divider_50ns_PASSED` | Multi-cycle divider, shared multiplier, dedicated branch comparator | 50 ns | Passed at all corners. 30,475 logic cells, 0 DRC, 0 LVS. 144 pin / 106 net antenna violations remain. |

See [Synthesis_results.md](../Synthesis_results.md) for more information