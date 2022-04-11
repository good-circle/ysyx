// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop___024root.h"
#include "Vtop__Syms.h"

#include "verilated_dpi.h"

//==========

extern "C" void set_gpr_ptr(const svOpenArrayHandle a);

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__u_regfile__DOT__set_gpr_ptr__Vdpioc2_TOP(const VlUnpacked<QData/*63:0*/, 32> &a) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__u_regfile__DOT__set_gpr_ptr__Vdpioc2_TOP\n"); );
    // Body
    static const int a__Vopenprops__ulims[2] = {31, 0};
    static const VerilatedVarProps a__Vopenprops(VLVT_UINT64, VLVD_IN, VerilatedVarProps::Packed(), 63, 0, VerilatedVarProps::Unpacked(), 1, a__Vopenprops__ulims);
    VerilatedDpiOpenVar a__Vopenarray (&a__Vopenprops, &a);
    set_gpr_ptr(&a__Vopenarray);
}

void Vtop___024root____Vdpiexp_top__DOT__u_blackbox__DOT__finish_TOP(Vtop__Syms* __restrict vlSymsp, CData/*0:0*/ &finish__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiexp_top__DOT__u_blackbox__DOT__finish_TOP\n"); );
    // Variables
    // Body
    finish__Vfuncrtn = (0x100073U == vlSymsp->TOP.top__DOT__inst);
}

extern "C" void pmem_read(long long mem_raddr, long long* mem_rdata, svBit mem_read);

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__u_blackbox__DOT__pmem_read_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, QData/*63:0*/ mem_raddr, QData/*63:0*/ &mem_rdata, CData/*0:0*/ mem_read) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__u_blackbox__DOT__pmem_read_TOP\n"); );
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

VL_INLINE_OPT void Vtop___024root____Vdpiimwrap_top__DOT__u_blackbox__DOT__pmem_write_TOP(const VerilatedScope* __Vscopep, const char* __Vfilenamep, IData/*31:0*/ __Vlineno, QData/*63:0*/ mem_waddr, QData/*63:0*/ mem_wdata, CData/*7:0*/ mem_wmask, CData/*0:0*/ mem_write) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__u_blackbox__DOT__pmem_write_TOP\n"); );
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

VL_INLINE_OPT void Vtop___024root___sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__1\n"); );
    // Variables
    CData/*4:0*/ __Vdlyvdim0__top__DOT__u_regfile__DOT__rf__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__u_regfile__DOT__rf__v0;
    QData/*63:0*/ __Vdlyvval__top__DOT__u_regfile__DOT__rf__v0;
    // Body
    __Vdlyvset__top__DOT__u_regfile__DOT__rf__v0 = 0U;
    if ((1U & ((~ (IData)(vlSelf->top__DOT__sd)) & 
               (~ (IData)(vlSelf->top__DOT__B_Type))))) {
        __Vdlyvval__top__DOT__u_regfile__DOT__rf__v0 
            = ((((((- (QData)((IData)(((0x6fU == (0x7fU 
                                                  & vlSelf->top__DOT__inst)) 
                                       | (IData)(vlSelf->top__DOT__jalr))))) 
                   & (4ULL + vlSelf->pc)) | ((- (QData)((IData)(
                                                                (0x37U 
                                                                 == 
                                                                 (0x7fU 
                                                                  & vlSelf->top__DOT__inst))))) 
                                             & vlSelf->top__DOT__U_extension)) 
                 | ((- (QData)((IData)((0x17U == (0x7fU 
                                                  & vlSelf->top__DOT__inst))))) 
                    & (vlSelf->pc + vlSelf->top__DOT__U_extension))) 
                | ((- (QData)((IData)(vlSelf->top__DOT__addi))) 
                   & vlSelf->top__DOT__alu_result)) 
               | ((- (QData)((IData)(vlSelf->top__DOT__sltiu))) 
                  & vlSelf->top__DOT__alu_result));
        __Vdlyvset__top__DOT__u_regfile__DOT__rf__v0 = 1U;
        __Vdlyvdim0__top__DOT__u_regfile__DOT__rf__v0 
            = (0x1fU & (vlSelf->top__DOT__inst >> 7U));
    }
    vlSelf->pc = ((IData)(vlSelf->rst) ? 0x80000000ULL
                   : (((((0x6fU == (0x7fU & vlSelf->top__DOT__inst)) 
                         | (IData)(vlSelf->top__DOT__jalr)) 
                        | ((IData)(vlSelf->top__DOT__beq) 
                           & (vlSelf->top__DOT__rf_rdata1 
                              == vlSelf->top__DOT__rf_rdata2))) 
                       | ((IData)(vlSelf->top__DOT__bne) 
                          & (vlSelf->top__DOT__rf_rdata1 
                             != vlSelf->top__DOT__rf_rdata2)))
                       ? vlSelf->top__DOT__br_target
                       : (4ULL + vlSelf->pc)));
    if (__Vdlyvset__top__DOT__u_regfile__DOT__rf__v0) {
        vlSelf->top__DOT__u_regfile__DOT__rf[__Vdlyvdim0__top__DOT__u_regfile__DOT__rf__v0] 
            = __Vdlyvval__top__DOT__u_regfile__DOT__rf__v0;
    }
}

VL_INLINE_OPT void Vtop___024root___settle__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__3\n"); );
    // Body
    Vtop___024root____Vdpiimwrap_top__DOT__u_blackbox__DOT__pmem_read_TOP(
                                                                          (&(vlSymsp->__Vscope_top__u_blackbox)), 
                                                                          "vsrc/blackbox.v", 0x22U, vlSelf->pc, vlSelf->__Vtask_top__DOT__u_blackbox__DOT__pmem_read__3__mem_rdata, 
                                                                          (1U 
                                                                           & (~ (IData)(vlSelf->rst))));
    vlSelf->top__DOT__inst_2 = vlSelf->__Vtask_top__DOT__u_blackbox__DOT__pmem_read__3__mem_rdata;
    vlSelf->top__DOT__inst = ((1U & (IData)((vlSelf->pc 
                                             >> 2U)))
                               ? (IData)((vlSelf->top__DOT__inst_2 
                                          >> 0x20U))
                               : (IData)(vlSelf->top__DOT__inst_2));
    vlSelf->top__DOT__rf_rdata2 = ((0U == (0x1fU & 
                                           (vlSelf->top__DOT__inst 
                                            >> 0x14U)))
                                    ? 0ULL : vlSelf->top__DOT__u_regfile__DOT__rf
                                   [(0x1fU & (vlSelf->top__DOT__inst 
                                              >> 0x14U))]);
    vlSelf->top__DOT__rf_rdata1 = ((0U == (0x1fU & 
                                           (vlSelf->top__DOT__inst 
                                            >> 0xfU)))
                                    ? 0ULL : vlSelf->top__DOT__u_regfile__DOT__rf
                                   [(0x1fU & (vlSelf->top__DOT__inst 
                                              >> 0xfU))]);
    vlSelf->top__DOT__U_extension = (((QData)((IData)(
                                                      (- (IData)(
                                                                 (vlSelf->top__DOT__inst 
                                                                  >> 0x1fU))))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (0xfffff000U 
                                                                   & vlSelf->top__DOT__inst))));
    vlSelf->top__DOT__U_Type = ((0x17U == (0x7fU & vlSelf->top__DOT__inst)) 
                                | (0x37U == (0x7fU 
                                             & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__sd = (IData)((0x3023U == (0x707fU 
                                                & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__beq = (IData)((0x63U == (0x707fU 
                                               & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__bne = (IData)((0x1063U == (0x707fU 
                                                 & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__addi = (IData)((0x13U == (0x707fU 
                                                & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__sltiu = (IData)((0x3013U == (0x707fU 
                                                   & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__jalr = (IData)((0x67U == (0x707fU 
                                                & vlSelf->top__DOT__inst)));
    vlSelf->top__DOT__alu_src1 = ((0x6fU == (0x7fU 
                                             & vlSelf->top__DOT__inst))
                                   ? vlSelf->pc : vlSelf->top__DOT__rf_rdata1);
    vlSelf->top__DOT__B_Type = ((IData)(vlSelf->top__DOT__beq) 
                                | (IData)(vlSelf->top__DOT__bne));
    vlSelf->top__DOT__aluop = (((IData)(vlSelf->top__DOT__sltiu) 
                                << 1U) | (((IData)(vlSelf->top__DOT__addi) 
                                           | (IData)(vlSelf->top__DOT__jalr)) 
                                          | (IData)(vlSelf->top__DOT__sd)));
    vlSelf->top__DOT__I_Type = (((IData)(vlSelf->top__DOT__addi) 
                                 | (IData)(vlSelf->top__DOT__jalr)) 
                                | (IData)(vlSelf->top__DOT__sltiu));
    Vtop___024root____Vdpiimwrap_top__DOT__u_blackbox__DOT__pmem_read_TOP(
                                                                          (&(vlSymsp->__Vscope_top__u_blackbox)), 
                                                                          "vsrc/blackbox.v", 0x1dU, 0x80001000ULL, vlSelf->__Vtask_top__DOT__u_blackbox__DOT__pmem_read__1__mem_rdata, 
                                                                          (1U 
                                                                           & (~ (IData)(vlSelf->rst))));
    vlSelf->top__DOT__mem_rdata = vlSelf->__Vtask_top__DOT__u_blackbox__DOT__pmem_read__1__mem_rdata;
    Vtop___024root____Vdpiimwrap_top__DOT__u_blackbox__DOT__pmem_write_TOP(
                                                                           (&(vlSymsp->__Vscope_top__u_blackbox)), 
                                                                           "vsrc/blackbox.v", 0x1eU, 0x80001000ULL, 
                                                                           ((IData)(vlSelf->top__DOT__I_Type)
                                                                             ? 0x1234567887654321ULL
                                                                             : 
                                                                            ((IData)(vlSelf->top__DOT__sd)
                                                                              ? 0x8765432112345678ULL
                                                                              : 
                                                                             ((IData)(vlSelf->top__DOT__U_Type)
                                                                               ? 0ULL
                                                                               : 0x1111111111111111ULL))), 
                                                                           ((IData)(vlSelf->top__DOT__I_Type)
                                                                             ? 0x55U
                                                                             : 
                                                                            ((IData)(vlSelf->top__DOT__sd)
                                                                              ? 0xaaU
                                                                              : 
                                                                             ((IData)(vlSelf->top__DOT__U_Type)
                                                                               ? 0x3cU
                                                                               : 0xc3U))), 
                                                                           (1U 
                                                                            & (~ (IData)(vlSelf->rst))));
    vlSelf->top__DOT__imm_extension = ((((((- (QData)((IData)(vlSelf->top__DOT__I_Type))) 
                                           & (((- (QData)((IData)(
                                                                  (vlSelf->top__DOT__inst 
                                                                   >> 0x1fU)))) 
                                               << 0xcU) 
                                              | (QData)((IData)(
                                                                (vlSelf->top__DOT__inst 
                                                                 >> 0x14U))))) 
                                          | ((- (QData)((IData)(vlSelf->top__DOT__sd))) 
                                             & (((- (QData)((IData)(
                                                                    (vlSelf->top__DOT__inst 
                                                                     >> 0x1fU)))) 
                                                 << 0xcU) 
                                                | (QData)((IData)(
                                                                  ((0xfe0U 
                                                                    & (vlSelf->top__DOT__inst 
                                                                       >> 0x14U)) 
                                                                   | (0x1fU 
                                                                      & (vlSelf->top__DOT__inst 
                                                                         >> 7U)))))))) 
                                         | ((- (QData)((IData)(vlSelf->top__DOT__B_Type))) 
                                            & (((- (QData)((IData)(
                                                                   (vlSelf->top__DOT__inst 
                                                                    >> 0x1fU)))) 
                                                << 0xcU) 
                                               | (QData)((IData)(
                                                                 ((0x800U 
                                                                   & (vlSelf->top__DOT__inst 
                                                                      << 4U)) 
                                                                  | ((0x7e0U 
                                                                      & (vlSelf->top__DOT__inst 
                                                                         >> 0x14U)) 
                                                                     | (0x1eU 
                                                                        & (vlSelf->top__DOT__inst 
                                                                           >> 7U))))))))) 
                                        | ((- (QData)((IData)(
                                                              (0x6fU 
                                                               == 
                                                               (0x7fU 
                                                                & vlSelf->top__DOT__inst))))) 
                                           & (((- (QData)((IData)(
                                                                  (vlSelf->top__DOT__inst 
                                                                   >> 0x1fU)))) 
                                               << 0x14U) 
                                              | (QData)((IData)(
                                                                ((0xff000U 
                                                                  & vlSelf->top__DOT__inst) 
                                                                 | ((0x800U 
                                                                     & (vlSelf->top__DOT__inst 
                                                                        >> 9U)) 
                                                                    | (0x7feU 
                                                                       & (vlSelf->top__DOT__inst 
                                                                          >> 0x14U))))))))) 
                                       | ((- (QData)((IData)(vlSelf->top__DOT__U_Type))) 
                                          & vlSelf->top__DOT__U_extension));
    VL_WRITEF("%x\n",64,vlSelf->top__DOT__mem_rdata);
    vlSelf->top__DOT__alu_result = (((- (QData)((IData)(
                                                        (1U 
                                                         & (IData)(vlSelf->top__DOT__aluop))))) 
                                     & (vlSelf->top__DOT__alu_src1 
                                        + vlSelf->top__DOT__imm_extension)) 
                                    | ((- (QData)((IData)(
                                                          (1U 
                                                           & ((IData)(vlSelf->top__DOT__aluop) 
                                                              >> 1U))))) 
                                       & (QData)((IData)(
                                                         (vlSelf->top__DOT__alu_src1 
                                                          < vlSelf->top__DOT__imm_extension)))));
    vlSelf->top__DOT__br_target = ((IData)(vlSelf->top__DOT__jalr)
                                    ? (0xfffffffffffffffeULL 
                                       & vlSelf->top__DOT__alu_result)
                                    : (vlSelf->pc + vlSelf->top__DOT__imm_extension));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    Vtop___024root___settle__TOP__3(vlSelf);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

QData Vtop___024root___change_request_1(Vtop___024root* vlSelf);

VL_INLINE_OPT QData Vtop___024root___change_request(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___change_request\n"); );
    // Body
    return (Vtop___024root___change_request_1(vlSelf));
}

VL_INLINE_OPT QData Vtop___024root___change_request_1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___change_request_1\n"); );
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
