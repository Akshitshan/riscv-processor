// ============================================================
//  MODULE: imm_gen — Immediate Generator
//  PURPOSE: Extracts and sign-extends the immediate value
//           from any of the 6 RISC-V instruction formats.
// ============================================================

module imm_gen
    import riscv_pkg::*;   // Import shared types (imm_sel_t lives here now)
(
    input  logic [31:0] instr,
    input  imm_sel_t    imm_sel,
    output logic [31:0] imm_out
);

    always_comb begin
        imm_out = 32'b0;

        case (imm_sel)
            // I-type: bits [31:20], sign-extend from bit 31
            IMM_I: imm_out = {{20{instr[31]}}, instr[31:20]};

            // S-type: split immediate, reassemble then sign-extend
            IMM_S: imm_out = {{20{instr[31]}}, instr[31:25], instr[11:7]};

            // B-type: scrambled branch offset (bit 0 always 0)
            IMM_B: imm_out = {{19{instr[31]}},
                               instr[31],
                               instr[7],
                               instr[30:25],
                               instr[11:8],
                               1'b0};

            // U-type: upper 20 bits, lower 12 zeroed
            IMM_U: imm_out = {instr[31:12], 12'b0};

            // J-type: scrambled jump offset (bit 0 always 0)
            IMM_J: imm_out = {{11{instr[31]}},
                               instr[31],
                               instr[19:12],
                               instr[20],
                               instr[30:21],
                               1'b0};

            // R-type: no immediate
            default: imm_out = 32'b0;
        endcase
    end

endmodule
