//  MODULE: imm_gen — Immediate Generator
//  PURPOSE: Extracts and sign-extends the immediate value
//           from any of the 6 RISC-V instruction formats.

module imm_gen
    import riscv_pkg::*;

   (input  logic [31:0] instr,
    input  imm_sel_t    imm_sel,
    output logic [31:0] imm_out);

    always_comb begin
        imm_out = 32'b0;

        case (imm_sel)
            // Rearrange wherever required (all except U-type, and sign extend using the 31st bit of the instr)
            // R-type: no immediate
            IMM_I: imm_out = {{20{instr[31]}}, instr[31:20]};
            IMM_S: imm_out = {{20{instr[31]}}, instr[31:25], instr[11:7]};
            IMM_B: imm_out = {{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0};
            IMM_U: imm_out = {instr[31:12], 12'b0};
            IMM_J: imm_out = {{11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0};
            default: imm_out = 32'b0;
        endcase
    end

endmodule