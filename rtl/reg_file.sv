//  Module: reg_file — Register File
//  Purpose: The CPU's 32 working registers (x0 to x31). Two can be read simultaneously; one can be written.

module reg_file
   (input logic clk,

    // For the source reg 1
    input logic [4:0] rs1_addr,
    output logic [31:0] rs1_data,

    // For the source reg 2
    input logic [4:0] rs2_addr,
    output logic [31:0] rs2_data,

    // For the destination reg
    input logic [4:0] rd_addr,
    input logic [31:0] rd_data,
    input logic reg_write);

    logic [31:0] regs [0:31];

//  For simulation, initialising to 0 avoids X-propagation issues
    integer i;
    initial 
    begin
        for (i = 0; i < 32; i = i + 1)
            regs[i] = 32'b0;
    end

    always_comb 
    begin
        rs1_data = (rs1_addr == 5'b0) ? 32'b0 : regs[rs1_addr];
        rs2_data = (rs2_addr == 5'b0) ? 32'b0 : regs[rs2_addr];
    end

    // For reading, we need the register value in this cycle to do the computation.
    // For writing, we want to store the result of this cycle's work in the next cycle.
    // This is so that we dont create a feedback path with another combinational block or timing problems.

    always_ff @(posedge clk) 
    begin
        if (reg_write && rd_addr != 5'b0)
            regs[rd_addr] <= rd_data;
    end
endmodule