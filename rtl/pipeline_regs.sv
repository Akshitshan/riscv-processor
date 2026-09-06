// Module: pipeline_regs
// Purpose: the four conveyor belts between the pipleine stages

// V2: Added branch preditor bit for the EX stage to compare later

`timescale 1ns/1ps

// --- IF/ID Pipeline Register -----------------------------------------------
module if_id_reg (
    input logic clk,
    input logic rst,
    input logic flush,
    input logic stall,

    input logic [31:0] pc_in,
    input logic [31:0] instr_in,
    input logic        predicted_taken_in,

    output logic [31:0] pc_out,
    output logic [31:0] instr_out,
    output logic        predicted_taken_out
);
    localparam NOP = 32'h0000_0013;

    always_ff @(posedge clk or posedge rst) begin
        if (rst || flush) begin
            pc_out              <= 32'b0;
            instr_out           <= NOP;
            predicted_taken_out <= 1'b0;   // a flushed/reset slot never "predicted taken"
        end else if (!stall) begin
            pc_out              <= pc_in;
            instr_out           <= instr_in;
            predicted_taken_out <= predicted_taken_in;
        end
    end
endmodule


// --- ID/EX Pipeline Register -----------------------------------------------
module id_ex_reg
    import riscv_pkg::*;
(
    input logic clk,
    input logic rst,
    input logic flush,

    input logic       reg_write_in,
    input logic       mem_read_in,
    input logic       mem_write_in,
    input logic [2:0] mem_funct3_in,
    input logic [1:0] wb_sel_in,
    input logic       alu_src_in,
    input alu_op_t    alu_op_in,
    input logic       branch_in,
    input logic       jump_in,
    input logic       jalr_in,

    input logic [31:0] pc_in,
    input logic [31:0] rs1_data_in,
    input logic [31:0] rs2_data_in,
    input logic [31:0] imm_in,

    input logic [4:0] rs1_addr_in,
    input logic [4:0] rs2_addr_in,
    input logic [4:0] rd_addr_in,

    input logic predicted_taken_in,

    output logic        reg_write_out,
    output logic        mem_read_out,
    output logic        mem_write_out,
    output logic [2:0]  mem_funct3_out,
    output logic [1:0]  wb_sel_out,
    output logic        alu_src_out,
    output alu_op_t     alu_op_out,
    output logic        branch_out,
    output logic        jump_out,
    output logic        jalr_out,
    output logic [31:0] pc_out,
    output logic [31:0] rs1_data_out,
    output logic [31:0] rs2_data_out,
    output logic [31:0] imm_out,
    output logic [4:0]  rs1_addr_out,
    output logic [4:0]  rs2_addr_out,
    output logic [4:0]  rd_addr_out,

    output logic predicted_taken_out
);
    always_ff @(posedge clk or posedge rst) begin
        if (rst || flush) begin
            reg_write_out <= 0; mem_read_out  <= 0;
            mem_write_out <= 0; mem_funct3_out<= 0;
            wb_sel_out    <= 0; alu_src_out   <= 0;
            alu_op_out    <= ALU_ADD;
            branch_out    <= 0; jump_out      <= 0; jalr_out <= 0;
            pc_out        <= 0; rs1_data_out  <= 0;
            rs2_data_out  <= 0; imm_out       <= 0;
            rs1_addr_out  <= 0; rs2_addr_out  <= 0; rd_addr_out <= 0;
            predicted_taken_out <= 1'b0;
        end 
        else begin
            reg_write_out <= reg_write_in;  mem_read_out  <= mem_read_in;
            mem_write_out <= mem_write_in;  mem_funct3_out<= mem_funct3_in;
            wb_sel_out    <= wb_sel_in;     alu_src_out   <= alu_src_in;
            alu_op_out    <= alu_op_in;
            branch_out    <= branch_in;     jump_out      <= jump_in;
            jalr_out      <= jalr_in;
            pc_out        <= pc_in;         rs1_data_out  <= rs1_data_in;
            rs2_data_out  <= rs2_data_in;   imm_out       <= imm_in;
            rs1_addr_out  <= rs1_addr_in;   rs2_addr_out  <= rs2_addr_in;
            rd_addr_out   <= rd_addr_in;
            predicted_taken_out <= predicted_taken_in;
        end
    end
endmodule

// --- EX/MEM Pipeline Register ----------------------------------------------
module ex_mem_reg (
    input logic clk,
    input logic rst,

    input logic        reg_write_in,
    input logic        mem_read_in,
    input logic        mem_write_in,
    input logic [2:0]  mem_funct3_in,
    input logic [1:0]  wb_sel_in,
    input logic [31:0] alu_result_in,
    input logic [31:0] rs2_data_in,
    input logic [31:0] pc_plus4_in,
    input logic [4:0]  rd_addr_in,

    output logic        reg_write_out,
    output logic        mem_read_out,
    output logic        mem_write_out,
    output logic [2:0]  mem_funct3_out,
    output logic [1:0]  wb_sel_out,
    output logic [31:0] alu_result_out,
    output logic [31:0] rs2_data_out,
    output logic [31:0] pc_plus4_out,
    output logic [4:0]  rd_addr_out
);
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            reg_write_out <= 0; mem_read_out   <= 0;
            mem_write_out <= 0; mem_funct3_out <= 0;
            wb_sel_out    <= 0; alu_result_out <= 0;
            rs2_data_out  <= 0; pc_plus4_out   <= 0;
            rd_addr_out   <= 0;
        end else begin
            reg_write_out <= reg_write_in;  mem_read_out   <= mem_read_in;
            mem_write_out <= mem_write_in;  mem_funct3_out <= mem_funct3_in;
            wb_sel_out    <= wb_sel_in;     alu_result_out <= alu_result_in;
            rs2_data_out  <= rs2_data_in;   pc_plus4_out   <= pc_plus4_in;
            rd_addr_out   <= rd_addr_in;
        end
    end
endmodule

// --- MEM/WB Pipeline Register ----------------------------------------------
module mem_wb_reg (
    input logic clk,
    input logic rst,

    input logic        reg_write_in,
    input logic [1:0]  wb_sel_in,
    input logic [31:0] alu_result_in,
    input logic [31:0] mem_data_in,
    input logic [31:0] pc_plus4_in,
    input logic [4:0]  rd_addr_in,

    output logic        reg_write_out,
    output logic [1:0]  wb_sel_out,
    output logic [31:0] alu_result_out,
    output logic [31:0] mem_data_out,
    output logic [31:0] pc_plus4_out,
    output logic [4:0]  rd_addr_out
);
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            reg_write_out  <= 0; wb_sel_out   <= 0;
            alu_result_out <= 0; mem_data_out <= 0;
            pc_plus4_out   <= 0; rd_addr_out  <= 0;
        end else begin
            reg_write_out  <= reg_write_in;  wb_sel_out   <= wb_sel_in;
            alu_result_out <= alu_result_in; mem_data_out <= mem_data_in;
            pc_plus4_out   <= pc_plus4_in;   rd_addr_out  <= rd_addr_in;
        end
    end
endmodule
