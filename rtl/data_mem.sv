// Module: data_mem- Data Memory
// Purpose: The RAM that the program reads from and writes to.
//          Supports byte (8-bit), halfword (16-bit), and
//          word (32-bit) accesses with correct sign extension.

// Little Endian memory
// If we read from memory, thats a load
// If we write to the memory, thats a store

module data_mem #(parameter MEM_DEPTH = 1024)
(
    input  logic        clk,
    input  logic        mem_read,
    input  logic        mem_write,
    input  logic [2:0]  funct3,         // Selects access size and sign
    input  logic [31:0] addr,           // Byte address (from ALU: rs1 + imm)
    input  logic [31:0] write_data,
    output logic [31:0] read_data       // Data loaded (goes to writeback)
); 

    logic [7:0] mem [0:MEM_DEPTH*4-1];   // 4096 bytes = 4 KB

    // --- Safe initialise ---------------------------------------------
    integer i;
    initial 
    begin
        for (i = 0; i < MEM_DEPTH*4; i = i + 1)
            mem[i] = 8'h00;
    end

    // --- Write: always synchronously on clk --------------------------
    always_ff @(posedge clk) 
    begin
        if (mem_write) 
        begin
            case (funct3)
                3'b000: mem[addr] <= write_data[7:0];       // sb- only last byte

                3'b001: begin                               // sh- last two bytes
                    mem[addr]     <= write_data[7:0];
                    mem[addr + 1] <= write_data[15:8];
                end

                3'b010: begin                               // sw- last four bytes
                    mem[addr]     <= write_data[7:0];
                    mem[addr + 1] <= write_data[15:8];
                    mem[addr + 2] <= write_data[23:16];
                    mem[addr + 3] <= write_data[31:24];
                end
            endcase
        end
    end

    // --- Read: we can read whenever ----------------------------------
    logic [7:0]  byte_val;    // Extracted byte
    logic [15:0] half_val;    // Extracted halfword (assembled from 2 bytes)

    always_comb begin
        read_data = 32'b0;   // Safe default

        if (mem_read) 
        begin
            case (funct3)
                3'b000: begin                                   // byte load with signed padding
                    byte_val  = mem[addr];
                    read_data = {{24{byte_val[7]}}, byte_val};
                end
                3'b001: begin
                    half_val  = {mem[addr + 1], mem[addr]};     // halfword load with signed padding
                    read_data = {{16{half_val[15]}}, half_val};
                end
                3'b010: begin                                   // full word load
                    read_data = {mem[addr + 3],   // bits [31:24]
                                 mem[addr + 2],   // bits [23:16]
                                 mem[addr + 1],   // bits [15:8]
                                 mem[addr]};      // bits [7:0]
                end

                3'b100: begin                                   // LB with zero padding
                    read_data = {24'b0, mem[addr]};
                end
                3'b101: begin                                   // LH with zero padding
                    read_data = {16'b0, mem[addr + 1], mem[addr]};
                end
            endcase
        end
    end
endmodule
