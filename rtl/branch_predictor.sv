// Module: branch_predictor- 2-bit saturating counter BHT
// Purpose: Takes PC every IF stage and checks it in the BHT (Branch History Table). 
//          If predicts taken, destination comes from BTB (Branch target Buffer) 
//          which stores the last know target for that PC slot.

`timescale 1ns/1ps

module branch_predictor #(parameter BHT_BITS = 6)         // 6 bits = 64 entries in the table
(
    input logic clk,
    input logic rst,

    // --- Prediction parameters (used by IF) -----------------------------------
    input logic [31:0] predict_pc,        // current PC to look up
    output logic predict_taken,           // prediction
    output logic [31:0] predict_target,  // prediction destination

    // --- Update parameters (used by EX after resolving) -----------------------
    input logic update_valid,           // a branch resolved this cycle
    input logic [31:0] update_pc,       // PC of the branch that resolved
    input logic update_taken,           // was it actually taken?
    input logic [31:0] update_target    // the real target address
);

    // --- The BHT: array of 2-bit saturating counters --------------------------
    // 2^BHT_BITS entries, each entry is 2 bits wide.
    // Counter meaning:
    // 00 = strongly not-taken
    // 01 = weakly not-taken
    // 10 = weakly taken
    // 11 = strongly taken
    // Prediction = the first bit of the counter (bit 1).

    localparam int entries = 1 << BHT_BITS;
 
    logic [1:0] bht [0:entries-1];
    logic [31:0] btb [0:entries-1];
    logic [entries-1:0] valid;
 
    logic [BHT_BITS-1:0] predict_idx;
    logic [BHT_BITS-1:0] update_idx;
 
    assign predict_idx = predict_pc[BHT_BITS+1:2];
    assign update_idx = update_pc[BHT_BITS+1:2];
 
    // Prediction: only trust entries that have been trained
    assign predict_taken = valid[predict_idx] && bht[predict_idx][1];
    assign predict_target = btb[predict_idx];
 
    // Valid bits (async reset)
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            valid <= '0;
        else if (update_valid)
            valid[update_idx] <= 1'b1;
    end
 
    // Counters and targets (no reset)
    always_ff @(posedge clk) begin
        if (update_valid) begin
            if (!valid[update_idx]) begin
                bht[update_idx] <= update_taken ? 2'b10 : 2'b00;
            end else if (update_taken) begin
                if (bht[update_idx] != 2'b11)
                    bht[update_idx] <= bht[update_idx] + 2'b01;
            end else begin
                if (bht[update_idx] != 2'b00)
                    bht[update_idx] <= bht[update_idx] - 2'b01;
            end
            btb[update_idx] <= update_target;
        end
    end
 
endmodule
