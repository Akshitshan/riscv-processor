// Module: tb_pipeline

// Version-2:

// 1. Instruction cache added a 5-cycle penalty on cold misses, so we can
//    no longer assume 1 cycle per instruction. We now wait a single big window,
//    then check everything.

// 2. return address ra and reg x1 being the same one, x1 gets legitimately overwritten
//    by 'jal ra, my_func.' So to check x1 value, we immediately extract its value the 
//    first time its written and hold it till we have to verify the contents. 
//    Keeps it immune from jal ra overwriting

`timescale 1ns/1ps

module tb_pipeline;

    logic clk, rst;
    logic [31:0] dbg_pc, dbg_instr, dbg_wb_data;

    riscv_pipeline DUT (
        .clk (clk),
        .rst (rst),
        .dbg_pc (dbg_pc),
        .dbg_instr (dbg_instr),
        .dbg_wb_data (dbg_wb_data)
    );

    initial clk = 0;
    always #5 clk = ~clk;

    initial begin
        $dumpfile("wave.vcd");
        $dumpvars(0, tb_pipeline);
    end

    int pass_count = 0, fail_count = 0;

    // --- x1 extract: capture its first write permanently -----------------------------------
    logic [31:0] x1_extract;
    logic x1_extract_taken;

    always_ff @(posedge clk) begin
        if (rst) begin
            x1_extract_taken <= 1'b0;
        end else if (!x1_extract_taken && DUT.wb_reg_write && DUT.wb_rd_addr == 5'd1) begin
            x1_extract <= DUT.wb_data;
            x1_extract_taken <= 1'b1;
        end
    end

    task automatic check_reg(input [4:0] rn, input [31:0] exp, input string label);
        logic [31:0] act;
        act = DUT.u_rf.regs[rn];
        if (act === exp) begin
            $display("PASS | x%-2d = 0x%08h | %s", rn, act, label);
            pass_count++;
        end else begin
            $display("FAIL | x%-2d = 0x%08h (expected 0x%08h) | %s", rn, act, exp, label);
            fail_count++;
        end
    endtask

    initial begin
        $display("RV32IM 5-Stage Pipeline Testbench");

        rst = 1;
        repeat(3) @(posedge clk); #1;
        rst = 0;

        // --- Wait window -------------------------------------------------------------------
        // Worst case considering repeated cold icache misses and branch/jump flush overhead.
        repeat(400) @(posedge clk); #1;

        $display("--- Basic Arithmetic ---");
        if (x1_extract === 32'd10) begin
            $display("PASS | x1(early) = 0x%08h | addi x1, x0, 10", x1_extract);
            pass_count++;
        end else begin
            $display("FAIL | x1(early) = 0x%08h (expected 0x0000000a) | addi x1, x0, 10", x1_extract);
            fail_count++;
        end
        check_reg(2, 32'd20, "addi x2, x0, 20");
        check_reg(3, 32'd30, "add x3, x1, x2 (forwarding EX-EX)");
        check_reg(4, 32'd10, "sub x4, x2, x1");

        $display("\n --- Logic ---");
        check_reg(5, 32'd0, "and x5, x1, x2");
        check_reg(6, 32'd30, "or x6, x1, x2");
        check_reg(7, 32'd30, "xor x7, x1, x2");

        $display("\n --- Shifts ---");
        check_reg(8, 32'd40, "slli x8, x1, 2");
        check_reg(9, 32'd10, "srli x9, x2, 1");

        $display("\n--- Load/Store (tests stall logic) ---");
        check_reg(10, 32'd30, "sw/lw round-trip (stall inserted)");

        $display("\n--- LUI ---");
        check_reg(11, 32'h12345000, "lui x11, 0x12345");

        $display("\n--- Multiply ---");
        check_reg(12, 32'd200, "mul x12, x1, x2");

        $display("\n--- Branch (tests flush logic) ---");
        check_reg(15, 32'd1, "beq taken: x15=1 not 99 (flush worked)");

        $display("\n--- JAL + Subroutine ---");
        check_reg(17, 32'd7, "jal: x17=7");
        check_reg(25, 32'd42, "subroutine: x25=42 (x1/ra correctly reused for this call)");

        $display("\n--- Divide ---");
        check_reg(26, 32'd14, "div 100/7=14");
        check_reg(27, 32'd2, "rem 100%7=2");

        $display("\n  %0d PASSED, %0d FAILED", pass_count, fail_count);
        if (fail_count == 0)
            $display("Pipeline correct- all hazards handled");
        else
            $display("Failed- trace the pipeline");
        $finish;
    end

    initial begin #1000000; $display("TIMEOUT"); $finish; end

endmodule