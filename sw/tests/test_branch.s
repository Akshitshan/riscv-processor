# test_branch.s- All 6 branch types, taken and not-taken
# Branch taken: pipeline flushes 2 wrongly-fetched instructions
# Branch not-taken: pipeline continues normally
.section .text
.global _start
_start:
    addi x1, x0, 5
    addi x2, x0, 5
    addi x3, x0, 3

    # BEQ taken (5 == 5), x4 = 1
    beq x1, x2, beq_t
    addi x4, x0, 99         # flushed
beq_t:
    addi x4, x0, 1

    # BNE not taken (5 == 5, so not equal), x5 = 2
    bne x1, x2, skip_a
    addi x5, x0, 2
    j cont_a
skip_a:
    addi x5, x0, 99
cont_a:

    # BNE taken (5 != 3), x6 = 3
    bne x1, x3, bne_t
    addi x6, x0, 99
bne_t:
    addi x6, x0, 3

    # BLT signed taken (-5 < 3), x7 = 4
    addi x20, x0, -5
    addi x21, x0, 3
    blt x20, x21, blt_t
    addi x7, x0, 99
blt_t:
    addi x7, x0, 4

    # BGE not taken (-5 is not >= 3), x8 = 5
    bge x20, x21, skip_b
    addi x8, x0, 5
    j cont_b
skip_b:
    addi x8, x0, 99
cont_b:

    # BLTU taken (2 <u 10), x9 = 6
    addi x22, x0, 2
    addi x23, x0, 10
    bltu x22, x23, bltu_t
    addi x9, x0, 99
bltu_t:
    addi x9, x0, 6

    # BGEU taken (10 >=u 2), x10 = 7
    bgeu x23, x22, bgeu_t
    addi x10, x0, 99
bgeu_t:
    addi x10, x0, 7

    # JAL + subroutine, x11 = 42
    jal ra, my_func
    j done
my_func:
    addi x11, x0, 42
    ret
done: j done
