// ============================================================
//  MODULE: pc_reg — Program Counter Register
//  PURPOSE: Holds the address of the instruction currently
//           being fetched. Updates every clock cycle.
// ============================================================
//
//  WHAT THIS IS IN PLAIN ENGLISH:
//  Imagine your program is a list of instructions stored in
//  memory, each at a numbered address (0, 4, 8, 12, ...).
//  The PC is a single register that remembers "which address
//  am I at right now?" Every clock tick it either:
//    - Moves to the next instruction (pc + 4), or
//    - Jumps to a branch/jump target address
//
//  WHY pc+4 AND NOT pc+1?
//  Every RV32I instruction is exactly 4 bytes (32 bits) wide.
//  So to move to the next instruction you skip 4 bytes.

module pc_reg (
    // ── Inputs ──────────────────────────────────────────────
    input  logic        clk,      // Clock: the heartbeat of your CPU.
                                  // Every rising edge = one tick of time.

    input  logic        rst,      // Reset: when rst=1, PC goes back to
                                  // address 0 (start of your program).
                                  // Like pressing the reset button on a
                                  // microcontroller.

    input  logic [31:0] pc_next,  // The NEXT address to load.
                                  // [31:0] means a 32-bit wide bus.
                                  // This comes from the "PC next" logic
                                  // block (pc+4 or branch target).

    // ── Outputs ─────────────────────────────────────────────
    output logic [31:0] pc        // The CURRENT address being used to
                                  // fetch an instruction right now.
);

    // ── The actual hardware: one 32-bit flip-flop ───────────
    //
    //  always_ff = "always sequential" = a register (flip-flop)
    //  @(posedge clk) = "trigger on the RISING EDGE of the clock"
    //                   (the moment the clock signal goes from 0→1)
    //
    //  A flip-flop is the most basic memory element in digital logic.
    //  It "captures" whatever is on its input at the rising clock edge
    //  and holds that value until the next rising edge.

    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            pc <= 32'h0000_0000;  // On reset: go to address 0x00000000
                                  // 32'h means "32-bit hex number"
                                  // The underscores are just for readability
        else
            pc <= pc_next;        // Every normal clock tick: load next address
    end

    // That's it. One register. But it controls EVERYTHING the CPU does.

endmodule
