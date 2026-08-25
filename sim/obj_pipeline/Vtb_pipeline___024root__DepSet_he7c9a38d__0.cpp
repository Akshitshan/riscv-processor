// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_pipeline.h for the primary calling header

#include "Vtb_pipeline__pch.h"
#include "Vtb_pipeline___024root.h"

VL_ATTR_COLD void Vtb_pipeline___024root___eval_initial__TOP(Vtb_pipeline___024root* vlSelf);
VlCoroutine Vtb_pipeline___024root___eval_initial__TOP__Vtiming__0(Vtb_pipeline___024root* vlSelf);
VlCoroutine Vtb_pipeline___024root___eval_initial__TOP__Vtiming__1(Vtb_pipeline___024root* vlSelf);
VlCoroutine Vtb_pipeline___024root___eval_initial__TOP__Vtiming__2(Vtb_pipeline___024root* vlSelf);

void Vtb_pipeline___024root___eval_initial(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_initial\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_pipeline___024root___eval_initial__TOP(vlSelf);
    vlSelfRef.__Vm_traceActivity[1U] = 1U;
    Vtb_pipeline___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_pipeline___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_pipeline___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelfRef.__Vtrigprevexpr___TOP__tb_pipeline__DOT__clk__0 
        = vlSelfRef.tb_pipeline__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_pipeline__DOT__rst__0 
        = vlSelfRef.tb_pipeline__DOT__rst;
}

VL_INLINE_OPT VlCoroutine Vtb_pipeline___024root___eval_initial__TOP__Vtiming__0(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_initial__TOP__Vtiming__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__0__rn;
    __Vtask_tb_pipeline__DOT__check_reg__0__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__0__exp;
    __Vtask_tb_pipeline__DOT__check_reg__0__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__0__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__0__act;
    __Vtask_tb_pipeline__DOT__check_reg__0__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__1__rn;
    __Vtask_tb_pipeline__DOT__check_reg__1__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__1__exp;
    __Vtask_tb_pipeline__DOT__check_reg__1__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__1__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__1__act;
    __Vtask_tb_pipeline__DOT__check_reg__1__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__2__rn;
    __Vtask_tb_pipeline__DOT__check_reg__2__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__2__exp;
    __Vtask_tb_pipeline__DOT__check_reg__2__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__2__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__2__act;
    __Vtask_tb_pipeline__DOT__check_reg__2__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__3__rn;
    __Vtask_tb_pipeline__DOT__check_reg__3__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__3__exp;
    __Vtask_tb_pipeline__DOT__check_reg__3__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__3__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__3__act;
    __Vtask_tb_pipeline__DOT__check_reg__3__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__4__rn;
    __Vtask_tb_pipeline__DOT__check_reg__4__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__4__exp;
    __Vtask_tb_pipeline__DOT__check_reg__4__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__4__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__4__act;
    __Vtask_tb_pipeline__DOT__check_reg__4__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__5__rn;
    __Vtask_tb_pipeline__DOT__check_reg__5__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__5__exp;
    __Vtask_tb_pipeline__DOT__check_reg__5__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__5__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__5__act;
    __Vtask_tb_pipeline__DOT__check_reg__5__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__6__rn;
    __Vtask_tb_pipeline__DOT__check_reg__6__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__6__exp;
    __Vtask_tb_pipeline__DOT__check_reg__6__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__6__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__6__act;
    __Vtask_tb_pipeline__DOT__check_reg__6__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__7__rn;
    __Vtask_tb_pipeline__DOT__check_reg__7__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__7__exp;
    __Vtask_tb_pipeline__DOT__check_reg__7__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__7__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__7__act;
    __Vtask_tb_pipeline__DOT__check_reg__7__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__8__rn;
    __Vtask_tb_pipeline__DOT__check_reg__8__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__8__exp;
    __Vtask_tb_pipeline__DOT__check_reg__8__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__8__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__8__act;
    __Vtask_tb_pipeline__DOT__check_reg__8__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__9__rn;
    __Vtask_tb_pipeline__DOT__check_reg__9__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__9__exp;
    __Vtask_tb_pipeline__DOT__check_reg__9__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__9__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__9__act;
    __Vtask_tb_pipeline__DOT__check_reg__9__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__10__rn;
    __Vtask_tb_pipeline__DOT__check_reg__10__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__10__exp;
    __Vtask_tb_pipeline__DOT__check_reg__10__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__10__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__10__act;
    __Vtask_tb_pipeline__DOT__check_reg__10__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__11__rn;
    __Vtask_tb_pipeline__DOT__check_reg__11__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__11__exp;
    __Vtask_tb_pipeline__DOT__check_reg__11__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__11__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__11__act;
    __Vtask_tb_pipeline__DOT__check_reg__11__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__12__rn;
    __Vtask_tb_pipeline__DOT__check_reg__12__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__12__exp;
    __Vtask_tb_pipeline__DOT__check_reg__12__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__12__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__12__act;
    __Vtask_tb_pipeline__DOT__check_reg__12__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__13__rn;
    __Vtask_tb_pipeline__DOT__check_reg__13__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__13__exp;
    __Vtask_tb_pipeline__DOT__check_reg__13__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__13__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__13__act;
    __Vtask_tb_pipeline__DOT__check_reg__13__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__14__rn;
    __Vtask_tb_pipeline__DOT__check_reg__14__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__14__exp;
    __Vtask_tb_pipeline__DOT__check_reg__14__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__14__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__14__act;
    __Vtask_tb_pipeline__DOT__check_reg__14__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__15__rn;
    __Vtask_tb_pipeline__DOT__check_reg__15__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__15__exp;
    __Vtask_tb_pipeline__DOT__check_reg__15__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__15__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__15__act;
    __Vtask_tb_pipeline__DOT__check_reg__15__act = 0;
    CData/*4:0*/ __Vtask_tb_pipeline__DOT__check_reg__16__rn;
    __Vtask_tb_pipeline__DOT__check_reg__16__rn = 0;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__16__exp;
    __Vtask_tb_pipeline__DOT__check_reg__16__exp = 0;
    std::string __Vtask_tb_pipeline__DOT__check_reg__16__lbl;
    IData/*31:0*/ __Vtask_tb_pipeline__DOT__check_reg__16__act;
    __Vtask_tb_pipeline__DOT__check_reg__16__act = 0;
    // Body
    VL_WRITEF_NX("\n========================================\n  RV32IM 5-Stage Pipeline Testbench\n========================================\n\n",0);
    vlSelfRef.tb_pipeline__DOT__rst = 1U;
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         44);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         44);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         44);
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "../tb/tb_pipeline.sv", 
                                         44);
    vlSelfRef.tb_pipeline__DOT__rst = 0U;
    VL_WRITEF_NX("--- Basic Arithmetic ---\n",0);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         49);
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "../tb/tb_pipeline.sv", 
                                         49);
    __Vtask_tb_pipeline__DOT__check_reg__0__lbl = std::string{"addi x1, x0, 10"};
    __Vtask_tb_pipeline__DOT__check_reg__0__exp = 0xaU;
    __Vtask_tb_pipeline__DOT__check_reg__0__rn = 1U;
    __Vtask_tb_pipeline__DOT__check_reg__0__act = vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__0__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__0__act 
         == __Vtask_tb_pipeline__DOT__check_reg__0__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__0__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__0__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__0__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__0__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__0__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__0__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__0__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    __Vtask_tb_pipeline__DOT__check_reg__1__lbl = std::string{"addi x2, x0, 20"};
    __Vtask_tb_pipeline__DOT__check_reg__1__exp = 0x14U;
    __Vtask_tb_pipeline__DOT__check_reg__1__rn = 2U;
    __Vtask_tb_pipeline__DOT__check_reg__1__act = vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__1__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__1__act 
         == __Vtask_tb_pipeline__DOT__check_reg__1__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__1__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__1__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__1__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__1__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__1__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__1__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__1__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    __Vtask_tb_pipeline__DOT__check_reg__2__lbl = std::string{"add  x3, x1, x2  (forwarding EX\342\206\222EX)"};
    __Vtask_tb_pipeline__DOT__check_reg__2__exp = 0x1eU;
    __Vtask_tb_pipeline__DOT__check_reg__2__rn = 3U;
    __Vtask_tb_pipeline__DOT__check_reg__2__act = vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__2__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__2__act 
         == __Vtask_tb_pipeline__DOT__check_reg__2__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__2__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__2__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__2__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__2__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__2__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__2__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__2__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    __Vtask_tb_pipeline__DOT__check_reg__3__lbl = std::string{"sub  x4, x2, x1"};
    __Vtask_tb_pipeline__DOT__check_reg__3__exp = 0xaU;
    __Vtask_tb_pipeline__DOT__check_reg__3__rn = 4U;
    __Vtask_tb_pipeline__DOT__check_reg__3__act = vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__3__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__3__act 
         == __Vtask_tb_pipeline__DOT__check_reg__3__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__3__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__3__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__3__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__3__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__3__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__3__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__3__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    VL_WRITEF_NX("\n--- Logic ---\n",0);
    __Vtask_tb_pipeline__DOT__check_reg__4__lbl = std::string{"and  x5, x1, x2"};
    __Vtask_tb_pipeline__DOT__check_reg__4__exp = 0U;
    __Vtask_tb_pipeline__DOT__check_reg__4__rn = 5U;
    __Vtask_tb_pipeline__DOT__check_reg__4__act = vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__4__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__4__act 
         == __Vtask_tb_pipeline__DOT__check_reg__4__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__4__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__4__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__4__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__4__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__4__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__4__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__4__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    __Vtask_tb_pipeline__DOT__check_reg__5__lbl = std::string{"or   x6, x1, x2"};
    __Vtask_tb_pipeline__DOT__check_reg__5__exp = 0x1eU;
    __Vtask_tb_pipeline__DOT__check_reg__5__rn = 6U;
    __Vtask_tb_pipeline__DOT__check_reg__5__act = vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__5__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__5__act 
         == __Vtask_tb_pipeline__DOT__check_reg__5__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__5__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__5__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__5__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__5__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__5__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__5__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__5__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    __Vtask_tb_pipeline__DOT__check_reg__6__lbl = std::string{"xor  x7, x1, x2"};
    __Vtask_tb_pipeline__DOT__check_reg__6__exp = 0x1eU;
    __Vtask_tb_pipeline__DOT__check_reg__6__rn = 7U;
    __Vtask_tb_pipeline__DOT__check_reg__6__act = vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__6__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__6__act 
         == __Vtask_tb_pipeline__DOT__check_reg__6__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__6__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__6__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__6__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__6__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__6__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__6__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__6__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    VL_WRITEF_NX("\n--- Shifts ---\n",0);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         61);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         61);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         61);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         61);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         61);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         61);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         61);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         61);
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "../tb/tb_pipeline.sv", 
                                         61);
    __Vtask_tb_pipeline__DOT__check_reg__7__lbl = std::string{"slli x8, x1, 2"};
    __Vtask_tb_pipeline__DOT__check_reg__7__exp = 0x28U;
    __Vtask_tb_pipeline__DOT__check_reg__7__rn = 8U;
    __Vtask_tb_pipeline__DOT__check_reg__7__act = vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__7__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__7__act 
         == __Vtask_tb_pipeline__DOT__check_reg__7__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__7__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__7__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__7__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__7__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__7__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__7__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__7__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    __Vtask_tb_pipeline__DOT__check_reg__8__lbl = std::string{"srli x9, x2, 1"};
    __Vtask_tb_pipeline__DOT__check_reg__8__exp = 0xaU;
    __Vtask_tb_pipeline__DOT__check_reg__8__rn = 9U;
    __Vtask_tb_pipeline__DOT__check_reg__8__act = vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__8__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__8__act 
         == __Vtask_tb_pipeline__DOT__check_reg__8__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__8__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__8__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__8__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__8__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__8__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__8__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__8__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    VL_WRITEF_NX("\n--- Load/Store (tests stall logic) ---\n",0);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         66);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         66);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         66);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         66);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         66);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         66);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         66);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         66);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         66);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         66);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         66);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         66);
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "../tb/tb_pipeline.sv", 
                                         66);
    __Vtask_tb_pipeline__DOT__check_reg__9__lbl = std::string{"sw/lw round-trip (stall inserted)"};
    __Vtask_tb_pipeline__DOT__check_reg__9__exp = 0x1eU;
    __Vtask_tb_pipeline__DOT__check_reg__9__rn = 0xaU;
    __Vtask_tb_pipeline__DOT__check_reg__9__act = vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__9__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__9__act 
         == __Vtask_tb_pipeline__DOT__check_reg__9__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__9__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__9__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__9__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__9__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__9__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__9__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__9__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    VL_WRITEF_NX("\n--- LUI ---\n",0);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         70);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         70);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         70);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         70);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         70);
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "../tb/tb_pipeline.sv", 
                                         70);
    __Vtask_tb_pipeline__DOT__check_reg__10__lbl = 
        std::string{"lui x11, 0x12345"};
    __Vtask_tb_pipeline__DOT__check_reg__10__exp = 0x12345000U;
    __Vtask_tb_pipeline__DOT__check_reg__10__rn = 0xbU;
    __Vtask_tb_pipeline__DOT__check_reg__10__act = 
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__10__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__10__act 
         == __Vtask_tb_pipeline__DOT__check_reg__10__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__10__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__10__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__10__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__10__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__10__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__10__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__10__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    VL_WRITEF_NX("\n--- Multiply ---\n",0);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         74);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         74);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         74);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         74);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         74);
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "../tb/tb_pipeline.sv", 
                                         74);
    __Vtask_tb_pipeline__DOT__check_reg__11__lbl = 
        std::string{"mul x12, x1, x2"};
    __Vtask_tb_pipeline__DOT__check_reg__11__exp = 0xc8U;
    __Vtask_tb_pipeline__DOT__check_reg__11__rn = 0xcU;
    __Vtask_tb_pipeline__DOT__check_reg__11__act = 
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__11__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__11__act 
         == __Vtask_tb_pipeline__DOT__check_reg__11__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__11__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__11__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__11__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__11__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__11__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__11__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__11__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    VL_WRITEF_NX("\n--- Branch (tests flush logic) ---\n",0);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         78);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         78);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         78);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         78);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         78);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         78);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         78);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         78);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         78);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         78);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         78);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         78);
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "../tb/tb_pipeline.sv", 
                                         78);
    __Vtask_tb_pipeline__DOT__check_reg__12__lbl = 
        std::string{"beq taken: x15=1 not 99 (flush worked)"};
    __Vtask_tb_pipeline__DOT__check_reg__12__exp = 1U;
    __Vtask_tb_pipeline__DOT__check_reg__12__rn = 0xfU;
    __Vtask_tb_pipeline__DOT__check_reg__12__act = 
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__12__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__12__act 
         == __Vtask_tb_pipeline__DOT__check_reg__12__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__12__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__12__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__12__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__12__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__12__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__12__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__12__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    VL_WRITEF_NX("\n--- JAL + Subroutine ---\n",0);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         82);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         82);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         82);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         82);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         82);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         82);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         82);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         82);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         82);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         82);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         82);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         82);
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "../tb/tb_pipeline.sv", 
                                         82);
    __Vtask_tb_pipeline__DOT__check_reg__13__lbl = 
        std::string{"jal: x17=7"};
    __Vtask_tb_pipeline__DOT__check_reg__13__exp = 7U;
    __Vtask_tb_pipeline__DOT__check_reg__13__rn = 0x11U;
    __Vtask_tb_pipeline__DOT__check_reg__13__act = 
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__13__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__13__act 
         == __Vtask_tb_pipeline__DOT__check_reg__13__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__13__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__13__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__13__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__13__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__13__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__13__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__13__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    __Vtask_tb_pipeline__DOT__check_reg__14__lbl = 
        std::string{"subroutine: x25=42"};
    __Vtask_tb_pipeline__DOT__check_reg__14__exp = 0x2aU;
    __Vtask_tb_pipeline__DOT__check_reg__14__rn = 0x19U;
    __Vtask_tb_pipeline__DOT__check_reg__14__act = 
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__14__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__14__act 
         == __Vtask_tb_pipeline__DOT__check_reg__14__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__14__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__14__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__14__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__14__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__14__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__14__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__14__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    VL_WRITEF_NX("\n--- Divide ---\n",0);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         87);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         87);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         87);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         87);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         87);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         87);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         87);
    co_await vlSelfRef.__VtrigSched_h0e336f6e__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_pipeline.clk)", 
                                                         "../tb/tb_pipeline.sv", 
                                                         87);
    co_await vlSelfRef.__VdlySched.delay(0x3e8ULL, 
                                         nullptr, "../tb/tb_pipeline.sv", 
                                         87);
    __Vtask_tb_pipeline__DOT__check_reg__15__lbl = 
        std::string{"div 100/7=14"};
    __Vtask_tb_pipeline__DOT__check_reg__15__exp = 0xeU;
    __Vtask_tb_pipeline__DOT__check_reg__15__rn = 0x1aU;
    __Vtask_tb_pipeline__DOT__check_reg__15__act = 
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__15__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__15__act 
         == __Vtask_tb_pipeline__DOT__check_reg__15__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__15__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__15__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__15__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__15__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__15__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__15__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__15__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    __Vtask_tb_pipeline__DOT__check_reg__16__lbl = 
        std::string{"rem 100%7=2"};
    __Vtask_tb_pipeline__DOT__check_reg__16__exp = 2U;
    __Vtask_tb_pipeline__DOT__check_reg__16__rn = 0x1bU;
    __Vtask_tb_pipeline__DOT__check_reg__16__act = 
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
        [__Vtask_tb_pipeline__DOT__check_reg__16__rn];
    if ((__Vtask_tb_pipeline__DOT__check_reg__16__act 
         == __Vtask_tb_pipeline__DOT__check_reg__16__exp)) {
        VL_WRITEF_NX("  PASS | x%-2# = 0x%08x | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__16__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__16__act,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__16__lbl));
        vlSelfRef.tb_pipeline__DOT__pass_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__pass_count);
    } else {
        VL_WRITEF_NX("  FAIL | x%-2# = 0x%08x (expected 0x%08x) | %@\n",0,
                     5,__Vtask_tb_pipeline__DOT__check_reg__16__rn,
                     32,__Vtask_tb_pipeline__DOT__check_reg__16__act,
                     32,__Vtask_tb_pipeline__DOT__check_reg__16__exp,
                     -1,&(__Vtask_tb_pipeline__DOT__check_reg__16__lbl));
        vlSelfRef.tb_pipeline__DOT__fail_count = ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__fail_count);
    }
    VL_WRITEF_NX("\n========================================\n  %0d PASSED, %0d FAILED\n",0,
                 32,vlSelfRef.tb_pipeline__DOT__pass_count,
                 32,vlSelfRef.tb_pipeline__DOT__fail_count);
    if ((0U == vlSelfRef.tb_pipeline__DOT__fail_count)) {
        VL_WRITEF_NX("  *** PIPELINE CORRECT \342\200\224 ALL HAZARDS HANDLED ***\n",0);
    } else {
        VL_WRITEF_NX("  *** FAILURES \342\200\224 open GTKWave and trace the pipeline ***\n",0);
    }
    VL_WRITEF_NX("========================================\n\n",0);
    VL_FINISH_MT("../tb/tb_pipeline.sv", 98, "");
}

VL_INLINE_OPT VlCoroutine Vtb_pipeline___024root___eval_initial__TOP__Vtiming__1(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_initial__TOP__Vtiming__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    co_await vlSelfRef.__VdlySched.delay(0x3b9aca00ULL, 
                                         nullptr, "../tb/tb_pipeline.sv", 
                                         101);
    VL_WRITEF_NX("TIMEOUT\n",0);
    VL_FINISH_MT("../tb/tb_pipeline.sv", 101, "");
}

VL_INLINE_OPT VlCoroutine Vtb_pipeline___024root___eval_initial__TOP__Vtiming__2(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_initial__TOP__Vtiming__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    while (1U) {
        co_await vlSelfRef.__VdlySched.delay(0x1388ULL, 
                                             nullptr, 
                                             "../tb/tb_pipeline.sv", 
                                             17);
        vlSelfRef.tb_pipeline__DOT__clk = (1U & (~ (IData)(vlSelfRef.tb_pipeline__DOT__clk)));
    }
}

void Vtb_pipeline___024root___eval_act(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtb_pipeline___024root___nba_sequent__TOP__0(Vtb_pipeline___024root* vlSelf);
void Vtb_pipeline___024root___nba_sequent__TOP__1(Vtb_pipeline___024root* vlSelf);
void Vtb_pipeline___024root___nba_sequent__TOP__2(Vtb_pipeline___024root* vlSelf);
void Vtb_pipeline___024root___nba_comb__TOP__0(Vtb_pipeline___024root* vlSelf);

void Vtb_pipeline___024root___eval_nba(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_pipeline___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_pipeline___024root___nba_sequent__TOP__1(vlSelf);
        vlSelfRef.__Vm_traceActivity[3U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtb_pipeline___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[4U] = 1U;
        Vtb_pipeline___024root___nba_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_pipeline___024root___nba_sequent__TOP__0(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___nba_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb__v0;
    __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb__v0 = 0;
    CData/*5:0*/ __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb__v0;
    __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb__v0;
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb__v0 = 0;
    CData/*5:0*/ __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__valid__v0;
    __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__valid__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__valid__v0;
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__valid__v0 = 0;
    CData/*1:0*/ __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v0;
    __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v0 = 0;
    CData/*5:0*/ __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v0;
    __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v0;
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v0 = 0;
    CData/*1:0*/ __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v1;
    __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v1 = 0;
    CData/*5:0*/ __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v1;
    __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v1;
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v1 = 0;
    // Body
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__valid__v0 = 0U;
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb__v0 = 0U;
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v0 = 0U;
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v1 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.tb_pipeline__DOT__rst)))) {
        if (vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch) {
            __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__valid__v0 
                = (0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc 
                            >> 2U));
            __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__valid__v0 = 1U;
            __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb__v0 
                = vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_target;
            __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb__v0 
                = (0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc 
                            >> 2U));
            __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb__v0 = 1U;
            if (vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_taken) {
                if ((3U != vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht
                     [(0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc 
                                >> 2U))])) {
                    __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v0 
                        = (3U & ((IData)(1U) + vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht
                                 [(0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc 
                                            >> 2U))]));
                    __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v0 
                        = (0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc 
                                    >> 2U));
                    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v0 = 1U;
                }
            } else if ((0U != vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht
                        [(0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc 
                                   >> 2U))])) {
                __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v1 
                    = (3U & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht
                             [(0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc 
                                        >> 2U))] - (IData)(1U)));
                __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v1 
                    = (0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc 
                                >> 2U));
                __VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v1 = 1U;
            }
        }
    }
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_jump = 
        ((1U & (~ ((IData)(vlSelfRef.tb_pipeline__DOT__rst) 
                   | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
         && (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_jump));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_read 
        = ((1U & (~ (IData)(vlSelfRef.tb_pipeline__DOT__rst))) 
           && (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_read));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_predicted_taken 
        = ((1U & (~ ((IData)(vlSelfRef.tb_pipeline__DOT__rst) 
                     | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
           && (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_predicted_taken));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_src 
        = ((1U & (~ ((IData)(vlSelfRef.tb_pipeline__DOT__rst) 
                     | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
           && (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_src));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_jalr = 
        ((1U & (~ ((IData)(vlSelfRef.tb_pipeline__DOT__rst) 
                   | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
         && (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_jalr));
    if (vlSelfRef.tb_pipeline__DOT__rst) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_mem_data = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_wb_sel = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_alu_result = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_pc_plus4 = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_wb_sel = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_pc_plus4 = 0U;
    } else {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_mem_data 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_read_data;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_wb_sel 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_wb_sel;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_alu_result 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_pc_plus4 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_pc_plus4;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_wb_sel 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_wb_sel;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_pc_plus4 
            = ((IData)(4U) + vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc);
    }
    if (((IData)(vlSelfRef.tb_pipeline__DOT__rst) | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush))) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_imm = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs1_addr = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs2_addr = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs1_data = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs2_data = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_wb_sel = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc = 0U;
    } else {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_imm 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_imm;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_op 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_alu_op;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs1_addr 
            = (0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                        >> 0xfU));
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs2_addr 
            = (0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                        >> 0x14U));
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs1_data 
            = ((0U == (0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                >> 0xfU))) ? 0U : (
                                                   ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_reg_write) 
                                                    & ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_rd_addr) 
                                                       == 
                                                       (0x1fU 
                                                        & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                                           >> 0xfU))))
                                                    ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_data
                                                    : 
                                                   vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
                                                   [
                                                   (0x1fU 
                                                    & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                                       >> 0xfU))]));
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rs2_data 
            = ((0U == (0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                >> 0x14U))) ? 0U : 
               (((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_reg_write) 
                 & ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_rd_addr) 
                    == (0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                 >> 0x14U)))) ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_data
                 : vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs
                [(0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                           >> 0x14U))]));
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_wb_sel 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_wb_sel;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_pc;
    }
    if (__VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__valid__v0) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__valid[__VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__valid__v0] = 1U;
    }
    if (__VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb__v0) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb[__VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb__v0] 
            = __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb__v0;
    }
    if (__VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v0) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht[__VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v0] 
            = __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v0;
    }
    if (__VdlySet__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v1) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht[__VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v1] 
            = __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht__v1;
    }
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch 
        = ((1U & (~ ((IData)(vlSelfRef.tb_pipeline__DOT__rst) 
                     | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
           && (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_branch));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_read 
        = ((1U & (~ ((IData)(vlSelfRef.tb_pipeline__DOT__rst) 
                     | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
           && (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_mem_read));
    if (((IData)(vlSelfRef.tb_pipeline__DOT__rst) | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__flush_if_id))) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_predicted_taken = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_pc = 0U;
    } else if ((1U & (~ (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__stall_pc)))) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_predicted_taken 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_predict_taken;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_pc 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc;
    }
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_target 
        = (vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_imm 
           + vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_pc);
}

VL_INLINE_OPT void Vtb_pipeline___024root___nba_sequent__TOP__1(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___nba_sequent__TOP__1\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs__v0;
    __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs__v0 = 0;
    CData/*4:0*/ __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs__v0;
    __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs__v0;
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v0;
    __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v0;
    __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v0;
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v0 = 0;
    CData/*7:0*/ __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v1;
    __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v1 = 0;
    SData/*11:0*/ __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v1;
    __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v1 = 0;
    CData/*0:0*/ __VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v1;
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v1 = 0;
    CData/*7:0*/ __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v2;
    __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v2 = 0;
    SData/*11:0*/ __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v2;
    __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v2 = 0;
    CData/*7:0*/ __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v3;
    __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v3 = 0;
    SData/*11:0*/ __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v3;
    __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v3 = 0;
    CData/*0:0*/ __VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v3;
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v3 = 0;
    CData/*7:0*/ __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v4;
    __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v4 = 0;
    SData/*11:0*/ __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v4;
    __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v4 = 0;
    CData/*7:0*/ __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v5;
    __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v5 = 0;
    SData/*11:0*/ __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v5;
    __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v5 = 0;
    CData/*7:0*/ __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v6;
    __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v6 = 0;
    SData/*11:0*/ __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v6;
    __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v6 = 0;
    // Body
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v0 = 0U;
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v1 = 0U;
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v3 = 0U;
    __VdlySet__tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs__v0 = 0U;
    if (vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_write) {
        if ((0U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_funct3))) {
            __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v0 
                = (0xffU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rs2_data);
            __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v0 
                = (0xfffU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result);
            __VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v0 = 1U;
        } else if ((1U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_funct3))) {
            __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v1 
                = (0xffU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rs2_data);
            __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v1 
                = (0xfffU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result);
            __VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v1 = 1U;
            __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v2 
                = (0xffU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rs2_data 
                            >> 8U));
            __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v2 
                = (0xfffU & ((IData)(1U) + vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result));
        } else if ((2U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_funct3))) {
            __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v3 
                = (0xffU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rs2_data);
            __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v3 
                = (0xfffU & vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result);
            __VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v3 = 1U;
            __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v4 
                = (0xffU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rs2_data 
                            >> 8U));
            __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v4 
                = (0xfffU & ((IData)(1U) + vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result));
            __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v5 
                = (0xffU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rs2_data 
                            >> 0x10U));
            __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v5 
                = (0xfffU & ((IData)(2U) + vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result));
            __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v6 
                = (vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rs2_data 
                   >> 0x18U);
            __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v6 
                = (0xfffU & ((IData)(3U) + vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result));
        }
    }
    if (((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_reg_write) 
         & (0U != (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_rd_addr)))) {
        __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs__v0 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_data;
        __VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs__v0 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_rd_addr;
        __VdlySet__tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs__v0 = 1U;
    }
    if (__VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v0) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem[__VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v0] 
            = __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v0;
    }
    if (__VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v1) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem[__VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v1] 
            = __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v1;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem[__VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v2] 
            = __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v2;
    }
    if (__VdlySet__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v3) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem[__VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v3] 
            = __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v3;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem[__VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v4] 
            = __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v4;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem[__VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v5] 
            = __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v5;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem[__VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v6] 
            = __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem__v6;
    }
    if (__VdlySet__tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs__v0) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs[__VdlyDim0__tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs__v0] 
            = __VdlyVal__tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs__v0;
    }
}

VL_INLINE_OPT void Vtb_pipeline___024root___nba_sequent__TOP__2(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___nba_sequent__TOP__2\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2;
    tb_pipeline__DOT__DUT__DOT__u_ctrl__DOT____VdfgRegularize_h9df94077_0_2 = 0;
    // Body
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_data = 
        ((0U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_wb_sel))
          ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_alu_result
          : ((1U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_wb_sel))
              ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_mem_data
              : ((2U == (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_wb_sel))
                  ? vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_pc_plus4
                  : vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_alu_result)));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_write 
        = ((1U & (~ (IData)(vlSelfRef.tb_pipeline__DOT__rst))) 
           && (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_write));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_reg_write 
        = ((1U & (~ (IData)(vlSelfRef.tb_pipeline__DOT__rst))) 
           && (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_reg_write));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_write 
        = ((1U & (~ ((IData)(vlSelfRef.tb_pipeline__DOT__rst) 
                     | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
           && (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_mem_write));
    if (vlSelfRef.tb_pipeline__DOT__rst) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rs2_data = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_funct3 = 0U;
    } else {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rs2_data 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_fwd_rs2;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_mem_funct3 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_funct3;
    }
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_funct3 
        = (((IData)(vlSelfRef.tb_pipeline__DOT__rst) 
            | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush))
            ? 0U : (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_mem_funct3));
    if (vlSelfRef.tb_pipeline__DOT__rst) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_rd_addr = 0U;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rd_addr = 0U;
    } else {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_alu_result 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_alu_result;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__wb_rd_addr 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rd_addr;
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_rd_addr 
            = vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rd_addr;
    }
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rd_addr 
        = (((IData)(vlSelfRef.tb_pipeline__DOT__rst) 
            | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush))
            ? 0U : (0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                             >> 7U)));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__mem_reg_write 
        = ((1U & (~ (IData)(vlSelfRef.tb_pipeline__DOT__rst))) 
           && (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_reg_write));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_reg_write 
        = ((1U & (~ ((IData)(vlSelfRef.tb_pipeline__DOT__rst) 
                     | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush)))) 
           && (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_reg_write));
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
    if (((IData)(vlSelfRef.tb_pipeline__DOT__rst) | (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__flush_if_id))) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr = 0x13U;
    } else if ((1U & (~ (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__stall_pc)))) {
        vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
            = (((vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_imem__DOT__mem
                 [(0xfffU & ((IData)(3U) + vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc))] 
                 << 0x18U) | (vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_imem__DOT__mem
                              [(0xfffU & ((IData)(2U) 
                                          + vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc))] 
                              << 0x10U)) | ((vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_imem__DOT__mem
                                             [(0xfffU 
                                               & ((IData)(1U) 
                                                  + vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc))] 
                                             << 8U) 
                                            | vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_imem__DOT__mem
                                            [(0xfffU 
                                              & vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc)]));
    }
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc = ((IData)(vlSelfRef.tb_pipeline__DOT__rst)
                                                    ? 0U
                                                    : vlSelfRef.tb_pipeline__DOT__DUT__DOT__next_pc);
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
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__stall_pc 
        = ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_mem_read) 
           & ((0U != (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rd_addr)) 
              & (((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rd_addr) 
                  == (0x1fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                               >> 0xfU))) | ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_rd_addr) 
                                             == (0x1fU 
                                                 & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__id_instr 
                                                    >> 0x14U))))));
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
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__flush_if_id 
        = ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_jump) 
           | ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch) 
              & ((IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_predicted_taken) 
                 != (IData)(vlSelfRef.tb_pipeline__DOT__DUT__DOT__ex_branch_taken))));
    vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_predict_taken 
        = (vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__valid
           [(0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc 
                      >> 2U))] & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht
                                  [(0x3fU & (vlSelfRef.tb_pipeline__DOT__DUT__DOT__if_pc 
                                             >> 2U))] 
                                  >> 1U));
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

VL_INLINE_OPT void Vtb_pipeline___024root___nba_comb__TOP__0(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___nba_comb__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

void Vtb_pipeline___024root___timing_resume(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___timing_resume\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VtrigSched_h0e336f6e__0.resume(
                                                   "@(posedge tb_pipeline.clk)");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_pipeline___024root___timing_commit(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___timing_commit\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((! (1ULL & vlSelfRef.__VactTriggered.word(0U)))) {
        vlSelfRef.__VtrigSched_h0e336f6e__0.commit(
                                                   "@(posedge tb_pipeline.clk)");
    }
}

void Vtb_pipeline___024root___eval_triggers__act(Vtb_pipeline___024root* vlSelf);

bool Vtb_pipeline___024root___eval_phase__act(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_pipeline___024root___eval_triggers__act(vlSelf);
    Vtb_pipeline___024root___timing_commit(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtb_pipeline___024root___timing_resume(vlSelf);
        Vtb_pipeline___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_pipeline___024root___eval_phase__nba(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_pipeline___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_pipeline___024root___dump_triggers__nba(Vtb_pipeline___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_pipeline___024root___dump_triggers__act(Vtb_pipeline___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_pipeline___024root___eval(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval\n"); );
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
            Vtb_pipeline___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("../tb/tb_pipeline.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_pipeline___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("../tb/tb_pipeline.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtb_pipeline___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtb_pipeline___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_pipeline___024root___eval_debug_assertions(Vtb_pipeline___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_pipeline__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_pipeline___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
