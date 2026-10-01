// Module: tb_imm_gen_unit- Testbench for imm_gen.sv

`timescale 1ns/1ps

module tb_imm_gen_unit;
    import riscv_pkg::*;

    logic [31:0] instr;
    logic [2:0] imm_sel;
    logic [31:0] imm_out;

    imm_gen DUT (
        .instr (instr),
        .imm_sel (imm_sel),
        .imm_out (imm_out)
    );

    int pass_count = 0;
    int fail_count = 0;

    task automatic check(
        input [31:0] instr_in,
        input [2:0] sel_in,
        input [31:0] expected,
        input string label
    );
        instr = instr_in;
        imm_sel = sel_in;
        #1;
        if (imm_out === expected) begin
            $display("PASS | %-30s | imm = 0x%08h", label, imm_out);
            pass_count++;
        end 
        else begin
            $display("FAIL | %-30s | got 0x%08h, expected 0x%08h", label, imm_out, expected);
            fail_count++;
        end
    endtask

    initial begin
        $display("\n imm_gen Unit Testbench");

        // --- R- type: no immediate -------------------------------------------------
        $display("\n----- R- type (no immediate) -----");
        check(32'h0020_8033, IMM_X, 32'h0000_0000, "add x0,x1,x2 (defaults to 0)");
        
        // --- I- type ---------------------------------------------------------------
        $display("\n----- I- type -----");
        check(32'hFFC0_8293, IMM_I, 32'hFFFF_FFFC, "addi x5,x1,-4 (negative imm)");
        check(32'h00A0_8293, IMM_I, 32'h0000_000A, "addi x5,x1,10 (positive imm)");

        // --- S- type ---------------------------------------------------------------
        $display("\n----- S- type -----");
        check(32'h0020_8423, IMM_S, 32'h0000_0008, "sw x2,8(x1)");
        check(32'hFE20_8FA3, IMM_S, 32'hFFFF_FFFF, "sw x2,-1(x1) (negative imm)");

        // --- B- type ---------------------------------------------------------------
        $display("\n----- B- type -----");
        check(32'h0020_8863, IMM_B, 32'h0000_0010, "beq x1,x2,+16");

        // --- U- type ---------------------------------------------------------------
        $display("\n----- U- type -----");
        check(32'h1234_52B7, IMM_U, 32'h1234_5000, "lui x5,0x12345");

        // --- J- type ---------------------------------------------------------------
        $display("\n----- J- type -----");
        check(32'h801F_F0EF, IMM_J, 32'hFFFF_F800, "jal x1,-2048 (negative, sign-extended)");

        // --- Summary -------------------------------------------------------------
        $display("\nPASS: %0d   FAIL: %0d", pass_count, fail_count);
        if (fail_count == 0)
            $display("Imm_gen unit verified \n");
        else
            $display("Imm_gen has bugs- check the failed cases \n");
        $finish;
    end
endmodule
