// ============================================================
//  MODULE: control_unit — Instruction Decoder
//
//  FIXES:
//  1. Secondary decode now checks OP_BRANCH for ALL funct3
//     values, not just funct3=000. This fixes BNE, BLT,
//     BGE, BLTU, BGEU which were getting wrong ALU ops.
//
//  2. funct3=010 checks for MULHSU (M-ext) before SLT.
//     funct3=011 checks for MULHU  (M-ext) before SLTU.
//     funct3=111 checks for BGEU (branch) then REMU (M-ext)
//     then AND — all three cases now handled correctly.
//
//  3. OP_BRANCH passes funct3 through mem_funct3 so the
//     branch evaluator in riscv_pipeline knows BEQ vs BNE
//     vs BLT etc. (was defaulting to 3'b010 = word access).
// ============================================================

`timescale 1ns/1ps

module control_unit
    import riscv_pkg::*;
(
    input  logic [31:0] instr,
    output alu_op_t     alu_op,
    output logic        alu_src,
    output logic        reg_write,
    output logic        mem_read,
    output logic        mem_write,
    output logic [2:0]  mem_funct3,
    output logic [1:0]  wb_sel,
    output imm_sel_t    imm_sel,
    output logic        branch,
    output logic        jump,
    output logic        jalr
);

    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [6:0] funct7;

    assign opcode = instr[6:0];
    assign funct3 = instr[14:12];
    assign funct7 = instr[31:25];

    localparam OP_LUI    = 7'b0110111;
    localparam OP_AUIPC  = 7'b0010111;
    localparam OP_JAL    = 7'b1101111;
    localparam OP_JALR   = 7'b1100111;
    localparam OP_BRANCH = 7'b1100011;
    localparam OP_LOAD   = 7'b0000011;
    localparam OP_STORE  = 7'b0100011;
    localparam OP_IMM    = 7'b0010011;
    localparam OP_REG    = 7'b0110011;
    localparam OP_SYSTEM = 7'b1110011;

    always_comb begin
        // ── Safe defaults ──────────────────────────────────
        alu_op    = ALU_ADD;
        alu_src   = 1'b0;
        reg_write = 1'b0;
        mem_read  = 1'b0;
        mem_write = 1'b0;
        mem_funct3= 3'b010;
        wb_sel    = 2'b00;
        imm_sel   = IMM_X;
        branch    = 1'b0;
        jump      = 1'b0;
        jalr      = 1'b0;

        case (opcode)
            OP_LUI: begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = ALU_LUI; imm_sel = IMM_U;
            end
            OP_AUIPC: begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = ALU_ADD; imm_sel = IMM_U;
            end
            OP_JAL: begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = ALU_ADD; imm_sel = IMM_J;
                wb_sel = 2'b10; jump = 1'b1;
            end
            OP_JALR: begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = ALU_ADD; imm_sel = IMM_I;
                wb_sel = 2'b10; jump = 1'b1; jalr = 1'b1;
            end
            OP_BRANCH: begin
                alu_src    = 1'b0;
                imm_sel    = IMM_B;
                branch     = 1'b1;
                // Pass actual funct3 so pipeline branch evaluator
                // can distinguish BEQ/BNE/BLT/BGE/BLTU/BGEU
                mem_funct3 = funct3;
            end
            OP_LOAD: begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = ALU_ADD; imm_sel = IMM_I;
                mem_read = 1'b1; mem_funct3 = funct3; wb_sel = 2'b01;
            end
            OP_STORE: begin
                alu_src = 1'b1; alu_op = ALU_ADD;
                imm_sel = IMM_S; mem_write = 1'b1; mem_funct3 = funct3;
            end
            OP_IMM: begin
                reg_write = 1'b1; alu_src = 1'b1; imm_sel = IMM_I;
            end
            OP_REG: begin
                reg_write = 1'b1; alu_src = 1'b0; imm_sel = IMM_X;
            end
            OP_SYSTEM: begin end  // ECALL/EBREAK: NOP for now
            default:   begin end
        endcase

        // ── Secondary decode: ALU op from funct3 + funct7 ──
        // Runs for OP-IMM, OP-REG, and OP-BRANCH.
        // Priority inside each case:
        //   1. OP_BRANCH check  (branch instructions)
        //   2. OP_REG + M-ext   (multiply/divide)
        //   3. OP_REG funct7[5] (SUB, SRA)
        //   4. Default          (base ALU or immediate ALU)

        if (opcode == OP_IMM || opcode == OP_REG || opcode == OP_BRANCH) begin
            case (funct3)

                // funct3=000: BEQ, ADD/ADDI, SUB, MUL
                3'b000: begin
                    if (opcode == OP_BRANCH)
                        alu_op = ALU_SUB;   // BEQ and BNE both subtract
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = ALU_MUL;   // MUL
                    else if (opcode == OP_REG && funct7[5])
                        alu_op = ALU_SUB;   // SUB (funct7 bit 5 = 1)
                    else
                        alu_op = ALU_ADD;   // ADD / ADDI
                end

                // funct3=001: BNE, SLL/SLLI, MULH
                // FIX: added OP_BRANCH check for BNE
                3'b001: begin
                    if (opcode == OP_BRANCH)
                        alu_op = ALU_SUB;   // BNE: subtract, branch if ~zero
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = ALU_MULH;  // MULH
                    else
                        alu_op = ALU_SLL;   // SLL / SLLI
                end

                // funct3=010: SLT/SLTI, MULHSU
                // Note: no branch instruction uses funct3=010
                3'b010: begin
                    if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = ALU_MULHSU; // MULHSU (signed×unsigned upper)
                    else
                        alu_op = ALU_SLT;    // SLT / SLTI
                end

                // funct3=011: SLTU/SLTIU, MULHU
                // Note: no branch instruction uses funct3=011
                3'b011: begin
                    if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = ALU_MULHU;  // MULHU (unsigned×unsigned upper)
                    else
                        alu_op = ALU_SLTU;   // SLTU / SLTIU
                end

                // funct3=100: BLT, XOR/XORI, DIV
                // FIX: added OP_BRANCH check for BLT (user spotted this!)
                3'b100: begin
                    if (opcode == OP_BRANCH)
                        alu_op = ALU_SLT;   // BLT: set-less-than signed
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = ALU_DIV;   // DIV
                    else
                        alu_op = ALU_XOR;   // XOR / XORI
                end

                // funct3=101: BGE, SRL/SRA/SRLI/SRAI, DIVU
                // FIX: branch check must come FIRST
                3'b101: begin
                    if (opcode == OP_BRANCH)
                        alu_op = ALU_SLT;   // BGE: SLT then ~result in evaluator
                    else if (funct7[5])
                        alu_op = ALU_SRA;   // SRA / SRAI
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = ALU_DIVU;  // DIVU
                    else
                        alu_op = ALU_SRL;   // SRL / SRLI
                end

                // funct3=110: BLTU, OR/ORI, REM
                3'b110: begin
                    if (opcode == OP_BRANCH)
                        alu_op = ALU_SLTU;  // BLTU: set-less-than unsigned
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = ALU_REM;   // REM (signed)
                    else
                        alu_op = ALU_OR;    // OR / ORI
                end

                // funct3=111: BGEU, AND/ANDI, REMU
                // FIX: three-way check — branch → REMU → AND
                3'b111: begin
                    if (opcode == OP_BRANCH)
                        alu_op = ALU_SLTU;  // BGEU: SLTU then ~result in evaluator
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = ALU_REMU;  // REMU (unsigned remainder)
                    else
                        alu_op = ALU_AND;   // AND / ANDI
                end

            endcase
        end
    end

endmodule
