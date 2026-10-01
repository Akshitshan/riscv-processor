// Package: riscv_pkg- Shared type definitions
// Purpose: Easy access and importability into all the other modules

`timescale 1ns/1ps

package riscv_pkg;

    // --- ALU operation codes --------------------------------------
        localparam logic [4:0] ALU_ADD = 5'b00000;          // Addition (ADD, ADDI, loads, stores)
        localparam logic [4:0] ALU_SUB = 5'b00001;          // Subtraction (SUB, branches)
        localparam logic [4:0] ALU_AND = 5'b00010;          // Bitwise AND (AND, ANDI)
        localparam logic [4:0] ALU_OR = 5'b00011;           // Bitwise OR (OR, ORI)
        localparam logic [4:0] ALU_XOR = 5'b00100;          // Bitwise XOR (XOR, XORI)
        localparam logic [4:0] ALU_SLL = 5'b00101;          // Shift Left Logical (SLL, SLLI)
        localparam logic [4:0] ALU_SRL = 5'b00110;          // Shift Right Logical (SRL, SRLI)
        localparam logic [4:0] ALU_SRA = 5'b00111;          // Shift Right Arith (SRA, SRAI)
        localparam logic [4:0] ALU_SLT = 5'b01000;          // Set Less Than signed (SLT, SLTI, BLT, BGE)
        localparam logic [4:0] ALU_SLTU = 5'b01001;         // Set Less Than unsign (SLTU, SLTIU, BLTU, BGEU)
        localparam logic [4:0] ALU_LUI = 5'b01010;          // Pass B through (LUI)
        localparam logic [4:0] ALU_MUL = 5'b01011;          // Multiply low 32 (MUL)
        localparam logic [4:0] ALU_MULH = 5'b01100;         // Multiply high s×s (MULH)
        localparam logic [4:0] ALU_MULHSU= 5'b01101;        // Multiply high s×u (MULHSU)
        localparam logic [4:0] ALU_MULHU = 5'b01110;        // Multiply high u×u (MULHU)
        localparam logic [4:0] ALU_DIV = 5'b01111;          // Signed division (DIV)
        localparam logic [4:0] ALU_DIVU = 5'b10000;         // Unsigned division (DIVU)
        localparam logic [4:0] ALU_REM = 5'b10001;          // Signed remainder (REM)
        localparam logic [4:0] ALU_REMU = 5'b10010;         // Unsigned remainder (REMU)

    // --- Immediate format selector -------------------------------
        localparam logic [2:0] IMM_I = 3'b000;          // I-type
        localparam logic [2:0] IMM_S = 3'b001;          // S-type
        localparam logic [2:0] IMM_B = 3'b010;          // B-type
        localparam logic [2:0] IMM_U = 3'b011;          // U-type
        localparam logic [2:0] IMM_J = 3'b100;          // J-type
        localparam logic [2:0] IMM_X = 3'b101;          // R-type

endpackage
