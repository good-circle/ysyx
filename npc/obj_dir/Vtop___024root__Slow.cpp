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

void Vtop___024root____Vdpiimwrap_top__DOT__u_regfile__DOT__set_gpr_ptr__Vdpioc2_TOP(const VlUnpacked<QData/*63:0*/, 32> &a);

void Vtop___024root___initial__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___initial__TOP__2\n"); );
    // Body
    Vtop___024root____Vdpiimwrap_top__DOT__u_regfile__DOT__set_gpr_ptr__Vdpioc2_TOP(vlSelf->top__DOT__u_regfile__DOT__rf);
}

void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    Vtop___024root___initial__TOP__2(vlSelf);
}

void Vtop___024root___settle__TOP__3(Vtop___024root* vlSelf);

void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__3(vlSelf);
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
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->pc = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__inst_2 = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__inst = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__U_extension = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__imm_extension = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__addi = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__jalr = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sd = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__sltiu = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__beq = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__bne = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__br_target = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__alu_src1 = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__alu_result = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__rf_rdata1 = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__rf_rdata2 = VL_RAND_RESET_Q(64);
    vlSelf->top__DOT__I_Type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__B_Type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__U_Type = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__aluop = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__mem_rdata = VL_RAND_RESET_Q(64);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->top__DOT__u_regfile__DOT__rf[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->__Vtask_top__DOT__u_blackbox__DOT__pmem_read__1__mem_rdata = 0;
    vlSelf->__Vtask_top__DOT__u_blackbox__DOT__pmem_read__3__mem_rdata = 0;
    for (int __Vi0=0; __Vi0<3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
