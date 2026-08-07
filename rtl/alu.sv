// Module: ALU - Arithmetic Logic Unit
// Purpose: Does all the computation. Takes two 32-bit inputs, 
//          performs the operation and returns a 32-bit result.


module alu
    import riscv_pkg::*; // Importing the common shared types (alu_op_t for the ALU)
   
   (input logic [31:0] operand_a,
    input logic [31:0] operand_b,
    input alu_op_t alu_op,
    output logic [31:0] result,
    output logic zero);

// Save a version of the variables as signed as well
    logic signed [31:0] signed_a;
    logic signed [31:0] signed_b;
    assign signed_a = $signed(operand_a);
    assign signed_b = $signed(operand_b);

    logic signed [63:0] mul_signed;
    logic        [63:0] mul_unsigned;
    assign mul_signed   = signed_a * signed_b;
    assign mul_unsigned = operand_a * operand_b;

    always_comb 
    begin
        result = 32'b0;
        case (alu_op)
            ALU_ADD:  result = operand_a + operand_b;
            ALU_SUB:  result = operand_a - operand_b;
            ALU_SLL:  result = operand_a << operand_b[4:0];
            ALU_SLT:  result = (signed_a < signed_b)   ? 32'd1 : 32'd0;
            ALU_SLTU: result = (operand_a < operand_b) ? 32'd1 : 32'd0;
            ALU_XOR:  result = operand_a ^ operand_b;
            ALU_SRL:  result = operand_a >> operand_b[4:0];
            ALU_SRA:  result = $signed(operand_a) >>> operand_b[4:0];
            ALU_OR:   result = operand_a | operand_b;
            ALU_AND:  result = operand_a & operand_b;
            ALU_LUI:  result = operand_b;          
            ALU_MUL:  result = mul_unsigned[31:0];
            ALU_MULH: result = mul_signed[63:32];

            ALU_DIV: 
            begin
                if (operand_b == 32'b0)
                    result = 32'hFFFF_FFFF;
                else 
                    result = $signed(operand_a) / $signed(operand_b);
            end

            ALU_DIVU: 
            begin
                if (operand_b == 32'b0)
                    result = 32'hFFFF_FFFF;
                else
                    result = operand_a / operand_b;
            end

            ALU_REM: begin
                if (operand_b == 32'b0)
                    result = operand_a;
                else
                    result = $signed(operand_a) % $signed(operand_b);
            end

            default: result = 32'b0;
        endcase
    end

    assign zero = (result == 32'b0);

endmodule
