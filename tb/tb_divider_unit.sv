// Module: tb_divider_unit

`timescale 1ns/1ps

module tb_divider_unit;

    logic clk, rst;
    logic start, is_signed, want_rem;
    logic [31:0] dividend, divisor;
    logic idle, done;
    logic [31:0] result;

    divider DUT (
        .clk(clk), .rst(rst), .start(start),
        .is_signed(is_signed), .want_rem(want_rem),
        .dividend(dividend), .divisor(divisor),
        .idle(idle), .done(done), .result(result)
    );

    initial clk = 0;
    always #5 clk = ~clk;

    int pass_count = 0, fail_count = 0;
    int latency, expected_latency = -1;

    // Behavioural reference, from the RISC-V spec
    function automatic logic [31:0] ref_div(
        input logic [31:0] a, 
        input logic [31:0] b,
        input logic sgn, 
        input logic rem
    );
        if (b == 32'd0)
            return rem ? a : 32'hFFFF_FFFF;
        if (sgn) begin
            if (a == 32'h8000_0000 && b == 32'hFFFF_FFFF)
                return rem ? 32'd0 : 32'h8000_0000;
            return rem ? $signed(a) % $signed(b) : $signed(a) / $signed(b);
        end
        return rem ? a % b : a / b;
    endfunction

    task automatic run_one(
        input logic [31:0] a, 
        input logic [31:0] b,
        input logic sgn, 
        input logic rem,
        input string label, 
        input bit verbose
    );

        logic [31:0] exp;
        exp = ref_div(a, b, sgn, rem);

        @(negedge clk);
        dividend = a; divisor = b; is_signed = sgn; want_rem = rem;
        start = 1'b1;
        @(negedge clk);
        start = 1'b0;
        latency = 1;
        while (!done) begin
            @(negedge clk);
            latency++;
        end

        if (expected_latency < 0) expected_latency = latency;

        if (result === exp && latency == expected_latency) begin
            pass_count++;
            if (verbose)
                $display("Pass | %-34s | result = 0x%08h (%0d cycles)", label, result, latency);
        end 
        else begin
            fail_count++;
            $display("  FAIL | %-34s | a=0x%08h b=0x%08h sgn=%0b rem=%0b got 0x%08h expected 0x%08h, %0d cycles",
                    label, a, b, sgn, rem, result, exp, latency);
        end
    endtask

    initial begin
        $display("Divider unit testbench");

        start = 0; dividend = 0; divisor = 0; is_signed = 0; want_rem = 0;
        rst = 1;
        repeat (3) @(posedge clk);
        rst = 0;

        $display("----- Directed cases -----");
        run_one(32'd12, 32'd5, 1, 0, "DIV  12 / 5 = 2", 1);
        run_one(32'd12, 32'd5, 1, 1, "REM  12 % 5 = 2", 1);
        run_one(-32'd7, 32'd2, 1, 0, "DIV  -7 / 2 = -3 (toward zero)", 1);
        run_one(-32'd7, 32'd2, 1, 1, "REM  -7 % 2 = -1 (dividend sign)", 1);
        run_one(32'd7, -32'd2, 1, 0, "DIV  7 / -2 = -3", 1);
        run_one(32'hFFFF_FFFF, 32'd3, 0, 0, "DIVU 0xFFFFFFFF / 3", 1);
        run_one(32'hFFFF_FFFF, 32'd3, 0, 1, "REMU 0xFFFFFFFF % 3", 1);

        $display("\n----- Divide by zero -----");
        run_one(32'd100, 32'd0, 1, 0, "DIV by 0 is all ones", 1);
        run_one(32'd100, 32'd0, 0, 0, "DIVU by 0 is all ones", 1);
        run_one(-32'd100, 32'd0, 1, 1, "REM by 0 is the dividend", 1);
        run_one(32'd100, 32'd0, 0, 1, "REMU by 0 is the dividend", 1);

        $display("\n----- Signed overflow (-2^31 / -1) -----");
        run_one(32'h8000_0000, 32'hFFFF_FFFF, 1, 0, "DIV -2^31 / -1 = -2^31", 1);
        run_one(32'h8000_0000, 32'hFFFF_FFFF, 1, 1, "REM -2^31 % -1 = 0", 1);

        $display("\n----- 2k random cases (all four operations) -----");
        for (int i = 0; i < 2000; i++) begin
            logic [31:0] a, b;
            a = $urandom;
            // Biasing some divisors small so quotients become large
            b = (i % 3 == 0) ? ($urandom % 64) : $urandom;
            run_one(a, b, i[0], i[1], "random", 0);
        end
        $display("Random cases done");

        // --- Summary -------------------------------------------------------------
        $display("\nPass: %0d   Fail: %0d   (fixed latency: %0d cycles)",
                 pass_count, fail_count, expected_latency);
        if (fail_count == 0)
            $display("Divider verified");
        else
            $display("Divider unit has bugs, check the failed cases\n");
        $finish;
    end

endmodule
