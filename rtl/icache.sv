// Module: icache- Direct-Mapped Instruction Cache
// Purpose: Saves 16 recently fetched instructions in a fast storage.
//          If its a hit, we return it in the same cycle without penalty
//          otherwise we simulate the delay of the slow main memory by penalizing 
//          and adding 5 extra cycles before returning the data and also
//          saving it in the cache for next time.

`timescale 1ns/1ps

module icache (
    input logic clk,
    input logic rst,
    input logic flush,       // If prev branch evaluates to not-taken, no need to serve penalty
    input logic [31:0] addr,
    output logic [31:0] instr_out,
    output logic stall,      // 1 = miss in progress, freeze pipeline

    // --- For the benchmark testbench ---------------------------------------
    output logic hit_pulse,
    output logic miss_pulse
);

    localparam LINES = 16;   // Only 1 instr per line
    localparam LATENCY = 5;    // simulated main-memory delay, in cycles

    logic [31:0] data [0:LINES-1];      // the cached instructions
    logic [25:0] tag [0:LINES-1];       // the tag stored for each line
    logic valid [0:LINES-1];            // has this line ever been filled?

    logic [3:0] index;         // Selects which line
    logic [25:0] cur_tag;       // Same line can house multiple instr, so another check
    assign index = addr[5:2];
    assign cur_tag = addr[31:6];

    // --- Hit detection ---------------------------------------------
    logic hit;
    assign hit = valid[index] && (tag[index] == cur_tag);

    // --- Existing instr_mem ----------------------------------------
    logic [31:0] mem_instr;
    instr_mem #(.MEM_DEPTH(1024)) u_backing_mem (
        .addr (addr),
        .instr (mem_instr)
    );

    // --- The miss-handling state machine ---------------------------
    typedef enum logic { IDLE, MISS } state_t;
    state_t state;
    logic [2:0] wait_count;   // counts down remaining wait cycles

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state <= IDLE;
            wait_count <= 3'd0;
            for (int i = 0; i < LINES; i++)
                valid[i] <= 1'b0;   // every line starts empty
        end 
        else if (flush) begin
            state <= IDLE;
            wait_count <= 3'd0;
        end 
        else begin
            case (state)
                IDLE: begin
                    if (!hit) begin                     // If miss detected
                        state <= MISS;
                        wait_count <= LATENCY - 1;
                    end
                    // If it's a hit, we just stay in Idle and not do anything
                end

                MISS: begin
                    if (wait_count == 3'd0) begin       // The simulated delay is over
                        data[index] <= mem_instr;
                        tag[index] <= cur_tag;
                        valid[index] <= 1'b1;
                        state <= IDLE;
                    end 
                    else begin
                        wait_count <= wait_count - 3'd1;
                    end
                end
                
            endcase
        end
    end

    // --- Outputs ---------------------------------------------------
    assign stall = (state == MISS);         // always stall whenever its a miss
    assign instr_out = hit ? data[index] : mem_instr;

    assign hit_pulse = (state == IDLE) && hit;
    assign miss_pulse = (state == IDLE) && !hit;

endmodule
