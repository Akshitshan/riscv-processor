# File: test_program.s- RISC-V Assembly Test Program

# This is compiled - program.hex - loaded by instr_mem.

.section .text
.global _start

_start:
    # --- Basic immediate arithmetic -------------------------------------
    addi x1, x0, 10      # x1 = 0 + 10 = 10
    addi x2, x0, 20      # x2 = 0 + 20 = 20

    # --- Register-register arithmetic -----------------------------------
    add x3, x1, x2      # x3 = 10 + 20 = 30
    sub x4, x2, x1      # x4 = 20 - 10 = 10

    # --- Logic operations -----------------------------------------------
    and x5, x1, x2      # x5 = 10 & 20 = 0b01010 & 0b10100 = 0
    or x6, x1, x2       # x6 = 10 | 20 = 0b01010 | 0b10100 = 30
    xor x7, x1, x2      # x7 = 10 ^ 20 = 30

    # --- Shifts ---------------------------------------------------------
    slli x8, x1, 2       # x8 = 10 << 2 = 40
    srli x9, x2, 1       # x9 = 20 >> 1 = 10

    # --- Load/ Store ----------------------------------------------------
    addi x20, x0, 256       # x20 = 256 (our data base address)
    sw x3, 0(x20)           # Mem[256] = 30
    lw x10, 0(x20)          # x10 = Mem[256] = 30 (should be 30)

    # --- Byte and halfword loads/stores ---------------------------------
    sb x1, 4(x20)           # Mem[260] = 10 (byte)
    lbu x21, 4(x20)         # x21 = 10 (zero-extended byte)
    sh x2, 8(x20)           # Mem[264] = 20 (halfword)
    lhu x22, 8(x20)         # x22 = 20 (zero-extended halfword)

    # --- LUI: Load Upper Immediate --------------------------------------
    lui x11, 0x12345        # x11 = 0x12345000

    # --- M-extension: Multiply ------------------------------------------
    mul x12, x1, x2         # x12 = 10 * 20 = 200

    # --- Compare instructions -------------------------------------------
    slt x23, x1, x2         # x23 = (10 < 20) = 1
    sltu x24, x2, x1        # x24 = (20 <u 10) = 0

    # --- Branch test ----------------------------------------------------
    addi x13, x0, 5         
    addi x14, x0, 5         

    beq x13, x14, equal
    addi x15, x0, 99      # skipped
equal:
    addi x15, x0, 1

    # --- JAL ------------------------------------------------------------
    jal x16, skip         # x16 = PC+4 (return addr), jump forward

    addi x17, x0, 55      # Skipped
    addi x17, x0, 55      # Skipped

skip:
    addi x17, x0, 7

    # --- JALR ----------------------------------------------------------
    addi x25, x0, 0
    jal ra, my_func

    # --- Division and remainder ----------------------------------------
    addi x18, x0, 100       # x18 = 100
    addi x19, x0, 7         # x19 = 7
    div x26, x18, x19       # x26 = 100 / 7 = 14 (integer division)
    rem x27, x18, x19       # x27 = 100 % 7 = 2

    # --- Infinite loop (halt the CPU) ----------------------------------
    # Without this, the PC would run off into undefined memory. The testbench's 
    # timeout watchdog detects this is stuck and knows the program has completed.
done:
    j done      # infinite loop, but predictable (trains branch predictor)

# --- Subroutine: my_func -----------------------------------------------
my_func:
    addi x25, x0, 42
    ret
