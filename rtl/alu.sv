// Module: alu- Arithmetic Logic Unit
// Purpose: Takes two inputs, rs1 and rs2/imm, along with the opeartion 
//          to perform and produces the result (and a zero flag for branch logics)

`timescale 1ns/1ps

module alu
    import riscv_pkg::*;
(
    input  logic [31:0] operand_a,
    input  logic [31:0] operand_b,
    input  alu_op_t     alu_op,
    output logic [31:0] result,
    output logic        zero
);

    // Signed versions of the inputs
    logic signed [31:0] signed_a;
    logic signed [31:0] signed_b;
    assign signed_a = $signed(operand_a);
    assign signed_b = $signed(operand_b);

    // --- Multiplication intermediates -------------------------------
    // Need a 64-bit intermediary to be able to extract
    // the high half in case of MULH

    logic signed [63:0] mul_ss;             // Signed x signed
    assign mul_ss = signed_a * signed_b;

    logic [63:0] mul_uu;                    // Unsigned x unsigned
    assign mul_uu = operand_a * operand_b;

    // zero-extend operand_b to 33 bits so '$signed' treats it as +ve
    logic signed [63:0] mul_su;             // Signed x Unsigned
    assign mul_su = signed_a * $signed({1'b0, operand_b});

    // --- Main operation selection -----------------------------------
    always_comb begin
        result = 32'b0;   // safe default

        case (alu_op)
            // ---Integer arithmetic ----------------------------------
            ALU_ADD:  result = operand_a + operand_b;
            ALU_SUB:  result = operand_a - operand_b;
            ALU_LUI:  result = operand_b;   // operand b in upper 20bits with padding

            // --- Bitwise logic --------------------------------------
            ALU_AND:  result = operand_a & operand_b;
            ALU_OR:   result = operand_a | operand_b;
            ALU_XOR:  result = operand_a ^ operand_b;

            // --- Shifts ---------------------------------------------
            // Only lower 5 bits of operand_b used as shift amount bcz 32-bit data width
            ALU_SLL:  result = operand_a << operand_b[4:0];
            ALU_SRL:  result = operand_a >> operand_b[4:0];
            ALU_SRA:  result = $signed(operand_a) >>> operand_b[4:0];

            // --- Comparisons ----------------------------------------
            ALU_SLT:  result = (signed_a < signed_b) ? 32'd1 : 32'd0;
            ALU_SLTU: result = (operand_a < operand_b) ? 32'd1 : 32'd0;

            // --- M-extension: Multiply ------------------------------
            ALU_MUL:   result = mul_ss[31:0];    // lower 32 of s×s
            ALU_MULH:  result = mul_ss[63:32];   // upper 32 of s×s
            ALU_MULHSU:result = mul_su[63:32];   // upper 32 of s×u
            ALU_MULHU: result = mul_uu[63:32];   // upper 32 of u×u

            // --- M-extension: Divide --------------------------------
            ALU_DIV: begin
                if (operand_b == 32'b0)
                    result = 32'hFFFF_FFFF;          // -1
                else
                    result = $signed(operand_a) / $signed(operand_b);
            end

            ALU_DIVU: begin
                if (operand_b == 32'b0)
                    result = 32'hFFFF_FFFF;          // 2^32 - 1
                else
                    result = operand_a / operand_b;  // unsigned
            end

            ALU_REM: begin
                if (operand_b == 32'b0)
                    result = operand_a;              // remainder = dividend
                else
                    result = $signed(operand_a) % $signed(operand_b);
            end

            ALU_REMU: begin
                if (operand_b == 32'b0)
                    result = operand_a;
                else
                    result = operand_a % operand_b;  // unsigned modulo
            end

            default: result = 32'b0;
        endcase
    end

    // --- Zero flag --------------------------------------------------
    assign zero = (result == 32'b0);

endmodule
