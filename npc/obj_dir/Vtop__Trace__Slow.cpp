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
        tracep->declBit(c+35,"clk", false,-1);
        tracep->declBus(c+36,"inst", false,-1, 31,0);
        tracep->declBus(c+37,"pc", false,-1, 31,0);
        tracep->declBit(c+38,"a", false,-1);
        tracep->declBit(c+35,"top clk", false,-1);
        tracep->declBus(c+36,"top inst", false,-1, 31,0);
        tracep->declBus(c+37,"top pc", false,-1, 31,0);
        tracep->declBit(c+38,"top a", false,-1);
        tracep->declBit(c+39,"top addi", false,-1);
        tracep->declBus(c+40,"top rf_raddr1", false,-1, 4,0);
        tracep->declBus(c+1,"top rf_rdata1", false,-1, 31,0);
        tracep->declBus(c+41,"top rf_raddr2", false,-1, 4,0);
        tracep->declBus(c+2,"top rf_rdata2", false,-1, 31,0);
        tracep->declBit(c+42,"top rf_we", false,-1);
        tracep->declBus(c+43,"top rf_waddr", false,-1, 4,0);
        tracep->declBus(c+44,"top rf_wdata", false,-1, 31,0);
        tracep->declBit(c+35,"top u_regfile clk", false,-1);
        tracep->declBus(c+40,"top u_regfile raddr1", false,-1, 4,0);
        tracep->declBus(c+1,"top u_regfile rdata1", false,-1, 31,0);
        tracep->declBus(c+41,"top u_regfile raddr2", false,-1, 4,0);
        tracep->declBus(c+2,"top u_regfile rdata2", false,-1, 31,0);
        tracep->declBit(c+42,"top u_regfile we", false,-1);
        tracep->declBus(c+43,"top u_regfile waddr", false,-1, 4,0);
        tracep->declBus(c+44,"top u_regfile wdata", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+3+i*1,"top u_regfile rf", true,(i+0), 31,0);}}
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
        tracep->fullIData(oldp+1,(((0U == (IData)(vlSelf->top__DOT__rf_raddr1))
                                    ? 0U : vlSelf->top__DOT__u_regfile__DOT__rf
                                   [vlSelf->top__DOT__rf_raddr1])),32);
        tracep->fullIData(oldp+2,(((0U == (IData)(vlSelf->top__DOT__rf_raddr2))
                                    ? 0U : vlSelf->top__DOT__u_regfile__DOT__rf
                                   [vlSelf->top__DOT__rf_raddr2])),32);
        tracep->fullIData(oldp+3,(vlSelf->top__DOT__u_regfile__DOT__rf[0]),32);
        tracep->fullIData(oldp+4,(vlSelf->top__DOT__u_regfile__DOT__rf[1]),32);
        tracep->fullIData(oldp+5,(vlSelf->top__DOT__u_regfile__DOT__rf[2]),32);
        tracep->fullIData(oldp+6,(vlSelf->top__DOT__u_regfile__DOT__rf[3]),32);
        tracep->fullIData(oldp+7,(vlSelf->top__DOT__u_regfile__DOT__rf[4]),32);
        tracep->fullIData(oldp+8,(vlSelf->top__DOT__u_regfile__DOT__rf[5]),32);
        tracep->fullIData(oldp+9,(vlSelf->top__DOT__u_regfile__DOT__rf[6]),32);
        tracep->fullIData(oldp+10,(vlSelf->top__DOT__u_regfile__DOT__rf[7]),32);
        tracep->fullIData(oldp+11,(vlSelf->top__DOT__u_regfile__DOT__rf[8]),32);
        tracep->fullIData(oldp+12,(vlSelf->top__DOT__u_regfile__DOT__rf[9]),32);
        tracep->fullIData(oldp+13,(vlSelf->top__DOT__u_regfile__DOT__rf[10]),32);
        tracep->fullIData(oldp+14,(vlSelf->top__DOT__u_regfile__DOT__rf[11]),32);
        tracep->fullIData(oldp+15,(vlSelf->top__DOT__u_regfile__DOT__rf[12]),32);
        tracep->fullIData(oldp+16,(vlSelf->top__DOT__u_regfile__DOT__rf[13]),32);
        tracep->fullIData(oldp+17,(vlSelf->top__DOT__u_regfile__DOT__rf[14]),32);
        tracep->fullIData(oldp+18,(vlSelf->top__DOT__u_regfile__DOT__rf[15]),32);
        tracep->fullIData(oldp+19,(vlSelf->top__DOT__u_regfile__DOT__rf[16]),32);
        tracep->fullIData(oldp+20,(vlSelf->top__DOT__u_regfile__DOT__rf[17]),32);
        tracep->fullIData(oldp+21,(vlSelf->top__DOT__u_regfile__DOT__rf[18]),32);
        tracep->fullIData(oldp+22,(vlSelf->top__DOT__u_regfile__DOT__rf[19]),32);
        tracep->fullIData(oldp+23,(vlSelf->top__DOT__u_regfile__DOT__rf[20]),32);
        tracep->fullIData(oldp+24,(vlSelf->top__DOT__u_regfile__DOT__rf[21]),32);
        tracep->fullIData(oldp+25,(vlSelf->top__DOT__u_regfile__DOT__rf[22]),32);
        tracep->fullIData(oldp+26,(vlSelf->top__DOT__u_regfile__DOT__rf[23]),32);
        tracep->fullIData(oldp+27,(vlSelf->top__DOT__u_regfile__DOT__rf[24]),32);
        tracep->fullIData(oldp+28,(vlSelf->top__DOT__u_regfile__DOT__rf[25]),32);
        tracep->fullIData(oldp+29,(vlSelf->top__DOT__u_regfile__DOT__rf[26]),32);
        tracep->fullIData(oldp+30,(vlSelf->top__DOT__u_regfile__DOT__rf[27]),32);
        tracep->fullIData(oldp+31,(vlSelf->top__DOT__u_regfile__DOT__rf[28]),32);
        tracep->fullIData(oldp+32,(vlSelf->top__DOT__u_regfile__DOT__rf[29]),32);
        tracep->fullIData(oldp+33,(vlSelf->top__DOT__u_regfile__DOT__rf[30]),32);
        tracep->fullIData(oldp+34,(vlSelf->top__DOT__u_regfile__DOT__rf[31]),32);
        tracep->fullBit(oldp+35,(vlSelf->clk));
        tracep->fullIData(oldp+36,(vlSelf->inst),32);
        tracep->fullIData(oldp+37,(vlSelf->pc),32);
        tracep->fullBit(oldp+38,(vlSelf->a));
        tracep->fullBit(oldp+39,((IData)((0x13U == 
                                          (0x707fU 
                                           & vlSelf->inst)))));
        tracep->fullCData(oldp+40,(vlSelf->top__DOT__rf_raddr1),5);
        tracep->fullCData(oldp+41,(vlSelf->top__DOT__rf_raddr2),5);
        tracep->fullBit(oldp+42,(vlSelf->top__DOT__rf_we));
        tracep->fullCData(oldp+43,(vlSelf->top__DOT__rf_waddr),5);
        tracep->fullIData(oldp+44,(vlSelf->top__DOT__rf_wdata),32);
    }
}
