// Module: alu- Arithmetic Logic Unit
// Purpose: Takes two inputs, rs1 and rs2/imm, along with the opeartion 
//          to perform and produces the result (and a zero flag for branch logics)

// V2: Removing 'import risv_pkg::*' bcz yosys is choking at the import call
// V3: For area/ timing pass, division and remainder moved out to a seperate 
//     divider.sv module. Also instead of three seperate 32x32 multipliers being built, 
//     we now have one shared 33x33 signed multiplier.

`timescale 1ns/1ps

module alu (
    input logic [31:0] operand_a,
    input logic [31:0] operand_b,
    input logic [4:0] alu_op,
    output logic [31:0] result,
    output logic zero
);

    // Signed versions of the inputs
    logic signed [31:0] signed_a;
    logic signed [31:0] signed_b;
    assign signed_a = $signed(operand_a);
    assign signed_b = $signed(operand_b);

    // Shared multiplier: operand A is unsigned only for MULHU, signed otherwise
    //                    operand B is signed only for MULH, unsigned otherwise
    // MUL only uses the low 32 bits, which are identical either way.
    logic signed [32:0] mul_a, mul_b;
    logic signed [65:0] mul_p;
    assign mul_a = (alu_op == riscv_pkg::ALU_MULHU) ? {1'b0, operand_a} : {operand_a[31], operand_a};
    assign mul_b = (alu_op == riscv_pkg::ALU_MULH)  ? {operand_b[31], operand_b} : {1'b0, operand_b};
    assign mul_p = mul_a * mul_b;

    // --- Main operation selection -----------------------------------
    always_comb begin
        result = 32'b0;   // safe default

        case (alu_op)
            // ---Integer arithmetic ----------------------------------
            riscv_pkg::ALU_ADD: result = operand_a + operand_b;
            riscv_pkg::ALU_SUB: result = operand_a - operand_b;
            riscv_pkg::ALU_LUI: result = operand_b;   // operand b in upper 20bits with padding

            // --- Bitwise logic --------------------------------------
            riscv_pkg::ALU_AND: result = operand_a & operand_b;
            riscv_pkg::ALU_OR: result = operand_a | operand_b;
            riscv_pkg::ALU_XOR: result = operand_a ^ operand_b;

            // --- Shifts ---------------------------------------------
            // Only lower 5 bits of operand_b used as shift amount bcz 32-bit data width
            riscv_pkg::ALU_SLL: result = operand_a << operand_b[4:0];
            riscv_pkg::ALU_SRL: result = operand_a >> operand_b[4:0];
            riscv_pkg::ALU_SRA: result = $signed(operand_a) >>> operand_b[4:0];

            // --- Comparisons ----------------------------------------
            riscv_pkg::ALU_SLT: result = (signed_a < signed_b) ? 32'd1 : 32'd0;
            riscv_pkg::ALU_SLTU: result = (operand_a < operand_b) ? 32'd1 : 32'd0;

            // --- M-extension: Multiply ------------------------------
            riscv_pkg::ALU_MUL: result = mul_p[31:0];
            riscv_pkg::ALU_MULH: result = mul_p[63:32];
            riscv_pkg::ALU_MULHSU: result = mul_p[63:32];
            riscv_pkg::ALU_MULHU: result = mul_p[63:32];

            default: result = 32'b0;
        endcase
    end

    // --- Zero flag --------------------------------------------------
    assign zero = (result == 32'b0);

endmodule
