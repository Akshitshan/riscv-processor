// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_pipeline.h for the primary calling header

#include "Vtb_pipeline__pch.h"
#include "Vtb_pipeline___024root.h"

VL_ATTR_COLD void Vtb_pipeline___024root___eval_static__TOP(Vtb_pipeline___024root* vlSelf);

VL_ATTR_COLD void Vtb_pipeline___024root___eval_static(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_static\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_pipeline___024root___eval_static__TOP(vlSelf);
}

VL_ATTR_COLD void Vtb_pipeline___024root___eval_static__TOP(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_static__TOP\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_pipeline__DOT__pass_count = 0U;
    vlSelfRef.tb_pipeline__DOT__fail_count = 0U;
}

VL_ATTR_COLD void Vtb_pipeline___024root___eval_final(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_final\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_pipeline___024root___dump_triggers__stl(Vtb_pipeline___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_pipeline___024root___eval_phase__stl(Vtb_pipeline___024root* vlSelf);

VL_ATTR_COLD void Vtb_pipeline___024root___eval_settle(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_settle\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_pipeline___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("../tb/tb_pipeline.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_pipeline___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_pipeline___024root___dump_triggers__stl(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___dump_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_pipeline___024root___stl_sequent__TOP__0(Vtb_pipeline___024root* vlSelf);
VL_ATTR_COLD void Vtb_pipeline___024root____Vm_traceActivitySetAll(Vtb_pipeline___024root* vlSelf);

VL_ATTR_COLD void Vtb_pipeline___024root___eval_stl(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vtb_pipeline___024root___stl_sequent__TOP__0(vlSelf);
        Vtb_pipeline___024root____Vm_traceActivitySetAll(vlSelf);
    }
}

VL_ATTR_COLD void Vtb_pipeline___024root___stl_sequent__TOP__0(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___stl_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2;
    tb_pipeline__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2 = 0;
    // Body
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_src = 0U;
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_reg_write = 0U;
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_mem_read = 0U;
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_mem_write = 0U;
    if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                  >> 6U)))) {
        if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                      >> 5U)))) {
            if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_mem_read = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
            if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_mem_write = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_mem_funct3 = 2U;
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_wb_sel = 0U;
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_branch = 0U;
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_jump = 0U;
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_jalr = 0U;
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel = 5U;
    tb_pipeline__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2 
        = (IData)((0x2000033U == (0xfe00007fU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_read_data = 0U;
    if (vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_read) {
        if ((0U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_funct3))) {
            vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__byte_val 
                = vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem
                [(0xfffU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result)];
            vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_read_data 
                = (((- (IData)((1U & ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__byte_val) 
                                      >> 7U)))) << 8U) 
                   | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__byte_val));
        } else if ((1U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_funct3))) {
            vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__half_val 
                = ((vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem
                    [(0xfffU & ((IData)(1U) + vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result))] 
                    << 8U) | vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem
                   [(0xfffU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result)]);
            vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_read_data 
                = (((- (IData)((1U & ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__half_val) 
                                      >> 0xfU)))) << 0x10U) 
                   | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__half_val));
        } else if ((2U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_funct3))) {
            vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_read_data 
                = (((vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem
                     [(0xfffU & ((IData)(3U) + vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result))] 
                     << 0x18U) | (vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem
                                  [(0xfffU & ((IData)(2U) 
                                              + vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result))] 
                                  << 0x10U)) | ((vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem
                                                 [(0xfffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result))] 
                                                 << 8U) 
                                                | vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem
                                                [(0xfffU 
                                                  & vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result)]));
        } else if ((4U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_funct3))) {
            vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_read_data 
                = vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem
                [(0xfffU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result)];
        } else if ((5U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_funct3))) {
            vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_read_data 
                = ((vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem
                    [(0xfffU & ((IData)(1U) + vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result))] 
                    << 8U) | vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem
                   [(0xfffU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result)]);
        }
    }
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_target 
        = (vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_imm 
           + vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc);
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_predict_taken 
        = (vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__valid
           [(0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc 
                      >> 2U))] & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht
                                  [(0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc 
                                             >> 2U))] 
                                  >> 1U));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__stall_pc 
        = ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_read) 
           & ((0U != (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rd_addr)) 
              & (((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rd_addr) 
                  == (0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                               >> 0xfU))) | ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rd_addr) 
                                             == (0x1fU 
                                                 & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                                    >> 0x14U))))));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_forward_a = 0U;
    if ((((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_reg_write) 
          & (0U != (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rd_addr))) 
         & ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rd_addr) 
            == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs1_addr)))) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_forward_a = 2U;
    } else if ((((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_reg_write) 
                 & (0U != (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_rd_addr))) 
                & ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_rd_addr) 
                   == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs1_addr)))) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_forward_a = 1U;
    }
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_forward_b = 0U;
    if ((((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_reg_write) 
          & (0U != (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rd_addr))) 
         & ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rd_addr) 
            == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs2_addr)))) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_forward_b = 2U;
    } else if ((((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_reg_write) 
                 & (0U != (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_rd_addr))) 
                & ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_rd_addr) 
                   == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs2_addr)))) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_forward_b = 1U;
    }
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_data = 
        ((0U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_wb_sel))
          ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_alu_result
          : ((1U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_wb_sel))
              ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_mem_data
              : ((2U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_wb_sel))
                  ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_pc_plus4
                  : vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_alu_result)));
    if ((0x40U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
        if ((0x20U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
            if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                    if ((4U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_src = 1U;
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_reg_write = 1U;
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_wb_sel = 2U;
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_jump = 1U;
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel = 4U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                    if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_src = 1U;
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_reg_write = 1U;
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_wb_sel = 2U;
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_jump = 1U;
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel = 0U;
                        }
                    }
                } else if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                    if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_src = 0U;
                        vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel = 2U;
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_mem_funct3 
                                    = (7U & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                             >> 0xcU));
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_branch = 1U;
                            }
                        }
                    }
                    if ((4U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_jalr = 1U;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
            if ((0x10U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_src = 1U;
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_reg_write = 1U;
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel = 3U;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_src = 0U;
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_reg_write = 1U;
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel = 5U;
                        }
                    }
                }
            } else if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                 >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_src = 1U;
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel = 1U;
                        }
                    }
                }
            }
            if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_mem_funct3 
                                    = (7U & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                             >> 0xcU));
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_src = 1U;
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_reg_write = 1U;
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel = 3U;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_src = 1U;
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_reg_write = 1U;
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel = 0U;
                        }
                    }
                }
            } else if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                 >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_src = 1U;
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_reg_write = 1U;
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel = 0U;
                        }
                    }
                }
            }
            if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_mem_funct3 
                                    = (7U & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                             >> 0xcU));
                            }
                        }
                    }
                }
            }
        }
        if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                      >> 5U)))) {
            if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_wb_sel = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm = 
        ((4U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel))
          ? ((2U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel))
              ? 0U : ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel))
                       ? 0U : ((((- (IData)((vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                             >> 0x1fU))) 
                                 << 0x15U) | (0x100000U 
                                              & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                                 >> 0xbU))) 
                               | (((0xff000U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr) 
                                   | (0x800U & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                                >> 9U))) 
                                  | (0x7feU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                               >> 0x14U))))))
          : ((2U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel))
              ? ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel))
                  ? (0xfffff000U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)
                  : (((- (IData)((vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                  >> 0x1fU))) << 0xdU) 
                     | (((0x1000U & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                     >> 0x13U)) | (0x800U 
                                                   & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                                      << 4U))) 
                        | ((0x7e0U & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                      >> 0x14U)) | 
                           (0x1eU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                     >> 7U)))))) : 
             ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm_sel))
               ? (((- (IData)((vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                               >> 0x1fU))) << 0xcU) 
                  | ((0xfe0U & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                >> 0x14U)) | (0x1fU 
                                              & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                                 >> 7U))))
               : (((- (IData)((vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                               >> 0x1fU))) << 0xcU) 
                  | (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                     >> 0x14U)))));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_op = 0U;
    if ((0x40U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
        if ((0x20U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
            if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                    if ((4U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_op = 0U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                    if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_op = 0U;
                        }
                    }
                }
            }
        }
    } else if ((0x20U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
        if ((0x10U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
            if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                    if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                            vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_op = 0xaU;
                        }
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                             >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                    if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_op = 0U;
                    }
                }
            }
        }
    } else if ((0x10U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
        if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                      >> 3U)))) {
            if ((4U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                    if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                        vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_op = 0U;
                    }
                }
            }
        }
    } else if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                         >> 3U)))) {
        if ((1U & (~ (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                      >> 2U)))) {
            if ((2U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                if ((1U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) {
                    vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_op = 0U;
                }
            }
        }
    }
    if (((0x13U == (0x7fU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) 
         | ((0x33U == (0x7fU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)) 
            | (0x63U == (0x7fU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr))))) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_op 
            = ((0x4000U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)
                ? ((0x2000U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)
                    ? ((0x1000U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)
                        ? ((0x63U == (0x7fU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr))
                            ? 9U : ((IData)(tb_pipeline__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                                     ? 0x12U : 2U))
                        : ((0x63U == (0x7fU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr))
                            ? 9U : ((IData)(tb_pipeline__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                                     ? 0x11U : 3U)))
                    : ((0x1000U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)
                        ? ((0x63U == (0x7fU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr))
                            ? 8U : ((0x40000000U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)
                                     ? 7U : ((IData)(tb_pipeline__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                                              ? 0x10U
                                              : 6U)))
                        : ((0x63U == (0x7fU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr))
                            ? 8U : ((IData)(tb_pipeline__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                                     ? 0xfU : 4U))))
                : ((0x2000U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)
                    ? ((0x1000U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)
                        ? ((IData)(tb_pipeline__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                            ? 0xeU : 9U) : ((IData)(tb_pipeline__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                                             ? 0xdU
                                             : 8U))
                    : ((0x1000U & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)
                        ? ((0x63U == (0x7fU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr))
                            ? 1U : ((IData)(tb_pipeline__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                                     ? 0xcU : 5U)) : 
                       ((0x63U == (0x7fU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr))
                         ? 1U : ((IData)(tb_pipeline__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                                  ? 0xbU : ((IData)(
                                                    (0x40000033U 
                                                     == 
                                                     (0x4000007fU 
                                                      & vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr)))
                                             ? 1U : 0U))))));
    }
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a 
        = ((0xaU == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
            ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs1_data
            : (((~ (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_jalr)) 
                & (2U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_wb_sel)))
                ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc
                : ((2U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_forward_a))
                    ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result
                    : ((1U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_forward_a))
                        ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_data
                        : vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs1_data))));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_fwd_rs2 
        = ((2U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_forward_b))
            ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result
            : ((1U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_forward_b))
                ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_data
                : vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs2_data));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b 
        = ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_src)
            ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_imm
            : vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_fwd_rs2);
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_alu__DOT__mul_ss 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a), 
                      VL_EXTENDS_QI(64,32, vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_result 
        = ((0x10U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
            ? ((8U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                ? 0U : ((4U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                         ? 0U : ((2U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                                  ? ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                                      ? 0U : ((0U == vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b)
                                               ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a
                                               : VL_MODDIV_III(32, vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a, vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b)))
                                  : ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                                      ? ((0U == vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b)
                                          ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a
                                          : VL_MODDIVS_III(32, vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a, vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b))
                                      : ((0U == vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b)
                                          ? 0xffffffffU
                                          : VL_DIV_III(32, vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a, vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b))))))
            : ((8U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                ? ((4U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                    ? ((2U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                        ? ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                            ? ((0U == vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b)
                                ? 0xffffffffU : VL_DIVS_III(32, vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a, vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b))
                            : (IData)((((QData)((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a)) 
                                        * (QData)((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b))) 
                                       >> 0x20U))) : 
                       ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                         ? (IData)((VL_MULS_QQQ(64, 
                                                VL_EXTENDS_QI(64,32, vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a), 
                                                VL_EXTENDS_QQ(64,33, (QData)((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b)))) 
                                    >> 0x20U)) : (IData)(
                                                         (vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_alu__DOT__mul_ss 
                                                          >> 0x20U))))
                    : ((2U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                        ? ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                            ? (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_alu__DOT__mul_ss)
                            : vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b)
                        : ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                            ? ((vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a 
                                < vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b)
                                ? 1U : 0U) : (VL_LTS_III(32, vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a, vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b)
                                               ? 1U
                                               : 0U))))
                : ((4U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                    ? ((2U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                        ? ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                            ? VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a, 
                                             (0x1fU 
                                              & vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b))
                            : (vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a 
                               >> (0x1fU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b)))
                        : ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                            ? (vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a 
                               << (0x1fU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b))
                            : (vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a 
                               ^ vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b)))
                    : ((2U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                        ? ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                            ? (vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a 
                               | vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b)
                            : (vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a 
                               & vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b))
                        : ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op))
                            ? (vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a 
                               - vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b)
                            : (vlSelfRef.tb_pipeline__DOT__DUT__DOT__final_alu_a 
                               + vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_input_b))))));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_taken = 0U;
    if (vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_taken 
            = (1U & ((4U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_funct3))
                      ? ((2U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_funct3))
                          ? ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_funct3))
                              ? (~ vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_result)
                              : vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_result)
                          : ((1U & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_funct3))
                              ? (~ vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_result)
                              : vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_result))
                      : ((1U & (~ ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_funct3) 
                                   >> 1U))) && ((1U 
                                                 & (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_funct3))
                                                 ? 
                                                (0U 
                                                 != vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_result)
                                                 : 
                                                (0U 
                                                 == vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_result)))));
    }
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__flush_if_id 
        = ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_jump) 
           | ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch) 
              & ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_predicted_taken) 
                 != (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_taken))));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush 
        = ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__stall_pc) 
           | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__flush_if_id));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__next_pc = 
        ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__stall_pc)
          ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc
          : ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__flush_if_id)
              ? ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_jalr)
                  ? (0xfffffffeU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_result)
                  : ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_jump)
                      ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_target
                      : ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_taken)
                          ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_target
                          : ((IData)(4U) + vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc))))
              : ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_predict_taken)
                  ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb
                 [(0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc 
                            >> 2U))] : ((IData)(4U) 
                                        + vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc))));
}

VL_ATTR_COLD void Vtb_pipeline___024root___eval_triggers__stl(Vtb_pipeline___024root* vlSelf);

VL_ATTR_COLD bool Vtb_pipeline___024root___eval_phase__stl(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_phase__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_pipeline___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_pipeline___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_pipeline___024root___dump_triggers__act(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___dump_triggers__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_pipeline.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_pipeline.rst)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_pipeline___024root___dump_triggers__nba(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___dump_triggers__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_pipeline.clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_pipeline.rst)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_pipeline___024root____Vm_traceActivitySetAll(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root____Vm_traceActivitySetAll\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vm_traceActivity[0U] = 1U;
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    vlSelfRef.__Vm_traceActivity[2U] = 1U;
    vlSelfRef.__Vm_traceActivity[3U] = 1U;
    vlSelfRef.__Vm_traceActivity[4U] = 1U;
}

VL_ATTR_COLD void Vtb_pipeline___024root___ctor_var_reset(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___ctor_var_reset\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->tb_pipeline__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__pass_count = 0;
    vlSelf->tb_pipeline__DOT__fail_count = 0;
    vlSelf->tb_pipeline__DOT__DUT__DOT__if_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_instr = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_imm = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_reg_write = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_mem_read = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_mem_write = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_mem_funct3 = VL_RAND_RESET_I(3);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_wb_sel = VL_RAND_RESET_I(2);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_alu_src = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_branch = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_jump = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_jalr = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_alu_op = VL_RAND_RESET_I(5);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_imm_sel = VL_RAND_RESET_I(3);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_rs1_data = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_rs2_data = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_imm = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_rs1_addr = VL_RAND_RESET_I(5);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_rs2_addr = VL_RAND_RESET_I(5);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_rd_addr = VL_RAND_RESET_I(5);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_reg_write = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_mem_read = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_mem_write = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_mem_funct3 = VL_RAND_RESET_I(3);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_wb_sel = VL_RAND_RESET_I(2);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_alu_src = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_branch = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_jump = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_jalr = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_alu_op = VL_RAND_RESET_I(5);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_alu_input_b = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_alu_result = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_branch_taken = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_forward_a = VL_RAND_RESET_I(2);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_forward_b = VL_RAND_RESET_I(2);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_fwd_rs2 = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__mem_alu_result = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__mem_rs2_data = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__mem_pc_plus4 = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__mem_rd_addr = VL_RAND_RESET_I(5);
    vlSelf->tb_pipeline__DOT__DUT__DOT__mem_reg_write = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__mem_mem_read = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__mem_mem_write = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__mem_mem_funct3 = VL_RAND_RESET_I(3);
    vlSelf->tb_pipeline__DOT__DUT__DOT__mem_wb_sel = VL_RAND_RESET_I(2);
    vlSelf->tb_pipeline__DOT__DUT__DOT__mem_read_data = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__wb_alu_result = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__wb_mem_data = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__wb_pc_plus4 = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__wb_rd_addr = VL_RAND_RESET_I(5);
    vlSelf->tb_pipeline__DOT__DUT__DOT__wb_reg_write = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__wb_wb_sel = VL_RAND_RESET_I(2);
    vlSelf->tb_pipeline__DOT__DUT__DOT__wb_data = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__stall_pc = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__flush_if_id = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__if_predict_taken = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__id_predicted_taken = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_predicted_taken = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__ex_branch_target = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__next_pc = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush = VL_RAND_RESET_I(1);
    vlSelf->tb_pipeline__DOT__DUT__DOT__final_alu_a = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_pipeline__DOT__DUT__DOT__u_imem__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_pipeline__DOT__DUT__DOT__u_imem__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht[__Vi0] = VL_RAND_RESET_I(2);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_pipeline__DOT__DUT__DOT__u_bp__DOT__valid[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->tb_pipeline__DOT__DUT__DOT__u_bp__DOT__i = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->tb_pipeline__DOT__DUT__DOT__u_rf__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__u_alu__DOT__mul_ss = VL_RAND_RESET_Q(64);
    for (int __Vi0 = 0; __Vi0 < 4096; ++__Vi0) {
        vlSelf->tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__byte_val = VL_RAND_RESET_I(8);
    vlSelf->tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__half_val = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigprevexpr___TOP__tb_pipeline__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_pipeline__DOT__rst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
