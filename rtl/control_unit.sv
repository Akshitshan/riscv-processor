// Module: control_unit- Instruction Decoder
// Purpose: Main character of the decoding process, takes an intsruction
//          and breaks it down into all the necessary control signals

// V2: Removing 'import risv_pkg::*' bcz yosys is choking at the import call

`timescale 1ns/1ps

module control_unit (
    input logic [31:0] instr,
    output logic alu_src,
    output logic reg_write,
    output logic mem_read,
    output logic mem_write,
    output logic [2:0] mem_funct3,
    output logic [1:0] wb_sel,
    output logic branch,
    output logic jump,
    output logic jalr,
    output logic [4:0] alu_op,
    output logic [2:0] imm_sel
);

    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [6:0] funct7;

    assign opcode = instr[6:0];
    assign funct3 = instr[14:12];
    assign funct7 = instr[31:25];

    // --- Defining the constant opcodes for each instruction type ---------
    localparam OP_LUI = 7'b0110111;
    localparam OP_AUIPC = 7'b0010111;
    localparam OP_JAL = 7'b1101111;
    localparam OP_JALR = 7'b1100111;
    localparam OP_BRANCH = 7'b1100011;
    localparam OP_LOAD = 7'b0000011;
    localparam OP_STORE = 7'b0100011;
    localparam OP_IMM = 7'b0010011;
    localparam OP_REG = 7'b0110011;
    localparam OP_SYSTEM = 7'b1110011;

    always_comb begin
        // --- Safe defaults -----------------------------------------------
        alu_op = riscv_pkg::ALU_ADD;
        alu_src = 1'b0;
        reg_write = 1'b0;
        mem_read = 1'b0;
        mem_write = 1'b0;
        mem_funct3 = 3'b010;
        wb_sel = 2'b00;
        imm_sel = riscv_pkg::IMM_X;
        branch = 1'b0;
        jump = 1'b0;
        jalr = 1'b0;

        case (opcode)
        // --- First decoding to find out which type of instruction --------
            OP_LUI: begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = riscv_pkg::ALU_LUI; imm_sel = riscv_pkg::IMM_U;
            end
            OP_AUIPC: begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = riscv_pkg::ALU_ADD; imm_sel = riscv_pkg::IMM_U;
            end
            OP_JAL: begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = riscv_pkg::ALU_ADD; imm_sel = riscv_pkg::IMM_J;
                wb_sel = 2'b10; jump = 1'b1;
            end
            OP_JALR: begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = riscv_pkg::ALU_ADD; imm_sel = riscv_pkg::IMM_I;
                wb_sel = 2'b10; jump = 1'b1; jalr = 1'b1;
            end
            OP_BRANCH: begin
                alu_src = 1'b0;
                imm_sel = riscv_pkg::IMM_B;
                branch = 1'b1;
                mem_funct3 = funct3;
            end
            OP_LOAD: begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = riscv_pkg::ALU_ADD; imm_sel = riscv_pkg::IMM_I;
                mem_read = 1'b1; mem_funct3 = funct3; wb_sel = 2'b01;
            end
            OP_STORE: begin
                alu_src = 1'b1; alu_op = riscv_pkg::ALU_ADD;
                imm_sel = riscv_pkg::IMM_S; mem_write = 1'b1; mem_funct3 = funct3;
            end
            OP_IMM: begin
                reg_write = 1'b1; alu_src = 1'b1; imm_sel = riscv_pkg::IMM_I;
            end
            OP_REG: begin
                reg_write = 1'b1; alu_src = 1'b0; imm_sel = riscv_pkg::IMM_X;
            end
            OP_SYSTEM: begin end        // ECALL/EBREAK: NOP for now
            default: begin end
        endcase

        // --- Secondary decode for which ALU op from funct3 + funct7 ------
        // Runs for R-type, I-type and B-type
        // Priority inside each case:
        //   1. Op_Branch check (branch instructions)
        //   2. Op_Reg + M-ext (multiply/divide)
        //   3. Op_Reg funct7[5] (SUB, SRA)
        //   4. Default (base ALU or immediate ALU)

        if (opcode == OP_IMM || opcode == OP_REG || opcode == OP_BRANCH) begin
            case (funct3)
                // funct3=000: BEQ, ADD/ADDI, SUB, MUL
                3'b000: begin
                    if (opcode == OP_BRANCH)
                        alu_op = riscv_pkg::ALU_SUB;   // BEQ and BNE both subtract
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = riscv_pkg::ALU_MUL;
                    else if (opcode == OP_REG && funct7[5])
                        alu_op = riscv_pkg::ALU_SUB;
                    else
                        alu_op = riscv_pkg::ALU_ADD;
                end

                // funct3=001: BNE, SLL/SLLI, MULH
                3'b001: begin
                    if (opcode == OP_BRANCH)
                        alu_op = riscv_pkg::ALU_SUB;   // BNE: subtract, branch if ~zero
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = riscv_pkg::ALU_MULH;
                    else
                        alu_op = riscv_pkg::ALU_SLL;
                end

                // funct3=010: SLT/SLTI, MULHSU
                3'b010: begin
                    if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = riscv_pkg::ALU_MULHSU; // MULHSU (SxU upper)
                    else
                        alu_op = riscv_pkg::ALU_SLT;
                end

                // funct3=011: SLTU/SLTIU, MULHU
                3'b011: begin
                    if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = riscv_pkg::ALU_MULHU;  // MULHU (UxU upper)
                    else
                        alu_op = riscv_pkg::ALU_SLTU;
                end

                // funct3=100: BLT, XOR/XORI, DIV
                3'b100: begin
                    if (opcode == OP_BRANCH)
                        alu_op = riscv_pkg::ALU_SLT;   // BLT: set-less-than signed
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = riscv_pkg::ALU_DIV;
                    else
                        alu_op = riscv_pkg::ALU_XOR;
                end

                // funct3=101: BGE, SRL/SRA/SRLI/SRAI, DIVU
                3'b101: begin
                    if (opcode == OP_BRANCH)
                        alu_op = riscv_pkg::ALU_SLT;   // BGE: SLT then ~result in evaluator
                    else if (funct7[5])
                        alu_op = riscv_pkg::ALU_SRA;
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = riscv_pkg::ALU_DIVU;
                    else
                        alu_op = riscv_pkg::ALU_SRL;
                end

                // funct3=110: BLTU, OR/ORI, REM
                3'b110: begin
                    if (opcode == OP_BRANCH)
                        alu_op = riscv_pkg::ALU_SLTU;  // BLTU: set-less-than unsigned
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = riscv_pkg::ALU_REM;
                    else
                        alu_op = riscv_pkg::ALU_OR;
                end

                // funct3=111: BGEU, AND/ANDI, REMU
                3'b111: begin
                    if (opcode == OP_BRANCH)
                        alu_op = riscv_pkg::ALU_SLTU;  // BGEU: SLTU then ~result in evaluator
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = riscv_pkg::ALU_REMU;
                    else
                        alu_op = riscv_pkg::ALU_AND;
                end

            endcase
        end
    end

endmodule