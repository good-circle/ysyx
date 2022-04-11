// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP__SYMS_H_
#define VERILATED_VTOP__SYMS_H_  // guard

#include "verilated_heavy.h"

// INCLUDE MODEL CLASS

#include "VTop.h"

// INCLUDE MODULE CLASSES
#include "VTop___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)
using VTop__Vcb_finish_t = void (*) (VTop__Syms* __restrict vlSymsp, CData/*0:0*/ &finish__Vfuncrtn);

// SYMS CLASS (contains all model state)
class VTop__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VTop* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    VTop___024root                 TOP;

    // SCOPE NAMES
    VerilatedScope __Vscope_Top__blackbox;

    // CONSTRUCTORS
    VTop__Syms(VerilatedContext* contextp, const char* namep, VTop* modelp);
    ~VTop__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
