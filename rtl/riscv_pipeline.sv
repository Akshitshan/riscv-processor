//  Module: riscv_pipeline — 5-Stage Pipelined RV32IM CPU
//
//  This is the top-level that wires all five stages together.
//  The five stages:
//    IF  — Instruction Fetch:    get the instruction from memory
//    ID  — Instruction Decode:   figure out what it does, read registers
//    EX  — Execute:              run the ALU, compute addresses
//    MEM — Memory:               read/write data memory
//    WB  — Writeback:            write the result back to a register

`timescale 1ns/1ps

module riscv_pipeline
    import riscv_pkg::*;
(
    input logic clk,
    input logic rst,

    // Debug outputs
    output logic [31:0] dbg_pc,
    output logic [31:0] dbg_instr,
    output logic [31:0] dbg_wb_data
);

    //  SIGNAL DECLARATIONS: All wires between modules. Grouped by pipeline stage.

    // ── IF stage signals ──────────────────────────────────────
    logic [31:0] if_pc;           // Current PC value
    logic [31:0] if_pc_plus4;     // PC + 4
    logic [31:0] if_instr;        // Instruction from memory

    // ── IF/ID pipeline register outputs ──────────────────────
    logic [31:0] id_pc;           // PC carried into decode stage
    logic [31:0] id_instr;        // Instruction being decoded

    // ── ID stage signals ──────────────────────────────────────
    logic [31:0] id_rs1_data;     // Register file read: rs1
    logic [31:0] id_rs2_data;     // Register file read: rs2
    logic [31:0] id_imm;          // Sign-extended immediate
    // Control signals decoded from the instruction:
    logic        id_reg_write, id_mem_read, id_mem_write;
    logic [2:0]  id_mem_funct3;
    logic [1:0]  id_wb_sel;
    logic        id_alu_src, id_branch, id_jump, id_jalr;
    alu_op_t     id_alu_op;
    imm_sel_t    id_imm_sel;

    // ── ID/EX pipeline register outputs ──────────────────────
    logic [31:0] ex_pc, ex_rs1_data, ex_rs2_data, ex_imm;
    logic [4:0]  ex_rs1_addr, ex_rs2_addr, ex_rd_addr;
    logic        ex_reg_write, ex_mem_read, ex_mem_write;
    logic [2:0]  ex_mem_funct3;
    logic [1:0]  ex_wb_sel;
    logic        ex_alu_src, ex_branch, ex_jump, ex_jalr;
    alu_op_t     ex_alu_op;

    // ── EX stage signals ──────────────────────────────────────
    logic [31:0] ex_alu_operand_a;  // ALU input A (after forwarding mux)
    logic [31:0] ex_alu_operand_b;  // ALU input B (after forwarding mux)
    logic [31:0] ex_alu_input_b;    // ALU input B before imm mux
    logic [31:0] ex_alu_result;     // ALU output
    logic        ex_alu_zero;       // ALU zero flag
    logic [31:0] ex_pc_plus4;       // PC+4 for this instruction
    logic [31:0] ex_branch_target;  // Computed branch/jump target
    logic        ex_branch_taken;   // Did the branch condition pass?
    logic        ex_pc_sel;         // Should we take the jump/branch?
    logic [1:0]  ex_forward_a;      // Forwarding mux select for A
    logic [1:0]  ex_forward_b;      // Forwarding mux select for B
    logic [31:0] ex_fwd_rs2;        // rs2 after forwarding (needed for stores)

    // ── EX/MEM pipeline register outputs ─────────────────────
    logic [31:0] mem_alu_result, mem_rs2_data, mem_pc_plus4;
    logic [4:0]  mem_rd_addr;
    logic        mem_reg_write, mem_mem_read, mem_mem_write;
    logic [2:0]  mem_mem_funct3;
    logic [1:0]  mem_wb_sel;

    // ── MEM stage signals ─────────────────────────────────────
    logic [31:0] mem_read_data;     // Data loaded from data memory

    // ── MEM/WB pipeline register outputs ─────────────────────
    logic [31:0] wb_alu_result, wb_mem_data, wb_pc_plus4;
    logic [4:0]  wb_rd_addr;
    logic        wb_reg_write;
    logic [1:0]  wb_wb_sel;

    // ── WB stage signals ──────────────────────────────────────
    logic [31:0] wb_data;           // Final data written to register file

    // ── Hazard and PC control ─────────────────────────────────
    logic stall_pc, stall_if_id, flush_id_ex;
    logic flush_if_id;       // Flush on branch taken

    // ==========================================================
    //  STAGE 1: INSTRUCTION FETCH (IF)
    //  Get the instruction at the current PC address.
    // ==========================================================

    assign if_pc_plus4 = if_pc + 32'd4;

    // The PC decides what to fetch next:
    //   - If a branch/jump was taken in EX: jump to that target
    //   - Otherwise: go to the next sequential instruction
    logic [31:0] next_pc;
    logic [31:0] branch_target;

    assign branch_target = ex_jalr
        ? {ex_alu_result[31:1], 1'b0}  // JALR: rs1+imm, bit0 cleared
        : ex_pc + ex_imm;               // JAL/Branch: PC + offset

    assign ex_pc_sel = ex_jump | ex_branch_taken;
    assign next_pc   = ex_pc_sel ? branch_target : if_pc_plus4;

    // Flush IF/ID when a branch is taken (wrong instructions fetched)
    assign flush_if_id = ex_pc_sel;

    assign dbg_pc = if_pc;

    // PC register
    pc_reg u_pc (
        .clk    (clk),
        .rst    (rst),
        .pc_next(stall_pc ? if_pc : next_pc),  // hold PC if stalled
        .pc     (if_pc)
    );

    // Instruction memory
    instr_mem #(.MEM_DEPTH(1024)) u_imem (
        .addr  (if_pc),
        .instr (if_instr)
    );

    assign dbg_instr = if_instr;

    // IF → ID pipeline register
    if_id_reg u_if_id (
        .clk      (clk), .rst(rst),
        .flush    (flush_if_id),
        .stall    (stall_if_id),
        .pc_in    (if_pc),
        .instr_in (if_instr),
        .pc_out   (id_pc),
        .instr_out(id_instr)
    );

    // ==========================================================
    //  STAGE 2: INSTRUCTION DECODE (ID)
    //  Figure out what the instruction does and read registers.
    // ==========================================================

    // Control unit: reads instruction, sets all control signals
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

    // Immediate generator: extracts and sign-extends the immediate
    imm_gen u_immgen (
        .instr   (id_instr),
        .imm_sel (id_imm_sel),
        .imm_out (id_imm)
    );

    // Register file: read rs1 and rs2
    // NOTE: rd_addr/rd_data/reg_write come from the WB stage —
    // this is the "writeback" happening simultaneously with decode.
    // This is why the register file has both read and write ports.
    reg_file u_rf (
        .clk      (clk),
        .rs1_addr (id_instr[19:15]),
        .rs2_addr (id_instr[24:20]),
        .rs1_data (id_rs1_data),
        .rs2_data (id_rs2_data),
        .rd_addr  (wb_rd_addr),     // ← from WB stage
        .rd_data  (wb_data),        // ← from WB stage
        .reg_write(wb_reg_write)    // ← from WB stage
    );

    // Hazard detection: do we need to stall?
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
    id_ex_reg u_id_ex (
        .clk           (clk), .rst(rst),
        .flush         (flush_id_ex),
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
        .rd_addr_in    (id_instr[11:7]), .rd_addr_out  (ex_rd_addr)
    );

    // ==========================================================
    //  STAGE 3: EXECUTE (EX)
    //  Run the ALU. Decide if a branch is taken. Compute addresses.
    // ==========================================================

    assign ex_pc_plus4 = ex_pc + 32'd4;

    // Forwarding unit: decides which value each operand should use
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

    // Forwarding MUX for operand A:
    //   00 → register file value (no hazard)
    //   10 → EX/MEM forwarded value (one instruction ago)
    //   01 → MEM/WB forwarded value (two instructions ago)
    always_comb begin
        case (ex_forward_a)
            2'b10:   ex_alu_operand_a = mem_alu_result; // from EX/MEM
            2'b01:   ex_alu_operand_a = wb_data;        // from MEM/WB
            default: ex_alu_operand_a = ex_rs1_data;    // from register file
        endcase
    end

    // Forwarding MUX for operand B (before the imm/rs2 select mux)
    always_comb begin
        case (ex_forward_b)
            2'b10:   ex_fwd_rs2 = mem_alu_result;
            2'b01:   ex_fwd_rs2 = wb_data;
            default: ex_fwd_rs2 = ex_rs2_data;
        endcase
    end

    // ALU source MUX:
    //   alu_src=0 → use forwarded rs2 (R-type instructions)
    //   alu_src=1 → use immediate    (I/S/B/U/J-type instructions)
    // AUIPC special case: use PC as operand A
    logic [31:0] final_alu_a;
    assign final_alu_a    = (ex_alu_op == ALU_LUI) ? ex_rs1_data :
                            (ex_wb_sel == 2'b10 && !ex_jalr) ? ex_pc :
                            ex_alu_operand_a;
    assign ex_alu_input_b = ex_alu_src ? ex_imm : ex_fwd_rs2;

    // ALU
    alu u_alu (
        .operand_a (ex_alu_operand_a),
        .operand_b (ex_alu_input_b),
        .alu_op    (ex_alu_op),
        .result    (ex_alu_result),
        .zero      (ex_alu_zero)
    );

    // Branch condition evaluator
    always_comb begin
        ex_branch_taken = 1'b0;
        if (ex_branch) begin
            case (ex_mem_funct3)  // funct3 passed through pipeline
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
    //  STAGE 4: MEMORY ACCESS (MEM)
    //  Read from or write to data memory.
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
    //  STAGE 5: WRITEBACK (WB)
    //  Choose what to write to the register file and write it.
    // ==========================================================

    // Writeback MUX: what goes into the register?
    //   00 → ALU result   (arithmetic, logic, shifts, LUI, AUIPC)
    //   01 → Memory data  (loads: LW, LH, LB, LHU, LBU)
    //   10 → PC + 4       (JAL/JALR: the return address)
    always_comb begin
        case (wb_wb_sel)
            2'b00:   wb_data = wb_alu_result;
            2'b01:   wb_data = wb_mem_data;
            2'b10:   wb_data = wb_pc_plus4;
            default: wb_data = wb_alu_result;
        endcase
    end

    assign dbg_wb_data = wb_data;

    // The actual register file write happens inside u_rf above
    // (the reg_file module's write port is connected to wb_* signals)

endmodule
