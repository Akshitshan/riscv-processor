// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_branch_bench__Syms.h"


VL_ATTR_COLD void Vtb_branch_bench___024root__trace_init_sub__TOP__0(Vtb_branch_bench___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root__trace_init_sub__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("tb_branch_bench", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+125,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"rst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"dbg_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"dbg_instr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"dbg_wb_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+42,0,"dbg_branch_resolved",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"dbg_mispredict",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+37,0,"cycle_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+38,0,"branches_seen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->declBus(c+39,0,"mispredict_count",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("DUT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+125,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"dbg_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"dbg_instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+41,0,"dbg_wb_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+42,0,"dbg_branch_resolved",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"dbg_mispredict",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"if_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"if_pc_plus4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"if_instr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"id_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"id_instr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+128,0,"id_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+129,0,"id_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"id_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+48,0,"id_reg_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"id_mem_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"id_mem_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"id_mem_funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+52,0,"id_wb_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+53,0,"id_alu_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+54,0,"id_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"id_jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"id_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+57,0,"id_alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+58,0,"id_imm_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+59,0,"ex_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+60,0,"ex_rs1_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"ex_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"ex_imm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"ex_rs1_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+64,0,"ex_rs2_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+65,0,"ex_rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+66,0,"ex_reg_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"ex_mem_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"ex_mem_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"ex_mem_funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+70,0,"ex_wb_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+71,0,"ex_alu_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"ex_branch",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"ex_jump",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"ex_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"ex_alu_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+75,0,"ex_alu_operand_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"ex_alu_input_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+77,0,"ex_alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+78,0,"ex_alu_zero",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+79,0,"ex_pc_plus4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+80,0,"ex_branch_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+81,0,"ex_forward_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+82,0,"ex_forward_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+83,0,"ex_fwd_rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+84,0,"mem_alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"mem_rs2_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"mem_pc_plus4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"mem_rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+88,0,"mem_reg_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"mem_mem_read",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"mem_mem_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"mem_mem_funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+92,0,"mem_wb_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+122,0,"mem_read_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+93,0,"wb_alu_result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"wb_mem_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"wb_pc_plus4",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"wb_rd_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+97,0,"wb_reg_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"wb_wb_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+41,0,"wb_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+99,0,"stall_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"stall_if_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"flush_id_ex",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"flush_if_id",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+101,0,"if_predict_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+130,0,"if_predict_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+102,0,"id_predicted_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+103,0,"ex_predicted_taken",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"ex_branch_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+43,0,"ex_mispredict",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"ex_redirect",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+105,0,"ex_redirect_target",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"next_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+106,0,"final_alu_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("u_alu", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+106,0,"operand_a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"operand_b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+74,0,"alu_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+77,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+78,0,"zero",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+106,0,"signed_a",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+76,0,"signed_b",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+107,0,"mul_ss",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+109,0,"mul_uu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->declQuad(c+111,0,"mul_su",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 63,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_bp", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+134,0,"BHT_BITS",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+125,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"predict_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+101,0,"predict_taken",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+130,0,"predict_target",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+42,0,"update_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"update_pc",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+80,0,"update_taken",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+104,0,"update_target",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+113,0,"predict_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBus(c+114,0,"update_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_ctrl", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+46,0,"instr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+57,0,"alu_op",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+53,0,"alu_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"reg_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"mem_read",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"mem_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"mem_funct3",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+52,0,"wb_sel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+58,0,"imm_sel",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+54,0,"branch",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"jump",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"jalr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+115,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+116,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+117,0,"funct7",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+135,0,"OP_LUI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+136,0,"OP_AUIPC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+137,0,"OP_JAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+138,0,"OP_JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+139,0,"OP_BRANCH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+140,0,"OP_LOAD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+141,0,"OP_STORE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+142,0,"OP_IMM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+143,0,"OP_REG",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+144,0,"OP_SYSTEM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_dmem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+145,0,"MEM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+125,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"mem_read",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"mem_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+84,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"write_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"read_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+123,0,"byte_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+124,0,"half_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_ex_mem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+125,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"reg_write_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"mem_read_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"mem_write_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"mem_funct3_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+70,0,"wb_sel_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+77,0,"alu_result_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"rs2_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+79,0,"pc_plus4_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+65,0,"rd_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+88,0,"reg_write_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"mem_read_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"mem_write_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+91,0,"mem_funct3_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+92,0,"wb_sel_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+84,0,"alu_result_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"rs2_data_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"pc_plus4_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"rd_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_fwd", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+63,0,"ex_rs1_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+64,0,"ex_rs2_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+88,0,"ex_mem_reg_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+87,0,"ex_mem_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+97,0,"mem_wb_reg_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+96,0,"mem_wb_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+81,0,"forward_a",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+82,0,"forward_b",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_hazard", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+67,0,"id_ex_mem_read",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+65,0,"id_ex_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+118,0,"if_id_rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+119,0,"if_id_rs2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+99,0,"stall_if_id",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"stall_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"flush_id_ex",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"load_use_hazard",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_id_ex", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+125,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+120,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+48,0,"reg_write_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+49,0,"mem_read_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+50,0,"mem_write_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+51,0,"mem_funct3_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+52,0,"wb_sel_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+53,0,"alu_src_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+57,0,"alu_op_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+54,0,"branch_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"jump_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+56,0,"jalr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+45,0,"pc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+128,0,"rs1_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+129,0,"rs2_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+47,0,"imm_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+118,0,"rs1_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+119,0,"rs2_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+121,0,"rd_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+102,0,"predicted_taken_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+66,0,"reg_write_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"mem_read_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"mem_write_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+69,0,"mem_funct3_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+70,0,"wb_sel_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+71,0,"alu_src_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+74,0,"alu_op_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+42,0,"branch_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+72,0,"jump_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+73,0,"jalr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+59,0,"pc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+60,0,"rs1_data_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+61,0,"rs2_data_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+62,0,"imm_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+63,0,"rs1_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+64,0,"rs2_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+65,0,"rd_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+103,0,"predicted_taken_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_if_id", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+125,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+100,0,"flush",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+99,0,"stall",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+40,0,"pc_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"instr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+101,0,"predicted_taken_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+45,0,"pc_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"instr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+102,0,"predicted_taken_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+146,0,"NOP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_imem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+145,0,"MEM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_immgen", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+46,0,"instr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+58,0,"imm_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+47,0,"imm_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mem_wb", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+125,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"reg_write_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+92,0,"wb_sel_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+84,0,"alu_result_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+122,0,"mem_data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+86,0,"pc_plus4_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+87,0,"rd_addr_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+97,0,"reg_write_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+98,0,"wb_sel_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+93,0,"alu_result_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+94,0,"mem_data_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+95,0,"pc_plus4_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"rd_addr_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_pc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+125,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+126,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+131,0,"pc_next",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+40,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_rf", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+125,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+118,0,"rs1_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+128,0,"rs1_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+119,0,"rs2_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+129,0,"rs2_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+96,0,"rd_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+41,0,"rd_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+97,0,"reg_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("regs", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+5+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+4,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declDouble(c+132,0,"accuracy",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_branch_bench___024root__trace_init_top(Vtb_branch_bench___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root__trace_init_top\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_branch_bench___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_branch_bench___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_branch_bench___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_branch_bench___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_branch_bench___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_branch_bench___024root__trace_register(Vtb_branch_bench___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root__trace_register\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtb_branch_bench___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_branch_bench___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_branch_bench___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_branch_bench___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_branch_bench___024root__trace_const_0_sub_0(Vtb_branch_bench___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_branch_bench___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root__trace_const_0\n"); );
    // Init
    Vtb_branch_bench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_branch_bench___024root*>(voidSelf);
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_branch_bench___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_branch_bench___024root__trace_const_0_sub_0(Vtb_branch_bench___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root__trace_const_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+134,(6U),32);
    bufp->fullCData(oldp+135,(0x37U),7);
    bufp->fullCData(oldp+136,(0x17U),7);
    bufp->fullCData(oldp+137,(0x6fU),7);
    bufp->fullCData(oldp+138,(0x67U),7);
    bufp->fullCData(oldp+139,(0x63U),7);
    bufp->fullCData(oldp+140,(3U),7);
    bufp->fullCData(oldp+141,(0x23U),7);
    bufp->fullCData(oldp+142,(0x13U),7);
    bufp->fullCData(oldp+143,(0x33U),7);
    bufp->fullCData(oldp+144,(0x73U),7);
    bufp->fullIData(oldp+145,(0x400U),32);
    bufp->fullIData(oldp+146,(0x13U),32);
}

VL_ATTR_COLD void Vtb_branch_bench___024root__trace_full_0_sub_0(Vtb_branch_bench___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_branch_bench___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root__trace_full_0\n"); );
    // Init
    Vtb_branch_bench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_branch_bench___024root*>(voidSelf);
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_branch_bench___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_branch_bench___024root__trace_full_0_sub_0(Vtb_branch_bench___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root__trace_full_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__i),32);
    bufp->fullIData(oldp+2,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__i),32);
    bufp->fullIData(oldp+3,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__i),32);
    bufp->fullIData(oldp+4,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__i),32);
    bufp->fullIData(oldp+5,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0]),32);
    bufp->fullIData(oldp+6,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[1]),32);
    bufp->fullIData(oldp+7,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[2]),32);
    bufp->fullIData(oldp+8,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[3]),32);
    bufp->fullIData(oldp+9,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[4]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[5]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[6]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[7]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[8]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[9]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[10]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[11]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[12]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[13]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[14]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[15]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[16]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[17]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[18]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[19]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[20]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[21]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[22]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[23]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[24]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[25]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[26]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[27]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[28]),32);
    bufp->fullIData(oldp+34,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[29]),32);
    bufp->fullIData(oldp+35,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[30]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[31]),32);
    bufp->fullIData(oldp+37,(vlSelfRef.tb_branch_bench__DOT__cycle_count),32);
    bufp->fullIData(oldp+38,(vlSelfRef.tb_branch_bench__DOT__branches_seen),32);
    bufp->fullIData(oldp+39,(vlSelfRef.tb_branch_bench__DOT__mispredict_count),32);
    bufp->fullIData(oldp+40,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc),32);
    bufp->fullIData(oldp+41,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_data),32);
    bufp->fullBit(oldp+42,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch));
    bufp->fullBit(oldp+43,(vlSelfRef.tb_branch_bench__DOT__dbg_mispredict));
    bufp->fullIData(oldp+44,(((IData)(4U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc)),32);
    bufp->fullIData(oldp+45,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_pc),32);
    bufp->fullIData(oldp+46,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr),32);
    bufp->fullIData(oldp+47,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm),32);
    bufp->fullBit(oldp+48,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_reg_write));
    bufp->fullBit(oldp+49,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_mem_read));
    bufp->fullBit(oldp+50,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_mem_write));
    bufp->fullCData(oldp+51,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_mem_funct3),3);
    bufp->fullCData(oldp+52,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_wb_sel),2);
    bufp->fullBit(oldp+53,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_src));
    bufp->fullBit(oldp+54,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_branch));
    bufp->fullBit(oldp+55,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_jump));
    bufp->fullBit(oldp+56,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_jalr));
    bufp->fullCData(oldp+57,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_op),5);
    bufp->fullCData(oldp+58,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel),3);
    bufp->fullIData(oldp+59,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc),32);
    bufp->fullIData(oldp+60,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs1_data),32);
    bufp->fullIData(oldp+61,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs2_data),32);
    bufp->fullIData(oldp+62,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_imm),32);
    bufp->fullCData(oldp+63,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs1_addr),5);
    bufp->fullCData(oldp+64,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs2_addr),5);
    bufp->fullCData(oldp+65,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rd_addr),5);
    bufp->fullBit(oldp+66,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_reg_write));
    bufp->fullBit(oldp+67,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_read));
    bufp->fullBit(oldp+68,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_write));
    bufp->fullCData(oldp+69,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_funct3),3);
    bufp->fullCData(oldp+70,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_wb_sel),2);
    bufp->fullBit(oldp+71,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_src));
    bufp->fullBit(oldp+72,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_jump));
    bufp->fullBit(oldp+73,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_jalr));
    bufp->fullCData(oldp+74,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op),5);
    bufp->fullIData(oldp+75,(((2U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_forward_a))
                               ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result
                               : ((1U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_forward_a))
                                   ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_data
                                   : vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs1_data))),32);
    bufp->fullIData(oldp+76,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b),32);
    bufp->fullIData(oldp+77,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_result),32);
    bufp->fullBit(oldp+78,((0U == vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_result)));
    bufp->fullIData(oldp+79,(((IData)(4U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc)),32);
    bufp->fullBit(oldp+80,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_taken));
    bufp->fullCData(oldp+81,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_forward_a),2);
    bufp->fullCData(oldp+82,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_forward_b),2);
    bufp->fullIData(oldp+83,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_fwd_rs2),32);
    bufp->fullIData(oldp+84,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result),32);
    bufp->fullIData(oldp+85,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rs2_data),32);
    bufp->fullIData(oldp+86,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_pc_plus4),32);
    bufp->fullCData(oldp+87,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rd_addr),5);
    bufp->fullBit(oldp+88,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_reg_write));
    bufp->fullBit(oldp+89,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_read));
    bufp->fullBit(oldp+90,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_write));
    bufp->fullCData(oldp+91,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_funct3),3);
    bufp->fullCData(oldp+92,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_wb_sel),2);
    bufp->fullIData(oldp+93,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_alu_result),32);
    bufp->fullIData(oldp+94,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_mem_data),32);
    bufp->fullIData(oldp+95,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_pc_plus4),32);
    bufp->fullCData(oldp+96,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_rd_addr),5);
    bufp->fullBit(oldp+97,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_reg_write));
    bufp->fullCData(oldp+98,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_wb_sel),2);
    bufp->fullBit(oldp+99,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__stall_pc));
    bufp->fullBit(oldp+100,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__flush_if_id));
    bufp->fullBit(oldp+101,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_predict_taken));
    bufp->fullBit(oldp+102,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_predicted_taken));
    bufp->fullBit(oldp+103,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_predicted_taken));
    bufp->fullIData(oldp+104,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_target),32);
    bufp->fullIData(oldp+105,(((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_jalr)
                                ? (0xfffffffeU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_result)
                                : ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_jump)
                                    ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_target
                                    : ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_taken)
                                        ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_target
                                        : ((IData)(4U) 
                                           + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc))))),32);
    bufp->fullIData(oldp+106,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a),32);
    bufp->fullQData(oldp+107,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_alu__DOT__mul_ss),64);
    bufp->fullQData(oldp+109,(((QData)((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a)) 
                               * (QData)((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b)))),64);
    bufp->fullQData(oldp+111,(VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a), 
                                          VL_EXTENDS_QQ(64,33, (QData)((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b))))),64);
    bufp->fullCData(oldp+113,((0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc 
                                        >> 2U))),6);
    bufp->fullCData(oldp+114,((0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc 
                                        >> 2U))),6);
    bufp->fullCData(oldp+115,((0x7fU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)),7);
    bufp->fullCData(oldp+116,((7U & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                     >> 0xcU))),3);
    bufp->fullCData(oldp+117,((vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                               >> 0x19U)),7);
    bufp->fullCData(oldp+118,((0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                        >> 0xfU))),5);
    bufp->fullCData(oldp+119,((0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                        >> 0x14U))),5);
    bufp->fullBit(oldp+120,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush));
    bufp->fullCData(oldp+121,((0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                        >> 7U))),5);
    bufp->fullIData(oldp+122,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_read_data),32);
    bufp->fullCData(oldp+123,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__byte_val),8);
    bufp->fullSData(oldp+124,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__half_val),16);
    bufp->fullBit(oldp+125,(vlSelfRef.tb_branch_bench__DOT__clk));
    bufp->fullBit(oldp+126,(vlSelfRef.tb_branch_bench__DOT__rst));
    bufp->fullIData(oldp+127,((((vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__mem
                                 [(0xfffU & ((IData)(3U) 
                                             + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc))] 
                                 << 0x18U) | (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__mem
                                              [(0xfffU 
                                                & ((IData)(2U) 
                                                   + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc))] 
                                              << 0x10U)) 
                               | ((vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__mem
                                   [(0xfffU & ((IData)(1U) 
                                               + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc))] 
                                   << 8U) | vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__mem
                                  [(0xfffU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc)]))),32);
    bufp->fullIData(oldp+128,(((0U == (0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                >> 0xfU)))
                                ? 0U : (((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_reg_write) 
                                         & ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_rd_addr) 
                                            == (0x1fU 
                                                & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                   >> 0xfU))))
                                         ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_data
                                         : vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs
                                        [(0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                   >> 0xfU))]))),32);
    bufp->fullIData(oldp+129,(((0U == (0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                >> 0x14U)))
                                ? 0U : (((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_reg_write) 
                                         & ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_rd_addr) 
                                            == (0x1fU 
                                                & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                   >> 0x14U))))
                                         ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_data
                                         : vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs
                                        [(0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                   >> 0x14U))]))),32);
    bufp->fullIData(oldp+130,(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb
                              [(0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc 
                                         >> 2U))]),32);
    bufp->fullIData(oldp+131,(((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__stall_pc)
                                ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc
                                : ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__flush_if_id)
                                    ? ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_jalr)
                                        ? (0xfffffffeU 
                                           & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_result)
                                        : ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_jump)
                                            ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_target
                                            : ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_taken)
                                                ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_target
                                                : ((IData)(4U) 
                                                   + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc))))
                                    : ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_predict_taken)
                                        ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb
                                       [(0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc 
                                                  >> 2U))]
                                        : ((IData)(4U) 
                                           + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc))))),32);
    bufp->fullDouble(oldp+132,(vlSelfRef.tb_branch_bench__DOT__unnamedblk1__DOT__accuracy));
}
