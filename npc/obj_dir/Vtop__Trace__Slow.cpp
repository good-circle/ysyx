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
        tracep->declBit(c+76,"clk", false,-1);
        tracep->declBit(c+77,"rst", false,-1);
        tracep->declBus(c+78,"inst", false,-1, 31,0);
        tracep->declQuad(c+79,"pc", false,-1, 63,0);
        tracep->declQuad(c+81,"address", false,-1, 63,0);
        tracep->declQuad(c+83,"data", false,-1, 63,0);
        tracep->declBit(c+85,"memwrite", false,-1);
        tracep->declBit(c+76,"top clk", false,-1);
        tracep->declBit(c+77,"top rst", false,-1);
        tracep->declBus(c+78,"top inst", false,-1, 31,0);
        tracep->declQuad(c+79,"top pc", false,-1, 63,0);
        tracep->declQuad(c+81,"top address", false,-1, 63,0);
        tracep->declQuad(c+83,"top data", false,-1, 63,0);
        tracep->declBit(c+85,"top memwrite", false,-1);
        tracep->declBus(c+86,"top rs2", false,-1, 4,0);
        tracep->declBus(c+87,"top rs1", false,-1, 4,0);
        tracep->declBus(c+88,"top funct3", false,-1, 2,0);
        tracep->declBus(c+89,"top rd", false,-1, 4,0);
        tracep->declBus(c+90,"top opcode", false,-1, 6,0);
        tracep->declQuad(c+91,"top I_extension", false,-1, 63,0);
        tracep->declQuad(c+93,"top S_extension", false,-1, 63,0);
        tracep->declQuad(c+95,"top B_extension", false,-1, 63,0);
        tracep->declQuad(c+1,"top U_extension", false,-1, 63,0);
        tracep->declQuad(c+3,"top J_extension", false,-1, 63,0);
        tracep->declQuad(c+97,"top imm_extension", false,-1, 63,0);
        tracep->declBit(c+5,"top addi", false,-1);
        tracep->declBit(c+99,"top auipc", false,-1);
        tracep->declBit(c+100,"top lui", false,-1);
        tracep->declBit(c+101,"top jal", false,-1);
        tracep->declBit(c+6,"top jalr", false,-1);
        tracep->declBit(c+7,"top sd", false,-1);
        tracep->declBit(c+102,"top br_taken", false,-1);
        tracep->declQuad(c+103,"top br_target", false,-1, 63,0);
        tracep->declQuad(c+105,"top adder_src1", false,-1, 63,0);
        tracep->declQuad(c+97,"top adder_src2", false,-1, 63,0);
        tracep->declQuad(c+8,"top adder_result", false,-1, 63,0);
        tracep->declBus(c+87,"top rf_raddr1", false,-1, 4,0);
        tracep->declQuad(c+107,"top rf_rdata1", false,-1, 63,0);
        tracep->declBus(c+86,"top rf_raddr2", false,-1, 4,0);
        tracep->declQuad(c+109,"top rf_rdata2", false,-1, 63,0);
        tracep->declBit(c+10,"top rf_we", false,-1);
        tracep->declBus(c+89,"top rf_waddr", false,-1, 4,0);
        tracep->declQuad(c+111,"top rf_wdata", false,-1, 63,0);
        tracep->declBit(c+11,"top I_Type", false,-1);
        tracep->declBit(c+7,"top S_Type", false,-1);
        tracep->declBit(c+114,"top B_Type", false,-1);
        tracep->declBit(c+113,"top U_Type", false,-1);
        tracep->declBit(c+101,"top J_Type", false,-1);
        tracep->declQuad(c+105,"top u_adder src1", false,-1, 63,0);
        tracep->declQuad(c+97,"top u_adder src2", false,-1, 63,0);
        tracep->declQuad(c+8,"top u_adder result", false,-1, 63,0);
        tracep->declBit(c+76,"top u_regfile clk", false,-1);
        tracep->declBus(c+87,"top u_regfile raddr1", false,-1, 4,0);
        tracep->declQuad(c+107,"top u_regfile rdata1", false,-1, 63,0);
        tracep->declBus(c+86,"top u_regfile raddr2", false,-1, 4,0);
        tracep->declQuad(c+109,"top u_regfile rdata2", false,-1, 63,0);
        tracep->declBit(c+10,"top u_regfile we", false,-1);
        tracep->declBus(c+89,"top u_regfile waddr", false,-1, 4,0);
        tracep->declQuad(c+111,"top u_regfile wdata", false,-1, 63,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+12+i*2,"top u_regfile rf", true,(i+0), 63,0);}}
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
        tracep->fullBit(oldp+10,((1U & (~ (IData)(vlSelf->top__DOT__sd)))));
        tracep->fullBit(oldp+11,(((IData)(vlSelf->top__DOT__addi) 
                                  | (IData)(vlSelf->top__DOT__jalr))));
        tracep->fullQData(oldp+12,(vlSelf->top__DOT__u_regfile__DOT__rf[0]),64);
        tracep->fullQData(oldp+14,(vlSelf->top__DOT__u_regfile__DOT__rf[1]),64);
        tracep->fullQData(oldp+16,(vlSelf->top__DOT__u_regfile__DOT__rf[2]),64);
        tracep->fullQData(oldp+18,(vlSelf->top__DOT__u_regfile__DOT__rf[3]),64);
        tracep->fullQData(oldp+20,(vlSelf->top__DOT__u_regfile__DOT__rf[4]),64);
        tracep->fullQData(oldp+22,(vlSelf->top__DOT__u_regfile__DOT__rf[5]),64);
        tracep->fullQData(oldp+24,(vlSelf->top__DOT__u_regfile__DOT__rf[6]),64);
        tracep->fullQData(oldp+26,(vlSelf->top__DOT__u_regfile__DOT__rf[7]),64);
        tracep->fullQData(oldp+28,(vlSelf->top__DOT__u_regfile__DOT__rf[8]),64);
        tracep->fullQData(oldp+30,(vlSelf->top__DOT__u_regfile__DOT__rf[9]),64);
        tracep->fullQData(oldp+32,(vlSelf->top__DOT__u_regfile__DOT__rf[10]),64);
        tracep->fullQData(oldp+34,(vlSelf->top__DOT__u_regfile__DOT__rf[11]),64);
        tracep->fullQData(oldp+36,(vlSelf->top__DOT__u_regfile__DOT__rf[12]),64);
        tracep->fullQData(oldp+38,(vlSelf->top__DOT__u_regfile__DOT__rf[13]),64);
        tracep->fullQData(oldp+40,(vlSelf->top__DOT__u_regfile__DOT__rf[14]),64);
        tracep->fullQData(oldp+42,(vlSelf->top__DOT__u_regfile__DOT__rf[15]),64);
        tracep->fullQData(oldp+44,(vlSelf->top__DOT__u_regfile__DOT__rf[16]),64);
        tracep->fullQData(oldp+46,(vlSelf->top__DOT__u_regfile__DOT__rf[17]),64);
        tracep->fullQData(oldp+48,(vlSelf->top__DOT__u_regfile__DOT__rf[18]),64);
        tracep->fullQData(oldp+50,(vlSelf->top__DOT__u_regfile__DOT__rf[19]),64);
        tracep->fullQData(oldp+52,(vlSelf->top__DOT__u_regfile__DOT__rf[20]),64);
        tracep->fullQData(oldp+54,(vlSelf->top__DOT__u_regfile__DOT__rf[21]),64);
        tracep->fullQData(oldp+56,(vlSelf->top__DOT__u_regfile__DOT__rf[22]),64);
        tracep->fullQData(oldp+58,(vlSelf->top__DOT__u_regfile__DOT__rf[23]),64);
        tracep->fullQData(oldp+60,(vlSelf->top__DOT__u_regfile__DOT__rf[24]),64);
        tracep->fullQData(oldp+62,(vlSelf->top__DOT__u_regfile__DOT__rf[25]),64);
        tracep->fullQData(oldp+64,(vlSelf->top__DOT__u_regfile__DOT__rf[26]),64);
        tracep->fullQData(oldp+66,(vlSelf->top__DOT__u_regfile__DOT__rf[27]),64);
        tracep->fullQData(oldp+68,(vlSelf->top__DOT__u_regfile__DOT__rf[28]),64);
        tracep->fullQData(oldp+70,(vlSelf->top__DOT__u_regfile__DOT__rf[29]),64);
        tracep->fullQData(oldp+72,(vlSelf->top__DOT__u_regfile__DOT__rf[30]),64);
        tracep->fullQData(oldp+74,(vlSelf->top__DOT__u_regfile__DOT__rf[31]),64);
        tracep->fullBit(oldp+76,(vlSelf->clk));
        tracep->fullBit(oldp+77,(vlSelf->rst));
        tracep->fullIData(oldp+78,(vlSelf->inst),32);
        tracep->fullQData(oldp+79,(vlSelf->pc),64);
        tracep->fullQData(oldp+81,(vlSelf->address),64);
        tracep->fullQData(oldp+83,(vlSelf->data),64);
        tracep->fullBit(oldp+85,(vlSelf->memwrite));
        tracep->fullCData(oldp+86,((0x1fU & (vlSelf->inst 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+87,((0x1fU & (vlSelf->inst 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+88,((7U & (vlSelf->inst 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+89,((0x1fU & (vlSelf->inst 
                                             >> 7U))),5);
        tracep->fullCData(oldp+90,((0x7fU & vlSelf->inst)),7);
        tracep->fullQData(oldp+91,((((- (QData)((IData)(
                                                        (vlSelf->inst 
                                                         >> 0x1fU)))) 
                                     << 0xcU) | (QData)((IData)(
                                                                (vlSelf->inst 
                                                                 >> 0x14U))))),64);
        tracep->fullQData(oldp+93,((((- (QData)((IData)(
                                                        (vlSelf->inst 
                                                         >> 0x1fU)))) 
                                     << 0xcU) | (QData)((IData)(
                                                                ((0xfe0U 
                                                                  & (vlSelf->inst 
                                                                     >> 0x14U)) 
                                                                 | (0x1fU 
                                                                    & (vlSelf->inst 
                                                                       >> 7U))))))),64);
        tracep->fullQData(oldp+95,((((- (QData)((IData)(
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
        tracep->fullQData(oldp+97,((((((- (QData)((IData)(
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
        tracep->fullBit(oldp+99,((0x17U == (0x7fU & vlSelf->inst))));
        tracep->fullBit(oldp+100,((0x37U == (0x7fU 
                                             & vlSelf->inst))));
        tracep->fullBit(oldp+101,((0x6fU == (0x7fU 
                                             & vlSelf->inst))));
        tracep->fullBit(oldp+102,(((0x6fU == (0x7fU 
                                              & vlSelf->inst)) 
                                   | (IData)(vlSelf->top__DOT__jalr))));
        tracep->fullQData(oldp+103,(((0x6fU == (0x7fU 
                                                & vlSelf->inst))
                                      ? (vlSelf->pc 
                                         + vlSelf->top__DOT__J_extension)
                                      : (0xfffffffffffffffeULL 
                                         & vlSelf->top__DOT__adder_result))),64);
        tracep->fullQData(oldp+105,(((0x6fU == (0x7fU 
                                                & vlSelf->inst))
                                      ? vlSelf->pc : 
                                     ((0U == (0x1fU 
                                              & (vlSelf->inst 
                                                 >> 0xfU)))
                                       ? 0ULL : vlSelf->top__DOT__u_regfile__DOT__rf
                                      [(0x1fU & (vlSelf->inst 
                                                 >> 0xfU))]))),64);
        tracep->fullQData(oldp+107,(((0U == (0x1fU 
                                             & (vlSelf->inst 
                                                >> 0xfU)))
                                      ? 0ULL : vlSelf->top__DOT__u_regfile__DOT__rf
                                     [(0x1fU & (vlSelf->inst 
                                                >> 0xfU))])),64);
        tracep->fullQData(oldp+109,(((0U == (0x1fU 
                                             & (vlSelf->inst 
                                                >> 0x14U)))
                                      ? 0ULL : vlSelf->top__DOT__u_regfile__DOT__rf
                                     [(0x1fU & (vlSelf->inst 
                                                >> 0x14U))])),64);
        tracep->fullQData(oldp+111,((((((- (QData)((IData)(
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
        tracep->fullBit(oldp+113,(((0x17U == (0x7fU 
                                              & vlSelf->inst)) 
                                   | (0x37U == (0x7fU 
                                                & vlSelf->inst)))));
        tracep->fullBit(oldp+114,(0U));
    }
}
