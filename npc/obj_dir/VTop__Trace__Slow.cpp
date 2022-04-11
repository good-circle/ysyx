// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VTop__Syms.h"


void VTop___024root__traceInitSub0(VTop___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VTop___024root__traceInitTop(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VTop___024root__traceInitSub0(vlSelf, tracep);
    }
}

void VTop___024root__traceInitSub0(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+207,"clock", false,-1);
        tracep->declBit(c+208,"reset", false,-1);
        tracep->declQuad(c+209,"io_pc", false,-1, 63,0);
        tracep->declBit(c+207,"Top clock", false,-1);
        tracep->declBit(c+208,"Top reset", false,-1);
        tracep->declQuad(c+209,"Top io_pc", false,-1, 63,0);
        tracep->declBus(c+67,"Top bru_io_bruop", false,-1, 3,0);
        tracep->declQuad(c+68,"Top bru_io_src1", false,-1, 63,0);
        tracep->declQuad(c+70,"Top bru_io_src2", false,-1, 63,0);
        tracep->declQuad(c+1,"Top bru_io_pc", false,-1, 63,0);
        tracep->declQuad(c+72,"Top bru_io_imm", false,-1, 63,0);
        tracep->declBit(c+74,"Top bru_io_br_taken", false,-1);
        tracep->declQuad(c+211,"Top bru_io_br_target", false,-1, 63,0);
        tracep->declBus(c+75,"Top alu_io_aluop", false,-1, 4,0);
        tracep->declBit(c+76,"Top alu_io_rv64", false,-1);
        tracep->declQuad(c+68,"Top alu_io_src1", false,-1, 63,0);
        tracep->declQuad(c+70,"Top alu_io_src2", false,-1, 63,0);
        tracep->declQuad(c+77,"Top alu_io_result", false,-1, 63,0);
        tracep->declBit(c+207,"Top regfile_clock", false,-1);
        tracep->declBus(c+79,"Top regfile_raddr1", false,-1, 4,0);
        tracep->declQuad(c+80,"Top regfile_rdata1", false,-1, 63,0);
        tracep->declBus(c+82,"Top regfile_raddr2", false,-1, 4,0);
        tracep->declQuad(c+83,"Top regfile_rdata2", false,-1, 63,0);
        tracep->declBus(c+85,"Top regfile_waddr", false,-1, 4,0);
        tracep->declQuad(c+213,"Top regfile_wdata", false,-1, 63,0);
        tracep->declBit(c+86,"Top regfile_wen", false,-1);
        tracep->declBit(c+87,"Top blackbox_mem_read", false,-1);
        tracep->declQuad(c+77,"Top blackbox_mem_raddr", false,-1, 63,0);
        tracep->declQuad(c+88,"Top blackbox_mem_rdata", false,-1, 63,0);
        tracep->declBit(c+90,"Top blackbox_mem_write", false,-1);
        tracep->declQuad(c+77,"Top blackbox_mem_waddr", false,-1, 63,0);
        tracep->declBus(c+91,"Top blackbox_mem_wmask", false,-1, 7,0);
        tracep->declQuad(c+92,"Top blackbox_mem_wdata", false,-1, 63,0);
        tracep->declBit(c+215,"Top blackbox_inst_ready", false,-1);
        tracep->declQuad(c+1,"Top blackbox_pc", false,-1, 63,0);
        tracep->declQuad(c+94,"Top blackbox_inst_2", false,-1, 63,0);
        tracep->declBit(c+96,"Top blackbox_ebreak", false,-1);
        tracep->declQuad(c+1,"Top pc", false,-1, 63,0);
        tracep->declQuad(c+94,"Top inst_2", false,-1, 63,0);
        tracep->declBus(c+97,"Top inst", false,-1, 31,0);
        tracep->declQuad(c+98,"Top imm_i_hi", false,-1, 51,0);
        tracep->declBus(c+100,"Top imm_i_lo", false,-1, 11,0);
        tracep->declQuad(c+101,"Top imm_i", false,-1, 63,0);
        tracep->declBus(c+103,"Top imm_s_hi_lo", false,-1, 6,0);
        tracep->declBus(c+85,"Top imm_s_lo", false,-1, 4,0);
        tracep->declQuad(c+104,"Top imm_s", false,-1, 63,0);
        tracep->declBit(c+106,"Top imm_b_hi_hi_lo", false,-1);
        tracep->declBus(c+107,"Top imm_b_hi_lo", false,-1, 5,0);
        tracep->declBus(c+108,"Top imm_b_lo_hi", false,-1, 3,0);
        tracep->declQuad(c+109,"Top imm_b", false,-1, 63,0);
        tracep->declBus(c+111,"Top imm_u_hi_hi", false,-1, 31,0);
        tracep->declBus(c+112,"Top imm_u_hi_lo", false,-1, 19,0);
        tracep->declQuad(c+113,"Top imm_u", false,-1, 63,0);
        tracep->declQuad(c+115,"Top imm_j_hi_hi_hi", false,-1, 43,0);
        tracep->declBus(c+117,"Top imm_j_hi_hi_lo", false,-1, 7,0);
        tracep->declBit(c+118,"Top imm_j_hi_lo", false,-1);
        tracep->declBus(c+119,"Top imm_j_lo_hi", false,-1, 9,0);
        tracep->declQuad(c+120,"Top imm_j", false,-1, 63,0);
        tracep->declBit(c+122,"Top information_0", false,-1);
        tracep->declBus(c+123,"Top information_1", false,-1, 2,0);
        tracep->declBus(c+124,"Top fu_type", false,-1, 1,0);
        tracep->declBus(c+125,"Top information_5", false,-1, 3,0);
        tracep->declBus(c+126,"Top information_6", false,-1, 1,0);
        tracep->declBus(c+127,"Top information_7", false,-1, 1,0);
        tracep->declBit(c+128,"Top information_8", false,-1);
        tracep->declQuad(c+72,"Top imm", false,-1, 63,0);
        tracep->declQuad(c+80,"Top rs1_value", false,-1, 63,0);
        tracep->declQuad(c+83,"Top rs2_value", false,-1, 63,0);
        tracep->declQuad(c+77,"Top alu_result", false,-1, 63,0);
        tracep->declQuad(c+88,"Top mem_rdata", false,-1, 63,0);
        tracep->declBus(c+129,"Top raddr_low", false,-1, 2,0);
        tracep->declBus(c+130,"Top lwu_rdata_lo_1", false,-1, 31,0);
        tracep->declBus(c+131,"Top lwu_rdata_lo", false,-1, 31,0);
        tracep->declQuad(c+132,"Top lwu_rdata", false,-1, 63,0);
        tracep->declBus(c+134,"Top lw_rdata_hi_1", false,-1, 31,0);
        tracep->declBus(c+135,"Top lw_rdata_hi", false,-1, 31,0);
        tracep->declQuad(c+136,"Top lw_rdata", false,-1, 63,0);
        tracep->declBus(c+138,"Top lhu_rdata_lo_3", false,-1, 15,0);
        tracep->declBus(c+139,"Top lhu_rdata_lo_2", false,-1, 15,0);
        tracep->declBus(c+140,"Top lhu_rdata_lo_1", false,-1, 15,0);
        tracep->declBus(c+141,"Top lhu_rdata_lo", false,-1, 15,0);
        tracep->declQuad(c+142,"Top lhu_rdata", false,-1, 63,0);
        tracep->declQuad(c+144,"Top lh_rdata_hi_3", false,-1, 47,0);
        tracep->declQuad(c+146,"Top lh_rdata_hi_2", false,-1, 47,0);
        tracep->declQuad(c+148,"Top lh_rdata_hi_1", false,-1, 47,0);
        tracep->declQuad(c+150,"Top lh_rdata_hi", false,-1, 47,0);
        tracep->declQuad(c+152,"Top lh_rdata", false,-1, 63,0);
        tracep->declBus(c+154,"Top lbu_rdata_lo_7", false,-1, 7,0);
        tracep->declBus(c+155,"Top lbu_rdata_lo_6", false,-1, 7,0);
        tracep->declBus(c+156,"Top lbu_rdata_lo_5", false,-1, 7,0);
        tracep->declBus(c+157,"Top lbu_rdata_lo_4", false,-1, 7,0);
        tracep->declBus(c+158,"Top lbu_rdata_lo_3", false,-1, 7,0);
        tracep->declBus(c+159,"Top lbu_rdata_lo_2", false,-1, 7,0);
        tracep->declBus(c+160,"Top lbu_rdata_lo_1", false,-1, 7,0);
        tracep->declBus(c+161,"Top lbu_rdata_lo", false,-1, 7,0);
        tracep->declQuad(c+162,"Top lbu_rdata", false,-1, 63,0);
        tracep->declQuad(c+164,"Top lb_rdata_hi_7", false,-1, 55,0);
        tracep->declQuad(c+166,"Top lb_rdata_hi_6", false,-1, 55,0);
        tracep->declQuad(c+168,"Top lb_rdata_hi_5", false,-1, 55,0);
        tracep->declQuad(c+170,"Top lb_rdata_hi_4", false,-1, 55,0);
        tracep->declQuad(c+172,"Top lb_rdata_hi_3", false,-1, 55,0);
        tracep->declQuad(c+174,"Top lb_rdata_hi_2", false,-1, 55,0);
        tracep->declQuad(c+176,"Top lb_rdata_hi_1", false,-1, 55,0);
        tracep->declQuad(c+178,"Top lb_rdata_hi", false,-1, 55,0);
        tracep->declQuad(c+180,"Top lb_rdata", false,-1, 63,0);
        tracep->declQuad(c+182,"Top load_rdata", false,-1, 63,0);
        tracep->declBit(c+74,"Top br_taken", false,-1);
        tracep->declQuad(c+211,"Top br_target", false,-1, 63,0);
        tracep->declBus(c+184,"Top sb_wmask", false,-1, 7,0);
        tracep->declBus(c+185,"Top sh_wmask", false,-1, 7,0);
        tracep->declBus(c+186,"Top sw_wmask", false,-1, 7,0);
        tracep->declBus(c+187,"Top sb_wdata_hi", false,-1, 7,0);
        tracep->declQuad(c+188,"Top sb_wdata", false,-1, 63,0);
        tracep->declBus(c+190,"Top sh_wdata_hi", false,-1, 15,0);
        tracep->declQuad(c+191,"Top sh_wdata", false,-1, 63,0);
        tracep->declBus(c+193,"Top sw_wdata_hi", false,-1, 31,0);
        tracep->declQuad(c+194,"Top sw_wdata", false,-1, 63,0);
        tracep->declBus(c+67,"Top bru io_bruop", false,-1, 3,0);
        tracep->declQuad(c+68,"Top bru io_src1", false,-1, 63,0);
        tracep->declQuad(c+70,"Top bru io_src2", false,-1, 63,0);
        tracep->declQuad(c+1,"Top bru io_pc", false,-1, 63,0);
        tracep->declQuad(c+72,"Top bru io_imm", false,-1, 63,0);
        tracep->declBit(c+74,"Top bru io_br_taken", false,-1);
        tracep->declQuad(c+211,"Top bru io_br_target", false,-1, 63,0);
        tracep->declBus(c+75,"Top alu io_aluop", false,-1, 4,0);
        tracep->declBit(c+76,"Top alu io_rv64", false,-1);
        tracep->declQuad(c+68,"Top alu io_src1", false,-1, 63,0);
        tracep->declQuad(c+70,"Top alu io_src2", false,-1, 63,0);
        tracep->declQuad(c+77,"Top alu io_result", false,-1, 63,0);
        tracep->declBit(c+196,"Top alu srl", false,-1);
        tracep->declBit(c+197,"Top alu sra", false,-1);
        tracep->declBus(c+198,"Top alu src1_lo", false,-1, 31,0);
        tracep->declBus(c+199,"Top alu src1_hi_1", false,-1, 31,0);
        tracep->declQuad(c+200,"Top alu src1", false,-1, 63,0);
        tracep->declBus(c+202,"Top alu shamt", false,-1, 5,0);
        tracep->declQuad(c+203,"Top alu tmp_result", false,-1, 63,0);
        tracep->declBus(c+205,"Top alu io_result_hi", false,-1, 31,0);
        tracep->declBus(c+206,"Top alu io_result_lo", false,-1, 31,0);
        tracep->declBit(c+207,"Top regfile clock", false,-1);
        tracep->declBus(c+79,"Top regfile raddr1", false,-1, 4,0);
        tracep->declQuad(c+80,"Top regfile rdata1", false,-1, 63,0);
        tracep->declBus(c+82,"Top regfile raddr2", false,-1, 4,0);
        tracep->declQuad(c+83,"Top regfile rdata2", false,-1, 63,0);
        tracep->declBit(c+86,"Top regfile wen", false,-1);
        tracep->declBus(c+85,"Top regfile waddr", false,-1, 4,0);
        tracep->declQuad(c+213,"Top regfile wdata", false,-1, 63,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declQuad(c+3+i*2,"Top regfile rf", true,(i+0), 63,0);}}
        tracep->declQuad(c+77,"Top blackbox mem_raddr", false,-1, 63,0);
        tracep->declBit(c+87,"Top blackbox mem_read", false,-1);
        tracep->declQuad(c+88,"Top blackbox mem_rdata", false,-1, 63,0);
        tracep->declQuad(c+77,"Top blackbox mem_waddr", false,-1, 63,0);
        tracep->declBit(c+90,"Top blackbox mem_write", false,-1);
        tracep->declBus(c+91,"Top blackbox mem_wmask", false,-1, 7,0);
        tracep->declQuad(c+92,"Top blackbox mem_wdata", false,-1, 63,0);
        tracep->declBit(c+215,"Top blackbox inst_ready", false,-1);
        tracep->declQuad(c+1,"Top blackbox pc", false,-1, 63,0);
        tracep->declQuad(c+94,"Top blackbox inst_2", false,-1, 63,0);
        tracep->declBit(c+96,"Top blackbox ebreak", false,-1);
    }
}

void VTop___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) VL_ATTR_COLD;
void VTop___024root__traceChgTop0(void* voidSelf, VerilatedVcd* tracep);
void VTop___024root__traceCleanup(void* voidSelf, VerilatedVcd* /*unused*/);

void VTop___024root__traceRegister(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        tracep->addFullCb(&VTop___024root__traceFullTop0, vlSelf);
        tracep->addChgCb(&VTop___024root__traceChgTop0, vlSelf);
        tracep->addCleanupCb(&VTop___024root__traceCleanup, vlSelf);
    }
}

void VTop___024root__traceFullSub0(VTop___024root* vlSelf, VerilatedVcd* tracep) VL_ATTR_COLD;

void VTop___024root__traceFullTop0(void* voidSelf, VerilatedVcd* tracep) {
    VTop___024root* const __restrict vlSelf = static_cast<VTop___024root*>(voidSelf);
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    {
        VTop___024root__traceFullSub0((&vlSymsp->TOP), tracep);
    }
}

void VTop___024root__traceFullSub0(VTop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    VTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullQData(oldp+1,(vlSelf->Top__DOT__pc),64);
        tracep->fullQData(oldp+3,(vlSelf->Top__DOT__regfile__DOT__rf[0]),64);
        tracep->fullQData(oldp+5,(vlSelf->Top__DOT__regfile__DOT__rf[1]),64);
        tracep->fullQData(oldp+7,(vlSelf->Top__DOT__regfile__DOT__rf[2]),64);
        tracep->fullQData(oldp+9,(vlSelf->Top__DOT__regfile__DOT__rf[3]),64);
        tracep->fullQData(oldp+11,(vlSelf->Top__DOT__regfile__DOT__rf[4]),64);
        tracep->fullQData(oldp+13,(vlSelf->Top__DOT__regfile__DOT__rf[5]),64);
        tracep->fullQData(oldp+15,(vlSelf->Top__DOT__regfile__DOT__rf[6]),64);
        tracep->fullQData(oldp+17,(vlSelf->Top__DOT__regfile__DOT__rf[7]),64);
        tracep->fullQData(oldp+19,(vlSelf->Top__DOT__regfile__DOT__rf[8]),64);
        tracep->fullQData(oldp+21,(vlSelf->Top__DOT__regfile__DOT__rf[9]),64);
        tracep->fullQData(oldp+23,(vlSelf->Top__DOT__regfile__DOT__rf[10]),64);
        tracep->fullQData(oldp+25,(vlSelf->Top__DOT__regfile__DOT__rf[11]),64);
        tracep->fullQData(oldp+27,(vlSelf->Top__DOT__regfile__DOT__rf[12]),64);
        tracep->fullQData(oldp+29,(vlSelf->Top__DOT__regfile__DOT__rf[13]),64);
        tracep->fullQData(oldp+31,(vlSelf->Top__DOT__regfile__DOT__rf[14]),64);
        tracep->fullQData(oldp+33,(vlSelf->Top__DOT__regfile__DOT__rf[15]),64);
        tracep->fullQData(oldp+35,(vlSelf->Top__DOT__regfile__DOT__rf[16]),64);
        tracep->fullQData(oldp+37,(vlSelf->Top__DOT__regfile__DOT__rf[17]),64);
        tracep->fullQData(oldp+39,(vlSelf->Top__DOT__regfile__DOT__rf[18]),64);
        tracep->fullQData(oldp+41,(vlSelf->Top__DOT__regfile__DOT__rf[19]),64);
        tracep->fullQData(oldp+43,(vlSelf->Top__DOT__regfile__DOT__rf[20]),64);
        tracep->fullQData(oldp+45,(vlSelf->Top__DOT__regfile__DOT__rf[21]),64);
        tracep->fullQData(oldp+47,(vlSelf->Top__DOT__regfile__DOT__rf[22]),64);
        tracep->fullQData(oldp+49,(vlSelf->Top__DOT__regfile__DOT__rf[23]),64);
        tracep->fullQData(oldp+51,(vlSelf->Top__DOT__regfile__DOT__rf[24]),64);
        tracep->fullQData(oldp+53,(vlSelf->Top__DOT__regfile__DOT__rf[25]),64);
        tracep->fullQData(oldp+55,(vlSelf->Top__DOT__regfile__DOT__rf[26]),64);
        tracep->fullQData(oldp+57,(vlSelf->Top__DOT__regfile__DOT__rf[27]),64);
        tracep->fullQData(oldp+59,(vlSelf->Top__DOT__regfile__DOT__rf[28]),64);
        tracep->fullQData(oldp+61,(vlSelf->Top__DOT__regfile__DOT__rf[29]),64);
        tracep->fullQData(oldp+63,(vlSelf->Top__DOT__regfile__DOT__rf[30]),64);
        tracep->fullQData(oldp+65,(vlSelf->Top__DOT__regfile__DOT__rf[31]),64);
        tracep->fullCData(oldp+67,(vlSelf->Top__DOT__bru_io_bruop),4);
        tracep->fullQData(oldp+68,(vlSelf->Top__DOT__alu_io_src1),64);
        tracep->fullQData(oldp+70,(vlSelf->Top__DOT__alu_io_src2),64);
        tracep->fullQData(oldp+72,(vlSelf->Top__DOT__bru_io_imm),64);
        tracep->fullBit(oldp+74,(((8U == (IData)(vlSelf->Top__DOT__bru_io_bruop))
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
                                                       == (IData)(vlSelf->Top__DOT__bru_io_bruop)))))))))));
        tracep->fullCData(oldp+75,(vlSelf->Top__DOT__alu_io_aluop),5);
        tracep->fullBit(oldp+76,(vlSelf->Top__DOT__alu_io_rv64));
        tracep->fullQData(oldp+77,(vlSelf->Top__DOT__alu_io_result),64);
        tracep->fullCData(oldp+79,((0x1fU & (vlSelf->Top__DOT__inst 
                                             >> 0xfU))),5);
        tracep->fullQData(oldp+80,(vlSelf->Top__DOT__regfile_rdata1),64);
        tracep->fullCData(oldp+82,((0x1fU & (vlSelf->Top__DOT__inst 
                                             >> 0x14U))),5);
        tracep->fullQData(oldp+83,(vlSelf->Top__DOT__regfile_rdata2),64);
        tracep->fullCData(oldp+85,((0x1fU & (vlSelf->Top__DOT__inst 
                                             >> 7U))),5);
        tracep->fullBit(oldp+86,(((0x37U == (0x7fU 
                                             & vlSelf->Top__DOT__inst)) 
                                  | ((0x17U == (0x7fU 
                                                & vlSelf->Top__DOT__inst)) 
                                     | ((0x6fU == (0x7fU 
                                                   & vlSelf->Top__DOT__inst)) 
                                        | ((0x67U == 
                                            (0x707fU 
                                             & vlSelf->Top__DOT__inst)) 
                                           | (IData)(vlSelf->Top__DOT___information_T_680)))))));
        tracep->fullBit(oldp+87,(((2U == (IData)(vlSelf->Top__DOT__fu_type)) 
                                  & (IData)(vlSelf->Top__DOT__information_8))));
        tracep->fullQData(oldp+88,(vlSelf->Top__DOT__blackbox_mem_rdata),64);
        tracep->fullBit(oldp+90,(((2U == (IData)(vlSelf->Top__DOT__fu_type)) 
                                  & (~ (IData)(vlSelf->Top__DOT__information_8)))));
        tracep->fullCData(oldp+91,(((0xbU == (IData)(vlSelf->Top__DOT__information_5))
                                     ? 0xffU : ((8U 
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
        tracep->fullQData(oldp+92,(((0xbU == (IData)(vlSelf->Top__DOT__information_5))
                                     ? vlSelf->Top__DOT__regfile_rdata2
                                     : ((8U == (IData)(vlSelf->Top__DOT__information_5))
                                         ? (((QData)((IData)(vlSelf->Top__DOT__regfile_rdata2)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelf->Top__DOT__regfile_rdata2)))
                                         : ((7U == (IData)(vlSelf->Top__DOT__information_5))
                                             ? (((QData)((IData)(
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
                                             : ((6U 
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
        tracep->fullQData(oldp+94,(vlSelf->Top__DOT__blackbox_inst_2),64);
        tracep->fullBit(oldp+96,((1U & (~ ((0x37U == 
                                            (0x7fU 
                                             & vlSelf->Top__DOT__inst)) 
                                           | (IData)(vlSelf->Top__DOT___information_T_187))))));
        tracep->fullIData(oldp+97,(vlSelf->Top__DOT__inst),32);
        tracep->fullQData(oldp+98,(((vlSelf->Top__DOT__inst 
                                     >> 0x1fU) ? 0xfffffffffffffULL
                                     : 0ULL)),52);
        tracep->fullSData(oldp+100,((vlSelf->Top__DOT__inst 
                                     >> 0x14U)),12);
        tracep->fullQData(oldp+101,(((((vlSelf->Top__DOT__inst 
                                        >> 0x1fU) ? 0xfffffffffffffULL
                                        : 0ULL) << 0xcU) 
                                     | (QData)((IData)(
                                                       (vlSelf->Top__DOT__inst 
                                                        >> 0x14U))))),64);
        tracep->fullCData(oldp+103,((vlSelf->Top__DOT__inst 
                                     >> 0x19U)),7);
        tracep->fullQData(oldp+104,(((((vlSelf->Top__DOT__inst 
                                        >> 0x1fU) ? 0xfffffffffffffULL
                                        : 0ULL) << 0xcU) 
                                     | (QData)((IData)(
                                                       ((0xfe0U 
                                                         & (vlSelf->Top__DOT__inst 
                                                            >> 0x14U)) 
                                                        | (0x1fU 
                                                           & (vlSelf->Top__DOT__inst 
                                                              >> 7U))))))),64);
        tracep->fullBit(oldp+106,((1U & (vlSelf->Top__DOT__inst 
                                         >> 7U))));
        tracep->fullCData(oldp+107,((0x3fU & (vlSelf->Top__DOT__inst 
                                              >> 0x19U))),6);
        tracep->fullCData(oldp+108,((0xfU & (vlSelf->Top__DOT__inst 
                                             >> 8U))),4);
        tracep->fullQData(oldp+109,(((((vlSelf->Top__DOT__inst 
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
                                                                 >> 7U)))))))),64);
        tracep->fullIData(oldp+111,(((vlSelf->Top__DOT__inst 
                                      >> 0x1fU) ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullIData(oldp+112,((vlSelf->Top__DOT__inst 
                                     >> 0xcU)),20);
        tracep->fullQData(oldp+113,((((QData)((IData)(
                                                      ((vlSelf->Top__DOT__inst 
                                                        >> 0x1fU)
                                                        ? 0xffffffffU
                                                        : 0U))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  (0xfffff000U 
                                                                   & vlSelf->Top__DOT__inst))))),64);
        tracep->fullQData(oldp+115,(((vlSelf->Top__DOT__inst 
                                      >> 0x1fU) ? 0xfffffffffffULL
                                      : 0ULL)),44);
        tracep->fullCData(oldp+117,((0xffU & (vlSelf->Top__DOT__inst 
                                              >> 0xcU))),8);
        tracep->fullBit(oldp+118,((1U & (vlSelf->Top__DOT__inst 
                                         >> 0x14U))));
        tracep->fullSData(oldp+119,((0x3ffU & (vlSelf->Top__DOT__inst 
                                               >> 0x15U))),10);
        tracep->fullQData(oldp+120,(vlSelf->Top__DOT__imm_j),64);
        tracep->fullBit(oldp+122,(((0x37U == (0x7fU 
                                              & vlSelf->Top__DOT__inst)) 
                                   | (IData)(vlSelf->Top__DOT___information_T_187))));
        tracep->fullCData(oldp+123,(vlSelf->Top__DOT__information_1),3);
        tracep->fullCData(oldp+124,(vlSelf->Top__DOT__fu_type),2);
        tracep->fullCData(oldp+125,(vlSelf->Top__DOT__information_5),4);
        tracep->fullCData(oldp+126,(vlSelf->Top__DOT__information_6),2);
        tracep->fullCData(oldp+127,(vlSelf->Top__DOT__information_7),2);
        tracep->fullBit(oldp+128,(vlSelf->Top__DOT__information_8));
        tracep->fullCData(oldp+129,((7U & (IData)(vlSelf->Top__DOT__alu_io_result))),3);
        tracep->fullIData(oldp+130,((IData)((vlSelf->Top__DOT__blackbox_mem_rdata 
                                             >> 0x20U))),32);
        tracep->fullIData(oldp+131,((IData)(vlSelf->Top__DOT__blackbox_mem_rdata)),32);
        tracep->fullQData(oldp+132,(((4U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                      ? (QData)((IData)(
                                                        (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                         >> 0x20U)))
                                      : ((0U == (7U 
                                                 & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                          ? (QData)((IData)(vlSelf->Top__DOT__blackbox_mem_rdata))
                                          : 0ULL))),64);
        tracep->fullIData(oldp+134,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                    >> 0x3fU)))
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullIData(oldp+135,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                    >> 0x1fU)))
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullQData(oldp+136,(((4U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
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
                                      : ((0U == (7U 
                                                 & (IData)(vlSelf->Top__DOT__alu_io_result)))
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
        tracep->fullSData(oldp+138,((0xffffU & (IData)(
                                                       (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                        >> 0x30U)))),16);
        tracep->fullSData(oldp+139,((0xffffU & (IData)(
                                                       (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                        >> 0x20U)))),16);
        tracep->fullSData(oldp+140,((0xffffU & (IData)(
                                                       (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                        >> 0x10U)))),16);
        tracep->fullSData(oldp+141,((0xffffU & (IData)(vlSelf->Top__DOT__blackbox_mem_rdata))),16);
        tracep->fullQData(oldp+142,(((6U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                      ? (QData)((IData)(
                                                        (0xffffU 
                                                         & (IData)(
                                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                    >> 0x30U)))))
                                      : ((4U == (7U 
                                                 & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                          ? (QData)((IData)(
                                                            (0xffffU 
                                                             & (IData)(
                                                                       (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                        >> 0x20U)))))
                                          : ((2U == 
                                              (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                              ? (QData)((IData)(
                                                                (0xffffU 
                                                                 & (IData)(
                                                                           (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                            >> 0x10U)))))
                                              : ((0U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                  ? (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(vlSelf->Top__DOT__blackbox_mem_rdata))))
                                                  : 0ULL))))),64);
        tracep->fullQData(oldp+144,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                    >> 0x3fU)))
                                      ? 0xffffffffffffULL
                                      : 0ULL)),48);
        tracep->fullQData(oldp+146,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                    >> 0x2fU)))
                                      ? 0xffffffffffffULL
                                      : 0ULL)),48);
        tracep->fullQData(oldp+148,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                    >> 0x1fU)))
                                      ? 0xffffffffffffULL
                                      : 0ULL)),48);
        tracep->fullQData(oldp+150,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                    >> 0xfU)))
                                      ? 0xffffffffffffULL
                                      : 0ULL)),48);
        tracep->fullQData(oldp+152,(((6U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
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
                                      : ((4U == (7U 
                                                 & (IData)(vlSelf->Top__DOT__alu_io_result)))
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
                                          : ((2U == 
                                              (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                              ? (((
                                                   (1U 
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
                                              : ((0U 
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
        tracep->fullCData(oldp+154,((0xffU & (IData)(
                                                     (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                      >> 0x38U)))),8);
        tracep->fullCData(oldp+155,((0xffU & (IData)(
                                                     (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                      >> 0x30U)))),8);
        tracep->fullCData(oldp+156,((0xffU & (IData)(
                                                     (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                      >> 0x28U)))),8);
        tracep->fullCData(oldp+157,((0xffU & (IData)(
                                                     (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                      >> 0x20U)))),8);
        tracep->fullCData(oldp+158,((0xffU & (IData)(
                                                     (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                      >> 0x18U)))),8);
        tracep->fullCData(oldp+159,((0xffU & (IData)(
                                                     (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                      >> 0x10U)))),8);
        tracep->fullCData(oldp+160,((0xffU & (IData)(
                                                     (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                      >> 8U)))),8);
        tracep->fullCData(oldp+161,((0xffU & (IData)(vlSelf->Top__DOT__blackbox_mem_rdata))),8);
        tracep->fullQData(oldp+162,(((7U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
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
                                                                        & (IData)(vlSelf->Top__DOT__blackbox_mem_rdata)))))))))))),64);
        tracep->fullQData(oldp+164,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                    >> 0x3fU)))
                                      ? 0xffffffffffffffULL
                                      : 0ULL)),56);
        tracep->fullQData(oldp+166,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                    >> 0x37U)))
                                      ? 0xffffffffffffffULL
                                      : 0ULL)),56);
        tracep->fullQData(oldp+168,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                    >> 0x2fU)))
                                      ? 0xffffffffffffffULL
                                      : 0ULL)),56);
        tracep->fullQData(oldp+170,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                    >> 0x27U)))
                                      ? 0xffffffffffffffULL
                                      : 0ULL)),56);
        tracep->fullQData(oldp+172,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                    >> 0x1fU)))
                                      ? 0xffffffffffffffULL
                                      : 0ULL)),56);
        tracep->fullQData(oldp+174,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                    >> 0x17U)))
                                      ? 0xffffffffffffffULL
                                      : 0ULL)),56);
        tracep->fullQData(oldp+176,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                    >> 0xfU)))
                                      ? 0xffffffffffffffULL
                                      : 0ULL)),56);
        tracep->fullQData(oldp+178,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                    >> 7U)))
                                      ? 0xffffffffffffffULL
                                      : 0ULL)),56);
        tracep->fullQData(oldp+180,(((7U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                      ? ((((1U & (IData)(
                                                         (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                          >> 0x3fU)))
                                            ? 0xffffffffffffffULL
                                            : 0ULL) 
                                          << 8U) | (QData)((IData)(
                                                                   (0xffU 
                                                                    & (IData)(
                                                                              (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                               >> 0x38U))))))
                                      : ((6U == (7U 
                                                 & (IData)(vlSelf->Top__DOT__alu_io_result)))
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
        tracep->fullQData(oldp+182,(((0xaU == (IData)(vlSelf->Top__DOT__information_5))
                                      ? vlSelf->Top__DOT__blackbox_mem_rdata
                                      : ((9U == (IData)(vlSelf->Top__DOT__information_5))
                                          ? ((4U == 
                                              (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                              ? (QData)((IData)(
                                                                (vlSelf->Top__DOT__blackbox_mem_rdata 
                                                                 >> 0x20U)))
                                              : ((0U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                  ? (QData)((IData)(vlSelf->Top__DOT__blackbox_mem_rdata))
                                                  : 0ULL))
                                          : ((3U == (IData)(vlSelf->Top__DOT__information_5))
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
                                              : vlSelf->Top__DOT___load_rdata_T_7)))),64);
        tracep->fullCData(oldp+184,(((7U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                      ? 0x80U : ((6U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                  ? 0x40U
                                                  : 
                                                 ((5U 
                                                   == 
                                                   (7U 
                                                    & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                   ? 0x20U
                                                   : 
                                                  ((4U 
                                                    == 
                                                    (7U 
                                                     & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                    ? 0x10U
                                                    : 
                                                   ((3U 
                                                     == 
                                                     (7U 
                                                      & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                     ? 8U
                                                     : 
                                                    ((2U 
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
        tracep->fullCData(oldp+185,(((6U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
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
                                                    : 0U))))),8);
        tracep->fullCData(oldp+186,(((4U == (7U & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                      ? 0xf0U : ((0U 
                                                  == 
                                                  (7U 
                                                   & (IData)(vlSelf->Top__DOT__alu_io_result)))
                                                  ? 0xfU
                                                  : 0U))),8);
        tracep->fullCData(oldp+187,((0xffU & (IData)(vlSelf->Top__DOT__regfile_rdata2))),8);
        tracep->fullQData(oldp+188,((((QData)((IData)(
                                                      (0xffU 
                                                       & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                      << 0x38U) | (
                                                   ((QData)((IData)(
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
        tracep->fullSData(oldp+190,((0xffffU & (IData)(vlSelf->Top__DOT__regfile_rdata2))),16);
        tracep->fullQData(oldp+191,((((QData)((IData)(
                                                      (0xffffU 
                                                       & (IData)(vlSelf->Top__DOT__regfile_rdata2)))) 
                                      << 0x30U) | (
                                                   ((QData)((IData)(
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
        tracep->fullIData(oldp+193,((IData)(vlSelf->Top__DOT__regfile_rdata2)),32);
        tracep->fullQData(oldp+194,((((QData)((IData)(vlSelf->Top__DOT__regfile_rdata2)) 
                                      << 0x20U) | (QData)((IData)(vlSelf->Top__DOT__regfile_rdata2)))),64);
        tracep->fullBit(oldp+196,(vlSelf->Top__DOT__alu__DOT__srl));
        tracep->fullBit(oldp+197,(((0xaU == (IData)(vlSelf->Top__DOT__alu_io_aluop)) 
                                   & (IData)(vlSelf->Top__DOT__alu_io_rv64))));
        tracep->fullIData(oldp+198,((IData)(vlSelf->Top__DOT__alu_io_src1)),32);
        tracep->fullIData(oldp+199,(((1U & (IData)(
                                                   (vlSelf->Top__DOT__alu_io_src1 
                                                    >> 0x1fU)))
                                      ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullQData(oldp+200,(vlSelf->Top__DOT__alu__DOT__src1),64);
        tracep->fullCData(oldp+202,(vlSelf->Top__DOT__alu__DOT__shamt),6);
        tracep->fullQData(oldp+203,((((QData)((IData)(
                                                      vlSelf->Top__DOT__alu__DOT___tmp_result_T_76[1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlSelf->Top__DOT__alu__DOT___tmp_result_T_76[0U])))),64);
        tracep->fullIData(oldp+205,(((vlSelf->Top__DOT__alu__DOT___tmp_result_T_76[0U] 
                                      >> 0x1fU) ? 0xffffffffU
                                      : 0U)),32);
        tracep->fullIData(oldp+206,(vlSelf->Top__DOT__alu__DOT___tmp_result_T_76[0U]),32);
        tracep->fullBit(oldp+207,(vlSelf->clock));
        tracep->fullBit(oldp+208,(vlSelf->reset));
        tracep->fullQData(oldp+209,(vlSelf->io_pc),64);
        tracep->fullQData(oldp+211,(((2U == (IData)(vlSelf->Top__DOT__bru_io_bruop))
                                      ? (0xfffffffffffffffeULL 
                                         & (vlSelf->Top__DOT__alu_io_src1 
                                            + vlSelf->Top__DOT__bru_io_imm))
                                      : (vlSelf->Top__DOT__pc 
                                         + vlSelf->Top__DOT__bru_io_imm))),64);
        tracep->fullQData(oldp+213,(((2U == (IData)(vlSelf->Top__DOT__fu_type))
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
        tracep->fullBit(oldp+215,((1U & (~ (IData)(vlSelf->reset)))));
    }
}
