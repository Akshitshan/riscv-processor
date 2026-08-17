// ============================================================
//  MODULE: pipeline_regs — The four conveyor belts
//
//  WHAT THIS IS IN PLAIN ENGLISH:
//  Between each pair of pipeline stages sits a row of flip-flops
//  (registers). At every clock edge, these flip-flops capture
//  whatever the previous stage produced, and hold it steady
//  for the next stage to read during the next cycle.
//
//  Think of it like passing a baton in a relay race:
//  The runner (stage) does their leg, then hands the baton
//  (data) to the next runner at a fixed exchange point (register).
//
//  We have four of these exchange points:
//    IF/ID  — between Fetch and Decode
//    ID/EX  — between Decode and Execute
//    EX/MEM — between Execute and Memory
//    MEM/WB — between Memory and Writeback
//
//  FLUSH vs STALL:
//  flush=1 → wipe this register clean (insert a NOP bubble).
//            Used when a branch was mispredicted and we fetched
//            the wrong instructions — we throw them away.
//  stall=1 → freeze, don't update this register.
//            Used when we're waiting for a load result —
//            the pipeline pauses like a conveyor belt stopping.
// ============================================================

`timescale 1ns/1ps

// ── IF/ID Pipeline Register ──────────────────────────────────
//    Holds: the fetched instruction + the PC it came from
//    Why PC? Because branches and AUIPC need to know "where was I?"

module if_id_reg (
    input  logic        clk,
    input  logic        rst,
    input  logic        flush,  // 1 = clear this (branch mispredict)
    input  logic        stall,  // 1 = freeze this (load-use hazard)

    // What comes IN from the Fetch stage
    input  logic [31:0] pc_in,
    input  logic [31:0] instr_in,

    // What goes OUT to the Decode stage
    output logic [31:0] pc_out,
    output logic [31:0] instr_out
);
    // The NOP instruction is addi x0, x0, 0 = 0x00000013
    // It does nothing — writes to x0 (which ignores writes)
    localparam NOP = 32'h0000_0013;

    always_ff @(posedge clk or posedge rst) begin
        if (rst || flush) begin
            // On reset or flush: load a NOP so this stage does nothing
            pc_out    <= 32'b0;
            instr_out <= NOP;
        end else if (!stall) begin
            // Normal operation: capture the current stage's values
            pc_out    <= pc_in;
            instr_out <= instr_in;
        end
        // If stall=1 and no flush: do nothing — hold current values
    end
endmodule


// ── ID/EX Pipeline Register ──────────────────────────────────
//    Holds: decoded control signals + register values + immediate
//    After Decode, we know EVERYTHING about the instruction.
//    We pass all of that to Execute in this register.

module id_ex_reg
    import riscv_pkg::*;
(
    input  logic        clk,
    input  logic        rst,
    input  logic        flush,  // 1 = turn into a NOP bubble

    // Control signals from the Decode stage
    input  logic        reg_write_in,
    input  logic        mem_read_in,
    input  logic        mem_write_in,
    input  logic [2:0]  mem_funct3_in,
    input  logic [1:0]  wb_sel_in,
    input  logic        alu_src_in,
    input  alu_op_t     alu_op_in,
    input  logic        branch_in,
    input  logic        jump_in,
    input  logic        jalr_in,

    // Data values
    input  logic [31:0] pc_in,
    input  logic [31:0] rs1_data_in,
    input  logic [31:0] rs2_data_in,
    input  logic [31:0] imm_in,

    // Register addresses — forwarding unit needs these
    input  logic [4:0]  rs1_addr_in,
    input  logic [4:0]  rs2_addr_in,
    input  logic [4:0]  rd_addr_in,

    // Everything above, but captured and held for Execute stage
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
    output logic [4:0]  rd_addr_out
);
    always_ff @(posedge clk or posedge rst) begin
        if (rst || flush) begin
            // NOP bubble: no register write, no memory access
            reg_write_out  <= 0; mem_read_out  <= 0;
            mem_write_out  <= 0; mem_funct3_out<= 0;
            wb_sel_out     <= 0; alu_src_out   <= 0;
            alu_op_out     <= ALU_ADD;
            branch_out     <= 0; jump_out      <= 0; jalr_out <= 0;
            pc_out         <= 0; rs1_data_out  <= 0;
            rs2_data_out   <= 0; imm_out       <= 0;
            rs1_addr_out   <= 0; rs2_addr_out  <= 0; rd_addr_out <= 0;
        end else begin
            reg_write_out  <= reg_write_in;  mem_read_out  <= mem_read_in;
            mem_write_out  <= mem_write_in;  mem_funct3_out<= mem_funct3_in;
            wb_sel_out     <= wb_sel_in;     alu_src_out   <= alu_src_in;
            alu_op_out     <= alu_op_in;
            branch_out     <= branch_in;     jump_out      <= jump_in;
            jalr_out       <= jalr_in;
            pc_out         <= pc_in;         rs1_data_out  <= rs1_data_in;
            rs2_data_out   <= rs2_data_in;   imm_out       <= imm_in;
            rs1_addr_out   <= rs1_addr_in;   rs2_addr_out  <= rs2_addr_in;
            rd_addr_out    <= rd_addr_in;
        end
    end
endmodule


// ── EX/MEM Pipeline Register ─────────────────────────────────
//    Holds: ALU result + store data + control signals
//    After Execute, the ALU is done. We pass the result forward.

module ex_mem_reg (
    input  logic        clk,
    input  logic        rst,

    input  logic        reg_write_in,
    input  logic        mem_read_in,
    input  logic        mem_write_in,
    input  logic [2:0]  mem_funct3_in,
    input  logic [1:0]  wb_sel_in,
    input  logic [31:0] alu_result_in,
    input  logic [31:0] rs2_data_in,   // The data to store (for SW/SH/SB)
    input  logic [31:0] pc_plus4_in,   // Return address (for JAL/JALR)
    input  logic [4:0]  rd_addr_in,

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
            reg_write_out  <= 0; mem_read_out   <= 0;
            mem_write_out  <= 0; mem_funct3_out <= 0;
            wb_sel_out     <= 0; alu_result_out <= 0;
            rs2_data_out   <= 0; pc_plus4_out   <= 0;
            rd_addr_out    <= 0;
        end else begin
            reg_write_out  <= reg_write_in;   mem_read_out   <= mem_read_in;
            mem_write_out  <= mem_write_in;   mem_funct3_out <= mem_funct3_in;
            wb_sel_out     <= wb_sel_in;      alu_result_out <= alu_result_in;
            rs2_data_out   <= rs2_data_in;    pc_plus4_out   <= pc_plus4_in;
            rd_addr_out    <= rd_addr_in;
        end
    end
endmodule


// ── MEM/WB Pipeline Register ─────────────────────────────────
//    Holds: memory read data + ALU result + which to write back
//    This is the last handoff — from Memory into Writeback.

module mem_wb_reg (
    input  logic        clk,
    input  logic        rst,

    input  logic        reg_write_in,
    input  logic [1:0]  wb_sel_in,
    input  logic [31:0] alu_result_in,
    input  logic [31:0] mem_data_in,
    input  logic [31:0] pc_plus4_in,
    input  logic [4:0]  rd_addr_in,

    output logic        reg_write_out,
    output logic [1:0]  wb_sel_out,
    output logic [31:0] alu_result_out,
    output logic [31:0] mem_data_out,
    output logic [31:0] pc_plus4_out,
    output logic [4:0]  rd_addr_out
);
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            reg_write_out  <= 0; wb_sel_out     <= 0;
            alu_result_out <= 0; mem_data_out   <= 0;
            pc_plus4_out   <= 0; rd_addr_out    <= 0;
        end else begin
            reg_write_out  <= reg_write_in;   wb_sel_out     <= wb_sel_in;
            alu_result_out <= alu_result_in;  mem_data_out   <= mem_data_in;
            pc_plus4_out   <= pc_plus4_in;    rd_addr_out    <= rd_addr_in;
        end
    end
endmodule
