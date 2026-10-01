# test_alu.s- Tests every ALU instruction type
# Expected results are computed by rv32im_sim.py
.section .text
.global _start
_start:
    addi x1, x0, 15        # x1 = 15
    addi x2, x0, 7         # x2 = 7
    add x3, x1, x2         # x3 = 22
    sub x4, x1, x2         # x4 = 8
    and x5, x1, x2         # x5 = 7
    or x6, x1, x2          # x6 = 15
    xor x7, x1, x2         # x7 = 8
    slt x8, x2, x1         # x8 = 1 (7 < 15)
    sltu x9, x2, x1        # x9 = 1
    sll x10, x2, x2         # x10 = 896 (7 << 7)
    srl x11, x1, x2         # x11 = 0 (15 >> 7)
    addi x12, x0, -16       # x12 = -16 = 0xFFFFFFF0
    sra x13, x12, x2        # x13 = -1 = 0xFFFFFFFF
    addi x14, x1, 10       # x14 = 25
    andi x15, x1, 5        # x15 = 5
    ori x16, x0, 0x7F      # x16 = 127
    xori x17, x16, -1       # x17 = 0xFFFFFF80
    slti x18, x12, 0        # x18 = 1 (-16 < 0)
    sltiu x19, x1, 100     # x19 = 1
    slli x20, x1, 3        # x20 = 120
    srli x21, x16, 2        # x21 = 31
    srai x22, x12, 2        # x22 = -4 = 0xFFFFFFFC
    lui x23, 0xABCDE        # x23 = 0xABCDE000
done: j done
