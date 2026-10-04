// Module: tb_verify

// 1. Loads expected register values from expected_regs.hex
//    (the Python reference model wrote this file)
// 2. Runs the real RTL pipeline for 500 clock cycles
// 3. Compares every register: DUT vs expected
// 4. Counts which instruction types were fetched (coverage)
// 5. Dumps register state so the regression runner can read it

// V2: as each divide now takes 33 cycles, its repeat(3000) instead of 800

`timescale 1ns/1ps

module tb_verify;

    logic clk, rst;
    logic [31:0] dbg_pc, dbg_instr, dbg_wb_data;

    logic [31:0] expected [0:31];

    // --- Coverage counters ------------------------------------------------
    int cov_alu_r = 0;   // R-type: ADD SUB AND OR XOR SLL SRL SRA
    int cov_alu_i = 0;   // I-type: ADDI ANDI ORI XORI SLLI SRLI
    int cov_load = 0;   // Loads: LW LH LB LHU LBU
    int cov_store = 0;   // Stores: SW SH SB
    int cov_branch = 0;   // Branches: BEQ BNE BLT BGE BLTU BGEU
    int cov_jump = 0;   // Jumps: JAL JALR
    int cov_lui = 0;   // LUI
    int cov_mul = 0;   // M-ext multiply: MUL MULH
    int cov_div = 0;   // M-ext divide: DIV DIVU REM REMU

    int pass_count = 0;
    int fail_count = 0;

    riscv_pipeline DUT (
        .clk (clk),
        .rst (rst),
        .dbg_pc (dbg_pc),
        .dbg_instr (dbg_instr),
        .dbg_wb_data (dbg_wb_data)
    );

    initial clk = 0;
    always #5 clk = ~clk;

    initial begin
        $dumpfile("wave_verify.vcd");
        $dumpvars(0, tb_verify);
    end

    // --- Coverage monitor -------------------------------------------------
    // Skips NOPs (0x00000013) which are pipeline bubbles.
    always_ff @(posedge clk) begin
        if (!rst && dbg_instr != 32'h0000_0013) begin
            case (dbg_instr[6:0])       // classify by opcode
                7'b0110011: begin       // R-type or M-extension
                    if (dbg_instr[31:25] == 7'b000_0001)
                        // M-extension: funct7 = 0000001, funct3 0-3 = multiply, 4-7 = divide
                        cov_mul <= (dbg_instr[14:12] < 3'h4) ? cov_mul + 1 : cov_mul;
                    else
                        cov_alu_r <= cov_alu_r + 1;
                    if (dbg_instr[31:25]==7'b000_0001 && dbg_instr[14:12]>=3'h4)
                        cov_div <= cov_div + 1;
                end
                7'b0010011: cov_alu_i <= cov_alu_i + 1;
                7'b0000011: cov_load <= cov_load + 1;
                7'b0100011: cov_store <= cov_store + 1;
                7'b1100011: cov_branch <= cov_branch + 1;
                7'b1101111: cov_jump <= cov_jump + 1;
                7'b1100111: cov_jump <= cov_jump + 1;
                7'b0110111: cov_lui <= cov_lui + 1;
                default: ;
            endcase
        end
    end

    task automatic check_reg(
        input [4:0] r,
        input [31:0] exp,
        input [31:0] act
    );
        if (act === exp) begin
            $display("PASS | x%-2d = 0x%08h", r, act);
            pass_count++;
        end else begin
            $display("FAIL | x%-2d = 0x%08h (expected 0x%08h)", r, act, exp);
            fail_count++;
        end
    endtask

    initial begin
        $display("Verification Testbench");

        // Load expected values written by the Python reference model
        $readmemh("expected_regs.hex", expected);

        // Reset for 3 cycles
        rst = 1;
        repeat(3) @(posedge clk); #1;
        rst = 0;

        // Run for 500 cycles- enough for any of our test programs
        // (even with stalls from load-use hazards)
        repeat(3000) @(posedge clk); #1;   // bumped for icache miss headroom (Phase 5b)

        // --- Scoreboard comparison ----------------------------------------
        $display("--- Register comparison: DUT vs reference model ---");
        begin
            int i;
            for (i = 1; i < 32; i++) begin
                if (expected[i] != 0 || DUT.u_core.u_rf.regs[i] != 0)
                    check_reg(i[4:0], expected[i], DUT.u_core.u_rf.regs[i]);
            end
        end

        // --- Coverage report ----------------------------------------------
        begin
            int total_i, types_hit;
            total_i = cov_alu_r + cov_alu_i + cov_load + cov_store +
                       cov_branch + cov_jump + cov_lui + cov_mul + cov_div;
            types_hit= (cov_alu_r>0) + (cov_alu_i>0) + (cov_load>0) +
                       (cov_store>0) + (cov_branch>0) + (cov_jump>0) +
                       (cov_lui>0) + (cov_mul>0) + (cov_div>0);

            $display("\n--- Functional Coverage ---");
            $display("ALU R-type: %0d", cov_alu_r);
            $display("ALU I-type: %0d", cov_alu_i);
            $display("Loads: %0d", cov_load);
            $display("Stores: %0d", cov_store);
            $display("Branches: %0d", cov_branch);
            $display("Jumps: %0d", cov_jump);
            $display("LUI: %0d", cov_lui);
            $display("M-ext mul: %0d", cov_mul);
            $display("M-ext div: %0d", cov_div);
            $display("\n Total instr: %0d", total_i);
            $display("Categories: %0d / 9 hit", types_hit);
        end

        $display("PASS: %0d  FAIL: %0d", pass_count, fail_count);
        if (fail_count == 0)
            $display("Verified");
        else
            $display("Failed- open wave_verify.vcd to debug");

        // --- Dump register values for Python regression runner ------------
        $display("REGDUMP_START");
        begin
            int j;
            for (j = 0; j < 32; j++)
                $display("x%0d=0x%08h", j, DUT.u_core.u_rf.regs[j]);
        end
        $display("REGDUMP_END");

        $finish;
    end

    initial begin #600000; $display("TIMEOUT"); $finish; end

endmodule
