// Module: tb_branch_bench

// Runs test_loop.s (which loops 20 times) through the pipeline
// and counts three things every clock cycle:
// 1. Total clock cycles passed
// 2. Total branches resolved (dbg_branch_resolved)
// 3. Total mispredictions (dbg_mispredict)

// From these, we calculate prediction accuracy and can compare
// against what the CPU would have taken with no predictor at
// all (every branch = automatic 2-cycle flush penalty).

`timescale 1ns/1ps

module tb_branch_bench;

    logic clk, rst;
    logic [31:0] dbg_pc, dbg_instr, dbg_wb_data;
    logic dbg_branch_resolved, dbg_mispredict;

    riscv_pipeline DUT (
        .clk (clk),
        .rst (rst),
        .dbg_pc (dbg_pc),
        .dbg_instr (dbg_instr),
        .dbg_wb_data (dbg_wb_data),
        .dbg_branch_resolved (dbg_branch_resolved),
        .dbg_mispredict (dbg_mispredict)
    );

    initial clk = 0;
    always #5 clk = ~clk;

    initial begin
        $dumpfile("wave_branch.vcd");
        $dumpvars(0, tb_branch_bench);
    end

    // --- Counters ------------------------------------------------------------
    int cycle_count = 0;
    int branches_seen = 0;
    int mispredict_count = 0;

    always_ff @(posedge clk) begin
        if (!rst) begin
            cycle_count <= cycle_count + 1;
            if (dbg_branch_resolved) branches_seen <= branches_seen + 1;
            if (dbg_mispredict) mispredict_count <= mispredict_count + 1;
        end
    end

    initial begin
        $display("Branch predictor benchmark");
        $display("Program: test_loop.s (20-iteration loop)");

        rst = 1;
        repeat(3) @(posedge clk); #1;
        rst = 0;

        // Run long enough for the loop to fully complete
        // 20 iterations times ~5 cycles each (with occasional stalls
        // from mispredictions) + pipeline fill/drain overhead
        repeat(200) @(posedge clk); #1;

        // --- Correctness check -----------------------------------------------
        $display("--- Correctness ---");
        if (DUT.u_rf.regs[1] == 32'd20)
            $display("PASS | x1 = %0d (loop counter reached 20)", DUT.u_rf.regs[1]);
        else
            $display("FAIL | x1 = %0d (expected 20)", DUT.u_rf.regs[1]);

        if (DUT.u_rf.regs[3] == 32'd99)
            $display("PASS | x3 = %0d (reached end-of-loop marker)", DUT.u_rf.regs[3]);
        else
            $display("FAIL | x3 = %0d (expected 99)", DUT.u_rf.regs[3]);

        // --- Performance report ----------------------------------------------
        $display("\n--- Branch predictor performance ---");
        $display("Total clock cycles: %0d", cycle_count);
        $display("Branches resolved: %0d", branches_seen);
        $display("Mispredictions: %0d", mispredict_count);
        $display("Correct predictions: %0d", branches_seen - mispredict_count);

        if (branches_seen > 0) begin
            real accuracy;
            accuracy = 100.0 * (branches_seen - mispredict_count) / branches_seen;
            $display("Prediction accuracy: %0.1f%%", accuracy);
        end

        // --- Estimate cycles saved vs without predictor ----------------------
        // Without any predictor (always predict "not taken"),
        // every taken branch costs a 2-cycle flush penalty.
        // With the predictor, only mispredicted branches cost it.
        $display("\n--- Estimated Impact ---");
        $display("Cycles wasted to mispredictions this run : %0d", mispredict_count * 2);
        $display("(Without prediction, ~%0d taken branches would all",
                  branches_seen - 1);
        $display("cost 2 cycles each = ~%0d cycles wasted instead)",
                  (branches_seen - 1) * 2);

        $finish;
    end

    initial begin #500000; $display("TIMEOUT"); $finish; end

endmodule
