# ============================================================
#  test_loop.s — A real loop, to demonstrate branch prediction
#
#  WHAT THIS PROGRAM DOES:
#  Counts from 0 to 20 using a loop. In plain C this would be:
#     for (int i = 0; i < 20; i++) { }
#
#  WHY THIS IS THE PERFECT TEST FOR A BRANCH PREDICTOR:
#  The loop body executes 20 times. Each time, it hits the
#  same BLT (branch-less-than) instruction:
#    - 19 times: the branch is TAKEN (loop again)
#    - 1 time:   the branch is NOT TAKEN (exit the loop)
#
#  A predictor with no learning would guess wrong constantly.
#  A 2-bit saturating counter predictor should:
#    - Guess wrong on the very first iteration (it starts
#      assuming "not taken")
#    - Learn quickly and correctly guess "taken" for the next
#      18 iterations
#    - Guess wrong exactly once more, at the very end, when
#      the loop finally exits (it had learned "taken" but this
#      time it's not)
#
#  Expected result: 18 correct predictions, 2 mispredictions,
#  out of 20 total branch resolutions = 90% accuracy.
# ============================================================

.section .text
.global _start
_start:
    addi  x1, x0, 0        # x1 = i = 0  (loop counter)
    addi  x2, x0, 20       # x2 = 20     (loop bound)

loop:
    addi  x1, x1, 1        # i = i + 1
    blt   x1, x2, loop     # if (i < 20) goto loop

    # ── Loop has exited — x1 should now equal 20 ─────────────
    addi  x3, x0, 99       # x3 = 99 (marker: we reached the end correctly)

done:
    j done
