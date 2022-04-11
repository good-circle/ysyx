// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTop.h for the primary calling header

#include "VTop___024root.h"
#include "VTop__Syms.h"

#include "verilated_dpi.h"

//==========

extern "C" void set_gpr_ptr(const svOpenArrayHandle a);

VL_INLINE_OPT void VTop___024root____Vdpiimwrap_Top__DOT__regfile__DOT__set_gpr_ptr__Vdpioc2_TOP(const VlUnpacked<QData/*63:0*/, 32> &a) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__regfile__DOT__set_gpr_ptr__Vdpioc2_TOP\n"); );
    // Body
    static const int a__Vopenprops__ulims[2] = {31, 0};
    static const VerilatedVarProps a__Vopenprops(VLVT_UINT64, VLVD_IN, VerilatedVarProps::Packed(), 63, 0, VerilatedVarProps::Unpacked(), 1, a__Vopenprops__ulims);
    VerilatedDpiOpenVar a__Vopenarray (&a__Vopenprops, &a);
    set_gpr_ptr(&a__Vopenarray);
}

void VTop___024root____Vdpiexp_Top__DOT__blackbox__DOT__finish_TOP(VTop__Syms* __restrict vlSymsp, CData/*0:0*/ &finish__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiexp_Top__DOT__blackbox__DOT__finish_TOP\n"); );
    // Variables
    // Body
    finish__Vfuncrtn = (1U & (~ ((0x37U == (0x7fU & vlSymsp->TOP.Top__DOT__inst)) 
                                 | (IData)(vlSymsp->TOP.Top__DOT___information_T_187))));
}

extern "C" void pmem_read(long long mem_raddr, long long* mem_rdata, svBit mem_read);

VL_INLINE_OPT void VTop___024root____Vdpiimwrap_Top__DOT__blackbox__DOT__pmem_read_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, QData/*63:0*/ mem_raddr, QData/*63:0*/ &mem_rdata, CData/*0:0*/ mem_read) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__blackbox__DOT__pmem_read_TOP\n"); );
    // Body
    long long mem_raddr__Vcvt;
    for (size_t mem_raddr__Vidx = 0; mem_raddr__Vidx < 1; ++mem_raddr__Vidx) mem_raddr__Vcvt = mem_raddr;
    long long mem_rdata__Vcvt;
    svBit mem_read__Vcvt;
    for (size_t mem_read__Vidx = 0; mem_read__Vidx < 1; ++mem_read__Vidx) mem_read__Vcvt = mem_read;
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    pmem_read(mem_raddr__Vcvt, &mem_rdata__Vcvt, mem_read__Vcvt);
    mem_rdata = mem_rdata__Vcvt;
}

extern "C" void pmem_write(long long mem_waddr, long long mem_wdata, char mem_wmask, svBit mem_write);

VL_INLINE_OPT void VTop___024root____Vdpiimwrap_Top__DOT__blackbox__DOT__pmem_write_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, QData/*63:0*/ mem_waddr, QData/*63:0*/ mem_wdata, CData/*7:0*/ mem_wmask, CData/*0:0*/ mem_write) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root____Vdpiimwrap_Top__DOT__blackbox__DOT__pmem_write_TOP\n"); );
    // Body
    long long mem_waddr__Vcvt;
    for (size_t mem_waddr__Vidx = 0; mem_waddr__Vidx < 1; ++mem_waddr__Vidx) mem_waddr__Vcvt = mem_waddr;
    long long mem_wdata__Vcvt;
    for (size_t mem_wdata__Vidx = 0; mem_wdata__Vidx < 1; ++mem_wdata__Vidx) mem_wdata__Vcvt = mem_wdata;
    char mem_wmask__Vcvt;
    for (size_t mem_wmask__Vidx = 0; mem_wmask__Vidx < 1; ++mem_wmask__Vidx) mem_wmask__Vcvt = mem_wmask;
    svBit mem_write__Vcvt;
    for (size_t mem_write__Vidx = 0; mem_write__Vidx < 1; ++mem_write__Vidx) mem_write__Vcvt = mem_write;
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    pmem_write(mem_waddr__Vcvt, mem_wdata__Vcvt, mem_wmask__Vcvt, mem_write__Vcvt);
}

VL_INLINE_OPT void VTop___024root___sequent__TOP__1(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___sequent__TOP__1\n"); );
    // Variables
    CData/*4:0*/ __Vdlyvdim0__Top__DOT__regfile__DOT__rf__v0;
    CData/*0:0*/ __Vdlyvset__Top__DOT__regfile__DOT__rf__v0;
    QData/*63:0*/ __Vdlyvval__Top__DOT__regfile__DOT__rf__v0;
    // Body
    __Vdlyvset__Top__DOT__regfile__DOT__rf__v0 = 0U;
    if (((0x37U == (0x7fU & vlSelf->Top__DOT__inst)) 
         | ((0x17U == (0x7fU & vlSelf->Top__DOT__inst)) 
            | ((0x6fU == (0x7fU & vlSelf->Top__DOT__inst)) 
               | ((0x67U == (0x707fU & vlSelf->Top__DOT__inst)) 
                  | (IData)(vlSelf->Top__DOT___information_T_680)))))) {
        __Vdlyvval__Top__DOT__regfile__DOT__rf__v0 
            = ((2U == (IData)(vlSelf->Top__DOT__fu_type))
                ? ((0xaU == (IData)(vlSelf->Top__DOT__information_5))
                    ? vlSelf->Top__DOT__blackbox_mem_rdata
                    : ((9U == (IData)(vlSelf->Top__DOT__information_5))
                        ? ((4U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                            ? (QData)((IData)((vlSelf->Top__DOT__blackbox_mem_rdata 
                                               >> 0x20U)))
                            : ((0U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                ? (QData)((IData)(vlSelf->Top__DOT__blackbox_mem_rdata))
                                : 0ULL)) : ((3U == (IData)(vlSelf->Top__DOT__information_5))
                                             ? ((4U 
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
                        : 0ULL)));
        __Vdlyvset__Top__DOT__regfile__DOT__rf__v0 = 1U;
        __Vdlyvdim0__Top__DOT__regfile__DOT__rf__v0 
            = (0x1fU & (vlSelf->Top__DOT__inst >> 7U));
    }
    if (__Vdlyvset__Top__DOT__regfile__DOT__rf__v0) {
        vlSelf->Top__DOT__regfile__DOT__rf[__Vdlyvdim0__Top__DOT__regfile__DOT__rf__v0] 
            = __Vdlyvval__Top__DOT__regfile__DOT__rf__v0;
    }
    vlSelf->Top__DOT__pc = ((IData)(vlSelf->reset) ? 0x80000000ULL
                             : (((8U == (IData)(vlSelf->Top__DOT__bru_io_bruop))
                                  ? (vlSelf->Top__DOT__alu_io_src1 
                                     >= vlSelf->Top__DOT__alu_io_src2)
                                  : ((7U == (IData)(vlSelf->Top__DOT__bru_io_bruop))
                                      ? (vlSelf->Top__DOT__alu_io_src1 
                                         < vlSelf->Top__DOT__alu_io_src2)
                                      : ((6U == (IData)(vlSelf->Top__DOT__bru_io_bruop))
                                          ? VL_GTES_IQQ(1,64,64, vlSelf->Top__DOT__alu_io_src1, vlSelf->Top__DOT__alu_io_src2)
                                          : ((5U == (IData)(vlSelf->Top__DOT__bru_io_bruop))
                                              ? VL_LTS_IQQ(1,64,64, vlSelf->Top__DOT__alu_io_src1, vlSelf->Top__DOT__alu_io_src2)
                                              : ((4U 
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
                                                      == (IData)(vlSelf->Top__DOT__bru_io_bruop)))))))))
                                 ? ((2U == (IData)(vlSelf->Top__DOT__bru_io_bruop))
                                     ? (0xfffffffffffffffeULL 
                                        & (vlSelf->Top__DOT__alu_io_src1 
                                           + vlSelf->Top__DOT__bru_io_imm))
                                     : vlSelf->Top__DOT__bru__DOT___io_br_target_T_6)
                                 : vlSelf->Top__DOT___rf_wdata_T_1));
    vlSelf->Top__DOT___rf_wdata_T_1 = (4ULL + vlSelf->Top__DOT__pc);
    vlSelf->io_pc = vlSelf->Top__DOT__pc;
}

VL_INLINE_OPT void VTop___024root___combo__TOP__4(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___combo__TOP__4\n"); );
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
    VlWide<4>/*127:0*/ __Vtemp63;
    VlWide<4>/*127:0*/ __Vtemp64;
    VlWide<4>/*127:0*/ __Vtemp65;
    VlWide<5>/*159:0*/ __Vtemp68;
    VlWide<5>/*159:0*/ __Vtemp69;
    VlWide<3>/*95:0*/ __Vtemp71;
    VlWide<5>/*159:0*/ __Vtemp72;
    VlWide<5>/*159:0*/ __Vtemp73;
    VlWide<5>/*159:0*/ __Vtemp74;
    VlWide<4>/*127:0*/ __Vtemp76;
    VlWide<4>/*127:0*/ __Vtemp77;
    VlWide<4>/*127:0*/ __Vtemp78;
    VlWide<4>/*127:0*/ __Vtemp79;
    VlWide<4>/*127:0*/ __Vtemp80;
    VlWide<4>/*127:0*/ __Vtemp82;
    VlWide<4>/*127:0*/ __Vtemp83;
    VlWide<4>/*127:0*/ __Vtemp84;
    VlWide<4>/*127:0*/ __Vtemp85;
    VlWide<4>/*127:0*/ __Vtemp86;
    VlWide<4>/*127:0*/ __Vtemp93;
    VlWide<4>/*127:0*/ __Vtemp94;
    VlWide<4>/*127:0*/ __Vtemp101;
    VlWide<4>/*127:0*/ __Vtemp102;
    VlWide<4>/*127:0*/ __Vtemp103;
    VlWide<3>/*95:0*/ __Vtemp106;
    VlWide<3>/*95:0*/ __Vtemp107;
    VlWide<3>/*95:0*/ __Vtemp109;
    VlWide<3>/*95:0*/ __Vtemp110;
    VlWide<3>/*95:0*/ __Vtemp111;
    VlWide<3>/*95:0*/ __Vtemp112;
    VlWide<4>/*127:0*/ __Vtemp113;
    VlWide<4>/*127:0*/ __Vtemp114;
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
    VL_EXTEND_WQ(128,64, __Vtemp63, Top__DOT__alu__DOT__src1);
    VL_EXTEND_WQ(128,64, __Vtemp64, vlSelf->Top__DOT__alu_io_src2);
    VL_MUL_W(4, __Vtemp65, __Vtemp63, __Vtemp64);
    Top__DOT__alu__DOT___tmp_result_T_16[0U] = __Vtemp65[0U];
    Top__DOT__alu__DOT___tmp_result_T_16[1U] = __Vtemp65[1U];
    Top__DOT__alu__DOT___tmp_result_T_16[2U] = __Vtemp65[2U];
    Top__DOT__alu__DOT___tmp_result_T_16[3U] = __Vtemp65[3U];
    VL_EXTENDS_WQ(129,64, __Vtemp68, Top__DOT__alu__DOT__src1);
    __Vtemp69[0U] = __Vtemp68[0U];
    __Vtemp69[1U] = __Vtemp68[1U];
    __Vtemp69[2U] = __Vtemp68[2U];
    __Vtemp69[3U] = __Vtemp68[3U];
    __Vtemp69[4U] = (1U & __Vtemp68[4U]);
    VL_EXTEND_WQ(65,64, __Vtemp71, vlSelf->Top__DOT__alu_io_src2);
    VL_EXTENDS_WW(129,65, __Vtemp72, __Vtemp71);
    __Vtemp73[0U] = __Vtemp72[0U];
    __Vtemp73[1U] = __Vtemp72[1U];
    __Vtemp73[2U] = __Vtemp72[2U];
    __Vtemp73[3U] = __Vtemp72[3U];
    __Vtemp73[4U] = (1U & __Vtemp72[4U]);
    VL_MULS_WWW(129,129,129, __Vtemp74, __Vtemp69, __Vtemp73);
    VL_EXTEND_WQ(128,64, __Vtemp76, (((QData)((IData)(
                                                      __Vtemp74[3U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  __Vtemp74[2U]))));
    VL_EXTENDS_WQ(128,64, __Vtemp77, Top__DOT__alu__DOT__src1);
    VL_EXTENDS_WQ(128,64, __Vtemp78, vlSelf->Top__DOT__alu_io_src2);
    VL_MULS_WWW(128,128,128, __Vtemp79, __Vtemp77, __Vtemp78);
    VL_EXTEND_WQ(128,64, __Vtemp80, (((QData)((IData)(
                                                      __Vtemp79[3U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  __Vtemp79[2U]))));
    VL_EXTEND_WQ(127,64, __Vtemp82, VL_SHIFTRS_QQI(64,64,6, Top__DOT__alu__DOT__src1, (IData)(Top__DOT__alu__DOT__shamt)));
    VL_EXTEND_WQ(127,64, __Vtemp83, (Top__DOT__alu__DOT__src1 
                                     >> (IData)(Top__DOT__alu__DOT__shamt)));
    VL_EXTEND_WQ(127,64, __Vtemp84, Top__DOT__alu__DOT__src1);
    VL_SHIFTL_WWI(127,127,6, __Vtemp85, __Vtemp84, (IData)(Top__DOT__alu__DOT__shamt));
    VL_EXTEND_WQ(127,64, __Vtemp86, ((7U == (IData)(Top__DOT__alu_io_aluop))
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
        __Vtemp93[0U] = __Vtemp82[0U];
        __Vtemp93[1U] = __Vtemp82[1U];
        __Vtemp93[2U] = __Vtemp82[2U];
        __Vtemp93[3U] = (0x7fffffffU & __Vtemp82[3U]);
    } else {
        __Vtemp93[0U] = ((9U == (IData)(Top__DOT__alu_io_aluop))
                          ? __Vtemp83[0U] : ((8U == (IData)(Top__DOT__alu_io_aluop))
                                              ? __Vtemp85[0U]
                                              : __Vtemp86[0U]));
        __Vtemp93[1U] = ((9U == (IData)(Top__DOT__alu_io_aluop))
                          ? __Vtemp83[1U] : ((8U == (IData)(Top__DOT__alu_io_aluop))
                                              ? __Vtemp85[1U]
                                              : __Vtemp86[1U]));
        __Vtemp93[2U] = ((9U == (IData)(Top__DOT__alu_io_aluop))
                          ? __Vtemp83[2U] : ((8U == (IData)(Top__DOT__alu_io_aluop))
                                              ? __Vtemp85[2U]
                                              : __Vtemp86[2U]));
        __Vtemp93[3U] = (0x7fffffffU & ((9U == (IData)(Top__DOT__alu_io_aluop))
                                         ? __Vtemp83[3U]
                                         : ((8U == (IData)(Top__DOT__alu_io_aluop))
                                             ? __Vtemp85[3U]
                                             : __Vtemp86[3U])));
    }
    VL_EXTEND_WW(128,127, __Vtemp94, __Vtemp93);
    if ((0xdU == (IData)(Top__DOT__alu_io_aluop))) {
        Top__DOT__alu__DOT___tmp_result_T_66[0U] = 
            __Vtemp76[0U];
        Top__DOT__alu__DOT___tmp_result_T_66[1U] = 
            __Vtemp76[1U];
        Top__DOT__alu__DOT___tmp_result_T_66[2U] = 
            __Vtemp76[2U];
        Top__DOT__alu__DOT___tmp_result_T_66[3U] = 
            __Vtemp76[3U];
    } else {
        Top__DOT__alu__DOT___tmp_result_T_66[0U] = 
            ((0xcU == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp80[0U] : ((0xbU == (IData)(Top__DOT__alu_io_aluop))
                                  ? Top__DOT__alu__DOT___tmp_result_T_16[0U]
                                  : __Vtemp94[0U]));
        Top__DOT__alu__DOT___tmp_result_T_66[1U] = 
            ((0xcU == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp80[1U] : ((0xbU == (IData)(Top__DOT__alu_io_aluop))
                                  ? Top__DOT__alu__DOT___tmp_result_T_16[1U]
                                  : __Vtemp94[1U]));
        Top__DOT__alu__DOT___tmp_result_T_66[2U] = 
            ((0xcU == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp80[2U] : ((0xbU == (IData)(Top__DOT__alu_io_aluop))
                                  ? Top__DOT__alu__DOT___tmp_result_T_16[2U]
                                  : __Vtemp94[2U]));
        Top__DOT__alu__DOT___tmp_result_T_66[3U] = 
            ((0xcU == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp80[3U] : ((0xbU == (IData)(Top__DOT__alu_io_aluop))
                                  ? Top__DOT__alu__DOT___tmp_result_T_16[3U]
                                  : __Vtemp94[3U]));
    }
    VL_EXTEND_WQ(128,64, __Vtemp101, VL_MODDIV_QQQ(64, Top__DOT__alu__DOT__src1, vlSelf->Top__DOT__alu_io_src2));
    VL_EXTEND_WQ(128,64, __Vtemp102, VL_MODDIVS_QQQ(64, Top__DOT__alu__DOT__src1, vlSelf->Top__DOT__alu_io_src2));
    VL_EXTEND_WQ(128,64, __Vtemp103, VL_DIV_QQQ(64, Top__DOT__alu__DOT__src1, vlSelf->Top__DOT__alu_io_src2));
    VL_EXTENDS_WQ(65,64, __Vtemp106, Top__DOT__alu__DOT__src1);
    __Vtemp107[0U] = __Vtemp106[0U];
    __Vtemp107[1U] = __Vtemp106[1U];
    __Vtemp107[2U] = (1U & __Vtemp106[2U]);
    VL_EXTENDS_WQ(65,64, __Vtemp109, vlSelf->Top__DOT__alu_io_src2);
    __Vtemp110[0U] = __Vtemp109[0U];
    __Vtemp110[1U] = __Vtemp109[1U];
    __Vtemp110[2U] = (1U & __Vtemp109[2U]);
    VL_DIVS_WWW(65, __Vtemp111, __Vtemp107, __Vtemp110);
    __Vtemp112[0U] = __Vtemp111[0U];
    __Vtemp112[1U] = __Vtemp111[1U];
    __Vtemp112[2U] = (1U & __Vtemp111[2U]);
    VL_EXTEND_WW(128,65, __Vtemp113, __Vtemp112);
    VL_EXTEND_WQ(128,64, __Vtemp114, (((QData)((IData)(
                                                       Top__DOT__alu__DOT___tmp_result_T_16[3U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   Top__DOT__alu__DOT___tmp_result_T_16[2U]))));
    if ((0x12U == (IData)(Top__DOT__alu_io_aluop))) {
        Top__DOT__alu__DOT___tmp_result_T_76[0U] = 
            __Vtemp101[0U];
        Top__DOT__alu__DOT___tmp_result_T_76[1U] = 
            __Vtemp101[1U];
        Top__DOT__alu__DOT___tmp_result_T_76[2U] = 
            __Vtemp101[2U];
        Top__DOT__alu__DOT___tmp_result_T_76[3U] = 
            __Vtemp101[3U];
    } else {
        Top__DOT__alu__DOT___tmp_result_T_76[0U] = 
            ((0x11U == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp102[0U] : ((0x10U == (IData)(Top__DOT__alu_io_aluop))
                                   ? __Vtemp103[0U]
                                   : ((0xfU == (IData)(Top__DOT__alu_io_aluop))
                                       ? __Vtemp113[0U]
                                       : ((0xeU == (IData)(Top__DOT__alu_io_aluop))
                                           ? __Vtemp114[0U]
                                           : Top__DOT__alu__DOT___tmp_result_T_66[0U]))));
        Top__DOT__alu__DOT___tmp_result_T_76[1U] = 
            ((0x11U == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp102[1U] : ((0x10U == (IData)(Top__DOT__alu_io_aluop))
                                   ? __Vtemp103[1U]
                                   : ((0xfU == (IData)(Top__DOT__alu_io_aluop))
                                       ? __Vtemp113[1U]
                                       : ((0xeU == (IData)(Top__DOT__alu_io_aluop))
                                           ? __Vtemp114[1U]
                                           : Top__DOT__alu__DOT___tmp_result_T_66[1U]))));
        Top__DOT__alu__DOT___tmp_result_T_76[2U] = 
            ((0x11U == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp102[2U] : ((0x10U == (IData)(Top__DOT__alu_io_aluop))
                                   ? __Vtemp103[2U]
                                   : ((0xfU == (IData)(Top__DOT__alu_io_aluop))
                                       ? __Vtemp113[2U]
                                       : ((0xeU == (IData)(Top__DOT__alu_io_aluop))
                                           ? __Vtemp114[2U]
                                           : Top__DOT__alu__DOT___tmp_result_T_66[2U]))));
        Top__DOT__alu__DOT___tmp_result_T_76[3U] = 
            ((0x11U == (IData)(Top__DOT__alu_io_aluop))
              ? __Vtemp102[3U] : ((0x10U == (IData)(Top__DOT__alu_io_aluop))
                                   ? __Vtemp103[3U]
                                   : ((0xfU == (IData)(Top__DOT__alu_io_aluop))
                                       ? __Vtemp113[3U]
                                       : ((0xeU == (IData)(Top__DOT__alu_io_aluop))
                                           ? __Vtemp114[3U]
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

void VTop___024root___eval(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clock) & (~ (IData)(vlSelf->__Vclklast__TOP__clock)))) {
        VTop___024root___sequent__TOP__1(vlSelf);
    }
    VTop___024root___combo__TOP__4(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clock = vlSelf->clock;
}

QData VTop___024root___change_request_1(VTop___024root* vlSelf);

VL_INLINE_OPT QData VTop___024root___change_request(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___change_request\n"); );
    // Body
    return (VTop___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData VTop___024root___change_request_1(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VTop___024root___eval_debug_assertions(VTop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clock & 0xfeU))) {
        Verilated::overWidthError("clock");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
