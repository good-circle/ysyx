// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
#include "Vtop.h"
#include "Vtop__Syms.h"
#include "verilated_dpi.h"


void Vtop::finish(svBit* is_finish) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root::finish\n"); );
    // Variables
    CData/*0:0*/ is_finish__Vcvt;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("finish");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    Vtop__Vcb_finish_t __Vcb = (Vtop__Vcb_finish_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((Vtop__Syms*)(__Vscopep->symsp()), is_finish__Vcvt);
    for (size_t is_finish__Vidx = 0; is_finish__Vidx < 1; ++is_finish__Vidx) *is_finish = is_finish__Vcvt;
}
