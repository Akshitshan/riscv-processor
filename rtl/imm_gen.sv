// Module: imm_gen- Immediate Generator
// Purpose: Extracts and sign-extends the immediate value
//          from any of the six RISC-V instruction formats.

// V2: Removing 'import risv_pkg::*' bcz yosys is choking at the import call

module imm_gen (
    input logic [31:0] instr,
    input logic [2:0] imm_sel,
    output logic [31:0] imm_out);

    always_comb begin
        imm_out = 32'b0;

        case (imm_sel)
            // Rearranged the bits wherever required and sign extended using the 31st bit of the instr
            // R-type: no immediate
            riscv_pkg::IMM_I: imm_out = {{20{instr[31]}}, instr[31:20]};
            riscv_pkg::IMM_S: imm_out = {{20{instr[31]}}, instr[31:25], instr[11:7]};
            riscv_pkg::IMM_B: imm_out = {{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0};
            riscv_pkg::IMM_U: imm_out = {instr[31:12], 12'b0};
            riscv_pkg::IMM_J: imm_out = {{11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0};
            default: imm_out = 32'b0;
        endcase
    end

endmodule