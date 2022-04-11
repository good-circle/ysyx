// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop___024root.h"
#include "VTop__Syms.h"

#include "verilated_dpi.h"

//==========


void VTop___024root___ctor_var_reset(VTop___024root* vlSelf);

VTop___024root::VTop___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    VTop___024root___ctor_var_reset(this);
}

void VTop___024root::__Vconfigure(VTop__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

VTop___024root::~VTop___024root() {
}

void VTop___024root____Vdpiimwrap_Top__DOT__regfile__DOT__set_gpr_ptr__Vdpioc2_TOP(const VlUnpacked<QData/*63:0*/, 32> &a);

void VTop___024root___initial__TOP__2(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___initial__TOP__2\n"); );
    // Body
    VTop___024root____Vdpiimwrap_Top__DOT__regfile__DOT__set_gpr_ptr__Vdpioc2_TOP(vlSelf->Top__DOT__regfile__DOT__rf);
}

void VTop___024root____Vdpiimwrap_Top__DOT__blackbox__DOT__pmem_read_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, QData/*63:0*/ mem_raddr, QData/*63:0*/ &mem_rdata, CData/*0:0*/ mem_read);
void VTop___024root____Vdpiimwrap_Top__DOT__blackbox__DOT__pmem_write_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, QData/*63:0*/ mem_waddr, QData/*63:0*/ mem_wdata, CData/*7:0*/ mem_wmask, CData/*0:0*/ mem_write);

void VTop___024root___settle__TOP__3(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___settle__TOP__3\n"); );
    // Variables
    CData/*4:0*/ Top__DOT__alu_io_aluop;
    CData/*0:0*/ Top__DOT__alu_io_rv64;
    CData/*0:0*/ Top__DOT___information_T_157;
    CData/*2:0*/ Top__DOT___information_T_202;
    CData/*2:0*/ Top__DOT___information_T_217;
    CData/*2:0*/ Top__DOT___information_T_232;
    CData/*2:0*/ Top__DOT___information_T_247;
    CData/*2:0*/ Top__DOT__information_1;
    CData/*1:0*/ Top__DOT___information_T_278;
    CData/*1:0*/ Top__DOT___information_T_293;
    CData/*1:0*/ Top__DOT___information_T_308;
    CData/*4:0*/ Top__DOT___information_T_327;
    CData/*4:0*/ Top__DOT___information_T_342;
    CData/*4:0*/ Top__DOT___information_T_357;
    CData/*4:0*/ Top__DOT___information_T_372;
    CData/*3:0*/ Top__DOT___information_T_464;
    CData/*3:0*/ Top__DOT___information_T_479;
    CData/*3:0*/ Top__DOT___information_T_494;
    CData/*1:0*/ Top__DOT___information_T_511;
    CData/*1:0*/ Top__DOT___information_T_526;
    CData/*1:0*/ Top__DOT___information_T_541;
    CData/*1:0*/ Top__DOT___information_T_556;
    CData/*1:0*/ Top__DOT__information_6;
    CData/*1:0*/ Top__DOT___information_T_588;
    CData/*1:0*/ Top__DOT___information_T_603;
    CData/*1:0*/ Top__DOT___information_T_618;
    CData/*1:0*/ Top__DOT__information_7;
    CData/*0:0*/ Top__DOT___information_T_666;
    CData/*0:0*/ Top__DOT__information_8;
    CData/*0:0*/ Top__DOT___information_T_710;
    CData/*0:0*/ Top__DOT___information_T_727;
    CData/*0:0*/ Top__DOT___information_T_744;
    CData/*7:0*/ Top__DOT___mem_wmask_T_3;
    CData/*0:0*/ Top__DOT__alu__DOT__srl;
    CData/*5:0*/ Top__DOT__alu__DOT__shamt;
    VlWide<4>/*127:0*/ Top__DOT__alu__DOT___tmp_result_T_16;
    VlWide<4>/*127:0*/ Top__DOT__alu__DOT___tmp_result_T_66;
    VlWide<4>/*127:0*/ Top__DOT__alu__DOT___tmp_result_T_76;
    VlWide<4>/*127:0*/ __Vtemp1;
    VlWide<4>/*127:0*/ __Vtemp2;
    VlWide<4>/*127:0*/ __Vtemp3;
    VlWide<5>/*159:0*/ __Vtemp6;
    VlWide<5>/*159:0*/ __Vtemp7;
    VlWide<3>/*95:0*/ __Vtemp9;
    VlWide<5>/*159:0*/ __Vtemp10;
    VlWide<5>/*159:0*/ __Vtemp11;
    VlWide<5>/*159:0*/ __Vtemp12;
    VlWide<4>/*127:0*/ __Vtemp14;
    VlWide<4>/*127:0*/ __Vtemp15;
    VlWide<4>/*127:0*/ __Vtemp16;
    VlWide<4>/*127:0*/ __Vtemp17;
    VlWide<4>/*127:0*/ __Vtemp18;
    VlWide<4>/*127:0*/ __Vtemp20;
    VlWide<4>/*127:0*/ __Vtemp21;
    VlWide<4>/*127:0*/ __Vtemp22;
    VlWide<4>/*127:0*/ __Vtemp23;
    VlWide<4>/*127:0*/ __Vtemp24;
    VlWide<4>/*127:0*/ __Vtemp31;
    VlWide<4>/*127:0*/ __Vtemp32;
    VlWide<4>/*127:0*/ __Vtemp39;
    VlWide<4>/*127:0*/ __Vtemp40;
    VlWide<4>/*127:0*/ __Vtemp41;
    VlWide<3>/*95:0*/ __Vtemp44;
    VlWide<3>/*95:0*/ __Vtemp45;
    VlWide<3>/*95:0*/ __Vtemp47;
    VlWide<3>/*95:0*/ __Vtemp48;
    VlWide<3>/*95:0*/ __Vtemp49;
    VlWide<3>/*95:0*/ __Vtemp50;
    VlWide<4>/*127:0*/ __Vtemp51;
    VlWide<4>/*127:0*/ __Vtemp52;
    QData/*63:0*/ Top__DOT__regfile_rdata1;
    QData/*63:0*/ Top__DOT__regfile_rdata2;
    QData/*63:0*/ Top__DOT__blackbox_inst_2;
    QData/*63:0*/ Top__DOT__imm_j;
    QData/*63:0*/ Top__DOT___imm_T_7;
    QData/*63:0*/ Top__DOT___src1_value_T_1;
    QData/*63:0*/ Top__DOT___src2_value_T_1;
    QData/*63:0*/ Top__DOT___lb_rdata_T_33;
    QData/*63:0*/ Top__DOT___load_rdata_T_3;
    QData/*63:0*/ Top__DOT__alu__DOT___src1_T_4;
    QData/*63:0*/ Top__DOT__alu__DOT__src1;
    // Body
    vlSelf->Top__DOT___rf_wdata_T_1 = (4ULL + vlSelf->Top__DOT__pc);
    vlSelf->io_pc = vlSelf->Top__DOT__pc;
    VTop___024root____Vdpiimwrap_Top__DOT__blackbox__DOT__pmem_read_TOP(
                                                                        (&(vlSymsp->__Vscope_Top__blackbox)), 
                                                                        "vsrc/chisel/Blackbox.v", 0x22U, vlSelf->Top__DOT__pc, vlSelf->__Vtask_Top__DOT__blackbox__DOT__pmem_read__3__mem_rdata, 
                                                                        (1U 
                                                                         & (~ (IData)(vlSelf->reset))));
    Top__DOT__blackbox_inst_2 = vlSelf->__Vtask_Top__DOT__blackbox__DOT__pmem_read__3__mem_rdata;
    vlSelf->Top__DOT__inst = ((1U & (IData)((vlSelf->Top__DOT__pc 
                                             >> 2U)))
                               ? (IData)((Top__DOT__blackbox_inst_2 
                                          >> 0x20U))
                               : (IData)(Top__DOT__blackbox_inst_2));
    vlSelf->Top__DOT__bru_io_bruop = ((0x37U == (0x7fU 
                                                 & vlSelf->Top__DOT__inst))
                                       ? 0U : ((0x17U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->Top__DOT__inst))
                                                ? 0U
                                                : (
                                                   (0x6fU 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 1U
                                                    : 
                                                   ((0x67U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 2U
                                                     : 
                                                    ((0x63U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 3U
                                                      : 
                                                     ((0x1063U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 4U
                                                       : 
                                                      ((0x4063U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 5U
                                                        : 
                                                       ((0x5063U 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 6U
                                                         : 
                                                        ((0x6063U 
                                                          == 
                                                          (0x707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 7U
                                                          : 
                                                         ((0x7063U 
                                                           == 
                                                           (0x707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 8U
                                                           : 0U))))))))));
    Top__DOT___information_T_157 = ((0x3033U == (0xfe00707fU 
                                                 & vlSelf->Top__DOT__inst)) 
                                    | ((0x4033U == 
                                        (0xfe00707fU 
                                         & vlSelf->Top__DOT__inst)) 
                                       | ((0x5033U 
                                           == (0xfe00707fU 
                                               & vlSelf->Top__DOT__inst)) 
                                          | ((0x40005033U 
                                              == (0xfe00707fU 
                                                  & vlSelf->Top__DOT__inst)) 
                                             | ((0x6033U 
                                                 == 
                                                 (0xfe00707fU 
                                                  & vlSelf->Top__DOT__inst)) 
                                                | ((0x7033U 
                                                    == 
                                                    (0xfe00707fU 
                                                     & vlSelf->Top__DOT__inst)) 
                                                   | ((0x1bU 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->Top__DOT__inst)) 
                                                      | ((0x101bU 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst)) 
                                                         | ((0x501bU 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlSelf->Top__DOT__inst)) 
                                                            | ((0x4000501bU 
                                                                == 
                                                                (0xfe00707fU 
                                                                 & vlSelf->Top__DOT__inst)) 
                                                               | ((0x3bU 
                                                                   == 
                                                                   (0xfe00707fU 
                                                                    & vlSelf->Top__DOT__inst)) 
                                                                  | ((0x4000003bU 
                                                                      == 
                                                                      (0xfe00707fU 
                                                                       & vlSelf->Top__DOT__inst)) 
                                                                     | ((0x103bU 
                                                                         == 
                                                                         (0xfe00707fU 
                                                                          & vlSelf->Top__DOT__inst)) 
                                                                        | ((0x503bU 
                                                                            == 
                                                                            (0xfe00707fU 
                                                                             & vlSelf->Top__DOT__inst)) 
                                                                           | ((0x4000503bU 
                                                                               == 
                                                                               (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                              | ((0x6003U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x3003U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x3023U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2000033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2001033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2002033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2003033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2004033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2005033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2006033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2007033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x200003bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x200403bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x200503bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x200603bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | (0x200703bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst))))))))))))))))))))))))))))))));
    Top__DOT___information_T_666 = ((0x13U == (0x707fU 
                                               & vlSelf->Top__DOT__inst)) 
                                    | ((0x2013U == 
                                        (0x707fU & vlSelf->Top__DOT__inst)) 
                                       | ((0x3013U 
                                           == (0x707fU 
                                               & vlSelf->Top__DOT__inst)) 
                                          | ((0x4013U 
                                              == (0x707fU 
                                                  & vlSelf->Top__DOT__inst)) 
                                             | ((0x6013U 
                                                 == 
                                                 (0x707fU 
                                                  & vlSelf->Top__DOT__inst)) 
                                                | ((0x7013U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst)) 
                                                   | ((0x1013U 
                                                       == 
                                                       (0xfc00707fU 
                                                        & vlSelf->Top__DOT__inst)) 
                                                      | ((0x5013U 
                                                          == 
                                                          (0xfc00707fU 
                                                           & vlSelf->Top__DOT__inst)) 
                                                         | ((0x40005013U 
                                                             == 
                                                             (0xfc00707fU 
                                                              & vlSelf->Top__DOT__inst)) 
                                                            | ((0x33U 
                                                                == 
                                                                (0xfe00707fU 
                                                                 & vlSelf->Top__DOT__inst)) 
                                                               | ((0x40000033U 
                                                                   == 
                                                                   (0xfe00707fU 
                                                                    & vlSelf->Top__DOT__inst)) 
                                                                  | ((0x1033U 
                                                                      == 
                                                                      (0xfe00707fU 
                                                                       & vlSelf->Top__DOT__inst)) 
                                                                     | ((0x2033U 
                                                                         == 
                                                                         (0xfe00707fU 
                                                                          & vlSelf->Top__DOT__inst)) 
                                                                        | ((0x3033U 
                                                                            == 
                                                                            (0xfe00707fU 
                                                                             & vlSelf->Top__DOT__inst)) 
                                                                           | ((0x4033U 
                                                                               == 
                                                                               (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                              | ((0x5033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x40005033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x6033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x7033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x1bU 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x101bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x501bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x4000501bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x3bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x4000003bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x103bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x503bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x4000503bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x6003U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x3003U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x3023U 
                                                                                != 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                & ((0x2000033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2001033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2002033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2003033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2004033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2005033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2006033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2007033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x200003bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x200403bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x200503bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x200603bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x200703bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | (0x100073U 
                                                                                == vlSelf->Top__DOT__inst)))))))))))))))))))))))))))))))))))))))))))));
    if ((0x40005033U == (0xfe00707fU & vlSelf->Top__DOT__inst))) {
        Top__DOT___information_T_278 = 0U;
        Top__DOT___information_T_464 = 0U;
    } else {
        Top__DOT___information_T_278 = ((0x6033U == 
                                         (0xfe00707fU 
                                          & vlSelf->Top__DOT__inst))
                                         ? 0U : ((0x7033U 
                                                  == 
                                                  (0xfe00707fU 
                                                   & vlSelf->Top__DOT__inst))
                                                  ? 0U
                                                  : 
                                                 ((0x1bU 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 0U
                                                   : 
                                                  ((0x101bU 
                                                    == 
                                                    (0xfe00707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 0U
                                                    : 
                                                   ((0x501bU 
                                                     == 
                                                     (0xfe00707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 0U
                                                     : 
                                                    ((0x4000501bU 
                                                      == 
                                                      (0xfe00707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 0U
                                                      : 
                                                     ((0x3bU 
                                                       == 
                                                       (0xfe00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 0U
                                                       : 
                                                      ((0x4000003bU 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 0U
                                                        : 
                                                       ((0x103bU 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 0U
                                                         : 
                                                        ((0x503bU 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 0U
                                                          : 
                                                         ((0x4000503bU 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 0U
                                                           : 
                                                          ((0x6003U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 2U
                                                            : 
                                                           ((0x3003U 
                                                             == 
                                                             (0x707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 2U
                                                             : 
                                                            ((0x3023U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 2U
                                                              : 0U))))))))))))));
        Top__DOT___information_T_464 = ((0x6033U == 
                                         (0xfe00707fU 
                                          & vlSelf->Top__DOT__inst))
                                         ? 0U : ((0x7033U 
                                                  == 
                                                  (0xfe00707fU 
                                                   & vlSelf->Top__DOT__inst))
                                                  ? 0U
                                                  : 
                                                 ((0x1bU 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 0U
                                                   : 
                                                  ((0x101bU 
                                                    == 
                                                    (0xfe00707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 0U
                                                    : 
                                                   ((0x501bU 
                                                     == 
                                                     (0xfe00707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 0U
                                                     : 
                                                    ((0x4000501bU 
                                                      == 
                                                      (0xfe00707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 0U
                                                      : 
                                                     ((0x3bU 
                                                       == 
                                                       (0xfe00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 0U
                                                       : 
                                                      ((0x4000003bU 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 0U
                                                        : 
                                                       ((0x103bU 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 0U
                                                         : 
                                                        ((0x503bU 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 0U
                                                          : 
                                                         ((0x4000503bU 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 0U
                                                           : 
                                                          ((0x6003U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 9U
                                                            : 
                                                           ((0x3003U 
                                                             == 
                                                             (0x707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 0xaU
                                                             : 
                                                            ((0x3023U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 0xbU
                                                              : 0U))))))))))))));
    }
    Top__DOT__imm_j = ((((vlSelf->Top__DOT__inst >> 0x1fU)
                          ? 0xfffffffffffULL : 0ULL) 
                        << 0x14U) | (QData)((IData)(
                                                    ((0xff000U 
                                                      & vlSelf->Top__DOT__inst) 
                                                     | ((0x800U 
                                                         & (vlSelf->Top__DOT__inst 
                                                            >> 9U)) 
                                                        | (0x7feU 
                                                           & (vlSelf->Top__DOT__inst 
                                                              >> 0x14U)))))));
    Top__DOT__regfile_rdata2 = ((0U == (0x1fU & (vlSelf->Top__DOT__inst 
                                                 >> 0x14U)))
                                 ? 0ULL : vlSelf->Top__DOT__regfile__DOT__rf
                                [(0x1fU & (vlSelf->Top__DOT__inst 
                                           >> 0x14U))]);
    Top__DOT__regfile_rdata1 = ((0U == (0x1fU & (vlSelf->Top__DOT__inst 
                                                 >> 0xfU)))
                                 ? 0ULL : vlSelf->Top__DOT__regfile__DOT__rf
                                [(0x1fU & (vlSelf->Top__DOT__inst 
                                           >> 0xfU))]);
    Top__DOT___information_T_710 = ((0x7033U != (0xfe00707fU 
                                                 & vlSelf->Top__DOT__inst)) 
                                    & ((0x1bU == (0x707fU 
                                                  & vlSelf->Top__DOT__inst)) 
                                       | ((0x101bU 
                                           == (0xfe00707fU 
                                               & vlSelf->Top__DOT__inst)) 
                                          | ((0x501bU 
                                              == (0xfe00707fU 
                                                  & vlSelf->Top__DOT__inst)) 
                                             | ((0x4000501bU 
                                                 == 
                                                 (0xfe00707fU 
                                                  & vlSelf->Top__DOT__inst)) 
                                                | ((0x3bU 
                                                    == 
                                                    (0xfe00707fU 
                                                     & vlSelf->Top__DOT__inst)) 
                                                   | ((0x4000003bU 
                                                       == 
                                                       (0xfe00707fU 
                                                        & vlSelf->Top__DOT__inst)) 
                                                      | ((0x103bU 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst)) 
                                                         | ((0x503bU 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlSelf->Top__DOT__inst)) 
                                                            | ((0x4000503bU 
                                                                == 
                                                                (0xfe00707fU 
                                                                 & vlSelf->Top__DOT__inst)) 
                                                               | ((0x6003U 
                                                                   != 
                                                                   (0x707fU 
                                                                    & vlSelf->Top__DOT__inst)) 
                                                                  & ((0x3003U 
                                                                      != 
                                                                      (0x707fU 
                                                                       & vlSelf->Top__DOT__inst)) 
                                                                     & ((0x3023U 
                                                                         != 
                                                                         (0x707fU 
                                                                          & vlSelf->Top__DOT__inst)) 
                                                                        & ((0x2000033U 
                                                                            != 
                                                                            (0xfe00707fU 
                                                                             & vlSelf->Top__DOT__inst)) 
                                                                           & ((0x2001033U 
                                                                               != 
                                                                               (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                              & ((0x2002033U 
                                                                                != 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                & ((0x2003033U 
                                                                                != 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                & ((0x2004033U 
                                                                                != 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                & ((0x2005033U 
                                                                                != 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                & ((0x2006033U 
                                                                                != 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                & ((0x2007033U 
                                                                                != 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                & ((0x200003bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x200403bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x200503bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x200603bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x200703bU 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | (0x100073U 
                                                                                == vlSelf->Top__DOT__inst)))))))))))))))))))))))))));
    Top__DOT___information_T_327 = ((0x3003U == (0x707fU 
                                                 & vlSelf->Top__DOT__inst))
                                     ? 1U : ((0x3023U 
                                              == (0x707fU 
                                                  & vlSelf->Top__DOT__inst))
                                              ? 1U : 
                                             ((0x2000033U 
                                               == (0xfe00707fU 
                                                   & vlSelf->Top__DOT__inst))
                                               ? 0xbU
                                               : ((0x2001033U 
                                                   == 
                                                   (0xfe00707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 0xcU
                                                   : 
                                                  ((0x2002033U 
                                                    == 
                                                    (0xfe00707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 0xdU
                                                    : 
                                                   ((0x2003033U 
                                                     == 
                                                     (0xfe00707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 0xeU
                                                     : 
                                                    ((0x2004033U 
                                                      == 
                                                      (0xfe00707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 0xfU
                                                      : 
                                                     ((0x2005033U 
                                                       == 
                                                       (0xfe00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 0x10U
                                                       : 
                                                      ((0x2006033U 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 0x11U
                                                        : 
                                                       ((0x2007033U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 0x12U
                                                         : 
                                                        ((0x200003bU 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 0xbU
                                                          : 
                                                         ((0x200403bU 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 0xfU
                                                           : 
                                                          ((0x200503bU 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 0x10U
                                                            : 
                                                           ((0x200603bU 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 0x11U
                                                             : 
                                                            ((0x200703bU 
                                                              == 
                                                              (0xfe00707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 0x12U
                                                              : 0U)))))))))))))));
    Top__DOT___information_T_202 = ((0x3023U == (0x707fU 
                                                 & vlSelf->Top__DOT__inst))
                                     ? 2U : ((0x2000033U 
                                              == (0xfe00707fU 
                                                  & vlSelf->Top__DOT__inst))
                                              ? 0U : 
                                             ((0x2001033U 
                                               == (0xfe00707fU 
                                                   & vlSelf->Top__DOT__inst))
                                               ? 0U
                                               : ((0x2002033U 
                                                   == 
                                                   (0xfe00707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 0U
                                                   : 
                                                  ((0x2003033U 
                                                    == 
                                                    (0xfe00707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 0U
                                                    : 
                                                   ((0x2004033U 
                                                     == 
                                                     (0xfe00707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 0U
                                                     : 
                                                    ((0x2005033U 
                                                      == 
                                                      (0xfe00707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 0U
                                                      : 
                                                     ((0x2006033U 
                                                       == 
                                                       (0xfe00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 0U
                                                       : 
                                                      ((0x2007033U 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 0U
                                                        : 
                                                       ((0x200003bU 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 0U
                                                         : 
                                                        ((0x200403bU 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 0U
                                                          : 
                                                         ((0x200503bU 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 0U
                                                           : 
                                                          ((0x200603bU 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 0U
                                                            : 
                                                           ((0x200703bU 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 0U
                                                             : 
                                                            ((0x100073U 
                                                              == vlSelf->Top__DOT__inst)
                                                              ? 1U
                                                              : 0U)))))))))))))));
    Top__DOT___information_T_511 = ((0x2000033U == 
                                     (0xfe00707fU & vlSelf->Top__DOT__inst))
                                     ? 2U : ((0x2001033U 
                                              == (0xfe00707fU 
                                                  & vlSelf->Top__DOT__inst))
                                              ? 2U : 
                                             ((0x2002033U 
                                               == (0xfe00707fU 
                                                   & vlSelf->Top__DOT__inst))
                                               ? 2U
                                               : ((0x2003033U 
                                                   == 
                                                   (0xfe00707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 2U
                                                   : 
                                                  ((0x2004033U 
                                                    == 
                                                    (0xfe00707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 2U
                                                    : 
                                                   ((0x2005033U 
                                                     == 
                                                     (0xfe00707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 2U
                                                     : 
                                                    ((0x2006033U 
                                                      == 
                                                      (0xfe00707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 2U
                                                      : 
                                                     ((0x2007033U 
                                                       == 
                                                       (0xfe00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 2U
                                                       : 
                                                      ((0x200003bU 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 2U
                                                        : 
                                                       ((0x200403bU 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 2U
                                                         : 
                                                        ((0x200503bU 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 2U
                                                          : 
                                                         ((0x200603bU 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 2U
                                                           : 
                                                          ((0x200703bU 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 2U
                                                            : 0U)))))))))))));
    vlSelf->Top__DOT___information_T_187 = ((0x17U 
                                             == (0x7fU 
                                                 & vlSelf->Top__DOT__inst)) 
                                            | ((0x6fU 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->Top__DOT__inst)) 
                                               | ((0x67U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst)) 
                                                  | ((0x63U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->Top__DOT__inst)) 
                                                     | ((0x1063U 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->Top__DOT__inst)) 
                                                        | ((0x4063U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->Top__DOT__inst)) 
                                                           | ((0x5063U 
                                                               == 
                                                               (0x707fU 
                                                                & vlSelf->Top__DOT__inst)) 
                                                              | ((0x6063U 
                                                                  == 
                                                                  (0x707fU 
                                                                   & vlSelf->Top__DOT__inst)) 
                                                                 | ((0x7063U 
                                                                     == 
                                                                     (0x707fU 
                                                                      & vlSelf->Top__DOT__inst)) 
                                                                    | ((3U 
                                                                        == 
                                                                        (0x707fU 
                                                                         & vlSelf->Top__DOT__inst)) 
                                                                       | ((0x1003U 
                                                                           == 
                                                                           (0x707fU 
                                                                            & vlSelf->Top__DOT__inst)) 
                                                                          | ((0x2003U 
                                                                              == 
                                                                              (0x707fU 
                                                                               & vlSelf->Top__DOT__inst)) 
                                                                             | ((0x4003U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x5003U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x23U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x1023U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2023U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x13U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2013U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x3013U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x4013U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x6013U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x7013U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x1013U 
                                                                                == 
                                                                                (0xfc00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x5013U 
                                                                                == 
                                                                                (0xfc00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x40005013U 
                                                                                == 
                                                                                (0xfc00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x33U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x40000033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x1033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | ((0x2033U 
                                                                                == 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                | (IData)(Top__DOT___information_T_157)))))))))))))))))))))))))))))));
    vlSelf->Top__DOT___information_T_680 = ((0x63U 
                                             != (0x707fU 
                                                 & vlSelf->Top__DOT__inst)) 
                                            & ((0x1063U 
                                                != 
                                                (0x707fU 
                                                 & vlSelf->Top__DOT__inst)) 
                                               & ((0x4063U 
                                                   != 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst)) 
                                                  & ((0x5063U 
                                                      != 
                                                      (0x707fU 
                                                       & vlSelf->Top__DOT__inst)) 
                                                     & ((0x6063U 
                                                         != 
                                                         (0x707fU 
                                                          & vlSelf->Top__DOT__inst)) 
                                                        & ((0x7063U 
                                                            != 
                                                            (0x707fU 
                                                             & vlSelf->Top__DOT__inst)) 
                                                           & ((3U 
                                                               == 
                                                               (0x707fU 
                                                                & vlSelf->Top__DOT__inst)) 
                                                              | ((0x1003U 
                                                                  == 
                                                                  (0x707fU 
                                                                   & vlSelf->Top__DOT__inst)) 
                                                                 | ((0x2003U 
                                                                     == 
                                                                     (0x707fU 
                                                                      & vlSelf->Top__DOT__inst)) 
                                                                    | ((0x4003U 
                                                                        == 
                                                                        (0x707fU 
                                                                         & vlSelf->Top__DOT__inst)) 
                                                                       | ((0x5003U 
                                                                           == 
                                                                           (0x707fU 
                                                                            & vlSelf->Top__DOT__inst)) 
                                                                          | ((0x23U 
                                                                              != 
                                                                              (0x707fU 
                                                                               & vlSelf->Top__DOT__inst)) 
                                                                             & ((0x1023U 
                                                                                != 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                & ((0x2023U 
                                                                                != 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                & (IData)(Top__DOT___information_T_666)))))))))))))));
    if ((0x2013U == (0x707fU & vlSelf->Top__DOT__inst))) {
        Top__DOT___information_T_293 = 0U;
        Top__DOT___information_T_479 = 0U;
    } else {
        Top__DOT___information_T_293 = ((0x3013U == 
                                         (0x707fU & vlSelf->Top__DOT__inst))
                                         ? 0U : ((0x4013U 
                                                  == 
                                                  (0x707fU 
                                                   & vlSelf->Top__DOT__inst))
                                                  ? 0U
                                                  : 
                                                 ((0x6013U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 0U
                                                   : 
                                                  ((0x7013U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 0U
                                                    : 
                                                   ((0x1013U 
                                                     == 
                                                     (0xfc00707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 0U
                                                     : 
                                                    ((0x5013U 
                                                      == 
                                                      (0xfc00707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 0U
                                                      : 
                                                     ((0x40005013U 
                                                       == 
                                                       (0xfc00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 0U
                                                       : 
                                                      ((0x33U 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 0U
                                                        : 
                                                       ((0x40000033U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 0U
                                                         : 
                                                        ((0x1033U 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 0U
                                                          : 
                                                         ((0x2033U 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 0U
                                                           : 
                                                          ((0x3033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 0U
                                                            : 
                                                           ((0x4033U 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 0U
                                                             : 
                                                            ((0x5033U 
                                                              == 
                                                              (0xfe00707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 0U
                                                              : (IData)(Top__DOT___information_T_278)))))))))))))));
        Top__DOT___information_T_479 = ((0x3013U == 
                                         (0x707fU & vlSelf->Top__DOT__inst))
                                         ? 0U : ((0x4013U 
                                                  == 
                                                  (0x707fU 
                                                   & vlSelf->Top__DOT__inst))
                                                  ? 0U
                                                  : 
                                                 ((0x6013U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 0U
                                                   : 
                                                  ((0x7013U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 0U
                                                    : 
                                                   ((0x1013U 
                                                     == 
                                                     (0xfc00707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 0U
                                                     : 
                                                    ((0x5013U 
                                                      == 
                                                      (0xfc00707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 0U
                                                      : 
                                                     ((0x40005013U 
                                                       == 
                                                       (0xfc00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 0U
                                                       : 
                                                      ((0x33U 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 0U
                                                        : 
                                                       ((0x40000033U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 0U
                                                         : 
                                                        ((0x1033U 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 0U
                                                          : 
                                                         ((0x2033U 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 0U
                                                           : 
                                                          ((0x3033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 0U
                                                            : 
                                                           ((0x4033U 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 0U
                                                             : 
                                                            ((0x5033U 
                                                              == 
                                                              (0xfe00707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 0U
                                                              : (IData)(Top__DOT___information_T_464)))))))))))))));
    }
    Top__DOT___information_T_727 = ((0x2013U != (0x707fU 
                                                 & vlSelf->Top__DOT__inst)) 
                                    & ((0x3013U != 
                                        (0x707fU & vlSelf->Top__DOT__inst)) 
                                       & ((0x4013U 
                                           != (0x707fU 
                                               & vlSelf->Top__DOT__inst)) 
                                          & ((0x6013U 
                                              != (0x707fU 
                                                  & vlSelf->Top__DOT__inst)) 
                                             & ((0x7013U 
                                                 != 
                                                 (0x707fU 
                                                  & vlSelf->Top__DOT__inst)) 
                                                & ((0x1013U 
                                                    != 
                                                    (0xfc00707fU 
                                                     & vlSelf->Top__DOT__inst)) 
                                                   & ((0x5013U 
                                                       != 
                                                       (0xfc00707fU 
                                                        & vlSelf->Top__DOT__inst)) 
                                                      & ((0x40005013U 
                                                          != 
                                                          (0xfc00707fU 
                                                           & vlSelf->Top__DOT__inst)) 
                                                         & ((0x33U 
                                                             != 
                                                             (0xfe00707fU 
                                                              & vlSelf->Top__DOT__inst)) 
                                                            & ((0x40000033U 
                                                                != 
                                                                (0xfe00707fU 
                                                                 & vlSelf->Top__DOT__inst)) 
                                                               & ((0x1033U 
                                                                   != 
                                                                   (0xfe00707fU 
                                                                    & vlSelf->Top__DOT__inst)) 
                                                                  & ((0x2033U 
                                                                      != 
                                                                      (0xfe00707fU 
                                                                       & vlSelf->Top__DOT__inst)) 
                                                                     & ((0x3033U 
                                                                         != 
                                                                         (0xfe00707fU 
                                                                          & vlSelf->Top__DOT__inst)) 
                                                                        & ((0x4033U 
                                                                            != 
                                                                            (0xfe00707fU 
                                                                             & vlSelf->Top__DOT__inst)) 
                                                                           & ((0x5033U 
                                                                               != 
                                                                               (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                              & ((0x40005033U 
                                                                                != 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                & ((0x6033U 
                                                                                != 
                                                                                (0xfe00707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                & (IData)(Top__DOT___information_T_710))))))))))))))))));
    Top__DOT___information_T_342 = ((0x4033U == (0xfe00707fU 
                                                 & vlSelf->Top__DOT__inst))
                                     ? 5U : ((0x5033U 
                                              == (0xfe00707fU 
                                                  & vlSelf->Top__DOT__inst))
                                              ? 9U : 
                                             ((0x40005033U 
                                               == (0xfe00707fU 
                                                   & vlSelf->Top__DOT__inst))
                                               ? 0xaU
                                               : ((0x6033U 
                                                   == 
                                                   (0xfe00707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 4U
                                                   : 
                                                  ((0x7033U 
                                                    == 
                                                    (0xfe00707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 3U
                                                    : 
                                                   ((0x1bU 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 1U
                                                     : 
                                                    ((0x101bU 
                                                      == 
                                                      (0xfe00707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 8U
                                                      : 
                                                     ((0x501bU 
                                                       == 
                                                       (0xfe00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 9U
                                                       : 
                                                      ((0x4000501bU 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 0xaU
                                                        : 
                                                       ((0x3bU 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 1U
                                                         : 
                                                        ((0x4000003bU 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 2U
                                                          : 
                                                         ((0x103bU 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 8U
                                                           : 
                                                          ((0x503bU 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 9U
                                                            : 
                                                           ((0x4000503bU 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 0xaU
                                                             : 
                                                            ((0x6003U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 1U
                                                              : (IData)(Top__DOT___information_T_327))))))))))))))));
    Top__DOT___information_T_217 = ((0x5033U == (0xfe00707fU 
                                                 & vlSelf->Top__DOT__inst))
                                     ? 0U : ((0x40005033U 
                                              == (0xfe00707fU 
                                                  & vlSelf->Top__DOT__inst))
                                              ? 0U : 
                                             ((0x6033U 
                                               == (0xfe00707fU 
                                                   & vlSelf->Top__DOT__inst))
                                               ? 0U
                                               : ((0x7033U 
                                                   == 
                                                   (0xfe00707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 0U
                                                   : 
                                                  ((0x1bU 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 1U
                                                    : 
                                                   ((0x101bU 
                                                     == 
                                                     (0xfe00707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 1U
                                                     : 
                                                    ((0x501bU 
                                                      == 
                                                      (0xfe00707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 1U
                                                      : 
                                                     ((0x4000501bU 
                                                       == 
                                                       (0xfe00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 1U
                                                       : 
                                                      ((0x3bU 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 0U
                                                        : 
                                                       ((0x4000003bU 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 0U
                                                         : 
                                                        ((0x103bU 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 0U
                                                          : 
                                                         ((0x503bU 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 0U
                                                           : 
                                                          ((0x4000503bU 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 0U
                                                            : 
                                                           ((0x6003U 
                                                             == 
                                                             (0x707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 1U
                                                             : 
                                                            ((0x3003U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 1U
                                                              : (IData)(Top__DOT___information_T_202))))))))))))))));
    if ((0x40005033U == (0xfe00707fU & vlSelf->Top__DOT__inst))) {
        Top__DOT___information_T_588 = 2U;
        Top__DOT___information_T_526 = 2U;
    } else {
        Top__DOT___information_T_588 = ((0x6033U == 
                                         (0xfe00707fU 
                                          & vlSelf->Top__DOT__inst))
                                         ? 2U : ((0x7033U 
                                                  == 
                                                  (0xfe00707fU 
                                                   & vlSelf->Top__DOT__inst))
                                                  ? 2U
                                                  : 
                                                 ((0x1bU 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 3U
                                                   : 
                                                  ((0x101bU 
                                                    == 
                                                    (0xfe00707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 3U
                                                    : 
                                                   ((0x501bU 
                                                     == 
                                                     (0xfe00707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 3U
                                                     : 
                                                    ((0x4000501bU 
                                                      == 
                                                      (0xfe00707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 3U
                                                      : 
                                                     ((0x3bU 
                                                       == 
                                                       (0xfe00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 2U
                                                       : 
                                                      ((0x4000003bU 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 2U
                                                        : 
                                                       ((0x103bU 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 2U
                                                         : 
                                                        ((0x503bU 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 2U
                                                          : 
                                                         ((0x4000503bU 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 2U
                                                           : 
                                                          ((0x6003U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 3U
                                                            : 
                                                           ((0x3003U 
                                                             == 
                                                             (0x707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 3U
                                                             : 
                                                            ((0x3023U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 3U
                                                              : (IData)(Top__DOT___information_T_511)))))))))))))));
        Top__DOT___information_T_526 = ((0x6033U == 
                                         (0xfe00707fU 
                                          & vlSelf->Top__DOT__inst))
                                         ? 2U : ((0x7033U 
                                                  == 
                                                  (0xfe00707fU 
                                                   & vlSelf->Top__DOT__inst))
                                                  ? 2U
                                                  : 
                                                 ((0x1bU 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 2U
                                                   : 
                                                  ((0x101bU 
                                                    == 
                                                    (0xfe00707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 2U
                                                    : 
                                                   ((0x501bU 
                                                     == 
                                                     (0xfe00707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 2U
                                                     : 
                                                    ((0x4000501bU 
                                                      == 
                                                      (0xfe00707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 2U
                                                      : 
                                                     ((0x3bU 
                                                       == 
                                                       (0xfe00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 2U
                                                       : 
                                                      ((0x4000003bU 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 2U
                                                        : 
                                                       ((0x103bU 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 2U
                                                         : 
                                                        ((0x503bU 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 2U
                                                          : 
                                                         ((0x4000503bU 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 2U
                                                           : 
                                                          ((0x6003U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 2U
                                                            : 
                                                           ((0x3003U 
                                                             == 
                                                             (0x707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 2U
                                                             : 
                                                            ((0x3023U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 2U
                                                              : (IData)(Top__DOT___information_T_511)))))))))))))));
    }
    Top__DOT__information_8 = ((0x37U == (0x7fU & vlSelf->Top__DOT__inst)) 
                               | ((0x17U == (0x7fU 
                                             & vlSelf->Top__DOT__inst)) 
                                  | ((0x6fU == (0x7fU 
                                                & vlSelf->Top__DOT__inst)) 
                                     | ((0x67U == (0x707fU 
                                                   & vlSelf->Top__DOT__inst)) 
                                        | (IData)(vlSelf->Top__DOT___information_T_680)))));
    if ((0x63U == (0x707fU & vlSelf->Top__DOT__inst))) {
        Top__DOT___information_T_308 = 1U;
        Top__DOT___information_T_494 = 0U;
    } else {
        Top__DOT___information_T_308 = ((0x1063U == 
                                         (0x707fU & vlSelf->Top__DOT__inst))
                                         ? 1U : ((0x4063U 
                                                  == 
                                                  (0x707fU 
                                                   & vlSelf->Top__DOT__inst))
                                                  ? 1U
                                                  : 
                                                 ((0x5063U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 1U
                                                   : 
                                                  ((0x6063U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 1U
                                                    : 
                                                   ((0x7063U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 1U
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 2U
                                                      : 
                                                     ((0x1003U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 2U
                                                       : 
                                                      ((0x2003U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 2U
                                                        : 
                                                       ((0x4003U 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 2U
                                                         : 
                                                        ((0x5003U 
                                                          == 
                                                          (0x707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 2U
                                                          : 
                                                         ((0x23U 
                                                           == 
                                                           (0x707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 2U
                                                           : 
                                                          ((0x1023U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 2U
                                                            : 
                                                           ((0x2023U 
                                                             == 
                                                             (0x707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 2U
                                                             : 
                                                            ((0x13U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 0U
                                                              : (IData)(Top__DOT___information_T_293)))))))))))))));
        Top__DOT___information_T_494 = ((0x1063U == 
                                         (0x707fU & vlSelf->Top__DOT__inst))
                                         ? 0U : ((0x4063U 
                                                  == 
                                                  (0x707fU 
                                                   & vlSelf->Top__DOT__inst))
                                                  ? 0U
                                                  : 
                                                 ((0x5063U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 0U
                                                   : 
                                                  ((0x6063U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 0U
                                                    : 
                                                   ((0x7063U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 0U
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 1U
                                                      : 
                                                     ((0x1003U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 2U
                                                       : 
                                                      ((0x2003U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 3U
                                                        : 
                                                       ((0x4003U 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 4U
                                                         : 
                                                        ((0x5003U 
                                                          == 
                                                          (0x707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 5U
                                                          : 
                                                         ((0x23U 
                                                           == 
                                                           (0x707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 6U
                                                           : 
                                                          ((0x1023U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 7U
                                                            : 
                                                           ((0x2023U 
                                                             == 
                                                             (0x707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 8U
                                                             : 
                                                            ((0x13U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 0U
                                                              : (IData)(Top__DOT___information_T_479)))))))))))))));
    }
    Top__DOT___information_T_744 = ((0x6fU != (0x7fU 
                                               & vlSelf->Top__DOT__inst)) 
                                    & ((0x67U != (0x707fU 
                                                  & vlSelf->Top__DOT__inst)) 
                                       & ((0x63U != 
                                           (0x707fU 
                                            & vlSelf->Top__DOT__inst)) 
                                          & ((0x1063U 
                                              != (0x707fU 
                                                  & vlSelf->Top__DOT__inst)) 
                                             & ((0x4063U 
                                                 != 
                                                 (0x707fU 
                                                  & vlSelf->Top__DOT__inst)) 
                                                & ((0x5063U 
                                                    != 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst)) 
                                                   & ((0x6063U 
                                                       != 
                                                       (0x707fU 
                                                        & vlSelf->Top__DOT__inst)) 
                                                      & ((0x7063U 
                                                          != 
                                                          (0x707fU 
                                                           & vlSelf->Top__DOT__inst)) 
                                                         & ((3U 
                                                             != 
                                                             (0x707fU 
                                                              & vlSelf->Top__DOT__inst)) 
                                                            & ((0x1003U 
                                                                != 
                                                                (0x707fU 
                                                                 & vlSelf->Top__DOT__inst)) 
                                                               & ((0x2003U 
                                                                   != 
                                                                   (0x707fU 
                                                                    & vlSelf->Top__DOT__inst)) 
                                                                  & ((0x4003U 
                                                                      != 
                                                                      (0x707fU 
                                                                       & vlSelf->Top__DOT__inst)) 
                                                                     & ((0x5003U 
                                                                         != 
                                                                         (0x707fU 
                                                                          & vlSelf->Top__DOT__inst)) 
                                                                        & ((0x23U 
                                                                            != 
                                                                            (0x707fU 
                                                                             & vlSelf->Top__DOT__inst)) 
                                                                           & ((0x1023U 
                                                                               != 
                                                                               (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                              & ((0x2023U 
                                                                                != 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                & ((0x13U 
                                                                                != 
                                                                                (0x707fU 
                                                                                & vlSelf->Top__DOT__inst)) 
                                                                                & (IData)(Top__DOT___information_T_727))))))))))))))))));
    Top__DOT___information_T_357 = ((0x2023U == (0x707fU 
                                                 & vlSelf->Top__DOT__inst))
                                     ? 1U : ((0x13U 
                                              == (0x707fU 
                                                  & vlSelf->Top__DOT__inst))
                                              ? 1U : 
                                             ((0x2013U 
                                               == (0x707fU 
                                                   & vlSelf->Top__DOT__inst))
                                               ? 6U
                                               : ((0x3013U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 7U
                                                   : 
                                                  ((0x4013U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 5U
                                                    : 
                                                   ((0x6013U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 4U
                                                     : 
                                                    ((0x7013U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 3U
                                                      : 
                                                     ((0x1013U 
                                                       == 
                                                       (0xfc00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 8U
                                                       : 
                                                      ((0x5013U 
                                                        == 
                                                        (0xfc00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 9U
                                                        : 
                                                       ((0x40005013U 
                                                         == 
                                                         (0xfc00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 0xaU
                                                         : 
                                                        ((0x33U 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 1U
                                                          : 
                                                         ((0x40000033U 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 2U
                                                           : 
                                                          ((0x1033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 8U
                                                            : 
                                                           ((0x2033U 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 6U
                                                             : 
                                                            ((0x3033U 
                                                              == 
                                                              (0xfe00707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 7U
                                                              : (IData)(Top__DOT___information_T_342))))))))))))))));
    Top__DOT___information_T_232 = ((0x13U == (0x707fU 
                                               & vlSelf->Top__DOT__inst))
                                     ? 1U : ((0x2013U 
                                              == (0x707fU 
                                                  & vlSelf->Top__DOT__inst))
                                              ? 1U : 
                                             ((0x3013U 
                                               == (0x707fU 
                                                   & vlSelf->Top__DOT__inst))
                                               ? 1U
                                               : ((0x4013U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 1U
                                                   : 
                                                  ((0x6013U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 1U
                                                    : 
                                                   ((0x7013U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 1U
                                                     : 
                                                    ((0x1013U 
                                                      == 
                                                      (0xfc00707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 1U
                                                      : 
                                                     ((0x5013U 
                                                       == 
                                                       (0xfc00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 1U
                                                       : 
                                                      ((0x40005013U 
                                                        == 
                                                        (0xfc00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 1U
                                                        : 
                                                       ((0x33U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 0U
                                                         : 
                                                        ((0x40000033U 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 0U
                                                          : 
                                                         ((0x1033U 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 0U
                                                           : 
                                                          ((0x2033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 0U
                                                            : 
                                                           ((0x3033U 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 0U
                                                             : 
                                                            ((0x4033U 
                                                              == 
                                                              (0xfe00707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 0U
                                                              : (IData)(Top__DOT___information_T_217))))))))))))))));
    if ((0x2013U == (0x707fU & vlSelf->Top__DOT__inst))) {
        Top__DOT___information_T_603 = 3U;
        Top__DOT___information_T_541 = 2U;
    } else {
        Top__DOT___information_T_603 = ((0x3013U == 
                                         (0x707fU & vlSelf->Top__DOT__inst))
                                         ? 3U : ((0x4013U 
                                                  == 
                                                  (0x707fU 
                                                   & vlSelf->Top__DOT__inst))
                                                  ? 3U
                                                  : 
                                                 ((0x6013U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 3U
                                                   : 
                                                  ((0x7013U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 3U
                                                    : 
                                                   ((0x1013U 
                                                     == 
                                                     (0xfc00707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 3U
                                                     : 
                                                    ((0x5013U 
                                                      == 
                                                      (0xfc00707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 3U
                                                      : 
                                                     ((0x40005013U 
                                                       == 
                                                       (0xfc00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 3U
                                                       : 
                                                      ((0x33U 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 2U
                                                        : 
                                                       ((0x40000033U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 2U
                                                         : 
                                                        ((0x1033U 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 2U
                                                          : 
                                                         ((0x2033U 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 2U
                                                           : 
                                                          ((0x3033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 2U
                                                            : 
                                                           ((0x4033U 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 2U
                                                             : 
                                                            ((0x5033U 
                                                              == 
                                                              (0xfe00707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 2U
                                                              : (IData)(Top__DOT___information_T_588)))))))))))))));
        Top__DOT___information_T_541 = ((0x3013U == 
                                         (0x707fU & vlSelf->Top__DOT__inst))
                                         ? 2U : ((0x4013U 
                                                  == 
                                                  (0x707fU 
                                                   & vlSelf->Top__DOT__inst))
                                                  ? 2U
                                                  : 
                                                 ((0x6013U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 2U
                                                   : 
                                                  ((0x7013U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 2U
                                                    : 
                                                   ((0x1013U 
                                                     == 
                                                     (0xfc00707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 2U
                                                     : 
                                                    ((0x5013U 
                                                      == 
                                                      (0xfc00707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 2U
                                                      : 
                                                     ((0x40005013U 
                                                       == 
                                                       (0xfc00707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 2U
                                                       : 
                                                      ((0x33U 
                                                        == 
                                                        (0xfe00707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 2U
                                                        : 
                                                       ((0x40000033U 
                                                         == 
                                                         (0xfe00707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 2U
                                                         : 
                                                        ((0x1033U 
                                                          == 
                                                          (0xfe00707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 2U
                                                          : 
                                                         ((0x2033U 
                                                           == 
                                                           (0xfe00707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 2U
                                                           : 
                                                          ((0x3033U 
                                                            == 
                                                            (0xfe00707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 2U
                                                            : 
                                                           ((0x4033U 
                                                             == 
                                                             (0xfe00707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 2U
                                                             : 
                                                            ((0x5033U 
                                                              == 
                                                              (0xfe00707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 2U
                                                              : (IData)(Top__DOT___information_T_526)))))))))))))));
    }
    if ((0x37U == (0x7fU & vlSelf->Top__DOT__inst))) {
        vlSelf->Top__DOT__fu_type = 0U;
        vlSelf->Top__DOT__information_5 = 0U;
    } else {
        vlSelf->Top__DOT__fu_type = ((0x17U == (0x7fU 
                                                & vlSelf->Top__DOT__inst))
                                      ? 0U : ((0x6fU 
                                               == (0x7fU 
                                                   & vlSelf->Top__DOT__inst))
                                               ? 1U
                                               : ((0x67U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 1U
                                                   : (IData)(Top__DOT___information_T_308))));
        vlSelf->Top__DOT__information_5 = ((0x17U == 
                                            (0x7fU 
                                             & vlSelf->Top__DOT__inst))
                                            ? 0U : 
                                           ((0x6fU 
                                             == (0x7fU 
                                                 & vlSelf->Top__DOT__inst))
                                             ? 0U : 
                                            ((0x67U 
                                              == (0x707fU 
                                                  & vlSelf->Top__DOT__inst))
                                              ? 0U : (IData)(Top__DOT___information_T_494))));
    }
    Top__DOT__alu_io_rv64 = ((0x37U != (0x7fU & vlSelf->Top__DOT__inst)) 
                             & ((0x17U != (0x7fU & vlSelf->Top__DOT__inst)) 
                                & (IData)(Top__DOT___information_T_744)));
    Top__DOT___information_T_372 = ((0x6fU == (0x7fU 
                                               & vlSelf->Top__DOT__inst))
                                     ? 0U : ((0x67U 
                                              == (0x707fU 
                                                  & vlSelf->Top__DOT__inst))
                                              ? 0U : 
                                             ((0x63U 
                                               == (0x707fU 
                                                   & vlSelf->Top__DOT__inst))
                                               ? 0U
                                               : ((0x1063U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 0U
                                                   : 
                                                  ((0x4063U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 0U
                                                    : 
                                                   ((0x5063U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 0U
                                                     : 
                                                    ((0x6063U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 0U
                                                      : 
                                                     ((0x7063U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 0U
                                                       : 
                                                      ((3U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 1U
                                                        : 
                                                       ((0x1003U 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 1U
                                                         : 
                                                        ((0x2003U 
                                                          == 
                                                          (0x707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 1U
                                                          : 
                                                         ((0x4003U 
                                                           == 
                                                           (0x707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 1U
                                                           : 
                                                          ((0x5003U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 1U
                                                            : 
                                                           ((0x23U 
                                                             == 
                                                             (0x707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 1U
                                                             : 
                                                            ((0x1023U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 1U
                                                              : (IData)(Top__DOT___information_T_357))))))))))))))));
    Top__DOT___information_T_247 = ((0x67U == (0x707fU 
                                               & vlSelf->Top__DOT__inst))
                                     ? 1U : ((0x63U 
                                              == (0x707fU 
                                                  & vlSelf->Top__DOT__inst))
                                              ? 3U : 
                                             ((0x1063U 
                                               == (0x707fU 
                                                   & vlSelf->Top__DOT__inst))
                                               ? 3U
                                               : ((0x4063U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 3U
                                                   : 
                                                  ((0x5063U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 3U
                                                    : 
                                                   ((0x6063U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 3U
                                                     : 
                                                    ((0x7063U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 3U
                                                      : 
                                                     ((3U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 1U
                                                       : 
                                                      ((0x1003U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 1U
                                                        : 
                                                       ((0x2003U 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 1U
                                                         : 
                                                        ((0x4003U 
                                                          == 
                                                          (0x707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 1U
                                                          : 
                                                         ((0x5003U 
                                                           == 
                                                           (0x707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 1U
                                                           : 
                                                          ((0x23U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 2U
                                                            : 
                                                           ((0x1023U 
                                                             == 
                                                             (0x707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 2U
                                                             : 
                                                            ((0x2023U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 2U
                                                              : (IData)(Top__DOT___information_T_232))))))))))))))));
    if ((0x63U == (0x707fU & vlSelf->Top__DOT__inst))) {
        Top__DOT___information_T_618 = 2U;
        Top__DOT___information_T_556 = 2U;
    } else {
        Top__DOT___information_T_618 = ((0x1063U == 
                                         (0x707fU & vlSelf->Top__DOT__inst))
                                         ? 2U : ((0x4063U 
                                                  == 
                                                  (0x707fU 
                                                   & vlSelf->Top__DOT__inst))
                                                  ? 2U
                                                  : 
                                                 ((0x5063U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 2U
                                                   : 
                                                  ((0x6063U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 2U
                                                    : 
                                                   ((0x7063U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 2U
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 3U
                                                      : 
                                                     ((0x1003U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 3U
                                                       : 
                                                      ((0x2003U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 3U
                                                        : 
                                                       ((0x4003U 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 3U
                                                         : 
                                                        ((0x5003U 
                                                          == 
                                                          (0x707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 3U
                                                          : 
                                                         ((0x23U 
                                                           == 
                                                           (0x707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 3U
                                                           : 
                                                          ((0x1023U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 3U
                                                            : 
                                                           ((0x2023U 
                                                             == 
                                                             (0x707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 3U
                                                             : 
                                                            ((0x13U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 3U
                                                              : (IData)(Top__DOT___information_T_603)))))))))))))));
        Top__DOT___information_T_556 = ((0x1063U == 
                                         (0x707fU & vlSelf->Top__DOT__inst))
                                         ? 2U : ((0x4063U 
                                                  == 
                                                  (0x707fU 
                                                   & vlSelf->Top__DOT__inst))
                                                  ? 2U
                                                  : 
                                                 ((0x5063U 
                                                   == 
                                                   (0x707fU 
                                                    & vlSelf->Top__DOT__inst))
                                                   ? 2U
                                                   : 
                                                  ((0x6063U 
                                                    == 
                                                    (0x707fU 
                                                     & vlSelf->Top__DOT__inst))
                                                    ? 2U
                                                    : 
                                                   ((0x7063U 
                                                     == 
                                                     (0x707fU 
                                                      & vlSelf->Top__DOT__inst))
                                                     ? 2U
                                                     : 
                                                    ((3U 
                                                      == 
                                                      (0x707fU 
                                                       & vlSelf->Top__DOT__inst))
                                                      ? 2U
                                                      : 
                                                     ((0x1003U 
                                                       == 
                                                       (0x707fU 
                                                        & vlSelf->Top__DOT__inst))
                                                       ? 2U
                                                       : 
                                                      ((0x2003U 
                                                        == 
                                                        (0x707fU 
                                                         & vlSelf->Top__DOT__inst))
                                                        ? 2U
                                                        : 
                                                       ((0x4003U 
                                                         == 
                                                         (0x707fU 
                                                          & vlSelf->Top__DOT__inst))
                                                         ? 2U
                                                         : 
                                                        ((0x5003U 
                                                          == 
                                                          (0x707fU 
                                                           & vlSelf->Top__DOT__inst))
                                                          ? 2U
                                                          : 
                                                         ((0x23U 
                                                           == 
                                                           (0x707fU 
                                                            & vlSelf->Top__DOT__inst))
                                                           ? 2U
                                                           : 
                                                          ((0x1023U 
                                                            == 
                                                            (0x707fU 
                                                             & vlSelf->Top__DOT__inst))
                                                            ? 2U
                                                            : 
                                                           ((0x2023U 
                                                             == 
                                                             (0x707fU 
                                                              & vlSelf->Top__DOT__inst))
                                                             ? 2U
                                                             : 
                                                            ((0x13U 
                                                              == 
                                                              (0x707fU 
                                                               & vlSelf->Top__DOT__inst))
                                                              ? 2U
                                                              : (IData)(Top__DOT___information_T_541)))))))))))))));
    }
    if ((0x37U == (0x7fU & vlSelf->Top__DOT__inst))) {
        Top__DOT__alu_io_aluop = 1U;
        Top__DOT__information_1 = 4U;
        Top__DOT__information_7 = 3U;
        Top__DOT__information_6 = 0U;
    } else {
        Top__DOT__alu_io_aluop = ((0x17U == (0x7fU 
                                             & vlSelf->Top__DOT__inst))
                                   ? 1U : (IData)(Top__DOT___information_T_372));
        Top__DOT__information_1 = ((0x17U == (0x7fU 
                                              & vlSelf->Top__DOT__inst))
                                    ? 4U : ((0x6fU 
                                             == (0x7fU 
                                                 & vlSelf->Top__DOT__inst))
                                             ? 5U : (IData)(Top__DOT___information_T_247)));
        Top__DOT__information_7 = ((0x17U == (0x7fU 
                                              & vlSelf->Top__DOT__inst))
                                    ? 3U : ((0x6fU 
                                             == (0x7fU 
                                                 & vlSelf->Top__DOT__inst))
                                             ? 3U : 
                                            ((0x67U 
                                              == (0x707fU 
                                                  & vlSelf->Top__DOT__inst))
                                              ? 3U : (IData)(Top__DOT___information_T_618))));
        Top__DOT__information_6 = ((0x17U == (0x7fU 
                                              & vlSelf->Top__DOT__inst))
                                    ? 1U : ((0x6fU 
                                             == (0x7fU 
                                                 & vlSelf->Top__DOT__inst))
                                             ? 1U : 
                                            ((0x67U 
                                              == (0x707fU 
                                                  & vlSelf->Top__DOT__inst))
                                              ? 2U : (IData)(Top__DOT___information_T_556))));
    }
    Top__DOT__alu__DOT__srl = ((9U == (IData)(Top__DOT__alu_io_aluop)) 
                               & (IData)(Top__DOT__alu_io_rv64));
    Top__DOT___imm_T_7 = ((4U == (IData)(Top__DOT__information_1))
                           ? (((QData)((IData)(((vlSelf->Top__DOT__inst 
                                                 >> 0x1fU)
                                                 ? 0xffffffffU
                                                 : 0U))) 
                               << 0x20U) | (QData)((IData)(
                                                           (0xfffff000U 
                                                            & vlSelf->Top__DOT__inst))))
                           : ((3U == (IData)(Top__DOT__information_1))
                               ? ((((vlSelf->Top__DOT__inst 
                                     >> 0x1fU) ? 0xfffffffffffffULL
                                     : 0ULL) << 0xcU) 
                                  | (QData)((IData)(
                                                    ((0x800U 
                                                      & (vlSelf->Top__DOT__inst 
                                                         << 4U)) 
                                                     | ((0x7e0U 
                                                         & (vlSelf->Top__DOT__inst 
                                                            >> 0x14U)) 
                                                        | (0x1eU 
                                                           & (vlSelf->Top__DOT__inst 
                                                              >> 7U)))))))
                               : ((2U == (IData)(Top__DOT__information_1))
                                   ? ((((vlSelf->Top__DOT__inst 
                                         >> 0x1fU) ? 0xfffffffffffffULL
                                         : 0ULL) << 0xcU) 
                                      | (QData)((IData)(
                                                        ((0xfe0U 
                                                          & (vlSelf->Top__DOT__inst 
                                                             >> 0x14U)) 
                                                         | (0x1fU 
                                                            & (vlSelf->Top__DOT__inst 
                                                               >> 7U))))))
                                   : ((1U == (IData)(Top__DOT__information_1))
                                       ? ((((vlSelf->Top__DOT__inst 
                                             >> 0x1fU)
                                             ? 0xfffffffffffffULL
                                             : 0ULL) 
                                           << 0xcU) 
                                          | (QData)((IData)(
                                                            (vlSelf->Top__DOT__inst 
                                                             >> 0x14U))))
                                       : 0ULL))));
    Top__DOT___src2_value_T_1 = ((2U == (IData)(Top__DOT__information_7))
                                  ? Top__DOT__regfile_rdata2
                                  : 0ULL);
    Top__DOT___src1_value_T_1 = ((1U == (IData)(Top__DOT__information_6))
                                  ? vlSelf->Top__DOT__pc
                                  : 0ULL);
    vlSelf->Top__DOT__bru_io_imm = ((5U == (IData)(Top__DOT__information_1))
                                     ? Top__DOT__imm_j
                                     : Top__DOT___imm_T_7);
    vlSelf->Top__DOT__alu_io_src1 = ((2U == (IData)(Top__DOT__information_6))
                                      ? Top__DOT__regfile_rdata1
                                      : Top__DOT___src1_value_T_1);
    vlSelf->Top__DOT__bru__DOT___io_br_target_T_6 = 
        (vlSelf->Top__DOT__pc + vlSelf->Top__DOT__bru_io_imm);
    vlSelf->Top__DOT__alu_io_src2 = ((3U == (IData)(Top__DOT__information_7))
                                      ? vlSelf->Top__DOT__bru_io_imm
                                      : Top__DOT___src2_value_T_1);
    Top__DOT__alu__DOT___src1_T_4 = (((0xaU == (IData)(Top__DOT__alu_io_aluop)) 
                                      & (IData)(Top__DOT__alu_io_rv64))
                                      ? (((QData)((IData)(
                                                          ((1U 
                                                            & (IData)(
                                                                      (vlSelf->Top__DOT__alu_io_src1 
                                                                       >> 0x1fU)))
                                                            ? 0xffffffffU
                                                            : 0U))) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->Top__DOT__alu_io_src1)))
                                      : vlSelf->Top__DOT__alu_io_src1);
    Top__DOT__alu__DOT__shamt = (0x3fU & ((IData)(Top__DOT__alu_io_rv64)
                                           ? (0x1fU 
                                              & (IData)(vlSelf->Top__DOT__alu_io_src2))
                                           : (IData)(vlSelf->Top__DOT__alu_io_src2)));
    Top__DOT__alu__DOT__src1 = ((IData)(Top__DOT__alu__DOT__srl)
                                 ? (QData)((IData)(vlSelf->Top__DOT__alu_io_src1))
                                 : Top__DOT__alu__DOT___src1_T_4);
    VL_EXTEND_WQ(128,64, __Vtemp1, Top__DOT__alu__DOT__src1);
    VL_EXTEND_WQ(128,64, __Vtemp2, vlSelf->Top__DOT__alu_io_src2);
    VL_MUL_W(4, __Vtemp3, __Vtemp1, __Vtemp2);
    Top__DOT__alu__DOT___tmp_result_T_16[0U] = __Vtemp3[0U];
    Top__DOT__alu__DOT___tmp_result_T_16[1U] = __Vtemp3[1U];
    Top__DOT__alu__DOT___tmp_result_T_16[2U] = __Vtemp3[2U];
    Top__DOT__alu__DOT___tmp_result_T_16[3U] = __Vtemp3[3U];
    VL_EXTENDS_WQ(129,64, __Vtemp6, Top__DOT__alu__DOT__src1);
    __Vtemp7[0U] = __Vtemp6[0U];
    __Vtemp7[1U] = __Vtemp6[1U];
    __Vtemp7[2U] = __Vtemp6[2U];
    __Vtemp7[3U] = __Vtemp6[3U];
    __Vtemp7[4U] = (1U & __Vtemp6[4U]);
    VL_EXTEND_WQ(65,64, __Vtemp9, vlSelf->Top__DOT__alu_io_src2);
    VL_EXTENDS_WW(129,65, __Vtemp10, __Vtemp9);
    __Vtemp11[0U] = __Vtemp10[0U];
    __Vtemp11[1U] = __Vtemp10[1U];
    __Vtemp11[2U] = __Vtemp10[2U];
    __Vtemp11[3U] = __Vtemp10[3U];
    __Vtemp11[4U] = (1U & __Vtemp10[4U]);
    VL_MULS_WWW(129,129,129, __Vtemp12, __Vtemp7, __Vtemp11);
    VL_EXTEND_WQ(128,64, __Vtemp14, (((QData)((IData)(
                                                      __Vtemp12[3U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  __Vtemp12[2U]))));
    VL_EXTENDS_WQ(128,64, __Vtemp15, Top__DOT__alu__DOT__src1);
    VL_EXTENDS_WQ(128,64, __Vtemp16, vlSelf->Top__DOT__alu_io_src2);
    VL_MULS_WWW(128,128,128, __Vtemp17, __Vtemp15, __Vtemp16);
    VL_EXTEND_WQ(128,64, __Vtemp18, (((QData)((IData)(
                                                      __Vtemp17[3U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  __Vtemp17[2U]))));
    VL_EXTEND_WQ(127,64, __Vtemp20, VL_SHIFTRS_QQI(64,64,6, Top__DOT__alu__DOT__src1, (IData)(Top__DOT__alu__DOT__shamt)));
    VL_EXTEND_WQ(127,64, __Vtemp21, (Top__DOT__alu__DOT__src1 
                                     >> (IData)(Top__DOT__alu__DOT__shamt)));
    VL_EXTEND_WQ(127,64, __Vtemp22, Top__DOT__alu__DOT__src1);
    VL_SHIFTL_WWI(127,127,6, __Vtemp23, __Vtemp22, (IData)(Top__DOT__alu__DOT__shamt));
    VL_EXTEND_WQ(127,64, __Vtemp24, ((7U == (IData)(Top__DOT__alu_io_aluop))
                                      ? (QData)((IData)(
                                                        (Top__DOT__alu__DOT__src1 
                                                         < vlSelf->Top__DOT__alu_io_src2)))
                                      : ((6U == (IData)(Top__DOT__alu_io_aluop))
                                          ? (QData)((IData)(
                                                            VL_LTS_IQQ(1,64,64, Top__DOT__alu__DOT__src1, vlSelf->Top__DOT__alu_io_src2)))
                                          : ((5U == (IData)(Top__DOT__alu_io_aluop))
                                              ? (Top__DOT__alu__DOT__src1 
                                                 ^ vlSelf->Top__DOT__alu_io_src2)
                                              : ((4U 
                                                  == (IData)(Top__DOT__alu_io_aluop))
                                                  ? 
                                                 (Top__DOT__alu__DOT__src1 
                                                  | vlSelf->Top__DOT__alu_io_src2)
                                                  : 
                                                 ((3U 
                                                   == (IData)(Top__DOT__alu_io_aluop))
                                                   ? 
                                                  (Top__DOT__alu__DOT__src1 
                                                   & vlSelf->Top__DOT__alu_io_src2)
                                                   : 
                                                  ((2U 
                                                    == (IData)(Top__DOT__alu_io_aluop))
                                                    ? 
                                                   (Top__DOT__alu__DOT__src1 
                                                    - vlSelf->Top__DOT__alu_io_src2)
                                                    : 
                                                   ((1U 
                                                     == (IData)(Top__DOT__alu_io_aluop))
                                                     ? 
                                                    (Top__DOT__alu__DOT__src1 
                                                     + vlSelf->Top__DOT__alu_io_src2)
                                                     : 0ULL))))))));
    if ((0xaU == (IData)(Top__DOT__alu_io_aluop))) {
        __Vtemp31[0U] = __Vtemp20[0U];
        __Vtemp31[1U] = __Vtemp20[1U];
        __Vtemp31[2U] = __Vtemp20[2U];
        __Vtemp31[3U] = (0x7fffffffU & __Vtemp20[3U]);
    } else {
        __Vtemp31[0U] = ((9U == (IData)(Top__DOT__alu_io_aluop))
                          ? __Vtemp21[0U] : ((8U == (IData)(Top__DOT__alu_io_aluop))
                                              ? __Vtemp23[0U]
                                              : __Vtemp24[0U]));
        __Vtemp31[1U] = ((9U == (IData)(Top__DOT__alu_io_aluop))
                          ? __Vtemp21[1U] : ((8U == (IData)(Top__DOT__alu_io_aluop))
                                              ? __Vtemp23[1U]
                                              : __Vtemp24[1U]));
        __Vtemp31[2U] = ((9U == (IData)(Top__DOT__alu_io_aluop))
                          ? __Vtemp21[2U] : ((8U == (IData)(Top__DOT__alu_io_aluop))
                                              ? __Vtemp23[2U]
                                              : __Vtemp24[2U]));
        __Vtemp31[3U] = (0x7fffffffU & ((9U == (IData)(Top__DOT__alu_io_aluop))
                                         ? __Vtemp21[3U]
                                         : ((8U == (IData)(Top__DOT__alu_io_aluop))
                                             ? __Vtemp23[3U]
                                             : __Vtemp24[3U])));
    }
    VL_EXTEND_WW(128,127, __Vtemp32, __Vtemp31);
    if ((0xdU == (IData)(Top__DOT__alu_io_aluop))) {
        Top__DOT__alu__DOT___tmp_result_T_66[0U] = 
            __Vtemp14[0U];
        Top__DOT__alu__DOT___tmp_result_T_66[1U] = 
            __Vtemp14[1U];
        Top__DOT__alu__DOT___tmp_result_T_66[2U] = 
            __Vtemp14[2U];
        Top__DOT__alu__DOT___tmp_result_T_66[3U] = 
            __Vtemp14[3U];
    } else {
        Top__DOT__alu__DOT___tmp_result_T_66[0U] = 
            ((0xcU == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp18[0U] : ((0xbU == (IData)(Top__DOT__alu_io_aluop))
                                  ? Top__DOT__alu__DOT___tmp_result_T_16[0U]
                                  : __Vtemp32[0U]));
        Top__DOT__alu__DOT___tmp_result_T_66[1U] = 
            ((0xcU == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp18[1U] : ((0xbU == (IData)(Top__DOT__alu_io_aluop))
                                  ? Top__DOT__alu__DOT___tmp_result_T_16[1U]
                                  : __Vtemp32[1U]));
        Top__DOT__alu__DOT___tmp_result_T_66[2U] = 
            ((0xcU == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp18[2U] : ((0xbU == (IData)(Top__DOT__alu_io_aluop))
                                  ? Top__DOT__alu__DOT___tmp_result_T_16[2U]
                                  : __Vtemp32[2U]));
        Top__DOT__alu__DOT___tmp_result_T_66[3U] = 
            ((0xcU == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp18[3U] : ((0xbU == (IData)(Top__DOT__alu_io_aluop))
                                  ? Top__DOT__alu__DOT___tmp_result_T_16[3U]
                                  : __Vtemp32[3U]));
    }
    VL_EXTEND_WQ(128,64, __Vtemp39, VL_MODDIV_QQQ(64, Top__DOT__alu__DOT__src1, vlSelf->Top__DOT__alu_io_src2));
    VL_EXTEND_WQ(128,64, __Vtemp40, VL_MODDIVS_QQQ(64, Top__DOT__alu__DOT__src1, vlSelf->Top__DOT__alu_io_src2));
    VL_EXTEND_WQ(128,64, __Vtemp41, VL_DIV_QQQ(64, Top__DOT__alu__DOT__src1, vlSelf->Top__DOT__alu_io_src2));
    VL_EXTENDS_WQ(65,64, __Vtemp44, Top__DOT__alu__DOT__src1);
    __Vtemp45[0U] = __Vtemp44[0U];
    __Vtemp45[1U] = __Vtemp44[1U];
    __Vtemp45[2U] = (1U & __Vtemp44[2U]);
    VL_EXTENDS_WQ(65,64, __Vtemp47, vlSelf->Top__DOT__alu_io_src2);
    __Vtemp48[0U] = __Vtemp47[0U];
    __Vtemp48[1U] = __Vtemp47[1U];
    __Vtemp48[2U] = (1U & __Vtemp47[2U]);
    VL_DIVS_WWW(65, __Vtemp49, __Vtemp45, __Vtemp48);
    __Vtemp50[0U] = __Vtemp49[0U];
    __Vtemp50[1U] = __Vtemp49[1U];
    __Vtemp50[2U] = (1U & __Vtemp49[2U]);
    VL_EXTEND_WW(128,65, __Vtemp51, __Vtemp50);
    VL_EXTEND_WQ(128,64, __Vtemp52, (((QData)((IData)(
                                                      Top__DOT__alu__DOT___tmp_result_T_16[3U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  Top__DOT__alu__DOT___tmp_result_T_16[2U]))));
    if ((0x12U == (IData)(Top__DOT__alu_io_aluop))) {
        Top__DOT__alu__DOT___tmp_result_T_76[0U] = 
            __Vtemp39[0U];
        Top__DOT__alu__DOT___tmp_result_T_76[1U] = 
            __Vtemp39[1U];
        Top__DOT__alu__DOT___tmp_result_T_76[2U] = 
            __Vtemp39[2U];
        Top__DOT__alu__DOT___tmp_result_T_76[3U] = 
            __Vtemp39[3U];
    } else {
        Top__DOT__alu__DOT___tmp_result_T_76[0U] = 
            ((0x11U == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp40[0U] : ((0x10U == (IData)(Top__DOT__alu_io_aluop))
                                  ? __Vtemp41[0U] : 
                                 ((0xfU == (IData)(Top__DOT__alu_io_aluop))
                                   ? __Vtemp51[0U] : 
                                  ((0xeU == (IData)(Top__DOT__alu_io_aluop))
                                    ? __Vtemp52[0U]
                                    : Top__DOT__alu__DOT___tmp_result_T_66[0U]))));
        Top__DOT__alu__DOT___tmp_result_T_76[1U] = 
            ((0x11U == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp40[1U] : ((0x10U == (IData)(Top__DOT__alu_io_aluop))
                                  ? __Vtemp41[1U] : 
                                 ((0xfU == (IData)(Top__DOT__alu_io_aluop))
                                   ? __Vtemp51[1U] : 
                                  ((0xeU == (IData)(Top__DOT__alu_io_aluop))
                                    ? __Vtemp52[1U]
                                    : Top__DOT__alu__DOT___tmp_result_T_66[1U]))));
        Top__DOT__alu__DOT___tmp_result_T_76[2U] = 
            ((0x11U == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp40[2U] : ((0x10U == (IData)(Top__DOT__alu_io_aluop))
                                  ? __Vtemp41[2U] : 
                                 ((0xfU == (IData)(Top__DOT__alu_io_aluop))
                                   ? __Vtemp51[2U] : 
                                  ((0xeU == (IData)(Top__DOT__alu_io_aluop))
                                    ? __Vtemp52[2U]
                                    : Top__DOT__alu__DOT___tmp_result_T_66[2U]))));
        Top__DOT__alu__DOT___tmp_result_T_76[3U] = 
            ((0x11U == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp40[3U] : ((0x10U == (IData)(Top__DOT__alu_io_aluop))
                                  ? __Vtemp41[3U] : 
                                 ((0xfU == (IData)(Top__DOT__alu_io_aluop))
                                   ? __Vtemp51[3U] : 
                                  ((0xeU == (IData)(Top__DOT__alu_io_aluop))
                                    ? __Vtemp52[3U]
                                    : Top__DOT__alu__DOT___tmp_result_T_66[3U]))));
    }
    vlSelf->Top__DOT__alu_io_result = ((IData)(Top__DOT__alu_io_rv64)
                                        ? (((QData)((IData)(
                                                            ((Top__DOT__alu__DOT___tmp_result_T_76[0U] 
                                                              >> 0x1fU)
                                                              ? 0xffffffffU
                                                              : 0U))) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             Top__DOT__alu__DOT___tmp_result_T_76[0U])))
                                        : (((QData)((IData)(
                                                            Top__DOT__alu__DOT___tmp_result_T_76[1U])) 
                                            << 0x20U) 
                                           | (QData)((IData)(
                                                             Top__DOT__alu__DOT___tmp_result_T_76[0U]))));
    Top__DOT___mem_wmask_T_3 = ((7U == (IData)(vlSelf->Top__DOT__information_5))
                                 ? ((6U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                     ? 0xc0U : ((4U 
                                                 == 
                                                 (7U 
                                                  & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                 ? 0x30U
                                                 : 
                                                ((2U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                  ? 0xcU
                                                  : 
                                                 ((0U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                   ? 3U
                                                   : 0U))))
                                 : ((6U == (IData)(vlSelf->Top__DOT__information_5))
                                     ? ((7U == (7U 
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
                                                     : 1U)))))))
                                     : 0U));
    VTop___024root____Vdpiimwrap_Top__DOT__blackbox__DOT__pmem_read_TOP(
                                                                        (&(vlSymsp->__Vscope_Top__blackbox)), 
                                                                        "vsrc/chisel/Blackbox.v", 0x1dU, vlSelf->Top__DOT__alu_io_result, vlSelf->__Vtask_Top__DOT__blackbox__DOT__pmem_read__1__mem_rdata, 
                                                                        ((2U 
                                                                          == (IData)(vlSelf->Top__DOT__fu_type)) 
                                                                         & (IData)(Top__DOT__information_8)));
    vlSelf->Top__DOT__blackbox_mem_rdata = vlSelf->__Vtask_Top__DOT__blackbox__DOT__pmem_read__1__mem_rdata;
    VTop___024root____Vdpiimwrap_Top__DOT__blackbox__DOT__pmem_write_TOP(
                                                                         (&(vlSymsp->__Vscope_Top__blackbox)), 
                                                                         "vsrc/chisel/Blackbox.v", 0x1eU, vlSelf->Top__DOT__alu_io_result, 
                                                                         ((0xbU 
                                                                           == (IData)(vlSelf->Top__DOT__information_5))
                                                                           ? Top__DOT__regfile_rdata2
                                                                           : 
                                                                          ((8U 
                                                                            == (IData)(vlSelf->Top__DOT__information_5))
                                                                            ? 
                                                                           (((QData)((IData)(Top__DOT__regfile_rdata2)) 
                                                                             << 0x20U) 
                                                                            | (QData)((IData)(Top__DOT__regfile_rdata2)))
                                                                            : 
                                                                           ((7U 
                                                                             == (IData)(vlSelf->Top__DOT__information_5))
                                                                             ? 
                                                                            (((QData)((IData)(
                                                                                (0xffffU 
                                                                                & (IData)(Top__DOT__regfile_rdata2)))) 
                                                                              << 0x30U) 
                                                                             | (((QData)((IData)(
                                                                                (0xffffU 
                                                                                & (IData)(Top__DOT__regfile_rdata2)))) 
                                                                                << 0x20U) 
                                                                                | (((QData)((IData)(
                                                                                (0xffffU 
                                                                                & (IData)(Top__DOT__regfile_rdata2)))) 
                                                                                << 0x10U) 
                                                                                | (QData)((IData)(
                                                                                (0xffffU 
                                                                                & (IData)(Top__DOT__regfile_rdata2)))))))
                                                                             : 
                                                                            ((6U 
                                                                              == (IData)(vlSelf->Top__DOT__information_5))
                                                                              ? 
                                                                             (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(Top__DOT__regfile_rdata2)))) 
                                                                               << 0x38U) 
                                                                              | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(Top__DOT__regfile_rdata2)))) 
                                                                                << 0x30U) 
                                                                                | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(Top__DOT__regfile_rdata2)))) 
                                                                                << 0x28U) 
                                                                                | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(Top__DOT__regfile_rdata2)))) 
                                                                                << 0x20U) 
                                                                                | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(Top__DOT__regfile_rdata2)))) 
                                                                                << 0x18U) 
                                                                                | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(Top__DOT__regfile_rdata2)))) 
                                                                                << 0x10U) 
                                                                                | (((QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(Top__DOT__regfile_rdata2)))) 
                                                                                << 8U) 
                                                                                | (QData)((IData)(
                                                                                (0xffU 
                                                                                & (IData)(Top__DOT__regfile_rdata2)))))))))))
                                                                              : 0ULL)))), 
                                                                         ((0xbU 
                                                                           == (IData)(vlSelf->Top__DOT__information_5))
                                                                           ? 0xffU
                                                                           : 
                                                                          ((8U 
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
                                                                            : (IData)(Top__DOT___mem_wmask_T_3))), 
                                                                         ((2U 
                                                                           == (IData)(vlSelf->Top__DOT__fu_type)) 
                                                                          & (~ (IData)(Top__DOT__information_8))));
    Top__DOT___lb_rdata_T_33 = ((5U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                 ? ((((1U & (IData)(
                                                    (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                     >> 0x2fU)))
                                       ? 0xffffffffffffffULL
                                       : 0ULL) << 8U) 
                                    | (QData)((IData)(
                                                      (0xffU 
                                                       & (IData)(
                                                                 (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                  >> 0x28U))))))
                                 : ((4U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                     ? ((((1U & (IData)(
                                                        (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                         >> 0x27U)))
                                           ? 0xffffffffffffffULL
                                           : 0ULL) 
                                         << 8U) | (QData)((IData)(
                                                                  (0xffU 
                                                                   & (IData)(
                                                                             (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                              >> 0x20U))))))
                                     : ((3U == (7U 
                                                & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                         ? ((((1U & (IData)(
                                                            (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                             >> 0x1fU)))
                                               ? 0xffffffffffffffULL
                                               : 0ULL) 
                                             << 8U) 
                                            | (QData)((IData)(
                                                              (0xffU 
                                                               & (IData)(
                                                                         (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                          >> 0x18U))))))
                                         : ((2U == 
                                             (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                             ? ((((1U 
                                                   & (IData)(
                                                             (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                              >> 0x17U)))
                                                   ? 0xffffffffffffffULL
                                                   : 0ULL) 
                                                 << 8U) 
                                                | (QData)((IData)(
                                                                  (0xffU 
                                                                   & (IData)(
                                                                             (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                              >> 0x10U))))))
                                             : ((1U 
                                                 == 
                                                 (7U 
                                                  & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                 ? 
                                                ((((1U 
                                                    & (IData)(
                                                              (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                               >> 0xfU)))
                                                    ? 0xffffffffffffffULL
                                                    : 0ULL) 
                                                  << 8U) 
                                                 | (QData)((IData)(
                                                                   (0xffU 
                                                                    & (IData)(
                                                                              (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                               >> 8U))))))
                                                 : 
                                                ((((1U 
                                                    & (IData)(
                                                              (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                               >> 7U)))
                                                    ? 0xffffffffffffffULL
                                                    : 0ULL) 
                                                  << 8U) 
                                                 | (QData)((IData)(
                                                                   (0xffU 
                                                                    & (IData)(vlSelf->Top__DOT__blackbox_mem_rdata))))))))));
    Top__DOT___load_rdata_T_3 = ((4U == (IData)(vlSelf->Top__DOT__information_5))
                                  ? ((7U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                      ? (QData)((IData)(
                                                        (0xffU 
                                                         & (IData)(
                                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                    >> 0x38U)))))
                                      : ((6U == (7U 
                                                 & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                          ? (QData)((IData)(
                                                            (0xffU 
                                                             & (IData)(
                                                                       (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                        >> 0x30U)))))
                                          : ((5U == 
                                              (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                              ? (QData)((IData)(
                                                                (0xffU 
                                                                 & (IData)(
                                                                           (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                            >> 0x28U)))))
                                              : ((4U 
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
                                                                        & (IData)(vlSelf->Top__DOT__blackbox_mem_rdata)))))))))))
                                  : ((1U == (IData)(vlSelf->Top__DOT__information_5))
                                      ? ((7U == (7U 
                                                 & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                          ? ((((1U 
                                                & (IData)(
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
                                              ? (((
                                                   (1U 
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
                                              : Top__DOT___lb_rdata_T_33))
                                      : 0ULL));
    vlSelf->Top__DOT___load_rdata_T_7 = ((5U == (IData)(vlSelf->Top__DOT__information_5))
                                          ? ((6U == 
                                              (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                              ? (QData)((IData)(
                                                                (0xffffU 
                                                                 & (IData)(
                                                                           (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                            >> 0x30U)))))
                                              : ((4U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                  ? (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(
                                                                               (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                                >> 0x20U)))))
                                                  : 
                                                 ((2U 
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
                                                    : 0ULL))))
                                          : ((2U == (IData)(vlSelf->Top__DOT__information_5))
                                              ? ((6U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                  ? 
                                                 ((((1U 
                                                     & (IData)(
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
                                                  : 
                                                 ((4U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                   ? 
                                                  ((((1U 
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
                                                   : 
                                                  ((2U 
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
                                                     : 0ULL))))
                                              : Top__DOT___load_rdata_T_3));
}

void VTop___024root___eval_initial(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
    VTop___024root___initial__TOP__2(vlSelf);
}

void VTop___024root___eval_settle(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_settle\n"); );
    // Body
    VTop___024root___settle__TOP__3(vlSelf);
}

void VTop___024root___final(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___final\n"); );
}

void VTop___024root___ctor_var_reset(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clock = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->io_pc = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__bru_io_bruop = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT__bru_io_imm = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__alu_io_src1 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__alu_io_src2 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__alu_io_result = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__blackbox_mem_rdata = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__pc = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__inst = VL_RAND_RESET_I(32);
    vlSelf->Top__DOT___information_T_187 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT__fu_type = VL_RAND_RESET_I(2);
    vlSelf->Top__DOT__information_5 = VL_RAND_RESET_I(4);
    vlSelf->Top__DOT___information_T_680 = VL_RAND_RESET_I(1);
    vlSelf->Top__DOT___rf_wdata_T_1 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT___load_rdata_T_7 = VL_RAND_RESET_Q(64);
    vlSelf->Top__DOT__bru__DOT___io_br_target_T_6 = VL_RAND_RESET_Q(64);
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->Top__DOT__regfile__DOT__rf[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->__Vtask_Top__DOT__blackbox__DOT__pmem_read__1__mem_rdata = 0;
    vlSelf->__Vtask_Top__DOT__blackbox__DOT__pmem_read__3__mem_rdata = 0;
}
