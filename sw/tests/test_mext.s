# test_mext.s- M extension: multiply and divide

.section .text
.global _start
_start:
    addi x1, x0, 12             # x1 = 12
    addi x2, x0, 5              # x2 = 5
    addi x3, x0, -3             # x3 = -3
    addi x4, x0, 7              # x4 = 7
 
    mul x5, x1, x2             # x5 = 60
    mul x6, x3, x2             # x6 = -15 = 0xFFFFFFF1
    mulh x7, x3, x2            # x7 = -1 = 0xFFFFFFFF (upper 32 of -15)
    div x8, x1, x2             # x8 = 2 (12/5)
    rem x9, x1, x2             # x9 = 2 (12 mod 5)
    divu x10, x1, x4            # x10 = 1 (12/7 unsigned)
    remu x11, x1, x4            # x11 = 5 (12 mod 7 unsigned)
    div x12, x1, x0             # x12 = 0xFFFFFFFF (div by zero)
    div x13, x3, x2             # x13 = 0 (-3/5 rounds to zero)
    rem x14, x3, x2             # x14 = -3 (-3 mod 5)
 
    addi x15, x0, 1000
    mul x16, x15, x15       # x16 = 1,000,000
 
    # Corner cases for the multi-cycle divider
    lui x17, 0x80000        # x17 = 0x80000000 (most negative number)
    addi x18, x0, -1         # x18 = -1
    div x19, x17, x18       # overflow case: x19 = 0x80000000
    rem x20, x17, x18       # x20 = 0
    divu x21, x1, x0         # divide by zero: x21 = 0xFFFFFFFF
    remu x22, x1, x0         # x22 = 12 (dividend)
    rem x23, x3, x0         # x23 = -3 (dividend)
 
    # Back-to-back dependent divides (forwarding out of the divider)
    div x24, x1, x2         # x24 = 12 / 5 = 2
    div x25, x24, x2        # x25 = 2 / 5 = 0
    add x26, x24, x1        # x26 = 2 + 12 = 14
done: beq x0, x0, done
