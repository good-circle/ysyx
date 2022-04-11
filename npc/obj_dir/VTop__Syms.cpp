// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VTop__Syms.h"
#include "VTop.h"
#include "VTop___024root.h"

void VTop___024root____Vdpiexp_Top__DOT__blackbox__DOT__finish_TOP(VTop__Syms* __restrict vlSymsp, CData/*0:0*/ &finish__Vfuncrtn);

// FUNCTIONS
VTop__Syms::~VTop__Syms()
{
}

VTop__Syms::VTop__Syms(VerilatedContext* contextp, const char* namep,VTop* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp(modelp)
    // Setup module instances
    , TOP(namep)
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(this, true);
    // Setup scopes
    __Vscope_Top__blackbox.configure(this, name(), "Top.blackbox", "blackbox", -12, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
        __Vscope_Top__blackbox.exportInsert(__Vfinal, "finish", (void*)(&VTop___024root____Vdpiexp_Top__DOT__blackbox__DOT__finish_TOP));
    }
}
