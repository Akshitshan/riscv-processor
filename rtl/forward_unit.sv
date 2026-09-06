// Module: forward_unit- Data forwarding
// Purpose: Mainly to solve RAW (Read after Write) hazards
//          When an instrx needs a register value before a 
//          previous intstrx has finished writing it back.
//  Path 1: EX-EX forwarding (forward from EX/MEM register)
//  Path 2: MEM-EX forwarding (forward from MEM/WB register)

// 2-bit mux selects:
//   2'b00 = use the register file value (no forwarding needed)
//   2'b10 = use EX/MEM forwarded value  (one instruction ago)
//   2'b01 = use MEM/WB forwarded value  (two instructions ago)
// EX/MEM forwarding for rs1 is the highest priority because that is the latest value

`timescale 1ns/1ps

module forward_unit (
    // Current instruction in EX stage
    input logic [4:0] ex_rs1_addr,      // Source register 1 address
    input logic [4:0] ex_rs2_addr,      // Source register 2 address

    // Previous instruction (in MEM stage)
    input logic       ex_mem_reg_write,  // Is it writing to a register?
    input logic [4:0] ex_mem_rd,         // To which register?

    // Instruction two stages back (in WB stage)
    input logic       mem_wb_reg_write,  // Is it writing to a register?
    input logic [4:0] mem_wb_rd,         // To which register?

    // Mux select lines- tells the EX stage MUXes which value to use
    output logic [1:0] forward_a,        // For operand A (rs1)
    output logic [1:0] forward_b         // For operand B (rs2)
);
    // --- Forwarding logic for operand A (rs1) -----------------------------
    always_comb 
    begin
        forward_a = 2'b00; // No forwarding by default- use register file

        if (ex_mem_reg_write &&             // It is writing to a reg
            (ex_mem_rd != 5'b0) &&          // It is not x0
            (ex_mem_rd == ex_rs1_addr))     // It is writing to the reg the next instruction needs
            forward_a = 2'b10;              // Take value from EX/MEM register

        else if (mem_wb_reg_write &&
                 (mem_wb_rd != 5'b0) &&
                 (mem_wb_rd == ex_rs1_addr))
            forward_a = 2'b01;              // Take value from MEM/WB register
    end

    // --- Forwarding logic for operand B (rs2) ----------------------------
    always_comb 
    begin
        forward_b = 2'b00;

        if (ex_mem_reg_write &&
            (ex_mem_rd != 5'b0) &&
            (ex_mem_rd == ex_rs2_addr))
            forward_b = 2'b10;

        else if (mem_wb_reg_write &&
                 (mem_wb_rd != 5'b0) &&
                 (mem_wb_rd == ex_rs2_addr))
            forward_b = 2'b01;
    end

endmodule
