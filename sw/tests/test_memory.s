# test_memory.s- All load/store widths + sign extension

.section .text
.global _start
_start:
    addi x1, x0, 256            # base address

    # SW/ LW (32-bit word)
    addi x2, x0, 1234
    sw x2, 0(x1)
    lw x3, 0(x1)            # x3 = 1234

    # SH/ LHU/ LH (16-bit halfword)
    addi x4, x0, 500
    sh x4, 8(x1)
    lhu x5, 8(x1)           # x5 = 500 (unsigned, zero-fill)
    lh x6, 8(x1)            # x6 = 500 (signed, bit15=0 so same)

    # SB/ LBU (byte, positive, no sign extension difference)
    addi x7, x0, 100
    sb x7, 16(x1)
    lbu x8, 16(x1)          # x8 = 100 (unsigned)
    lb x9, 16(x1)           # x9 = 100 (signed, bit7=0)

    # SB/ LB (byte 0xFF = negative signed byte)
    addi x10, x0, -1
    sb x10, 20(x1)          # stores 0xFF
    lbu x11, 20(x1)         # x11 = 255 (0x000000FF)
    lb x12, 20(x1)          # x12 = -1 (0xFFFFFFFF, sign extended)

    # Last write wins (overwrite test)
    addi x13, x0, 10
    addi x14, x0, 20
    sw x13, 32(x1)
    sw x14, 32(x1)
    lw x15, 32(x1)          # x15 = 20
done: j done
