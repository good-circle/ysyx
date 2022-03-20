// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__traceInitSub0(Vtop___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vtop___024root__traceInitTop(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vtop___024root__traceInitSub0(vlSelf, tracep);
    }
}

void Vtop___024root__traceInitSub0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+79,"clk", false,-1);
        tracep->declBit(c+80,"rst", false,-1);
        tracep->declBus(c+81,"inst", false,-1, 31,0);
        tracep->declQuad(c+82,"pc", false,-1, 63,0);
        tracep->declQuad(c+84,"address", false,-1, 63,0);
        tracep->declQuad(c+86,"data", false,-1, 63,0);
        tracep->declBit(c+88,"memwrite", false,-1);
        tracep->declQuad(c+89,"halt", false,-1, 63,0);
        tracep->declBit(c+79,"top clk", false,-1);
        tracep->declBit(c+80,"top rst", false,-1);
        tracep->declBus(c+81,"top inst", false,-1, 31,0);
        tracep->declQuad(c+82,"top pc", false,-1, 63,0);
        tracep->declQuad(c+84,"top address", false,-1, 63,0);
        tracep->declQuad(c+86,"top data", false,-1, 63,0);
        tracep->declBit(c+88,"top memwrite", false,-1);
        tracep->declQuad(c+89,"top halt", false,-1, 63,0);
        tracep->declBus(c+91,"top rs2", false,-1, 4,0);
        tracep->declBus(c+92,"top rs1", false,-1, 4,0);
        tracep->declBus(c+93,"top funct3", false,-1, 2,0);
        tracep->declBus(c+94,"top rd", false,-1, 4,0);
        tracep->declBus(c+95,"top opcode", false,-1, 6,0);
        tracep->declQuad(c+96,"top I_extension", false,-1, 63,0);
        tracep->declQuad(c+98,"top S_extension", false,-1, 63,0);
        tracep->declQuad(c+100,"top B_extension", false,-1, 63,0);
        tracep->declQuad(c+1,"top U_extension", false,-1, 63,0);
        tracep->declQuad(c+3,"top J_extension", false,-1, 63,0);
        tracep->declQuad(c+102,"top imm_extension", false,-1, 63,0);
        tracep->declBit(c+5,"top addi", false,-1);
        tracep->declBit(c+104,"top auipc", false,-1);
        tracep->declBit(c+105,"top lui", false,-1);
        tracep->declBit(c+106,"top jal", false,-1);
        tracep->declBit(c+6,"top jalr", false,-1);
        tracep->declBit(c+7,"top sd", false,-1);
        tracep->declBit(c+107,"top ebreak", false,-1);
        tracep->declBit(c+108,"top br_taken", false,-1);
        tracep->declQuad(c+109,"top br_target", false,-1, 63,0);
        tracep->declQuad(c+111,"top adder_src1", false,-1, 63,0);
        tracep->declQuad(c+102,"top adder_src2", false,-1, 63,0);
        tracep->declQuad(c+8,"top adder_result", false,-1, 63,0);
        tracep->declBus(c+10,"top rf_raddr1", false,-1, 4,0);
        tracep->declQuad(c+113,"top rf_rdata1", false,-1, 63,0);
        tracep->declBus(c+91,"top rf_raddr2", false,-1, 4,0);
        tracep->declQuad(c+11,"top rf_rdata2", false,-1, 63,0);
        tracep->declBit(c+13,"top rf_we", false,-1);
        tracep->declBus(c+94,"top rf_waddr", false,-1, 4,0);
        tracep->declQuad(c+115,"top rf_wdata", false,-1, 63,0);
        tracep->declBit(c+14,"top I_Type", false,-1);
        tracep->declBit(c+7,"top S_Type", false,-1);
        tracep->declBit(c+118,"top B_Type", false,-1);
        tracep->declBit(c+117,"top U_Type", false,-1);
        tracep->declBit(c+106,"top J_Type", false,-1);
        tracep->declQuad(c+111,"top u_adder src1", false,-1, 63,0);
        tracep->declQuad(c+102,"top u_adder src2", false,-1, 63,0);
        tracep->declQuad(c+8,"top u_adder result", false,-1, 63,0);
        tracep->declBit(c+79,"top u_regfile clk", false,-1);
        tracep->declBus(c+10,"top u_regfile raddr1", false,-1, 4,0);
        tracep->declQuad(c+113,"top u_regfile rdata1", false,-1, 63,0);
        tracep->declBus(c+91,"top u_regfile raddr2", false,-1, 4,0);
        tracep->declQuad(c+11,"top u_regfile rdata2", false,-1, 63,0);
        tracep->declBit(c+13,"top u_regfile we", false,-1);
        tracep->declBus(c+94,"top u_regfile waddr", false,-1, 4,0);
        tracep->declQuad(c+115,"top u_regfile wdata", false,-1, 63,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+15+i*2,"top u_regfile rf", true,(i+0), 63,0);}}
    }
}

void Vtop___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void Vtop___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void Vtop___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void Vtop___024root__traceRegister(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&Vtop___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&Vtop___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&Vtop___024root__traceCleanup, vlSelf);
    }
}

void Vtop___024root__traceFullSub0(Vtop___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void Vtop___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    Vtop___024root* const __restrict vlSelf = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        Vtop___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void Vtop___024root__traceFullSub0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullQData(oldp+1,(vlSelf->top__DOT__U_extension),64);
        tracep->fullQData(oldp+3,(vlSelf->top__DOT__J_extension),64);
        tracep->fullBit(oldp+5,(vlSelf->top__DOT__addi));
        tracep->fullBit(oldp+6,(vlSelf->top__DOT__jalr));
        tracep->fullBit(oldp+7,(vlSelf->top__DOT__sd));
        tracep->fullQData(oldp+8,(vlSelf->top__DOT__adder_result),64);
        tracep->fullCData(oldp+10,(vlSelf->top__DOT__rf_raddr1),5);
        tracep->fullQData(oldp+11,(vlSelf->top__DOT__rf_rdata2),64);
        tracep->fullBit(oldp+13,((1U & (~ (IData)(vlSelf->top__DOT__sd)))));
        tracep->fullBit(oldp+14,(((IData)(vlSelf->top__DOT__addi) 
                                  | (IData)(vlSelf->top__DOT__jalr))));
        tracep->fullQData(oldp+15,(vlSelf->top__DOT__u_regfile__DOT__rf[0]),64);
        tracep->fullQData(oldp+17,(vlSelf->top__DOT__u_regfile__DOT__rf[1]),64);
        tracep->fullQData(oldp+19,(vlSelf->top__DOT__u_regfile__DOT__rf[2]),64);
        tracep->fullQData(oldp+21,(vlSelf->top__DOT__u_regfile__DOT__rf[3]),64);
        tracep->fullQData(oldp+23,(vlSelf->top__DOT__u_regfile__DOT__rf[4]),64);
        tracep->fullQData(oldp+25,(vlSelf->top__DOT__u_regfile__DOT__rf[5]),64);
        tracep->fullQData(oldp+27,(vlSelf->top__DOT__u_regfile__DOT__rf[6]),64);
        tracep->fullQData(oldp+29,(vlSelf->top__DOT__u_regfile__DOT__rf[7]),64);
        tracep->fullQData(oldp+31,(vlSelf->top__DOT__u_regfile__DOT__rf[8]),64);
        tracep->fullQData(oldp+33,(vlSelf->top__DOT__u_regfile__DOT__rf[9]),64);
        tracep->fullQData(oldp+35,(vlSelf->top__DOT__u_regfile__DOT__rf[10]),64);
        tracep->fullQData(oldp+37,(vlSelf->top__DOT__u_regfile__DOT__rf[11]),64);
        tracep->fullQData(oldp+39,(vlSelf->top__DOT__u_regfile__DOT__rf[12]),64);
        tracep->fullQData(oldp+41,(vlSelf->top__DOT__u_regfile__DOT__rf[13]),64);
        tracep->fullQData(oldp+43,(vlSelf->top__DOT__u_regfile__DOT__rf[14]),64);
        tracep->fullQData(oldp+45,(vlSelf->top__DOT__u_regfile__DOT__rf[15]),64);
        tracep->fullQData(oldp+47,(vlSelf->top__DOT__u_regfile__DOT__rf[16]),64);
        tracep->fullQData(oldp+49,(vlSelf->top__DOT__u_regfile__DOT__rf[17]),64);
        tracep->fullQData(oldp+51,(vlSelf->top__DOT__u_regfile__DOT__rf[18]),64);
        tracep->fullQData(oldp+53,(vlSelf->top__DOT__u_regfile__DOT__rf[19]),64);
        tracep->fullQData(oldp+55,(vlSelf->top__DOT__u_regfile__DOT__rf[20]),64);
        tracep->fullQData(oldp+57,(vlSelf->top__DOT__u_regfile__DOT__rf[21]),64);
        tracep->fullQData(oldp+59,(vlSelf->top__DOT__u_regfile__DOT__rf[22]),64);
        tracep->fullQData(oldp+61,(vlSelf->top__DOT__u_regfile__DOT__rf[23]),64);
        tracep->fullQData(oldp+63,(vlSelf->top__DOT__u_regfile__DOT__rf[24]),64);
        tracep->fullQData(oldp+65,(vlSelf->top__DOT__u_regfile__DOT__rf[25]),64);
        tracep->fullQData(oldp+67,(vlSelf->top__DOT__u_regfile__DOT__rf[26]),64);
        tracep->fullQData(oldp+69,(vlSelf->top__DOT__u_regfile__DOT__rf[27]),64);
        tracep->fullQData(oldp+71,(vlSelf->top__DOT__u_regfile__DOT__rf[28]),64);
        tracep->fullQData(oldp+73,(vlSelf->top__DOT__u_regfile__DOT__rf[29]),64);
        tracep->fullQData(oldp+75,(vlSelf->top__DOT__u_regfile__DOT__rf[30]),64);
        tracep->fullQData(oldp+77,(vlSelf->top__DOT__u_regfile__DOT__rf[31]),64);
        tracep->fullBit(oldp+79,(vlSelf->clk));
        tracep->fullBit(oldp+80,(vlSelf->rst));
        tracep->fullIData(oldp+81,(vlSelf->inst),32);
        tracep->fullQData(oldp+82,(vlSelf->pc),64);
        tracep->fullQData(oldp+84,(vlSelf->address),64);
        tracep->fullQData(oldp+86,(vlSelf->data),64);
        tracep->fullBit(oldp+88,(vlSelf->memwrite));
        tracep->fullQData(oldp+89,(vlSelf->halt),64);
        tracep->fullCData(oldp+91,((0x1fU & (vlSelf->inst 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+92,((0x1fU & (vlSelf->inst 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+93,((7U & (vlSelf->inst 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+94,((0x1fU & (vlSelf->inst 
                                             >> 7U))),5);
        tracep->fullCData(oldp+95,((0x7fU & vlSelf->inst)),7);
        tracep->fullQData(oldp+96,((((- (QData)((IData)(
                                                        (vlSelf->inst 
                                                         >> 0x1fU)))) 
                                     << 0xcU) | (QData)((IData)(
                                                                (vlSelf->inst 
                                                                 >> 0x14U))))),64);
        tracep->fullQData(oldp+98,((((- (QData)((IData)(
                                                        (vlSelf->inst 
                                                         >> 0x1fU)))) 
                                     << 0xcU) | (QData)((IData)(
                                                                ((0xfe0U 
                                                                  & (vlSelf->inst 
                                                                     >> 0x14U)) 
                                                                 | (0x1fU 
                                                                    & (vlSelf->inst 
                                                                       >> 7U))))))),64);
        tracep->fullQData(oldp+100,((((- (QData)((IData)(
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
        tracep->fullQData(oldp+102,((((((- (QData)((IData)(
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
        tracep->fullBit(oldp+104,((0x17U == (0x7fU 
                                             & vlSelf->inst))));
        tracep->fullBit(oldp+105,((0x37U == (0x7fU 
                                             & vlSelf->inst))));
        tracep->fullBit(oldp+106,((0x6fU == (0x7fU 
                                             & vlSelf->inst))));
        tracep->fullBit(oldp+107,((0x100073U == vlSelf->inst)));
        tracep->fullBit(oldp+108,(((0x6fU == (0x7fU 
                                              & vlSelf->inst)) 
                                   | (IData)(vlSelf->top__DOT__jalr))));
        tracep->fullQData(oldp+109,(((0x6fU == (0x7fU 
                                                & vlSelf->inst))
                                      ? (vlSelf->pc 
                                         + vlSelf->top__DOT__J_extension)
                                      : (0xfffffffffffffffeULL 
                                         & vlSelf->top__DOT__adder_result))),64);
        tracep->fullQData(oldp+111,(((0x6fU == (0x7fU 
                                                & vlSelf->inst))
                                      ? vlSelf->pc : 
                                     ((0U == (IData)(vlSelf->top__DOT__rf_raddr1))
                                       ? 0ULL : vlSelf->top__DOT__u_regfile__DOT__rf
                                      [vlSelf->top__DOT__rf_raddr1]))),64);
        tracep->fullQData(oldp+113,(((0U == (IData)(vlSelf->top__DOT__rf_raddr1))
                                      ? 0ULL : vlSelf->top__DOT__u_regfile__DOT__rf
                                     [vlSelf->top__DOT__rf_raddr1])),64);
        tracep->fullQData(oldp+115,((((((- (QData)((IData)(
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
        tracep->fullBit(oldp+117,(((0x17U == (0x7fU 
                                              & vlSelf->inst)) 
                                   | (0x37U == (0x7fU 
                                                & vlSelf->inst)))));
        tracep->fullBit(oldp+118,(0U));
    }
}
