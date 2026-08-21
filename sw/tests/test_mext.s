# test_mext.s — M extension: multiply and divide
# MUL  : lower 32 bits of product
# MULH : upper 32 bits (signed×signed) — detects overflow
# DIV  : signed integer division, rounds toward zero
# DIVU : unsigned division
# REM  : signed remainder
# Division by zero → defined result (-1 or dividend, not crash)
.section .text
.global _start
_start:
    addi  x1, x0, 12          # x1 = 12
    addi  x2, x0, 5           # x2 = 5
    addi  x3, x0, -3          # x3 = -3
    addi  x4, x0, 7           # x4 = 7

    mul   x5,  x1, x2         # x5  = 60
    mul   x6,  x3, x2         # x6  = -15 = 0xFFFFFFF1
    mulh  x7,  x3, x2         # x7  = -1  = 0xFFFFFFFF (upper 32 of -15)
    div   x8,  x1, x2         # x8  = 2  (12/5)
    rem   x9,  x1, x2         # x9  = 2  (12 mod 5)
    divu  x10, x1, x4         # x10 = 1  (12/7 unsigned)
    remu  x11, x1, x4         # x11 = 5  (12 mod 7 unsigned)
    div   x12, x1, x0         # x12 = 0xFFFFFFFF (div by zero)
    div   x13, x3, x2         # x13 = 0  (-3/5 rounds to zero)
    rem   x14, x3, x2         # x14 = -3 (-3 mod 5)

    addi  x15, x0, 1000
    mul   x16, x15, x15       # x16 = 1,000,000
done: j done
