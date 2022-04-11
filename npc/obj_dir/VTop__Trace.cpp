// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


void VTop___024root__traceChgSub0(VTop___024root* vlSelf, VerilatedVcd* tracep);

void VTop___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep) {
    VTop___024root* const __restrict vlSelf = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        VTop___024root__traceChgSub0((&vlSymsp->TOP), tracep);
    }
}

void VTop___024root__traceChgSub0(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
            tracep->chgQData(oldp+0,(vlSelf->Top__DOT__pc),64);
            tracep->chgQData(oldp+2,(vlSelf->Top__DOT__regfile__DOT__rf[0]),64);
            tracep->chgQData(oldp+4,(vlSelf->Top__DOT__regfile__DOT__rf[1]),64);
            tracep->chgQData(oldp+6,(vlSelf->Top__DOT__regfile__DOT__rf[2]),64);
            tracep->chgQData(oldp+8,(vlSelf->Top__DOT__regfile__DOT__rf[3]),64);
            tracep->chgQData(oldp+10,(vlSelf->Top__DOT__regfile__DOT__rf[4]),64);
            tracep->chgQData(oldp+12,(vlSelf->Top__DOT__regfile__DOT__rf[5]),64);
            tracep->chgQData(oldp+14,(vlSelf->Top__DOT__regfile__DOT__rf[6]),64);
            tracep->chgQData(oldp+16,(vlSelf->Top__DOT__regfile__DOT__rf[7]),64);
            tracep->chgQData(oldp+18,(vlSelf->Top__DOT__regfile__DOT__rf[8]),64);
            tracep->chgQData(oldp+20,(vlSelf->Top__DOT__regfile__DOT__rf[9]),64);
            tracep->chgQData(oldp+22,(vlSelf->Top__DOT__regfile__DOT__rf[10]),64);
            tracep->chgQData(oldp+24,(vlSelf->Top__DOT__regfile__DOT__rf[11]),64);
            tracep->chgQData(oldp+26,(vlSelf->Top__DOT__regfile__DOT__rf[12]),64);
            tracep->chgQData(oldp+28,(vlSelf->Top__DOT__regfile__DOT__rf[13]),64);
            tracep->chgQData(oldp+30,(vlSelf->Top__DOT__regfile__DOT__rf[14]),64);
            tracep->chgQData(oldp+32,(vlSelf->Top__DOT__regfile__DOT__rf[15]),64);
            tracep->chgQData(oldp+34,(vlSelf->Top__DOT__regfile__DOT__rf[16]),64);
            tracep->chgQData(oldp+36,(vlSelf->Top__DOT__regfile__DOT__rf[17]),64);
            tracep->chgQData(oldp+38,(vlSelf->Top__DOT__regfile__DOT__rf[18]),64);
            tracep->chgQData(oldp+40,(vlSelf->Top__DOT__regfile__DOT__rf[19]),64);
            tracep->chgQData(oldp+42,(vlSelf->Top__DOT__regfile__DOT__rf[20]),64);
            tracep->chgQData(oldp+44,(vlSelf->Top__DOT__regfile__DOT__rf[21]),64);
            tracep->chgQData(oldp+46,(vlSelf->Top__DOT__regfile__DOT__rf[22]),64);
            tracep->chgQData(oldp+48,(vlSelf->Top__DOT__regfile__DOT__rf[23]),64);
            tracep->chgQData(oldp+50,(vlSelf->Top__DOT__regfile__DOT__rf[24]),64);
            tracep->chgQData(oldp+52,(vlSelf->Top__DOT__regfile__DOT__rf[25]),64);
            tracep->chgQData(oldp+54,(vlSelf->Top__DOT__regfile__DOT__rf[26]),64);
            tracep->chgQData(oldp+56,(vlSelf->Top__DOT__regfile__DOT__rf[27]),64);
            tracep->chgQData(oldp+58,(vlSelf->Top__DOT__regfile__DOT__rf[28]),64);
            tracep->chgQData(oldp+60,(vlSelf->Top__DOT__regfile__DOT__rf[29]),64);
            tracep->chgQData(oldp+62,(vlSelf->Top__DOT__regfile__DOT__rf[30]),64);
            tracep->chgQData(oldp+64,(vlSelf->Top__DOT__regfile__DOT__rf[31]),64);
        }
        if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
            tracep->chgCData(oldp+66,(vlSelf->Top__DOT__bru_io_bruop),4);
            tracep->chgQData(oldp+67,(vlSelf->Top__DOT__alu_io_src1),64);
            tracep->chgQData(oldp+69,(vlSelf->Top__DOT__alu_io_src2),64);
            tracep->chgQData(oldp+71,(vlSelf->Top__DOT__bru_io_imm),64);
            tracep->chgBit(oldp+73,(((8U == (IData)(vlSelf->Top__DOT__bru_io_bruop))
                                      ? (vlSelf->Top__DOT__alu_io_src1 
                                         >= vlSelf->Top__DOT__alu_io_src2)
                                      : ((7U == (IData)(vlSelf->Top__DOT__bru_io_bruop))
                                          ? (vlSelf->Top__DOT__alu_io_src1 
                                             < vlSelf->Top__DOT__alu_io_src2)
                                          : ((6U == (IData)(vlSelf->Top__DOT__bru_io_bruop))
                                              ? VL_GTES_IQQ(1,64,64, vlSelf->Top__DOT__alu_io_src1, vlSelf->Top__DOT__alu_io_src2)
                                              : ((5U 
                                                  == (IData)(vlSelf->Top__DOT__bru_io_bruop))
                                                  ? 
                                                 VL_LTS_IQQ(1,64,64, vlSelf->Top__DOT__alu_io_src1, vlSelf->Top__DOT__alu_io_src2)
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlSelf->Top__DOT__bru_io_bruop))
                                                   ? 
                                                  (vlSelf->Top__DOT__alu_io_src1 
                                                   != vlSelf->Top__DOT__alu_io_src2)
                                                   : 
                                                  ((3U 
                                                    == (IData)(vlSelf->Top__DOT__bru_io_bruop))
                                                    ? 
                                                   (vlSelf->Top__DOT__alu_io_src1 
                                                    == vlSelf->Top__DOT__alu_io_src2)
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlSelf->Top__DOT__bru_io_bruop)) 
                                                    | (1U 
                                                       == (IData)(vlSelf->Top__DOT__bru_io_bruop)))))))))));
            tracep->chgCData(oldp+74,(vlSelf->Top__DOT__alu_io_aluop),5);
            tracep->chgBit(oldp+75,(vlSelf->Top__DOT__alu_io_rv64));
            tracep->chgQData(oldp+76,(vlSelf->Top__DOT__alu_io_result),64);
            tracep->chgCData(oldp+78,((0x1fU & (vlSelf->Top__DOT__inst 
                                                >> 0xfU))),5);
            tracep->chgQData(oldp+79,(vlSelf->Top__DOT__regfile_rdata1),64);
            tracep->chgCData(oldp+81,((0x1fU & (vlSelf->Top__DOT__inst 
                                                >> 0x14U))),5);
            tracep->chgQData(oldp+82,(vlSelf->Top__DOT__regfile_rdata2),64);
            tracep->chgCData(oldp+84,((0x1fU & (vlSelf->Top__DOT__inst 
                                                >> 7U))),5);
            tracep->chgBit(oldp+85,(((0x37U == (0x7fU 
                                                & vlSelf->Top__DOT__inst)) 
                                     | ((0x17U == (0x7fU 
                                                   & vlSelf->Top__DOT__inst)) 
                                        | ((0x6fU == 
                                            (0x7fU 
                                             & vlSelf->Top__DOT__inst)) 
                                           | ((0x67U 
                                               == (0x707fU 
                                                   & vlSelf->Top__DOT__inst)) 
                                              | (IData)(vlSelf->Top__DOT___information_T_680)))))));
            tracep->chgBit(oldp+86,(((2U == (IData)(vlSelf->Top__DOT__fu_type)) 
                                     & (IData)(vlSelf->Top__DOT__information_8))));
            tracep->chgQData(oldp+87,(vlSelf->Top__DOT__blackbox_mem_rdata),64);
            tracep->chgBit(oldp+89,(((2U == (IData)(vlSelf->Top__DOT__fu_type)) 
                                     & (~ (IData)(vlSelf->Top__DOT__information_8)))));
            tracep->chgCData(oldp+90,(((0xbU == (IData)(vlSelf->Top__DOT__information_5))
                                        ? 0xffU : (
                                                   (8U 
                                                    == (IData)(vlSelf->Top__DOT__information_5))
                                                    ? 
                                                   ((4U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                     ? 0xf0U
                                                     : 
                                                    ((0U 
                                                      == 
                                                      (7U 
                                                       & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                      ? 0xfU
                                                      : 0U))
                                                    : (IData)(vlSelf->Top__DOT___mem_wmask_T_3)))),8);
            tracep->chgQData(oldp+91,(((0xbU == (IData)(vlSelf->Top__DOT__information_5))
                                        ? vlSelf->Top__DOT__regfile_rdata2
                                        : ((8U == (IData)(vlSelf->Top__DOT__information_5))
                                            ? (((QData)((IData)(vlSelf->Top__DOT__regfile_rdata2)) 
                                                << 0x20U) 
                                               | (QData)((IData)(vlSelf->Top__DOT__regfile_rdata2)))
                                            : ((7U 
                                                == (IData)(vlSelf->Top__DOT__information_5))
                                                ? (
                                                   ((QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                                    << 0x30U) 
                                                   | (((QData)((IData)(
                                                                       (0xffffU 
                                                                        & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                                       << 0x20U) 
                                                      | (((QData)((IData)(
                                                                          (0xffffU 
                                                                           & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                                          << 0x10U) 
                                                         | (QData)((IData)(
                                                                           (0xffffU 
                                                                            & (IData)(vlSelf->Top__DOT__regfile_rdata2)))))))
                                                : (
                                                   (6U 
                                                    == (IData)(vlSelf->Top__DOT__information_5))
                                                    ? 
                                                   (((QData)((IData)(
                                                                     (0xffU 
                                                                      & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                                     << 0x38U) 
                                                    | (((QData)((IData)(
                                                                        (0xffU 
                                                                         & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                                        << 0x30U) 
                                                       | (((QData)((IData)(
                                                                           (0xffU 
                                                                            & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                                           << 0x28U) 
                                                          | (((QData)((IData)(
                                                                              (0xffU 
                                                                               & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                                              << 0x20U) 
                                                             | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                                                 << 0x18U) 
                                                                | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                                                    << 0x10U) 
                                                                   | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                                                       << 8U) 
                                                                      | (QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(vlSelf->Top__DOT__regfile_rdata2)))))))))))
                                                    : 0ULL))))),64);
            tracep->chgQData(oldp+93,(vlSelf->Top__DOT__blackbox_inst_2),64);
            tracep->chgBit(oldp+95,((1U & (~ ((0x37U 
                                               == (0x7fU 
                                                   & vlSelf->Top__DOT__inst)) 
                                              | (IData)(vlSelf->Top__DOT___information_T_187))))));
            tracep->chgIData(oldp+96,(vlSelf->Top__DOT__inst),32);
            tracep->chgQData(oldp+97,(((vlSelf->Top__DOT__inst 
                                        >> 0x1fU) ? 0xfffffffffffffULL
                                        : 0ULL)),52);
            tracep->chgSData(oldp+99,((vlSelf->Top__DOT__inst 
                                       >> 0x14U)),12);
            tracep->chgQData(oldp+100,(((((vlSelf->Top__DOT__inst 
                                           >> 0x1fU)
                                           ? 0xfffffffffffffULL
                                           : 0ULL) 
                                         << 0xcU) | (QData)((IData)(
                                                                    (vlSelf->Top__DOT__inst 
                                                                     >> 0x14U))))),64);
            tracep->chgCData(oldp+102,((vlSelf->Top__DOT__inst 
                                        >> 0x19U)),7);
            tracep->chgQData(oldp+103,(((((vlSelf->Top__DOT__inst 
                                           >> 0x1fU)
                                           ? 0xfffffffffffffULL
                                           : 0ULL) 
                                         << 0xcU) | (QData)((IData)(
                                                                    ((0xfe0U 
                                                                      & (vlSelf->Top__DOT__inst 
                                                                         >> 0x14U)) 
                                                                     | (0x1fU 
                                                                        & (vlSelf->Top__DOT__inst 
                                                                           >> 7U))))))),64);
            tracep->chgBit(oldp+105,((1U & (vlSelf->Top__DOT__inst 
                                            >> 7U))));
            tracep->chgCData(oldp+106,((0x3fU & (vlSelf->Top__DOT__inst 
                                                 >> 0x19U))),6);
            tracep->chgCData(oldp+107,((0xfU & (vlSelf->Top__DOT__inst 
                                                >> 8U))),4);
            tracep->chgQData(oldp+108,(((((vlSelf->Top__DOT__inst 
                                           >> 0x1fU)
                                           ? 0xfffffffffffffULL
                                           : 0ULL) 
                                         << 0xcU) | (QData)((IData)(
                                                                    ((0x800U 
                                                                      & (vlSelf->Top__DOT__inst 
                                                                         << 4U)) 
                                                                     | ((0x7e0U 
                                                                         & (vlSelf->Top__DOT__inst 
                                                                            >> 0x14U)) 
                                                                        | (0x1eU 
                                                                           & (vlSelf->Top__DOT__inst 
                                                                              >> 7U)))))))),64);
            tracep->chgIData(oldp+110,(((vlSelf->Top__DOT__inst 
                                         >> 0x1fU) ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgIData(oldp+111,((vlSelf->Top__DOT__inst 
                                        >> 0xcU)),20);
            tracep->chgQData(oldp+112,((((QData)((IData)(
                                                         ((vlSelf->Top__DOT__inst 
                                                           >> 0x1fU)
                                                           ? 0xffffffffU
                                                           : 0U))) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          (0xfffff000U 
                                                           & vlSelf->Top__DOT__inst))))),64);
            tracep->chgQData(oldp+114,(((vlSelf->Top__DOT__inst 
                                         >> 0x1fU) ? 0xfffffffffffULL
                                         : 0ULL)),44);
            tracep->chgCData(oldp+116,((0xffU & (vlSelf->Top__DOT__inst 
                                                 >> 0xcU))),8);
            tracep->chgBit(oldp+117,((1U & (vlSelf->Top__DOT__inst 
                                            >> 0x14U))));
            tracep->chgSData(oldp+118,((0x3ffU & (vlSelf->Top__DOT__inst 
                                                  >> 0x15U))),10);
            tracep->chgQData(oldp+119,(vlSelf->Top__DOT__imm_j),64);
            tracep->chgBit(oldp+121,(((0x37U == (0x7fU 
                                                 & vlSelf->Top__DOT__inst)) 
                                      | (IData)(vlSelf->Top__DOT___information_T_187))));
            tracep->chgCData(oldp+122,(vlSelf->Top__DOT__information_1),3);
            tracep->chgCData(oldp+123,(vlSelf->Top__DOT__fu_type),2);
            tracep->chgCData(oldp+124,(vlSelf->Top__DOT__information_5),4);
            tracep->chgCData(oldp+125,(vlSelf->Top__DOT__information_6),2);
            tracep->chgCData(oldp+126,(vlSelf->Top__DOT__information_7),2);
            tracep->chgBit(oldp+127,(vlSelf->Top__DOT__information_8));
            tracep->chgCData(oldp+128,((7U & (IData)(vlSelf->Top__DOT__alu_io_result))),3);
            tracep->chgIData(oldp+129,((IData)((vlSelf->Top__DOT__blackbox_mem_rdata 
                                                >> 0x20U))),32);
            tracep->chgIData(oldp+130,((IData)(vlSelf->Top__DOT__blackbox_mem_rdata)),32);
            tracep->chgQData(oldp+131,(((4U == (7U 
                                                & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                         ? (QData)((IData)(
                                                           (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                            >> 0x20U)))
                                         : ((0U == 
                                             (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                             ? (QData)((IData)(vlSelf->Top__DOT__blackbox_mem_rdata))
                                             : 0ULL))),64);
            tracep->chgIData(oldp+133,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                       >> 0x3fU)))
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgIData(oldp+134,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                       >> 0x1fU)))
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgQData(oldp+135,(((4U == (7U 
                                                & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                         ? (((QData)((IData)(
                                                             ((1U 
                                                               & (IData)(
                                                                         (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                          >> 0x3fU)))
                                                               ? 0xffffffffU
                                                               : 0U))) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                               >> 0x20U))))
                                         : ((0U == 
                                             (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                             ? (((QData)((IData)(
                                                                 ((1U 
                                                                   & (IData)(
                                                                             (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                              >> 0x1fU)))
                                                                   ? 0xffffffffU
                                                                   : 0U))) 
                                                 << 0x20U) 
                                                | (QData)((IData)(vlSelf->Top__DOT__blackbox_mem_rdata)))
                                             : 0ULL))),64);
            tracep->chgSData(oldp+137,((0xffffU & (IData)(
                                                          (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                           >> 0x30U)))),16);
            tracep->chgSData(oldp+138,((0xffffU & (IData)(
                                                          (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                           >> 0x20U)))),16);
            tracep->chgSData(oldp+139,((0xffffU & (IData)(
                                                          (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                           >> 0x10U)))),16);
            tracep->chgSData(oldp+140,((0xffffU & (IData)(vlSelf->Top__DOT__blackbox_mem_rdata))),16);
            tracep->chgQData(oldp+141,(((6U == (7U 
                                                & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                         ? (QData)((IData)(
                                                           (0xffffU 
                                                            & (IData)(
                                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                       >> 0x30U)))))
                                         : ((4U == 
                                             (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                             ? (QData)((IData)(
                                                               (0xffffU 
                                                                & (IData)(
                                                                          (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                           >> 0x20U)))))
                                             : ((2U 
                                                 == 
                                                 (7U 
                                                  & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                 ? (QData)((IData)(
                                                                   (0xffffU 
                                                                    & (IData)(
                                                                              (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                               >> 0x10U)))))
                                                 : 
                                                ((0U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                  ? (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(vlSelf->Top__DOT__blackbox_mem_rdata))))
                                                  : 0ULL))))),64);
            tracep->chgQData(oldp+143,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                       >> 0x3fU)))
                                         ? 0xffffffffffffULL
                                         : 0ULL)),48);
            tracep->chgQData(oldp+145,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                       >> 0x2fU)))
                                         ? 0xffffffffffffULL
                                         : 0ULL)),48);
            tracep->chgQData(oldp+147,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                       >> 0x1fU)))
                                         ? 0xffffffffffffULL
                                         : 0ULL)),48);
            tracep->chgQData(oldp+149,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                       >> 0xfU)))
                                         ? 0xffffffffffffULL
                                         : 0ULL)),48);
            tracep->chgQData(oldp+151,(((6U == (7U 
                                                & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                         ? ((((1U & (IData)(
                                                            (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                             >> 0x3fU)))
                                               ? 0xffffffffffffULL
                                               : 0ULL) 
                                             << 0x10U) 
                                            | (QData)((IData)(
                                                              (0xffffU 
                                                               & (IData)(
                                                                         (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                          >> 0x30U))))))
                                         : ((4U == 
                                             (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                             ? ((((1U 
                                                   & (IData)(
                                                             (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                              >> 0x2fU)))
                                                   ? 0xffffffffffffULL
                                                   : 0ULL) 
                                                 << 0x10U) 
                                                | (QData)((IData)(
                                                                  (0xffffU 
                                                                   & (IData)(
                                                                             (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                              >> 0x20U))))))
                                             : ((2U 
                                                 == 
                                                 (7U 
                                                  & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                 ? 
                                                ((((1U 
                                                    & (IData)(
                                                              (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                               >> 0x1fU)))
                                                    ? 0xffffffffffffULL
                                                    : 0ULL) 
                                                  << 0x10U) 
                                                 | (QData)((IData)(
                                                                   (0xffffU 
                                                                    & (IData)(
                                                                              (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                               >> 0x10U))))))
                                                 : 
                                                ((0U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                  ? 
                                                 ((((1U 
                                                     & (IData)(
                                                               (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                >> 0xfU)))
                                                     ? 0xffffffffffffULL
                                                     : 0ULL) 
                                                   << 0x10U) 
                                                  | (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(vlSelf->Top__DOT__blackbox_mem_rdata)))))
                                                  : 0ULL))))),64);
            tracep->chgCData(oldp+153,((0xffU & (IData)(
                                                        (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                         >> 0x38U)))),8);
            tracep->chgCData(oldp+154,((0xffU & (IData)(
                                                        (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                         >> 0x30U)))),8);
            tracep->chgCData(oldp+155,((0xffU & (IData)(
                                                        (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                         >> 0x28U)))),8);
            tracep->chgCData(oldp+156,((0xffU & (IData)(
                                                        (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                         >> 0x20U)))),8);
            tracep->chgCData(oldp+157,((0xffU & (IData)(
                                                        (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                         >> 0x18U)))),8);
            tracep->chgCData(oldp+158,((0xffU & (IData)(
                                                        (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                         >> 0x10U)))),8);
            tracep->chgCData(oldp+159,((0xffU & (IData)(
                                                        (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                         >> 8U)))),8);
            tracep->chgCData(oldp+160,((0xffU & (IData)(vlSelf->Top__DOT__blackbox_mem_rdata))),8);
            tracep->chgQData(oldp+161,(((7U == (7U 
                                                & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                         ? (QData)((IData)(
                                                           (0xffU 
                                                            & (IData)(
                                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                       >> 0x38U)))))
                                         : ((6U == 
                                             (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                             ? (QData)((IData)(
                                                               (0xffU 
                                                                & (IData)(
                                                                          (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                           >> 0x30U)))))
                                             : ((5U 
                                                 == 
                                                 (7U 
                                                  & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                 ? (QData)((IData)(
                                                                   (0xffU 
                                                                    & (IData)(
                                                                              (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                               >> 0x28U)))))
                                                 : 
                                                ((4U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                  ? (QData)((IData)(
                                                                    (0xffU 
                                                                     & (IData)(
                                                                               (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                                >> 0x20U)))))
                                                  : 
                                                 ((3U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                   ? (QData)((IData)(
                                                                     (0xffU 
                                                                      & (IData)(
                                                                                (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                                >> 0x18U)))))
                                                   : 
                                                  ((2U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                    ? (QData)((IData)(
                                                                      (0xffU 
                                                                       & (IData)(
                                                                                (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                                >> 0x10U)))))
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                     ? (QData)((IData)(
                                                                       (0xffU 
                                                                        & (IData)(
                                                                                (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                                >> 8U)))))
                                                     : (QData)((IData)(
                                                                       (0xffU 
                                                                        & (IData)(vlSelf->Top__DOT__blackbox_mem_rdata)))))))))))),64);
            tracep->chgQData(oldp+163,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                       >> 0x3fU)))
                                         ? 0xffffffffffffffULL
                                         : 0ULL)),56);
            tracep->chgQData(oldp+165,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                       >> 0x37U)))
                                         ? 0xffffffffffffffULL
                                         : 0ULL)),56);
            tracep->chgQData(oldp+167,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                       >> 0x2fU)))
                                         ? 0xffffffffffffffULL
                                         : 0ULL)),56);
            tracep->chgQData(oldp+169,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                       >> 0x27U)))
                                         ? 0xffffffffffffffULL
                                         : 0ULL)),56);
            tracep->chgQData(oldp+171,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                       >> 0x1fU)))
                                         ? 0xffffffffffffffULL
                                         : 0ULL)),56);
            tracep->chgQData(oldp+173,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                       >> 0x17U)))
                                         ? 0xffffffffffffffULL
                                         : 0ULL)),56);
            tracep->chgQData(oldp+175,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                       >> 0xfU)))
                                         ? 0xffffffffffffffULL
                                         : 0ULL)),56);
            tracep->chgQData(oldp+177,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                       >> 7U)))
                                         ? 0xffffffffffffffULL
                                         : 0ULL)),56);
            tracep->chgQData(oldp+179,(((7U == (7U 
                                                & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                         ? ((((1U & (IData)(
                                                            (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                             >> 0x3fU)))
                                               ? 0xffffffffffffffULL
                                               : 0ULL) 
                                             << 8U) 
                                            | (QData)((IData)(
                                                              (0xffU 
                                                               & (IData)(
                                                                         (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                          >> 0x38U))))))
                                         : ((6U == 
                                             (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                             ? ((((1U 
                                                   & (IData)(
                                                             (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                              >> 0x37U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 << 8U) 
                                                | (QData)((IData)(
                                                                  (0xffU 
                                                                   & (IData)(
                                                                             (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                              >> 0x30U))))))
                                             : vlSelf->Top__DOT___lb_rdata_T_33))),64);
            tracep->chgQData(oldp+181,(((0xaU == (IData)(vlSelf->Top__DOT__information_5))
                                         ? vlSelf->Top__DOT__blackbox_mem_rdata
                                         : ((9U == (IData)(vlSelf->Top__DOT__information_5))
                                             ? ((4U 
                                                 == 
                                                 (7U 
                                                  & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                 ? (QData)((IData)(
                                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                    >> 0x20U)))
                                                 : 
                                                ((0U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                  ? (QData)((IData)(vlSelf->Top__DOT__blackbox_mem_rdata))
                                                  : 0ULL))
                                             : ((3U 
                                                 == (IData)(vlSelf->Top__DOT__information_5))
                                                 ? 
                                                ((4U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                  ? 
                                                 (((QData)((IData)(
                                                                   ((1U 
                                                                     & (IData)(
                                                                               (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                                >> 0x3fU)))
                                                                     ? 0xffffffffU
                                                                     : 0U))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                     >> 0x20U))))
                                                  : 
                                                 ((0U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                   ? 
                                                  (((QData)((IData)(
                                                                    ((1U 
                                                                      & (IData)(
                                                                                (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                                >> 0x1fU)))
                                                                      ? 0xffffffffU
                                                                      : 0U))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelf->Top__DOT__blackbox_mem_rdata)))
                                                   : 0ULL))
                                                 : vlSelf->Top__DOT___load_rdata_T_7)))),64);
            tracep->chgCData(oldp+183,(((7U == (7U 
                                                & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                         ? 0x80U : 
                                        ((6U == (7U 
                                                 & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                          ? 0x40U : 
                                         ((5U == (7U 
                                                  & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                           ? 0x20U : 
                                          ((4U == (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                            ? 0x10U
                                            : ((3U 
                                                == 
                                                (7U 
                                                 & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                ? 8U
                                                : (
                                                   (2U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                    ? 4U
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                     ? 2U
                                                     : 1U)))))))),8);
            tracep->chgCData(oldp+184,(((6U == (7U 
                                                & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                         ? 0xc0U : 
                                        ((4U == (7U 
                                                 & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                          ? 0x30U : 
                                         ((2U == (7U 
                                                  & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                           ? 0xcU : 
                                          ((0U == (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                            ? 3U : 0U))))),8);
            tracep->chgCData(oldp+185,(((4U == (7U 
                                                & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                         ? 0xf0U : 
                                        ((0U == (7U 
                                                 & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                          ? 0xfU : 0U))),8);
            tracep->chgCData(oldp+186,((0xffU & (IData)(vlSelf->Top__DOT__regfile_rdata2))),8);
            tracep->chgQData(oldp+187,((((QData)((IData)(
                                                         (0xffU 
                                                          & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                         << 0x38U) 
                                        | (((QData)((IData)(
                                                            (0xffU 
                                                             & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                            << 0x30U) 
                                           | (((QData)((IData)(
                                                               (0xffU 
                                                                & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                               << 0x28U) 
                                              | (((QData)((IData)(
                                                                  (0xffU 
                                                                   & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                                  << 0x20U) 
                                                 | (((QData)((IData)(
                                                                     (0xffU 
                                                                      & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                                     << 0x18U) 
                                                    | (((QData)((IData)(
                                                                        (0xffU 
                                                                         & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                                        << 0x10U) 
                                                       | (((QData)((IData)(
                                                                           (0xffU 
                                                                            & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                                           << 8U) 
                                                          | (QData)((IData)(
                                                                            (0xffU 
                                                                             & (IData)(vlSelf->Top__DOT__regfile_rdata2)))))))))))),64);
            tracep->chgSData(oldp+189,((0xffffU & (IData)(vlSelf->Top__DOT__regfile_rdata2))),16);
            tracep->chgQData(oldp+190,((((QData)((IData)(
                                                         (0xffffU 
                                                          & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                         << 0x30U) 
                                        | (((QData)((IData)(
                                                            (0xffffU 
                                                             & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                            << 0x20U) 
                                           | (((QData)((IData)(
                                                               (0xffffU 
                                                                & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                               << 0x10U) 
                                              | (QData)((IData)(
                                                                (0xffffU 
                                                                 & (IData)(vlSelf->Top__DOT__regfile_rdata2)))))))),64);
            tracep->chgIData(oldp+192,((IData)(vlSelf->Top__DOT__regfile_rdata2)),32);
            tracep->chgQData(oldp+193,((((QData)((IData)(vlSelf->Top__DOT__regfile_rdata2)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->Top__DOT__regfile_rdata2)))),64);
            tracep->chgBit(oldp+195,(vlSelf->Top__DOT__alu__DOT__srl));
            tracep->chgBit(oldp+196,(((0xaU == (IData)(vlSelf->Top__DOT__alu_io_aluop)) 
                                      & (IData)(vlSelf->Top__DOT__alu_io_rv64))));
            tracep->chgIData(oldp+197,((IData)(vlSelf->Top__DOT__alu_io_src1)),32);
            tracep->chgIData(oldp+198,(((1U & (IData)(
                                                      (vlSelf->Top__DOT__alu_io_src1 
                                                       >> 0x1fU)))
                                         ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgQData(oldp+199,(vlSelf->Top__DOT__alu__DOT__src1),64);
            tracep->chgCData(oldp+201,(vlSelf->Top__DOT__alu__DOT__shamt),6);
            tracep->chgQData(oldp+202,((((QData)((IData)(
                                                         vlSelf->Top__DOT__alu__DOT___tmp_result_T_76[1U])) 
                                         << 0x20U) 
                                        | (QData)((IData)(
                                                          vlSelf->Top__DOT__alu__DOT___tmp_result_T_76[0U])))),64);
            tracep->chgIData(oldp+204,(((vlSelf->Top__DOT__alu__DOT___tmp_result_T_76[0U] 
                                         >> 0x1fU) ? 0xffffffffU
                                         : 0U)),32);
            tracep->chgIData(oldp+205,(vlSelf->Top__DOT__alu__DOT___tmp_result_T_76[0U]),32);
        }
        tracep->chgBit(oldp+206,(vlSelf->clock));
        tracep->chgBit(oldp+207,(vlSelf->reset));
        tracep->chgQData(oldp+208,(vlSelf->io_pc),64);
        tracep->chgQData(oldp+210,(((2U == (IData)(vlSelf->Top__DOT__bru_io_bruop))
                                     ? (0xfffffffffffffffeULL 
                                        & (vlSelf->Top__DOT__alu_io_src1 
                                           + vlSelf->Top__DOT__bru_io_imm))
                                     : (vlSelf->Top__DOT__pc 
                                        + vlSelf->Top__DOT__bru_io_imm))),64);
        tracep->chgQData(oldp+212,(((2U == (IData)(vlSelf->Top__DOT__fu_type))
                                     ? ((0xaU == (IData)(vlSelf->Top__DOT__information_5))
                                         ? vlSelf->Top__DOT__blackbox_mem_rdata
                                         : ((9U == (IData)(vlSelf->Top__DOT__information_5))
                                             ? ((4U 
                                                 == 
                                                 (7U 
                                                  & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                 ? (QData)((IData)(
                                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                    >> 0x20U)))
                                                 : 
                                                ((0U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                  ? (QData)((IData)(vlSelf->Top__DOT__blackbox_mem_rdata))
                                                  : 0ULL))
                                             : ((3U 
                                                 == (IData)(vlSelf->Top__DOT__information_5))
                                                 ? 
                                                ((4U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                  ? 
                                                 (((QData)((IData)(
                                                                   ((1U 
                                                                     & (IData)(
                                                                               (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                                >> 0x3fU)))
                                                                     ? 0xffffffffU
                                                                     : 0U))) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                     >> 0x20U))))
                                                  : 
                                                 ((0U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                   ? 
                                                  (((QData)((IData)(
                                                                    ((1U 
                                                                      & (IData)(
                                                                                (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                                >> 0x1fU)))
                                                                      ? 0xffffffffU
                                                                      : 0U))) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(vlSelf->Top__DOT__blackbox_mem_rdata)))
                                                   : 0ULL))
                                                 : vlSelf->Top__DOT___load_rdata_T_7)))
                                     : ((1U == (IData)(vlSelf->Top__DOT__fu_type))
                                         ? (4ULL + vlSelf->Top__DOT__pc)
                                         : ((0U == (IData)(vlSelf->Top__DOT__fu_type))
                                             ? vlSelf->Top__DOT__alu_io_result
                                             : 0ULL)))),64);
        tracep->chgBit(oldp+214,((1U & (~ (IData)(vlSelf->reset)))));
    }
}

void VTop___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VTop___024root* const __restrict vlSelf = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
        vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    }
}
