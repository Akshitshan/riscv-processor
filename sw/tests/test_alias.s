# test_alias.s- branch predictor aliasing regression test

# Old RTL: predicted taken for the addi, jumped to 0x08, and never corrected it
# Fixed RTL: EX sees "taken predicted for a non-branch",
# redirects to 0x110, and execution continues correctly.

# Expected: x1 = 3, x2 = 3, x3 = 7, x4 = 9
.section .text
.global _start
_start:
    addi x1, x0, 0          # 0x00
    addi x2, x0, 3          # 0x04
loop:
    addi x1, x1, 1          # 0x08
    blt x1, x2, loop        # 0x0C trains predictor entry 3
    j far                   # 0x10

    .org 0x10C
far:
    addi x3, x0, 7          # 0x10C aliases with the blt at 0x0C
    addi x4, x0, 9          # 0x110
done:
    beq x0, x0, done
