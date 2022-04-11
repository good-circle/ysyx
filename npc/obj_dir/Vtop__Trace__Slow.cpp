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
        tracep->declBit(c+120,"clk", false,-1);
        tracep->declBit(c+121,"rst", false,-1);
        tracep->declQuad(c+122,"pc", false,-1, 63,0);
        tracep->declBit(c+120,"top clk", false,-1);
        tracep->declBit(c+121,"top rst", false,-1);
        tracep->declQuad(c+122,"top pc", false,-1, 63,0);
        tracep->declQuad(c+65,"top inst_2", false,-1, 63,0);
        tracep->declBus(c+67,"top inst", false,-1, 31,0);
        tracep->declBus(c+68,"top rs2", false,-1, 4,0);
        tracep->declBus(c+69,"top rs1", false,-1, 4,0);
        tracep->declBus(c+70,"top funct3", false,-1, 2,0);
        tracep->declBus(c+71,"top rd", false,-1, 4,0);
        tracep->declBus(c+72,"top opcode", false,-1, 6,0);
        tracep->declQuad(c+73,"top I_extension", false,-1, 63,0);
        tracep->declQuad(c+75,"top S_extension", false,-1, 63,0);
        tracep->declQuad(c+77,"top B_extension", false,-1, 63,0);
        tracep->declQuad(c+79,"top U_extension", false,-1, 63,0);
        tracep->declQuad(c+81,"top J_extension", false,-1, 63,0);
        tracep->declQuad(c+83,"top imm_extension", false,-1, 63,0);
        tracep->declBit(c+85,"top addi", false,-1);
        tracep->declBit(c+86,"top auipc", false,-1);
        tracep->declBit(c+87,"top lui", false,-1);
        tracep->declBit(c+88,"top jal", false,-1);
        tracep->declBit(c+89,"top jalr", false,-1);
        tracep->declBit(c+90,"top sd", false,-1);
        tracep->declBit(c+91,"top ebreak", false,-1);
        tracep->declBit(c+92,"top sltiu", false,-1);
        tracep->declBit(c+93,"top beq", false,-1);
        tracep->declBit(c+94,"top bne", false,-1);
        tracep->declBit(c+95,"top br_taken", false,-1);
        tracep->declQuad(c+124,"top br_target", false,-1, 63,0);
        tracep->declQuad(c+96,"top alu_src1", false,-1, 63,0);
        tracep->declQuad(c+83,"top alu_src2", false,-1, 63,0);
        tracep->declQuad(c+98,"top alu_result", false,-1, 63,0);
        tracep->declBus(c+69,"top rf_raddr1", false,-1, 4,0);
        tracep->declQuad(c+100,"top rf_rdata1", false,-1, 63,0);
        tracep->declBus(c+68,"top rf_raddr2", false,-1, 4,0);
        tracep->declQuad(c+102,"top rf_rdata2", false,-1, 63,0);
        tracep->declBit(c+104,"top rf_we", false,-1);
        tracep->declBus(c+71,"top rf_waddr", false,-1, 4,0);
        tracep->declQuad(c+126,"top rf_wdata", false,-1, 63,0);
        tracep->declBit(c+105,"top I_Type", false,-1);
        tracep->declBit(c+90,"top S_Type", false,-1);
        tracep->declBit(c+106,"top B_Type", false,-1);
        tracep->declBit(c+107,"top U_Type", false,-1);
        tracep->declBit(c+88,"top J_Type", false,-1);
        tracep->declBit(c+128,"top inst_ready", false,-1);
        tracep->declBus(c+108,"top aluop", false,-1, 1,0);
        tracep->declQuad(c+129,"top mem_raddr", false,-1, 63,0);
        tracep->declBit(c+128,"top mem_read", false,-1);
        tracep->declQuad(c+129,"top mem_waddr", false,-1, 63,0);
        tracep->declQuad(c+109,"top mem_wdata", false,-1, 63,0);
        tracep->declBus(c+111,"top mem_wmask", false,-1, 7,0);
        tracep->declBit(c+128,"top mem_write", false,-1);
        tracep->declQuad(c+112,"top mem_rdata", false,-1, 63,0);
        tracep->declQuad(c+96,"top u_alu src1", false,-1, 63,0);
        tracep->declQuad(c+83,"top u_alu src2", false,-1, 63,0);
        tracep->declBus(c+108,"top u_alu aluop", false,-1, 1,0);
        tracep->declQuad(c+98,"top u_alu result", false,-1, 63,0);
        tracep->declBit(c+114,"top u_alu op_add", false,-1);
        tracep->declBit(c+115,"top u_alu op_sltu", false,-1);
        tracep->declQuad(c+116,"top u_alu add_result", false,-1, 63,0);
        tracep->declQuad(c+118,"top u_alu sltu_result", false,-1, 63,0);
        tracep->declBit(c+120,"top u_regfile clk", false,-1);
        tracep->declBus(c+69,"top u_regfile raddr1", false,-1, 4,0);
        tracep->declQuad(c+100,"top u_regfile rdata1", false,-1, 63,0);
        tracep->declBus(c+68,"top u_regfile raddr2", false,-1, 4,0);
        tracep->declQuad(c+102,"top u_regfile rdata2", false,-1, 63,0);
        tracep->declBit(c+104,"top u_regfile we", false,-1);
        tracep->declBus(c+71,"top u_regfile waddr", false,-1, 4,0);
        tracep->declQuad(c+126,"top u_regfile wdata", false,-1, 63,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+1+i*2,"top u_regfile rf", true,(i+0), 63,0);}}
        tracep->declQuad(c+129,"top u_blackbox mem_raddr", false,-1, 63,0);
        tracep->declBit(c+128,"top u_blackbox mem_read", false,-1);
        tracep->declQuad(c+112,"top u_blackbox mem_rdata", false,-1, 63,0);
        tracep->declQuad(c+129,"top u_blackbox mem_waddr", false,-1, 63,0);
        tracep->declBit(c+128,"top u_blackbox mem_write", false,-1);
        tracep->declBus(c+111,"top u_blackbox mem_wmask", false,-1, 7,0);
        tracep->declQuad(c+109,"top u_blackbox mem_wdata", false,-1, 63,0);
        tracep->declBit(c+128,"top u_blackbox inst_ready", false,-1);
        tracep->declQuad(c+122,"top u_blackbox pc", false,-1, 63,0);
        tracep->declQuad(c+65,"top u_blackbox inst_2", false,-1, 63,0);
        tracep->declBit(c+91,"top u_blackbox ebreak", false,-1);
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
        tracep->fullQData(oldp+1,(vlSelf->top__DOT__u_regfile__DOT__rf[0]),64);
        tracep->fullQData(oldp+3,(vlSelf->top__DOT__u_regfile__DOT__rf[1]),64);
        tracep->fullQData(oldp+5,(vlSelf->top__DOT__u_regfile__DOT__rf[2]),64);
        tracep->fullQData(oldp+7,(vlSelf->top__DOT__u_regfile__DOT__rf[3]),64);
        tracep->fullQData(oldp+9,(vlSelf->top__DOT__u_regfile__DOT__rf[4]),64);
        tracep->fullQData(oldp+11,(vlSelf->top__DOT__u_regfile__DOT__rf[5]),64);
        tracep->fullQData(oldp+13,(vlSelf->top__DOT__u_regfile__DOT__rf[6]),64);
        tracep->fullQData(oldp+15,(vlSelf->top__DOT__u_regfile__DOT__rf[7]),64);
        tracep->fullQData(oldp+17,(vlSelf->top__DOT__u_regfile__DOT__rf[8]),64);
        tracep->fullQData(oldp+19,(vlSelf->top__DOT__u_regfile__DOT__rf[9]),64);
        tracep->fullQData(oldp+21,(vlSelf->top__DOT__u_regfile__DOT__rf[10]),64);
        tracep->fullQData(oldp+23,(vlSelf->top__DOT__u_regfile__DOT__rf[11]),64);
        tracep->fullQData(oldp+25,(vlSelf->top__DOT__u_regfile__DOT__rf[12]),64);
        tracep->fullQData(oldp+27,(vlSelf->top__DOT__u_regfile__DOT__rf[13]),64);
        tracep->fullQData(oldp+29,(vlSelf->top__DOT__u_regfile__DOT__rf[14]),64);
        tracep->fullQData(oldp+31,(vlSelf->top__DOT__u_regfile__DOT__rf[15]),64);
        tracep->fullQData(oldp+33,(vlSelf->top__DOT__u_regfile__DOT__rf[16]),64);
        tracep->fullQData(oldp+35,(vlSelf->top__DOT__u_regfile__DOT__rf[17]),64);
        tracep->fullQData(oldp+37,(vlSelf->top__DOT__u_regfile__DOT__rf[18]),64);
        tracep->fullQData(oldp+39,(vlSelf->top__DOT__u_regfile__DOT__rf[19]),64);
        tracep->fullQData(oldp+41,(vlSelf->top__DOT__u_regfile__DOT__rf[20]),64);
        tracep->fullQData(oldp+43,(vlSelf->top__DOT__u_regfile__DOT__rf[21]),64);
        tracep->fullQData(oldp+45,(vlSelf->top__DOT__u_regfile__DOT__rf[22]),64);
        tracep->fullQData(oldp+47,(vlSelf->top__DOT__u_regfile__DOT__rf[23]),64);
        tracep->fullQData(oldp+49,(vlSelf->top__DOT__u_regfile__DOT__rf[24]),64);
        tracep->fullQData(oldp+51,(vlSelf->top__DOT__u_regfile__DOT__rf[25]),64);
        tracep->fullQData(oldp+53,(vlSelf->top__DOT__u_regfile__DOT__rf[26]),64);
        tracep->fullQData(oldp+55,(vlSelf->top__DOT__u_regfile__DOT__rf[27]),64);
        tracep->fullQData(oldp+57,(vlSelf->top__DOT__u_regfile__DOT__rf[28]),64);
        tracep->fullQData(oldp+59,(vlSelf->top__DOT__u_regfile__DOT__rf[29]),64);
        tracep->fullQData(oldp+61,(vlSelf->top__DOT__u_regfile__DOT__rf[30]),64);
        tracep->fullQData(oldp+63,(vlSelf->top__DOT__u_regfile__DOT__rf[31]),64);
        tracep->fullQData(oldp+65,(vlSelf->top__DOT__inst_2),64);
        tracep->fullIData(oldp+67,(vlSelf->top__DOT__inst),32);
        tracep->fullCData(oldp+68,((0x1fU & (vlSelf->top__DOT__inst 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+69,((0x1fU & (vlSelf->top__DOT__inst 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+70,((7U & (vlSelf->top__DOT__inst 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+71,((0x1fU & (vlSelf->top__DOT__inst 
                                             >> 7U))),5);
        tracep->fullCData(oldp+72,((0x7fU & vlSelf->top__DOT__inst)),7);
        tracep->fullQData(oldp+73,((((- (QData)((IData)(
                                                        (vlSelf->top__DOT__inst 
                                                         >> 0x1fU)))) 
                                     << 0xcU) | (QData)((IData)(
                                                                (vlSelf->top__DOT__inst 
                                                                 >> 0x14U))))),64);
        tracep->fullQData(oldp+75,((((- (QData)((IData)(
                                                        (vlSelf->top__DOT__inst 
                                                         >> 0x1fU)))) 
                                     << 0xcU) | (QData)((IData)(
                                                                ((0xfe0U 
                                                                  & (vlSelf->top__DOT__inst 
                                                                     >> 0x14U)) 
                                                                 | (0x1fU 
                                                                    & (vlSelf->top__DOT__inst 
                                                                       >> 7U))))))),64);
        tracep->fullQData(oldp+77,((((- (QData)((IData)(
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
        tracep->fullQData(oldp+79,(vlSelf->top__DOT__U_extension),64);
        tracep->fullQData(oldp+81,((((- (QData)((IData)(
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
        tracep->fullQData(oldp+83,(vlSelf->top__DOT__imm_extension),64);
        tracep->fullBit(oldp+85,(vlSelf->top__DOT__addi));
        tracep->fullBit(oldp+86,((0x17U == (0x7fU & vlSelf->top__DOT__inst))));
        tracep->fullBit(oldp+87,((0x37U == (0x7fU & vlSelf->top__DOT__inst))));
        tracep->fullBit(oldp+88,((0x6fU == (0x7fU & vlSelf->top__DOT__inst))));
        tracep->fullBit(oldp+89,(vlSelf->top__DOT__jalr));
        tracep->fullBit(oldp+90,(vlSelf->top__DOT__sd));
        tracep->fullBit(oldp+91,((0x100073U == vlSelf->top__DOT__inst)));
        tracep->fullBit(oldp+92,(vlSelf->top__DOT__sltiu));
        tracep->fullBit(oldp+93,(vlSelf->top__DOT__beq));
        tracep->fullBit(oldp+94,(vlSelf->top__DOT__bne));
        tracep->fullBit(oldp+95,(((((0x6fU == (0x7fU 
                                               & vlSelf->top__DOT__inst)) 
                                    | (IData)(vlSelf->top__DOT__jalr)) 
                                   | ((IData)(vlSelf->top__DOT__beq) 
                                      & (vlSelf->top__DOT__rf_rdata1 
                                         == vlSelf->top__DOT__rf_rdata2))) 
                                  | ((IData)(vlSelf->top__DOT__bne) 
                                     & (vlSelf->top__DOT__rf_rdata1 
                                        != vlSelf->top__DOT__rf_rdata2)))));
        tracep->fullQData(oldp+96,(vlSelf->top__DOT__alu_src1),64);
        tracep->fullQData(oldp+98,(vlSelf->top__DOT__alu_result),64);
        tracep->fullQData(oldp+100,(vlSelf->top__DOT__rf_rdata1),64);
        tracep->fullQData(oldp+102,(vlSelf->top__DOT__rf_rdata2),64);
        tracep->fullBit(oldp+104,((1U & ((~ (IData)(vlSelf->top__DOT__sd)) 
                                         & (~ (IData)(vlSelf->top__DOT__B_Type))))));
        tracep->fullBit(oldp+105,(vlSelf->top__DOT__I_Type));
        tracep->fullBit(oldp+106,(vlSelf->top__DOT__B_Type));
        tracep->fullBit(oldp+107,(vlSelf->top__DOT__U_Type));
        tracep->fullCData(oldp+108,(vlSelf->top__DOT__aluop),2);
        tracep->fullQData(oldp+109,(((IData)(vlSelf->top__DOT__I_Type)
                                      ? 0x1234567887654321ULL
                                      : ((IData)(vlSelf->top__DOT__sd)
                                          ? 0x8765432112345678ULL
                                          : ((IData)(vlSelf->top__DOT__U_Type)
                                              ? 0ULL
                                              : 0x1111111111111111ULL)))),64);
        tracep->fullCData(oldp+111,(((IData)(vlSelf->top__DOT__I_Type)
                                      ? 0x55U : ((IData)(vlSelf->top__DOT__sd)
                                                  ? 0xaaU
                                                  : 
                                                 ((IData)(vlSelf->top__DOT__U_Type)
                                                   ? 0x3cU
                                                   : 0xc3U)))),8);
        tracep->fullQData(oldp+112,(vlSelf->top__DOT__mem_rdata),64);
        tracep->fullBit(oldp+114,((1U & (IData)(vlSelf->top__DOT__aluop))));
        tracep->fullBit(oldp+115,((1U & ((IData)(vlSelf->top__DOT__aluop) 
                                         >> 1U))));
        tracep->fullQData(oldp+116,((vlSelf->top__DOT__alu_src1 
                                     + vlSelf->top__DOT__imm_extension)),64);
        tracep->fullQData(oldp+118,((QData)((IData)(
                                                    (vlSelf->top__DOT__alu_src1 
                                                     < vlSelf->top__DOT__imm_extension)))),64);
        tracep->fullBit(oldp+120,(vlSelf->clk));
        tracep->fullBit(oldp+121,(vlSelf->rst));
        tracep->fullQData(oldp+122,(vlSelf->pc),64);
        tracep->fullQData(oldp+124,(((IData)(vlSelf->top__DOT__jalr)
                                      ? (0xfffffffffffffffeULL 
                                         & vlSelf->top__DOT__alu_result)
                                      : (vlSelf->pc 
                                         + vlSelf->top__DOT__imm_extension))),64);
        tracep->fullQData(oldp+126,(((((((- (QData)((IData)(
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
        tracep->fullBit(oldp+128,((1U & (~ (IData)(vlSelf->rst)))));
        tracep->fullQData(oldp+129,(0x80001000ULL),64);
    }
}
