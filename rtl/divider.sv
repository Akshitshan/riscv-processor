// Module: divider- multi-cycle RV32M divide / remainder unit
// Purpose: Replaces the original single-cycle combinational divider, which was
//          almost 17,000 cells and set the design's critical path (roughly 82 ns).

// Algorithm: It performs division step by step using the operands absolute 
// values, calculating one quotient bit per clock cycle, and applies the correct 
// signs to the quotient and remainder at the end. The quotient gets a negative sign when
// the operand signs differ, while the remainder takes the sign of the dividend.

// Timing: 1 cycle to load + 32 cycles to iterate, result valid on the next cycle. 
// A divide holds EX for 33 cycles.

`timescale 1ns/1ps

module divider (
    input logic clk,
    input logic rst,

    input logic start,              
    input logic is_signed,          // for div/rem = 1 or divu/remu = 0
    input logic want_rem,           // for rem/remu= 1 or DIV/DIVU= 0
    input logic [31:0] dividend,
    input logic [31:0] divisor,

    output logic idle,              // ready to accept a new division
    output logic done,              // result valid this cycle
    output logic [31:0] result
);

    localparam logic [1:0] s_idle = 2'd0;
    localparam logic [1:0] s_busy = 2'd1;
    localparam logic [1:0] s_done = 2'd2;

    logic [1:0] state;
    logic [5:0] count;

    logic [31:0] q;
    logic [31:0] r;
    logic [31:0] d;
    logic neg_q, neg_r, by_zero, rem_sel;
    logic [31:0] orig_dividend;

    logic [32:0] r_shift;               // remainder shifted left, next dividend bit in
    logic [32:0] r_sub;
    assign r_shift = {r, q[31]};
    assign r_sub = r_shift - {1'b0, d};

    // --- control (async reset) ----------------------------------------
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= s_idle;
            count <= 6'd0;
        end else begin
            case (state)
                s_idle: begin
                    if (start) begin
                        state <= s_busy;
                        count <= 6'd32;
                    end
                end
                s_busy: begin
                    count <= count - 6'd1;
                    if (count == 6'd1)
                        state <= s_done;
                end
                default: state <= s_idle;   // s_done lasts one cycle
            endcase
        end
    end

    // --- datapath (no reset needed) -----------------------------------
    always_ff @(posedge clk) begin
        if (state == s_idle && start) begin
            q <= (is_signed && dividend[31]) ? -dividend : dividend;
            d <= (is_signed && divisor[31]) ? -divisor : divisor;
            r <= 32'b0;
            neg_q <= is_signed && (dividend[31] ^ divisor[31]);
            neg_r <= is_signed && dividend[31];
            by_zero <= (divisor == 32'b0);
            rem_sel <= want_rem;
            orig_dividend <= dividend;
        end 
        else if (state == s_busy) begin
            if (!r_sub[32]) begin            // r_shift >= d: subtract, quotient bit 1
                r <= r_sub[31:0];
                q <= {q[30:0], 1'b1};
            end 
            else begin                   // r_shift < d: keep, quotient bit 0
                r <= r_shift[31:0];
                q <= {q[30:0], 1'b0};
            end
        end
    end

    assign idle = (state == s_idle);
    assign done = (state == s_done);

    always_comb begin
        if (by_zero)
            result = rem_sel ? orig_dividend : 32'hFFFF_FFFF;
        else if (rem_sel)
            result = neg_r ? -r : r;
        else
            result = neg_q ? -q : q;
    end

endmodule
