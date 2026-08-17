//  Module: control unit — Instruction Decoder
//  Purpose: Reads the instruction and decodes the opcode, funct3 and funct7. 
//           Drives every control signal that tells other modules what to do.

module control_unit
    import riscv_pkg::*;

   (input  logic [31:0] instr,
    output alu_op_t alu_op, //which opertion to perform
    output logic alu_src, //where should the ALU input B come from (0: rs2, 1: imm)
    output logic reg_write, //should the register file save the result (for ADD-yes, LW-yes, SW-no)
    output logic mem_read, //should memory be read (only in case of loads)
    output logic mem_write, //should memory be written (only in case of stores)
    output logic [2:0] mem_funct3, //S-type instruction funct3: how many bytes of data to access (LB, LH, LW)
    output logic [1:0] wb_sel, //what should be written back (ALU result or memory data or PC+4)
    output imm_sel_t imm_sel, //how should the imm be extracted
    output logic branch, //is this a branch instruction
    output logic jump, //should the PC jump
    output logic jalr); //is this specifically jalr

    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [6:0] funct7;

    assign opcode = instr[6:0];
    assign funct3 = instr[14:12];
    assign funct7 = instr[31:25];

    localparam OP_REG    = 7'b0110011; //Constant Opcode for R-type instructions
    localparam OP_IMM    = 7'b0010011; //Constant Opcode for I-type (arithematic) instructions
    localparam OP_LOAD   = 7'b0000011; //Constant Opcode for I-type (load) instructions
    localparam OP_SYSTEM = 7'b1110011; //Constant opcode for I-type (Env and sys calls) instructions
    localparam OP_JALR   = 7'b1100111; //Constant opcode for I-type (special category) instructions
    localparam OP_STORE  = 7'b0100011; //Constant opcode for S-type instructions
    localparam OP_BRANCH = 7'b1100011; //Constant opcode for B-type instructions
    localparam OP_LUI    = 7'b0110111; //Constant opcode for U-type (LUI) instructions
    localparam OP_AUIPC  = 7'b0010111; //Constant opcode for U-type (AUIPC) instructions
    localparam OP_JAL    = 7'b1101111; //Constant opcode for J-type intruction
    
    always_comb 
    begin
        //Safe defaults to start so that there are no accidental register write, memory access, etc
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
            OP_REG: 
                begin
                    reg_write = 1'b1; alu_src = 1'b0; imm_sel = IMM_X;
                end

            OP_IMM: 
            begin
                reg_write = 1'b1; alu_src = 1'b1; imm_sel = IMM_I;
            end

            OP_LOAD: 
            begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = ALU_ADD; imm_sel = IMM_I;
                mem_read = 1'b1; mem_funct3 = funct3; wb_sel = 2'b01;
            end

            OP_SYSTEM: 
            begin
                // ECALL/EBREAK: treat as NOP for now (Phase 3 adds traps)
            end

            OP_JALR: 
            begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = ALU_ADD; imm_sel = IMM_I;
                wb_sel = 2'b10; jump = 1'b1; jalr = 1'b1;
            end

            OP_STORE: 
            begin
                alu_src = 1'b1; alu_op = ALU_ADD;
                imm_sel = IMM_S; mem_write = 1'b1; mem_funct3 = funct3;
            end

            OP_BRANCH:
            begin
                alu_src = 1'b0; imm_sel = IMM_B; branch = 1'b1;
            end

            OP_LUI:
            begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = ALU_LUI; imm_sel = IMM_U;
            end

            OP_AUIPC:
            begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = ALU_ADD; imm_sel = IMM_U;
            end

            OP_JAL:
            begin
                reg_write = 1'b1; alu_src = 1'b1;
                alu_op = ALU_ADD; imm_sel = IMM_J;
                wb_sel = 2'b10; jump = 1'b1;
            end
            
            default: begin end
        endcase

        // Secondary decode: pick exact ALU op from funct3/funct7
        if (opcode == OP_IMM || opcode == OP_REG || opcode == OP_BRANCH) begin
            case (funct3)
                3'b000: 
                begin
                    if (opcode == OP_BRANCH)
                        alu_op = ALU_SUB;
                    else if (opcode == OP_REG && funct7[5])
                        alu_op = ALU_SUB;
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = ALU_MUL;
                    else
                        alu_op = ALU_ADD;
                end
                3'b001: 
                begin
                    if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = ALU_MULH;
                    else
                        alu_op = ALU_SLL;
                end
                3'b010: alu_op = ALU_SLT;
                3'b011: alu_op = ALU_SLTU;
                3'b100: begin
                    if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = ALU_DIV;
                    else
                        alu_op = ALU_XOR;
                end
                3'b101: 
                begin
                    if (opcode == OP_BRANCH)
                        alu_op = ALU_SLT;
                    else if (funct7[5])
                        alu_op = ALU_SRA;
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = ALU_DIVU;
                    else
                        alu_op = ALU_SRL;
                end
                3'b110: 
                begin
                    if (opcode == OP_BRANCH)
                        alu_op = ALU_SLTU;
                    else if (opcode == OP_REG && funct7 == 7'b0000001)
                        alu_op = ALU_REM;
                    else
                        alu_op = ALU_OR;
                end
                3'b111: alu_op = ALU_AND;
            endcase
        end
    end
endmodule