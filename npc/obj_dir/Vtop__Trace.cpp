// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__traceChgSub0(Vtop___024root* vlSelf, VerilatedVcd* tracep);

void Vtop___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vtop___024root* const __restrict vlSelf = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        Vtop___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void Vtop___024root__traceChgSub0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+0,(((0U == (IData)(vlSelf->top__DOT__rf_raddr1))
                                       ? 0U : vlSelf->top__DOT__u_regfile__DOT__rf
                                      [vlSelf->top__DOT__rf_raddr1])),32);
            tracep->chgIData(oldp+1,(((0U == (IData)(vlSelf->top__DOT__rf_raddr2))
                                       ? 0U : vlSelf->top__DOT__u_regfile__DOT__rf
                                      [vlSelf->top__DOT__rf_raddr2])),32);
            tracep->chgIData(oldp+2,(vlSelf->top__DOT__u_regfile__DOT__rf[0]),32);
            tracep->chgIData(oldp+3,(vlSelf->top__DOT__u_regfile__DOT__rf[1]),32);
            tracep->chgIData(oldp+4,(vlSelf->top__DOT__u_regfile__DOT__rf[2]),32);
            tracep->chgIData(oldp+5,(vlSelf->top__DOT__u_regfile__DOT__rf[3]),32);
            tracep->chgIData(oldp+6,(vlSelf->top__DOT__u_regfile__DOT__rf[4]),32);
            tracep->chgIData(oldp+7,(vlSelf->top__DOT__u_regfile__DOT__rf[5]),32);
            tracep->chgIData(oldp+8,(vlSelf->top__DOT__u_regfile__DOT__rf[6]),32);
            tracep->chgIData(oldp+9,(vlSelf->top__DOT__u_regfile__DOT__rf[7]),32);
            tracep->chgIData(oldp+10,(vlSelf->top__DOT__u_regfile__DOT__rf[8]),32);
            tracep->chgIData(oldp+11,(vlSelf->top__DOT__u_regfile__DOT__rf[9]),32);
            tracep->chgIData(oldp+12,(vlSelf->top__DOT__u_regfile__DOT__rf[10]),32);
            tracep->chgIData(oldp+13,(vlSelf->top__DOT__u_regfile__DOT__rf[11]),32);
            tracep->chgIData(oldp+14,(vlSelf->top__DOT__u_regfile__DOT__rf[12]),32);
            tracep->chgIData(oldp+15,(vlSelf->top__DOT__u_regfile__DOT__rf[13]),32);
            tracep->chgIData(oldp+16,(vlSelf->top__DOT__u_regfile__DOT__rf[14]),32);
            tracep->chgIData(oldp+17,(vlSelf->top__DOT__u_regfile__DOT__rf[15]),32);
            tracep->chgIData(oldp+18,(vlSelf->top__DOT__u_regfile__DOT__rf[16]),32);
            tracep->chgIData(oldp+19,(vlSelf->top__DOT__u_regfile__DOT__rf[17]),32);
            tracep->chgIData(oldp+20,(vlSelf->top__DOT__u_regfile__DOT__rf[18]),32);
            tracep->chgIData(oldp+21,(vlSelf->top__DOT__u_regfile__DOT__rf[19]),32);
            tracep->chgIData(oldp+22,(vlSelf->top__DOT__u_regfile__DOT__rf[20]),32);
            tracep->chgIData(oldp+23,(vlSelf->top__DOT__u_regfile__DOT__rf[21]),32);
            tracep->chgIData(oldp+24,(vlSelf->top__DOT__u_regfile__DOT__rf[22]),32);
            tracep->chgIData(oldp+25,(vlSelf->top__DOT__u_regfile__DOT__rf[23]),32);
            tracep->chgIData(oldp+26,(vlSelf->top__DOT__u_regfile__DOT__rf[24]),32);
            tracep->chgIData(oldp+27,(vlSelf->top__DOT__u_regfile__DOT__rf[25]),32);
            tracep->chgIData(oldp+28,(vlSelf->top__DOT__u_regfile__DOT__rf[26]),32);
            tracep->chgIData(oldp+29,(vlSelf->top__DOT__u_regfile__DOT__rf[27]),32);
            tracep->chgIData(oldp+30,(vlSelf->top__DOT__u_regfile__DOT__rf[28]),32);
            tracep->chgIData(oldp+31,(vlSelf->top__DOT__u_regfile__DOT__rf[29]),32);
            tracep->chgIData(oldp+32,(vlSelf->top__DOT__u_regfile__DOT__rf[30]),32);
            tracep->chgIData(oldp+33,(vlSelf->top__DOT__u_regfile__DOT__rf[31]),32);
        }
        tracep->chgBit(oldp+34,(vlSelf->clk));
        tracep->chgIData(oldp+35,(vlSelf->inst),32);
        tracep->chgIData(oldp+36,(vlSelf->pc),32);
        tracep->chgBit(oldp+37,(vlSelf->a));
        tracep->chgBit(oldp+38,((IData)((0x13U == (0x707fU 
                                                   & vlSelf->inst)))));
    }
}

void Vtop___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    Vtop___024root* const __restrict vlSelf = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    }
}
