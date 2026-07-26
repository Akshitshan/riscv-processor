// ============================================================
//  MODULE: data_mem — Data Memory
//  PURPOSE: The RAM your program reads from and writes to.
//           Supports byte (8-bit), halfword (16-bit), and
//           word (32-bit) accesses with correct sign extension.
// ============================================================
//
//  WHAT THIS IS IN PLAIN ENGLISH:
//  If instruction memory is your program's "code" (read-only),
//  data memory is your program's "working storage" (read/write).
//  This is where your stack lives, where global variables are
//  stored, and where arrays and structs sit.
//
//  THE DIFFERENCE FROM INSTRUCTION MEMORY:
//  Instruction memory: only ever reads 32-bit words, always aligned.
//  Data memory: can read OR write, in 8, 16, or 32-bit chunks,
//               at any byte address (subject to alignment rules).
//
//  WHY DIFFERENT SIZES?
//  C has char (8-bit), short (16-bit), and int (32-bit).
//  When you do "char c = array[i]", the CPU uses LBU (load byte unsigned).
//  When you do "array[i] = c", the CPU uses SB (store byte).
//  The funct3 field in the instruction tells us which size to use.
//
//  funct3 for loads:              funct3 for stores:
//   000 = LB  (byte, signed)       000 = SB (byte)
//   001 = LH  (halfword, signed)   001 = SH (halfword)
//   010 = LW  (word)               010 = SW (word)
//   100 = LBU (byte, unsigned)
//   101 = LHU (halfword, unsigned)

module data_mem #(
    parameter MEM_DEPTH = 1024   // 1024 words = 4 KB of data memory
) (
    input  logic        clk,
    input  logic        mem_read,    // 1 = perform a load this cycle
    input  logic        mem_write,   // 1 = perform a store this cycle
    input  logic [2:0]  funct3,      // Selects access size and signedness
    input  logic [31:0] addr,        // Byte address (from ALU: rs1 + imm)
    input  logic [31:0] write_data,  // Data to store (from rs2)
    output logic [31:0] read_data    // Data loaded (goes to writeback)
);

    // ── The memory array ─────────────────────────────────────
    //  We store memory as BYTES (8 bits each), not words.
    //  This makes byte and halfword accesses much easier to implement —
    //  we just read/write the individual bytes we need.
    //  A word access reads/writes 4 consecutive bytes.

    logic [7:0] mem [0:MEM_DEPTH*4-1];   // 4096 bytes = 4 KB

    // ── Initialise memory to 0 ───────────────────────────────
    integer i;
    initial begin
        for (i = 0; i < MEM_DEPTH*4; i = i + 1)
            mem[i] = 8'h00;
    end

    // ── WRITE (synchronous — happens on clock edge) ──────────
    //
    //  Writes are clocked because we don't want partial writes.
    //  If we wrote combinationally and a glitch hit mem_write,
    //  we could corrupt memory. The clock edge is clean and atomic.

    always_ff @(posedge clk) begin
        if (mem_write) begin
            case (funct3)

                // SB — Store Byte: write only the lowest 8 bits of rs2
                //  at the exact byte address given.
                3'b000: mem[addr]     <= write_data[7:0];

                // SH — Store Halfword: write 2 bytes (16 bits).
                //  Little-endian layout: lower byte at lower address.
                //  addr+0 gets bits [7:0], addr+1 gets bits [15:8].
                //  (RISC-V is little-endian by convention.)
                3'b001: begin
                    mem[addr]     <= write_data[7:0];
                    mem[addr + 1] <= write_data[15:8];
                end

                // SW — Store Word: write all 4 bytes.
                //  Little-endian: byte 0 (LSB) at lowest address.
                3'b010: begin
                    mem[addr]     <= write_data[7:0];
                    mem[addr + 1] <= write_data[15:8];
                    mem[addr + 2] <= write_data[23:16];
                    mem[addr + 3] <= write_data[31:24];
                end

            endcase
        end
    end

    // ── READ (combinational — instant) ────────────────────────
    //
    //  Reads are combinational so the result is available in the
    //  SAME cycle as the address. This is important for the
    //  single-cycle design — everything must finish in one cycle.
    //
    //  We reassemble the full word from individual bytes,
    //  then apply sign extension for signed load types (LB, LH).

    logic [7:0]  byte_val;    // Extracted byte
    logic [15:0] half_val;    // Extracted halfword (assembled from 2 bytes)

    always_comb begin
        read_data = 32'b0;   // Safe default

        if (mem_read) begin
            case (funct3)

                // LB — Load Byte, SIGN-EXTEND to 32 bits.
                //  Read one byte. The {{24{byte[7]}}} fills the upper
                //  24 bits with the sign bit of the byte.
                //  Example: byte = 0xFF (-1 signed)
                //    read_data = 0xFFFFFFFF (-1 as 32-bit signed)
                3'b000: begin
                    byte_val  = mem[addr];
                    read_data = {{24{byte_val[7]}}, byte_val};
                end

                // LH — Load Halfword, SIGN-EXTEND to 32 bits.
                //  Reassemble from two bytes (little-endian order),
                //  then sign-extend from bit 15.
                3'b001: begin
                    half_val  = {mem[addr + 1], mem[addr]};  // {high, low}
                    read_data = {{16{half_val[15]}}, half_val};
                end

                // LW — Load Word: read all 4 bytes, reassemble.
                //  No sign extension needed — fills all 32 bits.
                3'b010: begin
                    read_data = {mem[addr + 3],   // bits [31:24]
                                 mem[addr + 2],   // bits [23:16]
                                 mem[addr + 1],   // bits [15:8]
                                 mem[addr]};      // bits [7:0]
                end

                // LBU — Load Byte, ZERO-EXTEND (unsigned).
                //  Same as LB but fills upper bits with 0s, not sign bit.
                //  Example: byte = 0xFF → read_data = 0x000000FF (255, not -1)
                3'b100: begin
                    read_data = {24'b0, mem[addr]};
                end

                // LHU — Load Halfword, ZERO-EXTEND (unsigned).
                3'b101: begin
                    read_data = {16'b0, mem[addr + 1], mem[addr]};
                end

            endcase
        end
    end

endmodule
