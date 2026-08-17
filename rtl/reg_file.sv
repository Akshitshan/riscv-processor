//  Module: reg_file — Register File
//  Purpose: 32 working registers. Two read ports, one write port.

//  V2: Added write-first forwarding (or internal forwarding)

//  Problem: In a pipeline, the WB stage could write to the register file at
//  the same clock edge that the ID stage reads from it.
//  As non-blocking assignment (<=) settles after the
//  clock edge, the ID stage read sees the old value,
//  not the new one being written.

//  Fix:
//  In the combinational read logic, we check whether the WB stage is trying to 
//  write the same register that I'm reading in the ID stage
//  If yes, bypass the stored value and return the new write data
//  directly.

`timescale 1ns/1ps

module reg_file (
    input  logic clk,

    // Read port A (rs1)
    input  logic [4:0]  rs1_addr,
    output logic [31:0] rs1_data,

    // Read port B (rs2)
    input  logic [4:0]  rs2_addr,
    output logic [31:0] rs2_data,

    // Write port (rd — from WB stage)
    input  logic [4:0]  rd_addr,
    input  logic [31:0] rd_data,
    input  logic        reg_write
);

    // 32 registers × 32 bits
    logic [31:0] regs [0:31];

    integer i;
    initial begin
        for (i = 0; i < 32; i = i + 1)
            regs[i] = 32'b0;
    end

    // Read port A (with write-first forwarding)
    //  Priority order:
    //  1. x0 always returns 0, no matter what
    //  2. If WB is writing to this register right now, return
    //     the new write data (not the old stored value)
    //  3. Otherwise, return what is stored in the register

    always_comb 
    begin
        if (rs1_addr == 5'b0)
            rs1_data = 32'b0;                    // x0 is hardwired to 0
        else if (reg_write && rd_addr == rs1_addr)
            rs1_data = rd_data;                  // WB forwarding: new value
        else
            rs1_data = regs[rs1_addr];           // Normal read
    end

    // Read port B (with write-first forwarding)
    always_comb 
    begin
        if (rs2_addr == 5'b0)
            rs2_data = 32'b0;
        else if (reg_write && rd_addr == rs2_addr)
            rs2_data = rd_data;                  // WB forwarding: new value
        else
            rs2_data = regs[rs2_addr];
    end

    always_ff @(posedge clk) begin
        if (reg_write && rd_addr != 5'b0)
            regs[rd_addr] <= rd_data;
    end
endmodule