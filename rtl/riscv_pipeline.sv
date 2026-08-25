// ============================================================
//  MODULE: riscv_pipeline — 5-Stage Pipelined RV32IM CPU
//  PHASE 5: Now with branch prediction
//
//  WHAT CHANGED FROM PHASE 3/4:
//
//  1. Added a branch_predictor instance. Every cycle, it looks
//     at the PC we're about to fetch and gives us a guess:
//     "taken" or "not-taken", plus a target address if taken.
//
//  2. The IF stage now uses that guess to decide what to fetch
//     next, INSTEAD of always assuming "not taken" (PC+4).
//
//  3. The guess rides along with the instruction through the
//     pipeline registers (the "predicted_taken" signal you saw
//     added to if_id_reg and id_ex_reg).
//
//  4. In the EX stage, once we know the REAL outcome, we compare
//     it to what we guessed. Three outcomes:
//       - Guessed right  → no penalty, pipeline just keeps going
//       - Guessed wrong  → flush 2 instructions, fix the PC
//       - Not a branch   → guess is irrelevant, ignored
//
//  5. We also feed the real outcome back into the predictor
//     (the "update" interface) so it learns for next time.
// ============================================================

`timescale 1ns/1ps

module riscv_pipeline
    import riscv_pkg::*;
(
    input  logic        clk,
    input  logic        rst,
    output logic [31:0] dbg_pc,
    output logic [31:0] dbg_instr,
    output logic [31:0] dbg_wb_data,

    // ── NEW debug outputs for measuring predictor performance ──
    output logic        dbg_branch_resolved,  // pulses when any branch finishes in EX
    output logic        dbg_mispredict         // pulses when that branch was guessed wrong
);

    // ==========================================================
    //  SIGNAL DECLARATIONS
    // ==========================================================

    logic [31:0] if_pc, if_pc_plus4, if_instr;
    logic [31:0] id_pc, id_instr;

    logic [31:0] id_rs1_data, id_rs2_data, id_imm;
    logic        id_reg_write, id_mem_read, id_mem_write;
    logic [2:0]  id_mem_funct3;
    logic [1:0]  id_wb_sel;
    logic        id_alu_src, id_branch, id_jump, id_jalr;
    alu_op_t     id_alu_op;
    imm_sel_t    id_imm_sel;

    logic [31:0] ex_pc, ex_rs1_data, ex_rs2_data, ex_imm;
    logic [4:0]  ex_rs1_addr, ex_rs2_addr, ex_rd_addr;
    logic        ex_reg_write, ex_mem_read, ex_mem_write;
    logic [2:0]  ex_mem_funct3;
    logic [1:0]  ex_wb_sel;
    logic        ex_alu_src, ex_branch, ex_jump, ex_jalr;
    alu_op_t     ex_alu_op;

    logic [31:0] ex_alu_operand_a, ex_alu_input_b;
    logic [31:0] ex_alu_result;
    logic        ex_alu_zero;
    logic [31:0] ex_pc_plus4;
    logic        ex_branch_taken;
    logic [1:0]  ex_forward_a, ex_forward_b;
    logic [31:0] ex_fwd_rs2;

    logic [31:0] mem_alu_result, mem_rs2_data, mem_pc_plus4;
    logic [4:0]  mem_rd_addr;
    logic        mem_reg_write, mem_mem_read, mem_mem_write;
    logic [2:0]  mem_mem_funct3;
    logic [1:0]  mem_wb_sel;

    logic [31:0] mem_read_data;

    logic [31:0] wb_alu_result, wb_mem_data, wb_pc_plus4;
    logic [4:0]  wb_rd_addr;
    logic        wb_reg_write;
    logic [1:0]  wb_wb_sel;

    logic [31:0] wb_data;

    logic stall_pc, stall_if_id, flush_id_ex;
    logic flush_if_id;

    // ── NEW: branch predictor signals ──────────────────────────
    logic        if_predict_taken;    // predictor's guess for if_pc
    logic [31:0] if_predict_target;   // where to fetch if guess = taken
    logic        id_predicted_taken;  // guess, carried into ID
    logic        ex_predicted_taken;  // guess, carried into EX

    logic [31:0] ex_branch_target;    // pc + imm: the "real" branch/JAL target
    logic        ex_mispredict;       // 1 = our guess for this branch was wrong
    logic        ex_redirect;         // 1 = PC must be corrected this cycle
    logic [31:0] ex_redirect_target;  // where to correct the PC to

    // ==========================================================
    //  STAGE 1 — INSTRUCTION FETCH (IF)
    // ==========================================================

    assign if_pc_plus4 = if_pc + 32'd4;
    assign dbg_pc       = if_pc;
    assign dbg_instr    = if_instr;

    // ── Branch/JAL/JALR target computed once, reused everywhere ─
    // For a plain branch (BEQ etc.) or JAL, target = PC + immediate.
    // JALR is different — its target comes from a register, not PC.
    assign ex_branch_target = ex_pc + ex_imm;

    // ── Did we guess wrong? ────────────────────────────────────
    // Only branches (not jumps) go through the predictor, so we
    // only check misprediction when ex_branch=1.
    // "Wrong" means: what we predicted != what actually happened.
    assign ex_mispredict = ex_branch && (ex_predicted_taken != ex_branch_taken);

    // ── Does the PC need correcting this cycle? ─────────────────
    // Two reasons to redirect: an unconditional jump (always needs
    // it, since we never try to predict those), or a mispredicted
    // branch (we guessed and got it wrong).
    assign ex_redirect = ex_jump | ex_mispredict;

    // ── Where do we redirect to? ────────────────────────────────
    // JALR: target comes from a register (rs1 + imm), bit 0 cleared.
    // JAL:  target is PC + imm (always taken, no guessing needed).
    // Mispredicted branch: if it turned out taken, go to the real
    //   target. If it turned out NOT taken, go back to the normal
    //   fall-through address (pc_plus4) — undoing our wrong guess.
    assign ex_redirect_target =
        ex_jalr                ? {ex_alu_result[31:1], 1'b0} :
        ex_jump                ? ex_branch_target :
        ex_branch_taken         ? ex_branch_target :
                                  ex_pc_plus4;

    // Any redirect from EX kills the 2 instructions already fetched
    // on the (now known to be) wrong path.
    assign flush_if_id = ex_redirect;

    // ── The actual next-PC decision (this is the key change) ───
    // Priority order:
    //   1. Stalled (load-use hazard)? Don't move at all.
    //   2. EX says "I need to correct you"? Obey that — it overrides
    //      everything, because EX has ground truth this cycle.
    //   3. Otherwise, trust the predictor: if it says taken, fetch
    //      from its target; if not, fetch the next sequential
    //      instruction as usual.
    logic [31:0] next_pc;
    assign next_pc = stall_pc            ? if_pc :
                     ex_redirect          ? ex_redirect_target :
                     if_predict_taken     ? if_predict_target :
                                            if_pc_plus4;

    pc_reg u_pc (
        .clk    (clk),
        .rst    (rst),
        .pc_next(next_pc),
        .pc     (if_pc)
    );

    instr_mem #(.MEM_DEPTH(1024)) u_imem (
        .addr  (if_pc),
        .instr (if_instr)
    );

    // ── Branch predictor: makes a guess every single cycle ──────
    // It doesn't know yet if if_pc even points to a branch — that's
    // fine, because non-branch PCs simply never get "trained" (see
    // update_valid below), so they always predict "not taken" by
    // default and cause no harm.
    branch_predictor #(.BHT_BITS(6)) u_bp (
        .clk            (clk),
        .rst            (rst),
        .predict_pc     (if_pc),
        .predict_taken  (if_predict_taken),
        .predict_target (if_predict_target),
        .update_valid   (ex_branch),          // only branches train it
        .update_pc      (ex_pc),
        .update_taken   (ex_branch_taken),
        .update_target  (ex_branch_target)
    );

    if_id_reg u_if_id (
        .clk               (clk), .rst(rst),
        .flush             (flush_if_id),
        .stall             (stall_if_id),
        .pc_in             (if_pc),
        .instr_in          (if_instr),
        .predicted_taken_in(if_predict_taken),
        .pc_out            (id_pc),
        .instr_out         (id_instr),
        .predicted_taken_out(id_predicted_taken)
    );

    // ==========================================================
    //  STAGE 2 — INSTRUCTION DECODE (ID)
    // ==========================================================

    control_unit u_ctrl (
        .instr      (id_instr),
        .alu_op     (id_alu_op),
        .alu_src    (id_alu_src),
        .reg_write  (id_reg_write),
        .mem_read   (id_mem_read),
        .mem_write  (id_mem_write),
        .mem_funct3 (id_mem_funct3),
        .wb_sel     (id_wb_sel),
        .imm_sel    (id_imm_sel),
        .branch     (id_branch),
        .jump       (id_jump),
        .jalr       (id_jalr)
    );

    imm_gen u_immgen (
        .instr   (id_instr),
        .imm_sel (id_imm_sel),
        .imm_out (id_imm)
    );

    reg_file u_rf (
        .clk       (clk),
        .rs1_addr  (id_instr[19:15]),
        .rs2_addr  (id_instr[24:20]),
        .rs1_data  (id_rs1_data),
        .rs2_data  (id_rs2_data),
        .rd_addr   (wb_rd_addr),
        .rd_data   (wb_data),
        .reg_write (wb_reg_write)
    );

    hazard_unit u_hazard (
        .id_ex_mem_read (ex_mem_read),
        .id_ex_rd       (ex_rd_addr),
        .if_id_rs1      (id_instr[19:15]),
        .if_id_rs2      (id_instr[24:20]),
        .stall_if_id    (stall_if_id),
        .stall_pc       (stall_pc),
        .flush_id_ex    (flush_id_ex)
    );

    id_ex_reg u_id_ex (
        .clk           (clk), .rst(rst),
        .flush         (flush_id_ex | ex_redirect),
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
        .rd_addr_in    (id_instr[11:7]),  .rd_addr_out (ex_rd_addr),
        .predicted_taken_in (id_predicted_taken),
        .predicted_taken_out(ex_predicted_taken)
    );

    // ==========================================================
    //  STAGE 3 — EXECUTE (EX)
    // ==========================================================

    assign ex_pc_plus4 = ex_pc + 32'd4;

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

    always_comb begin
        case (ex_forward_a)
            2'b10:   ex_alu_operand_a = mem_alu_result;
            2'b01:   ex_alu_operand_a = wb_data;
            default: ex_alu_operand_a = ex_rs1_data;
        endcase
    end

    always_comb begin
        case (ex_forward_b)
            2'b10:   ex_fwd_rs2 = mem_alu_result;
            2'b01:   ex_fwd_rs2 = wb_data;
            default: ex_fwd_rs2 = ex_rs2_data;
        endcase
    end

    assign ex_alu_input_b = ex_alu_src ? ex_imm : ex_fwd_rs2;

    logic [31:0] final_alu_a;
    assign final_alu_a = (ex_alu_op == ALU_LUI)
                         ? ex_rs1_data
                         : (ex_wb_sel == 2'b10 && !ex_jalr)
                           ? ex_pc
                           : ex_alu_operand_a;

    alu u_alu (
        .operand_a (final_alu_a),
        .operand_b (ex_alu_input_b),
        .alu_op    (ex_alu_op),
        .result    (ex_alu_result),
        .zero      (ex_alu_zero)
    );

    // Branch condition evaluator — figures out the REAL outcome
    always_comb begin
        ex_branch_taken = 1'b0;
        if (ex_branch) begin
            case (ex_mem_funct3)
                3'b000: ex_branch_taken = ex_alu_zero;
                3'b001: ex_branch_taken = ~ex_alu_zero;
                3'b100: ex_branch_taken = ex_alu_result[0];
                3'b101: ex_branch_taken = ~ex_alu_result[0];
                3'b110: ex_branch_taken = ex_alu_result[0];
                3'b111: ex_branch_taken = ~ex_alu_result[0];
                default: ex_branch_taken = 1'b0;
            endcase
        end
    end

    // ── Debug outputs for the testbench to measure accuracy ────
    assign dbg_branch_resolved = ex_branch;
    assign dbg_mispredict      = ex_mispredict;

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
            2'b00:   wb_data = wb_alu_result;
            2'b01:   wb_data = wb_mem_data;
            2'b10:   wb_data = wb_pc_plus4;
            default: wb_data = wb_alu_result;
        endcase
    end

    assign dbg_wb_data = wb_data;

endmodule
