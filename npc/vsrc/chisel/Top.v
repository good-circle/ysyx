module BRU(
  input  [3:0]  io_bruop,
  input  [63:0] io_src1,
  input  [63:0] io_src2,
  input  [63:0] io_pc,
  input  [31:0] io_imm,
  output        io_br_taken,
  output [63:0] io_br_target
);
  wire  _io_br_taken_T = io_src1 == io_src2; // @[BRU.scala 19:26]
  wire  _io_br_taken_T_1 = io_src1 != io_src2; // @[BRU.scala 20:26]
  wire  _io_br_taken_T_4 = $signed(io_src1) < $signed(io_src2); // @[BRU.scala 21:33]
  wire  _io_br_taken_T_7 = $signed(io_src1) >= $signed(io_src2); // @[BRU.scala 22:33]
  wire  _io_br_taken_T_8 = io_src1 < io_src2; // @[BRU.scala 23:33]
  wire  _io_br_taken_T_9 = io_src1 >= io_src2; // @[BRU.scala 24:33]
  wire  _io_br_taken_T_15 = 4'h3 == io_bruop ? _io_br_taken_T : 4'h2 == io_bruop | 4'h1 == io_bruop; // @[Mux.scala 80:57]
  wire  _io_br_taken_T_17 = 4'h4 == io_bruop ? _io_br_taken_T_1 : _io_br_taken_T_15; // @[Mux.scala 80:57]
  wire  _io_br_taken_T_19 = 4'h5 == io_bruop ? _io_br_taken_T_4 : _io_br_taken_T_17; // @[Mux.scala 80:57]
  wire  _io_br_taken_T_21 = 4'h6 == io_bruop ? _io_br_taken_T_7 : _io_br_taken_T_19; // @[Mux.scala 80:57]
  wire  _io_br_taken_T_23 = 4'h7 == io_bruop ? _io_br_taken_T_8 : _io_br_taken_T_21; // @[Mux.scala 80:57]
  wire [63:0] _GEN_0 = {{32'd0}, io_imm}; // @[BRU.scala 27:56]
  wire [63:0] _io_br_target_T_2 = io_src1 + _GEN_0; // @[BRU.scala 27:56]
  wire [63:0] _io_br_target_T_4 = {_io_br_target_T_2[63:1], 1'h0}; // @[BRU.scala 27:72]
  wire [63:0] _io_br_target_T_6 = io_pc + _GEN_0; // @[BRU.scala 27:84]
  assign io_br_taken = 4'h8 == io_bruop ? _io_br_taken_T_9 : _io_br_taken_T_23; // @[Mux.scala 80:57]
  assign io_br_target = io_bruop == 4'h2 ? _io_br_target_T_4 : _io_br_target_T_6; // @[BRU.scala 27:22]
endmodule
module ALU(
  input  [4:0]  io_aluop,
  input         io_rv64,
  input  [63:0] io_src1,
  input  [63:0] io_src2,
  output [63:0] io_result
);
  wire [5:0] shamt = io_rv64 ? {{1'd0}, io_src2[4:0]} : io_src2[5:0]; // @[ALU.scala 19:18]
  wire [63:0] _tmp_result_T_1 = io_src1 + io_src2; // @[ALU.scala 23:26]
  wire [63:0] _tmp_result_T_3 = io_src1 - io_src2; // @[ALU.scala 24:26]
  wire [63:0] _tmp_result_T_4 = io_src1 & io_src2; // @[ALU.scala 25:26]
  wire [63:0] _tmp_result_T_5 = io_src1 | io_src2; // @[ALU.scala 26:26]
  wire [63:0] _tmp_result_T_6 = io_src1 ^ io_src2; // @[ALU.scala 27:26]
  wire  _tmp_result_T_9 = $signed(io_src1) < $signed(io_src2); // @[ALU.scala 28:33]
  wire  _tmp_result_T_10 = io_src1 < io_src2; // @[ALU.scala 29:26]
  wire [126:0] _GEN_0 = {{63'd0}, io_src1}; // @[ALU.scala 30:26]
  wire [126:0] _tmp_result_T_11 = _GEN_0 << shamt; // @[ALU.scala 30:26]
  wire [63:0] _tmp_result_T_12 = io_src1 >> shamt; // @[ALU.scala 31:26]
  wire [63:0] _tmp_result_T_15 = $signed(io_src1) >>> shamt; // @[ALU.scala 32:43]
  wire [127:0] _tmp_result_T_16 = io_src1 * io_src2; // @[ALU.scala 33:26]
  wire [127:0] _tmp_result_T_19 = $signed(io_src1) * $signed(io_src2); // @[ALU.scala 34:33]
  wire [63:0] _tmp_result_T_21 = _tmp_result_T_19[127:64]; // @[ALU.scala 34:54]
  wire [64:0] _tmp_result_T_23 = {1'b0,$signed(io_src2)}; // @[ALU.scala 35:33]
  wire [128:0] _tmp_result_T_24 = $signed(io_src1) * $signed(_tmp_result_T_23); // @[ALU.scala 35:33]
  wire [127:0] _tmp_result_T_26 = _tmp_result_T_24[127:0]; // @[ALU.scala 35:33]
  wire [63:0] _tmp_result_T_28 = _tmp_result_T_26[127:64]; // @[ALU.scala 35:54]
  wire [64:0] _tmp_result_T_34 = $signed(io_src1) / $signed(io_src2); // @[ALU.scala 37:48]
  wire [63:0] _tmp_result_T_35 = io_src1 / io_src2; // @[ALU.scala 38:33]
  wire [63:0] _tmp_result_T_39 = $signed(io_src1) % $signed(io_src2); // @[ALU.scala 39:48]
  wire [63:0] _GEN_1 = io_src1 % io_src2; // @[ALU.scala 40:33]
  wire [63:0] _tmp_result_T_40 = _GEN_1[63:0]; // @[ALU.scala 40:33]
  wire [63:0] _tmp_result_T_42 = 5'h1 == io_aluop ? _tmp_result_T_1 : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _tmp_result_T_44 = 5'h2 == io_aluop ? _tmp_result_T_3 : _tmp_result_T_42; // @[Mux.scala 80:57]
  wire [63:0] _tmp_result_T_46 = 5'h3 == io_aluop ? _tmp_result_T_4 : _tmp_result_T_44; // @[Mux.scala 80:57]
  wire [63:0] _tmp_result_T_48 = 5'h4 == io_aluop ? _tmp_result_T_5 : _tmp_result_T_46; // @[Mux.scala 80:57]
  wire [63:0] _tmp_result_T_50 = 5'h5 == io_aluop ? _tmp_result_T_6 : _tmp_result_T_48; // @[Mux.scala 80:57]
  wire [63:0] _tmp_result_T_52 = 5'h6 == io_aluop ? {{63'd0}, _tmp_result_T_9} : _tmp_result_T_50; // @[Mux.scala 80:57]
  wire [63:0] _tmp_result_T_54 = 5'h7 == io_aluop ? {{63'd0}, _tmp_result_T_10} : _tmp_result_T_52; // @[Mux.scala 80:57]
  wire [126:0] _tmp_result_T_56 = 5'h8 == io_aluop ? _tmp_result_T_11 : {{63'd0}, _tmp_result_T_54}; // @[Mux.scala 80:57]
  wire [126:0] _tmp_result_T_58 = 5'h9 == io_aluop ? {{63'd0}, _tmp_result_T_12} : _tmp_result_T_56; // @[Mux.scala 80:57]
  wire [126:0] _tmp_result_T_60 = 5'ha == io_aluop ? {{63'd0}, _tmp_result_T_15} : _tmp_result_T_58; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_62 = 5'hb == io_aluop ? _tmp_result_T_16 : {{1'd0}, _tmp_result_T_60}; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_64 = 5'hc == io_aluop ? {{64'd0}, _tmp_result_T_21} : _tmp_result_T_62; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_66 = 5'hd == io_aluop ? {{64'd0}, _tmp_result_T_28} : _tmp_result_T_64; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_68 = 5'he == io_aluop ? {{64'd0}, _tmp_result_T_16[127:64]} : _tmp_result_T_66; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_70 = 5'hf == io_aluop ? {{63'd0}, _tmp_result_T_34} : _tmp_result_T_68; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_72 = 5'h10 == io_aluop ? {{64'd0}, _tmp_result_T_35} : _tmp_result_T_70; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_74 = 5'h11 == io_aluop ? {{64'd0}, _tmp_result_T_39} : _tmp_result_T_72; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_76 = 5'h12 == io_aluop ? {{64'd0}, _tmp_result_T_40} : _tmp_result_T_74; // @[Mux.scala 80:57]
  wire [63:0] tmp_result = _tmp_result_T_76[63:0]; // @[ALU.scala 20:24 ALU.scala 22:14]
  wire [31:0] io_result_hi = tmp_result[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [31:0] io_result_lo = tmp_result[31:0]; // @[ALU.scala 43:66]
  wire [63:0] _io_result_T_2 = {io_result_hi,io_result_lo}; // @[Cat.scala 30:58]
  assign io_result = io_rv64 ? _io_result_T_2 : tmp_result; // @[ALU.scala 43:19]
endmodule
module Regfile(
  input         clock,
  input  [4:0]  io_raddr1,
  output [63:0] io_rdata1,
  input  [4:0]  io_raddr2,
  output [63:0] io_rdata2,
  input  [4:0]  io_waddr,
  input  [63:0] io_wdata,
  input         io_wen
);
`ifdef RANDOMIZE_MEM_INIT
  reg [63:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
  reg [63:0] rf [0:31]; // @[Regfile.scala 14:15]
  import "DPI-C" function void set_gpr_ptr(input logic [63:0] a []);
initial set_gpr_ptr(rf); 
  wire [63:0] rf_io_rdata1_MPORT_data; // @[Regfile.scala 14:15]
  wire [4:0] rf_io_rdata1_MPORT_addr; // @[Regfile.scala 14:15]
  wire [63:0] rf_io_rdata2_MPORT_data; // @[Regfile.scala 14:15]
  wire [4:0] rf_io_rdata2_MPORT_addr; // @[Regfile.scala 14:15]
  wire [63:0] rf_MPORT_data; // @[Regfile.scala 14:15]
  wire [4:0] rf_MPORT_addr; // @[Regfile.scala 14:15]
  wire  rf_MPORT_mask; // @[Regfile.scala 14:15]
  wire  rf_MPORT_en; // @[Regfile.scala 14:15]
  assign rf_io_rdata1_MPORT_addr = io_raddr1;
  assign rf_io_rdata1_MPORT_data = rf[rf_io_rdata1_MPORT_addr]; // @[Regfile.scala 14:15]
  assign rf_io_rdata2_MPORT_addr = io_raddr2;
  assign rf_io_rdata2_MPORT_data = rf[rf_io_rdata2_MPORT_addr]; // @[Regfile.scala 14:15]
  assign rf_MPORT_data = io_wdata;
  assign rf_MPORT_addr = io_waddr;
  assign rf_MPORT_mask = 1'h1;
  assign rf_MPORT_en = io_wen;
  assign io_rdata1 = io_raddr1 == 5'h0 ? 64'h0 : rf_io_rdata1_MPORT_data; // @[Regfile.scala 20:19]
  assign io_rdata2 = io_raddr2 == 5'h0 ? 64'h0 : rf_io_rdata2_MPORT_data; // @[Regfile.scala 21:19]
  always @(posedge clock) begin
    if(rf_MPORT_en & rf_MPORT_mask) begin
      rf[rf_MPORT_addr] <= rf_MPORT_data; // @[Regfile.scala 14:15]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {2{`RANDOM}};
  for (initvar = 0; initvar < 32; initvar = initvar+1)
    rf[initvar] = _RAND_0[63:0];
`endif // RANDOMIZE_MEM_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Top(
  input         clock,
  input         reset,
  output [63:0] io_pc
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  wire [3:0] bru_io_bruop; // @[Top.scala 170:19]
  wire [63:0] bru_io_src1; // @[Top.scala 170:19]
  wire [63:0] bru_io_src2; // @[Top.scala 170:19]
  wire [63:0] bru_io_pc; // @[Top.scala 170:19]
  wire [31:0] bru_io_imm; // @[Top.scala 170:19]
  wire  bru_io_br_taken; // @[Top.scala 170:19]
  wire [63:0] bru_io_br_target; // @[Top.scala 170:19]
  wire [4:0] alu_io_aluop; // @[Top.scala 182:19]
  wire  alu_io_rv64; // @[Top.scala 182:19]
  wire [63:0] alu_io_src1; // @[Top.scala 182:19]
  wire [63:0] alu_io_src2; // @[Top.scala 182:19]
  wire [63:0] alu_io_result; // @[Top.scala 182:19]
  wire  regfile_clock; // @[Top.scala 192:23]
  wire [4:0] regfile_io_raddr1; // @[Top.scala 192:23]
  wire [63:0] regfile_io_rdata1; // @[Top.scala 192:23]
  wire [4:0] regfile_io_raddr2; // @[Top.scala 192:23]
  wire [63:0] regfile_io_rdata2; // @[Top.scala 192:23]
  wire [4:0] regfile_io_waddr; // @[Top.scala 192:23]
  wire [63:0] regfile_io_wdata; // @[Top.scala 192:23]
  wire  regfile_io_wen; // @[Top.scala 192:23]
  wire  blackbox_mem_read; // @[Top.scala 218:24]
  wire [63:0] blackbox_mem_raddr; // @[Top.scala 218:24]
  wire [63:0] blackbox_mem_rdata; // @[Top.scala 218:24]
  wire  blackbox_mem_write; // @[Top.scala 218:24]
  wire [63:0] blackbox_mem_waddr; // @[Top.scala 218:24]
  wire [7:0] blackbox_mem_wmask; // @[Top.scala 218:24]
  wire [63:0] blackbox_mem_wdata; // @[Top.scala 218:24]
  wire  blackbox_inst_ready; // @[Top.scala 218:24]
  wire [63:0] blackbox_pc; // @[Top.scala 218:24]
  wire [63:0] blackbox_inst_2; // @[Top.scala 218:24]
  wire  blackbox_ebreak; // @[Top.scala 218:24]
  reg [63:0] pc; // @[Top.scala 11:19]
  wire [63:0] inst_2 = blackbox_inst_2; // @[Top.scala 48:20 Top.scala 335:10]
  wire [31:0] inst = pc[2] ? inst_2[63:32] : inst_2[31:0]; // @[Top.scala 215:14]
  wire [51:0] imm_i_hi = inst[31] ? 52'hfffffffffffff : 52'h0; // @[Bitwise.scala 72:12]
  wire [11:0] imm_i_lo = inst[31:20]; // @[Top.scala 17:43]
  wire [63:0] imm_i = {imm_i_hi,imm_i_lo}; // @[Cat.scala 30:58]
  wire [6:0] imm_s_hi_lo = inst[31:25]; // @[Top.scala 18:43]
  wire [4:0] imm_s_lo = inst[11:7]; // @[Top.scala 18:57]
  wire [63:0] imm_s = {imm_i_hi,imm_s_hi_lo,imm_s_lo}; // @[Cat.scala 30:58]
  wire  imm_b_hi_hi_lo = inst[7]; // @[Top.scala 19:43]
  wire [5:0] imm_b_hi_lo = inst[30:25]; // @[Top.scala 19:52]
  wire [3:0] imm_b_lo_hi = inst[11:8]; // @[Top.scala 19:66]
  wire [63:0] imm_b = {imm_i_hi,imm_b_hi_hi_lo,imm_b_hi_lo,imm_b_lo_hi,1'h0}; // @[Cat.scala 30:58]
  wire [31:0] imm_u_hi_hi = inst[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [19:0] imm_u_hi_lo = inst[31:12]; // @[Top.scala 20:43]
  wire [63:0] imm_u = {imm_u_hi_hi,imm_u_hi_lo,12'h0}; // @[Cat.scala 30:58]
  wire [43:0] imm_j_hi_hi_hi = inst[31] ? 44'hfffffffffff : 44'h0; // @[Bitwise.scala 72:12]
  wire [7:0] imm_j_hi_hi_lo = inst[19:12]; // @[Top.scala 21:43]
  wire  imm_j_hi_lo = inst[20]; // @[Top.scala 21:57]
  wire [9:0] imm_j_lo_hi = inst[30:21]; // @[Top.scala 21:67]
  wire [63:0] imm_j = {imm_j_hi_hi_hi,imm_j_hi_hi_lo,imm_j_hi_lo,imm_j_lo_hi,1'h0}; // @[Cat.scala 30:58]
  reg  inst_ready; // @[Top.scala 47:27]
  wire [31:0] _information_T = inst & 32'h7f; // @[Lookup.scala 31:38]
  wire  _information_T_1 = 32'h37 == _information_T; // @[Lookup.scala 31:38]
  wire  _information_T_3 = 32'h17 == _information_T; // @[Lookup.scala 31:38]
  wire  _information_T_5 = 32'h6f == _information_T; // @[Lookup.scala 31:38]
  wire [31:0] _information_T_6 = inst & 32'h707f; // @[Lookup.scala 31:38]
  wire  _information_T_7 = 32'h67 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_9 = 32'h63 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_11 = 32'h1063 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_13 = 32'h4063 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_15 = 32'h5063 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_17 = 32'h6063 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_19 = 32'h7063 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_21 = 32'h3 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_23 = 32'h1003 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_25 = 32'h2003 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_27 = 32'h4003 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_29 = 32'h5003 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_31 = 32'h23 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_33 = 32'h1023 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_35 = 32'h2023 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_37 = 32'h13 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_39 = 32'h2013 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_41 = 32'h3013 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_43 = 32'h4013 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_45 = 32'h6013 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_47 = 32'h7013 == _information_T_6; // @[Lookup.scala 31:38]
  wire [31:0] _information_T_48 = inst & 32'hfc00707f; // @[Lookup.scala 31:38]
  wire  _information_T_49 = 32'h1013 == _information_T_48; // @[Lookup.scala 31:38]
  wire  _information_T_51 = 32'h5013 == _information_T_48; // @[Lookup.scala 31:38]
  wire  _information_T_53 = 32'h40005013 == _information_T_48; // @[Lookup.scala 31:38]
  wire [31:0] _information_T_54 = inst & 32'hfe00707f; // @[Lookup.scala 31:38]
  wire  _information_T_55 = 32'h33 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_57 = 32'h40000033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_59 = 32'h1033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_61 = 32'h2033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_63 = 32'h3033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_65 = 32'h4033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_67 = 32'h5033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_69 = 32'h40005033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_71 = 32'h6033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_73 = 32'h7033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_75 = 32'h1b == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_77 = 32'h101b == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_79 = 32'h501b == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_81 = 32'h4000501b == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_83 = 32'h3b == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_85 = 32'h4000003b == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_87 = 32'h103b == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_89 = 32'h503b == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_91 = 32'h4000503b == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_93 = 32'h6003 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_95 = 32'h3003 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_97 = 32'h3023 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_99 = 32'h2000033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_101 = 32'h2001033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_103 = 32'h2002033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_105 = 32'h2003033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_107 = 32'h2004033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_109 = 32'h2005033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_111 = 32'h2006033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_113 = 32'h2007033 == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_115 = 32'h200003b == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_117 = 32'h200403b == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_119 = 32'h200503b == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_121 = 32'h200603b == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_123 = 32'h200703b == _information_T_54; // @[Lookup.scala 31:38]
  wire  _information_T_125 = 32'h100073 == inst; // @[Lookup.scala 31:38]
  wire  _information_T_157 = _information_T_63 | (_information_T_65 | (_information_T_67 | (_information_T_69 | (
    _information_T_71 | (_information_T_73 | (_information_T_75 | (_information_T_77 | (_information_T_79 | (
    _information_T_81 | (_information_T_83 | (_information_T_85 | (_information_T_87 | (_information_T_89 | (
    _information_T_91 | (_information_T_93 | (_information_T_95 | (_information_T_97 | (_information_T_99 | (
    _information_T_101 | (_information_T_103 | (_information_T_105 | (_information_T_107 | (_information_T_109 | (
    _information_T_111 | (_information_T_113 | (_information_T_115 | (_information_T_117 | (_information_T_119 | (
    _information_T_121 | _information_T_123))))))))))))))))))))))))))))); // @[Lookup.scala 33:37]
  wire  _information_T_187 = _information_T_3 | (_information_T_5 | (_information_T_7 | (_information_T_9 | (
    _information_T_11 | (_information_T_13 | (_information_T_15 | (_information_T_17 | (_information_T_19 | (
    _information_T_21 | (_information_T_23 | (_information_T_25 | (_information_T_27 | (_information_T_29 | (
    _information_T_31 | (_information_T_33 | (_information_T_35 | (_information_T_37 | (_information_T_39 | (
    _information_T_41 | (_information_T_43 | (_information_T_45 | (_information_T_47 | (_information_T_49 | (
    _information_T_51 | (_information_T_53 | (_information_T_55 | (_information_T_57 | (_information_T_59 | (
    _information_T_61 | _information_T_157))))))))))))))))))))))))))))); // @[Lookup.scala 33:37]
  wire  information_0 = _information_T_1 | _information_T_187; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_188 = _information_T_125 ? 3'h1 : 3'h0; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_189 = _information_T_123 ? 3'h0 : _information_T_188; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_190 = _information_T_121 ? 3'h0 : _information_T_189; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_191 = _information_T_119 ? 3'h0 : _information_T_190; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_192 = _information_T_117 ? 3'h0 : _information_T_191; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_193 = _information_T_115 ? 3'h0 : _information_T_192; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_194 = _information_T_113 ? 3'h0 : _information_T_193; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_195 = _information_T_111 ? 3'h0 : _information_T_194; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_196 = _information_T_109 ? 3'h0 : _information_T_195; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_197 = _information_T_107 ? 3'h0 : _information_T_196; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_198 = _information_T_105 ? 3'h0 : _information_T_197; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_199 = _information_T_103 ? 3'h0 : _information_T_198; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_200 = _information_T_101 ? 3'h0 : _information_T_199; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_201 = _information_T_99 ? 3'h0 : _information_T_200; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_202 = _information_T_97 ? 3'h2 : _information_T_201; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_203 = _information_T_95 ? 3'h1 : _information_T_202; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_204 = _information_T_93 ? 3'h1 : _information_T_203; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_205 = _information_T_91 ? 3'h0 : _information_T_204; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_206 = _information_T_89 ? 3'h0 : _information_T_205; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_207 = _information_T_87 ? 3'h0 : _information_T_206; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_208 = _information_T_85 ? 3'h0 : _information_T_207; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_209 = _information_T_83 ? 3'h0 : _information_T_208; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_210 = _information_T_81 ? 3'h1 : _information_T_209; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_211 = _information_T_79 ? 3'h1 : _information_T_210; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_212 = _information_T_77 ? 3'h1 : _information_T_211; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_213 = _information_T_75 ? 3'h1 : _information_T_212; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_214 = _information_T_73 ? 3'h0 : _information_T_213; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_215 = _information_T_71 ? 3'h0 : _information_T_214; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_216 = _information_T_69 ? 3'h0 : _information_T_215; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_217 = _information_T_67 ? 3'h0 : _information_T_216; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_218 = _information_T_65 ? 3'h0 : _information_T_217; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_219 = _information_T_63 ? 3'h0 : _information_T_218; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_220 = _information_T_61 ? 3'h0 : _information_T_219; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_221 = _information_T_59 ? 3'h0 : _information_T_220; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_222 = _information_T_57 ? 3'h0 : _information_T_221; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_223 = _information_T_55 ? 3'h0 : _information_T_222; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_224 = _information_T_53 ? 3'h1 : _information_T_223; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_225 = _information_T_51 ? 3'h1 : _information_T_224; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_226 = _information_T_49 ? 3'h1 : _information_T_225; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_227 = _information_T_47 ? 3'h1 : _information_T_226; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_228 = _information_T_45 ? 3'h1 : _information_T_227; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_229 = _information_T_43 ? 3'h1 : _information_T_228; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_230 = _information_T_41 ? 3'h1 : _information_T_229; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_231 = _information_T_39 ? 3'h1 : _information_T_230; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_232 = _information_T_37 ? 3'h1 : _information_T_231; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_233 = _information_T_35 ? 3'h2 : _information_T_232; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_234 = _information_T_33 ? 3'h2 : _information_T_233; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_235 = _information_T_31 ? 3'h2 : _information_T_234; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_236 = _information_T_29 ? 3'h1 : _information_T_235; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_237 = _information_T_27 ? 3'h1 : _information_T_236; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_238 = _information_T_25 ? 3'h1 : _information_T_237; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_239 = _information_T_23 ? 3'h1 : _information_T_238; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_240 = _information_T_21 ? 3'h1 : _information_T_239; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_241 = _information_T_19 ? 3'h3 : _information_T_240; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_242 = _information_T_17 ? 3'h3 : _information_T_241; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_243 = _information_T_15 ? 3'h3 : _information_T_242; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_244 = _information_T_13 ? 3'h3 : _information_T_243; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_245 = _information_T_11 ? 3'h3 : _information_T_244; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_246 = _information_T_9 ? 3'h3 : _information_T_245; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_247 = _information_T_7 ? 3'h1 : _information_T_246; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_248 = _information_T_5 ? 3'h5 : _information_T_247; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_249 = _information_T_3 ? 3'h4 : _information_T_248; // @[Lookup.scala 33:37]
  wire [2:0] information_1 = _information_T_1 ? 3'h4 : _information_T_249; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_264 = _information_T_97 ? 2'h2 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_265 = _information_T_95 ? 2'h2 : _information_T_264; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_266 = _information_T_93 ? 2'h2 : _information_T_265; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_267 = _information_T_91 ? 2'h0 : _information_T_266; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_268 = _information_T_89 ? 2'h0 : _information_T_267; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_269 = _information_T_87 ? 2'h0 : _information_T_268; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_270 = _information_T_85 ? 2'h0 : _information_T_269; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_271 = _information_T_83 ? 2'h0 : _information_T_270; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_272 = _information_T_81 ? 2'h0 : _information_T_271; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_273 = _information_T_79 ? 2'h0 : _information_T_272; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_274 = _information_T_77 ? 2'h0 : _information_T_273; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_275 = _information_T_75 ? 2'h0 : _information_T_274; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_276 = _information_T_73 ? 2'h0 : _information_T_275; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_277 = _information_T_71 ? 2'h0 : _information_T_276; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_278 = _information_T_69 ? 2'h0 : _information_T_277; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_279 = _information_T_67 ? 2'h0 : _information_T_278; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_280 = _information_T_65 ? 2'h0 : _information_T_279; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_281 = _information_T_63 ? 2'h0 : _information_T_280; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_282 = _information_T_61 ? 2'h0 : _information_T_281; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_283 = _information_T_59 ? 2'h0 : _information_T_282; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_284 = _information_T_57 ? 2'h0 : _information_T_283; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_285 = _information_T_55 ? 2'h0 : _information_T_284; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_286 = _information_T_53 ? 2'h0 : _information_T_285; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_287 = _information_T_51 ? 2'h0 : _information_T_286; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_288 = _information_T_49 ? 2'h0 : _information_T_287; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_289 = _information_T_47 ? 2'h0 : _information_T_288; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_290 = _information_T_45 ? 2'h0 : _information_T_289; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_291 = _information_T_43 ? 2'h0 : _information_T_290; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_292 = _information_T_41 ? 2'h0 : _information_T_291; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_293 = _information_T_39 ? 2'h0 : _information_T_292; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_294 = _information_T_37 ? 2'h0 : _information_T_293; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_295 = _information_T_35 ? 2'h2 : _information_T_294; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_296 = _information_T_33 ? 2'h2 : _information_T_295; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_297 = _information_T_31 ? 2'h2 : _information_T_296; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_298 = _information_T_29 ? 2'h2 : _information_T_297; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_299 = _information_T_27 ? 2'h2 : _information_T_298; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_300 = _information_T_25 ? 2'h2 : _information_T_299; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_301 = _information_T_23 ? 2'h2 : _information_T_300; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_302 = _information_T_21 ? 2'h2 : _information_T_301; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_303 = _information_T_19 ? 2'h1 : _information_T_302; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_304 = _information_T_17 ? 2'h1 : _information_T_303; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_305 = _information_T_15 ? 2'h1 : _information_T_304; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_306 = _information_T_13 ? 2'h1 : _information_T_305; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_307 = _information_T_11 ? 2'h1 : _information_T_306; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_308 = _information_T_9 ? 2'h1 : _information_T_307; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_309 = _information_T_7 ? 2'h1 : _information_T_308; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_310 = _information_T_5 ? 2'h1 : _information_T_309; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_311 = _information_T_3 ? 2'h0 : _information_T_310; // @[Lookup.scala 33:37]
  wire [1:0] fu_type = _information_T_1 ? 2'h0 : _information_T_311; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_313 = _information_T_123 ? 5'h12 : 5'h0; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_314 = _information_T_121 ? 5'h11 : _information_T_313; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_315 = _information_T_119 ? 5'h10 : _information_T_314; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_316 = _information_T_117 ? 5'hf : _information_T_315; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_317 = _information_T_115 ? 5'hb : _information_T_316; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_318 = _information_T_113 ? 5'h12 : _information_T_317; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_319 = _information_T_111 ? 5'h11 : _information_T_318; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_320 = _information_T_109 ? 5'h10 : _information_T_319; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_321 = _information_T_107 ? 5'hf : _information_T_320; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_322 = _information_T_105 ? 5'he : _information_T_321; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_323 = _information_T_103 ? 5'hd : _information_T_322; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_324 = _information_T_101 ? 5'hc : _information_T_323; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_325 = _information_T_99 ? 5'hb : _information_T_324; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_326 = _information_T_97 ? 5'h1 : _information_T_325; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_327 = _information_T_95 ? 5'h1 : _information_T_326; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_328 = _information_T_93 ? 5'h1 : _information_T_327; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_329 = _information_T_91 ? 5'ha : _information_T_328; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_330 = _information_T_89 ? 5'h9 : _information_T_329; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_331 = _information_T_87 ? 5'h8 : _information_T_330; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_332 = _information_T_85 ? 5'h2 : _information_T_331; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_333 = _information_T_83 ? 5'h1 : _information_T_332; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_334 = _information_T_81 ? 5'ha : _information_T_333; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_335 = _information_T_79 ? 5'h9 : _information_T_334; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_336 = _information_T_77 ? 5'h8 : _information_T_335; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_337 = _information_T_75 ? 5'h1 : _information_T_336; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_338 = _information_T_73 ? 5'h3 : _information_T_337; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_339 = _information_T_71 ? 5'h4 : _information_T_338; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_340 = _information_T_69 ? 5'ha : _information_T_339; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_341 = _information_T_67 ? 5'h9 : _information_T_340; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_342 = _information_T_65 ? 5'h5 : _information_T_341; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_343 = _information_T_63 ? 5'h7 : _information_T_342; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_344 = _information_T_61 ? 5'h6 : _information_T_343; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_345 = _information_T_59 ? 5'h8 : _information_T_344; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_346 = _information_T_57 ? 5'h2 : _information_T_345; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_347 = _information_T_55 ? 5'h1 : _information_T_346; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_348 = _information_T_53 ? 5'ha : _information_T_347; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_349 = _information_T_51 ? 5'h9 : _information_T_348; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_350 = _information_T_49 ? 5'h8 : _information_T_349; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_351 = _information_T_47 ? 5'h3 : _information_T_350; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_352 = _information_T_45 ? 5'h4 : _information_T_351; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_353 = _information_T_43 ? 5'h5 : _information_T_352; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_354 = _information_T_41 ? 5'h7 : _information_T_353; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_355 = _information_T_39 ? 5'h6 : _information_T_354; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_356 = _information_T_37 ? 5'h1 : _information_T_355; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_357 = _information_T_35 ? 5'h1 : _information_T_356; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_358 = _information_T_33 ? 5'h1 : _information_T_357; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_359 = _information_T_31 ? 5'h1 : _information_T_358; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_360 = _information_T_29 ? 5'h1 : _information_T_359; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_361 = _information_T_27 ? 5'h1 : _information_T_360; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_362 = _information_T_25 ? 5'h1 : _information_T_361; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_363 = _information_T_23 ? 5'h1 : _information_T_362; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_364 = _information_T_21 ? 5'h1 : _information_T_363; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_365 = _information_T_19 ? 5'h0 : _information_T_364; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_366 = _information_T_17 ? 5'h0 : _information_T_365; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_367 = _information_T_15 ? 5'h0 : _information_T_366; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_368 = _information_T_13 ? 5'h0 : _information_T_367; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_369 = _information_T_11 ? 5'h0 : _information_T_368; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_370 = _information_T_9 ? 5'h0 : _information_T_369; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_371 = _information_T_7 ? 5'h0 : _information_T_370; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_372 = _information_T_5 ? 5'h0 : _information_T_371; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_373 = _information_T_3 ? 5'h1 : _information_T_372; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_427 = _information_T_19 ? 4'h8 : 4'h0; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_428 = _information_T_17 ? 4'h7 : _information_T_427; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_429 = _information_T_15 ? 4'h6 : _information_T_428; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_430 = _information_T_13 ? 4'h5 : _information_T_429; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_431 = _information_T_11 ? 4'h4 : _information_T_430; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_432 = _information_T_9 ? 4'h3 : _information_T_431; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_433 = _information_T_7 ? 4'h2 : _information_T_432; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_434 = _information_T_5 ? 4'h1 : _information_T_433; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_435 = _information_T_3 ? 4'h0 : _information_T_434; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_450 = _information_T_97 ? 4'hb : 4'h0; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_451 = _information_T_95 ? 4'ha : _information_T_450; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_452 = _information_T_93 ? 4'h9 : _information_T_451; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_453 = _information_T_91 ? 4'h0 : _information_T_452; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_454 = _information_T_89 ? 4'h0 : _information_T_453; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_455 = _information_T_87 ? 4'h0 : _information_T_454; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_456 = _information_T_85 ? 4'h0 : _information_T_455; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_457 = _information_T_83 ? 4'h0 : _information_T_456; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_458 = _information_T_81 ? 4'h0 : _information_T_457; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_459 = _information_T_79 ? 4'h0 : _information_T_458; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_460 = _information_T_77 ? 4'h0 : _information_T_459; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_461 = _information_T_75 ? 4'h0 : _information_T_460; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_462 = _information_T_73 ? 4'h0 : _information_T_461; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_463 = _information_T_71 ? 4'h0 : _information_T_462; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_464 = _information_T_69 ? 4'h0 : _information_T_463; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_465 = _information_T_67 ? 4'h0 : _information_T_464; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_466 = _information_T_65 ? 4'h0 : _information_T_465; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_467 = _information_T_63 ? 4'h0 : _information_T_466; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_468 = _information_T_61 ? 4'h0 : _information_T_467; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_469 = _information_T_59 ? 4'h0 : _information_T_468; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_470 = _information_T_57 ? 4'h0 : _information_T_469; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_471 = _information_T_55 ? 4'h0 : _information_T_470; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_472 = _information_T_53 ? 4'h0 : _information_T_471; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_473 = _information_T_51 ? 4'h0 : _information_T_472; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_474 = _information_T_49 ? 4'h0 : _information_T_473; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_475 = _information_T_47 ? 4'h0 : _information_T_474; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_476 = _information_T_45 ? 4'h0 : _information_T_475; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_477 = _information_T_43 ? 4'h0 : _information_T_476; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_478 = _information_T_41 ? 4'h0 : _information_T_477; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_479 = _information_T_39 ? 4'h0 : _information_T_478; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_480 = _information_T_37 ? 4'h0 : _information_T_479; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_481 = _information_T_35 ? 4'h8 : _information_T_480; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_482 = _information_T_33 ? 4'h7 : _information_T_481; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_483 = _information_T_31 ? 4'h6 : _information_T_482; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_484 = _information_T_29 ? 4'h5 : _information_T_483; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_485 = _information_T_27 ? 4'h4 : _information_T_484; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_486 = _information_T_25 ? 4'h3 : _information_T_485; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_487 = _information_T_23 ? 4'h2 : _information_T_486; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_488 = _information_T_21 ? 4'h1 : _information_T_487; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_489 = _information_T_19 ? 4'h0 : _information_T_488; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_490 = _information_T_17 ? 4'h0 : _information_T_489; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_491 = _information_T_15 ? 4'h0 : _information_T_490; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_492 = _information_T_13 ? 4'h0 : _information_T_491; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_493 = _information_T_11 ? 4'h0 : _information_T_492; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_494 = _information_T_9 ? 4'h0 : _information_T_493; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_495 = _information_T_7 ? 4'h0 : _information_T_494; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_496 = _information_T_5 ? 4'h0 : _information_T_495; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_497 = _information_T_3 ? 4'h0 : _information_T_496; // @[Lookup.scala 33:37]
  wire [3:0] information_5 = _information_T_1 ? 4'h0 : _information_T_497; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_499 = _information_T_123 ? 2'h1 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_500 = _information_T_121 ? 2'h1 : _information_T_499; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_501 = _information_T_119 ? 2'h1 : _information_T_500; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_502 = _information_T_117 ? 2'h1 : _information_T_501; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_503 = _information_T_115 ? 2'h1 : _information_T_502; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_504 = _information_T_113 ? 2'h1 : _information_T_503; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_505 = _information_T_111 ? 2'h1 : _information_T_504; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_506 = _information_T_109 ? 2'h1 : _information_T_505; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_507 = _information_T_107 ? 2'h1 : _information_T_506; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_508 = _information_T_105 ? 2'h1 : _information_T_507; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_509 = _information_T_103 ? 2'h1 : _information_T_508; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_510 = _information_T_101 ? 2'h1 : _information_T_509; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_511 = _information_T_99 ? 2'h1 : _information_T_510; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_512 = _information_T_97 ? 2'h1 : _information_T_511; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_513 = _information_T_95 ? 2'h1 : _information_T_512; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_514 = _information_T_93 ? 2'h1 : _information_T_513; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_515 = _information_T_91 ? 2'h1 : _information_T_514; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_516 = _information_T_89 ? 2'h1 : _information_T_515; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_517 = _information_T_87 ? 2'h1 : _information_T_516; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_518 = _information_T_85 ? 2'h1 : _information_T_517; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_519 = _information_T_83 ? 2'h1 : _information_T_518; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_520 = _information_T_81 ? 2'h1 : _information_T_519; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_521 = _information_T_79 ? 2'h1 : _information_T_520; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_522 = _information_T_77 ? 2'h1 : _information_T_521; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_523 = _information_T_75 ? 2'h1 : _information_T_522; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_524 = _information_T_73 ? 2'h1 : _information_T_523; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_525 = _information_T_71 ? 2'h1 : _information_T_524; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_526 = _information_T_69 ? 2'h1 : _information_T_525; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_527 = _information_T_67 ? 2'h1 : _information_T_526; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_528 = _information_T_65 ? 2'h1 : _information_T_527; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_529 = _information_T_63 ? 2'h1 : _information_T_528; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_530 = _information_T_61 ? 2'h1 : _information_T_529; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_531 = _information_T_59 ? 2'h1 : _information_T_530; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_532 = _information_T_57 ? 2'h1 : _information_T_531; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_533 = _information_T_55 ? 2'h1 : _information_T_532; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_534 = _information_T_53 ? 2'h1 : _information_T_533; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_535 = _information_T_51 ? 2'h1 : _information_T_534; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_536 = _information_T_49 ? 2'h1 : _information_T_535; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_537 = _information_T_47 ? 2'h1 : _information_T_536; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_538 = _information_T_45 ? 2'h1 : _information_T_537; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_539 = _information_T_43 ? 2'h1 : _information_T_538; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_540 = _information_T_41 ? 2'h1 : _information_T_539; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_541 = _information_T_39 ? 2'h1 : _information_T_540; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_542 = _information_T_37 ? 2'h1 : _information_T_541; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_543 = _information_T_35 ? 2'h1 : _information_T_542; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_544 = _information_T_33 ? 2'h1 : _information_T_543; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_545 = _information_T_31 ? 2'h1 : _information_T_544; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_546 = _information_T_29 ? 2'h1 : _information_T_545; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_547 = _information_T_27 ? 2'h1 : _information_T_546; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_548 = _information_T_25 ? 2'h1 : _information_T_547; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_549 = _information_T_23 ? 2'h1 : _information_T_548; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_550 = _information_T_21 ? 2'h1 : _information_T_549; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_551 = _information_T_19 ? 2'h1 : _information_T_550; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_552 = _information_T_17 ? 2'h1 : _information_T_551; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_553 = _information_T_15 ? 2'h1 : _information_T_552; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_554 = _information_T_13 ? 2'h1 : _information_T_553; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_555 = _information_T_11 ? 2'h1 : _information_T_554; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_556 = _information_T_9 ? 2'h1 : _information_T_555; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_557 = _information_T_7 ? 2'h1 : _information_T_556; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_558 = _information_T_5 ? 2'h0 : _information_T_557; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_559 = _information_T_3 ? 2'h0 : _information_T_558; // @[Lookup.scala 33:37]
  wire [1:0] information_6 = _information_T_1 ? 2'h0 : _information_T_559; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_574 = _information_T_97 ? 2'h2 : _information_T_511; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_575 = _information_T_95 ? 2'h2 : _information_T_574; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_576 = _information_T_93 ? 2'h2 : _information_T_575; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_577 = _information_T_91 ? 2'h1 : _information_T_576; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_578 = _information_T_89 ? 2'h1 : _information_T_577; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_579 = _information_T_87 ? 2'h1 : _information_T_578; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_580 = _information_T_85 ? 2'h1 : _information_T_579; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_581 = _information_T_83 ? 2'h1 : _information_T_580; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_582 = _information_T_81 ? 2'h1 : _information_T_581; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_583 = _information_T_79 ? 2'h1 : _information_T_582; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_584 = _information_T_77 ? 2'h1 : _information_T_583; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_585 = _information_T_75 ? 2'h1 : _information_T_584; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_586 = _information_T_73 ? 2'h1 : _information_T_585; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_587 = _information_T_71 ? 2'h1 : _information_T_586; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_588 = _information_T_69 ? 2'h1 : _information_T_587; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_589 = _information_T_67 ? 2'h1 : _information_T_588; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_590 = _information_T_65 ? 2'h1 : _information_T_589; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_591 = _information_T_63 ? 2'h1 : _information_T_590; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_592 = _information_T_61 ? 2'h1 : _information_T_591; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_593 = _information_T_59 ? 2'h1 : _information_T_592; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_594 = _information_T_57 ? 2'h1 : _information_T_593; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_595 = _information_T_55 ? 2'h1 : _information_T_594; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_596 = _information_T_53 ? 2'h2 : _information_T_595; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_597 = _information_T_51 ? 2'h2 : _information_T_596; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_598 = _information_T_49 ? 2'h2 : _information_T_597; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_599 = _information_T_47 ? 2'h2 : _information_T_598; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_600 = _information_T_45 ? 2'h2 : _information_T_599; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_601 = _information_T_43 ? 2'h2 : _information_T_600; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_602 = _information_T_41 ? 2'h2 : _information_T_601; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_603 = _information_T_39 ? 2'h2 : _information_T_602; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_604 = _information_T_37 ? 2'h2 : _information_T_603; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_605 = _information_T_35 ? 2'h2 : _information_T_604; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_606 = _information_T_33 ? 2'h2 : _information_T_605; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_607 = _information_T_31 ? 2'h2 : _information_T_606; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_608 = _information_T_29 ? 2'h2 : _information_T_607; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_609 = _information_T_27 ? 2'h2 : _information_T_608; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_610 = _information_T_25 ? 2'h2 : _information_T_609; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_611 = _information_T_23 ? 2'h2 : _information_T_610; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_612 = _information_T_21 ? 2'h2 : _information_T_611; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_613 = _information_T_19 ? 2'h1 : _information_T_612; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_614 = _information_T_17 ? 2'h1 : _information_T_613; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_615 = _information_T_15 ? 2'h1 : _information_T_614; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_616 = _information_T_13 ? 2'h1 : _information_T_615; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_617 = _information_T_11 ? 2'h1 : _information_T_616; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_618 = _information_T_9 ? 2'h1 : _information_T_617; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_619 = _information_T_7 ? 2'h2 : _information_T_618; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_620 = _information_T_5 ? 2'h2 : _information_T_619; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_621 = _information_T_3 ? 2'h2 : _information_T_620; // @[Lookup.scala 33:37]
  wire [1:0] information_7 = _information_T_1 ? 2'h2 : _information_T_621; // @[Lookup.scala 33:37]
  wire  _information_T_636 = _information_T_97 ? 1'h0 : _information_T_99 | (_information_T_101 | (_information_T_103 |
    (_information_T_105 | (_information_T_107 | (_information_T_109 | (_information_T_111 | (_information_T_113 | (
    _information_T_115 | (_information_T_117 | (_information_T_119 | (_information_T_121 | (_information_T_123 |
    _information_T_125)))))))))))); // @[Lookup.scala 33:37]
  wire  _information_T_666 = _information_T_37 | (_information_T_39 | (_information_T_41 | (_information_T_43 | (
    _information_T_45 | (_information_T_47 | (_information_T_49 | (_information_T_51 | (_information_T_53 | (
    _information_T_55 | (_information_T_57 | (_information_T_59 | (_information_T_61 | (_information_T_63 | (
    _information_T_65 | (_information_T_67 | (_information_T_69 | (_information_T_71 | (_information_T_73 | (
    _information_T_75 | (_information_T_77 | (_information_T_79 | (_information_T_81 | (_information_T_83 | (
    _information_T_85 | (_information_T_87 | (_information_T_89 | (_information_T_91 | (_information_T_93 | (
    _information_T_95 | _information_T_636))))))))))))))))))))))))))))); // @[Lookup.scala 33:37]
  wire  _information_T_667 = _information_T_35 ? 1'h0 : _information_T_666; // @[Lookup.scala 33:37]
  wire  _information_T_668 = _information_T_33 ? 1'h0 : _information_T_667; // @[Lookup.scala 33:37]
  wire  _information_T_669 = _information_T_31 ? 1'h0 : _information_T_668; // @[Lookup.scala 33:37]
  wire  _information_T_675 = _information_T_19 ? 1'h0 : _information_T_21 | (_information_T_23 | (_information_T_25 | (
    _information_T_27 | (_information_T_29 | _information_T_669)))); // @[Lookup.scala 33:37]
  wire  _information_T_676 = _information_T_17 ? 1'h0 : _information_T_675; // @[Lookup.scala 33:37]
  wire  _information_T_677 = _information_T_15 ? 1'h0 : _information_T_676; // @[Lookup.scala 33:37]
  wire  _information_T_678 = _information_T_13 ? 1'h0 : _information_T_677; // @[Lookup.scala 33:37]
  wire  _information_T_679 = _information_T_11 ? 1'h0 : _information_T_678; // @[Lookup.scala 33:37]
  wire  _information_T_680 = _information_T_9 ? 1'h0 : _information_T_679; // @[Lookup.scala 33:37]
  wire  information_8 = _information_T_1 | (_information_T_3 | (_information_T_5 | (_information_T_7 |
    _information_T_680))); // @[Lookup.scala 33:37]
  wire  _information_T_690 = _information_T_113 ? 1'h0 : _information_T_115 | (_information_T_117 | (_information_T_119
     | (_information_T_121 | (_information_T_123 | _information_T_125)))); // @[Lookup.scala 33:37]
  wire  _information_T_691 = _information_T_111 ? 1'h0 : _information_T_690; // @[Lookup.scala 33:37]
  wire  _information_T_692 = _information_T_109 ? 1'h0 : _information_T_691; // @[Lookup.scala 33:37]
  wire  _information_T_693 = _information_T_107 ? 1'h0 : _information_T_692; // @[Lookup.scala 33:37]
  wire  _information_T_694 = _information_T_105 ? 1'h0 : _information_T_693; // @[Lookup.scala 33:37]
  wire  _information_T_695 = _information_T_103 ? 1'h0 : _information_T_694; // @[Lookup.scala 33:37]
  wire  _information_T_696 = _information_T_101 ? 1'h0 : _information_T_695; // @[Lookup.scala 33:37]
  wire  _information_T_697 = _information_T_99 ? 1'h0 : _information_T_696; // @[Lookup.scala 33:37]
  wire  _information_T_710 = _information_T_73 ? 1'h0 : _information_T_75 | (_information_T_77 | (_information_T_79 | (
    _information_T_81 | (_information_T_83 | (_information_T_85 | (_information_T_87 | (_information_T_89 | (
    _information_T_91 | (_information_T_93 | (_information_T_95 | (_information_T_97 | _information_T_697))))))))))); // @[Lookup.scala 33:37]
  wire  _information_T_711 = _information_T_71 ? 1'h0 : _information_T_710; // @[Lookup.scala 33:37]
  wire  _information_T_712 = _information_T_69 ? 1'h0 : _information_T_711; // @[Lookup.scala 33:37]
  wire  _information_T_713 = _information_T_67 ? 1'h0 : _information_T_712; // @[Lookup.scala 33:37]
  wire  _information_T_714 = _information_T_65 ? 1'h0 : _information_T_713; // @[Lookup.scala 33:37]
  wire  _information_T_715 = _information_T_63 ? 1'h0 : _information_T_714; // @[Lookup.scala 33:37]
  wire  _information_T_716 = _information_T_61 ? 1'h0 : _information_T_715; // @[Lookup.scala 33:37]
  wire  _information_T_717 = _information_T_59 ? 1'h0 : _information_T_716; // @[Lookup.scala 33:37]
  wire  _information_T_718 = _information_T_57 ? 1'h0 : _information_T_717; // @[Lookup.scala 33:37]
  wire  _information_T_719 = _information_T_55 ? 1'h0 : _information_T_718; // @[Lookup.scala 33:37]
  wire  _information_T_720 = _information_T_53 ? 1'h0 : _information_T_719; // @[Lookup.scala 33:37]
  wire  _information_T_721 = _information_T_51 ? 1'h0 : _information_T_720; // @[Lookup.scala 33:37]
  wire  _information_T_722 = _information_T_49 ? 1'h0 : _information_T_721; // @[Lookup.scala 33:37]
  wire  _information_T_723 = _information_T_47 ? 1'h0 : _information_T_722; // @[Lookup.scala 33:37]
  wire  _information_T_724 = _information_T_45 ? 1'h0 : _information_T_723; // @[Lookup.scala 33:37]
  wire  _information_T_725 = _information_T_43 ? 1'h0 : _information_T_724; // @[Lookup.scala 33:37]
  wire  _information_T_726 = _information_T_41 ? 1'h0 : _information_T_725; // @[Lookup.scala 33:37]
  wire  _information_T_727 = _information_T_39 ? 1'h0 : _information_T_726; // @[Lookup.scala 33:37]
  wire  _information_T_728 = _information_T_37 ? 1'h0 : _information_T_727; // @[Lookup.scala 33:37]
  wire  _information_T_729 = _information_T_35 ? 1'h0 : _information_T_728; // @[Lookup.scala 33:37]
  wire  _information_T_730 = _information_T_33 ? 1'h0 : _information_T_729; // @[Lookup.scala 33:37]
  wire  _information_T_731 = _information_T_31 ? 1'h0 : _information_T_730; // @[Lookup.scala 33:37]
  wire  _information_T_732 = _information_T_29 ? 1'h0 : _information_T_731; // @[Lookup.scala 33:37]
  wire  _information_T_733 = _information_T_27 ? 1'h0 : _information_T_732; // @[Lookup.scala 33:37]
  wire  _information_T_734 = _information_T_25 ? 1'h0 : _information_T_733; // @[Lookup.scala 33:37]
  wire  _information_T_735 = _information_T_23 ? 1'h0 : _information_T_734; // @[Lookup.scala 33:37]
  wire  _information_T_736 = _information_T_21 ? 1'h0 : _information_T_735; // @[Lookup.scala 33:37]
  wire  _information_T_737 = _information_T_19 ? 1'h0 : _information_T_736; // @[Lookup.scala 33:37]
  wire  _information_T_738 = _information_T_17 ? 1'h0 : _information_T_737; // @[Lookup.scala 33:37]
  wire  _information_T_739 = _information_T_15 ? 1'h0 : _information_T_738; // @[Lookup.scala 33:37]
  wire  _information_T_740 = _information_T_13 ? 1'h0 : _information_T_739; // @[Lookup.scala 33:37]
  wire  _information_T_741 = _information_T_11 ? 1'h0 : _information_T_740; // @[Lookup.scala 33:37]
  wire  _information_T_742 = _information_T_9 ? 1'h0 : _information_T_741; // @[Lookup.scala 33:37]
  wire  _information_T_743 = _information_T_7 ? 1'h0 : _information_T_742; // @[Lookup.scala 33:37]
  wire  _information_T_744 = _information_T_5 ? 1'h0 : _information_T_743; // @[Lookup.scala 33:37]
  wire  _information_T_745 = _information_T_3 ? 1'h0 : _information_T_744; // @[Lookup.scala 33:37]
  wire [63:0] _imm_T_1 = 3'h1 == information_1 ? imm_i : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _imm_T_3 = 3'h2 == information_1 ? imm_s : _imm_T_1; // @[Mux.scala 80:57]
  wire [63:0] _imm_T_5 = 3'h3 == information_1 ? imm_b : _imm_T_3; // @[Mux.scala 80:57]
  wire [63:0] _imm_T_7 = 3'h4 == information_1 ? imm_u : _imm_T_5; // @[Mux.scala 80:57]
  wire [63:0] imm = 3'h5 == information_1 ? imm_j : _imm_T_7; // @[Mux.scala 80:57]
  wire [63:0] _src1_value_T_1 = 2'h0 == information_6 ? pc : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] rs1_value = regfile_io_rdata1; // @[Top.scala 35:23 Top.scala 203:13]
  wire [63:0] rs2_value = regfile_io_rdata2; // @[Top.scala 36:23 Top.scala 204:13]
  wire [63:0] _src2_value_T_1 = 2'h1 == information_7 ? rs2_value : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _rf_wdata_T_1 = pc + 64'h4; // @[Top.scala 197:19]
  wire [63:0] alu_result = alu_io_result; // @[Top.scala 29:24 Top.scala 185:14]
  wire [63:0] _rf_wdata_T_3 = 2'h0 == fu_type ? alu_result : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _rf_wdata_T_5 = 2'h1 == fu_type ? _rf_wdata_T_1 : _rf_wdata_T_3; // @[Mux.scala 80:57]
  wire [63:0] mem_rdata = blackbox_mem_rdata; // @[Top.scala 40:23 Top.scala 305:13]
  wire [2:0] raddr_low = alu_result[2:0]; // @[Top.scala 249:25]
  wire [31:0] lwu_rdata_lo_1 = mem_rdata[63:32]; // @[Top.scala 290:40]
  wire [63:0] _lwu_rdata_T_1 = {32'h0,lwu_rdata_lo_1}; // @[Cat.scala 30:58]
  wire [31:0] lwu_rdata_lo = mem_rdata[31:0]; // @[Top.scala 289:40]
  wire [63:0] _lwu_rdata_T = {32'h0,lwu_rdata_lo}; // @[Cat.scala 30:58]
  wire [63:0] _lwu_rdata_T_3 = 3'h0 == raddr_low ? _lwu_rdata_T : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] lwu_rdata = 3'h4 == raddr_low ? _lwu_rdata_T_1 : _lwu_rdata_T_3; // @[Mux.scala 80:57]
  wire [31:0] lw_rdata_hi_1 = mem_rdata[63] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _lw_rdata_T_5 = {lw_rdata_hi_1,lwu_rdata_lo_1}; // @[Cat.scala 30:58]
  wire [31:0] lw_rdata_hi = mem_rdata[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _lw_rdata_T_2 = {lw_rdata_hi,lwu_rdata_lo}; // @[Cat.scala 30:58]
  wire [63:0] _lw_rdata_T_7 = 3'h0 == raddr_low ? _lw_rdata_T_2 : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] lw_rdata = 3'h4 == raddr_low ? _lw_rdata_T_5 : _lw_rdata_T_7; // @[Mux.scala 80:57]
  wire [15:0] lhu_rdata_lo_3 = mem_rdata[63:48]; // @[Top.scala 282:40]
  wire [63:0] _lhu_rdata_T_3 = {48'h0,lhu_rdata_lo_3}; // @[Cat.scala 30:58]
  wire [15:0] lhu_rdata_lo_2 = mem_rdata[47:32]; // @[Top.scala 281:40]
  wire [63:0] _lhu_rdata_T_2 = {48'h0,lhu_rdata_lo_2}; // @[Cat.scala 30:58]
  wire [15:0] lhu_rdata_lo_1 = mem_rdata[31:16]; // @[Top.scala 280:40]
  wire [63:0] _lhu_rdata_T_1 = {48'h0,lhu_rdata_lo_1}; // @[Cat.scala 30:58]
  wire [15:0] lhu_rdata_lo = mem_rdata[15:0]; // @[Top.scala 279:40]
  wire [63:0] _lhu_rdata_T = {48'h0,lhu_rdata_lo}; // @[Cat.scala 30:58]
  wire [63:0] _lhu_rdata_T_5 = 3'h0 == raddr_low ? _lhu_rdata_T : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _lhu_rdata_T_7 = 3'h2 == raddr_low ? _lhu_rdata_T_1 : _lhu_rdata_T_5; // @[Mux.scala 80:57]
  wire [63:0] _lhu_rdata_T_9 = 3'h4 == raddr_low ? _lhu_rdata_T_2 : _lhu_rdata_T_7; // @[Mux.scala 80:57]
  wire [63:0] lhu_rdata = 3'h6 == raddr_low ? _lhu_rdata_T_3 : _lhu_rdata_T_9; // @[Mux.scala 80:57]
  wire [47:0] lh_rdata_hi_3 = mem_rdata[63] ? 48'hffffffffffff : 48'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _lh_rdata_T_11 = {lh_rdata_hi_3,lhu_rdata_lo_3}; // @[Cat.scala 30:58]
  wire [47:0] lh_rdata_hi_2 = mem_rdata[47] ? 48'hffffffffffff : 48'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _lh_rdata_T_8 = {lh_rdata_hi_2,lhu_rdata_lo_2}; // @[Cat.scala 30:58]
  wire [47:0] lh_rdata_hi_1 = mem_rdata[31] ? 48'hffffffffffff : 48'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _lh_rdata_T_5 = {lh_rdata_hi_1,lhu_rdata_lo_1}; // @[Cat.scala 30:58]
  wire [47:0] lh_rdata_hi = mem_rdata[15] ? 48'hffffffffffff : 48'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _lh_rdata_T_2 = {lh_rdata_hi,lhu_rdata_lo}; // @[Cat.scala 30:58]
  wire [63:0] _lh_rdata_T_13 = 3'h0 == raddr_low ? _lh_rdata_T_2 : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _lh_rdata_T_15 = 3'h2 == raddr_low ? _lh_rdata_T_5 : _lh_rdata_T_13; // @[Mux.scala 80:57]
  wire [63:0] _lh_rdata_T_17 = 3'h4 == raddr_low ? _lh_rdata_T_8 : _lh_rdata_T_15; // @[Mux.scala 80:57]
  wire [63:0] lh_rdata = 3'h6 == raddr_low ? _lh_rdata_T_11 : _lh_rdata_T_17; // @[Mux.scala 80:57]
  wire [7:0] lbu_rdata_lo_7 = mem_rdata[63:56]; // @[Top.scala 270:40]
  wire [63:0] _lbu_rdata_T_7 = {56'h0,lbu_rdata_lo_7}; // @[Cat.scala 30:58]
  wire [7:0] lbu_rdata_lo_6 = mem_rdata[55:48]; // @[Top.scala 269:40]
  wire [63:0] _lbu_rdata_T_6 = {56'h0,lbu_rdata_lo_6}; // @[Cat.scala 30:58]
  wire [7:0] lbu_rdata_lo_5 = mem_rdata[47:40]; // @[Top.scala 268:40]
  wire [63:0] _lbu_rdata_T_5 = {56'h0,lbu_rdata_lo_5}; // @[Cat.scala 30:58]
  wire [7:0] lbu_rdata_lo_4 = mem_rdata[39:32]; // @[Top.scala 267:40]
  wire [63:0] _lbu_rdata_T_4 = {56'h0,lbu_rdata_lo_4}; // @[Cat.scala 30:58]
  wire [7:0] lbu_rdata_lo_3 = mem_rdata[31:24]; // @[Top.scala 266:40]
  wire [63:0] _lbu_rdata_T_3 = {56'h0,lbu_rdata_lo_3}; // @[Cat.scala 30:58]
  wire [7:0] lbu_rdata_lo_2 = mem_rdata[23:16]; // @[Top.scala 265:40]
  wire [63:0] _lbu_rdata_T_2 = {56'h0,lbu_rdata_lo_2}; // @[Cat.scala 30:58]
  wire [7:0] lbu_rdata_lo_1 = mem_rdata[15:8]; // @[Top.scala 264:40]
  wire [63:0] _lbu_rdata_T_1 = {56'h0,lbu_rdata_lo_1}; // @[Cat.scala 30:58]
  wire [7:0] lbu_rdata_lo = mem_rdata[7:0]; // @[Top.scala 263:40]
  wire [63:0] _lbu_rdata_T = {56'h0,lbu_rdata_lo}; // @[Cat.scala 30:58]
  wire [63:0] _lbu_rdata_T_9 = 3'h1 == raddr_low ? _lbu_rdata_T_1 : _lbu_rdata_T; // @[Mux.scala 80:57]
  wire [63:0] _lbu_rdata_T_11 = 3'h2 == raddr_low ? _lbu_rdata_T_2 : _lbu_rdata_T_9; // @[Mux.scala 80:57]
  wire [63:0] _lbu_rdata_T_13 = 3'h3 == raddr_low ? _lbu_rdata_T_3 : _lbu_rdata_T_11; // @[Mux.scala 80:57]
  wire [63:0] _lbu_rdata_T_15 = 3'h4 == raddr_low ? _lbu_rdata_T_4 : _lbu_rdata_T_13; // @[Mux.scala 80:57]
  wire [63:0] _lbu_rdata_T_17 = 3'h5 == raddr_low ? _lbu_rdata_T_5 : _lbu_rdata_T_15; // @[Mux.scala 80:57]
  wire [63:0] _lbu_rdata_T_19 = 3'h6 == raddr_low ? _lbu_rdata_T_6 : _lbu_rdata_T_17; // @[Mux.scala 80:57]
  wire [63:0] lbu_rdata = 3'h7 == raddr_low ? _lbu_rdata_T_7 : _lbu_rdata_T_19; // @[Mux.scala 80:57]
  wire [55:0] lb_rdata_hi_7 = mem_rdata[63] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _lb_rdata_T_23 = {lb_rdata_hi_7,lbu_rdata_lo_7}; // @[Cat.scala 30:58]
  wire [55:0] lb_rdata_hi_6 = mem_rdata[55] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _lb_rdata_T_20 = {lb_rdata_hi_6,lbu_rdata_lo_6}; // @[Cat.scala 30:58]
  wire [55:0] lb_rdata_hi_5 = mem_rdata[47] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _lb_rdata_T_17 = {lb_rdata_hi_5,lbu_rdata_lo_5}; // @[Cat.scala 30:58]
  wire [55:0] lb_rdata_hi_4 = mem_rdata[39] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _lb_rdata_T_14 = {lb_rdata_hi_4,lbu_rdata_lo_4}; // @[Cat.scala 30:58]
  wire [55:0] lb_rdata_hi_3 = mem_rdata[31] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _lb_rdata_T_11 = {lb_rdata_hi_3,lbu_rdata_lo_3}; // @[Cat.scala 30:58]
  wire [55:0] lb_rdata_hi_2 = mem_rdata[23] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _lb_rdata_T_8 = {lb_rdata_hi_2,lbu_rdata_lo_2}; // @[Cat.scala 30:58]
  wire [55:0] lb_rdata_hi_1 = mem_rdata[15] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _lb_rdata_T_5 = {lb_rdata_hi_1,lbu_rdata_lo_1}; // @[Cat.scala 30:58]
  wire [55:0] lb_rdata_hi = mem_rdata[7] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _lb_rdata_T_2 = {lb_rdata_hi,lbu_rdata_lo}; // @[Cat.scala 30:58]
  wire [63:0] _lb_rdata_T_25 = 3'h1 == raddr_low ? _lb_rdata_T_5 : _lb_rdata_T_2; // @[Mux.scala 80:57]
  wire [63:0] _lb_rdata_T_27 = 3'h2 == raddr_low ? _lb_rdata_T_8 : _lb_rdata_T_25; // @[Mux.scala 80:57]
  wire [63:0] _lb_rdata_T_29 = 3'h3 == raddr_low ? _lb_rdata_T_11 : _lb_rdata_T_27; // @[Mux.scala 80:57]
  wire [63:0] _lb_rdata_T_31 = 3'h4 == raddr_low ? _lb_rdata_T_14 : _lb_rdata_T_29; // @[Mux.scala 80:57]
  wire [63:0] _lb_rdata_T_33 = 3'h5 == raddr_low ? _lb_rdata_T_17 : _lb_rdata_T_31; // @[Mux.scala 80:57]
  wire [63:0] _lb_rdata_T_35 = 3'h6 == raddr_low ? _lb_rdata_T_20 : _lb_rdata_T_33; // @[Mux.scala 80:57]
  wire [63:0] lb_rdata = 3'h7 == raddr_low ? _lb_rdata_T_23 : _lb_rdata_T_35; // @[Mux.scala 80:57]
  wire [63:0] _load_rdata_T_1 = 4'h1 == information_5 ? lb_rdata : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _load_rdata_T_3 = 4'h4 == information_5 ? lbu_rdata : _load_rdata_T_1; // @[Mux.scala 80:57]
  wire [63:0] _load_rdata_T_5 = 4'h2 == information_5 ? lh_rdata : _load_rdata_T_3; // @[Mux.scala 80:57]
  wire [63:0] _load_rdata_T_7 = 4'h5 == information_5 ? lhu_rdata : _load_rdata_T_5; // @[Mux.scala 80:57]
  wire [63:0] _load_rdata_T_9 = 4'h3 == information_5 ? lw_rdata : _load_rdata_T_7; // @[Mux.scala 80:57]
  wire [63:0] _load_rdata_T_11 = 4'h9 == information_5 ? lwu_rdata : _load_rdata_T_9; // @[Mux.scala 80:57]
  wire [63:0] load_rdata = 4'ha == information_5 ? mem_rdata : _load_rdata_T_11; // @[Mux.scala 80:57]
  wire  br_taken = bru_io_br_taken; // @[Top.scala 26:22 Top.scala 172:12]
  wire [63:0] br_target = bru_io_br_target; // @[Top.scala 27:23 Top.scala 173:13]
  wire [1:0] _sb_wmask_T_1 = 3'h1 == raddr_low ? 2'h2 : 2'h1; // @[Mux.scala 80:57]
  wire [2:0] _sb_wmask_T_3 = 3'h2 == raddr_low ? 3'h4 : {{1'd0}, _sb_wmask_T_1}; // @[Mux.scala 80:57]
  wire [3:0] _sb_wmask_T_5 = 3'h3 == raddr_low ? 4'h8 : {{1'd0}, _sb_wmask_T_3}; // @[Mux.scala 80:57]
  wire [4:0] _sb_wmask_T_7 = 3'h4 == raddr_low ? 5'h10 : {{1'd0}, _sb_wmask_T_5}; // @[Mux.scala 80:57]
  wire [5:0] _sb_wmask_T_9 = 3'h5 == raddr_low ? 6'h20 : {{1'd0}, _sb_wmask_T_7}; // @[Mux.scala 80:57]
  wire [6:0] _sb_wmask_T_11 = 3'h6 == raddr_low ? 7'h40 : {{1'd0}, _sb_wmask_T_9}; // @[Mux.scala 80:57]
  wire [7:0] sb_wmask = 3'h7 == raddr_low ? 8'h80 : {{1'd0}, _sb_wmask_T_11}; // @[Mux.scala 80:57]
  wire [1:0] _sh_wmask_T_1 = 3'h0 == raddr_low ? 2'h3 : 2'h0; // @[Mux.scala 80:57]
  wire [3:0] _sh_wmask_T_3 = 3'h2 == raddr_low ? 4'hc : {{2'd0}, _sh_wmask_T_1}; // @[Mux.scala 80:57]
  wire [5:0] _sh_wmask_T_5 = 3'h4 == raddr_low ? 6'h30 : {{2'd0}, _sh_wmask_T_3}; // @[Mux.scala 80:57]
  wire [7:0] sh_wmask = 3'h6 == raddr_low ? 8'hc0 : {{2'd0}, _sh_wmask_T_5}; // @[Mux.scala 80:57]
  wire [3:0] _sw_wmask_T_1 = 3'h0 == raddr_low ? 4'hf : 4'h0; // @[Mux.scala 80:57]
  wire [7:0] sw_wmask = 3'h4 == raddr_low ? 8'hf0 : {{4'd0}, _sw_wmask_T_1}; // @[Mux.scala 80:57]
  wire [7:0] sb_wdata_hi = rs2_value[7:0]; // @[Top.scala 244:32]
  wire [63:0] sb_wdata = {sb_wdata_hi,sb_wdata_hi,sb_wdata_hi,sb_wdata_hi,sb_wdata_hi,sb_wdata_hi,sb_wdata_hi,
    sb_wdata_hi}; // @[Cat.scala 30:58]
  wire [15:0] sh_wdata_hi = rs2_value[15:0]; // @[Top.scala 245:32]
  wire [63:0] sh_wdata = {sh_wdata_hi,sh_wdata_hi,sh_wdata_hi,sh_wdata_hi}; // @[Cat.scala 30:58]
  wire [31:0] sw_wdata_hi = rs2_value[31:0]; // @[Top.scala 246:32]
  wire [63:0] sw_wdata = {sw_wdata_hi,sw_wdata_hi}; // @[Cat.scala 30:58]
  wire  _mem_read_T = fu_type == 2'h2; // @[Top.scala 303:24]
  wire [7:0] _mem_wmask_T_1 = 4'h6 == information_5 ? sb_wmask : 8'h0; // @[Mux.scala 80:57]
  wire [7:0] _mem_wmask_T_3 = 4'h7 == information_5 ? sh_wmask : _mem_wmask_T_1; // @[Mux.scala 80:57]
  wire [7:0] _mem_wmask_T_5 = 4'h8 == information_5 ? sw_wmask : _mem_wmask_T_3; // @[Mux.scala 80:57]
  wire [63:0] _mem_wdata_T_1 = 4'h6 == information_5 ? sb_wdata : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _mem_wdata_T_3 = 4'h7 == information_5 ? sh_wdata : _mem_wdata_T_1; // @[Mux.scala 80:57]
  wire [63:0] _mem_wdata_T_5 = 4'h8 == information_5 ? sw_wdata : _mem_wdata_T_3; // @[Mux.scala 80:57]
  BRU bru ( // @[Top.scala 170:19]
    .io_bruop(bru_io_bruop),
    .io_src1(bru_io_src1),
    .io_src2(bru_io_src2),
    .io_pc(bru_io_pc),
    .io_imm(bru_io_imm),
    .io_br_taken(bru_io_br_taken),
    .io_br_target(bru_io_br_target)
  );
  ALU alu ( // @[Top.scala 182:19]
    .io_aluop(alu_io_aluop),
    .io_rv64(alu_io_rv64),
    .io_src1(alu_io_src1),
    .io_src2(alu_io_src2),
    .io_result(alu_io_result)
  );
  Regfile regfile ( // @[Top.scala 192:23]
    .clock(regfile_clock),
    .io_raddr1(regfile_io_raddr1),
    .io_rdata1(regfile_io_rdata1),
    .io_raddr2(regfile_io_raddr2),
    .io_rdata2(regfile_io_rdata2),
    .io_waddr(regfile_io_waddr),
    .io_wdata(regfile_io_wdata),
    .io_wen(regfile_io_wen)
  );
  Blackbox blackbox ( // @[Top.scala 218:24]
    .mem_read(blackbox_mem_read),
    .mem_raddr(blackbox_mem_raddr),
    .mem_rdata(blackbox_mem_rdata),
    .mem_write(blackbox_mem_write),
    .mem_waddr(blackbox_mem_waddr),
    .mem_wmask(blackbox_mem_wmask),
    .mem_wdata(blackbox_mem_wdata),
    .inst_ready(blackbox_inst_ready),
    .pc(blackbox_pc),
    .inst_2(blackbox_inst_2),
    .ebreak(blackbox_ebreak)
  );
  assign io_pc = pc; // @[Top.scala 212:9]
  assign bru_io_bruop = _information_T_1 ? 4'h0 : _information_T_435; // @[Lookup.scala 33:37]
  assign bru_io_src1 = 2'h1 == information_6 ? rs1_value : _src1_value_T_1; // @[Mux.scala 80:57]
  assign bru_io_src2 = 2'h2 == information_7 ? imm : _src2_value_T_1; // @[Mux.scala 80:57]
  assign bru_io_pc = pc; // @[Top.scala 178:13]
  assign bru_io_imm = imm[31:0]; // @[Top.scala 179:14]
  assign alu_io_aluop = _information_T_1 ? 5'h1 : _information_T_373; // @[Lookup.scala 33:37]
  assign alu_io_rv64 = _information_T_1 ? 1'h0 : _information_T_745; // @[Lookup.scala 33:37]
  assign alu_io_src1 = {{62'd0}, information_6}; // @[Lookup.scala 33:37]
  assign alu_io_src2 = {{62'd0}, information_7}; // @[Lookup.scala 33:37]
  assign regfile_clock = clock;
  assign regfile_io_raddr1 = inst[19:15]; // @[Top.scala 200:20]
  assign regfile_io_raddr2 = inst[24:20]; // @[Top.scala 201:20]
  assign regfile_io_waddr = inst[11:7]; // @[Top.scala 194:19]
  assign regfile_io_wdata = 2'h2 == fu_type ? load_rdata : _rf_wdata_T_5; // @[Mux.scala 80:57]
  assign regfile_io_wen = _information_T_1 | (_information_T_3 | (_information_T_5 | (_information_T_7 |
    _information_T_680))); // @[Lookup.scala 33:37]
  assign blackbox_mem_read = fu_type == 2'h2 & information_8; // @[Top.scala 303:36]
  assign blackbox_mem_raddr = alu_io_result; // @[Top.scala 29:24 Top.scala 185:14]
  assign blackbox_mem_write = _mem_read_T & ~information_8; // @[Top.scala 307:37]
  assign blackbox_mem_waddr = alu_io_result; // @[Top.scala 29:24 Top.scala 185:14]
  assign blackbox_mem_wmask = 4'hb == information_5 ? 8'hff : _mem_wmask_T_5; // @[Mux.scala 80:57]
  assign blackbox_mem_wdata = 4'hb == information_5 ? rs2_value : _mem_wdata_T_5; // @[Mux.scala 80:57]
  assign blackbox_inst_ready = inst_ready; // @[Top.scala 333:26]
  assign blackbox_pc = pc; // @[Top.scala 334:18]
  assign blackbox_ebreak = ~information_0; // @[Top.scala 322:25]
  always @(posedge clock) begin
    if (reset) begin // @[Top.scala 11:19]
      pc <= 64'h80000000; // @[Top.scala 11:19]
    end else if (br_taken) begin // @[Top.scala 213:17]
      pc <= br_target;
    end else begin
      pc <= _rf_wdata_T_1;
    end
    if (reset) begin // @[Top.scala 47:27]
      inst_ready <= 1'h0; // @[Top.scala 47:27]
    end else begin
      inst_ready <= 1'h1; // @[Top.scala 323:14]
    end
  end
// Register and memory initialization
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {2{`RANDOM}};
  pc = _RAND_0[63:0];
  _RAND_1 = {1{`RANDOM}};
  inst_ready = _RAND_1[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
