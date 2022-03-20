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
            tracep->chgQData(oldp+0,(vlSelf->top__DOT__U_extension),64);
            tracep->chgQData(oldp+2,(vlSelf->top__DOT__J_extension),64);
            tracep->chgBit(oldp+4,(vlSelf->top__DOT__addi));
            tracep->chgBit(oldp+5,(vlSelf->top__DOT__jalr));
            tracep->chgBit(oldp+6,(vlSelf->top__DOT__sd));
            tracep->chgQData(oldp+7,(vlSelf->top__DOT__adder_result),64);
            tracep->chgBit(oldp+9,((1U & (~ (IData)(vlSelf->top__DOT__sd)))));
            tracep->chgBit(oldp+10,(((IData)(vlSelf->top__DOT__addi) 
                                     | (IData)(vlSelf->top__DOT__jalr))));
        }
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
            tracep->chgQData(oldp+11,(vlSelf->top__DOT__u_regfile__DOT__rf[0]),64);
            tracep->chgQData(oldp+13,(vlSelf->top__DOT__u_regfile__DOT__rf[1]),64);
            tracep->chgQData(oldp+15,(vlSelf->top__DOT__u_regfile__DOT__rf[2]),64);
            tracep->chgQData(oldp+17,(vlSelf->top__DOT__u_regfile__DOT__rf[3]),64);
            tracep->chgQData(oldp+19,(vlSelf->top__DOT__u_regfile__DOT__rf[4]),64);
            tracep->chgQData(oldp+21,(vlSelf->top__DOT__u_regfile__DOT__rf[5]),64);
            tracep->chgQData(oldp+23,(vlSelf->top__DOT__u_regfile__DOT__rf[6]),64);
            tracep->chgQData(oldp+25,(vlSelf->top__DOT__u_regfile__DOT__rf[7]),64);
            tracep->chgQData(oldp+27,(vlSelf->top__DOT__u_regfile__DOT__rf[8]),64);
            tracep->chgQData(oldp+29,(vlSelf->top__DOT__u_regfile__DOT__rf[9]),64);
            tracep->chgQData(oldp+31,(vlSelf->top__DOT__u_regfile__DOT__rf[10]),64);
            tracep->chgQData(oldp+33,(vlSelf->top__DOT__u_regfile__DOT__rf[11]),64);
            tracep->chgQData(oldp+35,(vlSelf->top__DOT__u_regfile__DOT__rf[12]),64);
            tracep->chgQData(oldp+37,(vlSelf->top__DOT__u_regfile__DOT__rf[13]),64);
            tracep->chgQData(oldp+39,(vlSelf->top__DOT__u_regfile__DOT__rf[14]),64);
            tracep->chgQData(oldp+41,(vlSelf->top__DOT__u_regfile__DOT__rf[15]),64);
            tracep->chgQData(oldp+43,(vlSelf->top__DOT__u_regfile__DOT__rf[16]),64);
            tracep->chgQData(oldp+45,(vlSelf->top__DOT__u_regfile__DOT__rf[17]),64);
            tracep->chgQData(oldp+47,(vlSelf->top__DOT__u_regfile__DOT__rf[18]),64);
            tracep->chgQData(oldp+49,(vlSelf->top__DOT__u_regfile__DOT__rf[19]),64);
            tracep->chgQData(oldp+51,(vlSelf->top__DOT__u_regfile__DOT__rf[20]),64);
            tracep->chgQData(oldp+53,(vlSelf->top__DOT__u_regfile__DOT__rf[21]),64);
            tracep->chgQData(oldp+55,(vlSelf->top__DOT__u_regfile__DOT__rf[22]),64);
            tracep->chgQData(oldp+57,(vlSelf->top__DOT__u_regfile__DOT__rf[23]),64);
            tracep->chgQData(oldp+59,(vlSelf->top__DOT__u_regfile__DOT__rf[24]),64);
            tracep->chgQData(oldp+61,(vlSelf->top__DOT__u_regfile__DOT__rf[25]),64);
            tracep->chgQData(oldp+63,(vlSelf->top__DOT__u_regfile__DOT__rf[26]),64);
            tracep->chgQData(oldp+65,(vlSelf->top__DOT__u_regfile__DOT__rf[27]),64);
            tracep->chgQData(oldp+67,(vlSelf->top__DOT__u_regfile__DOT__rf[28]),64);
            tracep->chgQData(oldp+69,(vlSelf->top__DOT__u_regfile__DOT__rf[29]),64);
            tracep->chgQData(oldp+71,(vlSelf->top__DOT__u_regfile__DOT__rf[30]),64);
            tracep->chgQData(oldp+73,(vlSelf->top__DOT__u_regfile__DOT__rf[31]),64);
        }
        tracep->chgBit(oldp+75,(vlSelf->clk));
        tracep->chgIData(oldp+76,(vlSelf->inst),32);
        tracep->chgQData(oldp+77,(vlSelf->pc),64);
        tracep->chgCData(oldp+79,((vlSelf->inst >> 0x19U)),7);
        tracep->chgCData(oldp+80,((0x1fU & (vlSelf->inst 
                                            >> 0x14U))),5);
        tracep->chgCData(oldp+81,((0x1fU & (vlSelf->inst 
                                            >> 0xfU))),5);
        tracep->chgCData(oldp+82,((7U & (vlSelf->inst 
                                         >> 0xcU))),3);
        tracep->chgCData(oldp+83,((0x1fU & (vlSelf->inst 
                                            >> 7U))),5);
        tracep->chgCData(oldp+84,((0x7fU & vlSelf->inst)),7);
        tracep->chgQData(oldp+85,((((- (QData)((IData)(
                                                       (vlSelf->inst 
                                                        >> 0x1fU)))) 
                                    << 0xcU) | (QData)((IData)(
                                                               (vlSelf->inst 
                                                                >> 0x14U))))),64);
        tracep->chgQData(oldp+87,((((- (QData)((IData)(
                                                       (vlSelf->inst 
                                                        >> 0x1fU)))) 
                                    << 0xcU) | (QData)((IData)(
                                                               ((0xfe0U 
                                                                 & (vlSelf->inst 
                                                                    >> 0x14U)) 
                                                                | (0x1fU 
                                                                   & (vlSelf->inst 
                                                                      >> 7U))))))),64);
        tracep->chgQData(oldp+89,((((- (QData)((IData)(
                                                       (vlSelf->inst 
                                                        >> 0x1fU)))) 
                                    << 0xcU) | (QData)((IData)(
                                                               ((0x800U 
                                                                 & (vlSelf->inst 
                                                                    << 4U)) 
                                                                | ((0x7e0U 
                                                                    & (vlSelf->inst 
                                                                       >> 0x14U)) 
                                                                   | (0x1eU 
                                                                      & (vlSelf->inst 
                                                                         >> 7U)))))))),64);
        tracep->chgQData(oldp+91,((((((- (QData)((IData)(
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
                                      & vlSelf->top__DOT__U_extension))),64);
        tracep->chgBit(oldp+93,((0x17U == (0x7fU & vlSelf->inst))));
        tracep->chgBit(oldp+94,((0x37U == (0x7fU & vlSelf->inst))));
        tracep->chgBit(oldp+95,((0x6fU == (0x7fU & vlSelf->inst))));
        tracep->chgBit(oldp+96,(((0x6fU == (0x7fU & vlSelf->inst)) 
                                 | (IData)(vlSelf->top__DOT__jalr))));
        tracep->chgQData(oldp+97,(((0x6fU == (0x7fU 
                                              & vlSelf->inst))
                                    ? (vlSelf->pc + vlSelf->top__DOT__J_extension)
                                    : (0xfffffffffffffffeULL 
                                       & vlSelf->top__DOT__adder_result))),64);
        tracep->chgQData(oldp+99,(((0x6fU == (0x7fU 
                                              & vlSelf->inst))
                                    ? vlSelf->pc : 
                                   ((0U == (0x1fU & 
                                            (vlSelf->inst 
                                             >> 0xfU)))
                                     ? 0ULL : vlSelf->top__DOT__u_regfile__DOT__rf
                                    [(0x1fU & (vlSelf->inst 
                                               >> 0xfU))]))),64);
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
        tracep->chgQData(oldp+105,((((((- (QData)((IData)(
                                                          ((0x6fU 
                                                            == 
                                                            (0x7fU 
                                                             & vlSelf->inst)) 
                                                           | (IData)(vlSelf->top__DOT__jalr))))) 
                                       & (4ULL + vlSelf->pc)) 
                                      | ((- (QData)((IData)(
                                                            (0x37U 
                                                             == 
                                                             (0x7fU 
                                                              & vlSelf->inst))))) 
                                         & vlSelf->top__DOT__U_extension)) 
                                     | ((- (QData)((IData)(
                                                           (0x17U 
                                                            == 
                                                            (0x7fU 
                                                             & vlSelf->inst))))) 
                                        & (vlSelf->pc 
                                           + vlSelf->top__DOT__U_extension))) 
                                    | ((- (QData)((IData)(vlSelf->top__DOT__addi))) 
                                       & vlSelf->top__DOT__adder_result))),64);
        tracep->chgBit(oldp+107,(((0x17U == (0x7fU 
                                             & vlSelf->inst)) 
                                  | (0x37U == (0x7fU 
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
        vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    }
}
