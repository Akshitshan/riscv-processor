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
    output logic         predict_taken,   // prediction
    output logic [31:0]  predict_target,  // prediction destination

    // --- Update parameters (used by EX after resolving) ----------------------
    input logic        update_valid,    // a branch resolved this cycle
    input logic [31:0] update_pc,       // PC of the branch that resolved
    input logic        update_taken,    // was it actually taken?
    input logic [31:0] update_target    // the real target address
);

    // --- The BHT: array of 2-bit saturating counters -------------------------
    // 2^BHT_BITS entries, each entry is 2 bits wide.
    // Counter meaning:
    // 00 = strongly not-taken
    // 01 = weakly not-taken
    // 10 = weakly taken
    // 11 = strongly taken
    // Prediction = the first bit of the counter (bit 1).

    logic [1:0] bht [0:(1<<BHT_BITS)-1];
    logic [31:0] btb [0:(1<<BHT_BITS)-1];
    logic valid [0:(1<<BHT_BITS)-1];

    // initialise- everything starts at 01 (weakly taken) bcz not all instrx are branches
    //              and not all branches are taken on first sight.
    integer i;
    initial begin
        for (i = 0; i < (1<<BHT_BITS); i = i + 1) begin
            bht[i]   = 2'b01;
            btb[i]   = 32'b0;
            valid[i] = 1'b0;
        end
    end

    // --- Index computation ---------------------------------------------------
    // We take BHT_BITS worth of PC bits, skipping the bottom 2 bits (00 anyway)

    logic [BHT_BITS-1:0] predict_idx;
    logic [BHT_BITS-1:0] update_idx;

    assign predict_idx = predict_pc[BHT_BITS+1 : 2];
    assign update_idx  = update_pc[BHT_BITS+1 : 2];

    // --- Prediction logic ---------------------------------------------------
    always_comb begin
        if (valid[predict_idx])
            predict_taken = bht[predict_idx][1];   // top bit for prediction
        else
            predict_taken = 1'b0;                  // never seen, not valid

        predict_target = btb[predict_idx];
    end

    // --- Update logic (happens on clock edge) -------------------------------
    // When a branch resolves in EX stage, we move the counter towards the truth
    // update the target in btb, and mark the slot valid

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            for (int j = 0; j < (1<<BHT_BITS); j = j + 1)
                valid[j] <= 1'b0;
        end 
        else if (update_valid) begin
            // --- move the counter towards the truth -------------------------
            if (update_taken) begin             // move towards taken but cap at 11
                if (bht[update_idx] != 2'b11)
                    bht[update_idx] <= bht[update_idx] + 2'b01;
            end 
            else begin                          // move towards not taken but cap at 00
                if (bht[update_idx] != 2'b00)
                    bht[update_idx] <= bht[update_idx] - 2'b01;
            end
            // --- remember destination for next time and mark slot valid -----
            btb[update_idx] <= update_target;
            valid[update_idx] <= 1'b1;
        end
    end

endmodule
