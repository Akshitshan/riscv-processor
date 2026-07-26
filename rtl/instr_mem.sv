// ============================================================
//  MODULE: instr_mem — Instruction Memory
//  PURPOSE: Stores the compiled program and returns the
//           32-bit instruction at the requested address.
//
//  FIX: objcopy -O verilog writes bytes, not 32-bit words.
//  We store as a BYTE array and reassemble into 32-bit words
//  using little-endian order (LSB at lowest address).
//
//  LITTLE-ENDIAN means:
//  Instruction 0x00A00093 (addi x1,x0,10) sits in memory as:
//    addr 0: 0x93  (lowest byte first)
//    addr 1: 0x00
//    addr 2: 0xA0
//    addr 3: 0x00
//  We reassemble: {mem[3], mem[2], mem[1], mem[0]} = 0x00A00093
// ============================================================

module instr_mem #(
    parameter MEM_DEPTH = 1024   // 1024 words = 4096 bytes
) (
    input  logic [31:0] addr,    // Byte address from PC
    output logic [31:0] instr    // 32-bit instruction out
);

    // Byte array — matches exactly what objcopy -O verilog produces
    logic [7:0] mem [0:MEM_DEPTH*4-1];   // 4096 bytes

    // Initialise to NOP (addi x0,x0,0 = 0x00000013), then load hex
    integer i;
    initial begin
        for (i = 0; i < MEM_DEPTH*4; i = i + 1)
            mem[i] = 8'h00;
        $readmemh("program.hex", mem);   // Load compiled program
    end

    // Reassemble 4 consecutive bytes into one 32-bit word
    // Little-endian: lowest address = least-significant byte
    always_comb begin
        instr = { mem[addr + 3],   // bits [31:24]
                  mem[addr + 2],   // bits [23:16]
                  mem[addr + 1],   // bits [15:8]
                  mem[addr + 0] }; // bits [7:0]
    end

endmodule
