// Module: hazard_unit — Detects pipeline hazards
//  There are two types we handle here: 1: Load-use hazard
//                                      2: Control Hazard

`timescale 1ns/1ps

module hazard_unit (
    // What instruction is in the ID/EX stage right now?
    input  logic        id_ex_mem_read,  // Is it a LOAD instruction?
    input  logic [4:0]  id_ex_rd,        // Which register is it writing to?

    // What registers does the NEXT instruction (in ID stage) need?
    input  logic [4:0]  if_id_rs1,       // Source register 1
    input  logic [4:0]  if_id_rs2,       // Source register 2

    // Outputs: what the pipeline should do
    output logic stall_if_id,     // 1 = freeze IF/ID register
    output logic stall_pc,        // 1 = freeze the PC too
    output logic flush_id_ex      // 1 = inject NOP into EX stage
);

    // ── Load-use hazard detection ─────────────────────────────
    //
    //  A load-use hazard exists when ALL THREE of these are true:
    //   1. The instruction in EX is a LOAD (mem_read=1)
    //   2. The load's destination register (rd) is NOT x0
    //      (writing to x0 is always discarded, so no hazard)
    //   3. The load's rd matches either rs1 or rs2 of the
    //      instruction currently being decoded (in ID)
    //
    //  If any one of these is false, there's no hazard — let it run.

    logic load_use_hazard;

    assign load_use_hazard = id_ex_mem_read && (id_ex_rd != 5'b0) &&
                             ((id_ex_rd == if_id_rs1) || (id_ex_rd == if_id_rs2));

    // ── Drive outputs ─────────────────────────────────────────
    //  When a load-use hazard is detected:
    //   - stall_pc=1:     PC does NOT advance (re-fetches same instruction)
    //   - stall_if_id=1:  IF/ID register does NOT update (holds current instr)
    //   - flush_id_ex=1:  ID/EX register gets cleared to NOP (bubble injected)
    //
    //  This effectively inserts one empty cycle between the load
    //  and the instruction that needs its result.

    assign stall_pc    = load_use_hazard;
    assign stall_if_id = load_use_hazard;
    assign flush_id_ex = load_use_hazard;

endmodule
