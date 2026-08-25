// ============================================================
//  MODULE: branch_predictor — 2-bit saturating counter BHT
//
//  WHAT THIS MODULE DOES:
//  Every clock cycle, the IF stage gives us the current PC.
//  We use a few bits of that PC to look up a small table
//  (the Branch History Table, or BHT) and return a prediction:
//  "taken" or "not-taken". We also remember the last known
//  target address for that PC (the Branch Target Buffer, BTB)
//  so we know WHERE to fetch from if we predict taken.
//
//  Later, when the EX stage actually resolves the branch, it
//  tells us the real outcome and target. We use that to UPDATE
//  our table so future predictions get better.
//
//  WHY THIS SPEEDS UP THE CPU:
//  Without prediction, every branch that IS taken costs 2 wasted
//  cycles (the flush we built in Phase 3). With prediction, a
//  correctly-predicted taken branch costs ZERO extra cycles —
//  we already fetched the right instructions.
//
//  KEY DATA STRUCTURES:
//
//  1. BHT (Branch History Table) — array of 2-bit counters.
//     Indexed by low bits of PC. Value 00/01 = predict not-taken.
//     Value 10/11 = predict taken. This is the "history" memory.
//
//  2. BTB (Branch Target Buffer) — array of 32-bit addresses.
//     Indexed the same way as BHT. Stores "last known target"
//     for that PC slot, so we know where to fetch if we predict
//     taken.
//
//  3. Valid bits — a BTB entry is only useful if we've actually
//     seen a branch at that PC before. Without this, an unrelated
//     instruction that happens to share the same table index
//     could cause us to jump to garbage.
// ============================================================

`timescale 1ns/1ps

module branch_predictor #(
    parameter BHT_BITS = 6          // 6 bits = 64 entries in the table
) (
    input logic clk,
    input logic rst,

    // ── Prediction interface (used every cycle by IF stage) ──
    input  logic [31:0] predict_pc,      // current PC to look up
    output logic         predict_taken,   // our guess: taken?
    output logic [31:0]  predict_target,  // our guess: where to?

    // ── Update interface (used by EX stage after resolving) ──
    input  logic         update_valid,    // 1 = a branch resolved this cycle
    input  logic [31:0]  update_pc,       // PC of the branch that resolved
    input  logic         update_taken,    // was it actually taken?
    input  logic [31:0]  update_target    // the real target address
);

    // ── The BHT: array of 2-bit saturating counters ──────────
    //  2^BHT_BITS entries, each entry is 2 bits wide.
    //  Counter meaning:
    //    2'b00 = strongly not-taken
    //    2'b01 = weakly not-taken
    //    2'b10 = weakly taken
    //    2'b11 = strongly taken
    //  Prediction = the TOP bit of the counter (bit 1).

    logic [1:0] bht [0:(1<<BHT_BITS)-1];

    // ── The BTB: array of target addresses ────────────────────
    logic [31:0] btb [0:(1<<BHT_BITS)-1];

    // ── Valid bits: has this BTB slot ever been written? ─────
    logic valid [0:(1<<BHT_BITS)-1];

    // ── Initialise everything at simulation start ─────────────
    //  All counters start at "weakly not-taken" (01) — a
    //  reasonable default since most instructions are NOT
    //  branches, and most branches are not-taken on first sight.
    integer i;
    initial begin
        for (i = 0; i < (1<<BHT_BITS); i = i + 1) begin
            bht[i]   = 2'b01;   // weakly not-taken
            btb[i]   = 32'b0;
            valid[i] = 1'b0;    // no branch seen here yet
        end
    end

    // ── Index computation ──────────────────────────────────────
    //  We take BHT_BITS worth of PC bits, skipping the bottom
    //  2 bits (which are always 00 since instructions are
    //  4-byte aligned — using them would waste table entries).
    //
    //  Example: BHT_BITS=6, predict_pc bits [7:2] used as index.
    //  This gives 64 unique table slots.

    logic [BHT_BITS-1:0] predict_idx;
    logic [BHT_BITS-1:0] update_idx;

    assign predict_idx = predict_pc[BHT_BITS+1 : 2];
    assign update_idx  = update_pc[BHT_BITS+1 : 2];

    // ── Prediction logic (combinational — instant lookup) ─────
    //  If we've never seen a branch at this PC (valid=0), the
    //  safest prediction is "not taken" — most instructions
    //  aren't branches, and PC+4 is always a safe fallback since
    //  every instruction has a "next sequential" address.

    always_comb begin
        if (valid[predict_idx])
            predict_taken = bht[predict_idx][1];   // top bit = prediction
        else
            predict_taken = 1'b0;                  // never seen: predict not-taken

        predict_target = btb[predict_idx];
    end

    // ── Update logic (sequential — happens on clock edge) ─────
    //  When a branch resolves in EX stage, we:
    //   1. Move the 2-bit counter toward the real outcome
    //      (saturating — never goes below 00 or above 11)
    //   2. Store the real target in the BTB
    //   3. Mark this slot as valid

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            // Reset re-initialises on the fly during simulation
            // (the initial block above handles power-on state)
        end else if (update_valid) begin
            // ── 2-bit saturating counter update ───────────────
            if (update_taken) begin
                // Move toward "taken": increment, but cap at 11
                if (bht[update_idx] != 2'b11)
                    bht[update_idx] <= bht[update_idx] + 2'b01;
            end else begin
                // Move toward "not-taken": decrement, but floor at 00
                if (bht[update_idx] != 2'b00)
                    bht[update_idx] <= bht[update_idx] - 2'b01;
            end

            // Remember the real target address for next time
            btb[update_idx] <= update_target;
            valid[update_idx] <= 1'b1;
        end
    end

endmodule
