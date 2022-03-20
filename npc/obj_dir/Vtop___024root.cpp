// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop___024root.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

void Vtop___024root____Vdpiexp_top__DOT__finish_TOP(Vtop__Syms* __restrict vlSymsp, CData/*0:0*/ &is_finish) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiexp_top__DOT__finish_TOP\n"); );
    // Variables
    // Body
    is_finish = (0U == vlSymsp->TOP.inst);
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__1\n"); );
    // Body
    vlSelf->pc = ((IData)(4U) + vlSelf->pc);
    if ((IData)((0x13U == (0x707fU & vlSelf->inst)))) {
        vlSelf->a = (1U & ((IData)(1U) + (IData)(vlSelf->a)));
    }
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__2\n"); );
    // Variables
    CData/*4:0*/ __Vdlyvdim0__regfile__DOT__rf__v0;
    CData/*0:0*/ __Vdlyvset__regfile__DOT__rf__v0;
    IData/*31:0*/ __Vdlyvval__regfile__DOT__rf__v0;
    // Body
    __Vdlyvset__regfile__DOT__rf__v0 = 0U;
    if (vlSelf->we) {
        __Vdlyvval__regfile__DOT__rf__v0 = vlSelf->wdata;
        __Vdlyvset__regfile__DOT__rf__v0 = 1U;
        __Vdlyvdim0__regfile__DOT__rf__v0 = vlSelf->waddr;
    }
    if (__Vdlyvset__regfile__DOT__rf__v0) {
        vlSelf->regfile__DOT__rf[__Vdlyvdim0__regfile__DOT__rf__v0] 
            = __Vdlyvval__regfile__DOT__rf__v0;
    }
}

VL_INLINE_OPT void Vtop___024root___settle__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__3\n"); );
    // Body
    vlSelf->rdata1 = ((0U == (IData)(vlSelf->raddr1))
                       ? 0U : vlSelf->regfile__DOT__rf
                      [vlSelf->raddr1]);
    vlSelf->rdata2 = ((0U == (IData)(vlSelf->raddr2))
                       ? 0U : vlSelf->regfile__DOT__rf
                      [vlSelf->raddr2]);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->top__02Eclk) & (~ (IData)(vlSelf->__Vclklast__TOP__top__02Eclk)))) {
        Vtop___024root___sequent__TOP__1(vlSelf);
    }
    if (((IData)(vlSelf->regfile__02Eclk) & (~ (IData)(vlSelf->__Vclklast__TOP__regfile__02Eclk)))) {
        Vtop___024root___sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    Vtop___024root___settle__TOP__3(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__top__02Eclk = vlSelf->top__02Eclk;
    vlSelf->__Vclklast__TOP__regfile__02Eclk = vlSelf->regfile__02Eclk;
}

QData Vtop___024root___change_request_1(Vtop___024root* vlSelf);

VL_INLINE_OPT QData Vtop___024root___change_request(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___change_request\n"); );
    // Body
    return (Vtop___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vtop___024root___change_request_1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->top__02Eclk & 0xfeU))) {
        Verilated::overWidthError("top.clk");}
    if (VL_UNLIKELY((vlSelf->regfile__02Eclk & 0xfeU))) {
        Verilated::overWidthError("regfile.clk");}
    if (VL_UNLIKELY((vlSelf->raddr1 & 0xe0U))) {
        Verilated::overWidthError("raddr1");}
    if (VL_UNLIKELY((vlSelf->raddr2 & 0xe0U))) {
        Verilated::overWidthError("raddr2");}
    if (VL_UNLIKELY((vlSelf->we & 0xfeU))) {
        Verilated::overWidthError("we");}
    if (VL_UNLIKELY((vlSelf->waddr & 0xe0U))) {
        Verilated::overWidthError("waddr");}
}
#endif  // VL_DEBUG
