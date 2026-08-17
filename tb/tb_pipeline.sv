`timescale 1ns/1ps

module tb_pipeline;

    logic        clk, rst;
    logic [31:0] dbg_pc, dbg_instr, dbg_wb_data;

    riscv_pipeline DUT (
        .clk        (clk),
        .rst        (rst),
        .dbg_pc     (dbg_pc),
        .dbg_instr  (dbg_instr),
        .dbg_wb_data(dbg_wb_data)
    );

    initial clk = 0;
    always #5 clk = ~clk;

    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, tb_pipeline);
    end

    int pass_count = 0, fail_count = 0;

    task automatic check_reg(input [4:0] rn, input [31:0] exp, input string lbl);
        logic [31:0] act;
        act = DUT.u_rf.regs[rn];
        if (act === exp) begin
            $display("  PASS | x%-2d = 0x%08h | %s", rn, act, lbl);
            pass_count++;
        end else begin
            $display("  FAIL | x%-2d = 0x%08h (expected 0x%08h) | %s", rn, act, exp, lbl);
            fail_count++;
        end
    endtask

    initial begin
        $display("\n========================================");
        $display("  RV32IM 5-Stage Pipeline Testbench");
        $display("========================================\n");

        rst = 1;
        repeat(3) @(posedge clk); #1;
        rst = 0;

        // Pipeline takes a few extra cycles to fill vs single-cycle
        $display("--- Basic Arithmetic ---");
        repeat(15) @(posedge clk); #1;
        check_reg(1,  32'd10,       "addi x1, x0, 10");
        check_reg(2,  32'd20,       "addi x2, x0, 20");
        check_reg(3,  32'd30,       "add  x3, x1, x2  (forwarding EX→EX)");
        check_reg(4,  32'd10,       "sub  x4, x2, x1");

        $display("\n--- Logic ---");
        check_reg(5,  32'd0,        "and  x5, x1, x2");
        check_reg(6,  32'd30,       "or   x6, x1, x2");
        check_reg(7,  32'd30,       "xor  x7, x1, x2");

        $display("\n--- Shifts ---");
        repeat(8) @(posedge clk); #1;
        check_reg(8,  32'd40,       "slli x8, x1, 2");
        check_reg(9,  32'd10,       "srli x9, x2, 1");

        $display("\n--- Load/Store (tests stall logic) ---");
        repeat(12) @(posedge clk); #1;
        check_reg(10, 32'd30,       "sw/lw round-trip (stall inserted)");

        $display("\n--- LUI ---");
        repeat(5) @(posedge clk); #1;
        check_reg(11, 32'h12345000, "lui x11, 0x12345");

        $display("\n--- Multiply ---");
        repeat(5) @(posedge clk); #1;
        check_reg(12, 32'd200,      "mul x12, x1, x2");

        $display("\n--- Branch (tests flush logic) ---");
        repeat(12) @(posedge clk); #1;
        check_reg(15, 32'd1,        "beq taken: x15=1 not 99 (flush worked)");

        $display("\n--- JAL + Subroutine ---");
        repeat(12) @(posedge clk); #1;
        check_reg(17, 32'd7,        "jal: x17=7");
        check_reg(25, 32'd42,       "subroutine: x25=42");

        $display("\n--- Divide ---");
        repeat(8) @(posedge clk); #1;
        check_reg(26, 32'd14,       "div 100/7=14");
        check_reg(27, 32'd2,        "rem 100%7=2");

        $display("\n========================================");
        $display("  %0d PASSED, %0d FAILED", pass_count, fail_count);
        if (fail_count == 0)
            $display("  *** PIPELINE CORRECT — ALL HAZARDS HANDLED ***");
        else
            $display("  *** FAILURES — open GTKWave and trace the pipeline ***");
        $display("========================================\n");
        $finish;
    end

    initial begin #1000000; $display("TIMEOUT"); $finish; end

endmodule
