//  Module: Shared package
//  Purpose: Shared type definitions used across all modules.
`timescale 1ns/1ps

package riscv_pkg;
// ALU operation codes- Tells the ALU which operation to perform

    typedef enum logic [3:0] {
        ALU_ADD  = 4'b0000,   // Addition
        ALU_SUB  = 4'b0001,   // Subtraction
        ALU_AND  = 4'b0010,   // Bitwise AND
        ALU_OR   = 4'b0011,   // Bitwise OR
        ALU_XOR  = 4'b0100,   // Bitwise XOR
        ALU_SLL  = 4'b0101,   // Shift Left Logical
        ALU_SRL  = 4'b0110,   // Shift Right Logical
        ALU_SRA  = 4'b0111,   // Shift Right Arithmetic
        ALU_SLT  = 4'b1000,   // Set Less Than (signed)
        ALU_SLTU = 4'b1001,   // Set Less Than (unsigned)
        ALU_LUI  = 4'b1010,   // Pass operand_b through (for LUI)
        ALU_MUL  = 4'b1011,   // Multiply lower 32 bits
        ALU_MULH = 4'b1100,   // Multiply upper 32 bits (signed)
        ALU_DIV  = 4'b1101,   // Signed division
        ALU_DIVU = 4'b1110,   // Unsigned division
        ALU_REM  = 4'b1111    // Signed remainder
    } alu_op_t;


    // Format of IMMediate- Tells the immediate generator which instruction format to decode the immediate from.

    typedef enum logic [2:0] {
        IMM_I = 3'b000,   // I-type: loads, ALU-imm, JALR
        IMM_S = 3'b001,   // S-type: stores
        IMM_B = 3'b010,   // B-type: branches
        IMM_U = 3'b011,   // U-type: LUI, AUIPC
        IMM_J = 3'b100,   // J-type: JAL
        IMM_X = 3'b101    // R-type: no immediate
    } imm_sel_t;

endpackage