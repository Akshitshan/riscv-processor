// Module: divider- multi-cycle RV32M divide / remainder unit

// Replaces the single-cycle combinational divider, which was
// ~17,000 cells and set the design's critical path (~82 ns).
//
//  Algorithm: restoring division on the operand magnitudes,
//  one quotient bit per clock. Signs are fixed up at the end:
//    quotient is negative if the operand signs differ
//    remainder takes the sign of the dividend
//
//  Timing: 1 cycle to load + 32 cycles to iterate, result
//  valid on the next cycle. A divide holds EX for 33 cycles.
//
//  RISC-V corner cases (no traps, defined results):
//    divide by zero : quotient = all ones, remainder = dividend
//    -2^31 / -1     : quotient = -2^31,    remainder = 0
//  The magnitude algorithm produces the overflow case naturally
//  (|-2^31| = 2^31 fits in 32 unsigned bits). Divide by zero is
//  handled explicitly, since the sign fix-up would corrupt it.
// ============================================================

`timescale 1ns/1ps

module divider (
    input  logic        clk,
    input  logic        rst,

    input  logic        start,      // begin a division (sampled only when idle)
    input  logic        is_signed,  // DIV/REM (1) or DIVU/REMU (0)
    input  logic        want_rem,   // REM/REMU (1) or DIV/DIVU (0)
    input  logic [31:0] dividend,
    input  logic [31:0] divisor,

    output logic        idle,       // ready to accept a new division
    output logic        done,       // result valid this cycle
    output logic [31:0] result
);

    localparam logic [1:0] S_IDLE = 2'd0;
    localparam logic [1:0] S_BUSY = 2'd1;
    localparam logic [1:0] S_DONE = 2'd2;

    logic [1:0]  state;
    logic [5:0]  count;

    logic [31:0] q;        // magnitude of dividend, shifts into quotient
    logic [31:0] r;        // partial remainder
    logic [31:0] d;        // magnitude of divisor
    logic        neg_q, neg_r, by_zero, rem_sel;
    logic [31:0] orig_dividend;

    logic [32:0] r_shift;  // remainder shifted left, next dividend bit in
    logic [32:0] r_sub;
    assign r_shift = {r, q[31]};
    assign r_sub   = r_shift - {1'b0, d};

    // ---------------- control (async reset) ----------------
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= S_IDLE;
            count <= 6'd0;
        end else begin
            case (state)
                S_IDLE: begin
                    if (start) begin
                        state <= S_BUSY;
                        count <= 6'd32;
                    end
                end
                S_BUSY: begin
                    count <= count - 6'd1;
                    if (count == 6'd1)
                        state <= S_DONE;
                end
                default: state <= S_IDLE;   // S_DONE lasts one cycle
            endcase
        end
    end

    // ---------------- datapath (no reset needed) ----------------
    always_ff @(posedge clk) begin
        if (state == S_IDLE && start) begin
            q             <= (is_signed && dividend[31]) ? -dividend : dividend;
            d             <= (is_signed && divisor[31])  ? -divisor  : divisor;
            r             <= 32'b0;
            neg_q         <= is_signed && (dividend[31] ^ divisor[31]);
            neg_r         <= is_signed && dividend[31];
            by_zero       <= (divisor == 32'b0);
            rem_sel       <= want_rem;
            orig_dividend <= dividend;
        end else if (state == S_BUSY) begin
            if (!r_sub[32]) begin            // r_shift >= d: subtract, quotient bit 1
                r <= r_sub[31:0];
                q <= {q[30:0], 1'b1};
            end else begin                   // r_shift < d: keep, quotient bit 0
                r <= r_shift[31:0];
                q <= {q[30:0], 1'b0};
            end
        end
    end

    assign idle = (state == S_IDLE);
    assign done = (state == S_DONE);

    always_comb begin
        if (by_zero)
            result = rem_sel ? orig_dividend : 32'hFFFF_FFFF;
        else if (rem_sel)
            result = neg_r ? -r : r;
        else
            result = neg_q ? -q : q;
    end

endmodule
