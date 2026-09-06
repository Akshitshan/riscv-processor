// Module: tb_alu_unit- testbench for alu.sv

`timescale 1ns/1ps

module tb_alu_unit;
    import riscv_pkg::*;

    logic [31:0] a, b;        
    alu_op_t     op;          
    logic [31:0] result;      
    logic        zero;        

    alu DUT (
        .operand_a (a),
        .operand_b (b),
        .alu_op    (op),
        .result    (result),
        .zero      (zero)
    );

    int pass_count = 0;
    int fail_count = 0;

    // ── check task: drive inputs, wait, compare ────────────────
    task automatic check(
        input [31:0]  a_in,
        input [31:0]  b_in,
        input alu_op_t op_in,
        input [31:0]  expected,
        input string  label
    );
        a   = a_in;
        b   = b_in;
        op  = op_in;
        #1;   // let combinational logic settle (no clock needed)

        if (result === expected) begin
            $display("PASS | %-28s | result = 0x%08h", label, result);
            pass_count++;
        end 
        else begin
            $display("FAIL | %-28s | got 0x%08h, expected 0x%08h", label, result, expected);
            fail_count++;
        end
    endtask

    initial begin
        $display("\n========================================");
        $display("  ALU Unit Testbench  ");
        $display("========================================\n");

        // --- Basic arithmetic ---------------------------------
        $display("--- Arithmetic ---");
        check(32'd15, 32'd7, ALU_ADD, 32'd22, "15 + 7 = 22");
        check(32'd15, 32'd7, ALU_SUB, 32'd8, "15 - 7 = 8");
        check(32'd5, 32'd10, ALU_SUB, -32'd5, "5 - 10 = -5");

        // --- Bitwise logic ------------------------------------
        $display("\n--- Bitwise Logic ---");
        check(32'hF0F0_F0F0, 32'h0F0F_0F0F, ALU_AND, 32'h0000_0000, "AND: no overlap");
        check(32'hFF00_0000, 32'h00FF_0000, ALU_OR,  32'hFFFF_0000, "OR combines bits");
        check(32'hFFFF_FFFF, 32'h0000_FFFF, ALU_XOR, 32'hFFFF_0000, "XOR flips upper half");

        // --- Shifts --------------------------------------------
        $display("\n--- Shifts ---");
        check(32'h0000_0001, 32'd31, ALU_SLL, 32'h8000_0000, "SLL by 31 (max shift)");
        check(32'h8000_0000, 32'd31, ALU_SRL, 32'h0000_0001, "SRL by 31, zero-fill");
        check(32'hFFFF_FFF0, 32'd4,  ALU_SRA, 32'hFFFF_FFFF, "SRA sign-extends negative");
        check(32'h0000_00F0, 32'd4,  ALU_SRA, 32'h0000_000F, "SRA on positive = normal shift");
        // Only lower 5 bits of shift amount matter (max shift = 31)
        check(32'h0000_0001, 32'd32, ALU_SLL, 32'h0000_0001, "shift amt 32 wraps to 0 (uses [4:0])");

        // ── Comparisons: signed vs unsigned matters ──────────
        $display("\n--- Comparisons (signed vs unsigned) ---");
        check(32'hFFFF_FFFF, 32'd1, ALU_SLT,  32'd1, "SLT: -1 < 1 (signed) = true");
        check(32'hFFFF_FFFF, 32'd1, ALU_SLTU, 32'd0, "SLTU: 0xFFFFFFFF <u 1 = false (huge unsigned)");
        check(32'd5, 32'd5, ALU_SLT,  32'd0, "SLT: 5 < 5 = false (equal)");

        // ── LUI passthrough ───────────────────────────────────
        $display("\n--- LUI passthrough ---");
        check(32'hDEAD_BEEF, 32'hABCD_E000, ALU_LUI, 32'hABCD_E000, "LUI ignores operand_a");

        // ── M-extension: Multiply (all 4 variants) ───────────
        $display("\n--- Multiply (all 4 M-ext variants) ---");
        check(32'd12, 32'd5,        ALU_MUL,    32'd60,       "MUL: 12*5=60 (lower 32)");
        check(-32'd3, 32'd5,        ALU_MUL,    -32'd15,      "MUL: -3*5=-15");
        check(-32'd3, 32'd5,        ALU_MULH,   32'hFFFF_FFFF,"MULH: upper 32 of -15 (s×s)");
        check(32'hFFFF_FFFF, 32'd5, ALU_MULHU,  32'd4,        "MULHU: 0xFFFFFFFF*5 upper (u×u)");
        check(32'hFFFF_FFFF, 32'd5, ALU_MULHSU, 32'hFFFF_FFFF,"MULHSU: -1*5 upper (s×u)");

        // ── M-extension: Divide + Remainder (all 4 variants) ──
        $display("\n--- Divide / Remainder (all 4 M-ext variants) ---");
        check(32'd12, 32'd5, ALU_DIV,  32'd2,  "DIV: 12/5=2");
        check(32'd12, 32'd5, ALU_REM,  32'd2,  "REM: 12 mod 5=2");
        check(32'd12, 32'd5, ALU_DIVU, 32'd2,  "DIVU: 12/5=2 unsigned");
        check(32'd12, 32'd5, ALU_REMU, 32'd2,  "REMU: 12 mod 5=2 unsigned");
        check(-32'd7, 32'd2, ALU_DIV,  -32'd3, "DIV: -7/2=-3 (rounds toward zero)");
        check(-32'd7, 32'd2, ALU_REM,  -32'd1, "REM: -7 mod 2=-1 (sign follows dividend)");

        // ── Division by zero — defined RISC-V behaviour ──────
        $display("\n--- Division by zero (RISC-V defined, no trap) ---");
        check(32'd100, 32'd0, ALU_DIV,  32'hFFFF_FFFF, "DIV by 0 → -1");
        check(32'd100, 32'd0, ALU_DIVU, 32'hFFFF_FFFF, "DIVU by 0 → 0xFFFFFFFF");
        check(32'd100, 32'd0, ALU_REM,  32'd100,       "REM by 0 → dividend unchanged");
        check(32'd100, 32'd0, ALU_REMU, 32'd100,       "REMU by 0 → dividend unchanged");

        // ── Zero flag ──────────────────────────────────────────
        $display("\n--- Zero flag ---");
        check(32'd5, 32'd5, ALU_SUB, 32'd0, "SUB: 5-5=0, zero flag should be 1");
        if (zero) begin
            $display("  PASS | zero flag correctly set after 5-5=0");
            pass_count++;
        end else begin
            $display("  FAIL | zero flag NOT set after 5-5=0");
            fail_count++;
        end

        // ── Summary ────────────────────────────────────────────
        $display("\n========================================");
        $display("  PASS: %0d   FAIL: %0d", pass_count, fail_count);
        if (fail_count == 0)
            $display("  *** ALU UNIT VERIFIED — all %0d cases pass ***", pass_count);
        else
            $display("  *** ALU HAS BUGS — see failures above ***");
        $display("========================================\n");

        $finish;
    end

endmodule
