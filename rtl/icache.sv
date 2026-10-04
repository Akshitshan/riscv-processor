// Module: icache- Direct-Mapped Instruction Cache
// Purpose: Saves 16 recently fetched instructions in a fast storage.
//          If its a hit, we return it in the same cycle without penalty
//          otherwise we simulate the delay of the slow main memory by penalizing 
//          and adding 5 extra cycles before returning the data and also
//          saving it in the cache for next time.

// V2: 
`timescale 1ns/1ps

module icache (
    input logic clk,
    input logic rst,
    input logic flush,       // If prev branch evaluates to not-taken, no need to serve penalty
    input logic [31:0] addr,
    output logic [31:0] instr_out,
    output logic stall,      // 1 = miss in progress, freeze pipeline

    output logic [31:0] mem_addr,   // to backing instruction memory
    input logic [31:0] mem_rdata,   // from backing instruction memory

    // --- For the benchmark testbench ---------------------------------------
    output logic hit_pulse,
    output logic miss_pulse
);

    localparam int lines = 16;
    localparam logic [2:0] miss_wait = 3'd4;     // 5-cycle penalty (4..0)
    localparam logic idle = 1'b0;
    localparam logic miss = 1'b1;
 
    logic [31:0] data [0:lines-1];
    logic [25:0] tag [0:lines-1];
    logic [lines-1:0] valid;
 
    logic [3:0] index;
    logic [25:0] cur_tag;
    logic hit;
    logic state;
    logic [2:0] wait_count;
    logic fill;
 
    assign index = addr[5:2];
    assign cur_tag = addr[31:6];
    assign mem_addr = addr;
 
    assign hit = valid[index] && (tag[index] == cur_tag);
    assign fill = (state == miss) && (wait_count == 3'd0) && !flush;
 
    // Control state: FSM and valid bits (async reset)
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= idle;
            wait_count <= 3'd0;
            valid <= '0;
        end 
        else if (flush) begin
            state <= idle;
            wait_count <= 3'd0;
        end 
        else begin
            case (state)
                idle: begin
                    if (!hit) begin
                        state <= miss;
                        wait_count <= miss_wait;
                    end
                end
                miss: begin
                    if (wait_count == 3'd0) begin
                        valid[index] <= 1'b1;
                        state <= idle;
                    end else begin
                        wait_count <= wait_count - 3'd1;
                    end
                end
                default: state <= idle;
            endcase
        end
    end
 
    // Storage arrays: no reset needed
    always_ff @(posedge clk) begin
        if (fill) begin
            data[index] <= mem_rdata;
            tag[index] <= cur_tag;
        end
    end
 
    assign stall = (state == miss);
    assign instr_out = hit ? data[index] : mem_rdata;
    assign hit_pulse = (state == idle) && hit;
    assign miss_pulse = (state == idle) && !hit;
 
endmodule
