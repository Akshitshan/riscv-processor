# test_loop.s- A real loop, to demonstrate branch prediction

# Expected result: 18 correct predictions, 2 mispredictions out of 20
# total branch resolutions = 90% accuracy.

.section .text
.global _start
_start:
    addi x1, x0, 0          # x1 = i = 0 (loop counter)
    addi x2, x0, 20         # x2 = 20 (loop bound)

loop:
    addi x1, x1, 1
    blt x1, x2, loop

    # Loop has exited- x1 is 20
    addi x3, x0, 99       # x3 = 99 (marker: we reached the end correctly)

done:
    beq x0, x0, done   # infinite loop, but predictable (trains the branch predictor)
