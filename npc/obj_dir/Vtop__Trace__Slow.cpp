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
        tracep->declBit(c+33,"top.clk", false,-1);
        tracep->declBus(c+34,"inst", false,-1, 31,0);
        tracep->declBus(c+35,"pc", false,-1, 31,0);
        tracep->declBit(c+36,"a", false,-1);
        tracep->declBit(c+37,"regfile.clk", false,-1);
        tracep->declBus(c+38,"raddr1", false,-1, 4,0);
        tracep->declBus(c+39,"rdata1", false,-1, 31,0);
        tracep->declBus(c+40,"raddr2", false,-1, 4,0);
        tracep->declBus(c+41,"rdata2", false,-1, 31,0);
        tracep->declBit(c+42,"we", false,-1);
        tracep->declBus(c+43,"waddr", false,-1, 4,0);
        tracep->declBus(c+44,"wdata", false,-1, 31,0);
        tracep->declBit(c+33,"top clk", false,-1);
        tracep->declBus(c+34,"top inst", false,-1, 31,0);
        tracep->declBus(c+35,"top pc", false,-1, 31,0);
        tracep->declBit(c+36,"top a", false,-1);
        tracep->declBit(c+45,"top addi", false,-1);
        tracep->declBit(c+37,"regfile clk", false,-1);
        tracep->declBus(c+38,"regfile raddr1", false,-1, 4,0);
        tracep->declBus(c+39,"regfile rdata1", false,-1, 31,0);
        tracep->declBus(c+40,"regfile raddr2", false,-1, 4,0);
        tracep->declBus(c+41,"regfile rdata2", false,-1, 31,0);
        tracep->declBit(c+42,"regfile we", false,-1);
        tracep->declBus(c+43,"regfile waddr", false,-1, 4,0);
        tracep->declBus(c+44,"regfile wdata", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+1+i*1,"regfile rf", true,(i+0), 31,0);}}
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
        tracep->fullIData(oldp+1,(vlSelf->regfile__DOT__rf[0]),32);
        tracep->fullIData(oldp+2,(vlSelf->regfile__DOT__rf[1]),32);
        tracep->fullIData(oldp+3,(vlSelf->regfile__DOT__rf[2]),32);
        tracep->fullIData(oldp+4,(vlSelf->regfile__DOT__rf[3]),32);
        tracep->fullIData(oldp+5,(vlSelf->regfile__DOT__rf[4]),32);
        tracep->fullIData(oldp+6,(vlSelf->regfile__DOT__rf[5]),32);
        tracep->fullIData(oldp+7,(vlSelf->regfile__DOT__rf[6]),32);
        tracep->fullIData(oldp+8,(vlSelf->regfile__DOT__rf[7]),32);
        tracep->fullIData(oldp+9,(vlSelf->regfile__DOT__rf[8]),32);
        tracep->fullIData(oldp+10,(vlSelf->regfile__DOT__rf[9]),32);
        tracep->fullIData(oldp+11,(vlSelf->regfile__DOT__rf[10]),32);
        tracep->fullIData(oldp+12,(vlSelf->regfile__DOT__rf[11]),32);
        tracep->fullIData(oldp+13,(vlSelf->regfile__DOT__rf[12]),32);
        tracep->fullIData(oldp+14,(vlSelf->regfile__DOT__rf[13]),32);
        tracep->fullIData(oldp+15,(vlSelf->regfile__DOT__rf[14]),32);
        tracep->fullIData(oldp+16,(vlSelf->regfile__DOT__rf[15]),32);
        tracep->fullIData(oldp+17,(vlSelf->regfile__DOT__rf[16]),32);
        tracep->fullIData(oldp+18,(vlSelf->regfile__DOT__rf[17]),32);
        tracep->fullIData(oldp+19,(vlSelf->regfile__DOT__rf[18]),32);
        tracep->fullIData(oldp+20,(vlSelf->regfile__DOT__rf[19]),32);
        tracep->fullIData(oldp+21,(vlSelf->regfile__DOT__rf[20]),32);
        tracep->fullIData(oldp+22,(vlSelf->regfile__DOT__rf[21]),32);
        tracep->fullIData(oldp+23,(vlSelf->regfile__DOT__rf[22]),32);
        tracep->fullIData(oldp+24,(vlSelf->regfile__DOT__rf[23]),32);
        tracep->fullIData(oldp+25,(vlSelf->regfile__DOT__rf[24]),32);
        tracep->fullIData(oldp+26,(vlSelf->regfile__DOT__rf[25]),32);
        tracep->fullIData(oldp+27,(vlSelf->regfile__DOT__rf[26]),32);
        tracep->fullIData(oldp+28,(vlSelf->regfile__DOT__rf[27]),32);
        tracep->fullIData(oldp+29,(vlSelf->regfile__DOT__rf[28]),32);
        tracep->fullIData(oldp+30,(vlSelf->regfile__DOT__rf[29]),32);
        tracep->fullIData(oldp+31,(vlSelf->regfile__DOT__rf[30]),32);
        tracep->fullIData(oldp+32,(vlSelf->regfile__DOT__rf[31]),32);
        tracep->fullBit(oldp+33,(vlSelf->top__02Eclk));
        tracep->fullIData(oldp+34,(vlSelf->inst),32);
        tracep->fullIData(oldp+35,(vlSelf->pc),32);
        tracep->fullBit(oldp+36,(vlSelf->a));
        tracep->fullBit(oldp+37,(vlSelf->regfile__02Eclk));
        tracep->fullCData(oldp+38,(vlSelf->raddr1),5);
        tracep->fullIData(oldp+39,(vlSelf->rdata1),32);
        tracep->fullCData(oldp+40,(vlSelf->raddr2),5);
        tracep->fullIData(oldp+41,(vlSelf->rdata2),32);
        tracep->fullBit(oldp+42,(vlSelf->we));
        tracep->fullCData(oldp+43,(vlSelf->waddr),5);
        tracep->fullIData(oldp+44,(vlSelf->wdata),32);
        tracep->fullBit(oldp+45,((IData)((0x13U == 
                                          (0x707fU 
                                           & vlSelf->inst)))));
    }
}
