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
            tracep->chgIData(oldp+0,(vlSelf->top__DOT__J_extension),32);
            tracep->chgBit(oldp+1,(vlSelf->top__DOT__addi));
            tracep->chgBit(oldp+2,(vlSelf->top__DOT__jalr));
            tracep->chgBit(oldp+3,(vlSelf->top__DOT__sd));
            tracep->chgQData(oldp+4,(vlSelf->top__DOT__adder_result),64);
            tracep->chgBit(oldp+6,((1U & (~ (IData)(vlSelf->top__DOT__sd)))));
            tracep->chgBit(oldp+7,(((IData)(vlSelf->top__DOT__addi) 
                                    | (IData)(vlSelf->top__DOT__jalr))));
        }
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
            tracep->chgQData(oldp+8,(vlSelf->top__DOT__u_regfile__DOT__rf[0]),64);
            tracep->chgQData(oldp+10,(vlSelf->top__DOT__u_regfile__DOT__rf[1]),64);
            tracep->chgQData(oldp+12,(vlSelf->top__DOT__u_regfile__DOT__rf[2]),64);
            tracep->chgQData(oldp+14,(vlSelf->top__DOT__u_regfile__DOT__rf[3]),64);
            tracep->chgQData(oldp+16,(vlSelf->top__DOT__u_regfile__DOT__rf[4]),64);
            tracep->chgQData(oldp+18,(vlSelf->top__DOT__u_regfile__DOT__rf[5]),64);
            tracep->chgQData(oldp+20,(vlSelf->top__DOT__u_regfile__DOT__rf[6]),64);
            tracep->chgQData(oldp+22,(vlSelf->top__DOT__u_regfile__DOT__rf[7]),64);
            tracep->chgQData(oldp+24,(vlSelf->top__DOT__u_regfile__DOT__rf[8]),64);
            tracep->chgQData(oldp+26,(vlSelf->top__DOT__u_regfile__DOT__rf[9]),64);
            tracep->chgQData(oldp+28,(vlSelf->top__DOT__u_regfile__DOT__rf[10]),64);
            tracep->chgQData(oldp+30,(vlSelf->top__DOT__u_regfile__DOT__rf[11]),64);
            tracep->chgQData(oldp+32,(vlSelf->top__DOT__u_regfile__DOT__rf[12]),64);
            tracep->chgQData(oldp+34,(vlSelf->top__DOT__u_regfile__DOT__rf[13]),64);
            tracep->chgQData(oldp+36,(vlSelf->top__DOT__u_regfile__DOT__rf[14]),64);
            tracep->chgQData(oldp+38,(vlSelf->top__DOT__u_regfile__DOT__rf[15]),64);
            tracep->chgQData(oldp+40,(vlSelf->top__DOT__u_regfile__DOT__rf[16]),64);
            tracep->chgQData(oldp+42,(vlSelf->top__DOT__u_regfile__DOT__rf[17]),64);
            tracep->chgQData(oldp+44,(vlSelf->top__DOT__u_regfile__DOT__rf[18]),64);
            tracep->chgQData(oldp+46,(vlSelf->top__DOT__u_regfile__DOT__rf[19]),64);
            tracep->chgQData(oldp+48,(vlSelf->top__DOT__u_regfile__DOT__rf[20]),64);
            tracep->chgQData(oldp+50,(vlSelf->top__DOT__u_regfile__DOT__rf[21]),64);
            tracep->chgQData(oldp+52,(vlSelf->top__DOT__u_regfile__DOT__rf[22]),64);
            tracep->chgQData(oldp+54,(vlSelf->top__DOT__u_regfile__DOT__rf[23]),64);
            tracep->chgQData(oldp+56,(vlSelf->top__DOT__u_regfile__DOT__rf[24]),64);
            tracep->chgQData(oldp+58,(vlSelf->top__DOT__u_regfile__DOT__rf[25]),64);
            tracep->chgQData(oldp+60,(vlSelf->top__DOT__u_regfile__DOT__rf[26]),64);
            tracep->chgQData(oldp+62,(vlSelf->top__DOT__u_regfile__DOT__rf[27]),64);
            tracep->chgQData(oldp+64,(vlSelf->top__DOT__u_regfile__DOT__rf[28]),64);
            tracep->chgQData(oldp+66,(vlSelf->top__DOT__u_regfile__DOT__rf[29]),64);
            tracep->chgQData(oldp+68,(vlSelf->top__DOT__u_regfile__DOT__rf[30]),64);
            tracep->chgQData(oldp+70,(vlSelf->top__DOT__u_regfile__DOT__rf[31]),64);
        }
        tracep->chgBit(oldp+72,(vlSelf->clk));
        tracep->chgIData(oldp+73,(vlSelf->inst),32);
        tracep->chgQData(oldp+74,(vlSelf->pc),64);
        tracep->chgCData(oldp+76,((vlSelf->inst >> 0x19U)),7);
        tracep->chgCData(oldp+77,((0x1fU & (vlSelf->inst 
                                            >> 0x14U))),5);
        tracep->chgCData(oldp+78,((0x1fU & (vlSelf->inst 
                                            >> 0xfU))),5);
        tracep->chgCData(oldp+79,((7U & (vlSelf->inst 
                                         >> 0xcU))),3);
        tracep->chgCData(oldp+80,((0x1fU & (vlSelf->inst 
                                            >> 7U))),5);
        tracep->chgCData(oldp+81,((0x7fU & vlSelf->inst)),7);
        tracep->chgIData(oldp+82,((((- (IData)((vlSelf->inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | (vlSelf->inst 
                                                >> 0x14U))),32);
        tracep->chgIData(oldp+83,((((- (IData)((vlSelf->inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | ((0xfe0U 
                                                 & (vlSelf->inst 
                                                    >> 0x14U)) 
                                                | (0x1fU 
                                                   & (vlSelf->inst 
                                                      >> 7U))))),32);
        tracep->chgIData(oldp+84,((((- (IData)((vlSelf->inst 
                                                >> 0x1fU))) 
                                    << 0xcU) | ((0x800U 
                                                 & (vlSelf->inst 
                                                    << 4U)) 
                                                | ((0x7e0U 
                                                    & (vlSelf->inst 
                                                       >> 0x14U)) 
                                                   | (0x1eU 
                                                      & (vlSelf->inst 
                                                         >> 7U)))))),32);
        tracep->chgIData(oldp+85,((0xfffff000U & vlSelf->inst)),32);
        tracep->chgIData(oldp+86,((((((- (IData)(((IData)(vlSelf->top__DOT__addi) 
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
                                    | ((- (IData)((0x6fU 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->inst)))) 
                                       & vlSelf->top__DOT__J_extension)) 
                                   | (0xfffff000U & 
                                      ((- (IData)((
                                                   (0x17U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->inst)) 
                                                   | (0x37U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->inst))))) 
                                       & vlSelf->inst)))),32);
        tracep->chgBit(oldp+87,((0x17U == (0x7fU & vlSelf->inst))));
        tracep->chgBit(oldp+88,((0x37U == (0x7fU & vlSelf->inst))));
        tracep->chgBit(oldp+89,((0x6fU == (0x7fU & vlSelf->inst))));
        tracep->chgBit(oldp+90,(((0x6fU == (0x7fU & vlSelf->inst)) 
                                 | (IData)(vlSelf->top__DOT__jalr))));
        tracep->chgQData(oldp+91,(((0x6fU == (0x7fU 
                                              & vlSelf->inst))
                                    ? (vlSelf->pc + (QData)((IData)(vlSelf->top__DOT__J_extension)))
                                    : (QData)((IData)(
                                                      ((IData)(
                                                               (vlSelf->top__DOT__adder_result 
                                                                >> 1U)) 
                                                       << 1U))))),64);
        tracep->chgQData(oldp+93,(((0x6fU == (0x7fU 
                                              & vlSelf->inst))
                                    ? vlSelf->pc : (QData)((IData)(
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
                                                                        >> 0xfU))]))))),64);
        tracep->chgQData(oldp+95,((QData)((IData)((
                                                   ((((- (IData)(
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
                                                         & vlSelf->inst)))))),64);
        tracep->chgIData(oldp+97,((IData)(((0U == (0x1fU 
                                                   & (vlSelf->inst 
                                                      >> 0xfU)))
                                            ? 0ULL : 
                                           vlSelf->top__DOT__u_regfile__DOT__rf
                                           [(0x1fU 
                                             & (vlSelf->inst 
                                                >> 0xfU))]))),32);
        tracep->chgIData(oldp+98,((IData)(((0U == (0x1fU 
                                                   & (vlSelf->inst 
                                                      >> 0x14U)))
                                            ? 0ULL : 
                                           vlSelf->top__DOT__u_regfile__DOT__rf
                                           [(0x1fU 
                                             & (vlSelf->inst 
                                                >> 0x14U))]))),32);
        tracep->chgIData(oldp+99,((((((- (IData)(((0x6fU 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->inst)) 
                                                  | (IData)(vlSelf->top__DOT__jalr)))) 
                                      & ((IData)(4U) 
                                         + (IData)(vlSelf->pc))) 
                                     | (0xfffff000U 
                                        & ((- (IData)(
                                                      (0x37U 
                                                       == 
                                                       (0x7fU 
                                                        & vlSelf->inst)))) 
                                           & vlSelf->inst))) 
                                    | ((- (IData)((0x17U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->inst)))) 
                                       & ((IData)(vlSelf->pc) 
                                          + (0xfffff000U 
                                             & vlSelf->inst)))) 
                                   | ((- (IData)((IData)(vlSelf->top__DOT__addi))) 
                                      & (IData)(vlSelf->top__DOT__adder_result)))),32);
        tracep->chgBit(oldp+100,(((0x17U == (0x7fU 
                                             & vlSelf->inst)) 
                                  | (0x37U == (0x7fU 
                                               & vlSelf->inst)))));
        tracep->chgQData(oldp+101,(((0U == (0x1fU & 
                                            (vlSelf->inst 
                                             >> 0xfU)))
                                     ? 0ULL : vlSelf->top__DOT__u_regfile__DOT__rf
                                    [(0x1fU & (vlSelf->inst 
                                               >> 0xfU))])),64);
        tracep->chgQData(oldp+103,(((0U == (0x1fU & 
                                            (vlSelf->inst 
                                             >> 0x14U)))
                                     ? 0ULL : vlSelf->top__DOT__u_regfile__DOT__rf
                                    [(0x1fU & (vlSelf->inst 
                                               >> 0x14U))])),64);
        tracep->chgQData(oldp+105,((QData)((IData)(
                                                   (((((- (IData)(
                                                                  ((0x6fU 
                                                                    == 
                                                                    (0x7fU 
                                                                     & vlSelf->inst)) 
                                                                   | (IData)(vlSelf->top__DOT__jalr)))) 
                                                       & ((IData)(4U) 
                                                          + (IData)(vlSelf->pc))) 
                                                      | (0xfffff000U 
                                                         & ((- (IData)(
                                                                       (0x37U 
                                                                        == 
                                                                        (0x7fU 
                                                                         & vlSelf->inst)))) 
                                                            & vlSelf->inst))) 
                                                     | ((- (IData)(
                                                                   (0x17U 
                                                                    == 
                                                                    (0x7fU 
                                                                     & vlSelf->inst)))) 
                                                        & ((IData)(vlSelf->pc) 
                                                           + 
                                                           (0xfffff000U 
                                                            & vlSelf->inst)))) 
                                                    | ((- (IData)((IData)(vlSelf->top__DOT__addi))) 
                                                       & (IData)(vlSelf->top__DOT__adder_result)))))),64);
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
        vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    }
}
