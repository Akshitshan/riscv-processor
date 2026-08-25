// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_pipeline__Syms.h"


void Vtb_pipeline___024root__trace_chg_0_sub_0(Vtb_pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_pipeline___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root__trace_chg_0\n"); );
    // Init
    Vtb_pipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_pipeline___024root*>(voidSelf);
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_pipeline___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_pipeline___024root__trace_chg_0_sub_0(Vtb_pipeline___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root__trace_chg_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[1U])) {
        bufp->chgIData(oldp+0,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__i),32);
        bufp->chgIData(oldp+1,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__i),32);
        bufp->chgIData(oldp+2,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_imem__DOT__i),32);
        bufp->chgIData(oldp+3,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__i),32);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U] 
                     | vlSelfRef.__Vm_traceActivity
                     [3U]))) {
        bufp->chgIData(oldp+4,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[0]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[1]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[2]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[3]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[4]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[5]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[6]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[7]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[8]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[9]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[10]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[11]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[12]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[13]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[14]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[15]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[16]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[17]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[18]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[19]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[20]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[21]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[22]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[23]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[24]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[25]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[26]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[27]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[28]),32);
        bufp->chgIData(oldp+33,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[29]),32);
        bufp->chgIData(oldp+34,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[30]),32);
        bufp->chgIData(oldp+35,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[31]),32);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+36,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch));
        bufp->chgIData(oldp+37,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_pc),32);
        bufp->chgIData(oldp+38,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc),32);
        bufp->chgIData(oldp+39,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs1_data),32);
        bufp->chgIData(oldp+40,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs2_data),32);
        bufp->chgIData(oldp+41,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_imm),32);
        bufp->chgCData(oldp+42,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs1_addr),5);
        bufp->chgCData(oldp+43,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs2_addr),5);
        bufp->chgBit(oldp+44,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_read));
        bufp->chgCData(oldp+45,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_wb_sel),2);
        bufp->chgBit(oldp+46,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_src));
        bufp->chgBit(oldp+47,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_jump));
        bufp->chgBit(oldp+48,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_jalr));
        bufp->chgCData(oldp+49,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op),5);
        bufp->chgIData(oldp+50,(((IData)(4U) + vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc)),32);
        bufp->chgIData(oldp+51,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_pc_plus4),32);
        bufp->chgBit(oldp+52,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_read));
        bufp->chgCData(oldp+53,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_wb_sel),2);
        bufp->chgIData(oldp+54,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_alu_result),32);
        bufp->chgIData(oldp+55,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_mem_data),32);
        bufp->chgIData(oldp+56,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_pc_plus4),32);
        bufp->chgCData(oldp+57,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_wb_sel),2);
        bufp->chgBit(oldp+58,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_predicted_taken));
        bufp->chgBit(oldp+59,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_predicted_taken));
        bufp->chgIData(oldp+60,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_target),32);
        bufp->chgCData(oldp+61,((0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc 
                                          >> 2U))),6);
    }
    if (VL_UNLIKELY(vlSelfRef.__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+62,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc),32);
        bufp->chgIData(oldp+63,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_data),32);
        bufp->chgIData(oldp+64,(((IData)(4U) + vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc)),32);
        bufp->chgIData(oldp+65,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr),32);
        bufp->chgIData(oldp+66,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm),32);
        bufp->chgBit(oldp+67,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_reg_write));
        bufp->chgBit(oldp+68,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_mem_read));
        bufp->chgBit(oldp+69,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_mem_write));
        bufp->chgCData(oldp+70,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_mem_funct3),3);
        bufp->chgCData(oldp+71,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_wb_sel),2);
        bufp->chgBit(oldp+72,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_src));
        bufp->chgBit(oldp+73,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_branch));
        bufp->chgBit(oldp+74,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_jump));
        bufp->chgBit(oldp+75,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_jalr));
        bufp->chgCData(oldp+76,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_op),5);
        bufp->chgCData(oldp+77,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel),3);
        bufp->chgCData(oldp+78,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rd_addr),5);
        bufp->chgBit(oldp+79,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_reg_write));
        bufp->chgBit(oldp+80,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_write));
        bufp->chgCData(oldp+81,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_funct3),3);
        bufp->chgIData(oldp+82,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b),32);
        bufp->chgIData(oldp+83,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_result),32);
        bufp->chgBit(oldp+84,((0U == vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_result)));
        bufp->chgBit(oldp+85,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_taken));
        bufp->chgCData(oldp+86,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_forward_a),2);
        bufp->chgCData(oldp+87,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_forward_b),2);
        bufp->chgIData(oldp+88,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_fwd_rs2),32);
        bufp->chgIData(oldp+89,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result),32);
        bufp->chgIData(oldp+90,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rs2_data),32);
        bufp->chgCData(oldp+91,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rd_addr),5);
        bufp->chgBit(oldp+92,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_reg_write));
        bufp->chgBit(oldp+93,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_write));
        bufp->chgCData(oldp+94,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_funct3),3);
        bufp->chgIData(oldp+95,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_read_data),32);
        bufp->chgCData(oldp+96,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_rd_addr),5);
        bufp->chgBit(oldp+97,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_reg_write));
        bufp->chgBit(oldp+98,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__stall_pc));
        bufp->chgBit(oldp+99,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__flush_if_id));
        bufp->chgBit(oldp+100,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_predict_taken));
        bufp->chgIData(oldp+101,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a),32);
        bufp->chgQData(oldp+102,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_alu__DOT__mul_ss),64);
        bufp->chgQData(oldp+104,(((QData)((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a)) 
                                  * (QData)((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b)))),64);
        bufp->chgQData(oldp+106,(VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a), 
                                             VL_EXTENDS_QQ(64,33, (QData)((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b))))),64);
        bufp->chgCData(oldp+108,((0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc 
                                           >> 2U))),6);
        bufp->chgCData(oldp+109,((0x7fU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)),7);
        bufp->chgCData(oldp+110,((7U & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                        >> 0xcU))),3);
        bufp->chgCData(oldp+111,((vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                  >> 0x19U)),7);
        bufp->chgCData(oldp+112,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__byte_val),8);
        bufp->chgSData(oldp+113,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__half_val),16);
        bufp->chgCData(oldp+114,((0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                           >> 0xfU))),5);
        bufp->chgCData(oldp+115,((0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                           >> 0x14U))),5);
        bufp->chgBit(oldp+116,(vlSelfRef.tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush));
        bufp->chgCData(oldp+117,((0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                           >> 7U))),5);
    }
    bufp->chgBit(oldp+118,(vlSelfRef.tb_pipeline__DOT__clk));
    bufp->chgBit(oldp+119,(vlSelfRef.tb_pipeline__DOT__rst));
    bufp->chgIData(oldp+120,((((vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_imem__DOT__mem
                                [(0xfffU & ((IData)(3U) 
                                            + vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc))] 
                                << 0x18U) | (vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_imem__DOT__mem
                                             [(0xfffU 
                                               & ((IData)(2U) 
                                                  + vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc))] 
                                             << 0x10U)) 
                              | ((vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_imem__DOT__mem
                                  [(0xfffU & ((IData)(1U) 
                                              + vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc))] 
                                  << 8U) | vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_imem__DOT__mem
                                 [(0xfffU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc)]))),32);
    bufp->chgIData(oldp+121,(vlSelfRef.tb_pipeline__DOT__pass_count),32);
    bufp->chgIData(oldp+122,(vlSelfRef.tb_pipeline__DOT__fail_count),32);
    bufp->chgBit(oldp+123,(((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch) 
                            & ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_predicted_taken) 
                               != (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_taken)))));
    bufp->chgIData(oldp+124,(((0U == (0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                               >> 0xfU)))
                               ? 0U : (((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_reg_write) 
                                        & ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_rd_addr) 
                                           == (0x1fU 
                                               & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                                  >> 0xfU))))
                                        ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_data
                                        : vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
                                       [(0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                                  >> 0xfU))]))),32);
    bufp->chgIData(oldp+125,(((0U == (0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                               >> 0x14U)))
                               ? 0U : (((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_reg_write) 
                                        & ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_rd_addr) 
                                           == (0x1fU 
                                               & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                                  >> 0x14U))))
                                        ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_data
                                        : vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
                                       [(0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                                  >> 0x14U))]))),32);
    bufp->chgIData(oldp+126,(((2U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_forward_a))
                               ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result
                               : ((1U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_forward_a))
                                   ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_data
                                   : vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs1_data))),32);
    bufp->chgIData(oldp+127,(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb
                             [(0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc 
                                        >> 2U))]),32);
    bufp->chgIData(oldp+128,(((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_jalr)
                               ? (0xfffffffeU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_result)
                               : ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_jump)
                                   ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_target
                                   : ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_taken)
                                       ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_target
                                       : ((IData)(4U) 
                                          + vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc))))),32);
    bufp->chgIData(oldp+129,(((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__stall_pc)
                               ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc
                               : ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__flush_if_id)
                                   ? ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_jalr)
                                       ? (0xfffffffeU 
                                          & vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_result)
                                       : ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_jump)
                                           ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_target
                                           : ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_taken)
                                               ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_target
                                               : ((IData)(4U) 
                                                  + vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc))))
                                   : ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_predict_taken)
                                       ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb
                                      [(0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc 
                                                 >> 2U))]
                                       : ((IData)(4U) 
                                          + vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc))))),32);
}

void Vtb_pipeline___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root__trace_cleanup\n"); );
    // Init
    Vtb_pipeline___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_pipeline___024root*>(voidSelf);
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
