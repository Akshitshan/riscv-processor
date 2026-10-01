// Module: tb_icache_bench

// Runs test_loop.s (the same 20-iteration loop from the
// branch predictor testbench) and measures:
//  1. Total cycles taken
//  2. Cache hits vs misses
//  3. Hit rate percentage
//  4. Cycles wasted to cache misses

// The first pass through causes 2 misses (these addresses have 
// never been fetched before). Every pass after that should be 
// pure hits- the addresses are already sitting in the cache- temporal locality

`timescale 1ns/1ps

module tb_icache_bench;

    logic clk, rst;
    logic [31:0] dbg_pc, dbg_instr, dbg_wb_data;
    logic dbg_branch_resolved, dbg_mispredict;
    logic dbg_icache_hit, dbg_icache_miss;

    riscv_pipeline DUT (
        .clk (clk),
        .rst (rst),
        .dbg_pc (dbg_pc),
        .dbg_instr (dbg_instr),
        .dbg_wb_data (dbg_wb_data),
        .dbg_branch_resolved (dbg_branch_resolved),
        .dbg_mispredict (dbg_mispredict),
        .dbg_icache_hit (dbg_icache_hit),
        .dbg_icache_miss (dbg_icache_miss)
    );

    initial clk = 0;
    always #5 clk = ~clk;

    initial begin
        $dumpfile("wave_icache.vcd");
        $dumpvars(0, tb_icache_bench);
    end

    int cycle_count = 0;
    int hit_count = 0;
    int miss_count = 0;

    always_ff @(posedge clk) begin
        if (!rst) begin
            cycle_count <= cycle_count + 1;
            if (dbg_icache_hit) hit_count <= hit_count + 1;
            if (dbg_icache_miss) miss_count <= miss_count + 1;
        end
    end

    initial begin
        $display("Instruction Cache Benchmark");
        $display("Program: test_loop.s (20-iteration loop)");

        rst = 1;
        repeat(3) @(posedge clk); #1;
        rst = 0;

        // Running it long enough for the loop plus cache-miss delays to settle.
        // Each miss costs 5 extra cycles, and branch mispredictions add their own overhead
        repeat(300) @(posedge clk); #1;

        $display("--- Correctness ---");
        if (DUT.u_rf.regs[1] == 32'd20)
            $display("PASS | x1 = %0d (loop counter reached 20)", DUT.u_rf.regs[1]);
        else
            $display("FAIL | x1 = %0d (expected 20)", DUT.u_rf.regs[1]);

        if (DUT.u_rf.regs[3] == 32'd99)
            $display("PASS | x3 = %0d (reached end-of-loop marker)", DUT.u_rf.regs[3]);
        else
            $display("FAIL | x3 = %0d (expected 99)", DUT.u_rf.regs[3]);

        $display("\n--- Instruction Cache Performance ---");
        $display("Total clock cycles: %0d", cycle_count);
        $display("Cache accesses: %0d", hit_count + miss_count);
        $display("Hits: %0d", hit_count);
        $display("Misses: %0d", miss_count);

        if ((hit_count + miss_count) > 0) begin
            real hit_rate;
            hit_rate = 100.0 * hit_count / (hit_count + miss_count);
            $display("Hit rate: %0.1f%%", hit_rate);
        end

        $display("\n--- Estimated Impact ---");
        $display("Cycles spent waiting on misses: %0d (miss_count x 5-cycle penalty)", miss_count * 5);
        $display("If every access were a miss: ~%0d cycles would be spent waiting", (hit_count + miss_count) * 5);

        $finish;
    end

    initial begin #500000; $display("TIMEOUT"); $finish; end

endmodule
