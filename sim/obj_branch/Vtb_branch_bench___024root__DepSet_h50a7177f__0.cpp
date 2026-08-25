// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_branch_bench.h for the primary calling header

#include "Vtb_branch_bench__pch.h"
#include "Vtb_branch_bench___024root.h"

VL_ATTR_COLD void Vtb_branch_bench___024root___eval_initial__TOP(Vtb_branch_bench___024root* vlSelf);
VlCoroutine Vtb_branch_bench___024root___eval_initial__TOP__Vtiming__0(Vtb_branch_bench___024root* vlSelf);
VlCoroutine Vtb_branch_bench___024root___eval_initial__TOP__Vtiming__1(Vtb_branch_bench___024root* vlSelf);
VlCoroutine Vtb_branch_bench___024root___eval_initial__TOP__Vtiming__2(Vtb_branch_bench___024root* vlSelf);

void Vtb_branch_bench___024root___eval_initial(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_branch_bench___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtb_branch_bench___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_branch_bench___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_branch_bench___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_branch_bench__DOT__clk__0 
        = vlSelfRef.tb_branch_bench__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_branch_bench__DOT__rst__0 
        = vlSelfRef.tb_branch_bench__DOT__rst;
}

VL_INLINE_OPT VlCoroutine Vtb_branch_bench___024root___eval_initial__TOP__Vtiming__0(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ tb_branch_bench__DOT__unnamedblk1_2__DOT____Vrepeat1;
    tb_branch_bench__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0;
    // Body
    VL_WRITEF_NX("\n========================================\n  Phase 5 \342\200\224 Branch Predictor Benchmark\n  Program: test_loop.s (20-iteration loop)\n========================================\n\n",0);
    vlSelfRef.tb_branch_bench__DOT__rst = 1U;
    co_await vlSelfRef.__VtrigSched_hd385a94f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_branch_bench.clk)", 
                                                         "../tb/tb_branch_bench.sv", 
                                                         62);
    co_await vlSelfRef.__VtrigSched_hd385a94f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_branch_bench.clk)", 
                                                         "../tb/tb_branch_bench.sv", 
                                                         62);
    co_await vlSelfRef.__VtrigSched_hd385a94f__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_branch_bench.clk)", 
                                                         "../tb/tb_branch_bench.sv", 
                                                         62);
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "../tb/tb_branch_bench.sv", 
                                         62);
    vlSelfRef.tb_branch_bench__DOT__rst = 0U;
    tb_branch_bench__DOT__unnamedblk1_2__DOT____Vrepeat1 = 0xc8U;
    while (VL_LTS_III(32, 0U, tb_branch_bench__DOT__unnamedblk1_2__DOT____Vrepeat1)) {
        co_await vlSelfRef.__VtrigSched_hd385a94f__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_branch_bench.clk)", 
                                                             "../tb/tb_branch_bench.sv", 
                                                             68);
        tb_branch_bench__DOT__unnamedblk1_2__DOT____Vrepeat1 
            = (tb_branch_bench__DOT__unnamedblk1_2__DOT____Vrepeat1 
               - (IData)(1U));
    }
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "../tb/tb_branch_bench.sv", 
                                         68);
    VL_WRITEF_NX("--- Correctness ---\n",0);
    if ((0x14U == vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs
         [1U])) {
        VL_WRITEF_NX("  PASS | x1 = %0# (loop counter reached 20)\n",0,
                     32,vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs
                     [1U]);
    } else {
        VL_WRITEF_NX("  FAIL | x1 = %0# (expected 20)\n",0,
                     32,vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs
                     [1U]);
    }
    if ((0x63U == vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs
         [3U])) {
        VL_WRITEF_NX("  PASS | x3 = %0# (reached end-of-loop marker)\n",0,
                     32,vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs
                     [3U]);
    } else {
        VL_WRITEF_NX("  FAIL | x3 = %0# (expected 99)\n",0,
                     32,vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs
                     [3U]);
    }
    VL_WRITEF_NX("\n--- Branch Predictor Performance ---\n  Total clock cycles         : %0d\n  Branches resolved           : %0d\n  Mispredictions               : %0d\n  Correct predictions          : %0d\n",0,
                 32,vlSelfRef.tb_branch_bench__DOT__cycle_count,
                 32,vlSelfRef.tb_branch_bench__DOT__branches_seen,
                 32,vlSelfRef.tb_branch_bench__DOT__mispredict_count,
                 32,(vlSelfRef.tb_branch_bench__DOT__branches_seen 
                     - vlSelfRef.tb_branch_bench__DOT__mispredict_count));
    if (VL_UNLIKELY(VL_LTS_III(32, 0U, vlSelfRef.tb_branch_bench__DOT__branches_seen))) {
        vlSelfRef.tb_branch_bench__DOT__unnamedblk1__DOT__accuracy 
            = ((100.0 * VL_ISTOR_D_I(32, (vlSelfRef.tb_branch_bench__DOT__branches_seen 
                                          - vlSelfRef.tb_branch_bench__DOT__mispredict_count))) 
               / VL_ISTOR_D_I(32, vlSelfRef.tb_branch_bench__DOT__branches_seen));
        VL_WRITEF_NX("  Prediction accuracy          : %0.1f%%\n",0,
                     64,vlSelfRef.tb_branch_bench__DOT__unnamedblk1__DOT__accuracy);
    }
    VL_WRITEF_NX("\n--- Estimated Impact ---\n  Cycles wasted to mispredictions this run : %0d\n  (Without prediction, ~%0d taken branches would ALL\n   cost 2 cycles each = ~%0d cycles wasted instead)\n\n========================================\n\n",0,
                 32,VL_MULS_III(32, (IData)(2U), vlSelfRef.tb_branch_bench__DOT__mispredict_count),
                 32,(vlSelfRef.tb_branch_bench__DOT__branches_seen 
                     - (IData)(1U)),32,VL_MULS_III(32, (IData)(2U), 
                                                   (vlSelfRef.tb_branch_bench__DOT__branches_seen 
                                                    - (IData)(1U))));
    VL_FINISH_MT("../tb/tb_branch_bench.sv", 107, "");
}

VL_INLINE_OPT VlCoroutine Vtb_branch_bench___024root___eval_initial__TOP__Vtiming__1(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x1dcd6500ULL, 
                                         nullptr, "../tb/tb_branch_bench.sv", 
                                         110);
    VL_WRITEF_NX("TIMEOUT\n",0);
    VL_FINISH_MT("../tb/tb_branch_bench.sv", 110, "");
}

VL_INLINE_OPT VlCoroutine Vtb_branch_bench___024root___eval_initial__TOP__Vtiming__2(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___eval_initial__TOP__Vtiming__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "../tb/tb_branch_bench.sv", 
                                             35);
        vlSelfRef.tb_branch_bench__DOT__clk = (1U & 
                                               (~ (IData)(vlSelfRef.tb_branch_bench__DOT__clk)));
    }
}

void Vtb_branch_bench___024root___eval_act(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtb_branch_bench___024root___nba_sequent__TOP__0(Vtb_branch_bench___024root* vlSelf);
void Vtb_branch_bench___024root___nba_sequent__TOP__1(Vtb_branch_bench___024root* vlSelf);
void Vtb_branch_bench___024root___nba_sequent__TOP__2(Vtb_branch_bench___024root* vlSelf);
void Vtb_branch_bench___024root___nba_comb__TOP__0(Vtb_branch_bench___024root* vlSelf);

void Vtb_branch_bench___024root___eval_nba(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_branch_bench___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_branch_bench___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_branch_bench___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_branch_bench___024root___nba_comb__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[5U] = 1U;
    }
}

VL_INLINE_OPT void Vtb_branch_bench___024root___nba_sequent__TOP__0(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*7:0*/ __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v0;
    __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v0;
    __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v0;
    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v1;
    __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v1 = 0;
    SData/*11:0*/ __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v1;
    __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v1;
    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v2;
    __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v2 = 0;
    SData/*11:0*/ __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v2;
    __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v3;
    __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v3 = 0;
    SData/*11:0*/ __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v3;
    __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v3;
    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v3 = 0;
    CData/*7:0*/ __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v4;
    __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v4 = 0;
    SData/*11:0*/ __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v4;
    __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v4 = 0;
    CData/*7:0*/ __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v5;
    __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v5 = 0;
    SData/*11:0*/ __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v5;
    __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v5 = 0;
    CData/*7:0*/ __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v6;
    __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v6 = 0;
    SData/*11:0*/ __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v6;
    __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v6 = 0;
    // Body
    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v0 = 0U;
    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v1 = 0U;
    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v3 = 0U;
    vlSelfRef.__VdlySet__tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs__v0 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_branch_bench__DOT__rst)))) {
        vlSelfRef.tb_branch_bench__DOT__cycle_count 
            = ((IData)(1U) + vlSelfRef.tb_branch_bench__DOT__cycle_count);
        if (vlSelfRef.tb_branch_bench__DOT__dbg_mispredict) {
            vlSelfRef.tb_branch_bench__DOT__mispredict_count 
                = ((IData)(1U) + vlSelfRef.tb_branch_bench__DOT__mispredict_count);
        }
        if (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch) {
            vlSelfRef.tb_branch_bench__DOT__branches_seen 
                = ((IData)(1U) + vlSelfRef.tb_branch_bench__DOT__branches_seen);
        }
    }
    if (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_write) {
        if ((0U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_funct3))) {
            __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v0 
                = (0xffU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rs2_data);
            __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v0 
                = (0xfffU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result);
            __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v0 = 1U;
        } else if ((1U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_funct3))) {
            __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v1 
                = (0xffU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rs2_data);
            __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v1 
                = (0xfffU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result);
            __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v1 = 1U;
            __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v2 
                = (0xffU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rs2_data 
                            >> 8U));
            __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v2 
                = (0xfffU & ((IData)(1U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result));
        } else if ((2U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_funct3))) {
            __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v3 
                = (0xffU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rs2_data);
            __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v3 
                = (0xfffU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result);
            __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v3 = 1U;
            __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v4 
                = (0xffU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rs2_data 
                            >> 8U));
            __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v4 
                = (0xfffU & ((IData)(1U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result));
            __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v5 
                = (0xffU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rs2_data 
                            >> 0x10U));
            __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v5 
                = (0xfffU & ((IData)(2U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result));
            __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v6 
                = (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rs2_data 
                   >> 0x18U);
            __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v6 
                = (0xfffU & ((IData)(3U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result));
        }
    }
    if (((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_reg_write) 
         & (0U != (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_rd_addr)))) {
        vlSelfRef.__VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs__v0 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_data;
        vlSelfRef.__VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs__v0 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_rd_addr;
        vlSelfRef.__VdlySet__tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs__v0 = 1U;
    }
    if (__VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v0) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem[__VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v0] 
            = __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v0;
    }
    if (__VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v1) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem[__VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v1] 
            = __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v1;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem[__VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v2] 
            = __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v2;
    }
    if (__VdlySet__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v3) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem[__VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v3] 
            = __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v3;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem[__VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v4] 
            = __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v4;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem[__VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v5] 
            = __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v5;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem[__VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v6] 
            = __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem__v6;
    }
}

VL_INLINE_OPT void Vtb_branch_bench___024root___nba_sequent__TOP__1(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___nba_sequent__TOP__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tb_branch_bench__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2;
    tb_branch_bench__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2 = 0;
    IData/*31:0*/ __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb__v0;
    __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb__v0 = 0;
    CData/*5:0*/ __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb__v0;
    __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb__v0;
    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb__v0 = 0;
    CData/*5:0*/ __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid__v0;
    __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid__v0;
    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid__v0 = 0;
    CData/*1:0*/ __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v0;
    __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v0 = 0;
    CData/*5:0*/ __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v0;
    __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v0;
    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v0 = 0;
    CData/*1:0*/ __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v1;
    __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v1 = 0;
    CData/*5:0*/ __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v1;
    __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v1;
    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v1 = 0;
    // Body
    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid__v0 = 0U;
    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb__v0 = 0U;
    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v0 = 0U;
    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v1 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_branch_bench__DOT__rst)))) {
        if (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch) {
            __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid__v0 
                = (0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc 
                            >> 2U));
            __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid__v0 = 1U;
            __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb__v0 
                = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_target;
            __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb__v0 
                = (0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc 
                            >> 2U));
            __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb__v0 = 1U;
            if (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_taken) {
                if ((3U != vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht
                     [(0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc 
                                >> 2U))])) {
                    __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v0 
                        = (3U & ((IData)(1U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht
                                 [(0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc 
                                            >> 2U))]));
                    __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v0 
                        = (0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc 
                                    >> 2U));
                    __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v0 = 1U;
                }
            } else if ((0U != vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht
                        [(0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc 
                                   >> 2U))])) {
                __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v1 
                    = (3U & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht
                             [(0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc 
                                        >> 2U))] - (IData)(1U)));
                __VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v1 
                    = (0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc 
                                >> 2U));
                __VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v1 = 1U;
            }
        }
    }
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_jump 
        = ((1U & (~ ((IData)(vlSelfRef.tb_branch_bench__DOT__rst) 
                     | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
           && (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_jump));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_read 
        = ((1U & (~ (IData)(vlSelfRef.tb_branch_bench__DOT__rst))) 
           && (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_read));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_predicted_taken 
        = ((1U & (~ ((IData)(vlSelfRef.tb_branch_bench__DOT__rst) 
                     | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
           && (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_predicted_taken));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_src 
        = ((1U & (~ ((IData)(vlSelfRef.tb_branch_bench__DOT__rst) 
                     | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
           && (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_src));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_jalr 
        = ((1U & (~ ((IData)(vlSelfRef.tb_branch_bench__DOT__rst) 
                     | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
           && (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_jalr));
    if (((IData)(vlSelfRef.tb_branch_bench__DOT__rst) 
         | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush))) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_imm = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs1_addr = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs2_addr = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs1_data = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs2_data = 0U;
    } else {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_imm 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_op;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs1_addr 
            = (0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                        >> 0xfU));
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs2_addr 
            = (0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                        >> 0x14U));
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs1_data 
            = ((0U == (0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                >> 0xfU))) ? 0U : (
                                                   ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_reg_write) 
                                                    & ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_rd_addr) 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                           >> 0xfU))))
                                                    ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_data
                                                    : 
                                                   vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs
                                                   [
                                                   (0x1fU 
                                                    & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                       >> 0xfU))]));
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs2_data 
            = ((0U == (0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                >> 0x14U))) ? 0U : 
               (((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_reg_write) 
                 & ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_rd_addr) 
                    == (0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                 >> 0x14U)))) ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_data
                 : vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs
                [(0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                           >> 0x14U))]));
    }
    if (vlSelfRef.tb_branch_bench__DOT__rst) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_mem_data = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_wb_sel = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_alu_result = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_pc_plus4 = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rs2_data = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_funct3 = 0U;
    } else {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_mem_data 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_read_data;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_wb_sel 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_wb_sel;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_alu_result 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_pc_plus4 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_pc_plus4;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rs2_data 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_fwd_rs2;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_funct3 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_funct3;
    }
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_funct3 
        = (((IData)(vlSelfRef.tb_branch_bench__DOT__rst) 
            | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush))
            ? 0U : (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_mem_funct3));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_wb_sel 
        = ((IData)(vlSelfRef.tb_branch_bench__DOT__rst)
            ? 0U : (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_wb_sel));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_wb_sel 
        = (((IData)(vlSelfRef.tb_branch_bench__DOT__rst) 
            | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush))
            ? 0U : (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_wb_sel));
    if (vlSelfRef.tb_branch_bench__DOT__rst) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_pc_plus4 = 0U;
    } else {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_result;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_pc_plus4 
            = ((IData)(4U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc);
    }
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc 
        = (((IData)(vlSelfRef.tb_branch_bench__DOT__rst) 
            | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush))
            ? 0U : vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_pc);
    if (vlSelfRef.tb_branch_bench__DOT__rst) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_rd_addr = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rd_addr = 0U;
    } else {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_rd_addr 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rd_addr;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rd_addr 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rd_addr;
    }
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rd_addr 
        = (((IData)(vlSelfRef.tb_branch_bench__DOT__rst) 
            | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush))
            ? 0U : (0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                             >> 7U)));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_write 
        = ((1U & (~ (IData)(vlSelfRef.tb_branch_bench__DOT__rst))) 
           && (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_write));
    if (__VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid__v0) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[__VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid__v0] = 1U;
    }
    if (__VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb__v0) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[__VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb__v0] 
            = __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb__v0;
    }
    if (__VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v0) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[__VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v0] 
            = __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v0;
    }
    if (__VdlySet__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v1) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[__VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v1] 
            = __VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht__v1;
    }
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch 
        = ((1U & (~ ((IData)(vlSelfRef.tb_branch_bench__DOT__rst) 
                     | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
           && (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_branch));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_read 
        = ((1U & (~ ((IData)(vlSelfRef.tb_branch_bench__DOT__rst) 
                     | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
           && (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_mem_read));
    if (((IData)(vlSelfRef.tb_branch_bench__DOT__rst) 
         | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__flush_if_id))) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_predicted_taken = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_pc = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr = 0x13U;
    } else if ((1U & (~ (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__stall_pc)))) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_predicted_taken 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_predict_taken;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_pc 
            = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
            = (((vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__mem
                 [(0xfffU & ((IData)(3U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc))] 
                 << 0x18U) | (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__mem
                              [(0xfffU & ((IData)(2U) 
                                          + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc))] 
                              << 0x10U)) | ((vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__mem
                                             [(0xfffU 
                                               & ((IData)(1U) 
                                                  + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc))] 
                                             << 8U) 
                                            | vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__mem
                                            [(0xfffU 
                                              & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc)]));
    }
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc 
        = ((IData)(vlSelfRef.tb_branch_bench__DOT__rst)
            ? 0U : vlSelfRef.tb_branch_bench__DOT__DUT__DOT__next_pc);
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_data 
        = ((0U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_wb_sel))
            ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_alu_result
            : ((1U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_wb_sel))
                ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_mem_data
                : ((2U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_wb_sel))
                    ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_pc_plus4
                    : vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_alu_result)));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_reg_write 
        = ((1U & (~ (IData)(vlSelfRef.tb_branch_bench__DOT__rst))) 
           && (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_reg_write));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_write 
        = ((1U & (~ ((IData)(vlSelfRef.tb_branch_bench__DOT__rst) 
                     | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
           && (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_mem_write));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_reg_write 
        = ((1U & (~ (IData)(vlSelfRef.tb_branch_bench__DOT__rst))) 
           && (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_reg_write));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_target 
        = (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_imm 
           + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc);
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_reg_write 
        = ((1U & (~ ((IData)(vlSelfRef.tb_branch_bench__DOT__rst) 
                     | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
           && (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_reg_write));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_forward_a = 0U;
    if ((((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_reg_write) 
          & (0U != (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rd_addr))) 
         & ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rd_addr) 
            == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs1_addr)))) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_forward_a = 2U;
    } else if ((((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_reg_write) 
                 & (0U != (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_rd_addr))) 
                & ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_rd_addr) 
                   == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs1_addr)))) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_forward_a = 1U;
    }
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_forward_b = 0U;
    if ((((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_reg_write) 
          & (0U != (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rd_addr))) 
         & ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_rd_addr) 
            == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs2_addr)))) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_forward_b = 2U;
    } else if ((((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_reg_write) 
                 & (0U != (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_rd_addr))) 
                & ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_rd_addr) 
                   == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs2_addr)))) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_forward_b = 1U;
    }
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a 
        = ((0xaU == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
            ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs1_data
            : (((~ (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_jalr)) 
                & (2U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_wb_sel)))
                ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc
                : ((2U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_forward_a))
                    ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result
                    : ((1U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_forward_a))
                        ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_data
                        : vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs1_data))));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_fwd_rs2 
        = ((2U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_forward_b))
            ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result
            : ((1U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_forward_b))
                ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__wb_data
                : vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rs2_data));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b 
        = ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_src)
            ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_imm
            : vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_fwd_rs2);
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_alu__DOT__mul_ss 
        = VL_MULS_QQQ(64, VL_EXTENDS_QI(64,32, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a), 
                      VL_EXTENDS_QI(64,32, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_result 
        = ((0x10U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
            ? ((8U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                ? 0U : ((4U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                         ? 0U : ((2U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                                  ? ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                                      ? 0U : ((0U == vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b)
                                               ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a
                                               : VL_MODDIV_III(32, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b)))
                                  : ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                                      ? ((0U == vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b)
                                          ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a
                                          : VL_MODDIVS_III(32, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b))
                                      : ((0U == vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b)
                                          ? 0xffffffffU
                                          : VL_DIV_III(32, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b))))))
            : ((8U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                ? ((4U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                    ? ((2U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                        ? ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                            ? ((0U == vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b)
                                ? 0xffffffffU : VL_DIVS_III(32, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b))
                            : (IData)((((QData)((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a)) 
                                        * (QData)((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b))) 
                                       >> 0x20U))) : 
                       ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                         ? (IData)((VL_MULS_QQQ(64, 
                                                VL_EXTENDS_QI(64,32, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a), 
                                                VL_EXTENDS_QQ(64,33, (QData)((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b)))) 
                                    >> 0x20U)) : (IData)(
                                                         (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_alu__DOT__mul_ss 
                                                          >> 0x20U))))
                    : ((2U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                        ? ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                            ? (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_alu__DOT__mul_ss)
                            : vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b)
                        : ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                            ? ((vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a 
                                < vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b)
                                ? 1U : 0U) : (VL_LTS_III(32, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b)
                                               ? 1U
                                               : 0U))))
                : ((4U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                    ? ((2U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                        ? ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                            ? VL_SHIFTRS_III(32,32,5, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a, 
                                             (0x1fU 
                                              & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b))
                            : (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a 
                               >> (0x1fU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b)))
                        : ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                            ? (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a 
                               << (0x1fU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b))
                            : (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a 
                               ^ vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b)))
                    : ((2U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                        ? ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                            ? (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a 
                               | vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b)
                            : (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a 
                               & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b))
                        : ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_op))
                            ? (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a 
                               - vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b)
                            : (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__final_alu_a 
                               + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_input_b))))));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_src = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_reg_write = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_mem_read = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_mem_write = 0U;
    if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                  >> 6U)))) {
        if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                      >> 5U)))) {
            if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_mem_read = 1U;
                            }
                        }
                    }
                }
            }
        }
        if ((0x20U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
            if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_mem_write = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_mem_funct3 = 2U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_wb_sel = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_branch = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_jump = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_jalr = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel = 5U;
    tb_branch_bench__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2 
        = (IData)((0x2000033U == (0xfe00007fU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__stall_pc 
        = ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_read) 
           & ((0U != (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rd_addr)) 
              & (((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rd_addr) 
                  == (0x1fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                               >> 0xfU))) | ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_rd_addr) 
                                             == (0x1fU 
                                                 & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                    >> 0x14U))))));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_taken = 0U;
    if (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_taken 
            = (1U & ((4U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_funct3))
                      ? ((2U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_funct3))
                          ? ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_funct3))
                              ? (~ vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_result)
                              : vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_result)
                          : ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_funct3))
                              ? (~ vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_result)
                              : vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_result))
                      : ((1U & (~ ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_funct3) 
                                   >> 1U))) && ((1U 
                                                 & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_mem_funct3))
                                                 ? 
                                                (0U 
                                                 != vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_result)
                                                 : 
                                                (0U 
                                                 == vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_result)))));
    }
    if ((0x40U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
        if ((0x20U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
            if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                    if ((4U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_src = 1U;
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_reg_write = 1U;
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_wb_sel = 2U;
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_jump = 1U;
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel = 4U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                    if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_src = 1U;
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_reg_write = 1U;
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_wb_sel = 2U;
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_jump = 1U;
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel = 0U;
                        }
                    }
                } else if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                    if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_src = 0U;
                        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel = 2U;
                    }
                }
                if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_mem_funct3 
                                    = (7U & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                             >> 0xcU));
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_branch = 1U;
                            }
                        }
                    }
                    if ((4U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_jalr = 1U;
                            }
                        }
                    }
                }
            }
        }
    } else {
        if ((0x20U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
            if ((0x10U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_src = 1U;
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_reg_write = 1U;
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel = 3U;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_src = 0U;
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_reg_write = 1U;
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel = 5U;
                        }
                    }
                }
            } else if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                 >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_src = 1U;
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel = 1U;
                        }
                    }
                }
            }
            if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_mem_funct3 
                                    = (7U & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                             >> 0xcU));
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((4U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_src = 1U;
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_reg_write = 1U;
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel = 3U;
                            }
                        }
                    } else if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_src = 1U;
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_reg_write = 1U;
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel = 0U;
                        }
                    }
                }
            } else if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                 >> 3U)))) {
                if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                              >> 2U)))) {
                    if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_src = 1U;
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_reg_write = 1U;
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel = 0U;
                        }
                    }
                }
            }
            if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_mem_funct3 
                                    = (7U & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                             >> 0xcU));
                            }
                        }
                    }
                }
            }
        }
        if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                      >> 5U)))) {
            if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                          >> 4U)))) {
                if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                  >> 2U)))) {
                        if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_wb_sel = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm 
        = ((4U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel))
            ? ((2U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel))
                ? 0U : ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel))
                         ? 0U : ((((- (IData)((vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                               >> 0x1fU))) 
                                   << 0x15U) | (0x100000U 
                                                & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                   >> 0xbU))) 
                                 | (((0xff000U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr) 
                                     | (0x800U & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                  >> 9U))) 
                                    | (0x7feU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                 >> 0x14U))))))
            : ((2U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel))
                ? ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel))
                    ? (0xfffff000U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)
                    : (((- (IData)((vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                    >> 0x1fU))) << 0xdU) 
                       | (((0x1000U & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                       >> 0x13U)) | 
                           (0x800U & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                      << 4U))) | ((0x7e0U 
                                                   & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                      >> 0x14U)) 
                                                  | (0x1eU 
                                                     & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                        >> 7U))))))
                : ((1U & (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_imm_sel))
                    ? (((- (IData)((vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                    >> 0x1fU))) << 0xcU) 
                       | ((0xfe0U & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                     >> 0x14U)) | (0x1fU 
                                                   & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                                      >> 7U))))
                    : (((- (IData)((vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                                    >> 0x1fU))) << 0xcU) 
                       | (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                          >> 0x14U)))));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_op = 0U;
    if ((0x40U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
        if ((0x20U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
            if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                          >> 4U)))) {
                if ((8U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                    if ((4U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                                vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_op = 0U;
                            }
                        }
                    }
                } else if ((4U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                    if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_op = 0U;
                        }
                    }
                }
            }
        }
    } else if ((0x20U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
        if ((0x10U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
            if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                          >> 3U)))) {
                if ((4U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                    if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_op = 0xaU;
                        }
                    }
                }
            }
        } else if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                             >> 3U)))) {
            if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                          >> 2U)))) {
                if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                    if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_op = 0U;
                    }
                }
            }
        }
    } else if ((0x10U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
        if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                      >> 3U)))) {
            if ((4U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                    if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_op = 0U;
                    }
                }
            }
        }
    } else if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                         >> 3U)))) {
        if ((1U & (~ (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr 
                      >> 2U)))) {
            if ((2U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                if ((1U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) {
                    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_op = 0U;
                }
            }
        }
    }
    if (((0x13U == (0x7fU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) 
         | ((0x33U == (0x7fU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)) 
            | (0x63U == (0x7fU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr))))) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_alu_op 
            = ((0x4000U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)
                ? ((0x2000U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)
                    ? ((0x1000U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)
                        ? ((0x63U == (0x7fU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr))
                            ? 9U : ((IData)(tb_branch_bench__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                                     ? 0x12U : 2U))
                        : ((0x63U == (0x7fU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr))
                            ? 9U : ((IData)(tb_branch_bench__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                                     ? 0x11U : 3U)))
                    : ((0x1000U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)
                        ? ((0x63U == (0x7fU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr))
                            ? 8U : ((0x40000000U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)
                                     ? 7U : ((IData)(tb_branch_bench__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                                              ? 0x10U
                                              : 6U)))
                        : ((0x63U == (0x7fU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr))
                            ? 8U : ((IData)(tb_branch_bench__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                                     ? 0xfU : 4U))))
                : ((0x2000U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)
                    ? ((0x1000U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)
                        ? ((IData)(tb_branch_bench__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                            ? 0xeU : 9U) : ((IData)(tb_branch_bench__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                                             ? 0xdU
                                             : 8U))
                    : ((0x1000U & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)
                        ? ((0x63U == (0x7fU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr))
                            ? 1U : ((IData)(tb_branch_bench__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                                     ? 0xcU : 5U)) : 
                       ((0x63U == (0x7fU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr))
                         ? 1U : ((IData)(tb_branch_bench__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2)
                                  ? 0xbU : ((IData)(
                                                    (0x40000033U 
                                                     == 
                                                     (0x4000007fU 
                                                      & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__id_instr)))
                                             ? 1U : 0U))))));
    }
    vlSelfRef.tb_branch_bench__DOT__dbg_mispredict 
        = ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch) 
           & ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_predicted_taken) 
              != (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_taken)));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_predict_taken 
        = (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid
           [(0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc 
                      >> 2U))] & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht
                                  [(0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc 
                                             >> 2U))] 
                                  >> 1U));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__flush_if_id 
        = ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_jump) 
           | (IData)(vlSelfRef.tb_branch_bench__DOT__dbg_mispredict));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT____Vcellinp__u_id_ex__flush 
        = ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__stall_pc) 
           | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__flush_if_id));
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__next_pc 
        = ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__stall_pc)
            ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc
            : ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__flush_if_id)
                ? ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_jalr)
                    ? (0xfffffffeU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_alu_result)
                    : ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_jump)
                        ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_target
                        : ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_taken)
                            ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_branch_target
                            : ((IData)(4U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__ex_pc))))
                : ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_predict_taken)
                    ? vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb
                   [(0x3fU & (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc 
                              >> 2U))] : ((IData)(4U) 
                                          + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__if_pc))));
}

VL_INLINE_OPT void Vtb_branch_bench___024root___nba_sequent__TOP__2(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___nba_sequent__TOP__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.__VdlySet__tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs__v0) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[vlSelfRef.__VdlyDim0__tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs__v0] 
            = vlSelfRef.__VdlyVal__tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs__v0;
    }
}

VL_INLINE_OPT void Vtb_branch_bench___024root___nba_comb__TOP__0(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___nba_comb__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_read_data = 0U;
    if (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_read) {
        if ((0U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_funct3))) {
            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__byte_val 
                = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem
                [(0xfffU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result)];
            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_read_data 
                = (((- (IData)((1U & ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__byte_val) 
                                      >> 7U)))) << 8U) 
                   | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__byte_val));
        } else if ((1U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_funct3))) {
            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__half_val 
                = ((vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem
                    [(0xfffU & ((IData)(1U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result))] 
                    << 8U) | vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem
                   [(0xfffU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result)]);
            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_read_data 
                = (((- (IData)((1U & ((IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__half_val) 
                                      >> 0xfU)))) << 0x10U) 
                   | (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__half_val));
        } else if ((2U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_funct3))) {
            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_read_data 
                = (((vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem
                     [(0xfffU & ((IData)(3U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result))] 
                     << 0x18U) | (vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem
                                  [(0xfffU & ((IData)(2U) 
                                              + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result))] 
                                  << 0x10U)) | ((vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem
                                                 [(0xfffU 
                                                   & ((IData)(1U) 
                                                      + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result))] 
                                                 << 8U) 
                                                | vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem
                                                [(0xfffU 
                                                  & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result)]));
        } else if ((4U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_funct3))) {
            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_read_data 
                = vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem
                [(0xfffU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result)];
        } else if ((5U == (IData)(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_mem_funct3))) {
            vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_read_data 
                = ((vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem
                    [(0xfffU & ((IData)(1U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result))] 
                    << 8U) | vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem
                   [(0xfffU & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__mem_alu_result)]);
        }
    }
}

void Vtb_branch_bench___024root___timing_resume(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___timing_resume\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_hd385a94f__0.resume(
                                                   "@(posedge tb_branch_bench.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_branch_bench___024root___timing_commit(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___timing_commit\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_hd385a94f__0.commit(
                                                   "@(posedge tb_branch_bench.clk)");
    }
}

void Vtb_branch_bench___024root___eval_triggers__act(Vtb_branch_bench___024root* vlSelf);

bool Vtb_branch_bench___024root___eval_phase__act(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_branch_bench___024root___eval_triggers__act(vlSelf);
    Vtb_branch_bench___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_branch_bench___024root___timing_resume(vlSelf);
        Vtb_branch_bench___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_branch_bench___024root___eval_phase__nba(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_branch_bench___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_branch_bench___024root___dump_triggers__nba(Vtb_branch_bench___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_branch_bench___024root___dump_triggers__act(Vtb_branch_bench___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_branch_bench___024root___eval(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_branch_bench___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../tb/tb_branch_bench.sv", 18, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_branch_bench___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../tb/tb_branch_bench.sv", 18, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_branch_bench___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_branch_bench___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_branch_bench___024root___eval_debug_assertions(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
