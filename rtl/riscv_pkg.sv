// Package: riscv_pkg- Shared type definitions
// Purpose: Easy access and importability into all the other modules

`timescale 1ns/1ps

package riscv_pkg;

    // --- ALU operation codes --------------------------------------
    typedef enum logic [4:0] {
        ALU_ADD   = 5'b00000,   // Addition             (ADD, ADDI, loads, stores)
        ALU_SUB   = 5'b00001,   // Subtraction          (SUB, branches)
        ALU_AND   = 5'b00010,   // Bitwise AND          (AND, ANDI)
        ALU_OR    = 5'b00011,   // Bitwise OR           (OR, ORI)
        ALU_XOR   = 5'b00100,   // Bitwise XOR          (XOR, XORI)
        ALU_SLL   = 5'b00101,   // Shift Left Logical   (SLL, SLLI)
        ALU_SRL   = 5'b00110,   // Shift Right Logical  (SRL, SRLI)
        ALU_SRA   = 5'b00111,   // Shift Right Arith    (SRA, SRAI)
        ALU_SLT   = 5'b01000,   // Set Less Than signed (SLT, SLTI, BLT, BGE)
        ALU_SLTU  = 5'b01001,   // Set Less Than unsign (SLTU, SLTIU, BLTU, BGEU)
        ALU_LUI   = 5'b01010,   // Pass B through       (LUI)
        ALU_MUL   = 5'b01011,   // Multiply low 32      (MUL)
        ALU_MULH  = 5'b01100,   // Multiply high s×s    (MULH)
        ALU_MULHSU= 5'b01101,   // Multiply high s×u    (MULHSU)
        ALU_MULHU = 5'b01110,   // Multiply high u×u    (MULHU)
        ALU_DIV   = 5'b01111,   // Signed division      (DIV)
        ALU_DIVU  = 5'b10000,   // Unsigned division    (DIVU)
        ALU_REM   = 5'b10001,   // Signed remainder     (REM)
        ALU_REMU  = 5'b10010    // Unsigned remainder   (REMU)
    } alu_op_t;

    // --- Immediate format selector -------------------------------
    typedef enum logic [2:0] {
        IMM_I = 3'b000,   // I-type
        IMM_S = 3'b001,   // S-type
        IMM_B = 3'b010,   // B-type
        IMM_U = 3'b011,   // U-type
        IMM_J = 3'b100,   // J-type
        IMM_X = 3'b101    // R-type
    } imm_sel_t;

endpackage
