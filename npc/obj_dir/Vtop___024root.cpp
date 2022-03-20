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

VL_INLINE_OPT void Vtop___024root___combo__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__1\n"); );
    // Body
    vlSelf->top__DOT__J_extension = (((- (QData)((IData)(
                                                         (vlSelf->inst 
                                                          >> 0x1fU)))) 
                                      << 0x14U) | (QData)((IData)(
                                                                  ((0xff000U 
                                                                    & vlSelf->inst) 
                                                                   | ((0x800U 
                                                                       & (vlSelf->inst 
                                                                          >> 9U)) 
                                                                      | (0x7feU 
                                                                         & (vlSelf->inst 
                                                                            >> 0x14U)))))));
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__3\n"); );
    // Variables
    CData/*4:0*/ __Vdlyvdim0__top__DOT__u_regfile__DOT__rf__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__u_regfile__DOT__rf__v0;
    QData/*63:0*/ __Vdly__pc;
    QData/*63:0*/ __Vdlyvval__top__DOT__u_regfile__DOT__rf__v0;
    // Body
    __Vdly__pc = vlSelf->pc;
    __Vdlyvset__top__DOT__u_regfile__DOT__rf__v0 = 0U;
    __Vdly__pc = (((0x6fU == (0x7fU & vlSelf->inst)) 
                   | (IData)(vlSelf->top__DOT__jalr))
                   ? vlSelf->top__DOT__br_target : 
                  (4ULL + vlSelf->pc));
    if ((1U & (~ (IData)(vlSelf->top__DOT__sd)))) {
        __Vdlyvval__top__DOT__u_regfile__DOT__rf__v0 
            = (QData)((IData)((((((- (IData)(((0x6fU 
                                               == (0x7fU 
                                                   & vlSelf->inst)) 
                                              | (IData)(vlSelf->top__DOT__jalr)))) 
                                  & ((IData)(4U) + (IData)(vlSelf->pc))) 
                                 | ((- (IData)((0x37U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->inst)))) 
                                    & (IData)(vlSelf->top__DOT__U_extension))) 
                                | ((- (IData)((0x17U 
                                               == (0x7fU 
                                                   & vlSelf->inst)))) 
                                   & ((IData)(vlSelf->pc) 
                                      + (IData)(vlSelf->top__DOT__U_extension)))) 
                               | ((- (IData)((IData)(vlSelf->top__DOT__addi))) 
                                  & (IData)(vlSelf->top__DOT__adder_result)))));
        __Vdlyvset__top__DOT__u_regfile__DOT__rf__v0 = 1U;
        __Vdlyvdim0__top__DOT__u_regfile__DOT__rf__v0 
            = (0x1fU & (vlSelf->inst >> 7U));
    }
    if (__Vdlyvset__top__DOT__u_regfile__DOT__rf__v0) {
        vlSelf->top__DOT__u_regfile__DOT__rf[__Vdlyvdim0__top__DOT__u_regfile__DOT__rf__v0] 
            = __Vdlyvval__top__DOT__u_regfile__DOT__rf__v0;
    }
    vlSelf->pc = __Vdly__pc;
}

VL_INLINE_OPT void Vtop___024root___combo__TOP__4(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__4\n"); );
    // Body
    vlSelf->top__DOT__sd = (IData)((0x3023U == (0x707fU 
                                                & vlSelf->inst)));
    vlSelf->top__DOT__U_extension = (((QData)((IData)(
                                                      (- (IData)(
                                                                 (vlSelf->inst 
                                                                  >> 0x1fU))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (0xfffff000U 
                                                                   & vlSelf->inst))));
    vlSelf->top__DOT__addi = (IData)((0x13U == (0x707fU 
                                                & vlSelf->inst)));
    vlSelf->top__DOT__jalr = (IData)((0x67U == (0x707fU 
                                                & vlSelf->inst)));
    vlSelf->top__DOT__adder_result = (((0x6fU == (0x7fU 
                                                  & vlSelf->inst))
                                        ? vlSelf->pc
                                        : (QData)((IData)(
                                                          ((0U 
                                                            == 
                                                            (0x1fU 
                                                             & (vlSelf->inst 
                                                                >> 0xfU)))
                                                            ? 0ULL
                                                            : 
                                                           vlSelf->top__DOT__u_regfile__DOT__rf
                                                           [
                                                           (0x1fU 
                                                            & (vlSelf->inst 
                                                               >> 0xfU))])))) 
                                      + (((((- (QData)((IData)(
                                                               ((IData)(vlSelf->top__DOT__addi) 
                                                                | (IData)(vlSelf->top__DOT__jalr))))) 
                                            & (((- (QData)((IData)(
                                                                   (vlSelf->inst 
                                                                    >> 0x1fU)))) 
                                                << 0xcU) 
                                               | (QData)((IData)(
                                                                 (vlSelf->inst 
                                                                  >> 0x14U))))) 
                                           | ((- (QData)((IData)(vlSelf->top__DOT__sd))) 
                                              & (((- (QData)((IData)(
                                                                     (vlSelf->inst 
                                                                      >> 0x1fU)))) 
                                                  << 0xcU) 
                                                 | (QData)((IData)(
                                                                   ((0xfe0U 
                                                                     & (vlSelf->inst 
                                                                        >> 0x14U)) 
                                                                    | (0x1fU 
                                                                       & (vlSelf->inst 
                                                                          >> 7U)))))))) 
                                          | ((- (QData)((IData)(
                                                                (0x6fU 
                                                                 == 
                                                                 (0x7fU 
                                                                  & vlSelf->inst))))) 
                                             & vlSelf->top__DOT__J_extension)) 
                                         | ((- (QData)((IData)(
                                                               ((0x17U 
                                                                 == 
                                                                 (0x7fU 
                                                                  & vlSelf->inst)) 
                                                                | (0x37U 
                                                                   == 
                                                                   (0x7fU 
                                                                    & vlSelf->inst)))))) 
                                            & vlSelf->top__DOT__U_extension)));
    vlSelf->top__DOT__br_target = ((0x6fU == (0x7fU 
                                              & vlSelf->inst))
                                    ? (vlSelf->pc + vlSelf->top__DOT__J_extension)
                                    : (QData)((IData)(
                                                      ((IData)(
                                                               (vlSelf->top__DOT__adder_result 
                                                                >> 1U)) 
                                                       << 1U))));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    Vtop___024root___combo__TOP__1(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    Vtop___024root___combo__TOP__4(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
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
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
