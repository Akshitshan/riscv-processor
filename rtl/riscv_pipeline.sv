// ============================================================
//  MODULE: riscv_pipeline — 5-Stage Pipelined RV32IM CPU
//
//  FIX (v2): When a branch or jump is taken, we must flush
//  TWO instructions — the one in IF and the one in ID.
//  Old: only flushed IF/ID (1 instruction killed)
//  Fix: also flush ID/EX (2 instructions killed)
//
//  The change is one line in the id_ex_reg instantiation:
//    OLD: .flush (flush_id_ex)
//    NEW: .flush (flush_id_ex | ex_pc_sel)
//
//  WHY 2 INSTRUCTIONS?
//  Branch resolves in EX. At that moment:
//    - IF has fetched instruction B+8 (2 ahead of branch)
//    - ID has instruction B+4 (1 ahead of branch)
//  Both are on the wrong path and must be killed.
//  Flushing only IF/ID let the instruction in ID slip
//  through into EX, executing skip_a when it shouldn't.
// ============================================================

`timescale 1ns/1ps

module riscv_pipeline
    import riscv_pkg::*;
(
    input  logic        clk,
    input  logic        rst,
    output logic [31:0] dbg_pc,
    output logic [31:0] dbg_instr,
    output logic [31:0] dbg_wb_data
);

    // ==========================================================
    //  SIGNAL DECLARATIONS
    // ==========================================================

    // IF stage
    logic [31:0] if_pc, if_pc_plus4, if_instr;

    // IF/ID register outputs (ID stage inputs)
    logic [31:0] id_pc, id_instr;

    // ID stage decoded signals
    logic [31:0] id_rs1_data, id_rs2_data, id_imm;
    logic        id_reg_write, id_mem_read, id_mem_write;
    logic [2:0]  id_mem_funct3;
    logic [1:0]  id_wb_sel;
    logic        id_alu_src, id_branch, id_jump, id_jalr;
    alu_op_t     id_alu_op;
    imm_sel_t    id_imm_sel;

    // ID/EX register outputs (EX stage inputs)
    logic [31:0] ex_pc, ex_rs1_data, ex_rs2_data, ex_imm;
    logic [4:0]  ex_rs1_addr, ex_rs2_addr, ex_rd_addr;
    logic        ex_reg_write, ex_mem_read, ex_mem_write;
    logic [2:0]  ex_mem_funct3;
    logic [1:0]  ex_wb_sel;
    logic        ex_alu_src, ex_branch, ex_jump, ex_jalr;
    alu_op_t     ex_alu_op;

    // EX stage computed signals
    logic [31:0] ex_alu_operand_a, ex_alu_operand_b, ex_alu_input_b;
    logic [31:0] ex_alu_result;
    logic        ex_alu_zero;
    logic [31:0] ex_pc_plus4;
    logic        ex_branch_taken, ex_pc_sel;
    logic [1:0]  ex_forward_a, ex_forward_b;
    logic [31:0] ex_fwd_rs2;

    // EX/MEM register outputs (MEM stage inputs)
    logic [31:0] mem_alu_result, mem_rs2_data, mem_pc_plus4;
    logic [4:0]  mem_rd_addr;
    logic        mem_reg_write, mem_mem_read, mem_mem_write;
    logic [2:0]  mem_mem_funct3;
    logic [1:0]  mem_wb_sel;

    // MEM stage
    logic [31:0] mem_read_data;

    // MEM/WB register outputs (WB stage inputs)
    logic [31:0] wb_alu_result, wb_mem_data, wb_pc_plus4;
    logic [4:0]  wb_rd_addr;
    logic        wb_reg_write;
    logic [1:0]  wb_wb_sel;

    // WB stage
    logic [31:0] wb_data;

    // Hazard and control
    logic stall_pc, stall_if_id, flush_id_ex;
    logic flush_if_id;

    // ==========================================================
    //  STAGE 1 — INSTRUCTION FETCH (IF)
    // ==========================================================

    assign if_pc_plus4 = if_pc + 32'd4;
    assign dbg_pc      = if_pc;
    assign dbg_instr   = if_instr;

    // Branch/jump target address
    logic [31:0] branch_target;
    assign branch_target = ex_jalr
        ? {ex_alu_result[31:1], 1'b0}  // JALR: (rs1+imm), bit0 cleared
        : ex_pc + ex_imm;               // JAL/Branch: PC + offset

    assign ex_pc_sel   = ex_jump | ex_branch_taken;
    assign flush_if_id = ex_pc_sel;    // flush IF/ID on any taken branch/jump

    // PC register
    pc_reg u_pc (
        .clk    (clk),
        .rst    (rst),
        .pc_next(stall_pc ? if_pc : (ex_pc_sel ? branch_target : if_pc_plus4)),
        .pc     (if_pc)
    );

    // Instruction memory
    instr_mem #(.MEM_DEPTH(1024)) u_imem (
        .addr  (if_pc),
        .instr (if_instr)
    );

    // IF → ID pipeline register
    if_id_reg u_if_id (
        .clk      (clk),     .rst  (rst),
        .flush    (flush_if_id),
        .stall    (stall_if_id),
        .pc_in    (if_pc),   .pc_out   (id_pc),
        .instr_in (if_instr),.instr_out(id_instr)
    );

    // ==========================================================
    //  STAGE 2 — INSTRUCTION DECODE (ID)
    // ==========================================================

    // Control unit: decode instruction → control signals
    control_unit u_ctrl (
        .instr      (id_instr),
        .alu_op     (id_alu_op),    .alu_src    (id_alu_src),
        .reg_write  (id_reg_write), .mem_read   (id_mem_read),
        .mem_write  (id_mem_write), .mem_funct3 (id_mem_funct3),
        .wb_sel     (id_wb_sel),    .imm_sel    (id_imm_sel),
        .branch     (id_branch),    .jump       (id_jump),
        .jalr       (id_jalr)
    );

    // Immediate generator
    imm_gen u_immgen (
        .instr   (id_instr),
        .imm_sel (id_imm_sel),
        .imm_out (id_imm)
    );

    // Register file (write port comes from WB stage)
    reg_file u_rf (
        .clk      (clk),
        .rs1_addr (id_instr[19:15]), .rs1_data (id_rs1_data),
        .rs2_addr (id_instr[24:20]), .rs2_data (id_rs2_data),
        .rd_addr  (wb_rd_addr),
        .rd_data  (wb_data),
        .reg_write(wb_reg_write)
    );

    // Hazard detection unit
    hazard_unit u_hazard (
        .id_ex_mem_read (ex_mem_read),
        .id_ex_rd       (ex_rd_addr),
        .if_id_rs1      (id_instr[19:15]),
        .if_id_rs2      (id_instr[24:20]),
        .stall_if_id    (stall_if_id),
        .stall_pc       (stall_pc),
        .flush_id_ex    (flush_id_ex)
    );

    // ID → EX pipeline register
    // ── FIX: flush when load-use hazard (flush_id_ex) ────────
    //         OR when branch/jump taken (ex_pc_sel)
    //   This kills the instruction in ID that was already
    //   partially fetched on the wrong path.
    id_ex_reg u_id_ex (
        .clk           (clk), .rst(rst),
        .flush         (flush_id_ex | ex_pc_sel),   // ← THE FIX (was: flush_id_ex)
        .reg_write_in  (id_reg_write),  .reg_write_out (ex_reg_write),
        .mem_read_in   (id_mem_read),   .mem_read_out  (ex_mem_read),
        .mem_write_in  (id_mem_write),  .mem_write_out (ex_mem_write),
        .mem_funct3_in (id_mem_funct3), .mem_funct3_out(ex_mem_funct3),
        .wb_sel_in     (id_wb_sel),     .wb_sel_out    (ex_wb_sel),
        .alu_src_in    (id_alu_src),    .alu_src_out   (ex_alu_src),
        .alu_op_in     (id_alu_op),     .alu_op_out    (ex_alu_op),
        .branch_in     (id_branch),     .branch_out    (ex_branch),
        .jump_in       (id_jump),       .jump_out      (ex_jump),
        .jalr_in       (id_jalr),       .jalr_out      (ex_jalr),
        .pc_in         (id_pc),         .pc_out        (ex_pc),
        .rs1_data_in   (id_rs1_data),   .rs1_data_out  (ex_rs1_data),
        .rs2_data_in   (id_rs2_data),   .rs2_data_out  (ex_rs2_data),
        .imm_in        (id_imm),        .imm_out       (ex_imm),
        .rs1_addr_in   (id_instr[19:15]), .rs1_addr_out(ex_rs1_addr),
        .rs2_addr_in   (id_instr[24:20]), .rs2_addr_out(ex_rs2_addr),
        .rd_addr_in    (id_instr[11:7]),  .rd_addr_out (ex_rd_addr)
    );

    // ==========================================================
    //  STAGE 3 — EXECUTE (EX)
    // ==========================================================

    assign ex_pc_plus4 = ex_pc + 32'd4;

    // Forwarding unit: decides where each ALU operand comes from
    forward_unit u_fwd (
        .ex_rs1_addr      (ex_rs1_addr),
        .ex_rs2_addr      (ex_rs2_addr),
        .ex_mem_reg_write (mem_reg_write),
        .ex_mem_rd        (mem_rd_addr),
        .mem_wb_reg_write (wb_reg_write),
        .mem_wb_rd        (wb_rd_addr),
        .forward_a        (ex_forward_a),
        .forward_b        (ex_forward_b)
    );

    // Forwarding MUX for operand A
    always_comb begin
        case (ex_forward_a)
            2'b10:   ex_alu_operand_a = mem_alu_result;
            2'b01:   ex_alu_operand_a = wb_data;
            default: ex_alu_operand_a = ex_rs1_data;
        endcase
    end

    // Forwarding MUX for operand B (before imm/rs2 select)
    always_comb begin
        case (ex_forward_b)
            2'b10:   ex_fwd_rs2 = mem_alu_result;
            2'b01:   ex_fwd_rs2 = wb_data;
            default: ex_fwd_rs2 = ex_rs2_data;
        endcase
    end

    // ALU source MUX: use immediate or forwarded rs2
    assign ex_alu_input_b = ex_alu_src ? ex_imm : ex_fwd_rs2;

    // AUIPC: operand A is PC, not rs1
    logic [31:0] final_alu_a;
    assign final_alu_a = (ex_alu_op == ALU_LUI)
                         ? ex_rs1_data                        // LUI: B passes through
                         : (ex_wb_sel == 2'b10 && !ex_jalr)
                           ? ex_pc                            // AUIPC: A = PC
                           : ex_alu_operand_a;                // normal: A = rs1

    // ALU
    alu u_alu (
        .operand_a (final_alu_a),
        .operand_b (ex_alu_input_b),
        .alu_op    (ex_alu_op),
        .result    (ex_alu_result),
        .zero      (ex_alu_zero)
    );

    // Branch condition evaluator
    // ex_mem_funct3 now correctly holds the branch's funct3
    // because control_unit sets mem_funct3=funct3 for branches.
    always_comb begin
        ex_branch_taken = 1'b0;
        if (ex_branch) begin
            case (ex_mem_funct3)
                3'b000: ex_branch_taken = ex_alu_zero;        // BEQ
                3'b001: ex_branch_taken = ~ex_alu_zero;       // BNE
                3'b100: ex_branch_taken = ex_alu_result[0];   // BLT
                3'b101: ex_branch_taken = ~ex_alu_result[0];  // BGE
                3'b110: ex_branch_taken = ex_alu_result[0];   // BLTU
                3'b111: ex_branch_taken = ~ex_alu_result[0];  // BGEU
                default: ex_branch_taken = 1'b0;
            endcase
        end
    end

    // EX → MEM pipeline register
    ex_mem_reg u_ex_mem (
        .clk           (clk), .rst(rst),
        .reg_write_in  (ex_reg_write),   .reg_write_out (mem_reg_write),
        .mem_read_in   (ex_mem_read),    .mem_read_out  (mem_mem_read),
        .mem_write_in  (ex_mem_write),   .mem_write_out (mem_mem_write),
        .mem_funct3_in (ex_mem_funct3),  .mem_funct3_out(mem_mem_funct3),
        .wb_sel_in     (ex_wb_sel),      .wb_sel_out    (mem_wb_sel),
        .alu_result_in (ex_alu_result),  .alu_result_out(mem_alu_result),
        .rs2_data_in   (ex_fwd_rs2),     .rs2_data_out  (mem_rs2_data),
        .pc_plus4_in   (ex_pc_plus4),    .pc_plus4_out  (mem_pc_plus4),
        .rd_addr_in    (ex_rd_addr),     .rd_addr_out   (mem_rd_addr)
    );

    // ==========================================================
    //  STAGE 4 — MEMORY (MEM)
    // ==========================================================

    data_mem #(.MEM_DEPTH(1024)) u_dmem (
        .clk        (clk),
        .mem_read   (mem_mem_read),
        .mem_write  (mem_mem_write),
        .funct3     (mem_mem_funct3),
        .addr       (mem_alu_result),
        .write_data (mem_rs2_data),
        .read_data  (mem_read_data)
    );

    // MEM → WB pipeline register
    mem_wb_reg u_mem_wb (
        .clk           (clk), .rst(rst),
        .reg_write_in  (mem_reg_write),  .reg_write_out (wb_reg_write),
        .wb_sel_in     (mem_wb_sel),     .wb_sel_out    (wb_wb_sel),
        .alu_result_in (mem_alu_result), .alu_result_out(wb_alu_result),
        .mem_data_in   (mem_read_data),  .mem_data_out  (wb_mem_data),
        .pc_plus4_in   (mem_pc_plus4),   .pc_plus4_out  (wb_pc_plus4),
        .rd_addr_in    (mem_rd_addr),    .rd_addr_out   (wb_rd_addr)
    );

    // ==========================================================
    //  STAGE 5 — WRITEBACK (WB)
    // ==========================================================

    always_comb begin
        case (wb_wb_sel)
            2'b00:   wb_data = wb_alu_result;  // ALU result
            2'b01:   wb_data = wb_mem_data;    // memory load
            2'b10:   wb_data = wb_pc_plus4;    // return address (JAL/JALR)
            default: wb_data = wb_alu_result;
        endcase
    end

    assign dbg_wb_data = wb_data;

endmodule
