// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions.
//
#include "VTop.h"
#include "VTop__Syms.h"
#include "verilated_dpi.h"


svBit VTop::finish() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root::finish\n"); );
    // Variables
    CData/*0:0*/ finish__Vfuncrtn__Vcvt;
    // Body
    static int __Vfuncnum = -1;
    if (VL_UNLIKELY(__Vfuncnum == -1)) __Vfuncnum = Verilated::exportFuncNum("finish");
    const VerilatedScope* __Vscopep = Verilated::dpiScope();
    VTop__Vcb_finish_t __Vcb = (VTop__Vcb_finish_t)(VerilatedScope::exportFind(__Vscopep, __Vfuncnum));
    (*__Vcb)((VTop__Syms*)(__Vscopep->symsp()), finish__Vfuncrtn__Vcvt);
    svBit finish__Vfuncrtn;
    for (size_t finish__Vfuncrtn__Vidx = 0; finish__Vfuncrtn__Vidx < 1; ++finish__Vfuncrtn__Vidx) finish__Vfuncrtn = finish__Vfuncrtn__Vcvt;
    return finish__Vfuncrtn;
}
