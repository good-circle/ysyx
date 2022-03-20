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
    VL_IN8(top__02Eclk,0,0);
    VL_IN8(regfile__02Eclk,0,0);
    VL_OUT8(a,0,0);
    VL_IN8(raddr1,4,0);
    VL_IN8(raddr2,4,0);
    VL_IN8(we,0,0);
    VL_IN8(waddr,4,0);
    VL_IN(inst,31,0);
    VL_OUT(pc,31,0);
    VL_OUT(rdata1,31,0);
    VL_OUT(rdata2,31,0);
    VL_IN(wdata,31,0);

    // LOCAL SIGNALS
    VlUnpacked<IData/*31:0*/, 32> regfile__DOT__rf;

    // LOCAL VARIABLES
    CData/*0:0*/ __Vclklast__TOP__top__02Eclk;
    CData/*0:0*/ __Vclklast__TOP__regfile__02Eclk;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

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
