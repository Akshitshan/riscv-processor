//  Module: riscv_top — Single-Cycle RV32IM Processor
//  Purpose: Wires every submodule into one complete CPU.

module riscv_top
    import riscv_pkg::*;
(
    input logic clk,
    input logic rst,
    output logic [31:0] dbg_pc,
    output logic [31:0] dbg_instr,
    output logic [31:0] dbg_alu_result
);

    // ── Wires between modules ─────────────────────────────────
    logic [31:0] pc, pc_plus4, pc_branch, pc_next;
    logic [31:0] instr;
    logic [31:0] rs1_data, rs2_data, rd_data;
    logic [31:0] imm;
    logic [31:0] alu_operand_a, alu_operand_b;
    logic [31:0] alu_result;
    logic        alu_zero;
    logic [31:0] mem_read_data;

    // Control signals
    alu_op_t     alu_op;
    logic        alu_src, reg_write, mem_read, mem_write;
    logic [2:0]  mem_funct3;
    logic [1:0]  wb_sel;
    imm_sel_t    imm_sel;
    logic        branch, jump, jalr_sel;
    logic        branch_taken, pc_sel;

    // ── Debug taps ────────────────────────────────────────────
    assign dbg_pc         = pc;
    assign dbg_instr      = instr;
    assign dbg_alu_result = alu_result;

    // ── PC arithmetic ─────────────────────────────────────────
    assign pc_plus4  = pc + 32'd4;

    // Branch/jump target:
    //   JALR  → (rs1 + imm) with bit 0 forced to 0
    //   JAL/B → PC + imm
    assign pc_branch = jalr_sel ? {alu_result[31:1], 1'b0} : (pc + imm);
    assign pc_sel    = jump | branch_taken;
    assign pc_next   = pc_sel ? pc_branch : pc_plus4;

    // ALU second operand: register or immediate
    assign alu_operand_b = alu_src ? imm : rs2_data;

    // AUIPC needs PC as operand_a; all others use rs1
    assign alu_operand_a = (instr[6:0] == 7'b0010111) ? pc : rs1_data;

    // Writeback mux: ALU result / memory data / return address
    always_comb begin
        case (wb_sel)
            2'b00:   rd_data = alu_result;
            2'b01:   rd_data = mem_read_data;
            2'b10:   rd_data = pc_plus4;
            default: rd_data = alu_result;
        endcase
    end

    // Branch condition evaluator
    always_comb begin
        branch_taken = 1'b0;
        if (branch) begin
            case (instr[14:12])
                3'b000: branch_taken = alu_zero;        // BEQ
                3'b001: branch_taken = ~alu_zero;       // BNE
                3'b100: branch_taken = alu_result[0];   // BLT
                3'b101: branch_taken = ~alu_result[0];  // BGE
                3'b110: branch_taken = alu_result[0];   // BLTU
                3'b111: branch_taken = ~alu_result[0];  // BGEU
                default: branch_taken = 1'b0;
            endcase
        end
    end

    // ── Module instantiations ─────────────────────────────────
    pc_reg u_pc (
        .clk(clk), .rst(rst), .pc_next(pc_next), .pc(pc)
    );

    instr_mem #(.MEM_DEPTH(1024)) u_imem (
        .addr(pc), .instr(instr)
    );

    control_unit u_ctrl (
        .instr(instr),
        .alu_op(alu_op),       .alu_src(alu_src),
        .reg_write(reg_write), .mem_read(mem_read),
        .mem_write(mem_write), .mem_funct3(mem_funct3),
        .wb_sel(wb_sel),       .imm_sel(imm_sel),
        .branch(branch),       .jump(jump),
        .jalr(jalr_sel)
    );

    imm_gen u_immgen (
        .instr(instr), .imm_sel(imm_sel), .imm_out(imm)
    );

    reg_file u_rf (
        .clk(clk),
        .rs1_addr(instr[19:15]), .rs1_data(rs1_data),
        .rs2_addr(instr[24:20]), .rs2_data(rs2_data),
        .rd_addr(instr[11:7]),   .rd_data(rd_data),
        .reg_write(reg_write)
    );

    alu u_alu (
        .operand_a(alu_operand_a), .operand_b(alu_operand_b),
        .alu_op(alu_op),
        .result(alu_result),       .zero(alu_zero)
    );

    data_mem #(.MEM_DEPTH(1024)) u_dmem (
        .clk(clk),
        .mem_read(mem_read),   .mem_write(mem_write),
        .funct3(mem_funct3),   .addr(alu_result),
        .write_data(rs2_data), .read_data(mem_read_data)
    );

endmodule
