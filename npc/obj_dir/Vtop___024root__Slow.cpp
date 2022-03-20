// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop___024root.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========


void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf);

Vtop___024root::Vtop___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vtop___024root___ctor_var_reset(this);
}

void Vtop___024root::__Vconfigure(Vtop__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vtop___024root::~Vtop___024root() {
}

void Vtop___024root___settle__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__2\n"); );
    // Body
    vlSelf->top__DOT__J_extension = (((- (IData)((vlSelf->inst 
                                                  >> 0x1fU))) 
                                      << 0x14U) | (
                                                   (0xff000U 
                                                    & vlSelf->inst) 
                                                   | ((0x800U 
                                                       & (vlSelf->inst 
                                                          >> 9U)) 
                                                      | (0x7feU 
                                                         & (vlSelf->inst 
                                                            >> 0x14U)))));
    vlSelf->top__DOT__addi = (IData)((0x13U == (0x707fU 
                                                & vlSelf->inst)));
    vlSelf->top__DOT__jalr = (IData)((0x67U == (0x707fU 
                                                & vlSelf->inst)));
    vlSelf->top__DOT__sd = (IData)((0x3023U == (0x707fU 
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
                                      + (QData)((IData)(
                                                        (((((- (IData)(
                                                                       ((IData)(vlSelf->top__DOT__addi) 
                                                                        | (IData)(vlSelf->top__DOT__jalr)))) 
                                                            & (((- (IData)(
                                                                           (vlSelf->inst 
                                                                            >> 0x1fU))) 
                                                                << 0xcU) 
                                                               | (vlSelf->inst 
                                                                  >> 0x14U))) 
                                                           | ((- (IData)((IData)(vlSelf->top__DOT__sd))) 
                                                              & (((- (IData)(
                                                                             (vlSelf->inst 
                                                                              >> 0x1fU))) 
                                                                  << 0xcU) 
                                                                 | ((0xfe0U 
                                                                     & (vlSelf->inst 
                                                                        >> 0x14U)) 
                                                                    | (0x1fU 
                                                                       & (vlSelf->inst 
                                                                          >> 7U)))))) 
                                                          | ((- (IData)(
                                                                        (0x6fU 
                                                                         == 
                                                                         (0x7fU 
                                                                          & vlSelf->inst)))) 
                                                             & vlSelf->top__DOT__J_extension)) 
                                                         | (0xfffff000U 
                                                            & ((- (IData)(
                                                                          ((0x17U 
                                                                            == 
                                                                            (0x7fU 
                                                                             & vlSelf->inst)) 
                                                                           | (0x37U 
                                                                              == 
                                                                              (0x7fU 
                                                                               & vlSelf->inst))))) 
                                                               & vlSelf->inst))))));
    vlSelf->top__DOT__br_target = ((0x6fU == (0x7fU 
                                              & vlSelf->inst))
                                    ? (vlSelf->pc + (QData)((IData)(vlSelf->top__DOT__J_extension)))
                                    : (QData)((IData)(
                                                      ((IData)(
                                                               (vlSelf->top__DOT__adder_result 
                                                                >> 1U)) 
                                                       << 1U))));
}

void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__2(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

void Vtop___024root___final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___final\n"); );
}

void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->inst = VL_RAND_RESET_I(32);
    vlSelf->pc = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__J_extension = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__addi = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__jalr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sd = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__br_target = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__adder_result = VL_RAND_RESET_Q(64);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->top__DOT__u_regfile__DOT__rf[__Vi0] = VL_RAND_RESET_Q(64);
    }
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
