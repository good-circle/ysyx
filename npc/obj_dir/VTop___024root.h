// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VTop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class VTop__Syms;

//----------

VL_MODULE(VTop___024root) {
  public:

    // PORTS
    VL_IN8(clock,0,0);
    VL_IN8(reset,0,0);
    VL_OUT64(io_pc,63,0);

    // LOCAL SIGNALS
    CData/*3:0*/ Top__DOT__bru_io_bruop;
    CData/*0:0*/ Top__DOT___information_T_187;
    CData/*1:0*/ Top__DOT__fu_type;
    CData/*3:0*/ Top__DOT__information_5;
    CData/*0:0*/ Top__DOT___information_T_680;
    IData/*31:0*/ Top__DOT__inst;
    QData/*63:0*/ Top__DOT__bru_io_imm;
    QData/*63:0*/ Top__DOT__alu_io_src1;
    QData/*63:0*/ Top__DOT__alu_io_src2;
    QData/*63:0*/ Top__DOT__alu_io_result;
    QData/*63:0*/ Top__DOT__blackbox_mem_rdata;
    QData/*63:0*/ Top__DOT__pc;
    QData/*63:0*/ Top__DOT___rf_wdata_T_1;
    QData/*63:0*/ Top__DOT___load_rdata_T_7;
    QData/*63:0*/ Top__DOT__bru__DOT___io_br_target_T_6;
    VlUnpacked<QData/*63:0*/, 32> Top__DOT__regfile__DOT__rf;

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clock;
    QData/*63:0*/ __Vtask_Top__DOT__blackbox__DOT__pmem_read__1__mem_rdata;
    QData/*63:0*/ __Vtask_Top__DOT__blackbox__DOT__pmem_read__3__mem_rdata;

    // INTERNAL VARIABLES
    VTop__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VTop___024root);  ///< Copying not allowed
  public:
    VTop___024root(const char* name);
    ~VTop___024root();

    // INTERNAL METHODS
    void __Vconfigure(VTop__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
