// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_branch_bench.h for the primary calling header

#include "Vtb_branch_bench__pch.h"
#include "Vtb_branch_bench__Syms.h"
#include "Vtb_branch_bench___024root.h"

void Vtb_branch_bench___024root___ctor_var_reset(Vtb_branch_bench___024root* vlSelf);

Vtb_branch_bench___024root::Vtb_branch_bench___024root(Vtb_branch_bench__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_branch_bench___024root___ctor_var_reset(this);
}

void Vtb_branch_bench___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_branch_bench___024root::~Vtb_branch_bench___024root() {
}
