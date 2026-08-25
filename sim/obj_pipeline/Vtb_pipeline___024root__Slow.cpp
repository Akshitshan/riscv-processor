// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_pipeline.h for the primary calling header

#include "Vtb_pipeline__pch.h"
#include "Vtb_pipeline__Syms.h"
#include "Vtb_pipeline___024root.h"

void Vtb_pipeline___024root___ctor_var_reset(Vtb_pipeline___024root* vlSelf);

Vtb_pipeline___024root::Vtb_pipeline___024root(Vtb_pipeline__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_pipeline___024root___ctor_var_reset(this);
}

void Vtb_pipeline___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_pipeline___024root::~Vtb_pipeline___024root() {
}
