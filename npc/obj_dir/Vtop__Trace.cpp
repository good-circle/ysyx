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
            tracep->chgQData(oldp+0,(vlSelf->top__DOT__u_regfile__DOT__rf[0]),64);
            tracep->chgQData(oldp+2,(vlSelf->top__DOT__u_regfile__DOT__rf[1]),64);
            tracep->chgQData(oldp+4,(vlSelf->top__DOT__u_regfile__DOT__rf[2]),64);
            tracep->chgQData(oldp+6,(vlSelf->top__DOT__u_regfile__DOT__rf[3]),64);
            tracep->chgQData(oldp+8,(vlSelf->top__DOT__u_regfile__DOT__rf[4]),64);
            tracep->chgQData(oldp+10,(vlSelf->top__DOT__u_regfile__DOT__rf[5]),64);
            tracep->chgQData(oldp+12,(vlSelf->top__DOT__u_regfile__DOT__rf[6]),64);
            tracep->chgQData(oldp+14,(vlSelf->top__DOT__u_regfile__DOT__rf[7]),64);
            tracep->chgQData(oldp+16,(vlSelf->top__DOT__u_regfile__DOT__rf[8]),64);
            tracep->chgQData(oldp+18,(vlSelf->top__DOT__u_regfile__DOT__rf[9]),64);
            tracep->chgQData(oldp+20,(vlSelf->top__DOT__u_regfile__DOT__rf[10]),64);
            tracep->chgQData(oldp+22,(vlSelf->top__DOT__u_regfile__DOT__rf[11]),64);
            tracep->chgQData(oldp+24,(vlSelf->top__DOT__u_regfile__DOT__rf[12]),64);
            tracep->chgQData(oldp+26,(vlSelf->top__DOT__u_regfile__DOT__rf[13]),64);
            tracep->chgQData(oldp+28,(vlSelf->top__DOT__u_regfile__DOT__rf[14]),64);
            tracep->chgQData(oldp+30,(vlSelf->top__DOT__u_regfile__DOT__rf[15]),64);
            tracep->chgQData(oldp+32,(vlSelf->top__DOT__u_regfile__DOT__rf[16]),64);
            tracep->chgQData(oldp+34,(vlSelf->top__DOT__u_regfile__DOT__rf[17]),64);
            tracep->chgQData(oldp+36,(vlSelf->top__DOT__u_regfile__DOT__rf[18]),64);
            tracep->chgQData(oldp+38,(vlSelf->top__DOT__u_regfile__DOT__rf[19]),64);
            tracep->chgQData(oldp+40,(vlSelf->top__DOT__u_regfile__DOT__rf[20]),64);
            tracep->chgQData(oldp+42,(vlSelf->top__DOT__u_regfile__DOT__rf[21]),64);
            tracep->chgQData(oldp+44,(vlSelf->top__DOT__u_regfile__DOT__rf[22]),64);
            tracep->chgQData(oldp+46,(vlSelf->top__DOT__u_regfile__DOT__rf[23]),64);
            tracep->chgQData(oldp+48,(vlSelf->top__DOT__u_regfile__DOT__rf[24]),64);
            tracep->chgQData(oldp+50,(vlSelf->top__DOT__u_regfile__DOT__rf[25]),64);
            tracep->chgQData(oldp+52,(vlSelf->top__DOT__u_regfile__DOT__rf[26]),64);
            tracep->chgQData(oldp+54,(vlSelf->top__DOT__u_regfile__DOT__rf[27]),64);
            tracep->chgQData(oldp+56,(vlSelf->top__DOT__u_regfile__DOT__rf[28]),64);
            tracep->chgQData(oldp+58,(vlSelf->top__DOT__u_regfile__DOT__rf[29]),64);
            tracep->chgQData(oldp+60,(vlSelf->top__DOT__u_regfile__DOT__rf[30]),64);
            tracep->chgQData(oldp+62,(vlSelf->top__DOT__u_regfile__DOT__rf[31]),64);
        }
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
            tracep->chgQData(oldp+64,(vlSelf->top__DOT__inst_2),64);
            tracep->chgIData(oldp+66,(vlSelf->top__DOT__inst),32);
            tracep->chgCData(oldp+67,((0x1fU & (vlSelf->top__DOT__inst 
                                                >> 0x14U))),5);
            tracep->chgCData(oldp+68,((0x1fU & (vlSelf->top__DOT__inst 
                                                >> 0xfU))),5);
            tracep->chgCData(oldp+69,((7U & (vlSelf->top__DOT__inst 
                                             >> 0xcU))),3);
            tracep->chgCData(oldp+70,((0x1fU & (vlSelf->top__DOT__inst 
                                                >> 7U))),5);
            tracep->chgCData(oldp+71,((0x7fU & vlSelf->top__DOT__inst)),7);
            tracep->chgQData(oldp+72,((((- (QData)((IData)(
                                                           (vlSelf->top__DOT__inst 
                                                            >> 0x1fU)))) 
                                        << 0xcU) | (QData)((IData)(
                                                                   (vlSelf->top__DOT__inst 
                                                                    >> 0x14U))))),64);
            tracep->chgQData(oldp+74,((((- (QData)((IData)(
                                                           (vlSelf->top__DOT__inst 
                                                            >> 0x1fU)))) 
                                        << 0xcU) | (QData)((IData)(
                                                                   ((0xfe0U 
                                                                     & (vlSelf->top__DOT__inst 
                                                                        >> 0x14U)) 
                                                                    | (0x1fU 
                                                                       & (vlSelf->top__DOT__inst 
                                                                          >> 7U))))))),64);
            tracep->chgQData(oldp+76,((((- (QData)((IData)(
                                                           (vlSelf->top__DOT__inst 
                                                            >> 0x1fU)))) 
                                        << 0xcU) | (QData)((IData)(
                                                                   ((0x800U 
                                                                     & (vlSelf->top__DOT__inst 
                                                                        << 4U)) 
                                                                    | ((0x7e0U 
                                                                        & (vlSelf->top__DOT__inst 
                                                                           >> 0x14U)) 
                                                                       | (0x1eU 
                                                                          & (vlSelf->top__DOT__inst 
                                                                             >> 7U)))))))),64);
            tracep->chgQData(oldp+78,(vlSelf->top__DOT__U_extension),64);
            tracep->chgQData(oldp+80,((((- (QData)((IData)(
                                                           (vlSelf->top__DOT__inst 
                                                            >> 0x1fU)))) 
                                        << 0x14U) | (QData)((IData)(
                                                                    ((0xff000U 
                                                                      & vlSelf->top__DOT__inst) 
                                                                     | ((0x800U 
                                                                         & (vlSelf->top__DOT__inst 
                                                                            >> 9U)) 
                                                                        | (0x7feU 
                                                                           & (vlSelf->top__DOT__inst 
                                                                              >> 0x14U)))))))),64);
            tracep->chgQData(oldp+82,(vlSelf->top__DOT__imm_extension),64);
            tracep->chgBit(oldp+84,(vlSelf->top__DOT__addi));
            tracep->chgBit(oldp+85,((0x17U == (0x7fU 
                                               & vlSelf->top__DOT__inst))));
            tracep->chgBit(oldp+86,((0x37U == (0x7fU 
                                               & vlSelf->top__DOT__inst))));
            tracep->chgBit(oldp+87,((0x6fU == (0x7fU 
                                               & vlSelf->top__DOT__inst))));
            tracep->chgBit(oldp+88,(vlSelf->top__DOT__jalr));
            tracep->chgBit(oldp+89,(vlSelf->top__DOT__sd));
            tracep->chgBit(oldp+90,((0x100073U == vlSelf->top__DOT__inst)));
            tracep->chgBit(oldp+91,(vlSelf->top__DOT__sltiu));
            tracep->chgBit(oldp+92,(vlSelf->top__DOT__beq));
            tracep->chgBit(oldp+93,(vlSelf->top__DOT__bne));
            tracep->chgBit(oldp+94,(((((0x6fU == (0x7fU 
                                                  & vlSelf->top__DOT__inst)) 
                                       | (IData)(vlSelf->top__DOT__jalr)) 
                                      | ((IData)(vlSelf->top__DOT__beq) 
                                         & (vlSelf->top__DOT__rf_rdata1 
                                            == vlSelf->top__DOT__rf_rdata2))) 
                                     | ((IData)(vlSelf->top__DOT__bne) 
                                        & (vlSelf->top__DOT__rf_rdata1 
                                           != vlSelf->top__DOT__rf_rdata2)))));
            tracep->chgQData(oldp+95,(vlSelf->top__DOT__alu_src1),64);
            tracep->chgQData(oldp+97,(vlSelf->top__DOT__alu_result),64);
            tracep->chgQData(oldp+99,(vlSelf->top__DOT__rf_rdata1),64);
            tracep->chgQData(oldp+101,(vlSelf->top__DOT__rf_rdata2),64);
            tracep->chgBit(oldp+103,((1U & ((~ (IData)(vlSelf->top__DOT__sd)) 
                                            & (~ (IData)(vlSelf->top__DOT__B_Type))))));
            tracep->chgBit(oldp+104,(vlSelf->top__DOT__I_Type));
            tracep->chgBit(oldp+105,(vlSelf->top__DOT__B_Type));
            tracep->chgBit(oldp+106,(vlSelf->top__DOT__U_Type));
            tracep->chgCData(oldp+107,(vlSelf->top__DOT__aluop),2);
            tracep->chgQData(oldp+108,(((IData)(vlSelf->top__DOT__I_Type)
                                         ? 0x1234567887654321ULL
                                         : ((IData)(vlSelf->top__DOT__sd)
                                             ? 0x8765432112345678ULL
                                             : ((IData)(vlSelf->top__DOT__U_Type)
                                                 ? 0ULL
                                                 : 0x1111111111111111ULL)))),64);
            tracep->chgCData(oldp+110,(((IData)(vlSelf->top__DOT__I_Type)
                                         ? 0x55U : 
                                        ((IData)(vlSelf->top__DOT__sd)
                                          ? 0xaaU : 
                                         ((IData)(vlSelf->top__DOT__U_Type)
                                           ? 0x3cU : 0xc3U)))),8);
            tracep->chgQData(oldp+111,(vlSelf->top__DOT__mem_rdata),64);
            tracep->chgBit(oldp+113,((1U & (IData)(vlSelf->top__DOT__aluop))));
            tracep->chgBit(oldp+114,((1U & ((IData)(vlSelf->top__DOT__aluop) 
                                            >> 1U))));
            tracep->chgQData(oldp+115,((vlSelf->top__DOT__alu_src1 
                                        + vlSelf->top__DOT__imm_extension)),64);
            tracep->chgQData(oldp+117,((QData)((IData)(
                                                       (vlSelf->top__DOT__alu_src1 
                                                        < vlSelf->top__DOT__imm_extension)))),64);
        }
        tracep->chgBit(oldp+119,(vlSelf->clk));
        tracep->chgBit(oldp+120,(vlSelf->rst));
        tracep->chgQData(oldp+121,(vlSelf->pc),64);
        tracep->chgQData(oldp+123,(((IData)(vlSelf->top__DOT__jalr)
                                     ? (0xfffffffffffffffeULL 
                                        & vlSelf->top__DOT__alu_result)
                                     : (vlSelf->pc 
                                        + vlSelf->top__DOT__imm_extension))),64);
        tracep->chgQData(oldp+125,(((((((- (QData)((IData)(
                                                           ((0x6fU 
                                                             == 
                                                             (0x7fU 
                                                              & vlSelf->top__DOT__inst)) 
                                                            | (IData)(vlSelf->top__DOT__jalr))))) 
                                        & (4ULL + vlSelf->pc)) 
                                       | ((- (QData)((IData)(
                                                             (0x37U 
                                                              == 
                                                              (0x7fU 
                                                               & vlSelf->top__DOT__inst))))) 
                                          & vlSelf->top__DOT__U_extension)) 
                                      | ((- (QData)((IData)(
                                                            (0x17U 
                                                             == 
                                                             (0x7fU 
                                                              & vlSelf->top__DOT__inst))))) 
                                         & (vlSelf->pc 
                                            + vlSelf->top__DOT__U_extension))) 
                                     | ((- (QData)((IData)(vlSelf->top__DOT__addi))) 
                                        & vlSelf->top__DOT__alu_result)) 
                                    | ((- (QData)((IData)(vlSelf->top__DOT__sltiu))) 
                                       & vlSelf->top__DOT__alu_result))),64);
        tracep->chgBit(oldp+127,((1U & (~ (IData)(vlSelf->rst)))));
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
