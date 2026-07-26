// ============================================================
//  MODULE: reg_file — Register File
//  PURPOSE: The CPU's 32 working registers (x0 to x31).
//           Two can be read simultaneously; one can be written.
// ============================================================
//
//  WHAT THIS IS IN PLAIN ENGLISH:
//  A register file is like a small, extremely fast scratchpad.
//  Your CPU uses these 32 registers to hold all the values
//  it's currently working with. Unlike memory (which takes
//  a whole clock cycle to access), registers respond in a
//  fraction of a cycle — they're right inside the CPU core.
//
//  WHY TWO READ PORTS?
//  Most instructions need two source values. For example:
//    add x5, x1, x2   →  needs to read x1 AND x2 simultaneously.
//  With two independent read ports, we read both in one shot.
//
//  WHY ONE WRITE PORT?
//  Only one instruction executes per cycle in a single-cycle CPU,
//  so only one register can ever be written per cycle.

module reg_file (
    // ── Clock (writes are synchronous) ───────────────────────
    input  logic        clk,

    // ── Read Port A (for rs1 — source register 1) ──────────
    input  logic [4:0]  rs1_addr, // Which register to read? (0–31)
                                  // [4:0] = 5 bits wide, because
                                  // 2^5 = 32 possible registers.
    output logic [31:0] rs1_data, // The 32-bit value inside that register.

    // ── Read Port B (for rs2 — source register 2) ──────────
    input  logic [4:0]  rs2_addr, // Which register to read?
    output logic [31:0] rs2_data, // Its 32-bit value.

    // ── Write Port (for rd — destination register) ─────────
    input  logic [4:0]  rd_addr,  // Which register to write to?
    input  logic [31:0] rd_data,  // What value to write?
    input  logic        reg_write // ENABLE signal: only write when
                                  // this is 1. If 0, nothing changes.
                                  // The control unit drives this signal.
);

    // ── The register array ───────────────────────────────────
    //
    //  32 registers, each 32 bits wide.
    //  regs[0] = x0, regs[1] = x1, ... regs[31] = x31

    logic [31:0] regs [0:31];

    // ── Initialise all registers to 0 ───────────────────────
    //  (In real hardware, registers have undefined power-on state.
    //  For simulation, initialising to 0 avoids X-propagation
    //  issues — mysterious undefined values spreading everywhere.)

    integer i;
    initial begin
        for (i = 0; i < 32; i = i + 1)
            regs[i] = 32'b0;
    end

    // ── Read ports (combinational — instant, no clock) ───────
    //
    //  The key hardware rule of RISC-V: x0 ALWAYS reads as 0.
    //  No matter what anyone writes to x0, reading it gives 0.
    //  This is enforced here with a ternary (? :) expression:
    //    "if address is 0, output 0; otherwise output regs[addr]"
    //
    //  This gives us free pseudo-instructions like:
    //    addi x5, x0, 42   →  x5 = 0 + 42 = 42
    //    sub  x5, x0, x1   →  x5 = 0 - x1  (negate x1)

    always_comb begin
        rs1_data = (rs1_addr == 5'b0) ? 32'b0 : regs[rs1_addr];
        rs2_data = (rs2_addr == 5'b0) ? 32'b0 : regs[rs2_addr];
    end

    // ── Write port (sequential — only on clock rising edge) ──
    //
    //  WHY is writing sequential but reading is combinational?
    //  Reads: We need the register value THIS cycle to do the
    //         computation. Must be instant.
    //  Writes: We want to store the result of THIS cycle's work.
    //          The result isn't ready until the end of the cycle,
    //          so we latch it on the NEXT rising edge.
    //
    //  The guard (rd_addr != 0) enforces x0 = always 0.
    //  Even if someone tries to write to x0, we block it.

    always_ff @(posedge clk) begin
        if (reg_write && rd_addr != 5'b0)
            regs[rd_addr] <= rd_data;
    end

endmodule
