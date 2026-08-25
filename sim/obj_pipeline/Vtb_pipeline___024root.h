// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_pipeline.h for the primary calling header

#ifndef VERILATED_VTB_PIPELINE___024ROOT_H_
#define VERILATED_VTB_PIPELINE___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_pipeline__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_pipeline___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_pipeline__DOT__clk;
        CData/*0:0*/ tb_pipeline__DOT__rst;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__id_reg_write;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__id_mem_read;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__id_mem_write;
        CData/*2:0*/ tb_pipeline__DOT__DUT__DOT__id_mem_funct3;
        CData/*1:0*/ tb_pipeline__DOT__DUT__DOT__id_wb_sel;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__id_alu_src;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__id_branch;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__id_jump;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__id_jalr;
        CData/*4:0*/ tb_pipeline__DOT__DUT__DOT__id_alu_op;
        CData/*2:0*/ tb_pipeline__DOT__DUT__DOT__id_imm_sel;
        CData/*4:0*/ tb_pipeline__DOT__DUT__DOT__ex_rs1_addr;
        CData/*4:0*/ tb_pipeline__DOT__DUT__DOT__ex_rs2_addr;
        CData/*4:0*/ tb_pipeline__DOT__DUT__DOT__ex_rd_addr;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__ex_reg_write;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__ex_mem_read;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__ex_mem_write;
        CData/*2:0*/ tb_pipeline__DOT__DUT__DOT__ex_mem_funct3;
        CData/*1:0*/ tb_pipeline__DOT__DUT__DOT__ex_wb_sel;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__ex_alu_src;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__ex_branch;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__ex_jump;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__ex_jalr;
        CData/*4:0*/ tb_pipeline__DOT__DUT__DOT__ex_alu_op;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__ex_branch_taken;
        CData/*1:0*/ tb_pipeline__DOT__DUT__DOT__ex_forward_a;
        CData/*1:0*/ tb_pipeline__DOT__DUT__DOT__ex_forward_b;
        CData/*4:0*/ tb_pipeline__DOT__DUT__DOT__mem_rd_addr;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__mem_reg_write;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__mem_mem_read;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__mem_mem_write;
        CData/*2:0*/ tb_pipeline__DOT__DUT__DOT__mem_mem_funct3;
        CData/*1:0*/ tb_pipeline__DOT__DUT__DOT__mem_wb_sel;
        CData/*4:0*/ tb_pipeline__DOT__DUT__DOT__wb_rd_addr;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__wb_reg_write;
        CData/*1:0*/ tb_pipeline__DOT__DUT__DOT__wb_wb_sel;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__stall_pc;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__flush_if_id;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__if_predict_taken;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__id_predicted_taken;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT__ex_predicted_taken;
        CData/*0:0*/ tb_pipeline__DOT__DUT__DOT____Vcellinp__u_id_ex__flush;
        CData/*7:0*/ tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__byte_val;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_pipeline__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_pipeline__DOT__rst__0;
        CData/*0:0*/ __VactContinue;
        SData/*15:0*/ tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__half_val;
        IData/*31:0*/ tb_pipeline__DOT__pass_count;
        IData/*31:0*/ tb_pipeline__DOT__fail_count;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__if_pc;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__id_pc;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__id_instr;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__id_imm;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__ex_pc;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__ex_rs1_data;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__ex_rs2_data;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__ex_imm;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__ex_alu_input_b;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__ex_alu_result;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__ex_fwd_rs2;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__mem_alu_result;
    };
    struct {
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__mem_rs2_data;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__mem_pc_plus4;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__mem_read_data;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__wb_alu_result;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__wb_mem_data;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__wb_pc_plus4;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__wb_data;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__ex_branch_target;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__next_pc;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__final_alu_a;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__u_imem__DOT__i;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__u_bp__DOT__i;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__u_rf__DOT__i;
        IData/*31:0*/ tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__i;
        IData/*31:0*/ __VactIterCount;
        QData/*63:0*/ tb_pipeline__DOT__DUT__DOT__u_alu__DOT__mul_ss;
        VlUnpacked<CData/*7:0*/, 4096> tb_pipeline__DOT__DUT__DOT__u_imem__DOT__mem;
        VlUnpacked<CData/*1:0*/, 64> tb_pipeline__DOT__DUT__DOT__u_bp__DOT__bht;
        VlUnpacked<IData/*31:0*/, 64> tb_pipeline__DOT__DUT__DOT__u_bp__DOT__btb;
        VlUnpacked<CData/*0:0*/, 64> tb_pipeline__DOT__DUT__DOT__u_bp__DOT__valid;
        VlUnpacked<IData/*31:0*/, 32> tb_pipeline__DOT__DUT__DOT__u_rf__DOT__regs;
        VlUnpacked<CData/*7:0*/, 4096> tb_pipeline__DOT__DUT__DOT__u_dmem__DOT__mem;
        VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h0e336f6e__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_pipeline__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_pipeline___024root(Vtb_pipeline__Syms* symsp, const char* v__name);
    ~Vtb_pipeline___024root();
    VL_UNCOPYABLE(Vtb_pipeline___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
