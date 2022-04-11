// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated_heavy.h"

//==========

class Vtop__Syms;
class Vtop_VerilatedVcd;


//----------

VL_MODULE(Vtop___024root) {
  public:

    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT64(pc,63,0);

    // LOCAL SIGNALS
    CData/*0:0*/ top__DOT__addi;
    CData/*0:0*/ top__DOT__jalr;
    CData/*0:0*/ top__DOT__sd;
    CData/*0:0*/ top__DOT__sltiu;
    CData/*0:0*/ top__DOT__beq;
    CData/*0:0*/ top__DOT__bne;
    CData/*0:0*/ top__DOT__I_Type;
    CData/*0:0*/ top__DOT__B_Type;
    CData/*0:0*/ top__DOT__U_Type;
    CData/*1:0*/ top__DOT__aluop;
    IData/*31:0*/ top__DOT__inst;
    QData/*63:0*/ top__DOT__inst_2;
    QData/*63:0*/ top__DOT__U_extension;
    QData/*63:0*/ top__DOT__imm_extension;
    QData/*63:0*/ top__DOT__br_target;
    QData/*63:0*/ top__DOT__alu_src1;
    QData/*63:0*/ top__DOT__alu_result;
    QData/*63:0*/ top__DOT__rf_rdata1;
    QData/*63:0*/ top__DOT__rf_rdata2;
    QData/*63:0*/ top__DOT__mem_rdata;
    VlUnpacked<QData/*63:0*/, 32> top__DOT__u_regfile__DOT__rf;

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__clk;
    QData/*63:0*/ __Vtask_top__DOT__u_blackbox__DOT__pmem_read__1__mem_rdata;
    QData/*63:0*/ __Vtask_top__DOT__u_blackbox__DOT__pmem_read__3__mem_rdata;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vtop___024root);  ///< Copying not allowed
  public:
    Vtop___024root(const char* name);
    ~Vtop___024root();

    // INTERNAL METHODS
    void __Vconfigure(Vtop__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
