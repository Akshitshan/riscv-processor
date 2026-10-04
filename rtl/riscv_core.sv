// Module: riscv_core- 5-stage pipelined RV32IM core
// Purpose: This is the synthesizable CPU. It contains no memories.
//          Instruction fetch goes out through the imem_* port (via the
//          icache) and loads/stores go out through the dmem_* port.
//          riscv_pipeline.sv wraps this core with instr_mem/data_mem
//          for simulation.

// When instr_mem lived inside the design, synthesis saw an
// instruction memory full of zeros. Every fetched instruction 
// was a constant 0, so Yosys removed the decoder, ALU, multiplier,
// divider, register file and data memory as dead logic.

// V2: additional fixes
// 1. AUIPC: Fixed the ALU input so AUIPC uses the current PC. 
//    The old logic was accidentally treating it like JAL.

// 2. Predictor aliasing: Fixed target-address checking. A prediction is 
//    now considered wrong if the direction is wrong, the target address 
//    is wrong, or the predictor says "taken" for an instruction that isn't actually a branch.

// 3. Fixed register detection for immediate instructions. rs1/rs2 
//    are now set to x0 when an instruction doesn't actually use them,
//    so immediate bits can't be mistaken for registers.

// 4. EX/MEM forwarding returns PC+4 for JAL/JALR results.

`timescale 1ns/1ps

module riscv_core (
    input logic clk,
    input logic rst,

    // Instruction memory interface (icache refill path)
    output logic [31:0] imem_addr,
    input logic [31:0] imem_rdata,

    // Data memory interface
    output logic dmem_read,
    output logic dmem_write,
    output logic [2:0] dmem_funct3,
    output logic [31:0] dmem_addr,
    output logic [31:0] dmem_wdata,
    input logic [31:0] dmem_rdata,

    // Debug/ measurement outputs
    output logic [31:0] dbg_pc,
    output logic [31:0] dbg_instr,
    output logic [31:0] dbg_wb_data,
    output logic dbg_branch_resolved,
    output logic dbg_mispredict,
    output logic dbg_icache_hit,
    output logic dbg_icache_miss
);

    localparam logic [6:0] OP_LUI = 7'b0110111;
    localparam logic [6:0] OP_AUIPC = 7'b0010111;
    localparam logic [6:0] OP_JAL = 7'b1101111;
    localparam logic [6:0] OP_BRANCH = 7'b1100011;
    localparam logic [6:0] OP_STORE = 7'b0100011;
    localparam logic [6:0] OP_REG = 7'b0110011;

    // --- IF signals ------------------------------------------------
    logic [31:0] if_pc, if_pc_plus4, if_instr, next_pc;
    logic if_predict_taken;
    logic [31:0] if_predict_target;

    // --- ID signals ------------------------------------------------
    logic [31:0] id_pc, id_instr, id_predicted_target;
    logic id_predicted_taken;
    logic [6:0] id_opcode;
    logic id_uses_rs1, id_uses_rs2;
    logic [4:0] id_rs1_addr, id_rs2_addr;
    logic [31:0] id_rs1_data, id_rs2_data, id_opa, id_imm;
    logic id_reg_write, id_mem_read, id_mem_write;
    logic [2:0] id_mem_funct3;
    logic [1:0] id_wb_sel;
    logic id_alu_src, id_branch, id_jump, id_jalr;
    logic [4:0] id_alu_op;
    logic [2:0] id_imm_sel;

    // --- EX signals -----------------------------------------------
    logic [31:0] ex_pc, ex_pc_plus4, ex_rs1_data, ex_rs2_data, ex_imm;
    logic [4:0] ex_rs1_addr, ex_rs2_addr, ex_rd_addr;
    logic ex_reg_write, ex_mem_read, ex_mem_write;
    logic [2:0] ex_mem_funct3;
    logic [1:0] ex_wb_sel;
    logic ex_alu_src, ex_branch, ex_jump, ex_jalr;
    logic [4:0] ex_alu_op;
    logic ex_predicted_taken;
    logic [31:0] ex_predicted_target;
    logic [1:0] ex_forward_a, ex_forward_b;
    logic [31:0] ex_alu_operand_a, ex_fwd_rs2, ex_alu_operand_b, ex_alu_result;
    logic ex_alu_zero, ex_branch_taken;
    logic [31:0] ex_branch_target, ex_redirect_target, ex_jalr_target;
    logic ex_mispredict, ex_redirect;
    logic ex_cmp_eq, ex_cmp_lt, ex_cmp_ltu;
    logic ex_is_div, div_start, div_stall, div_idle, div_done;
    logic [31:0] div_result, ex_result;
    logic ex_mem_reg_write_in, ex_mem_mem_read_in, ex_mem_mem_write_in;

    // --- MEM signals ----------------------------------------------
    logic [31:0] mem_alu_result, mem_rs2_data, mem_pc_plus4, mem_fwd_value;
    logic [4:0] mem_rd_addr;
    logic mem_reg_write, mem_mem_read, mem_mem_write;
    logic [2:0] mem_mem_funct3;
    logic [1:0] mem_wb_sel;

    // --- WB signals -----------------------------------------------
    logic [31:0] wb_alu_result, wb_mem_data, wb_pc_plus4, wb_data;
    logic [4:0] wb_rd_addr;
    logic wb_reg_write;
    logic [1:0] wb_wb_sel;

    // --- Hazard / control -----------------------------------------
    logic hazard_stall_pc, hazard_stall_if_id, hazard_bubble;
    logic icache_stall, icache_flush;
    logic stall_pc, stall_if_id, bubble_id_ex, flush_if_id;

    // A divide in progress holds IF, ID and EX in place
    assign stall_pc = hazard_stall_pc | icache_stall | div_stall;
    assign stall_if_id = hazard_stall_if_id | icache_stall | div_stall;
    assign bubble_id_ex = hazard_bubble | icache_stall;
    assign flush_if_id = ex_redirect;


//                              STAGE 1- Instruction Fetch


    assign if_pc_plus4 = if_pc + 32'd4;

    // A redirect from EX should not be masked by a stall
    assign next_pc = ex_redirect ? ex_redirect_target : stall_pc ? if_pc :
                    if_predict_taken ? if_predict_target : if_pc_plus4;

    pc_reg u_pc (
        .clk (clk),
        .rst (rst),
        .pc_next (next_pc),
        .pc (if_pc)
    );

    // Leave an in-flight miss only when the PC really moves.
    assign icache_flush = ex_redirect && (ex_redirect_target != if_pc);

    icache u_icache (
        .clk (clk),
        .rst (rst),
        .addr (if_pc),
        .instr_out (if_instr),
        .stall (icache_stall),
        .flush (icache_flush),
        .mem_addr (imem_addr),
        .mem_rdata (imem_rdata),
        .hit_pulse (dbg_icache_hit),
        .miss_pulse (dbg_icache_miss)
    );

    branch_predictor #(.BHT_BITS(6)) u_bp (
        .clk (clk),
        .rst (rst),
        .predict_pc (if_pc),
        .predict_taken (if_predict_taken),
        .predict_target (if_predict_target),
        .update_valid (ex_branch),
        .update_pc (ex_pc),
        .update_taken (ex_branch_taken),
        .update_target (ex_branch_target)
    );

    if_id_reg u_if_id (
        .clk (clk),
        .rst (rst),
        .flush (flush_if_id),
        .stall (stall_if_id),
        .pc_in (if_pc),
        .instr_in (if_instr),
        .predicted_taken_in (if_predict_taken),
        .predicted_target_in (if_predict_target),
        .pc_out (id_pc),
        .instr_out (id_instr),
        .predicted_taken_out (id_predicted_taken),
        .predicted_target_out (id_predicted_target)
    );

    assign dbg_pc = if_pc;
    assign dbg_instr = if_instr;


//                              STAGE 2- Instruction Decode


    assign id_opcode = id_instr[6:0];

    // LUI, AUIPC and JAL have no rs1. Only R-type, branches and
    // stores have an rs2. In other formats those bit positions
    // hold immediate bits, so they are masked to x0, which the
    // forwarding and hazard units always ignore.
    assign id_uses_rs1 = (id_opcode != OP_LUI) && (id_opcode != OP_AUIPC) && (id_opcode != OP_JAL);
    assign id_uses_rs2 = (id_opcode == OP_REG) || (id_opcode == OP_BRANCH) || (id_opcode == OP_STORE);

    assign id_rs1_addr = id_uses_rs1 ? id_instr[19:15] : 5'd0;
    assign id_rs2_addr = id_uses_rs2 ? id_instr[24:20] : 5'd0;

    control_unit u_ctrl (
        .instr (id_instr),
        .alu_op (id_alu_op),
        .alu_src (id_alu_src),
        .reg_write (id_reg_write),
        .mem_read (id_mem_read),
        .mem_write (id_mem_write),
        .mem_funct3 (id_mem_funct3),
        .wb_sel (id_wb_sel),
        .imm_sel (id_imm_sel),
        .branch (id_branch),
        .jump (id_jump),
        .jalr (id_jalr)
    );

    imm_gen u_immgen (
        .instr (id_instr),
        .imm_sel (id_imm_sel),
        .imm_out (id_imm)
    );

    reg_file u_rf (
        .clk (clk),
        .rs1_addr (id_rs1_addr),
        .rs2_addr (id_rs2_addr),
        .rs1_data (id_rs1_data),
        .rs2_data (id_rs2_data),
        .rd_addr (wb_rd_addr),
        .rd_data (wb_data),
        .reg_write (wb_reg_write)
    );

    // AUIPC computes PC + imm: operand A is this instruction's PC.
    assign id_opa = (id_opcode == OP_AUIPC) ? id_pc : id_rs1_data;

    hazard_unit u_hazard (
        .id_ex_mem_read (ex_mem_read),
        .id_ex_rd (ex_rd_addr),
        .if_id_rs1 (id_rs1_addr),
        .if_id_rs2 (id_rs2_addr),
        .stall_if_id (hazard_stall_if_id),
        .stall_pc (hazard_stall_pc),
        .flush_id_ex (hazard_bubble)
    );

    id_ex_reg u_id_ex (
        .clk (clk),
        .rst (rst),
        .flush ((bubble_id_ex | ex_redirect) & ~div_stall),
        .stall (div_stall),
        .reg_write_in (id_reg_write), .reg_write_out (ex_reg_write),
        .mem_read_in (id_mem_read), .mem_read_out (ex_mem_read),
        .mem_write_in (id_mem_write), .mem_write_out (ex_mem_write),
        .mem_funct3_in (id_mem_funct3), .mem_funct3_out (ex_mem_funct3),
        .wb_sel_in (id_wb_sel), .wb_sel_out (ex_wb_sel),
        .alu_src_in (id_alu_src), .alu_src_out (ex_alu_src),
        .alu_op_in (id_alu_op), .alu_op_out (ex_alu_op),
        .branch_in (id_branch), .branch_out (ex_branch),
        .jump_in (id_jump), .jump_out (ex_jump),
        .jalr_in (id_jalr), .jalr_out (ex_jalr),
        .pc_in (id_pc), .pc_out (ex_pc),
        .rs1_data_in (id_opa), .rs1_data_out (ex_rs1_data),
        .rs2_data_in (id_rs2_data), .rs2_data_out (ex_rs2_data),
        .imm_in (id_imm), .imm_out (ex_imm),
        .rs1_addr_in (id_rs1_addr), .rs1_addr_out (ex_rs1_addr),
        .rs2_addr_in (id_rs2_addr), .rs2_addr_out (ex_rs2_addr),
        .rd_addr_in (id_instr[11:7]), .rd_addr_out (ex_rd_addr),
        .predicted_taken_in (id_predicted_taken),
        .predicted_taken_out (ex_predicted_taken),
        .predicted_target_in (id_predicted_target),
        .predicted_target_out (ex_predicted_target)
    );


//                              STAGE 3- Execute


    assign ex_pc_plus4 = ex_pc + 32'd4;

    forward_unit u_fwd (
        .ex_rs1_addr (ex_rs1_addr),
        .ex_rs2_addr (ex_rs2_addr),
        .ex_mem_reg_write (mem_reg_write),
        .ex_mem_rd (mem_rd_addr),
        .mem_wb_reg_write (wb_reg_write),
        .mem_wb_rd (wb_rd_addr),
        .forward_a (ex_forward_a),
        .forward_b (ex_forward_b)
    );

    // The value an instruction in MEM will eventually write back.
    // JAL/JALR write PC+4, not their ALU result.
    assign mem_fwd_value = (mem_wb_sel == 2'b10) ? mem_pc_plus4 : mem_alu_result;

    always_comb begin
        case (ex_forward_a)
            2'b10: ex_alu_operand_a = mem_fwd_value;
            2'b01: ex_alu_operand_a = wb_data;
            default: ex_alu_operand_a = ex_rs1_data;
        endcase
    end

    always_comb begin
        case (ex_forward_b)
            2'b10: ex_fwd_rs2 = mem_fwd_value;
            2'b01: ex_fwd_rs2 = wb_data;
            default: ex_fwd_rs2 = ex_rs2_data;
        endcase
    end

    assign ex_alu_operand_b = ex_alu_src ? ex_imm : ex_fwd_rs2;

    alu u_alu (
        .operand_a (ex_alu_operand_a),
        .operand_b (ex_alu_operand_b),
        .alu_op (ex_alu_op),
        .result (ex_alu_result),
        .zero (ex_alu_zero)
    );

    // Dedicated branch comparator: Branches compare rs1 and rs2
    // directly (after forwarding) instead of reading the ALU's
    // result, which would put the multiplier on the next-PC path.
    assign ex_cmp_eq  = (ex_alu_operand_a == ex_fwd_rs2);
    assign ex_cmp_lt  = ($signed(ex_alu_operand_a) < $signed(ex_fwd_rs2));
    assign ex_cmp_ltu = (ex_alu_operand_a < ex_fwd_rs2);

    // Real branch outcome
    always_comb begin
        ex_branch_taken = 1'b0;
        if (ex_branch) begin
            case (ex_mem_funct3)
                3'b000: ex_branch_taken = ex_cmp_eq;    // BEQ
                3'b001: ex_branch_taken = ~ex_cmp_eq;    // BNE
                3'b100: ex_branch_taken = ex_cmp_lt;    // BLT
                3'b101: ex_branch_taken = ~ex_cmp_lt;    // BGE
                3'b110: ex_branch_taken = ex_cmp_ltu;   // BLTU
                3'b111: ex_branch_taken = ~ex_cmp_ltu;   // BGEU
                default: ex_branch_taken = 1'b0;
            endcase
        end
    end

    // Dedicated JALR target adder (rs1 + imm, bit 0 cleared)
    assign ex_jalr_target = (ex_alu_operand_a + ex_imm) & ~32'd1;

    assign ex_branch_target = ex_pc + ex_imm;

    // A misprediction means the CPU fetched the instruction from the wrong place:
    //   branch: wrongly taken or not-taken decision, or wrong BTB target
    //   non-branch: predictor incorrectly said "taken"
    //   jump: always redirects, so no check needed
    assign ex_mispredict = ex_branch ? ((ex_predicted_taken != ex_branch_taken) ||
                    (ex_branch_taken && (ex_predicted_target != ex_branch_target))) : 
                    (ex_predicted_taken && !ex_jump);

    assign ex_redirect = ex_jump | ex_mispredict;

    assign ex_redirect_target = ex_jalr ? ex_jalr_target :
                            (ex_jump || ex_branch_taken) ? ex_branch_target : ex_pc_plus4;


    assign dbg_branch_resolved = ex_branch;
    assign dbg_mispredict      = ex_branch & ex_mispredict;
 
    // --- Multi-cycle divider --------------------------------------
    assign ex_is_div = (ex_alu_op == riscv_pkg::ALU_DIV)  ||
                       (ex_alu_op == riscv_pkg::ALU_DIVU) ||
                       (ex_alu_op == riscv_pkg::ALU_REM)  ||
                       (ex_alu_op == riscv_pkg::ALU_REMU);
 
    // Start as soon as a divide reaches EX. Operands are latched
    // inside the divider on that first cycle, because forwarding
    // sources move on while the pipeline is stalled.
    assign div_start = ex_is_div && div_idle;
    assign div_stall = ex_is_div && !div_done;
 
    divider u_div (
        .clk (clk),
        .rst (rst),
        .start (div_start),
        .is_signed ((ex_alu_op == riscv_pkg::ALU_DIV) || (ex_alu_op == riscv_pkg::ALU_REM)),
        .want_rem ((ex_alu_op == riscv_pkg::ALU_REM) || (ex_alu_op == riscv_pkg::ALU_REMU)),
        .dividend (ex_alu_operand_a),
        .divisor (ex_fwd_rs2),
        .idle (div_idle),
        .done (div_done),
        .result (div_result)
    );
 
    assign ex_result = ex_is_div ? div_result : ex_alu_result;
 
    // While the divide is running, EX/MEM receives bubbles so the
    // unfinished divide never writes back.
    assign ex_mem_reg_write_in = ex_reg_write & ~div_stall;
    assign ex_mem_mem_read_in  = ex_mem_read  & ~div_stall;
    assign ex_mem_mem_write_in = ex_mem_write & ~div_stall;


    ex_mem_reg u_ex_mem (
        .clk (clk),
        .rst (rst),
        .reg_write_in (ex_mem_reg_write_in), .reg_write_out (mem_reg_write),
        .mem_read_in (ex_mem_mem_read_in), .mem_read_out (mem_mem_read),
        .mem_write_in (ex_mem_mem_write_in), .mem_write_out (mem_mem_write),
        .mem_funct3_in (ex_mem_funct3), .mem_funct3_out (mem_mem_funct3),
        .wb_sel_in (ex_wb_sel), .wb_sel_out (mem_wb_sel),
        .alu_result_in (ex_result), .alu_result_out (mem_alu_result),
        .rs2_data_in (ex_fwd_rs2), .rs2_data_out (mem_rs2_data),
        .pc_plus4_in (ex_pc_plus4), .pc_plus4_out (mem_pc_plus4),
        .rd_addr_in (ex_rd_addr), .rd_addr_out (mem_rd_addr)
    );


//                              STAGE 4- Memory


    assign dmem_read = mem_mem_read;
    assign dmem_write = mem_mem_write;
    assign dmem_funct3 = mem_mem_funct3;
    assign dmem_addr = mem_alu_result;
    assign dmem_wdata = mem_rs2_data;

    mem_wb_reg u_mem_wb (
        .clk (clk),
        .rst (rst),
        .reg_write_in (mem_reg_write), .reg_write_out (wb_reg_write),
        .wb_sel_in (mem_wb_sel), .wb_sel_out (wb_wb_sel),
        .alu_result_in (mem_alu_result), .alu_result_out (wb_alu_result),
        .mem_data_in (dmem_rdata), .mem_data_out (wb_mem_data),
        .pc_plus4_in (mem_pc_plus4), .pc_plus4_out (wb_pc_plus4),
        .rd_addr_in (mem_rd_addr), .rd_addr_out (wb_rd_addr)
    );


//                              STAGE 5- WriteBack


    always_comb begin
        case (wb_wb_sel)
            2'b01: wb_data = wb_mem_data;
            2'b10: wb_data = wb_pc_plus4;
            default: wb_data = wb_alu_result;
        endcase
    end

    assign dbg_wb_data = wb_data;

endmodule
