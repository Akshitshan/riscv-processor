// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_branch_bench.h for the primary calling header

#include "Vtb_branch_bench__pch.h"
#include "Vtb_branch_bench__Syms.h"
#include "Vtb_branch_bench___024root.h"

VL_ATTR_COLD void Vtb_branch_bench___024root___eval_initial__TOP(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___eval_initial__TOP\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<4>/*127:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_3;
    // Body
    vlSelfRef.tb_branch_bench__DOT__clk = 0U;
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x616e6368U;
    __Vtemp_1[2U] = 0x655f6272U;
    __Vtemp_1[3U] = 0x776176U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__i = 0U;
    while (VL_GTS_III(32, 0x1000U, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__i)) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__mem[(0xfffU 
                                                                    & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__i)] = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__i 
            = ((IData)(1U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__i);
    }
    __Vtemp_3[0U] = 0x2e686578U;
    __Vtemp_3[1U] = 0x6772616dU;
    __Vtemp_3[2U] = 0x70726fU;
    VL_READMEM_N(true, 8, 4096, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_3)
                 ,  &(vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_imem__DOT__mem)
                 , 0, ~0ULL);
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[1U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[1U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[1U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[2U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[2U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[2U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[3U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[3U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[3U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[4U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[4U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[4U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[5U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[5U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[5U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[6U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[6U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[6U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[7U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[7U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[7U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[8U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[8U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[8U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[9U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[9U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[9U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0xaU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0xaU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0xaU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0xbU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0xbU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0xbU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0xcU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0xcU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0xcU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0xdU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0xdU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0xdU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0xeU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0xeU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0xeU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0xfU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0xfU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0xfU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x10U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x10U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x10U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x11U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x11U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x11U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x12U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x12U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x12U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x13U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x13U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x13U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x14U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x14U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x14U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x15U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x15U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x15U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x16U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x16U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x16U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x17U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x17U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x17U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x18U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x18U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x18U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x19U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x19U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x19U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x1aU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x1aU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x1aU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x1bU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x1bU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x1bU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x1cU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x1cU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x1cU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x1dU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x1dU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x1dU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x1eU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x1eU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x1eU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x1fU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x1fU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x1fU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x20U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x20U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x20U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x21U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x21U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x21U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x22U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x22U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x22U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x23U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x23U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x23U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x24U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x24U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x24U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x25U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x25U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x25U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x26U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x26U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x26U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x27U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x27U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x27U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x28U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x28U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x28U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x29U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x29U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x29U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x2aU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x2aU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x2aU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x2bU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x2bU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x2bU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x2cU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x2cU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x2cU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x2dU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x2dU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x2dU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x2eU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x2eU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x2eU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x2fU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x2fU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x2fU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x30U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x30U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x30U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x31U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x31U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x31U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x32U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x32U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x32U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x33U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x33U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x33U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x34U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x34U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x34U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x35U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x35U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x35U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x36U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x36U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x36U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x37U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x37U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x37U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x38U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x38U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x38U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x39U] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x39U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x39U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x3aU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x3aU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x3aU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x3bU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x3bU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x3bU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x3cU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x3cU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x3cU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x3dU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x3dU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x3dU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x3eU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x3eU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x3eU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__bht[0x3fU] = 1U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__btb[0x3fU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__valid[0x3fU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_bp__DOT__i = 0x40U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[1U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[2U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[3U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[4U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[5U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[6U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[7U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[8U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[9U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0xaU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0xbU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0xcU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0xdU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0xeU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0xfU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x10U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x11U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x12U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x13U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x14U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x15U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x16U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x17U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x18U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x19U] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x1aU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x1bU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x1cU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x1dU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x1eU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__regs[0x1fU] = 0U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_rf__DOT__i = 0x20U;
    vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__i = 0U;
    while (VL_GTS_III(32, 0x1000U, vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__i)) {
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__mem[(0xfffU 
                                                                    & vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__i)] = 0U;
        vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__i 
            = ((IData)(1U) + vlSelfRef.tb_branch_bench__DOT__DUT__DOT__u_dmem__DOT__i);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_branch_bench___024root___dump_triggers__stl(Vtb_branch_bench___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_branch_bench___024root___eval_triggers__stl(Vtb_branch_bench___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_branch_bench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_branch_bench___024root___eval_triggers__stl\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_branch_bench___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
