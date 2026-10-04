// Module: riscv_pipeline- simulation wrapper (core + memories)

// V2: added branch predictor and icache signals
// V3: Removing 'import risv_pkg::*' bcz yosys is choking at the import call
// V4: Full restructure. This now connects riscv_core to instr_mem and data_mem.
//     This wrapper is simulation-only. Synthesis targets riscv_core directly.

`timescale 1ns/1ps

module riscv_pipeline (
    input logic clk,
    input logic rst,
    output logic [31:0] dbg_pc,
    output logic [31:0] dbg_instr,
    output logic [31:0] dbg_wb_data,
    output logic dbg_branch_resolved,   // pulses when any branch finishes in EX
    output logic dbg_mispredict,        // pulses when that branch was guessed wrong
    output logic dbg_icache_hit,        // pulses on every cache hit
    output logic dbg_icache_miss        // pulses once per new miss
);

    logic [31:0] imem_addr, imem_rdata;
    logic dmem_read, dmem_write;
    logic [2:0] dmem_funct3;
    logic [31:0] dmem_addr, dmem_wdata, dmem_rdata;

    riscv_core u_core (
        .clk (clk),
        .rst (rst),
        .imem_addr (imem_addr),
        .imem_rdata (imem_rdata),
        .dmem_read (dmem_read),
        .dmem_write (dmem_write),
        .dmem_funct3 (dmem_funct3),
        .dmem_addr (dmem_addr),
        .dmem_wdata (dmem_wdata),
        .dmem_rdata (dmem_rdata),
        .dbg_pc (dbg_pc),
        .dbg_instr (dbg_instr),
        .dbg_wb_data (dbg_wb_data),
        .dbg_branch_resolved (dbg_branch_resolved),
        .dbg_mispredict (dbg_mispredict),
        .dbg_icache_hit (dbg_icache_hit),
        .dbg_icache_miss (dbg_icache_miss)
    );
 
    instr_mem #(.MEM_DEPTH(1024)) u_imem (
        .addr (imem_addr),
        .instr (imem_rdata)
    );
 
    data_mem #(.MEM_DEPTH(1024)) u_dmem (
        .clk (clk),
        .mem_read (dmem_read),
        .mem_write (dmem_write),
        .funct3 (dmem_funct3),
        .addr (dmem_addr),
        .write_data (dmem_wdata),
        .read_data (dmem_rdata)
    );
 
endmodule
