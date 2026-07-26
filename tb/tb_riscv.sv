// ============================================================
//  MODULE: tb_riscv — Testbench for the single-cycle CPU
//  PURPOSE: Runs a real program, checks every result,
//           reports PASS/FAIL, and dumps waveforms.
// ============================================================

`timescale 1ns/1ps

module tb_riscv;

    // ── Signals ───────────────────────────────────────────────
    logic        clk;
    logic        rst;
    logic [31:0] dbg_pc;
    logic [31:0] dbg_instr;
    logic [31:0] dbg_alu_result;

    // ── Instantiate the CPU ───────────────────────────────────
    riscv_top DUT (
        .clk            (clk),
        .rst            (rst),
        .dbg_pc         (dbg_pc),
        .dbg_instr      (dbg_instr),
        .dbg_alu_result (dbg_alu_result)
    );

    // ── Clock: 100 MHz (10ns period) ─────────────────────────
    initial clk = 0;
    always #5 clk = ~clk;

    // ── Waveform dump ─────────────────────────────────────────
    // Note: run Makefile with --trace flag enabled (see Makefile)
    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, tb_riscv);
    end

    // ── Counters ──────────────────────────────────────────────
    int pass_count = 0;
    int fail_count = 0;

    // ── Check task — uses 'string' type (no width warnings) ──
    task automatic check_reg(
        input [4:0]  reg_num,
        input [31:0] expected,
        input string label
    );
        logic [31:0] actual;
        actual = DUT.u_rf.regs[reg_num];
        if (actual === expected) begin
            $display("  PASS | x%-2d = 0x%08h | %s", reg_num, actual, label);
            pass_count++;
        end else begin
            $display("  FAIL | x%-2d = 0x%08h  (expected 0x%08h) | %s",
                     reg_num, actual, expected, label);
            fail_count++;
        end
    endtask

    // ── Helper: print PC and instruction each cycle (debug) ───
    // Uncomment this if you want cycle-by-cycle trace in terminal:
    // always @(posedge clk) begin
    //     if (!rst)
    //         $display("  [t=%0t] PC=0x%08h INSTR=0x%08h", $time, dbg_pc, dbg_instr);
    // end

    // ── Main test flow ────────────────────────────────────────
    initial begin

        $display("\n========================================");
        $display("  RV32IM Single-Cycle CPU Testbench");
        $display("========================================");

        // Reset for 2 cycles — holds PC at 0, clears registers
        rst = 1;
        @(posedge clk); #1;
        @(posedge clk); #1;
        rst = 0;

        // ── Show what instruction memory loaded ───────────────
        $display("\n[MEM CHECK] First 4 instructions from program.hex:");
        $display("  mem[0..3]  = 0x%02h%02h%02h%02h",
            DUT.u_imem.mem[3], DUT.u_imem.mem[2],
            DUT.u_imem.mem[1], DUT.u_imem.mem[0]);
        $display("  mem[4..7]  = 0x%02h%02h%02h%02h",
            DUT.u_imem.mem[7], DUT.u_imem.mem[6],
            DUT.u_imem.mem[5], DUT.u_imem.mem[4]);
        $display("  mem[8..11] = 0x%02h%02h%02h%02h",
            DUT.u_imem.mem[11], DUT.u_imem.mem[10],
            DUT.u_imem.mem[9],  DUT.u_imem.mem[8]);
        $display("  (Should NOT all be 0x00000000 — if they are, hex file not loading)");

        // ── Run the program ───────────────────────────────────
        // Each clock cycle executes one instruction (single-cycle CPU).
        // We wait enough cycles for all instructions to complete.
        $display("\n--- Basic Arithmetic ---");
        repeat(10) @(posedge clk); #1;
        check_reg(1,  32'd10,       "addi x1, x0, 10");
        check_reg(2,  32'd20,       "addi x2, x0, 20");
        check_reg(3,  32'd30,       "add  x3, x1, x2");
        check_reg(4,  32'd10,       "sub  x4, x2, x1");

        $display("\n--- Logic ---");
        check_reg(5,  32'd0,        "and  x5, x1, x2  (10 & 20 = 0)");
        check_reg(6,  32'd30,       "or   x6, x1, x2  (10 | 20 = 30)");
        check_reg(7,  32'd30,       "xor  x7, x1, x2  (10 ^ 20 = 30)");

        $display("\n--- Shifts ---");
        repeat(5) @(posedge clk); #1;
        check_reg(8,  32'd40,       "slli x8, x1, 2   (10 << 2 = 40)");
        check_reg(9,  32'd10,       "srli x9, x2, 1   (20 >> 1 = 10)");

        $display("\n--- Load/Store ---");
        repeat(8) @(posedge clk); #1;
        check_reg(10, 32'd30,       "sw/lw  round-trip (x10 = 30)");
        check_reg(21, 32'd10,       "sb/lbu round-trip (x21 = 10)");
        check_reg(22, 32'd20,       "sh/lhu round-trip (x22 = 20)");

        $display("\n--- LUI ---");
        repeat(3) @(posedge clk); #1;
        check_reg(11, 32'h12345000, "lui  x11, 0x12345");

        $display("\n--- M-extension: Multiply ---");
        repeat(3) @(posedge clk); #1;
        check_reg(12, 32'd200,      "mul  x12, x1, x2  (10 * 20 = 200)");

        $display("\n--- Compare ---");
        repeat(3) @(posedge clk); #1;
        check_reg(23, 32'd1,        "slt  x23, x1, x2  (10 < 20 = 1)");
        check_reg(24, 32'd0,        "sltu x24, x2, x1  (20 <u 10 = 0)");

        $display("\n--- Branch ---");
        repeat(8) @(posedge clk); #1;
        check_reg(15, 32'd1,        "beq taken: x15=1 (not 99)");

        $display("\n--- JAL / Subroutine ---");
        repeat(8) @(posedge clk); #1;
        check_reg(17, 32'd7,        "jal: x17=7 (skipped 55)");
        check_reg(25, 32'd42,       "jal+ret: x25=42 from my_func");

        $display("\n--- M-extension: Divide ---");
        repeat(5) @(posedge clk); #1;
        check_reg(26, 32'd14,       "div  x26, 100/7 = 14");
        check_reg(27, 32'd2,        "rem  x27, 100%7 = 2");

        // ── Final summary ─────────────────────────────────────
        $display("\n========================================");
        $display("  Results: %0d PASSED, %0d FAILED", pass_count, fail_count);
        if (fail_count == 0)
            $display("  *** ALL TESTS PASSED — CPU IS CORRECT ***");
        else
            $display("  *** FAILURES — open GTKWave to debug ***");
        $display("========================================\n");

        $finish;
    end

    // ── Timeout watchdog ──────────────────────────────────────
    initial begin
        #500000;
        $display("TIMEOUT: simulation took too long — possible infinite loop");
        $finish;
    end

endmodule
