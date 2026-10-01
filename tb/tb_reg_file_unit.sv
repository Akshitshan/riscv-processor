// Module: tb_reg_file_unit- Testbench for reg_file.sv

`timescale 1ns/1ps

module tb_reg_file_unit;

    logic clk;
    logic [4:0] rs1_addr, rs2_addr, rd_addr;
    logic [31:0] rs1_data, rs2_data, rd_data;
    logic reg_write;

    reg_file DUT (
        .clk (clk),
        .rs1_addr (rs1_addr),
        .rs2_addr (rs2_addr),
        .rs1_data (rs1_data),
        .rs2_data (rs2_data),
        .rd_addr (rd_addr),
        .rd_data (rd_data),
        .reg_write (reg_write)
    );

    initial clk = 0;
    always #5 clk = ~clk;

    int pass_count = 0;
    int fail_count = 0;

    task automatic check_read(
        input [31:0] expected1, expected2,
        input string label
    );
        #1;
        if (rs1_data === expected1 && rs2_data === expected2) begin
            $display("PASS | %-45s | rs1=0x%0h rs2=0x%0h", label, rs1_data, rs2_data);
            pass_count++;
        end 
        else begin
            $display("FAIL | %-45s | got rs1=0x%0h rs2=0x%0h, expected rs1=0x%0h rs2=0x%0h",
                      label, rs1_data, rs2_data, expected1, expected2);
            fail_count++;
        end 
    endtask

    initial begin
        reg_write = 0;
        rs1_addr = 0; rs2_addr = 0; rd_addr = 0; rd_data = 0;

        $display("\n reg_file Unit Testbench");

        $display("\n----- x0 should always be zero -----");
        rs1_addr = 5'd0; rs2_addr = 5'd0;
        check_read(32'd0, 32'd0, "x0 always zero no matter what");

        $display("\n----- Normal write then read -----");
        @(negedge clk);
        rd_addr = 5'd3; rd_data = 32'd100; reg_write = 1'b1;
        @(posedge clk); #1;
        reg_write = 0;
        rs1_addr = 5'd3; rs2_addr = 5'd3;
        check_read(32'd100, 32'd100, "x3 correctly holds 100 after a normal write");

        $display("\n----- Writing to x0 does nothing -----");
        @(negedge clk);
        rd_addr = 5'd0; rd_data = 32'd999; reg_write = 1'b1;
        @(posedge clk); #1;
        reg_write = 0;
        rs1_addr = 5'd0;
        check_read(32'd0, 32'd100, "x0 still reads 0 despite the write attempt");

        $display("\n----- Write- first forwarding -----");
        @(negedge clk);
        rd_addr = 5'd7; rd_data = 32'd55;
        reg_write = 1'b1;
        rs1_addr = 5'd7;               // reading the same register being written
        rs2_addr = 5'd7;
        
        // We check the combinational read logic right now before the +ve edge
        // to check the forwarding functionality. If we read after, it will just 
        // be a normal write-then-read case
        check_read(32'd55, 32'd55, "write first forwarding is seeing the new value, so nice");
        @(posedge clk); #1;
        reg_write = 0;

        $display("\n----- Two independent registers read simultaneously -----");
        @(negedge clk);
        rd_addr = 5'd10; rd_data = 32'd10; reg_write = 1;
        @(posedge clk); #1; reg_write = 0;
        @(negedge clk);
        rd_addr = 5'd20; rd_data = 32'd20; reg_write = 1;
        @(posedge clk); #1; 
        reg_write = 0;
        rs1_addr = 5'd10; rs2_addr = 5'd20;
        check_read(32'd10, 32'd20, "rs1=x10, rs2=x20 read independently, same cycle");

        $display("\n Pass: %0d   Fail: %0d", pass_count, fail_count);
        if (fail_count == 0)
            $display("Reg_file unit verified- all %0d cases pass\n", pass_count);
        else
            $display("Reg_file has bugs- check the failed cases\n");
        $finish;
    end
endmodule
