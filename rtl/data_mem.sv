//  Module: data_mem — Data Memory
//  Purpose: The RAM your program reads from and writes to.
//           Supports byte (8-bit), halfword (16-bit), and
//           word (32-bit) accesses with correct sign extension.

//  funct3 for loads:              funct3 for stores:
//   000 = LB  (byte, signed)       000 = SB (byte)
//   001 = LH  (halfword, signed)   001 = SH (halfword)
//   010 = LW  (word)               010 = SW (word)
//   100 = LBU (byte, unsigned)
//   101 = LHU (halfword, unsigned)

module data_mem #(parameter MEM_DEPTH = 1024)
(
    input logic clk,
    input logic mem_read, // 1 = perform a load this cycle
    input logic mem_write, // 1 = perform a store this cycle
    input logic [2:0] funct3, // Selects access size and sign
    input logic [31:0] addr, // Byte address (from ALU: rs1 + imm)
    input logic [31:0] write_data, // Data to store (from rs2)
    output logic [31:0] read_data // Data loaded (goes to writeback)
); 

    logic [7:0] mem [0:MEM_DEPTH*4-1];   // 4096 bytes = 4 KB

    integer i;
    initial 
    begin
        for (i = 0; i < MEM_DEPTH*4; i = i + 1)
            mem[i] = 8'h00;
    end

// WRITE- synchronous
    always_ff @(posedge clk) 
    begin
        if (mem_write) 
        begin
            case (funct3)

                // As it is SB, we store only one byte= last 8 bits
                3'b000: mem[addr] <= write_data[7:0];

                // For SH, store two bytes= last 16 bits (little endian)
                3'b001: begin
                    mem[addr]     <= write_data[7:0];
                    mem[addr + 1] <= write_data[15:8];
                end

                // For SW, store four bytes= last 32 bits 
                3'b010: begin
                    mem[addr]     <= write_data[7:0];
                    mem[addr + 1] <= write_data[15:8];
                    mem[addr + 2] <= write_data[23:16];
                    mem[addr + 3] <= write_data[31:24];
                end
            endcase
        end
    end

// READ- combinational
    logic [7:0]  byte_val;    // Extracted byte
    logic [15:0] half_val;    // Extracted halfword (assembled from 2 bytes)

    always_comb begin
        read_data = 32'b0;   // Safe default

        if (mem_read) 
        begin
            case (funct3)

                // Load just a byte
                3'b000: begin
                    byte_val  = mem[addr];
                    read_data = {{24{byte_val[7]}}, byte_val};
                end

                // Load a halfword
                3'b001: begin
                    half_val  = {mem[addr + 1], mem[addr]};  // {high, low}
                    read_data = {{16{half_val[15]}}, half_val};
                end

                // Load the whole word
                3'b010: begin
                    read_data = {mem[addr + 3],   // bits [31:24]
                                 mem[addr + 2],   // bits [23:16]
                                 mem[addr + 1],   // bits [15:8]
                                 mem[addr]};      // bits [7:0]
                end

                // LBU, same as LB but loaded with zeroes instead of signed bit
                3'b100: begin
                    read_data = {24'b0, mem[addr]};
                end

                // LHU, same as LH but loaded with zeroes instead of signed bit
                3'b101: begin
                    read_data = {16'b0, mem[addr + 1], mem[addr]};
                end
            endcase
        end
    end
endmodule