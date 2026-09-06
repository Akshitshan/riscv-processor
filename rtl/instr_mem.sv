// Module: instr_mem- Instruction Memory
// Purpose: Stores the compiled program and returns the 32-bit instruction at the requested address.
// Example: Instruction 0xABCDEF12 sits in memory as:
//          addr 0: 0x12  (lowest byte first)
//          addr 1: 0xEF
//          addr 2: 0xCD
//          addr 3: 0xAB
//  To reassemble: {mem[3], mem[2], mem[1], mem[0]} = 0xABCDEF12

module instr_mem #(parameter MEM_DEPTH = 1024)
   (input  logic [31:0] addr,            // Byte address from PC
    output logic [31:0] instr);          // 32-bit instruction out

    logic [7:0] mem [0:MEM_DEPTH*4-1];   
    // 1024*4 = 4096 memory locations and each location stores 8-bits or 1-byte

    integer i;
    initial 
        begin
            for (i = 0; i < MEM_DEPTH*4; i = i + 1)
                mem[i] = 8'h00;
            $readmemh("program.hex", mem);   // Load compiled program
        end

    always_comb 
    begin
        instr = { mem[addr + 3],   // bits [31:24]
                  mem[addr + 2],   // bits [23:16]
                  mem[addr + 1],   // bits [15:8]
                  mem[addr + 0] }; // bits [7:0]
    end

endmodule