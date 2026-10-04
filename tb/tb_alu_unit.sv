// Module: tb_alu_unit- Testbench for alu.sv

// V2: Removed the divide/ remainder and the divide by zero tests
// as those are now checked by the dividers own testbench

`timescale 1ns/1ps

module tb_alu_unit;
    import riscv_pkg::*;

    logic [31:0] a, b;        
    logic [4:0] op;          
    logic [31:0] result;      
    logic zero;        

    alu DUT (
        .operand_a (a),
        .operand_b (b),
        .alu_op (op),
        .result (result),
        .zero (zero)
    );

    int pass_count = 0;
    int fail_count = 0;

    // --- check task --------------------------------------------------------------
    task automatic check(
        input [31:0] a_in,
        input [31:0] b_in,
        input [4:0] op_in,
        input [31:0] expected,
        input string label
    );
        a = a_in;
        b = b_in;
        op = op_in;
        #1;         // let combinational logic settle (no clock needed)

        if (result === expected) begin
            $display("PASS | %-30s | result = 0x%08h", label, result);
            pass_count++;
        end 
        else begin
            $display("FAIL | %-30s | got 0x%08h, expected 0x%08h", label, result, expected);
            fail_count++;
        end
    endtask

    initial begin
        $display("\nALU Unit Testbench\n");

        // --- Basic arithmetic ----------------------------------------------------
        $display("----- Arithmetic -----");
        check(32'd15, 32'd7, ALU_ADD, 32'd22, "15 + 7 = 22");
        check(32'd15, 32'd7, ALU_SUB, 32'd8, "15 - 7 = 8");
        check(32'd5, 32'd10, ALU_SUB, -32'd5, "5 - 10 = -5");

        // --- Bitwise logic -------------------------------------------------------
        $display("\n----- Bitwise Logic -----");
        check(32'hF0F0_F0F0, 32'h0F0F_0F0F, ALU_AND, 32'h0000_0000, "AND: no overlap");
        check(32'hFF00_0000, 32'h00FF_0000, ALU_OR, 32'hFFFF_0000, "OR combines bits");
        check(32'hFFFF_FFFF, 32'h0000_FFFF, ALU_XOR, 32'hFFFF_0000, "XOR finds where the bits differ");

        // --- Shifts --------------------------------------------------------------
        $display("\n----- Shifts -----");
        check(32'h0000_0001, 32'd31, ALU_SLL, 32'h8000_0000, "SLL by 31 (max shift)");
        check(32'h8000_0000, 32'd31, ALU_SRL, 32'h0000_0001, "SRL by 31, zero padding");
        check(32'hFFFF_FFF0, 32'd4, ALU_SRA, 32'hFFFF_FFFF, "SRA sign-extends negative");
        check(32'h0000_00F0, 32'd4, ALU_SRA, 32'h0000_000F, "SRA on positive is just normal");
        check(32'h0000_0001, 32'd32, ALU_SLL, 32'h0000_0001, "only bottom 5 bits taken as shift amt");

        // --- Comparisons ---------------------------------------------------------
        $display("\n----- Comparisons -----");
        check(32'hFFFF_FFFF, 32'd1, ALU_SLT, 32'd1, "SLT: -1 < 1 (signed) = true");
        check(32'hFFFF_FFFF, 32'd1, ALU_SLTU, 32'd0, "SLTU: 0xFFFFFFFF <u 1 = false");
        check(32'd5, 32'd5, ALU_SLT, 32'd0, "SLT: 5 < 5 = false");

        // --- LUI passthrough -----------------------------------------------------
        $display("\n----- LUI passthrough -----");
        check(32'hDEAD_BEEF, 32'hABCD_E000, ALU_LUI, 32'hABCD_E000, "LUI ignores operand_a");

        // --- M- extension: Multiply -----------------------------------------------
        $display("\n----- Multiply (all 4 M- ext variants) -----");
        check(32'd12, 32'd5, ALU_MUL, 32'd60, "MUL: 12*5=60 (lower 32)");
        check(-32'd3, 32'd5, ALU_MUL, -32'd15, "MUL: -3*5=-15");
        check(-32'd3, 32'd5, ALU_MULH, 32'hFFFF_FFFF,"MULH: upper 32 of -15 (s×s)");
        check(32'hFFFF_FFFF, 32'd5, ALU_MULHU, 32'd4, "MULHU: 0xFFFFFFFF*5 upper (u×u)");
        check(32'hFFFF_FFFF, 32'd5, ALU_MULHSU, 32'hFFFF_FFFF,"MULHSU: -1*5 upper (s×u)");

        // --- Zero flag -----------------------------------------------------------
        $display("\n----- Zero flag -----");
        check(32'd5, 32'd5, ALU_SUB, 32'd0, "SUB: 5-5=0, zero flag should be 1");
        if (zero) begin
            $display("PASS | zero flag correctly set after 5-5=0");
            pass_count++;
        end 
        else begin
            $display("FAIL | zero flag NOT set after 5-5=0");
            fail_count++;
        end

        // --- Summary -------------------------------------------------------------
        $display("\n Pass: %0d      Fail: %0d", pass_count, fail_count);
        if (fail_count == 0)
            $display("ALU unit verified- all %0d cases pass\n", pass_count);
        else
            $display("ALU has bugs- check the failed cases\n");

        $finish;
    end

endmodule