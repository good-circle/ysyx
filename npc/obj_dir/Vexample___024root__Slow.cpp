// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vexample.h for the primary calling header

#include "Vexample___024root.h"
#include "Vexample__Syms.h"

//==========


void Vexample___024root___ctor_var_reset(Vexample___024root* vlSelf);

Vexample___024root::Vexample___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vexample___024root___ctor_var_reset(this);
}

void Vexample___024root::__Vconfigure(Vexample__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vexample___024root::~Vexample___024root() {
}

void Vexample___024root___eval_initial(Vexample___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vexample__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexample___024root___eval_initial\n"); );
}

void Vexample___024root___combo__TOP__1(Vexample___024root* vlSelf);

void Vexample___024root___eval_settle(Vexample___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vexample__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexample___024root___eval_settle\n"); );
    // Body
    Vexample___024root___combo__TOP__1(vlSelf);
}

void Vexample___024root___final(Vexample___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vexample__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexample___024root___final\n"); );
}

void Vexample___024root___ctor_var_reset(Vexample___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vexample__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vexample___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->a = VL_RAND_RESET_I(1);
    vlSelf->b = VL_RAND_RESET_I(1);
    vlSelf->f = VL_RAND_RESET_I(1);
}
