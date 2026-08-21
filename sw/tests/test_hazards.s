# test_hazards.s — Tests all three pipeline hazard types
# RAW hazard    : result used immediately → forwarding handles it
# Load-use      : LW result used next cycle → stall inserted
# WAW           : two writes to same register → second wins
.section .text
.global _start
_start:
    # EX→EX forwarding (result used immediately after)
    addi  x1,  x0, 5         # x1  = 5
    addi  x2,  x1, 3         # x2  = 8   RAW: needs x1
    add   x3,  x1, x2        # x3  = 13  RAW: needs x2
    sub   x4,  x3, x1        # x4  = 8   RAW: needs x3

    # MEM→EX forwarding (result used 2 instructions later)
    addi  x5,  x0, 20        # x5  = 20
    addi  x6,  x0, 30        # x6  = 30
    add   x7,  x5, x6        # x7  = 50  MEM→EX forward of x5

    # Load-use hazard: stall inserted between LW and next user
    addi  x8,  x0, 256       # x8  = 256 (memory base address)
    addi  x9,  x0, 99        # x9  = 99
    sw    x9,  0(x8)         # Mem[256] = 99
    lw    x10, 0(x8)         # x10 = 99
    add   x11, x10, x9       # x11 = 198 ← stall happens here

    # Second load-use
    addi  x12, x0, 42
    sw    x12, 4(x8)         # Mem[260] = 42
    lw    x13, 4(x8)         # x13 = 42
    addi  x14, x13, 1        # x14 = 43  ← stall happens here

    # WAW: two writes to same register, last one wins
    addi  x15, x0, 100
    addi  x15, x0, 200       # x15 = 200 (overwrites 100)
    addi  x16, x15, 0        # x16 = 200
done: j done
