// Module: reg_file- Register File
// Purpose: 32 working registers made of two read ports, one write port.

// V2: Added write- first forwarding
// Problem: As non-blocking assignment is merely evaluated before the clock edge 
//          but gets assigned only after it, if the WB stage is writing to 
//          a register that is being read in the ID stage, ID sees the old value not the new.
// Fix: solved by bypassing the stored value and returning the new write data directly. 

`timescale 1ns/1ps

module reg_file #(parameter bit WRITE_FIRST = 1'b1)
    (input logic clk,

    input logic [4:0] rs1_addr,               // Read port A (rs1)
    output logic [31:0] rs1_data,

    input logic [4:0] rs2_addr,               // Read port B (rs2)
    output logic [31:0] rs2_data,

    input logic [4:0] rd_addr,                // Write port (rd- from WB stage)
    input logic [31:0] rd_data,
    input logic reg_write
);

    // 32 registers × 32 bits
    logic [31:0] regs [0:31];

`ifndef SYNTHESIS
    integer i;
    initial begin
        for (i = 0; i < 32; i = i + 1)
            regs[i] = 32'b0;
    end
`endif

    // --- Read port A ---------------------------------------------------
    always_comb 
    begin
        if (rs1_addr == 5'b0)
            rs1_data = 32'b0;                    // x0 is hardwired to 0
        else if (WRITE_FIRST && reg_write && rd_addr == rs1_addr)
            rs1_data = rd_data;                  // WB forwarding: new value
        else
            rs1_data = regs[rs1_addr];           // Normal read
    end

    // --- Read port B ---------------------------------------------------
    always_comb 
    begin
        if (rs2_addr == 5'b0)
            rs2_data = 32'b0;
        else if (WRITE_FIRST && reg_write && rd_addr == rs2_addr)
            rs2_data = rd_data;
        else
            rs2_data = regs[rs2_addr];
    end

    // --- Write port (on clock edge only) -------------------------------
    always_ff @(posedge clk) begin
        if (reg_write && rd_addr != 5'b0)
            regs[rd_addr] <= rd_data;
    end
endmodule