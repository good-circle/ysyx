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
        tracep->declBit(c+73,"clk", false,-1);
        tracep->declBus(c+74,"inst", false,-1, 31,0);
        tracep->declQuad(c+75,"pc", false,-1, 63,0);
        tracep->declBit(c+73,"top clk", false,-1);
        tracep->declBus(c+74,"top inst", false,-1, 31,0);
        tracep->declQuad(c+75,"top pc", false,-1, 63,0);
        tracep->declBus(c+77,"top funct7", false,-1, 6,0);
        tracep->declBus(c+78,"top rs2", false,-1, 4,0);
        tracep->declBus(c+79,"top rs1", false,-1, 4,0);
        tracep->declBus(c+80,"top funct3", false,-1, 2,0);
        tracep->declBus(c+81,"top rd", false,-1, 4,0);
        tracep->declBus(c+82,"top opcode", false,-1, 6,0);
        tracep->declBus(c+83,"top I_extension", false,-1, 31,0);
        tracep->declBus(c+84,"top S_extension", false,-1, 31,0);
        tracep->declBus(c+85,"top B_extension", false,-1, 31,0);
        tracep->declBus(c+86,"top U_extension", false,-1, 31,0);
        tracep->declBus(c+1,"top J_extension", false,-1, 31,0);
        tracep->declBus(c+87,"top imm_extension", false,-1, 31,0);
        tracep->declBit(c+2,"top addi", false,-1);
        tracep->declBit(c+88,"top auipc", false,-1);
        tracep->declBit(c+89,"top lui", false,-1);
        tracep->declBit(c+90,"top jal", false,-1);
        tracep->declBit(c+3,"top jalr", false,-1);
        tracep->declBit(c+4,"top sd", false,-1);
        tracep->declBit(c+91,"top br_taken", false,-1);
        tracep->declQuad(c+92,"top br_target", false,-1, 63,0);
        tracep->declQuad(c+94,"top adder_src1", false,-1, 63,0);
        tracep->declQuad(c+96,"top adder_src2", false,-1, 63,0);
        tracep->declQuad(c+5,"top adder_result", false,-1, 63,0);
        tracep->declBus(c+79,"top rf_raddr1", false,-1, 4,0);
        tracep->declBus(c+98,"top rf_rdata1", false,-1, 31,0);
        tracep->declBus(c+78,"top rf_raddr2", false,-1, 4,0);
        tracep->declBus(c+99,"top rf_rdata2", false,-1, 31,0);
        tracep->declBit(c+7,"top rf_we", false,-1);
        tracep->declBus(c+81,"top rf_waddr", false,-1, 4,0);
        tracep->declBus(c+100,"top rf_wdata", false,-1, 31,0);
        tracep->declBit(c+8,"top I_Type", false,-1);
        tracep->declBit(c+108,"top R_Type", false,-1);
        tracep->declBit(c+4,"top S_Type", false,-1);
        tracep->declBit(c+108,"top B_Type", false,-1);
        tracep->declBit(c+101,"top U_Type", false,-1);
        tracep->declBit(c+90,"top J_Type", false,-1);
        tracep->declQuad(c+94,"top u_adder src1", false,-1, 63,0);
        tracep->declQuad(c+96,"top u_adder src2", false,-1, 63,0);
        tracep->declQuad(c+5,"top u_adder result", false,-1, 63,0);
        tracep->declBit(c+73,"top u_regfile clk", false,-1);
        tracep->declBus(c+79,"top u_regfile raddr1", false,-1, 4,0);
        tracep->declQuad(c+102,"top u_regfile rdata1", false,-1, 63,0);
        tracep->declBus(c+78,"top u_regfile raddr2", false,-1, 4,0);
        tracep->declQuad(c+104,"top u_regfile rdata2", false,-1, 63,0);
        tracep->declBit(c+7,"top u_regfile we", false,-1);
        tracep->declBus(c+81,"top u_regfile waddr", false,-1, 4,0);
        tracep->declQuad(c+106,"top u_regfile wdata", false,-1, 63,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+9+i*2,"top u_regfile rf", true,(i+0), 63,0);}}
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
        tracep->fullIData(oldp+1,(vlSelf->top__DOT__J_extension),32);
        tracep->fullBit(oldp+2,(vlSelf->top__DOT__addi));
        tracep->fullBit(oldp+3,(vlSelf->top__DOT__jalr));
        tracep->fullBit(oldp+4,(vlSelf->top__DOT__sd));
        tracep->fullQData(oldp+5,(vlSelf->top__DOT__adder_result),64);
        tracep->fullBit(oldp+7,((1U & (~ (IData)(vlSelf->top__DOT__sd)))));
        tracep->fullBit(oldp+8,(((IData)(vlSelf->top__DOT__addi) 
                                 | (IData)(vlSelf->top__DOT__jalr))));
        tracep->fullQData(oldp+9,(vlSelf->top__DOT__u_regfile__DOT__rf[0]),64);
        tracep->fullQData(oldp+11,(vlSelf->top__DOT__u_regfile__DOT__rf[1]),64);
        tracep->fullQData(oldp+13,(vlSelf->top__DOT__u_regfile__DOT__rf[2]),64);
        tracep->fullQData(oldp+15,(vlSelf->top__DOT__u_regfile__DOT__rf[3]),64);
        tracep->fullQData(oldp+17,(vlSelf->top__DOT__u_regfile__DOT__rf[4]),64);
        tracep->fullQData(oldp+19,(vlSelf->top__DOT__u_regfile__DOT__rf[5]),64);
        tracep->fullQData(oldp+21,(vlSelf->top__DOT__u_regfile__DOT__rf[6]),64);
        tracep->fullQData(oldp+23,(vlSelf->top__DOT__u_regfile__DOT__rf[7]),64);
        tracep->fullQData(oldp+25,(vlSelf->top__DOT__u_regfile__DOT__rf[8]),64);
        tracep->fullQData(oldp+27,(vlSelf->top__DOT__u_regfile__DOT__rf[9]),64);
        tracep->fullQData(oldp+29,(vlSelf->top__DOT__u_regfile__DOT__rf[10]),64);
        tracep->fullQData(oldp+31,(vlSelf->top__DOT__u_regfile__DOT__rf[11]),64);
        tracep->fullQData(oldp+33,(vlSelf->top__DOT__u_regfile__DOT__rf[12]),64);
        tracep->fullQData(oldp+35,(vlSelf->top__DOT__u_regfile__DOT__rf[13]),64);
        tracep->fullQData(oldp+37,(vlSelf->top__DOT__u_regfile__DOT__rf[14]),64);
        tracep->fullQData(oldp+39,(vlSelf->top__DOT__u_regfile__DOT__rf[15]),64);
        tracep->fullQData(oldp+41,(vlSelf->top__DOT__u_regfile__DOT__rf[16]),64);
        tracep->fullQData(oldp+43,(vlSelf->top__DOT__u_regfile__DOT__rf[17]),64);
        tracep->fullQData(oldp+45,(vlSelf->top__DOT__u_regfile__DOT__rf[18]),64);
        tracep->fullQData(oldp+47,(vlSelf->top__DOT__u_regfile__DOT__rf[19]),64);
        tracep->fullQData(oldp+49,(vlSelf->top__DOT__u_regfile__DOT__rf[20]),64);
        tracep->fullQData(oldp+51,(vlSelf->top__DOT__u_regfile__DOT__rf[21]),64);
        tracep->fullQData(oldp+53,(vlSelf->top__DOT__u_regfile__DOT__rf[22]),64);
        tracep->fullQData(oldp+55,(vlSelf->top__DOT__u_regfile__DOT__rf[23]),64);
        tracep->fullQData(oldp+57,(vlSelf->top__DOT__u_regfile__DOT__rf[24]),64);
        tracep->fullQData(oldp+59,(vlSelf->top__DOT__u_regfile__DOT__rf[25]),64);
        tracep->fullQData(oldp+61,(vlSelf->top__DOT__u_regfile__DOT__rf[26]),64);
        tracep->fullQData(oldp+63,(vlSelf->top__DOT__u_regfile__DOT__rf[27]),64);
        tracep->fullQData(oldp+65,(vlSelf->top__DOT__u_regfile__DOT__rf[28]),64);
        tracep->fullQData(oldp+67,(vlSelf->top__DOT__u_regfile__DOT__rf[29]),64);
        tracep->fullQData(oldp+69,(vlSelf->top__DOT__u_regfile__DOT__rf[30]),64);
        tracep->fullQData(oldp+71,(vlSelf->top__DOT__u_regfile__DOT__rf[31]),64);
        tracep->fullBit(oldp+73,(vlSelf->clk));
        tracep->fullIData(oldp+74,(vlSelf->inst),32);
        tracep->fullQData(oldp+75,(vlSelf->pc),64);
        tracep->fullCData(oldp+77,((vlSelf->inst >> 0x19U)),7);
        tracep->fullCData(oldp+78,((0x1fU & (vlSelf->inst 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+79,((0x1fU & (vlSelf->inst 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+80,((7U & (vlSelf->inst 
                                          >> 0xcU))),3);
        tracep->fullCData(oldp+81,((0x1fU & (vlSelf->inst 
                                             >> 7U))),5);
        tracep->fullCData(oldp+82,((0x7fU & vlSelf->inst)),7);
        tracep->fullIData(oldp+83,((((- (IData)((vlSelf->inst 
                                                 >> 0x1fU))) 
                                     << 0xcU) | (vlSelf->inst 
                                                 >> 0x14U))),32);
        tracep->fullIData(oldp+84,((((- (IData)((vlSelf->inst 
                                                 >> 0x1fU))) 
                                     << 0xcU) | ((0xfe0U 
                                                  & (vlSelf->inst 
                                                     >> 0x14U)) 
                                                 | (0x1fU 
                                                    & (vlSelf->inst 
                                                       >> 7U))))),32);
        tracep->fullIData(oldp+85,((((- (IData)((vlSelf->inst 
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
        tracep->fullIData(oldp+86,((0xfffff000U & vlSelf->inst)),32);
        tracep->fullIData(oldp+87,((((((- (IData)(((IData)(vlSelf->top__DOT__addi) 
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
                                          & vlSelf->inst)))),32);
        tracep->fullBit(oldp+88,((0x17U == (0x7fU & vlSelf->inst))));
        tracep->fullBit(oldp+89,((0x37U == (0x7fU & vlSelf->inst))));
        tracep->fullBit(oldp+90,((0x6fU == (0x7fU & vlSelf->inst))));
        tracep->fullBit(oldp+91,(((0x6fU == (0x7fU 
                                             & vlSelf->inst)) 
                                  | (IData)(vlSelf->top__DOT__jalr))));
        tracep->fullQData(oldp+92,(((0x6fU == (0x7fU 
                                               & vlSelf->inst))
                                     ? (vlSelf->pc 
                                        + (QData)((IData)(vlSelf->top__DOT__J_extension)))
                                     : (QData)((IData)(
                                                       ((IData)(
                                                                (vlSelf->top__DOT__adder_result 
                                                                 >> 1U)) 
                                                        << 1U))))),64);
        tracep->fullQData(oldp+94,(((0x6fU == (0x7fU 
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
        tracep->fullQData(oldp+96,((QData)((IData)(
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
                                                          & vlSelf->inst)))))),64);
        tracep->fullIData(oldp+98,((IData)(((0U == 
                                             (0x1fU 
                                              & (vlSelf->inst 
                                                 >> 0xfU)))
                                             ? 0ULL
                                             : vlSelf->top__DOT__u_regfile__DOT__rf
                                            [(0x1fU 
                                              & (vlSelf->inst 
                                                 >> 0xfU))]))),32);
        tracep->fullIData(oldp+99,((IData)(((0U == 
                                             (0x1fU 
                                              & (vlSelf->inst 
                                                 >> 0x14U)))
                                             ? 0ULL
                                             : vlSelf->top__DOT__u_regfile__DOT__rf
                                            [(0x1fU 
                                              & (vlSelf->inst 
                                                 >> 0x14U))]))),32);
        tracep->fullIData(oldp+100,((((((- (IData)(
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
                                            + (0xfffff000U 
                                               & vlSelf->inst)))) 
                                     | ((- (IData)((IData)(vlSelf->top__DOT__addi))) 
                                        & (IData)(vlSelf->top__DOT__adder_result)))),32);
        tracep->fullBit(oldp+101,(((0x17U == (0x7fU 
                                              & vlSelf->inst)) 
                                   | (0x37U == (0x7fU 
                                                & vlSelf->inst)))));
        tracep->fullQData(oldp+102,(((0U == (0x1fU 
                                             & (vlSelf->inst 
                                                >> 0xfU)))
                                      ? 0ULL : vlSelf->top__DOT__u_regfile__DOT__rf
                                     [(0x1fU & (vlSelf->inst 
                                                >> 0xfU))])),64);
        tracep->fullQData(oldp+104,(((0U == (0x1fU 
                                             & (vlSelf->inst 
                                                >> 0x14U)))
                                      ? 0ULL : vlSelf->top__DOT__u_regfile__DOT__rf
                                     [(0x1fU & (vlSelf->inst 
                                                >> 0x14U))])),64);
        tracep->fullQData(oldp+106,((QData)((IData)(
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
        tracep->fullBit(oldp+108,(0U));
    }
}
