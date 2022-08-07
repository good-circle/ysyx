module IFU(
  input         clock,
  input         reset,
  output        io_imem_en,
  output [63:0] io_imem_addr,
  input  [63:0] io_imem_rdata,
  output        io_out_valid,
  output [31:0] io_out_bits_pc,
  output [31:0] io_out_bits_inst,
  input         io_br_bus_br_taken,
  input  [31:0] io_br_bus_br_target,
  input         io_csr_br_bus_is_reflush,
  input  [31:0] io_csr_br_bus_br_target
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
`endif // RANDOMIZE_REG_INIT
  reg  pc_en; // @[IFU.scala 12:22]
  reg [31:0] pc; // @[IFU.scala 13:19]
  reg  if_valid; // @[IFU.scala 21:25]
  wire [31:0] _next_pc_T_1 = pc + 32'h4; // @[IFU.scala 25:73]
  assign io_imem_en = if_valid; // @[IFU.scala 28:14]
  assign io_imem_addr = {{32'd0}, pc}; // @[IFU.scala 29:16]
  assign io_out_valid = ~io_br_bus_br_taken & pc_en; // @[IFU.scala 33:29]
  assign io_out_bits_pc = pc_en ? pc : 32'h0; // @[IFU.scala 31:24]
  assign io_out_bits_inst = pc_en ? io_imem_rdata[31:0] : 32'h0; // @[IFU.scala 32:26]
  always @(posedge clock) begin
    if (reset) begin // @[IFU.scala 12:22]
      pc_en <= 1'h0; // @[IFU.scala 12:22]
    end else begin
      pc_en <= 1'h1; // @[IFU.scala 24:9]
    end
    if (reset) begin // @[IFU.scala 13:19]
      pc <= 32'h7ffffffc; // @[IFU.scala 13:19]
    end else if (io_csr_br_bus_is_reflush) begin // @[IFU.scala 25:17]
      pc <= io_csr_br_bus_br_target;
    end else if (io_br_bus_br_taken) begin // @[IFU.scala 25:48]
      pc <= io_br_bus_br_target;
    end else begin
      pc <= _next_pc_T_1;
    end
    if (reset) begin // @[IFU.scala 21:25]
      if_valid <= 1'h0; // @[IFU.scala 21:25]
    end else begin
      if_valid <= 1'h1; // @[IFU.scala 22:12]
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
  _RAND_0 = {1{`RANDOM}};
  pc_en = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  pc = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  if_valid = _RAND_2[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module BRU(
  input  [3:0]  io_bru_op,
  input  [63:0] io_src1,
  input  [63:0] io_src2,
  input  [31:0] io_pc,
  input  [63:0] io_imm,
  output        io_br_taken,
  output [31:0] io_br_target
);
  wire  _io_br_taken_T = io_src1 == io_src2; // @[BRU.scala 19:26]
  wire  _io_br_taken_T_1 = io_src1 != io_src2; // @[BRU.scala 20:26]
  wire  _io_br_taken_T_4 = $signed(io_src1) < $signed(io_src2); // @[BRU.scala 21:33]
  wire  _io_br_taken_T_7 = $signed(io_src1) >= $signed(io_src2); // @[BRU.scala 22:33]
  wire  _io_br_taken_T_8 = io_src1 < io_src2; // @[BRU.scala 23:33]
  wire  _io_br_taken_T_9 = io_src1 >= io_src2; // @[BRU.scala 24:33]
  wire  _io_br_taken_T_15 = 4'h3 == io_bru_op ? _io_br_taken_T : 4'h2 == io_bru_op | 4'h1 == io_bru_op; // @[Mux.scala 80:57]
  wire  _io_br_taken_T_17 = 4'h4 == io_bru_op ? _io_br_taken_T_1 : _io_br_taken_T_15; // @[Mux.scala 80:57]
  wire  _io_br_taken_T_19 = 4'h5 == io_bru_op ? _io_br_taken_T_4 : _io_br_taken_T_17; // @[Mux.scala 80:57]
  wire  _io_br_taken_T_21 = 4'h6 == io_bru_op ? _io_br_taken_T_7 : _io_br_taken_T_19; // @[Mux.scala 80:57]
  wire  _io_br_taken_T_23 = 4'h7 == io_bru_op ? _io_br_taken_T_8 : _io_br_taken_T_21; // @[Mux.scala 80:57]
  wire [63:0] _io_br_target_T_2 = io_src1 + io_imm; // @[BRU.scala 27:57]
  wire [63:0] _io_br_target_T_4 = {_io_br_target_T_2[63:1], 1'h0}; // @[BRU.scala 27:73]
  wire [63:0] _GEN_0 = {{32'd0}, io_pc}; // @[BRU.scala 27:85]
  wire [63:0] _io_br_target_T_6 = _GEN_0 + io_imm; // @[BRU.scala 27:85]
  wire [63:0] _io_br_target_T_7 = io_bru_op == 4'h2 ? _io_br_target_T_4 : _io_br_target_T_6; // @[BRU.scala 27:22]
  assign io_br_taken = 4'h8 == io_bru_op ? _io_br_taken_T_9 : _io_br_taken_T_23; // @[Mux.scala 80:57]
  assign io_br_target = _io_br_target_T_7[31:0]; // @[BRU.scala 27:16]
endmodule
module IDU(
  input         clock,
  input         io_in_valid,
  input  [31:0] io_in_bits_pc,
  input  [31:0] io_in_bits_inst,
  output        io_out_valid,
  output [31:0] io_out_bits_pc,
  output [31:0] io_out_bits_inst,
  output [63:0] io_out_bits_src1_value,
  output [63:0] io_out_bits_src2_value,
  output [63:0] io_out_bits_rs2_value,
  output [4:0]  io_out_bits_dest,
  output [1:0]  io_out_bits_fu_type,
  output [4:0]  io_out_bits_alu_op,
  output [3:0]  io_out_bits_lsu_op,
  output [2:0]  io_out_bits_csr_op,
  output        io_out_bits_wen,
  output        io_out_bits_rv64,
  output        io_br_bus_br_taken,
  output [31:0] io_br_bus_br_target,
  input         io_wb_bus_rf_wen,
  input  [4:0]  io_wb_bus_rf_waddr,
  input  [63:0] io_wb_bus_rf_wdata,
  input         io_ex_fwd_is_reflush,
  input         io_ex_fwd_fwd_valid,
  input  [4:0]  io_ex_fwd_rf_waddr,
  input  [63:0] io_ex_fwd_rf_wdata
);
  wire [3:0] bru_io_bru_op; // @[IDU.scala 152:19]
  wire [63:0] bru_io_src1; // @[IDU.scala 152:19]
  wire [63:0] bru_io_src2; // @[IDU.scala 152:19]
  wire [31:0] bru_io_pc; // @[IDU.scala 152:19]
  wire [63:0] bru_io_imm; // @[IDU.scala 152:19]
  wire  bru_io_br_taken; // @[IDU.scala 152:19]
  wire [31:0] bru_io_br_target; // @[IDU.scala 152:19]
  wire  rf__clock; // @[IDU.scala 162:18]
  wire [4:0] rf__raddr1; // @[IDU.scala 162:18]
  wire [4:0] rf__raddr2; // @[IDU.scala 162:18]
  wire [63:0] rf__rdata1; // @[IDU.scala 162:18]
  wire [63:0] rf__rdata2; // @[IDU.scala 162:18]
  wire [4:0] rf__waddr; // @[IDU.scala 162:18]
  wire [63:0] rf__wdata; // @[IDU.scala 162:18]
  wire  rf__wen; // @[IDU.scala 162:18]
  wire [51:0] imm_i_hi = io_in_bits_inst[31] ? 52'hfffffffffffff : 52'h0; // @[Bitwise.scala 72:12]
  wire [11:0] imm_i_lo = io_in_bits_inst[31:20]; // @[IDU.scala 19:43]
  wire [63:0] imm_i = {imm_i_hi,imm_i_lo}; // @[Cat.scala 30:58]
  wire [6:0] imm_s_hi_lo = io_in_bits_inst[31:25]; // @[IDU.scala 20:43]
  wire [4:0] imm_s_lo = io_in_bits_inst[11:7]; // @[IDU.scala 20:57]
  wire [63:0] imm_s = {imm_i_hi,imm_s_hi_lo,imm_s_lo}; // @[Cat.scala 30:58]
  wire  imm_b_hi_hi_lo = io_in_bits_inst[7]; // @[IDU.scala 21:43]
  wire [5:0] imm_b_hi_lo = io_in_bits_inst[30:25]; // @[IDU.scala 21:52]
  wire [3:0] imm_b_lo_hi = io_in_bits_inst[11:8]; // @[IDU.scala 21:66]
  wire [63:0] imm_b = {imm_i_hi,imm_b_hi_hi_lo,imm_b_hi_lo,imm_b_lo_hi,1'h0}; // @[Cat.scala 30:58]
  wire [31:0] imm_u_hi_hi = io_in_bits_inst[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [19:0] imm_u_hi_lo = io_in_bits_inst[31:12]; // @[IDU.scala 22:43]
  wire [63:0] imm_u = {imm_u_hi_hi,imm_u_hi_lo,12'h0}; // @[Cat.scala 30:58]
  wire [43:0] imm_j_hi_hi_hi = io_in_bits_inst[31] ? 44'hfffffffffff : 44'h0; // @[Bitwise.scala 72:12]
  wire [7:0] imm_j_hi_hi_lo = io_in_bits_inst[19:12]; // @[IDU.scala 23:43]
  wire  imm_j_hi_lo = io_in_bits_inst[20]; // @[IDU.scala 23:57]
  wire [9:0] imm_j_lo_hi = io_in_bits_inst[30:21]; // @[IDU.scala 23:67]
  wire [63:0] imm_j = {imm_j_hi_hi_hi,imm_j_hi_hi_lo,imm_j_hi_lo,imm_j_lo_hi,1'h0}; // @[Cat.scala 30:58]
  wire [31:0] _information_T = io_in_bits_inst & 32'h7f; // @[Lookup.scala 31:38]
  wire  _information_T_1 = 32'h37 == _information_T; // @[Lookup.scala 31:38]
  wire  _information_T_3 = 32'h17 == _information_T; // @[Lookup.scala 31:38]
  wire  _information_T_5 = 32'h6f == _information_T; // @[Lookup.scala 31:38]
  wire [31:0] _information_T_6 = io_in_bits_inst & 32'h707f; // @[Lookup.scala 31:38]
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
  wire [31:0] _information_T_48 = io_in_bits_inst & 32'hfc00707f; // @[Lookup.scala 31:38]
  wire  _information_T_49 = 32'h1013 == _information_T_48; // @[Lookup.scala 31:38]
  wire  _information_T_51 = 32'h5013 == _information_T_48; // @[Lookup.scala 31:38]
  wire  _information_T_53 = 32'h40005013 == _information_T_48; // @[Lookup.scala 31:38]
  wire [31:0] _information_T_54 = io_in_bits_inst & 32'hfe00707f; // @[Lookup.scala 31:38]
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
  wire  _information_T_125 = 32'h1073 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_127 = 32'h2073 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_129 = 32'h3073 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_131 = 32'h5073 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_133 = 32'h6073 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_135 = 32'h7073 == _information_T_6; // @[Lookup.scala 31:38]
  wire  _information_T_137 = 32'h73 == io_in_bits_inst; // @[Lookup.scala 31:38]
  wire  _information_T_139 = 32'h30200073 == io_in_bits_inst; // @[Lookup.scala 31:38]
  wire [2:0] _information_T_218 = _information_T_137 ? 3'h1 : 3'h0; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_219 = _information_T_135 ? 3'h1 : _information_T_218; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_220 = _information_T_133 ? 3'h1 : _information_T_219; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_221 = _information_T_131 ? 3'h1 : _information_T_220; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_222 = _information_T_129 ? 3'h1 : _information_T_221; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_223 = _information_T_127 ? 3'h1 : _information_T_222; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_224 = _information_T_125 ? 3'h1 : _information_T_223; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_225 = _information_T_123 ? 3'h0 : _information_T_224; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_226 = _information_T_121 ? 3'h0 : _information_T_225; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_227 = _information_T_119 ? 3'h0 : _information_T_226; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_228 = _information_T_117 ? 3'h0 : _information_T_227; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_229 = _information_T_115 ? 3'h0 : _information_T_228; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_230 = _information_T_113 ? 3'h0 : _information_T_229; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_231 = _information_T_111 ? 3'h0 : _information_T_230; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_232 = _information_T_109 ? 3'h0 : _information_T_231; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_233 = _information_T_107 ? 3'h0 : _information_T_232; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_234 = _information_T_105 ? 3'h0 : _information_T_233; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_235 = _information_T_103 ? 3'h0 : _information_T_234; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_236 = _information_T_101 ? 3'h0 : _information_T_235; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_237 = _information_T_99 ? 3'h0 : _information_T_236; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_238 = _information_T_97 ? 3'h2 : _information_T_237; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_239 = _information_T_95 ? 3'h1 : _information_T_238; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_240 = _information_T_93 ? 3'h1 : _information_T_239; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_241 = _information_T_91 ? 3'h0 : _information_T_240; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_242 = _information_T_89 ? 3'h0 : _information_T_241; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_243 = _information_T_87 ? 3'h0 : _information_T_242; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_244 = _information_T_85 ? 3'h0 : _information_T_243; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_245 = _information_T_83 ? 3'h0 : _information_T_244; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_246 = _information_T_81 ? 3'h1 : _information_T_245; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_247 = _information_T_79 ? 3'h1 : _information_T_246; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_248 = _information_T_77 ? 3'h1 : _information_T_247; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_249 = _information_T_75 ? 3'h1 : _information_T_248; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_250 = _information_T_73 ? 3'h0 : _information_T_249; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_251 = _information_T_71 ? 3'h0 : _information_T_250; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_252 = _information_T_69 ? 3'h0 : _information_T_251; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_253 = _information_T_67 ? 3'h0 : _information_T_252; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_254 = _information_T_65 ? 3'h0 : _information_T_253; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_255 = _information_T_63 ? 3'h0 : _information_T_254; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_256 = _information_T_61 ? 3'h0 : _information_T_255; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_257 = _information_T_59 ? 3'h0 : _information_T_256; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_258 = _information_T_57 ? 3'h0 : _information_T_257; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_259 = _information_T_55 ? 3'h0 : _information_T_258; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_260 = _information_T_53 ? 3'h1 : _information_T_259; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_261 = _information_T_51 ? 3'h1 : _information_T_260; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_262 = _information_T_49 ? 3'h1 : _information_T_261; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_263 = _information_T_47 ? 3'h1 : _information_T_262; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_264 = _information_T_45 ? 3'h1 : _information_T_263; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_265 = _information_T_43 ? 3'h1 : _information_T_264; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_266 = _information_T_41 ? 3'h1 : _information_T_265; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_267 = _information_T_39 ? 3'h1 : _information_T_266; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_268 = _information_T_37 ? 3'h1 : _information_T_267; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_269 = _information_T_35 ? 3'h2 : _information_T_268; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_270 = _information_T_33 ? 3'h2 : _information_T_269; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_271 = _information_T_31 ? 3'h2 : _information_T_270; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_272 = _information_T_29 ? 3'h1 : _information_T_271; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_273 = _information_T_27 ? 3'h1 : _information_T_272; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_274 = _information_T_25 ? 3'h1 : _information_T_273; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_275 = _information_T_23 ? 3'h1 : _information_T_274; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_276 = _information_T_21 ? 3'h1 : _information_T_275; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_277 = _information_T_19 ? 3'h3 : _information_T_276; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_278 = _information_T_17 ? 3'h3 : _information_T_277; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_279 = _information_T_15 ? 3'h3 : _information_T_278; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_280 = _information_T_13 ? 3'h3 : _information_T_279; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_281 = _information_T_11 ? 3'h3 : _information_T_280; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_282 = _information_T_9 ? 3'h3 : _information_T_281; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_283 = _information_T_7 ? 3'h1 : _information_T_282; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_284 = _information_T_5 ? 3'h5 : _information_T_283; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_285 = _information_T_3 ? 3'h4 : _information_T_284; // @[Lookup.scala 33:37]
  wire [2:0] information_1 = _information_T_1 ? 3'h4 : _information_T_285; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_288 = _information_T_139 ? 2'h3 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_289 = _information_T_137 ? 2'h3 : _information_T_288; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_290 = _information_T_135 ? 2'h3 : _information_T_289; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_291 = _information_T_133 ? 2'h3 : _information_T_290; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_292 = _information_T_131 ? 2'h3 : _information_T_291; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_293 = _information_T_129 ? 2'h3 : _information_T_292; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_294 = _information_T_127 ? 2'h3 : _information_T_293; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_295 = _information_T_125 ? 2'h3 : _information_T_294; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_296 = _information_T_123 ? 2'h0 : _information_T_295; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_297 = _information_T_121 ? 2'h0 : _information_T_296; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_298 = _information_T_119 ? 2'h0 : _information_T_297; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_299 = _information_T_117 ? 2'h0 : _information_T_298; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_300 = _information_T_115 ? 2'h0 : _information_T_299; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_301 = _information_T_113 ? 2'h0 : _information_T_300; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_302 = _information_T_111 ? 2'h0 : _information_T_301; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_303 = _information_T_109 ? 2'h0 : _information_T_302; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_304 = _information_T_107 ? 2'h0 : _information_T_303; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_305 = _information_T_105 ? 2'h0 : _information_T_304; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_306 = _information_T_103 ? 2'h0 : _information_T_305; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_307 = _information_T_101 ? 2'h0 : _information_T_306; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_308 = _information_T_99 ? 2'h0 : _information_T_307; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_309 = _information_T_97 ? 2'h2 : _information_T_308; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_310 = _information_T_95 ? 2'h2 : _information_T_309; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_311 = _information_T_93 ? 2'h2 : _information_T_310; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_312 = _information_T_91 ? 2'h0 : _information_T_311; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_313 = _information_T_89 ? 2'h0 : _information_T_312; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_314 = _information_T_87 ? 2'h0 : _information_T_313; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_315 = _information_T_85 ? 2'h0 : _information_T_314; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_316 = _information_T_83 ? 2'h0 : _information_T_315; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_317 = _information_T_81 ? 2'h0 : _information_T_316; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_318 = _information_T_79 ? 2'h0 : _information_T_317; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_319 = _information_T_77 ? 2'h0 : _information_T_318; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_320 = _information_T_75 ? 2'h0 : _information_T_319; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_321 = _information_T_73 ? 2'h0 : _information_T_320; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_322 = _information_T_71 ? 2'h0 : _information_T_321; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_323 = _information_T_69 ? 2'h0 : _information_T_322; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_324 = _information_T_67 ? 2'h0 : _information_T_323; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_325 = _information_T_65 ? 2'h0 : _information_T_324; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_326 = _information_T_63 ? 2'h0 : _information_T_325; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_327 = _information_T_61 ? 2'h0 : _information_T_326; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_328 = _information_T_59 ? 2'h0 : _information_T_327; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_329 = _information_T_57 ? 2'h0 : _information_T_328; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_330 = _information_T_55 ? 2'h0 : _information_T_329; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_331 = _information_T_53 ? 2'h0 : _information_T_330; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_332 = _information_T_51 ? 2'h0 : _information_T_331; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_333 = _information_T_49 ? 2'h0 : _information_T_332; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_334 = _information_T_47 ? 2'h0 : _information_T_333; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_335 = _information_T_45 ? 2'h0 : _information_T_334; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_336 = _information_T_43 ? 2'h0 : _information_T_335; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_337 = _information_T_41 ? 2'h0 : _information_T_336; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_338 = _information_T_39 ? 2'h0 : _information_T_337; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_339 = _information_T_37 ? 2'h0 : _information_T_338; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_340 = _information_T_35 ? 2'h2 : _information_T_339; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_341 = _information_T_33 ? 2'h2 : _information_T_340; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_342 = _information_T_31 ? 2'h2 : _information_T_341; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_343 = _information_T_29 ? 2'h2 : _information_T_342; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_344 = _information_T_27 ? 2'h2 : _information_T_343; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_345 = _information_T_25 ? 2'h2 : _information_T_344; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_346 = _information_T_23 ? 2'h2 : _information_T_345; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_347 = _information_T_21 ? 2'h2 : _information_T_346; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_348 = _information_T_19 ? 2'h1 : _information_T_347; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_349 = _information_T_17 ? 2'h1 : _information_T_348; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_350 = _information_T_15 ? 2'h1 : _information_T_349; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_351 = _information_T_13 ? 2'h1 : _information_T_350; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_352 = _information_T_11 ? 2'h1 : _information_T_351; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_353 = _information_T_9 ? 2'h1 : _information_T_352; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_354 = _information_T_7 ? 2'h1 : _information_T_353; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_355 = _information_T_5 ? 2'h1 : _information_T_354; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_356 = _information_T_3 ? 2'h0 : _information_T_355; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_367 = _information_T_123 ? 5'h12 : 5'h0; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_368 = _information_T_121 ? 5'h11 : _information_T_367; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_369 = _information_T_119 ? 5'h10 : _information_T_368; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_370 = _information_T_117 ? 5'hf : _information_T_369; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_371 = _information_T_115 ? 5'hb : _information_T_370; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_372 = _information_T_113 ? 5'h12 : _information_T_371; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_373 = _information_T_111 ? 5'h11 : _information_T_372; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_374 = _information_T_109 ? 5'h10 : _information_T_373; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_375 = _information_T_107 ? 5'hf : _information_T_374; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_376 = _information_T_105 ? 5'he : _information_T_375; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_377 = _information_T_103 ? 5'hd : _information_T_376; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_378 = _information_T_101 ? 5'hc : _information_T_377; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_379 = _information_T_99 ? 5'hb : _information_T_378; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_380 = _information_T_97 ? 5'h1 : _information_T_379; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_381 = _information_T_95 ? 5'h1 : _information_T_380; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_382 = _information_T_93 ? 5'h1 : _information_T_381; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_383 = _information_T_91 ? 5'ha : _information_T_382; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_384 = _information_T_89 ? 5'h9 : _information_T_383; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_385 = _information_T_87 ? 5'h8 : _information_T_384; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_386 = _information_T_85 ? 5'h2 : _information_T_385; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_387 = _information_T_83 ? 5'h1 : _information_T_386; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_388 = _information_T_81 ? 5'ha : _information_T_387; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_389 = _information_T_79 ? 5'h9 : _information_T_388; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_390 = _information_T_77 ? 5'h8 : _information_T_389; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_391 = _information_T_75 ? 5'h1 : _information_T_390; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_392 = _information_T_73 ? 5'h3 : _information_T_391; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_393 = _information_T_71 ? 5'h4 : _information_T_392; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_394 = _information_T_69 ? 5'ha : _information_T_393; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_395 = _information_T_67 ? 5'h9 : _information_T_394; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_396 = _information_T_65 ? 5'h5 : _information_T_395; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_397 = _information_T_63 ? 5'h7 : _information_T_396; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_398 = _information_T_61 ? 5'h6 : _information_T_397; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_399 = _information_T_59 ? 5'h8 : _information_T_398; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_400 = _information_T_57 ? 5'h2 : _information_T_399; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_401 = _information_T_55 ? 5'h1 : _information_T_400; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_402 = _information_T_53 ? 5'ha : _information_T_401; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_403 = _information_T_51 ? 5'h9 : _information_T_402; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_404 = _information_T_49 ? 5'h8 : _information_T_403; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_405 = _information_T_47 ? 5'h3 : _information_T_404; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_406 = _information_T_45 ? 5'h4 : _information_T_405; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_407 = _information_T_43 ? 5'h5 : _information_T_406; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_408 = _information_T_41 ? 5'h7 : _information_T_407; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_409 = _information_T_39 ? 5'h6 : _information_T_408; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_410 = _information_T_37 ? 5'h1 : _information_T_409; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_411 = _information_T_35 ? 5'h1 : _information_T_410; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_412 = _information_T_33 ? 5'h1 : _information_T_411; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_413 = _information_T_31 ? 5'h1 : _information_T_412; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_414 = _information_T_29 ? 5'h1 : _information_T_413; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_415 = _information_T_27 ? 5'h1 : _information_T_414; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_416 = _information_T_25 ? 5'h1 : _information_T_415; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_417 = _information_T_23 ? 5'h1 : _information_T_416; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_418 = _information_T_21 ? 5'h1 : _information_T_417; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_419 = _information_T_19 ? 5'h0 : _information_T_418; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_420 = _information_T_17 ? 5'h0 : _information_T_419; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_421 = _information_T_15 ? 5'h0 : _information_T_420; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_422 = _information_T_13 ? 5'h0 : _information_T_421; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_423 = _information_T_11 ? 5'h0 : _information_T_422; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_424 = _information_T_9 ? 5'h0 : _information_T_423; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_425 = _information_T_7 ? 5'h0 : _information_T_424; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_426 = _information_T_5 ? 5'h0 : _information_T_425; // @[Lookup.scala 33:37]
  wire [4:0] _information_T_427 = _information_T_3 ? 5'h1 : _information_T_426; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_490 = _information_T_19 ? 4'h8 : 4'h0; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_491 = _information_T_17 ? 4'h7 : _information_T_490; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_492 = _information_T_15 ? 4'h6 : _information_T_491; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_493 = _information_T_13 ? 4'h5 : _information_T_492; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_494 = _information_T_11 ? 4'h4 : _information_T_493; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_495 = _information_T_9 ? 4'h3 : _information_T_494; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_496 = _information_T_7 ? 4'h2 : _information_T_495; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_497 = _information_T_5 ? 4'h1 : _information_T_496; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_498 = _information_T_3 ? 4'h0 : _information_T_497; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_522 = _information_T_97 ? 4'hb : 4'h0; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_523 = _information_T_95 ? 4'ha : _information_T_522; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_524 = _information_T_93 ? 4'h9 : _information_T_523; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_525 = _information_T_91 ? 4'h0 : _information_T_524; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_526 = _information_T_89 ? 4'h0 : _information_T_525; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_527 = _information_T_87 ? 4'h0 : _information_T_526; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_528 = _information_T_85 ? 4'h0 : _information_T_527; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_529 = _information_T_83 ? 4'h0 : _information_T_528; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_530 = _information_T_81 ? 4'h0 : _information_T_529; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_531 = _information_T_79 ? 4'h0 : _information_T_530; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_532 = _information_T_77 ? 4'h0 : _information_T_531; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_533 = _information_T_75 ? 4'h0 : _information_T_532; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_534 = _information_T_73 ? 4'h0 : _information_T_533; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_535 = _information_T_71 ? 4'h0 : _information_T_534; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_536 = _information_T_69 ? 4'h0 : _information_T_535; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_537 = _information_T_67 ? 4'h0 : _information_T_536; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_538 = _information_T_65 ? 4'h0 : _information_T_537; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_539 = _information_T_63 ? 4'h0 : _information_T_538; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_540 = _information_T_61 ? 4'h0 : _information_T_539; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_541 = _information_T_59 ? 4'h0 : _information_T_540; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_542 = _information_T_57 ? 4'h0 : _information_T_541; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_543 = _information_T_55 ? 4'h0 : _information_T_542; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_544 = _information_T_53 ? 4'h0 : _information_T_543; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_545 = _information_T_51 ? 4'h0 : _information_T_544; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_546 = _information_T_49 ? 4'h0 : _information_T_545; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_547 = _information_T_47 ? 4'h0 : _information_T_546; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_548 = _information_T_45 ? 4'h0 : _information_T_547; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_549 = _information_T_43 ? 4'h0 : _information_T_548; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_550 = _information_T_41 ? 4'h0 : _information_T_549; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_551 = _information_T_39 ? 4'h0 : _information_T_550; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_552 = _information_T_37 ? 4'h0 : _information_T_551; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_553 = _information_T_35 ? 4'h8 : _information_T_552; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_554 = _information_T_33 ? 4'h7 : _information_T_553; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_555 = _information_T_31 ? 4'h6 : _information_T_554; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_556 = _information_T_29 ? 4'h5 : _information_T_555; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_557 = _information_T_27 ? 4'h4 : _information_T_556; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_558 = _information_T_25 ? 4'h3 : _information_T_557; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_559 = _information_T_23 ? 4'h2 : _information_T_558; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_560 = _information_T_21 ? 4'h1 : _information_T_559; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_561 = _information_T_19 ? 4'h0 : _information_T_560; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_562 = _information_T_17 ? 4'h0 : _information_T_561; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_563 = _information_T_15 ? 4'h0 : _information_T_562; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_564 = _information_T_13 ? 4'h0 : _information_T_563; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_565 = _information_T_11 ? 4'h0 : _information_T_564; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_566 = _information_T_9 ? 4'h0 : _information_T_565; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_567 = _information_T_7 ? 4'h0 : _information_T_566; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_568 = _information_T_5 ? 4'h0 : _information_T_567; // @[Lookup.scala 33:37]
  wire [3:0] _information_T_569 = _information_T_3 ? 4'h0 : _information_T_568; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_572 = _information_T_139 ? 3'h5 : 3'h0; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_573 = _information_T_137 ? 3'h4 : _information_T_572; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_574 = _information_T_135 ? 3'h3 : _information_T_573; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_575 = _information_T_133 ? 3'h2 : _information_T_574; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_576 = _information_T_131 ? 3'h1 : _information_T_575; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_577 = _information_T_129 ? 3'h3 : _information_T_576; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_578 = _information_T_127 ? 3'h2 : _information_T_577; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_579 = _information_T_125 ? 3'h1 : _information_T_578; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_580 = _information_T_123 ? 3'h0 : _information_T_579; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_581 = _information_T_121 ? 3'h0 : _information_T_580; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_582 = _information_T_119 ? 3'h0 : _information_T_581; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_583 = _information_T_117 ? 3'h0 : _information_T_582; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_584 = _information_T_115 ? 3'h0 : _information_T_583; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_585 = _information_T_113 ? 3'h0 : _information_T_584; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_586 = _information_T_111 ? 3'h0 : _information_T_585; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_587 = _information_T_109 ? 3'h0 : _information_T_586; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_588 = _information_T_107 ? 3'h0 : _information_T_587; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_589 = _information_T_105 ? 3'h0 : _information_T_588; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_590 = _information_T_103 ? 3'h0 : _information_T_589; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_591 = _information_T_101 ? 3'h0 : _information_T_590; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_592 = _information_T_99 ? 3'h0 : _information_T_591; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_593 = _information_T_97 ? 3'h0 : _information_T_592; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_594 = _information_T_95 ? 3'h0 : _information_T_593; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_595 = _information_T_93 ? 3'h0 : _information_T_594; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_596 = _information_T_91 ? 3'h0 : _information_T_595; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_597 = _information_T_89 ? 3'h0 : _information_T_596; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_598 = _information_T_87 ? 3'h0 : _information_T_597; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_599 = _information_T_85 ? 3'h0 : _information_T_598; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_600 = _information_T_83 ? 3'h0 : _information_T_599; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_601 = _information_T_81 ? 3'h0 : _information_T_600; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_602 = _information_T_79 ? 3'h0 : _information_T_601; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_603 = _information_T_77 ? 3'h0 : _information_T_602; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_604 = _information_T_75 ? 3'h0 : _information_T_603; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_605 = _information_T_73 ? 3'h0 : _information_T_604; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_606 = _information_T_71 ? 3'h0 : _information_T_605; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_607 = _information_T_69 ? 3'h0 : _information_T_606; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_608 = _information_T_67 ? 3'h0 : _information_T_607; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_609 = _information_T_65 ? 3'h0 : _information_T_608; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_610 = _information_T_63 ? 3'h0 : _information_T_609; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_611 = _information_T_61 ? 3'h0 : _information_T_610; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_612 = _information_T_59 ? 3'h0 : _information_T_611; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_613 = _information_T_57 ? 3'h0 : _information_T_612; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_614 = _information_T_55 ? 3'h0 : _information_T_613; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_615 = _information_T_53 ? 3'h0 : _information_T_614; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_616 = _information_T_51 ? 3'h0 : _information_T_615; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_617 = _information_T_49 ? 3'h0 : _information_T_616; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_618 = _information_T_47 ? 3'h0 : _information_T_617; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_619 = _information_T_45 ? 3'h0 : _information_T_618; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_620 = _information_T_43 ? 3'h0 : _information_T_619; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_621 = _information_T_41 ? 3'h0 : _information_T_620; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_622 = _information_T_39 ? 3'h0 : _information_T_621; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_623 = _information_T_37 ? 3'h0 : _information_T_622; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_624 = _information_T_35 ? 3'h0 : _information_T_623; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_625 = _information_T_33 ? 3'h0 : _information_T_624; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_626 = _information_T_31 ? 3'h0 : _information_T_625; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_627 = _information_T_29 ? 3'h0 : _information_T_626; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_628 = _information_T_27 ? 3'h0 : _information_T_627; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_629 = _information_T_25 ? 3'h0 : _information_T_628; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_630 = _information_T_23 ? 3'h0 : _information_T_629; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_631 = _information_T_21 ? 3'h0 : _information_T_630; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_632 = _information_T_19 ? 3'h0 : _information_T_631; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_633 = _information_T_17 ? 3'h0 : _information_T_632; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_634 = _information_T_15 ? 3'h0 : _information_T_633; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_635 = _information_T_13 ? 3'h0 : _information_T_634; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_636 = _information_T_11 ? 3'h0 : _information_T_635; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_637 = _information_T_9 ? 3'h0 : _information_T_636; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_638 = _information_T_7 ? 3'h0 : _information_T_637; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_639 = _information_T_5 ? 3'h0 : _information_T_638; // @[Lookup.scala 33:37]
  wire [2:0] _information_T_640 = _information_T_3 ? 3'h0 : _information_T_639; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_645 = _information_T_135 ? 2'h3 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_646 = _information_T_133 ? 2'h3 : _information_T_645; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_647 = _information_T_131 ? 2'h3 : _information_T_646; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_648 = _information_T_129 ? 2'h2 : _information_T_647; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_649 = _information_T_127 ? 2'h2 : _information_T_648; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_650 = _information_T_125 ? 2'h2 : _information_T_649; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_651 = _information_T_123 ? 2'h2 : _information_T_650; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_652 = _information_T_121 ? 2'h2 : _information_T_651; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_653 = _information_T_119 ? 2'h2 : _information_T_652; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_654 = _information_T_117 ? 2'h2 : _information_T_653; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_655 = _information_T_115 ? 2'h2 : _information_T_654; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_656 = _information_T_113 ? 2'h2 : _information_T_655; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_657 = _information_T_111 ? 2'h2 : _information_T_656; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_658 = _information_T_109 ? 2'h2 : _information_T_657; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_659 = _information_T_107 ? 2'h2 : _information_T_658; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_660 = _information_T_105 ? 2'h2 : _information_T_659; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_661 = _information_T_103 ? 2'h2 : _information_T_660; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_662 = _information_T_101 ? 2'h2 : _information_T_661; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_663 = _information_T_99 ? 2'h2 : _information_T_662; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_664 = _information_T_97 ? 2'h2 : _information_T_663; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_665 = _information_T_95 ? 2'h2 : _information_T_664; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_666 = _information_T_93 ? 2'h2 : _information_T_665; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_667 = _information_T_91 ? 2'h2 : _information_T_666; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_668 = _information_T_89 ? 2'h2 : _information_T_667; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_669 = _information_T_87 ? 2'h2 : _information_T_668; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_670 = _information_T_85 ? 2'h2 : _information_T_669; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_671 = _information_T_83 ? 2'h2 : _information_T_670; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_672 = _information_T_81 ? 2'h2 : _information_T_671; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_673 = _information_T_79 ? 2'h2 : _information_T_672; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_674 = _information_T_77 ? 2'h2 : _information_T_673; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_675 = _information_T_75 ? 2'h2 : _information_T_674; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_676 = _information_T_73 ? 2'h2 : _information_T_675; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_677 = _information_T_71 ? 2'h2 : _information_T_676; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_678 = _information_T_69 ? 2'h2 : _information_T_677; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_679 = _information_T_67 ? 2'h2 : _information_T_678; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_680 = _information_T_65 ? 2'h2 : _information_T_679; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_681 = _information_T_63 ? 2'h2 : _information_T_680; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_682 = _information_T_61 ? 2'h2 : _information_T_681; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_683 = _information_T_59 ? 2'h2 : _information_T_682; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_684 = _information_T_57 ? 2'h2 : _information_T_683; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_685 = _information_T_55 ? 2'h2 : _information_T_684; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_686 = _information_T_53 ? 2'h2 : _information_T_685; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_687 = _information_T_51 ? 2'h2 : _information_T_686; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_688 = _information_T_49 ? 2'h2 : _information_T_687; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_689 = _information_T_47 ? 2'h2 : _information_T_688; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_690 = _information_T_45 ? 2'h2 : _information_T_689; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_691 = _information_T_43 ? 2'h2 : _information_T_690; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_692 = _information_T_41 ? 2'h2 : _information_T_691; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_693 = _information_T_39 ? 2'h2 : _information_T_692; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_694 = _information_T_37 ? 2'h2 : _information_T_693; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_695 = _information_T_35 ? 2'h2 : _information_T_694; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_696 = _information_T_33 ? 2'h2 : _information_T_695; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_697 = _information_T_31 ? 2'h2 : _information_T_696; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_698 = _information_T_29 ? 2'h2 : _information_T_697; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_699 = _information_T_27 ? 2'h2 : _information_T_698; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_700 = _information_T_25 ? 2'h2 : _information_T_699; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_701 = _information_T_23 ? 2'h2 : _information_T_700; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_702 = _information_T_21 ? 2'h2 : _information_T_701; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_703 = _information_T_19 ? 2'h2 : _information_T_702; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_704 = _information_T_17 ? 2'h2 : _information_T_703; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_705 = _information_T_15 ? 2'h2 : _information_T_704; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_706 = _information_T_13 ? 2'h2 : _information_T_705; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_707 = _information_T_11 ? 2'h2 : _information_T_706; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_708 = _information_T_9 ? 2'h2 : _information_T_707; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_709 = _information_T_7 ? 2'h2 : _information_T_708; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_710 = _information_T_5 ? 2'h1 : _information_T_709; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_711 = _information_T_3 ? 2'h1 : _information_T_710; // @[Lookup.scala 33:37]
  wire [1:0] information_7 = _information_T_1 ? 2'h0 : _information_T_711; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_722 = _information_T_123 ? 2'h2 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_723 = _information_T_121 ? 2'h2 : _information_T_722; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_724 = _information_T_119 ? 2'h2 : _information_T_723; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_725 = _information_T_117 ? 2'h2 : _information_T_724; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_726 = _information_T_115 ? 2'h2 : _information_T_725; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_727 = _information_T_113 ? 2'h2 : _information_T_726; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_728 = _information_T_111 ? 2'h2 : _information_T_727; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_729 = _information_T_109 ? 2'h2 : _information_T_728; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_730 = _information_T_107 ? 2'h2 : _information_T_729; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_731 = _information_T_105 ? 2'h2 : _information_T_730; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_732 = _information_T_103 ? 2'h2 : _information_T_731; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_733 = _information_T_101 ? 2'h2 : _information_T_732; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_734 = _information_T_99 ? 2'h2 : _information_T_733; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_735 = _information_T_97 ? 2'h3 : _information_T_734; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_736 = _information_T_95 ? 2'h3 : _information_T_735; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_737 = _information_T_93 ? 2'h3 : _information_T_736; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_738 = _information_T_91 ? 2'h2 : _information_T_737; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_739 = _information_T_89 ? 2'h2 : _information_T_738; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_740 = _information_T_87 ? 2'h2 : _information_T_739; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_741 = _information_T_85 ? 2'h2 : _information_T_740; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_742 = _information_T_83 ? 2'h2 : _information_T_741; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_743 = _information_T_81 ? 2'h3 : _information_T_742; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_744 = _information_T_79 ? 2'h3 : _information_T_743; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_745 = _information_T_77 ? 2'h3 : _information_T_744; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_746 = _information_T_75 ? 2'h3 : _information_T_745; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_747 = _information_T_73 ? 2'h2 : _information_T_746; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_748 = _information_T_71 ? 2'h2 : _information_T_747; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_749 = _information_T_69 ? 2'h2 : _information_T_748; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_750 = _information_T_67 ? 2'h2 : _information_T_749; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_751 = _information_T_65 ? 2'h2 : _information_T_750; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_752 = _information_T_63 ? 2'h2 : _information_T_751; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_753 = _information_T_61 ? 2'h2 : _information_T_752; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_754 = _information_T_59 ? 2'h2 : _information_T_753; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_755 = _information_T_57 ? 2'h2 : _information_T_754; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_756 = _information_T_55 ? 2'h2 : _information_T_755; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_757 = _information_T_53 ? 2'h3 : _information_T_756; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_758 = _information_T_51 ? 2'h3 : _information_T_757; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_759 = _information_T_49 ? 2'h3 : _information_T_758; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_760 = _information_T_47 ? 2'h3 : _information_T_759; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_761 = _information_T_45 ? 2'h3 : _information_T_760; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_762 = _information_T_43 ? 2'h3 : _information_T_761; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_763 = _information_T_41 ? 2'h3 : _information_T_762; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_764 = _information_T_39 ? 2'h3 : _information_T_763; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_765 = _information_T_37 ? 2'h3 : _information_T_764; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_766 = _information_T_35 ? 2'h3 : _information_T_765; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_767 = _information_T_33 ? 2'h3 : _information_T_766; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_768 = _information_T_31 ? 2'h3 : _information_T_767; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_769 = _information_T_29 ? 2'h3 : _information_T_768; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_770 = _information_T_27 ? 2'h3 : _information_T_769; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_771 = _information_T_25 ? 2'h3 : _information_T_770; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_772 = _information_T_23 ? 2'h3 : _information_T_771; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_773 = _information_T_21 ? 2'h3 : _information_T_772; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_774 = _information_T_19 ? 2'h2 : _information_T_773; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_775 = _information_T_17 ? 2'h2 : _information_T_774; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_776 = _information_T_15 ? 2'h2 : _information_T_775; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_777 = _information_T_13 ? 2'h2 : _information_T_776; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_778 = _information_T_11 ? 2'h2 : _information_T_777; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_779 = _information_T_9 ? 2'h2 : _information_T_778; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_780 = _information_T_7 ? 2'h3 : _information_T_779; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_781 = _information_T_5 ? 2'h3 : _information_T_780; // @[Lookup.scala 33:37]
  wire [1:0] _information_T_782 = _information_T_3 ? 2'h3 : _information_T_781; // @[Lookup.scala 33:37]
  wire [1:0] information_8 = _information_T_1 ? 2'h3 : _information_T_782; // @[Lookup.scala 33:37]
  wire  _information_T_806 = _information_T_97 ? 1'h0 : _information_T_99 | (_information_T_101 | (_information_T_103 |
    (_information_T_105 | (_information_T_107 | (_information_T_109 | (_information_T_111 | (_information_T_113 | (
    _information_T_115 | (_information_T_117 | (_information_T_119 | (_information_T_121 | (_information_T_123 | (
    _information_T_125 | (_information_T_127 | (_information_T_129 | (_information_T_131 | (_information_T_133 |
    _information_T_135))))))))))))))))); // @[Lookup.scala 33:37]
  wire  _information_T_836 = _information_T_37 | (_information_T_39 | (_information_T_41 | (_information_T_43 | (
    _information_T_45 | (_information_T_47 | (_information_T_49 | (_information_T_51 | (_information_T_53 | (
    _information_T_55 | (_information_T_57 | (_information_T_59 | (_information_T_61 | (_information_T_63 | (
    _information_T_65 | (_information_T_67 | (_information_T_69 | (_information_T_71 | (_information_T_73 | (
    _information_T_75 | (_information_T_77 | (_information_T_79 | (_information_T_81 | (_information_T_83 | (
    _information_T_85 | (_information_T_87 | (_information_T_89 | (_information_T_91 | (_information_T_93 | (
    _information_T_95 | _information_T_806))))))))))))))))))))))))))))); // @[Lookup.scala 33:37]
  wire  _information_T_837 = _information_T_35 ? 1'h0 : _information_T_836; // @[Lookup.scala 33:37]
  wire  _information_T_838 = _information_T_33 ? 1'h0 : _information_T_837; // @[Lookup.scala 33:37]
  wire  _information_T_839 = _information_T_31 ? 1'h0 : _information_T_838; // @[Lookup.scala 33:37]
  wire  _information_T_845 = _information_T_19 ? 1'h0 : _information_T_21 | (_information_T_23 | (_information_T_25 | (
    _information_T_27 | (_information_T_29 | _information_T_839)))); // @[Lookup.scala 33:37]
  wire  _information_T_846 = _information_T_17 ? 1'h0 : _information_T_845; // @[Lookup.scala 33:37]
  wire  _information_T_847 = _information_T_15 ? 1'h0 : _information_T_846; // @[Lookup.scala 33:37]
  wire  _information_T_848 = _information_T_13 ? 1'h0 : _information_T_847; // @[Lookup.scala 33:37]
  wire  _information_T_849 = _information_T_11 ? 1'h0 : _information_T_848; // @[Lookup.scala 33:37]
  wire  _information_T_850 = _information_T_9 ? 1'h0 : _information_T_849; // @[Lookup.scala 33:37]
  wire  _information_T_869 = _information_T_113 ? 1'h0 : _information_T_115 | (_information_T_117 | (_information_T_119
     | (_information_T_121 | _information_T_123))); // @[Lookup.scala 33:37]
  wire  _information_T_870 = _information_T_111 ? 1'h0 : _information_T_869; // @[Lookup.scala 33:37]
  wire  _information_T_871 = _information_T_109 ? 1'h0 : _information_T_870; // @[Lookup.scala 33:37]
  wire  _information_T_872 = _information_T_107 ? 1'h0 : _information_T_871; // @[Lookup.scala 33:37]
  wire  _information_T_873 = _information_T_105 ? 1'h0 : _information_T_872; // @[Lookup.scala 33:37]
  wire  _information_T_874 = _information_T_103 ? 1'h0 : _information_T_873; // @[Lookup.scala 33:37]
  wire  _information_T_875 = _information_T_101 ? 1'h0 : _information_T_874; // @[Lookup.scala 33:37]
  wire  _information_T_876 = _information_T_99 ? 1'h0 : _information_T_875; // @[Lookup.scala 33:37]
  wire  _information_T_877 = _information_T_97 ? 1'h0 : _information_T_876; // @[Lookup.scala 33:37]
  wire  _information_T_878 = _information_T_95 ? 1'h0 : _information_T_877; // @[Lookup.scala 33:37]
  wire  _information_T_879 = _information_T_93 ? 1'h0 : _information_T_878; // @[Lookup.scala 33:37]
  wire  _information_T_889 = _information_T_73 ? 1'h0 : _information_T_75 | (_information_T_77 | (_information_T_79 | (
    _information_T_81 | (_information_T_83 | (_information_T_85 | (_information_T_87 | (_information_T_89 | (
    _information_T_91 | _information_T_879)))))))); // @[Lookup.scala 33:37]
  wire  _information_T_890 = _information_T_71 ? 1'h0 : _information_T_889; // @[Lookup.scala 33:37]
  wire  _information_T_891 = _information_T_69 ? 1'h0 : _information_T_890; // @[Lookup.scala 33:37]
  wire  _information_T_892 = _information_T_67 ? 1'h0 : _information_T_891; // @[Lookup.scala 33:37]
  wire  _information_T_893 = _information_T_65 ? 1'h0 : _information_T_892; // @[Lookup.scala 33:37]
  wire  _information_T_894 = _information_T_63 ? 1'h0 : _information_T_893; // @[Lookup.scala 33:37]
  wire  _information_T_895 = _information_T_61 ? 1'h0 : _information_T_894; // @[Lookup.scala 33:37]
  wire  _information_T_896 = _information_T_59 ? 1'h0 : _information_T_895; // @[Lookup.scala 33:37]
  wire  _information_T_897 = _information_T_57 ? 1'h0 : _information_T_896; // @[Lookup.scala 33:37]
  wire  _information_T_898 = _information_T_55 ? 1'h0 : _information_T_897; // @[Lookup.scala 33:37]
  wire  _information_T_899 = _information_T_53 ? 1'h0 : _information_T_898; // @[Lookup.scala 33:37]
  wire  _information_T_900 = _information_T_51 ? 1'h0 : _information_T_899; // @[Lookup.scala 33:37]
  wire  _information_T_901 = _information_T_49 ? 1'h0 : _information_T_900; // @[Lookup.scala 33:37]
  wire  _information_T_902 = _information_T_47 ? 1'h0 : _information_T_901; // @[Lookup.scala 33:37]
  wire  _information_T_903 = _information_T_45 ? 1'h0 : _information_T_902; // @[Lookup.scala 33:37]
  wire  _information_T_904 = _information_T_43 ? 1'h0 : _information_T_903; // @[Lookup.scala 33:37]
  wire  _information_T_905 = _information_T_41 ? 1'h0 : _information_T_904; // @[Lookup.scala 33:37]
  wire  _information_T_906 = _information_T_39 ? 1'h0 : _information_T_905; // @[Lookup.scala 33:37]
  wire  _information_T_907 = _information_T_37 ? 1'h0 : _information_T_906; // @[Lookup.scala 33:37]
  wire  _information_T_908 = _information_T_35 ? 1'h0 : _information_T_907; // @[Lookup.scala 33:37]
  wire  _information_T_909 = _information_T_33 ? 1'h0 : _information_T_908; // @[Lookup.scala 33:37]
  wire  _information_T_910 = _information_T_31 ? 1'h0 : _information_T_909; // @[Lookup.scala 33:37]
  wire  _information_T_911 = _information_T_29 ? 1'h0 : _information_T_910; // @[Lookup.scala 33:37]
  wire  _information_T_912 = _information_T_27 ? 1'h0 : _information_T_911; // @[Lookup.scala 33:37]
  wire  _information_T_913 = _information_T_25 ? 1'h0 : _information_T_912; // @[Lookup.scala 33:37]
  wire  _information_T_914 = _information_T_23 ? 1'h0 : _information_T_913; // @[Lookup.scala 33:37]
  wire  _information_T_915 = _information_T_21 ? 1'h0 : _information_T_914; // @[Lookup.scala 33:37]
  wire  _information_T_916 = _information_T_19 ? 1'h0 : _information_T_915; // @[Lookup.scala 33:37]
  wire  _information_T_917 = _information_T_17 ? 1'h0 : _information_T_916; // @[Lookup.scala 33:37]
  wire  _information_T_918 = _information_T_15 ? 1'h0 : _information_T_917; // @[Lookup.scala 33:37]
  wire  _information_T_919 = _information_T_13 ? 1'h0 : _information_T_918; // @[Lookup.scala 33:37]
  wire  _information_T_920 = _information_T_11 ? 1'h0 : _information_T_919; // @[Lookup.scala 33:37]
  wire  _information_T_921 = _information_T_9 ? 1'h0 : _information_T_920; // @[Lookup.scala 33:37]
  wire  _information_T_922 = _information_T_7 ? 1'h0 : _information_T_921; // @[Lookup.scala 33:37]
  wire  _information_T_923 = _information_T_5 ? 1'h0 : _information_T_922; // @[Lookup.scala 33:37]
  wire  _information_T_924 = _information_T_3 ? 1'h0 : _information_T_923; // @[Lookup.scala 33:37]
  wire [4:0] rs1 = io_in_bits_inst[19:15]; // @[IDU.scala 130:14]
  wire [4:0] rs2 = io_in_bits_inst[24:20]; // @[IDU.scala 131:14]
  wire [63:0] _imm_T_1 = 3'h1 == information_1 ? imm_i : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _imm_T_3 = 3'h2 == information_1 ? imm_s : _imm_T_1; // @[Mux.scala 80:57]
  wire [63:0] _imm_T_5 = 3'h3 == information_1 ? imm_b : _imm_T_3; // @[Mux.scala 80:57]
  wire [63:0] _imm_T_7 = 3'h4 == information_1 ? imm_u : _imm_T_5; // @[Mux.scala 80:57]
  wire [63:0] imm = 3'h5 == information_1 ? imm_j : _imm_T_7; // @[Mux.scala 80:57]
  wire [63:0] _src1_value_T = {59'h0,rs1}; // @[Cat.scala 30:58]
  wire [31:0] _src1_value_T_2 = 2'h1 == information_7 ? io_in_bits_pc : 32'h0; // @[Mux.scala 80:57]
  wire [63:0] _rs1_value_T_4 = io_wb_bus_rf_wen & io_wb_bus_rf_waddr == rs1 ? io_wb_bus_rf_wdata : rf__rdata1; // @[IDU.scala 177:19]
  wire [63:0] rs1_value = io_ex_fwd_fwd_valid & io_ex_fwd_rf_waddr == rs1 ? io_ex_fwd_rf_wdata : _rs1_value_T_4; // @[IDU.scala 176:19]
  wire [63:0] _src1_value_T_4 = 2'h2 == information_7 ? rs1_value : {{32'd0}, _src1_value_T_2}; // @[Mux.scala 80:57]
  wire [63:0] _rs2_value_T_4 = io_wb_bus_rf_wen & io_wb_bus_rf_waddr == rs2 ? io_wb_bus_rf_wdata : rf__rdata2; // @[IDU.scala 179:19]
  wire [63:0] rs2_value = io_ex_fwd_fwd_valid & io_ex_fwd_rf_waddr == rs2 ? io_ex_fwd_rf_wdata : _rs2_value_T_4; // @[IDU.scala 178:19]
  wire [63:0] _src2_value_T_1 = 2'h2 == information_8 ? rs2_value : 64'h0; // @[Mux.scala 80:57]
  BRU bru ( // @[IDU.scala 152:19]
    .io_bru_op(bru_io_bru_op),
    .io_src1(bru_io_src1),
    .io_src2(bru_io_src2),
    .io_pc(bru_io_pc),
    .io_imm(bru_io_imm),
    .io_br_taken(bru_io_br_taken),
    .io_br_target(bru_io_br_target)
  );
  RegFile rf_ ( // @[IDU.scala 162:18]
    .clock(rf__clock),
    .raddr1(rf__raddr1),
    .raddr2(rf__raddr2),
    .rdata1(rf__rdata1),
    .rdata2(rf__rdata2),
    .waddr(rf__waddr),
    .wdata(rf__wdata),
    .wen(rf__wen)
  );
  assign io_out_valid = io_in_valid; // @[IDU.scala 193:16]
  assign io_out_bits_pc = io_in_bits_pc; // @[IDU.scala 181:18]
  assign io_out_bits_inst = io_in_bits_inst; // @[IDU.scala 182:20]
  assign io_out_bits_src1_value = 2'h3 == information_7 ? _src1_value_T : _src1_value_T_4; // @[Mux.scala 80:57]
  assign io_out_bits_src2_value = 2'h3 == information_8 ? imm : _src2_value_T_1; // @[Mux.scala 80:57]
  assign io_out_bits_rs2_value = io_ex_fwd_fwd_valid & io_ex_fwd_rf_waddr == rs2 ? io_ex_fwd_rf_wdata : _rs2_value_T_4; // @[IDU.scala 178:19]
  assign io_out_bits_dest = io_in_bits_inst[11:7]; // @[IDU.scala 132:15]
  assign io_out_bits_fu_type = _information_T_1 ? 2'h0 : _information_T_356; // @[Lookup.scala 33:37]
  assign io_out_bits_alu_op = _information_T_1 ? 5'h1 : _information_T_427; // @[Lookup.scala 33:37]
  assign io_out_bits_lsu_op = _information_T_1 ? 4'h0 : _information_T_569; // @[Lookup.scala 33:37]
  assign io_out_bits_csr_op = _information_T_1 ? 3'h0 : _information_T_640; // @[Lookup.scala 33:37]
  assign io_out_bits_wen = _information_T_1 | (_information_T_3 | (_information_T_5 | (_information_T_7 |
    _information_T_850))); // @[Lookup.scala 33:37]
  assign io_out_bits_rv64 = _information_T_1 ? 1'h0 : _information_T_924; // @[Lookup.scala 33:37]
  assign io_br_bus_br_taken = bru_io_br_taken & io_in_valid; // @[IDU.scala 153:41]
  assign io_br_bus_br_target = bru_io_br_target; // @[IDU.scala 154:23]
  assign bru_io_bru_op = _information_T_1 ? 4'h0 : _information_T_498; // @[Lookup.scala 33:37]
  assign bru_io_src1 = 2'h3 == information_7 ? _src1_value_T : _src1_value_T_4; // @[Mux.scala 80:57]
  assign bru_io_src2 = 2'h3 == information_8 ? imm : _src2_value_T_1; // @[Mux.scala 80:57]
  assign bru_io_pc = io_in_bits_pc; // @[IDU.scala 159:13]
  assign bru_io_imm = 3'h5 == information_1 ? imm_j : _imm_T_7; // @[Mux.scala 80:57]
  assign rf__clock = clock; // @[IDU.scala 163:15]
  assign rf__raddr1 = io_in_bits_inst[19:15]; // @[IDU.scala 130:14]
  assign rf__raddr2 = io_in_bits_inst[24:20]; // @[IDU.scala 131:14]
  assign rf__waddr = io_wb_bus_rf_waddr; // @[IDU.scala 33:22 IDU.scala 172:12]
  assign rf__wdata = io_wb_bus_rf_wdata; // @[IDU.scala 34:22 IDU.scala 173:12]
  assign rf__wen = io_wb_bus_rf_wen; // @[IDU.scala 32:20 IDU.scala 174:10]
endmodule
module ALU(
  input  [4:0]  io_alu_op,
  input         io_rv64,
  input  [63:0] io_src1,
  input  [63:0] io_src2,
  output [63:0] io_result
);
  wire  srl = io_alu_op == 5'h9 & io_rv64; // @[ALU.scala 19:31]
  wire  sra = io_alu_op == 5'ha & io_rv64; // @[ALU.scala 20:31]
  wire [31:0] src1_lo = io_src1[31:0]; // @[ALU.scala 23:38]
  wire [63:0] _src1_T = {32'h0,src1_lo}; // @[Cat.scala 30:58]
  wire [31:0] src1_hi_1 = io_src1[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _src1_T_3 = {src1_hi_1,src1_lo}; // @[Cat.scala 30:58]
  wire [63:0] _src1_T_4 = sra ? _src1_T_3 : io_src1; // @[Mux.scala 98:16]
  wire [63:0] src1 = srl ? _src1_T : _src1_T_4; // @[Mux.scala 98:16]
  wire [5:0] shamt = io_rv64 ? {{1'd0}, io_src2[4:0]} : io_src2[5:0]; // @[ALU.scala 28:18]
  wire [63:0] _tmp_result_T_1 = src1 + io_src2; // @[ALU.scala 32:26]
  wire [63:0] _tmp_result_T_3 = src1 - io_src2; // @[ALU.scala 33:26]
  wire [63:0] _tmp_result_T_4 = src1 & io_src2; // @[ALU.scala 34:26]
  wire [63:0] _tmp_result_T_5 = src1 | io_src2; // @[ALU.scala 35:26]
  wire [63:0] _tmp_result_T_6 = src1 ^ io_src2; // @[ALU.scala 36:26]
  wire [63:0] _tmp_result_T_7 = srl ? _src1_T : _src1_T_4; // @[ALU.scala 37:26]
  wire  _tmp_result_T_9 = $signed(_tmp_result_T_7) < $signed(io_src2); // @[ALU.scala 37:33]
  wire  _tmp_result_T_10 = src1 < io_src2; // @[ALU.scala 38:26]
  wire [126:0] _GEN_0 = {{63'd0}, src1}; // @[ALU.scala 39:26]
  wire [126:0] _tmp_result_T_11 = _GEN_0 << shamt; // @[ALU.scala 39:26]
  wire [63:0] _tmp_result_T_12 = src1 >> shamt; // @[ALU.scala 40:26]
  wire [63:0] _tmp_result_T_15 = $signed(_tmp_result_T_7) >>> shamt; // @[ALU.scala 41:43]
  wire [127:0] _tmp_result_T_16 = src1 * io_src2; // @[ALU.scala 42:26]
  wire [127:0] _tmp_result_T_19 = $signed(_tmp_result_T_7) * $signed(io_src2); // @[ALU.scala 43:33]
  wire [63:0] _tmp_result_T_21 = _tmp_result_T_19[127:64]; // @[ALU.scala 43:54]
  wire [64:0] _tmp_result_T_23 = {1'b0,$signed(io_src2)}; // @[ALU.scala 44:33]
  wire [128:0] _tmp_result_T_24 = $signed(_tmp_result_T_7) * $signed(_tmp_result_T_23); // @[ALU.scala 44:33]
  wire [127:0] _tmp_result_T_26 = _tmp_result_T_24[127:0]; // @[ALU.scala 44:33]
  wire [63:0] _tmp_result_T_28 = _tmp_result_T_26[127:64]; // @[ALU.scala 44:54]
  wire [64:0] _tmp_result_T_34 = $signed(_tmp_result_T_7) / $signed(io_src2); // @[ALU.scala 46:48]
  wire [63:0] _tmp_result_T_35 = src1 / io_src2; // @[ALU.scala 47:33]
  wire [63:0] _tmp_result_T_39 = $signed(_tmp_result_T_7) % $signed(io_src2); // @[ALU.scala 48:48]
  wire [63:0] _GEN_1 = src1 % io_src2; // @[ALU.scala 49:33]
  wire [63:0] _tmp_result_T_40 = _GEN_1[63:0]; // @[ALU.scala 49:33]
  wire [63:0] _tmp_result_T_42 = 5'h1 == io_alu_op ? _tmp_result_T_1 : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _tmp_result_T_44 = 5'h2 == io_alu_op ? _tmp_result_T_3 : _tmp_result_T_42; // @[Mux.scala 80:57]
  wire [63:0] _tmp_result_T_46 = 5'h3 == io_alu_op ? _tmp_result_T_4 : _tmp_result_T_44; // @[Mux.scala 80:57]
  wire [63:0] _tmp_result_T_48 = 5'h4 == io_alu_op ? _tmp_result_T_5 : _tmp_result_T_46; // @[Mux.scala 80:57]
  wire [63:0] _tmp_result_T_50 = 5'h5 == io_alu_op ? _tmp_result_T_6 : _tmp_result_T_48; // @[Mux.scala 80:57]
  wire [63:0] _tmp_result_T_52 = 5'h6 == io_alu_op ? {{63'd0}, _tmp_result_T_9} : _tmp_result_T_50; // @[Mux.scala 80:57]
  wire [63:0] _tmp_result_T_54 = 5'h7 == io_alu_op ? {{63'd0}, _tmp_result_T_10} : _tmp_result_T_52; // @[Mux.scala 80:57]
  wire [126:0] _tmp_result_T_56 = 5'h8 == io_alu_op ? _tmp_result_T_11 : {{63'd0}, _tmp_result_T_54}; // @[Mux.scala 80:57]
  wire [126:0] _tmp_result_T_58 = 5'h9 == io_alu_op ? {{63'd0}, _tmp_result_T_12} : _tmp_result_T_56; // @[Mux.scala 80:57]
  wire [126:0] _tmp_result_T_60 = 5'ha == io_alu_op ? {{63'd0}, _tmp_result_T_15} : _tmp_result_T_58; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_62 = 5'hb == io_alu_op ? _tmp_result_T_16 : {{1'd0}, _tmp_result_T_60}; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_64 = 5'hc == io_alu_op ? {{64'd0}, _tmp_result_T_21} : _tmp_result_T_62; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_66 = 5'hd == io_alu_op ? {{64'd0}, _tmp_result_T_28} : _tmp_result_T_64; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_68 = 5'he == io_alu_op ? {{64'd0}, _tmp_result_T_16[127:64]} : _tmp_result_T_66; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_70 = 5'hf == io_alu_op ? {{63'd0}, _tmp_result_T_34} : _tmp_result_T_68; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_72 = 5'h10 == io_alu_op ? {{64'd0}, _tmp_result_T_35} : _tmp_result_T_70; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_74 = 5'h11 == io_alu_op ? {{64'd0}, _tmp_result_T_39} : _tmp_result_T_72; // @[Mux.scala 80:57]
  wire [127:0] _tmp_result_T_76 = 5'h12 == io_alu_op ? {{64'd0}, _tmp_result_T_40} : _tmp_result_T_74; // @[Mux.scala 80:57]
  wire [63:0] tmp_result = _tmp_result_T_76[63:0]; // @[ALU.scala 29:24 ALU.scala 31:14]
  wire [31:0] io_result_hi = tmp_result[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [31:0] io_result_lo = tmp_result[31:0]; // @[ALU.scala 52:66]
  wire [63:0] _io_result_T_2 = {io_result_hi,io_result_lo}; // @[Cat.scala 30:58]
  assign io_result = io_rv64 ? _io_result_T_2 : tmp_result; // @[ALU.scala 52:19]
endmodule
module LSU(
  output        io_dmem_en,
  output [63:0] io_dmem_addr,
  input  [63:0] io_dmem_rdata,
  output [63:0] io_dmem_wdata,
  output [63:0] io_dmem_wmask,
  output        io_dmem_wen,
  input  [63:0] io_src1,
  input  [63:0] io_src2,
  input  [63:0] io_wdata,
  input         io_is_lsu,
  input         io_wen,
  input  [3:0]  io_lsu_op,
  output [63:0] io_rdata
);
  wire [63:0] dmem_addr = io_src1 + io_src2; // @[LSU.scala 23:24]
  wire [2:0] addr_low = dmem_addr[2:0]; // @[LSU.scala 24:24]
  wire [7:0] sb_wdata_hi = io_wdata[7:0]; // @[LSU.scala 48:28]
  wire [63:0] sb_wdata = {sb_wdata_hi,sb_wdata_hi,sb_wdata_hi,sb_wdata_hi,sb_wdata_hi,sb_wdata_hi,sb_wdata_hi,
    sb_wdata_hi}; // @[Cat.scala 30:58]
  wire [15:0] sh_wdata_hi = io_wdata[15:0]; // @[LSU.scala 49:28]
  wire [63:0] sh_wdata = {sh_wdata_hi,sh_wdata_hi,sh_wdata_hi,sh_wdata_hi}; // @[Cat.scala 30:58]
  wire [31:0] sw_wdata_hi = io_wdata[31:0]; // @[LSU.scala 50:28]
  wire [63:0] sw_wdata = {sw_wdata_hi,sw_wdata_hi}; // @[Cat.scala 30:58]
  wire [63:0] _dmem_wdata_T_1 = 4'h6 == io_lsu_op ? sb_wdata : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _dmem_wdata_T_3 = 4'h7 == io_lsu_op ? sh_wdata : _dmem_wdata_T_1; // @[Mux.scala 80:57]
  wire [63:0] _dmem_wdata_T_5 = 4'h8 == io_lsu_op ? sw_wdata : _dmem_wdata_T_3; // @[Mux.scala 80:57]
  wire [15:0] _sb_wmask_T_1 = 3'h1 == addr_low ? 16'hff00 : 16'hff; // @[Mux.scala 80:57]
  wire [23:0] _sb_wmask_T_3 = 3'h2 == addr_low ? 24'hff0000 : {{8'd0}, _sb_wmask_T_1}; // @[Mux.scala 80:57]
  wire [31:0] _sb_wmask_T_5 = 3'h3 == addr_low ? 32'hff000000 : {{8'd0}, _sb_wmask_T_3}; // @[Mux.scala 80:57]
  wire [39:0] _sb_wmask_T_7 = 3'h4 == addr_low ? 40'hff00000000 : {{8'd0}, _sb_wmask_T_5}; // @[Mux.scala 80:57]
  wire [47:0] _sb_wmask_T_9 = 3'h5 == addr_low ? 48'hff0000000000 : {{8'd0}, _sb_wmask_T_7}; // @[Mux.scala 80:57]
  wire [55:0] _sb_wmask_T_11 = 3'h6 == addr_low ? 56'hff000000000000 : {{8'd0}, _sb_wmask_T_9}; // @[Mux.scala 80:57]
  wire [63:0] sb_wmask = 3'h7 == addr_low ? 64'hff00000000000000 : {{8'd0}, _sb_wmask_T_11}; // @[Mux.scala 80:57]
  wire [15:0] _sh_wmask_T_1 = 3'h0 == addr_low ? 16'hffff : 16'h0; // @[Mux.scala 80:57]
  wire [31:0] _sh_wmask_T_3 = 3'h2 == addr_low ? 32'hffff0000 : {{16'd0}, _sh_wmask_T_1}; // @[Mux.scala 80:57]
  wire [47:0] _sh_wmask_T_5 = 3'h4 == addr_low ? 48'hffff00000000 : {{16'd0}, _sh_wmask_T_3}; // @[Mux.scala 80:57]
  wire [63:0] sh_wmask = 3'h6 == addr_low ? 64'hffff000000000000 : {{16'd0}, _sh_wmask_T_5}; // @[Mux.scala 80:57]
  wire [31:0] _sw_wmask_T_1 = 3'h0 == addr_low ? 32'hffffffff : 32'h0; // @[Mux.scala 80:57]
  wire [63:0] sw_wmask = 3'h4 == addr_low ? 64'hffffffff00000000 : {{32'd0}, _sw_wmask_T_1}; // @[Mux.scala 80:57]
  wire [63:0] _dmem_wmask_T_1 = 4'h6 == io_lsu_op ? sb_wmask : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _dmem_wmask_T_3 = 4'h7 == io_lsu_op ? sh_wmask : _dmem_wmask_T_1; // @[Mux.scala 80:57]
  wire [63:0] _dmem_wmask_T_5 = 4'h8 == io_lsu_op ? sw_wmask : _dmem_wmask_T_3; // @[Mux.scala 80:57]
  wire [55:0] lb_rdata_hi = io_dmem_rdata[7] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [7:0] lb_rdata_lo = io_dmem_rdata[7:0]; // @[LSU.scala 88:51]
  wire [63:0] _lb_rdata_T_2 = {lb_rdata_hi,lb_rdata_lo}; // @[Cat.scala 30:58]
  wire [55:0] lb_rdata_hi_1 = io_dmem_rdata[15] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [7:0] lb_rdata_lo_1 = io_dmem_rdata[15:8]; // @[LSU.scala 89:52]
  wire [63:0] _lb_rdata_T_5 = {lb_rdata_hi_1,lb_rdata_lo_1}; // @[Cat.scala 30:58]
  wire [55:0] lb_rdata_hi_2 = io_dmem_rdata[23] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [7:0] lb_rdata_lo_2 = io_dmem_rdata[23:16]; // @[LSU.scala 90:52]
  wire [63:0] _lb_rdata_T_8 = {lb_rdata_hi_2,lb_rdata_lo_2}; // @[Cat.scala 30:58]
  wire [55:0] lb_rdata_hi_3 = io_dmem_rdata[31] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [7:0] lb_rdata_lo_3 = io_dmem_rdata[31:24]; // @[LSU.scala 91:52]
  wire [63:0] _lb_rdata_T_11 = {lb_rdata_hi_3,lb_rdata_lo_3}; // @[Cat.scala 30:58]
  wire [55:0] lb_rdata_hi_4 = io_dmem_rdata[39] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [7:0] lb_rdata_lo_4 = io_dmem_rdata[39:32]; // @[LSU.scala 92:52]
  wire [63:0] _lb_rdata_T_14 = {lb_rdata_hi_4,lb_rdata_lo_4}; // @[Cat.scala 30:58]
  wire [55:0] lb_rdata_hi_5 = io_dmem_rdata[47] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [7:0] lb_rdata_lo_5 = io_dmem_rdata[47:40]; // @[LSU.scala 93:52]
  wire [63:0] _lb_rdata_T_17 = {lb_rdata_hi_5,lb_rdata_lo_5}; // @[Cat.scala 30:58]
  wire [55:0] lb_rdata_hi_6 = io_dmem_rdata[55] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [7:0] lb_rdata_lo_6 = io_dmem_rdata[55:48]; // @[LSU.scala 94:52]
  wire [63:0] _lb_rdata_T_20 = {lb_rdata_hi_6,lb_rdata_lo_6}; // @[Cat.scala 30:58]
  wire [55:0] lb_rdata_hi_7 = io_dmem_rdata[63] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [7:0] lb_rdata_lo_7 = io_dmem_rdata[63:56]; // @[LSU.scala 95:52]
  wire [63:0] _lb_rdata_T_23 = {lb_rdata_hi_7,lb_rdata_lo_7}; // @[Cat.scala 30:58]
  wire [63:0] _lb_rdata_T_25 = 3'h1 == addr_low ? _lb_rdata_T_5 : _lb_rdata_T_2; // @[Mux.scala 80:57]
  wire [63:0] _lb_rdata_T_27 = 3'h2 == addr_low ? _lb_rdata_T_8 : _lb_rdata_T_25; // @[Mux.scala 80:57]
  wire [63:0] _lb_rdata_T_29 = 3'h3 == addr_low ? _lb_rdata_T_11 : _lb_rdata_T_27; // @[Mux.scala 80:57]
  wire [63:0] _lb_rdata_T_31 = 3'h4 == addr_low ? _lb_rdata_T_14 : _lb_rdata_T_29; // @[Mux.scala 80:57]
  wire [63:0] _lb_rdata_T_33 = 3'h5 == addr_low ? _lb_rdata_T_17 : _lb_rdata_T_31; // @[Mux.scala 80:57]
  wire [63:0] _lb_rdata_T_35 = 3'h6 == addr_low ? _lb_rdata_T_20 : _lb_rdata_T_33; // @[Mux.scala 80:57]
  wire [63:0] lb_rdata = 3'h7 == addr_low ? _lb_rdata_T_23 : _lb_rdata_T_35; // @[Mux.scala 80:57]
  wire [63:0] _lbu_rdata_T = {56'h0,lb_rdata_lo}; // @[Cat.scala 30:58]
  wire [63:0] _lbu_rdata_T_1 = {56'h0,lb_rdata_lo_1}; // @[Cat.scala 30:58]
  wire [63:0] _lbu_rdata_T_2 = {56'h0,lb_rdata_lo_2}; // @[Cat.scala 30:58]
  wire [63:0] _lbu_rdata_T_3 = {56'h0,lb_rdata_lo_3}; // @[Cat.scala 30:58]
  wire [63:0] _lbu_rdata_T_4 = {56'h0,lb_rdata_lo_4}; // @[Cat.scala 30:58]
  wire [63:0] _lbu_rdata_T_5 = {56'h0,lb_rdata_lo_5}; // @[Cat.scala 30:58]
  wire [63:0] _lbu_rdata_T_6 = {56'h0,lb_rdata_lo_6}; // @[Cat.scala 30:58]
  wire [63:0] _lbu_rdata_T_7 = {56'h0,lb_rdata_lo_7}; // @[Cat.scala 30:58]
  wire [63:0] _lbu_rdata_T_9 = 3'h1 == addr_low ? _lbu_rdata_T_1 : _lbu_rdata_T; // @[Mux.scala 80:57]
  wire [63:0] _lbu_rdata_T_11 = 3'h2 == addr_low ? _lbu_rdata_T_2 : _lbu_rdata_T_9; // @[Mux.scala 80:57]
  wire [63:0] _lbu_rdata_T_13 = 3'h3 == addr_low ? _lbu_rdata_T_3 : _lbu_rdata_T_11; // @[Mux.scala 80:57]
  wire [63:0] _lbu_rdata_T_15 = 3'h4 == addr_low ? _lbu_rdata_T_4 : _lbu_rdata_T_13; // @[Mux.scala 80:57]
  wire [63:0] _lbu_rdata_T_17 = 3'h5 == addr_low ? _lbu_rdata_T_5 : _lbu_rdata_T_15; // @[Mux.scala 80:57]
  wire [63:0] _lbu_rdata_T_19 = 3'h6 == addr_low ? _lbu_rdata_T_6 : _lbu_rdata_T_17; // @[Mux.scala 80:57]
  wire [63:0] lbu_rdata = 3'h7 == addr_low ? _lbu_rdata_T_7 : _lbu_rdata_T_19; // @[Mux.scala 80:57]
  wire [47:0] lh_rdata_hi = io_dmem_rdata[15] ? 48'hffffffffffff : 48'h0; // @[Bitwise.scala 72:12]
  wire [15:0] lh_rdata_lo = io_dmem_rdata[15:0]; // @[LSU.scala 109:52]
  wire [63:0] _lh_rdata_T_2 = {lh_rdata_hi,lh_rdata_lo}; // @[Cat.scala 30:58]
  wire [47:0] lh_rdata_hi_1 = io_dmem_rdata[31] ? 48'hffffffffffff : 48'h0; // @[Bitwise.scala 72:12]
  wire [15:0] lh_rdata_lo_1 = io_dmem_rdata[31:16]; // @[LSU.scala 110:52]
  wire [63:0] _lh_rdata_T_5 = {lh_rdata_hi_1,lh_rdata_lo_1}; // @[Cat.scala 30:58]
  wire [47:0] lh_rdata_hi_2 = io_dmem_rdata[47] ? 48'hffffffffffff : 48'h0; // @[Bitwise.scala 72:12]
  wire [15:0] lh_rdata_lo_2 = io_dmem_rdata[47:32]; // @[LSU.scala 111:52]
  wire [63:0] _lh_rdata_T_8 = {lh_rdata_hi_2,lh_rdata_lo_2}; // @[Cat.scala 30:58]
  wire [47:0] lh_rdata_hi_3 = io_dmem_rdata[63] ? 48'hffffffffffff : 48'h0; // @[Bitwise.scala 72:12]
  wire [15:0] lh_rdata_lo_3 = io_dmem_rdata[63:48]; // @[LSU.scala 112:52]
  wire [63:0] _lh_rdata_T_11 = {lh_rdata_hi_3,lh_rdata_lo_3}; // @[Cat.scala 30:58]
  wire [63:0] _lh_rdata_T_13 = 3'h0 == addr_low ? _lh_rdata_T_2 : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _lh_rdata_T_15 = 3'h2 == addr_low ? _lh_rdata_T_5 : _lh_rdata_T_13; // @[Mux.scala 80:57]
  wire [63:0] _lh_rdata_T_17 = 3'h4 == addr_low ? _lh_rdata_T_8 : _lh_rdata_T_15; // @[Mux.scala 80:57]
  wire [63:0] lh_rdata = 3'h6 == addr_low ? _lh_rdata_T_11 : _lh_rdata_T_17; // @[Mux.scala 80:57]
  wire [63:0] _lhu_rdata_T = {48'h0,lh_rdata_lo}; // @[Cat.scala 30:58]
  wire [63:0] _lhu_rdata_T_1 = {48'h0,lh_rdata_lo_1}; // @[Cat.scala 30:58]
  wire [63:0] _lhu_rdata_T_2 = {48'h0,lh_rdata_lo_2}; // @[Cat.scala 30:58]
  wire [63:0] _lhu_rdata_T_3 = {48'h0,lh_rdata_lo_3}; // @[Cat.scala 30:58]
  wire [63:0] _lhu_rdata_T_5 = 3'h0 == addr_low ? _lhu_rdata_T : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _lhu_rdata_T_7 = 3'h2 == addr_low ? _lhu_rdata_T_1 : _lhu_rdata_T_5; // @[Mux.scala 80:57]
  wire [63:0] _lhu_rdata_T_9 = 3'h4 == addr_low ? _lhu_rdata_T_2 : _lhu_rdata_T_7; // @[Mux.scala 80:57]
  wire [63:0] lhu_rdata = 3'h6 == addr_low ? _lhu_rdata_T_3 : _lhu_rdata_T_9; // @[Mux.scala 80:57]
  wire [31:0] lw_rdata_hi = io_dmem_rdata[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [31:0] lw_rdata_lo = io_dmem_rdata[31:0]; // @[LSU.scala 121:52]
  wire [63:0] _lw_rdata_T_2 = {lw_rdata_hi,lw_rdata_lo}; // @[Cat.scala 30:58]
  wire [31:0] lw_rdata_hi_1 = io_dmem_rdata[63] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [31:0] lw_rdata_lo_1 = io_dmem_rdata[63:32]; // @[LSU.scala 122:52]
  wire [63:0] _lw_rdata_T_5 = {lw_rdata_hi_1,lw_rdata_lo_1}; // @[Cat.scala 30:58]
  wire [63:0] _lw_rdata_T_7 = 3'h0 == addr_low ? _lw_rdata_T_2 : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] lw_rdata = 3'h4 == addr_low ? _lw_rdata_T_5 : _lw_rdata_T_7; // @[Mux.scala 80:57]
  wire [63:0] _lwu_rdata_T = {32'h0,lw_rdata_lo}; // @[Cat.scala 30:58]
  wire [63:0] _lwu_rdata_T_1 = {32'h0,lw_rdata_lo_1}; // @[Cat.scala 30:58]
  wire [63:0] _lwu_rdata_T_3 = 3'h0 == addr_low ? _lwu_rdata_T : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] lwu_rdata = 3'h4 == addr_low ? _lwu_rdata_T_1 : _lwu_rdata_T_3; // @[Mux.scala 80:57]
  wire [63:0] _load_rdata_T_1 = 4'h1 == io_lsu_op ? lb_rdata : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _load_rdata_T_3 = 4'h4 == io_lsu_op ? lbu_rdata : _load_rdata_T_1; // @[Mux.scala 80:57]
  wire [63:0] _load_rdata_T_5 = 4'h2 == io_lsu_op ? lh_rdata : _load_rdata_T_3; // @[Mux.scala 80:57]
  wire [63:0] _load_rdata_T_7 = 4'h5 == io_lsu_op ? lhu_rdata : _load_rdata_T_5; // @[Mux.scala 80:57]
  wire [63:0] _load_rdata_T_9 = 4'h3 == io_lsu_op ? lw_rdata : _load_rdata_T_7; // @[Mux.scala 80:57]
  wire [63:0] _load_rdata_T_11 = 4'h9 == io_lsu_op ? lwu_rdata : _load_rdata_T_9; // @[Mux.scala 80:57]
  assign io_dmem_en = io_is_lsu; // @[LSU.scala 139:14]
  assign io_dmem_addr = io_src1 + io_src2; // @[LSU.scala 23:24]
  assign io_dmem_wdata = 4'hb == io_lsu_op ? io_wdata : _dmem_wdata_T_5; // @[Mux.scala 80:57]
  assign io_dmem_wmask = 4'hb == io_lsu_op ? 64'hffffffffffffffff : _dmem_wmask_T_5; // @[Mux.scala 80:57]
  assign io_dmem_wen = io_is_lsu & ~io_wen; // @[LSU.scala 141:25]
  assign io_rdata = 4'ha == io_lsu_op ? io_dmem_rdata : _load_rdata_T_11; // @[Mux.scala 80:57]
endmodule
module CSR(
  input         clock,
  input         reset,
  input  [31:0] io_pc,
  input  [2:0]  io_csr_op,
  input  [11:0] io_addr,
  input  [63:0] io_src,
  output [63:0] io_rdata,
  output        io_is_reflush,
  output [63:0] io_csr_target,
  output        io_handle_int,
  input         io_valid,
  input         clint_has_int
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [63:0] _RAND_1;
  reg [63:0] _RAND_2;
  reg [63:0] _RAND_3;
  reg [63:0] _RAND_4;
  reg [63:0] _RAND_5;
  reg [63:0] _RAND_6;
  reg [63:0] _RAND_7;
`endif // RANDOMIZE_REG_INIT
  reg [63:0] mcycle; // @[CSR.scala 28:23]
  reg [63:0] mepc; // @[CSR.scala 29:21]
  reg [63:0] mcause; // @[CSR.scala 30:23]
  reg [63:0] mstatus; // @[CSR.scala 31:24]
  reg [63:0] mtvec; // @[CSR.scala 32:22]
  reg [63:0] mip; // @[CSR.scala 33:20]
  reg [63:0] mie; // @[CSR.scala 34:20]
  reg [63:0] mscratch; // @[CSR.scala 35:25]
  wire  wen = io_csr_op == 3'h1 | io_csr_op == 3'h2 | io_csr_op == 3'h3; // @[CSR.scala 43:59]
  wire  _T_37 = io_addr == 12'h342; // @[MAP.scala 19:18]
  wire  _T_34 = io_addr == 12'h344; // @[MAP.scala 19:18]
  wire  _T_31 = io_addr == 12'hb00; // @[MAP.scala 19:18]
  wire  _T_28 = io_addr == 12'h305; // @[MAP.scala 19:18]
  wire  _T_25 = io_addr == 12'h341; // @[MAP.scala 19:18]
  wire  _T_22 = io_addr == 12'h340; // @[MAP.scala 19:18]
  wire  _T_19 = io_addr == 12'h300; // @[MAP.scala 19:18]
  wire  _T_16 = io_addr == 12'h304; // @[MAP.scala 19:18]
  wire [63:0] _GEN_14 = io_addr == 12'h304 ? mie : 64'h0; // @[MAP.scala 19:25 MAP.scala 20:15]
  wire [63:0] _GEN_16 = io_addr == 12'h300 ? mstatus : _GEN_14; // @[MAP.scala 19:25 MAP.scala 20:15]
  wire [63:0] _GEN_18 = io_addr == 12'h340 ? mscratch : _GEN_16; // @[MAP.scala 19:25 MAP.scala 20:15]
  wire [63:0] _GEN_20 = io_addr == 12'h341 ? mepc : _GEN_18; // @[MAP.scala 19:25 MAP.scala 20:15]
  wire [63:0] _GEN_22 = io_addr == 12'h305 ? mtvec : _GEN_20; // @[MAP.scala 19:25 MAP.scala 20:15]
  wire [63:0] _GEN_24 = io_addr == 12'hb00 ? mcycle : _GEN_22; // @[MAP.scala 19:25 MAP.scala 20:15]
  wire [63:0] _GEN_26 = io_addr == 12'h344 ? mip : _GEN_24; // @[MAP.scala 19:25 MAP.scala 20:15]
  wire [63:0] rdata = io_addr == 12'h342 ? mcause : _GEN_26; // @[MAP.scala 19:25 MAP.scala 20:15]
  wire [63:0] _wdata_T = rdata | io_src; // @[CSR.scala 63:25]
  wire [63:0] _wdata_T_1 = ~io_src; // @[CSR.scala 64:28]
  wire [63:0] _wdata_T_2 = rdata & _wdata_T_1; // @[CSR.scala 64:25]
  wire [63:0] _wdata_T_4 = 3'h1 == io_csr_op ? io_src : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _wdata_T_6 = 3'h2 == io_csr_op ? _wdata_T : _wdata_T_4; // @[Mux.scala 80:57]
  wire [63:0] wdata = 3'h3 == io_csr_op ? _wdata_T_2 : _wdata_T_6; // @[Mux.scala 80:57]
  wire  _T_14 = io_csr_op == 3'h4; // @[CSR.scala 67:16]
  wire [55:0] mstatus_hi_hi_hi = mstatus[63:8]; // @[CSR.scala 70:27]
  wire  mstatus_hi_hi_lo = mstatus[3]; // @[CSR.scala 70:43]
  wire [2:0] mstatus_hi_lo = mstatus[6:4]; // @[CSR.scala 70:55]
  wire [2:0] mstatus_lo_lo = mstatus[2:0]; // @[CSR.scala 70:75]
  wire [63:0] _mstatus_T = {mstatus_hi_hi_hi,mstatus_hi_hi_lo,mstatus_hi_lo,1'h0,mstatus_lo_lo}; // @[Cat.scala 30:58]
  wire [29:0] csr_target_hi = mtvec[31:2]; // @[CSR.scala 72:28]
  wire [31:0] _csr_target_T = {csr_target_hi,2'h0}; // @[Cat.scala 30:58]
  wire [63:0] _GEN_2 = io_csr_op == 3'h4 ? _mstatus_T : mstatus; // @[CSR.scala 67:31 CSR.scala 70:13 CSR.scala 31:24]
  wire [31:0] _GEN_4 = io_csr_op == 3'h4 ? _csr_target_T : 32'h0; // @[CSR.scala 67:31 CSR.scala 72:16]
  wire  handle_int = clint_has_int & mstatus_hi_hi_lo & mie[7] & io_valid; // @[CSR.scala 96:40]
  wire  _GEN_9 = handle_int | _T_14; // @[CSR.scala 75:20 CSR.scala 80:15]
  wire [31:0] _GEN_10 = handle_int ? _csr_target_T : _GEN_4; // @[CSR.scala 75:20 CSR.scala 81:16]
  wire  mstatus_lo_hi = mstatus[7]; // @[CSR.scala 85:63]
  wire [63:0] _mstatus_T_2 = {mstatus_hi_hi_hi,1'h1,mstatus_hi_lo,mstatus_lo_hi,mstatus_lo_lo}; // @[Cat.scala 30:58]
  wire [31:0] csr_target = io_csr_op == 3'h5 ? mepc[31:0] : _GEN_10; // @[CSR.scala 84:30 CSR.scala 87:16]
  wire [63:0] _mcycle_T_1 = mcycle + 64'h1; // @[CSR.scala 90:20]
  wire  mstatus_mstatus_new_hi = wdata[16:15] == 2'h3 | wdata[14:13] == 2'h3; // @[CSR.scala 46:57]
  wire [62:0] mstatus_mstatus_new_lo = wdata[62:0]; // @[CSR.scala 46:98]
  wire [63:0] mstatus_mstatus_new = {mstatus_mstatus_new_hi,mstatus_mstatus_new_lo}; // @[Cat.scala 30:58]
  wire [63:0] _mip_T_2 = mip & 64'h1; // @[MAP.scala 6:33]
  wire [55:0] mip_hi_hi = mip[63:8]; // @[CSR.scala 98:19]
  wire [6:0] mip_lo = mip[6:0]; // @[CSR.scala 98:36]
  wire [63:0] _mip_T_4 = {mip_hi_hi,1'h1,mip_lo}; // @[Cat.scala 30:58]
  assign io_rdata = io_addr == 12'h342 ? mcause : _GEN_26; // @[MAP.scala 19:25 MAP.scala 20:15]
  assign io_is_reflush = io_csr_op == 3'h5 | _GEN_9; // @[CSR.scala 84:30 CSR.scala 86:15]
  assign io_csr_target = {{32'd0}, csr_target}; // @[CSR.scala 84:30 CSR.scala 87:16]
  assign io_handle_int = clint_has_int & mstatus_hi_hi_lo & mie[7] & io_valid; // @[CSR.scala 96:40]
  always @(posedge clock) begin
    if (reset) begin // @[CSR.scala 28:23]
      mcycle <= 64'h0; // @[CSR.scala 28:23]
    end else if (_T_31 & wen) begin // @[MAP.scala 23:34]
      if (3'h3 == io_csr_op) begin // @[Mux.scala 80:57]
        mcycle <= _wdata_T_2;
      end else if (3'h2 == io_csr_op) begin // @[Mux.scala 80:57]
        mcycle <= _wdata_T;
      end else begin
        mcycle <= _wdata_T_4;
      end
    end else begin
      mcycle <= _mcycle_T_1; // @[CSR.scala 90:10]
    end
    if (reset) begin // @[CSR.scala 29:21]
      mepc <= 64'h0; // @[CSR.scala 29:21]
    end else if (_T_25 & wen) begin // @[MAP.scala 23:34]
      if (3'h3 == io_csr_op) begin // @[Mux.scala 80:57]
        mepc <= _wdata_T_2;
      end else if (3'h2 == io_csr_op) begin // @[Mux.scala 80:57]
        mepc <= _wdata_T;
      end else begin
        mepc <= _wdata_T_4;
      end
    end else if (handle_int) begin // @[CSR.scala 75:20]
      mepc <= {{32'd0}, io_pc}; // @[CSR.scala 77:10]
    end else if (io_csr_op == 3'h4) begin // @[CSR.scala 67:31]
      mepc <= {{32'd0}, io_pc}; // @[CSR.scala 68:10]
    end
    if (reset) begin // @[CSR.scala 30:23]
      mcause <= 64'h0; // @[CSR.scala 30:23]
    end else if (_T_37 & wen) begin // @[MAP.scala 23:34]
      if (3'h3 == io_csr_op) begin // @[Mux.scala 80:57]
        mcause <= _wdata_T_2;
      end else if (3'h2 == io_csr_op) begin // @[Mux.scala 80:57]
        mcause <= _wdata_T;
      end else begin
        mcause <= _wdata_T_4;
      end
    end else if (handle_int) begin // @[CSR.scala 75:20]
      mcause <= 64'h8000000000000007; // @[CSR.scala 78:12]
    end else if (io_csr_op == 3'h4) begin // @[CSR.scala 67:31]
      mcause <= 64'hb; // @[CSR.scala 69:12]
    end
    if (reset) begin // @[CSR.scala 31:24]
      mstatus <= 64'h1800; // @[CSR.scala 31:24]
    end else if (_T_19 & wen) begin // @[MAP.scala 23:34]
      mstatus <= mstatus_mstatus_new; // @[MAP.scala 24:13]
    end else if (io_csr_op == 3'h5) begin // @[CSR.scala 84:30]
      mstatus <= _mstatus_T_2; // @[CSR.scala 85:13]
    end else if (handle_int) begin // @[CSR.scala 75:20]
      mstatus <= _mstatus_T; // @[CSR.scala 79:13]
    end else begin
      mstatus <= _GEN_2;
    end
    if (reset) begin // @[CSR.scala 32:22]
      mtvec <= 64'h0; // @[CSR.scala 32:22]
    end else if (_T_28 & wen) begin // @[MAP.scala 23:34]
      if (3'h3 == io_csr_op) begin // @[Mux.scala 80:57]
        mtvec <= _wdata_T_2;
      end else if (3'h2 == io_csr_op) begin // @[Mux.scala 80:57]
        mtvec <= _wdata_T;
      end else begin
        mtvec <= _wdata_T_4;
      end
    end
    if (reset) begin // @[CSR.scala 33:20]
      mip <= 64'h0; // @[CSR.scala 33:20]
    end else if (handle_int) begin // @[CSR.scala 96:53]
      mip <= _mip_T_4; // @[CSR.scala 98:9]
    end else if (_T_34 & wen) begin // @[MAP.scala 23:34]
      mip <= _mip_T_2; // @[MAP.scala 24:13]
    end else if (handle_int) begin // @[CSR.scala 75:20]
      mip <= 64'h0; // @[CSR.scala 76:9]
    end
    if (reset) begin // @[CSR.scala 34:20]
      mie <= 64'h0; // @[CSR.scala 34:20]
    end else if (_T_16 & wen) begin // @[MAP.scala 23:34]
      if (3'h3 == io_csr_op) begin // @[Mux.scala 80:57]
        mie <= _wdata_T_2;
      end else if (3'h2 == io_csr_op) begin // @[Mux.scala 80:57]
        mie <= _wdata_T;
      end else begin
        mie <= _wdata_T_4;
      end
    end
    if (reset) begin // @[CSR.scala 35:25]
      mscratch <= 64'h0; // @[CSR.scala 35:25]
    end else if (_T_22 & wen) begin // @[MAP.scala 23:34]
      if (3'h3 == io_csr_op) begin // @[Mux.scala 80:57]
        mscratch <= _wdata_T_2;
      end else if (3'h2 == io_csr_op) begin // @[Mux.scala 80:57]
        mscratch <= _wdata_T;
      end else begin
        mscratch <= _wdata_T_4;
      end
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
  mcycle = _RAND_0[63:0];
  _RAND_1 = {2{`RANDOM}};
  mepc = _RAND_1[63:0];
  _RAND_2 = {2{`RANDOM}};
  mcause = _RAND_2[63:0];
  _RAND_3 = {2{`RANDOM}};
  mstatus = _RAND_3[63:0];
  _RAND_4 = {2{`RANDOM}};
  mtvec = _RAND_4[63:0];
  _RAND_5 = {2{`RANDOM}};
  mip = _RAND_5[63:0];
  _RAND_6 = {2{`RANDOM}};
  mie = _RAND_6[63:0];
  _RAND_7 = {2{`RANDOM}};
  mscratch = _RAND_7[63:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module CLINT(
  input         clock,
  input         reset,
  input         io_is_mtime,
  input         io_is_mtimecmp,
  input         io_is_clint,
  input         io_wen,
  input  [63:0] io_wdata,
  output [63:0] io_rdata,
  output        has_int_0
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [63:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  reg [63:0] mtime; // @[CLINT.scala 17:22]
  reg [63:0] mtimecmp; // @[CLINT.scala 18:25]
  wire [63:0] _mtime_T_1 = mtime + 64'h1; // @[CLINT.scala 27:18]
  wire [63:0] _rdata_T = io_is_mtime ? mtime : mtimecmp; // @[CLINT.scala 31:19]
  wire [63:0] _GEN_0 = io_wen ? _rdata_T : 64'h0; // @[CLINT.scala 30:16 CLINT.scala 31:13]
  wire  _GEN_8 = mtime >= mtimecmp; // @[CLINT.scala 45:16]
  wire  has_int = mtime >= mtimecmp; // @[CLINT.scala 45:16]
  assign io_rdata = io_is_clint ? _GEN_0 : 64'h0; // @[CLINT.scala 29:19]
  assign has_int_0 = _GEN_8;
  always @(posedge clock) begin
    if (reset) begin // @[CLINT.scala 17:22]
      mtime <= 64'h0; // @[CLINT.scala 17:22]
    end else if (io_is_clint) begin // @[CLINT.scala 29:19]
      if (~io_wen) begin // @[CLINT.scala 33:17]
        if (io_is_mtime) begin // @[CLINT.scala 34:23]
          mtime <= io_wdata; // @[CLINT.scala 35:15]
        end else begin
          mtime <= _mtime_T_1; // @[CLINT.scala 27:9]
        end
      end else begin
        mtime <= _mtime_T_1; // @[CLINT.scala 27:9]
      end
    end else begin
      mtime <= _mtime_T_1; // @[CLINT.scala 27:9]
    end
    if (reset) begin // @[CLINT.scala 18:25]
      mtimecmp <= 64'h0; // @[CLINT.scala 18:25]
    end else if (io_is_clint) begin // @[CLINT.scala 29:19]
      if (~io_wen) begin // @[CLINT.scala 33:17]
        if (io_is_mtimecmp) begin // @[CLINT.scala 37:26]
          mtimecmp <= io_wdata; // @[CLINT.scala 38:18]
        end
      end
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
  mtime = _RAND_0[63:0];
  _RAND_1 = {2{`RANDOM}};
  mtimecmp = _RAND_1[63:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module EXU(
  input         clock,
  input         reset,
  output        io_dmem_en,
  output [63:0] io_dmem_addr,
  input  [63:0] io_dmem_rdata,
  output [63:0] io_dmem_wdata,
  output [63:0] io_dmem_wmask,
  output        io_dmem_wen,
  input         io_in_valid,
  input  [31:0] io_in_bits_pc,
  input  [31:0] io_in_bits_inst,
  input  [63:0] io_in_bits_src1_value,
  input  [63:0] io_in_bits_src2_value,
  input  [63:0] io_in_bits_rs2_value,
  input  [4:0]  io_in_bits_dest,
  input  [1:0]  io_in_bits_fu_type,
  input  [4:0]  io_in_bits_alu_op,
  input  [3:0]  io_in_bits_lsu_op,
  input  [2:0]  io_in_bits_csr_op,
  input         io_in_bits_wen,
  input         io_in_bits_rv64,
  output        io_out_valid,
  output [31:0] io_out_bits_pc,
  output [31:0] io_out_bits_inst,
  output [63:0] io_out_bits_final_result,
  output [4:0]  io_out_bits_dest,
  output        io_out_bits_wen,
  output        io_forward_is_reflush,
  output        io_forward_fwd_valid,
  output [4:0]  io_forward_rf_waddr,
  output [63:0] io_forward_rf_wdata,
  output        io_br_bus_is_reflush,
  output [31:0] io_br_bus_br_target
);
  wire [4:0] alu_io_alu_op; // @[EXU.scala 28:19]
  wire  alu_io_rv64; // @[EXU.scala 28:19]
  wire [63:0] alu_io_src1; // @[EXU.scala 28:19]
  wire [63:0] alu_io_src2; // @[EXU.scala 28:19]
  wire [63:0] alu_io_result; // @[EXU.scala 28:19]
  wire  lsu_io_dmem_en; // @[EXU.scala 29:19]
  wire [63:0] lsu_io_dmem_addr; // @[EXU.scala 29:19]
  wire [63:0] lsu_io_dmem_rdata; // @[EXU.scala 29:19]
  wire [63:0] lsu_io_dmem_wdata; // @[EXU.scala 29:19]
  wire [63:0] lsu_io_dmem_wmask; // @[EXU.scala 29:19]
  wire  lsu_io_dmem_wen; // @[EXU.scala 29:19]
  wire [63:0] lsu_io_src1; // @[EXU.scala 29:19]
  wire [63:0] lsu_io_src2; // @[EXU.scala 29:19]
  wire [63:0] lsu_io_wdata; // @[EXU.scala 29:19]
  wire  lsu_io_is_lsu; // @[EXU.scala 29:19]
  wire  lsu_io_wen; // @[EXU.scala 29:19]
  wire [3:0] lsu_io_lsu_op; // @[EXU.scala 29:19]
  wire [63:0] lsu_io_rdata; // @[EXU.scala 29:19]
  wire  csr_clock; // @[EXU.scala 30:19]
  wire  csr_reset; // @[EXU.scala 30:19]
  wire [31:0] csr_io_pc; // @[EXU.scala 30:19]
  wire [2:0] csr_io_csr_op; // @[EXU.scala 30:19]
  wire [11:0] csr_io_addr; // @[EXU.scala 30:19]
  wire [63:0] csr_io_src; // @[EXU.scala 30:19]
  wire [63:0] csr_io_rdata; // @[EXU.scala 30:19]
  wire  csr_io_is_reflush; // @[EXU.scala 30:19]
  wire [63:0] csr_io_csr_target; // @[EXU.scala 30:19]
  wire  csr_io_handle_int; // @[EXU.scala 30:19]
  wire  csr_io_valid; // @[EXU.scala 30:19]
  wire  csr_clint_has_int; // @[EXU.scala 30:19]
  wire  clint_clock; // @[EXU.scala 31:21]
  wire  clint_reset; // @[EXU.scala 31:21]
  wire  clint_io_is_mtime; // @[EXU.scala 31:21]
  wire  clint_io_is_mtimecmp; // @[EXU.scala 31:21]
  wire  clint_io_is_clint; // @[EXU.scala 31:21]
  wire  clint_io_wen; // @[EXU.scala 31:21]
  wire [63:0] clint_io_wdata; // @[EXU.scala 31:21]
  wire [63:0] clint_io_rdata; // @[EXU.scala 31:21]
  wire  clint_has_int_0; // @[EXU.scala 31:21]
  wire  is_lsu = io_in_bits_fu_type == 2'h2; // @[EXU.scala 52:22]
  wire  is_clint = (clint_io_is_mtime | clint_io_is_mtimecmp) & io_in_valid; // @[EXU.scala 79:59]
  wire [63:0] lsu_rdata = is_clint ? clint_io_rdata : lsu_io_rdata; // @[EXU.scala 60:19]
  wire [2:0] _csr_io_csr_op_T_1 = io_in_valid ? 3'h7 : 3'h0; // @[Bitwise.scala 72:12]
  wire [63:0] alu_result = alu_io_result; // @[EXU.scala 33:24 EXU.scala 45:14]
  wire [31:0] _final_result_T_1 = io_in_bits_pc + 32'h4; // @[EXU.scala 83:19]
  wire [63:0] _final_result_T_3 = 2'h1 == io_in_bits_fu_type ? {{32'd0}, _final_result_T_1} : alu_result; // @[Mux.scala 80:57]
  wire [63:0] _final_result_T_5 = 2'h2 == io_in_bits_fu_type ? lsu_rdata : _final_result_T_3; // @[Mux.scala 80:57]
  wire [63:0] csr_rdata = csr_io_rdata; // @[EXU.scala 36:23 EXU.scala 68:13]
  wire  handle_int = csr_io_handle_int; // @[EXU.scala 42:24 EXU.scala 71:14]
  wire [63:0] csr_target = csr_io_csr_target; // @[EXU.scala 41:24 EXU.scala 70:14]
  ALU alu ( // @[EXU.scala 28:19]
    .io_alu_op(alu_io_alu_op),
    .io_rv64(alu_io_rv64),
    .io_src1(alu_io_src1),
    .io_src2(alu_io_src2),
    .io_result(alu_io_result)
  );
  LSU lsu ( // @[EXU.scala 29:19]
    .io_dmem_en(lsu_io_dmem_en),
    .io_dmem_addr(lsu_io_dmem_addr),
    .io_dmem_rdata(lsu_io_dmem_rdata),
    .io_dmem_wdata(lsu_io_dmem_wdata),
    .io_dmem_wmask(lsu_io_dmem_wmask),
    .io_dmem_wen(lsu_io_dmem_wen),
    .io_src1(lsu_io_src1),
    .io_src2(lsu_io_src2),
    .io_wdata(lsu_io_wdata),
    .io_is_lsu(lsu_io_is_lsu),
    .io_wen(lsu_io_wen),
    .io_lsu_op(lsu_io_lsu_op),
    .io_rdata(lsu_io_rdata)
  );
  CSR csr ( // @[EXU.scala 30:19]
    .clock(csr_clock),
    .reset(csr_reset),
    .io_pc(csr_io_pc),
    .io_csr_op(csr_io_csr_op),
    .io_addr(csr_io_addr),
    .io_src(csr_io_src),
    .io_rdata(csr_io_rdata),
    .io_is_reflush(csr_io_is_reflush),
    .io_csr_target(csr_io_csr_target),
    .io_handle_int(csr_io_handle_int),
    .io_valid(csr_io_valid),
    .clint_has_int(csr_clint_has_int)
  );
  CLINT clint ( // @[EXU.scala 31:21]
    .clock(clint_clock),
    .reset(clint_reset),
    .io_is_mtime(clint_io_is_mtime),
    .io_is_mtimecmp(clint_io_is_mtimecmp),
    .io_is_clint(clint_io_is_clint),
    .io_wen(clint_io_wen),
    .io_wdata(clint_io_wdata),
    .io_rdata(clint_io_rdata),
    .has_int_0(clint_has_int_0)
  );
  assign io_dmem_en = lsu_io_dmem_en; // @[EXU.scala 53:15]
  assign io_dmem_addr = lsu_io_dmem_addr; // @[EXU.scala 53:15]
  assign io_dmem_wdata = lsu_io_dmem_wdata; // @[EXU.scala 53:15]
  assign io_dmem_wmask = lsu_io_dmem_wmask; // @[EXU.scala 53:15]
  assign io_dmem_wen = lsu_io_dmem_wen; // @[EXU.scala 53:15]
  assign io_out_valid = io_in_valid & ~handle_int; // @[EXU.scala 98:31]
  assign io_out_bits_pc = io_in_bits_pc; // @[EXU.scala 88:18]
  assign io_out_bits_inst = io_in_bits_inst; // @[EXU.scala 89:20]
  assign io_out_bits_final_result = 2'h3 == io_in_bits_fu_type ? csr_rdata : _final_result_T_5; // @[Mux.scala 80:57]
  assign io_out_bits_dest = io_in_bits_dest; // @[EXU.scala 91:20]
  assign io_out_bits_wen = io_in_bits_wen; // @[EXU.scala 92:19]
  assign io_forward_is_reflush = csr_io_is_reflush; // @[EXU.scala 40:24 EXU.scala 69:14]
  assign io_forward_fwd_valid = io_in_bits_wen & io_in_bits_dest != 5'h0 & io_in_valid; // @[EXU.scala 101:47]
  assign io_forward_rf_waddr = io_in_bits_dest; // @[EXU.scala 102:23]
  assign io_forward_rf_wdata = 2'h3 == io_in_bits_fu_type ? csr_rdata : _final_result_T_5; // @[Mux.scala 80:57]
  assign io_br_bus_is_reflush = csr_io_is_reflush; // @[EXU.scala 40:24 EXU.scala 69:14]
  assign io_br_bus_br_target = csr_target[31:0]; // @[EXU.scala 106:23]
  assign alu_io_alu_op = io_in_bits_alu_op; // @[EXU.scala 46:17]
  assign alu_io_rv64 = io_in_bits_rv64; // @[EXU.scala 47:15]
  assign alu_io_src1 = io_in_bits_src1_value; // @[EXU.scala 48:15]
  assign alu_io_src2 = io_in_bits_src2_value; // @[EXU.scala 49:15]
  assign lsu_io_dmem_rdata = io_dmem_rdata; // @[EXU.scala 53:15]
  assign lsu_io_src1 = io_in_bits_src1_value; // @[EXU.scala 54:15]
  assign lsu_io_src2 = io_in_bits_src2_value; // @[EXU.scala 55:15]
  assign lsu_io_wdata = io_in_bits_rs2_value; // @[EXU.scala 56:16]
  assign lsu_io_is_lsu = is_lsu & ~is_clint & io_in_valid; // @[EXU.scala 57:40]
  assign lsu_io_wen = io_in_bits_wen; // @[EXU.scala 58:14]
  assign lsu_io_lsu_op = io_in_bits_lsu_op; // @[EXU.scala 59:17]
  assign csr_clock = clock;
  assign csr_reset = reset;
  assign csr_io_pc = io_in_bits_pc; // @[EXU.scala 63:13]
  assign csr_io_csr_op = io_in_bits_csr_op & _csr_io_csr_op_T_1; // @[EXU.scala 64:27]
  assign csr_io_addr = io_in_bits_inst[31:20]; // @[EXU.scala 65:22]
  assign csr_io_src = io_in_bits_src1_value; // @[EXU.scala 66:14]
  assign csr_io_valid = io_in_valid; // @[EXU.scala 67:16]
  assign csr_clint_has_int = clint_has_int_0;
  assign clint_clock = clock;
  assign clint_reset = reset;
  assign clint_io_is_mtime = alu_result == 64'h200bff8; // @[EXU.scala 74:36]
  assign clint_io_is_mtimecmp = alu_result == 64'h2004000; // @[EXU.scala 75:39]
  assign clint_io_is_clint = is_lsu & is_clint; // @[EXU.scala 76:31]
  assign clint_io_wen = io_in_bits_wen; // @[EXU.scala 77:16]
  assign clint_io_wdata = io_in_bits_rs2_value; // @[EXU.scala 78:18]
endmodule
module WBU(
  input         io_in_valid,
  input  [31:0] io_in_bits_pc,
  input  [31:0] io_in_bits_inst,
  input  [63:0] io_in_bits_final_result,
  input  [4:0]  io_in_bits_dest,
  input         io_in_bits_wen,
  output        io_wb_bus_rf_wen,
  output [4:0]  io_wb_bus_rf_waddr,
  output [63:0] io_wb_bus_rf_wdata,
  output        io_commit_valid,
  output [31:0] io_commit_pc,
  output [31:0] io_commit_inst
);
  assign io_wb_bus_rf_wen = io_in_bits_wen & io_in_bits_dest != 5'h0 & io_in_valid; // @[WBU.scala 23:46]
  assign io_wb_bus_rf_waddr = io_in_bits_dest; // @[WBU.scala 24:22]
  assign io_wb_bus_rf_wdata = io_in_bits_final_result; // @[WBU.scala 25:22]
  assign io_commit_valid = io_in_valid; // @[WBU.scala 32:19]
  assign io_commit_pc = io_in_bits_pc; // @[WBU.scala 27:16]
  assign io_commit_inst = io_in_bits_inst; // @[WBU.scala 28:18]
endmodule
module Core(
  input         clock,
  input         reset,
  output        io_imem_en,
  output [63:0] io_imem_addr,
  input  [63:0] io_imem_rdata,
  output        io_dmem_en,
  output [63:0] io_dmem_addr,
  input  [63:0] io_dmem_rdata,
  output [63:0] io_dmem_wdata,
  output [63:0] io_dmem_wmask,
  output        io_dmem_wen
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [63:0] _RAND_6;
  reg [63:0] _RAND_7;
  reg [63:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [63:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [31:0] _RAND_21;
`endif // RANDOMIZE_REG_INIT
  wire  ifu_clock; // @[Core.scala 12:19]
  wire  ifu_reset; // @[Core.scala 12:19]
  wire  ifu_io_imem_en; // @[Core.scala 12:19]
  wire [63:0] ifu_io_imem_addr; // @[Core.scala 12:19]
  wire [63:0] ifu_io_imem_rdata; // @[Core.scala 12:19]
  wire  ifu_io_out_valid; // @[Core.scala 12:19]
  wire [31:0] ifu_io_out_bits_pc; // @[Core.scala 12:19]
  wire [31:0] ifu_io_out_bits_inst; // @[Core.scala 12:19]
  wire  ifu_io_br_bus_br_taken; // @[Core.scala 12:19]
  wire [31:0] ifu_io_br_bus_br_target; // @[Core.scala 12:19]
  wire  ifu_io_csr_br_bus_is_reflush; // @[Core.scala 12:19]
  wire [31:0] ifu_io_csr_br_bus_br_target; // @[Core.scala 12:19]
  wire  idu_clock; // @[Core.scala 13:19]
  wire  idu_io_in_valid; // @[Core.scala 13:19]
  wire [31:0] idu_io_in_bits_pc; // @[Core.scala 13:19]
  wire [31:0] idu_io_in_bits_inst; // @[Core.scala 13:19]
  wire  idu_io_out_valid; // @[Core.scala 13:19]
  wire [31:0] idu_io_out_bits_pc; // @[Core.scala 13:19]
  wire [31:0] idu_io_out_bits_inst; // @[Core.scala 13:19]
  wire [63:0] idu_io_out_bits_src1_value; // @[Core.scala 13:19]
  wire [63:0] idu_io_out_bits_src2_value; // @[Core.scala 13:19]
  wire [63:0] idu_io_out_bits_rs2_value; // @[Core.scala 13:19]
  wire [4:0] idu_io_out_bits_dest; // @[Core.scala 13:19]
  wire [1:0] idu_io_out_bits_fu_type; // @[Core.scala 13:19]
  wire [4:0] idu_io_out_bits_alu_op; // @[Core.scala 13:19]
  wire [3:0] idu_io_out_bits_lsu_op; // @[Core.scala 13:19]
  wire [2:0] idu_io_out_bits_csr_op; // @[Core.scala 13:19]
  wire  idu_io_out_bits_wen; // @[Core.scala 13:19]
  wire  idu_io_out_bits_rv64; // @[Core.scala 13:19]
  wire  idu_io_br_bus_br_taken; // @[Core.scala 13:19]
  wire [31:0] idu_io_br_bus_br_target; // @[Core.scala 13:19]
  wire  idu_io_wb_bus_rf_wen; // @[Core.scala 13:19]
  wire [4:0] idu_io_wb_bus_rf_waddr; // @[Core.scala 13:19]
  wire [63:0] idu_io_wb_bus_rf_wdata; // @[Core.scala 13:19]
  wire  idu_io_ex_fwd_is_reflush; // @[Core.scala 13:19]
  wire  idu_io_ex_fwd_fwd_valid; // @[Core.scala 13:19]
  wire [4:0] idu_io_ex_fwd_rf_waddr; // @[Core.scala 13:19]
  wire [63:0] idu_io_ex_fwd_rf_wdata; // @[Core.scala 13:19]
  wire  exu_clock; // @[Core.scala 14:19]
  wire  exu_reset; // @[Core.scala 14:19]
  wire  exu_io_dmem_en; // @[Core.scala 14:19]
  wire [63:0] exu_io_dmem_addr; // @[Core.scala 14:19]
  wire [63:0] exu_io_dmem_rdata; // @[Core.scala 14:19]
  wire [63:0] exu_io_dmem_wdata; // @[Core.scala 14:19]
  wire [63:0] exu_io_dmem_wmask; // @[Core.scala 14:19]
  wire  exu_io_dmem_wen; // @[Core.scala 14:19]
  wire  exu_io_in_valid; // @[Core.scala 14:19]
  wire [31:0] exu_io_in_bits_pc; // @[Core.scala 14:19]
  wire [31:0] exu_io_in_bits_inst; // @[Core.scala 14:19]
  wire [63:0] exu_io_in_bits_src1_value; // @[Core.scala 14:19]
  wire [63:0] exu_io_in_bits_src2_value; // @[Core.scala 14:19]
  wire [63:0] exu_io_in_bits_rs2_value; // @[Core.scala 14:19]
  wire [4:0] exu_io_in_bits_dest; // @[Core.scala 14:19]
  wire [1:0] exu_io_in_bits_fu_type; // @[Core.scala 14:19]
  wire [4:0] exu_io_in_bits_alu_op; // @[Core.scala 14:19]
  wire [3:0] exu_io_in_bits_lsu_op; // @[Core.scala 14:19]
  wire [2:0] exu_io_in_bits_csr_op; // @[Core.scala 14:19]
  wire  exu_io_in_bits_wen; // @[Core.scala 14:19]
  wire  exu_io_in_bits_rv64; // @[Core.scala 14:19]
  wire  exu_io_out_valid; // @[Core.scala 14:19]
  wire [31:0] exu_io_out_bits_pc; // @[Core.scala 14:19]
  wire [31:0] exu_io_out_bits_inst; // @[Core.scala 14:19]
  wire [63:0] exu_io_out_bits_final_result; // @[Core.scala 14:19]
  wire [4:0] exu_io_out_bits_dest; // @[Core.scala 14:19]
  wire  exu_io_out_bits_wen; // @[Core.scala 14:19]
  wire  exu_io_forward_is_reflush; // @[Core.scala 14:19]
  wire  exu_io_forward_fwd_valid; // @[Core.scala 14:19]
  wire [4:0] exu_io_forward_rf_waddr; // @[Core.scala 14:19]
  wire [63:0] exu_io_forward_rf_wdata; // @[Core.scala 14:19]
  wire  exu_io_br_bus_is_reflush; // @[Core.scala 14:19]
  wire [31:0] exu_io_br_bus_br_target; // @[Core.scala 14:19]
  wire  wbu_io_in_valid; // @[Core.scala 15:19]
  wire [31:0] wbu_io_in_bits_pc; // @[Core.scala 15:19]
  wire [31:0] wbu_io_in_bits_inst; // @[Core.scala 15:19]
  wire [63:0] wbu_io_in_bits_final_result; // @[Core.scala 15:19]
  wire [4:0] wbu_io_in_bits_dest; // @[Core.scala 15:19]
  wire  wbu_io_in_bits_wen; // @[Core.scala 15:19]
  wire  wbu_io_wb_bus_rf_wen; // @[Core.scala 15:19]
  wire [4:0] wbu_io_wb_bus_rf_waddr; // @[Core.scala 15:19]
  wire [63:0] wbu_io_wb_bus_rf_wdata; // @[Core.scala 15:19]
  wire  wbu_io_commit_valid; // @[Core.scala 15:19]
  wire [31:0] wbu_io_commit_pc; // @[Core.scala 15:19]
  wire [31:0] wbu_io_commit_inst; // @[Core.scala 15:19]
  wire  commit_valid; // @[Core.scala 30:22]
  wire [31:0] commit_pc; // @[Core.scala 30:22]
  wire  commit_ebreak; // @[Core.scala 30:22]
  reg  valid; // @[Connect.scala 6:24]
  wire  fire = ifu_io_out_valid; // @[Connect.scala 7:27]
  wire  _T_1 = idu_io_in_valid; // @[Decoupled.scala 40:37]
  wire  _GEN_0 = _T_1 ? 1'h0 : valid; // @[Connect.scala 8:23 Connect.scala 8:31 Connect.scala 6:24]
  wire  _GEN_1 = fire | _GEN_0; // @[Connect.scala 9:17 Connect.scala 9:25]
  reg [31:0] idu_io_in_bits_r_pc; // @[Reg.scala 15:16]
  reg [31:0] idu_io_in_bits_r_inst; // @[Reg.scala 15:16]
  reg  valid_1; // @[Connect.scala 6:24]
  wire  fire_1 = idu_io_out_valid; // @[Connect.scala 7:27]
  wire  _T_3 = exu_io_in_valid; // @[Decoupled.scala 40:37]
  wire  _GEN_5 = _T_3 ? 1'h0 : valid_1; // @[Connect.scala 8:23 Connect.scala 8:31 Connect.scala 6:24]
  wire  _GEN_6 = fire_1 | _GEN_5; // @[Connect.scala 9:17 Connect.scala 9:25]
  reg [31:0] exu_io_in_bits_r_pc; // @[Reg.scala 15:16]
  reg [31:0] exu_io_in_bits_r_inst; // @[Reg.scala 15:16]
  reg [63:0] exu_io_in_bits_r_src1_value; // @[Reg.scala 15:16]
  reg [63:0] exu_io_in_bits_r_src2_value; // @[Reg.scala 15:16]
  reg [63:0] exu_io_in_bits_r_rs2_value; // @[Reg.scala 15:16]
  reg [4:0] exu_io_in_bits_r_dest; // @[Reg.scala 15:16]
  reg [1:0] exu_io_in_bits_r_fu_type; // @[Reg.scala 15:16]
  reg [4:0] exu_io_in_bits_r_alu_op; // @[Reg.scala 15:16]
  reg [3:0] exu_io_in_bits_r_lsu_op; // @[Reg.scala 15:16]
  reg [2:0] exu_io_in_bits_r_csr_op; // @[Reg.scala 15:16]
  reg  exu_io_in_bits_r_wen; // @[Reg.scala 15:16]
  reg  exu_io_in_bits_r_rv64; // @[Reg.scala 15:16]
  reg  valid_2; // @[Connect.scala 6:24]
  wire  fire_2 = exu_io_out_valid; // @[Connect.scala 7:27]
  wire  _T_4 = wbu_io_in_valid; // @[Decoupled.scala 40:37]
  wire  _GEN_20 = _T_4 ? 1'h0 : valid_2; // @[Connect.scala 8:23 Connect.scala 8:31 Connect.scala 6:24]
  wire  _GEN_21 = fire_2 | _GEN_20; // @[Connect.scala 9:17 Connect.scala 9:25]
  reg [31:0] wbu_io_in_bits_r_pc; // @[Reg.scala 15:16]
  reg [31:0] wbu_io_in_bits_r_inst; // @[Reg.scala 15:16]
  reg [63:0] wbu_io_in_bits_r_final_result; // @[Reg.scala 15:16]
  reg [4:0] wbu_io_in_bits_r_dest; // @[Reg.scala 15:16]
  reg  wbu_io_in_bits_r_wen; // @[Reg.scala 15:16]
  IFU ifu ( // @[Core.scala 12:19]
    .clock(ifu_clock),
    .reset(ifu_reset),
    .io_imem_en(ifu_io_imem_en),
    .io_imem_addr(ifu_io_imem_addr),
    .io_imem_rdata(ifu_io_imem_rdata),
    .io_out_valid(ifu_io_out_valid),
    .io_out_bits_pc(ifu_io_out_bits_pc),
    .io_out_bits_inst(ifu_io_out_bits_inst),
    .io_br_bus_br_taken(ifu_io_br_bus_br_taken),
    .io_br_bus_br_target(ifu_io_br_bus_br_target),
    .io_csr_br_bus_is_reflush(ifu_io_csr_br_bus_is_reflush),
    .io_csr_br_bus_br_target(ifu_io_csr_br_bus_br_target)
  );
  IDU idu ( // @[Core.scala 13:19]
    .clock(idu_clock),
    .io_in_valid(idu_io_in_valid),
    .io_in_bits_pc(idu_io_in_bits_pc),
    .io_in_bits_inst(idu_io_in_bits_inst),
    .io_out_valid(idu_io_out_valid),
    .io_out_bits_pc(idu_io_out_bits_pc),
    .io_out_bits_inst(idu_io_out_bits_inst),
    .io_out_bits_src1_value(idu_io_out_bits_src1_value),
    .io_out_bits_src2_value(idu_io_out_bits_src2_value),
    .io_out_bits_rs2_value(idu_io_out_bits_rs2_value),
    .io_out_bits_dest(idu_io_out_bits_dest),
    .io_out_bits_fu_type(idu_io_out_bits_fu_type),
    .io_out_bits_alu_op(idu_io_out_bits_alu_op),
    .io_out_bits_lsu_op(idu_io_out_bits_lsu_op),
    .io_out_bits_csr_op(idu_io_out_bits_csr_op),
    .io_out_bits_wen(idu_io_out_bits_wen),
    .io_out_bits_rv64(idu_io_out_bits_rv64),
    .io_br_bus_br_taken(idu_io_br_bus_br_taken),
    .io_br_bus_br_target(idu_io_br_bus_br_target),
    .io_wb_bus_rf_wen(idu_io_wb_bus_rf_wen),
    .io_wb_bus_rf_waddr(idu_io_wb_bus_rf_waddr),
    .io_wb_bus_rf_wdata(idu_io_wb_bus_rf_wdata),
    .io_ex_fwd_is_reflush(idu_io_ex_fwd_is_reflush),
    .io_ex_fwd_fwd_valid(idu_io_ex_fwd_fwd_valid),
    .io_ex_fwd_rf_waddr(idu_io_ex_fwd_rf_waddr),
    .io_ex_fwd_rf_wdata(idu_io_ex_fwd_rf_wdata)
  );
  EXU exu ( // @[Core.scala 14:19]
    .clock(exu_clock),
    .reset(exu_reset),
    .io_dmem_en(exu_io_dmem_en),
    .io_dmem_addr(exu_io_dmem_addr),
    .io_dmem_rdata(exu_io_dmem_rdata),
    .io_dmem_wdata(exu_io_dmem_wdata),
    .io_dmem_wmask(exu_io_dmem_wmask),
    .io_dmem_wen(exu_io_dmem_wen),
    .io_in_valid(exu_io_in_valid),
    .io_in_bits_pc(exu_io_in_bits_pc),
    .io_in_bits_inst(exu_io_in_bits_inst),
    .io_in_bits_src1_value(exu_io_in_bits_src1_value),
    .io_in_bits_src2_value(exu_io_in_bits_src2_value),
    .io_in_bits_rs2_value(exu_io_in_bits_rs2_value),
    .io_in_bits_dest(exu_io_in_bits_dest),
    .io_in_bits_fu_type(exu_io_in_bits_fu_type),
    .io_in_bits_alu_op(exu_io_in_bits_alu_op),
    .io_in_bits_lsu_op(exu_io_in_bits_lsu_op),
    .io_in_bits_csr_op(exu_io_in_bits_csr_op),
    .io_in_bits_wen(exu_io_in_bits_wen),
    .io_in_bits_rv64(exu_io_in_bits_rv64),
    .io_out_valid(exu_io_out_valid),
    .io_out_bits_pc(exu_io_out_bits_pc),
    .io_out_bits_inst(exu_io_out_bits_inst),
    .io_out_bits_final_result(exu_io_out_bits_final_result),
    .io_out_bits_dest(exu_io_out_bits_dest),
    .io_out_bits_wen(exu_io_out_bits_wen),
    .io_forward_is_reflush(exu_io_forward_is_reflush),
    .io_forward_fwd_valid(exu_io_forward_fwd_valid),
    .io_forward_rf_waddr(exu_io_forward_rf_waddr),
    .io_forward_rf_wdata(exu_io_forward_rf_wdata),
    .io_br_bus_is_reflush(exu_io_br_bus_is_reflush),
    .io_br_bus_br_target(exu_io_br_bus_br_target)
  );
  WBU wbu ( // @[Core.scala 15:19]
    .io_in_valid(wbu_io_in_valid),
    .io_in_bits_pc(wbu_io_in_bits_pc),
    .io_in_bits_inst(wbu_io_in_bits_inst),
    .io_in_bits_final_result(wbu_io_in_bits_final_result),
    .io_in_bits_dest(wbu_io_in_bits_dest),
    .io_in_bits_wen(wbu_io_in_bits_wen),
    .io_wb_bus_rf_wen(wbu_io_wb_bus_rf_wen),
    .io_wb_bus_rf_waddr(wbu_io_wb_bus_rf_waddr),
    .io_wb_bus_rf_wdata(wbu_io_wb_bus_rf_wdata),
    .io_commit_valid(wbu_io_commit_valid),
    .io_commit_pc(wbu_io_commit_pc),
    .io_commit_inst(wbu_io_commit_inst)
  );
  Commit commit ( // @[Core.scala 30:22]
    .valid(commit_valid),
    .pc(commit_pc),
    .ebreak(commit_ebreak)
  );
  assign io_imem_en = ifu_io_imem_en; // @[Core.scala 17:15]
  assign io_imem_addr = ifu_io_imem_addr; // @[Core.scala 17:15]
  assign io_dmem_en = exu_io_dmem_en; // @[Core.scala 27:15]
  assign io_dmem_addr = exu_io_dmem_addr; // @[Core.scala 27:15]
  assign io_dmem_wdata = exu_io_dmem_wdata; // @[Core.scala 27:15]
  assign io_dmem_wmask = exu_io_dmem_wmask; // @[Core.scala 27:15]
  assign io_dmem_wen = exu_io_dmem_wen; // @[Core.scala 27:15]
  assign ifu_clock = clock;
  assign ifu_reset = reset;
  assign ifu_io_imem_rdata = io_imem_rdata; // @[Core.scala 17:15]
  assign ifu_io_br_bus_br_taken = idu_io_br_bus_br_taken; // @[Core.scala 18:17]
  assign ifu_io_br_bus_br_target = idu_io_br_bus_br_target; // @[Core.scala 18:17]
  assign ifu_io_csr_br_bus_is_reflush = exu_io_br_bus_is_reflush; // @[Core.scala 19:21]
  assign ifu_io_csr_br_bus_br_target = exu_io_br_bus_br_target; // @[Core.scala 19:21]
  assign idu_clock = clock;
  assign idu_io_in_valid = valid; // @[Connect.scala 14:17]
  assign idu_io_in_bits_pc = idu_io_in_bits_r_pc; // @[Connect.scala 13:16]
  assign idu_io_in_bits_inst = idu_io_in_bits_r_inst; // @[Connect.scala 13:16]
  assign idu_io_wb_bus_rf_wen = wbu_io_wb_bus_rf_wen; // @[Core.scala 22:17]
  assign idu_io_wb_bus_rf_waddr = wbu_io_wb_bus_rf_waddr; // @[Core.scala 22:17]
  assign idu_io_wb_bus_rf_wdata = wbu_io_wb_bus_rf_wdata; // @[Core.scala 22:17]
  assign idu_io_ex_fwd_is_reflush = exu_io_forward_is_reflush; // @[Core.scala 23:17]
  assign idu_io_ex_fwd_fwd_valid = exu_io_forward_fwd_valid; // @[Core.scala 23:17]
  assign idu_io_ex_fwd_rf_waddr = exu_io_forward_rf_waddr; // @[Core.scala 23:17]
  assign idu_io_ex_fwd_rf_wdata = exu_io_forward_rf_wdata; // @[Core.scala 23:17]
  assign exu_clock = clock;
  assign exu_reset = reset;
  assign exu_io_dmem_rdata = io_dmem_rdata; // @[Core.scala 27:15]
  assign exu_io_in_valid = valid_1; // @[Connect.scala 14:17]
  assign exu_io_in_bits_pc = exu_io_in_bits_r_pc; // @[Connect.scala 13:16]
  assign exu_io_in_bits_inst = exu_io_in_bits_r_inst; // @[Connect.scala 13:16]
  assign exu_io_in_bits_src1_value = exu_io_in_bits_r_src1_value; // @[Connect.scala 13:16]
  assign exu_io_in_bits_src2_value = exu_io_in_bits_r_src2_value; // @[Connect.scala 13:16]
  assign exu_io_in_bits_rs2_value = exu_io_in_bits_r_rs2_value; // @[Connect.scala 13:16]
  assign exu_io_in_bits_dest = exu_io_in_bits_r_dest; // @[Connect.scala 13:16]
  assign exu_io_in_bits_fu_type = exu_io_in_bits_r_fu_type; // @[Connect.scala 13:16]
  assign exu_io_in_bits_alu_op = exu_io_in_bits_r_alu_op; // @[Connect.scala 13:16]
  assign exu_io_in_bits_lsu_op = exu_io_in_bits_r_lsu_op; // @[Connect.scala 13:16]
  assign exu_io_in_bits_csr_op = exu_io_in_bits_r_csr_op; // @[Connect.scala 13:16]
  assign exu_io_in_bits_wen = exu_io_in_bits_r_wen; // @[Connect.scala 13:16]
  assign exu_io_in_bits_rv64 = exu_io_in_bits_r_rv64; // @[Connect.scala 13:16]
  assign wbu_io_in_valid = valid_2; // @[Connect.scala 14:17]
  assign wbu_io_in_bits_pc = wbu_io_in_bits_r_pc; // @[Connect.scala 13:16]
  assign wbu_io_in_bits_inst = wbu_io_in_bits_r_inst; // @[Connect.scala 13:16]
  assign wbu_io_in_bits_final_result = wbu_io_in_bits_r_final_result; // @[Connect.scala 13:16]
  assign wbu_io_in_bits_dest = wbu_io_in_bits_r_dest; // @[Connect.scala 13:16]
  assign wbu_io_in_bits_wen = wbu_io_in_bits_r_wen; // @[Connect.scala 13:16]
  assign commit_valid = wbu_io_commit_valid; // @[Core.scala 31:19]
  assign commit_pc = wbu_io_commit_pc; // @[Core.scala 32:16]
  assign commit_ebreak = wbu_io_commit_inst == 32'h100073; // @[Core.scala 33:42]
  always @(posedge clock) begin
    if (reset) begin // @[Connect.scala 6:24]
      valid <= 1'h0; // @[Connect.scala 6:24]
    end else if (ifu_io_csr_br_bus_is_reflush) begin // @[Connect.scala 10:23]
      valid <= 1'h0; // @[Connect.scala 10:30]
    end else begin
      valid <= _GEN_1;
    end
    if (fire) begin // @[Reg.scala 16:19]
      idu_io_in_bits_r_pc <= ifu_io_out_bits_pc; // @[Reg.scala 16:23]
    end
    if (fire) begin // @[Reg.scala 16:19]
      idu_io_in_bits_r_inst <= ifu_io_out_bits_inst; // @[Reg.scala 16:23]
    end
    if (reset) begin // @[Connect.scala 6:24]
      valid_1 <= 1'h0; // @[Connect.scala 6:24]
    end else if (idu_io_ex_fwd_is_reflush) begin // @[Connect.scala 10:23]
      valid_1 <= 1'h0; // @[Connect.scala 10:30]
    end else begin
      valid_1 <= _GEN_6;
    end
    if (fire_1) begin // @[Reg.scala 16:19]
      exu_io_in_bits_r_pc <= idu_io_out_bits_pc; // @[Reg.scala 16:23]
    end
    if (fire_1) begin // @[Reg.scala 16:19]
      exu_io_in_bits_r_inst <= idu_io_out_bits_inst; // @[Reg.scala 16:23]
    end
    if (fire_1) begin // @[Reg.scala 16:19]
      exu_io_in_bits_r_src1_value <= idu_io_out_bits_src1_value; // @[Reg.scala 16:23]
    end
    if (fire_1) begin // @[Reg.scala 16:19]
      exu_io_in_bits_r_src2_value <= idu_io_out_bits_src2_value; // @[Reg.scala 16:23]
    end
    if (fire_1) begin // @[Reg.scala 16:19]
      exu_io_in_bits_r_rs2_value <= idu_io_out_bits_rs2_value; // @[Reg.scala 16:23]
    end
    if (fire_1) begin // @[Reg.scala 16:19]
      exu_io_in_bits_r_dest <= idu_io_out_bits_dest; // @[Reg.scala 16:23]
    end
    if (fire_1) begin // @[Reg.scala 16:19]
      exu_io_in_bits_r_fu_type <= idu_io_out_bits_fu_type; // @[Reg.scala 16:23]
    end
    if (fire_1) begin // @[Reg.scala 16:19]
      exu_io_in_bits_r_alu_op <= idu_io_out_bits_alu_op; // @[Reg.scala 16:23]
    end
    if (fire_1) begin // @[Reg.scala 16:19]
      exu_io_in_bits_r_lsu_op <= idu_io_out_bits_lsu_op; // @[Reg.scala 16:23]
    end
    if (fire_1) begin // @[Reg.scala 16:19]
      exu_io_in_bits_r_csr_op <= idu_io_out_bits_csr_op; // @[Reg.scala 16:23]
    end
    if (fire_1) begin // @[Reg.scala 16:19]
      exu_io_in_bits_r_wen <= idu_io_out_bits_wen; // @[Reg.scala 16:23]
    end
    if (fire_1) begin // @[Reg.scala 16:19]
      exu_io_in_bits_r_rv64 <= idu_io_out_bits_rv64; // @[Reg.scala 16:23]
    end
    if (reset) begin // @[Connect.scala 6:24]
      valid_2 <= 1'h0; // @[Connect.scala 6:24]
    end else begin
      valid_2 <= _GEN_21;
    end
    if (fire_2) begin // @[Reg.scala 16:19]
      wbu_io_in_bits_r_pc <= exu_io_out_bits_pc; // @[Reg.scala 16:23]
    end
    if (fire_2) begin // @[Reg.scala 16:19]
      wbu_io_in_bits_r_inst <= exu_io_out_bits_inst; // @[Reg.scala 16:23]
    end
    if (fire_2) begin // @[Reg.scala 16:19]
      wbu_io_in_bits_r_final_result <= exu_io_out_bits_final_result; // @[Reg.scala 16:23]
    end
    if (fire_2) begin // @[Reg.scala 16:19]
      wbu_io_in_bits_r_dest <= exu_io_out_bits_dest; // @[Reg.scala 16:23]
    end
    if (fire_2) begin // @[Reg.scala 16:19]
      wbu_io_in_bits_r_wen <= exu_io_out_bits_wen; // @[Reg.scala 16:23]
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
  _RAND_0 = {1{`RANDOM}};
  valid = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  idu_io_in_bits_r_pc = _RAND_1[31:0];
  _RAND_2 = {1{`RANDOM}};
  idu_io_in_bits_r_inst = _RAND_2[31:0];
  _RAND_3 = {1{`RANDOM}};
  valid_1 = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  exu_io_in_bits_r_pc = _RAND_4[31:0];
  _RAND_5 = {1{`RANDOM}};
  exu_io_in_bits_r_inst = _RAND_5[31:0];
  _RAND_6 = {2{`RANDOM}};
  exu_io_in_bits_r_src1_value = _RAND_6[63:0];
  _RAND_7 = {2{`RANDOM}};
  exu_io_in_bits_r_src2_value = _RAND_7[63:0];
  _RAND_8 = {2{`RANDOM}};
  exu_io_in_bits_r_rs2_value = _RAND_8[63:0];
  _RAND_9 = {1{`RANDOM}};
  exu_io_in_bits_r_dest = _RAND_9[4:0];
  _RAND_10 = {1{`RANDOM}};
  exu_io_in_bits_r_fu_type = _RAND_10[1:0];
  _RAND_11 = {1{`RANDOM}};
  exu_io_in_bits_r_alu_op = _RAND_11[4:0];
  _RAND_12 = {1{`RANDOM}};
  exu_io_in_bits_r_lsu_op = _RAND_12[3:0];
  _RAND_13 = {1{`RANDOM}};
  exu_io_in_bits_r_csr_op = _RAND_13[2:0];
  _RAND_14 = {1{`RANDOM}};
  exu_io_in_bits_r_wen = _RAND_14[0:0];
  _RAND_15 = {1{`RANDOM}};
  exu_io_in_bits_r_rv64 = _RAND_15[0:0];
  _RAND_16 = {1{`RANDOM}};
  valid_2 = _RAND_16[0:0];
  _RAND_17 = {1{`RANDOM}};
  wbu_io_in_bits_r_pc = _RAND_17[31:0];
  _RAND_18 = {1{`RANDOM}};
  wbu_io_in_bits_r_inst = _RAND_18[31:0];
  _RAND_19 = {2{`RANDOM}};
  wbu_io_in_bits_r_final_result = _RAND_19[63:0];
  _RAND_20 = {1{`RANDOM}};
  wbu_io_in_bits_r_dest = _RAND_20[4:0];
  _RAND_21 = {1{`RANDOM}};
  wbu_io_in_bits_r_wen = _RAND_21[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
endmodule
module Ram2r1w(
  input         clock,
  input         io_imem_en,
  input  [63:0] io_imem_addr,
  output [63:0] io_imem_rdata,
  input         io_dmem_en,
  input  [63:0] io_dmem_addr,
  output [63:0] io_dmem_rdata,
  input  [63:0] io_dmem_wdata,
  input  [63:0] io_dmem_wmask,
  input         io_dmem_wen
);
  wire  mem_clk; // @[Ram.scala 73:19]
  wire  mem_imem_en; // @[Ram.scala 73:19]
  wire [63:0] mem_imem_addr; // @[Ram.scala 73:19]
  wire [31:0] mem_imem_data; // @[Ram.scala 73:19]
  wire  mem_dmem_en; // @[Ram.scala 73:19]
  wire [63:0] mem_dmem_addr; // @[Ram.scala 73:19]
  wire [63:0] mem_dmem_rdata; // @[Ram.scala 73:19]
  wire [63:0] mem_dmem_wdata; // @[Ram.scala 73:19]
  wire [63:0] mem_dmem_wmask; // @[Ram.scala 73:19]
  wire  mem_dmem_wen; // @[Ram.scala 73:19]
  ram_2r1w mem ( // @[Ram.scala 73:19]
    .clk(mem_clk),
    .imem_en(mem_imem_en),
    .imem_addr(mem_imem_addr),
    .imem_data(mem_imem_data),
    .dmem_en(mem_dmem_en),
    .dmem_addr(mem_dmem_addr),
    .dmem_rdata(mem_dmem_rdata),
    .dmem_wdata(mem_dmem_wdata),
    .dmem_wmask(mem_dmem_wmask),
    .dmem_wen(mem_dmem_wen)
  );
  assign io_imem_rdata = {{32'd0}, mem_imem_data}; // @[Ram.scala 77:21]
  assign io_dmem_rdata = mem_dmem_rdata; // @[Ram.scala 80:21]
  assign mem_clk = clock; // @[Ram.scala 74:21]
  assign mem_imem_en = io_imem_en; // @[Ram.scala 75:21]
  assign mem_imem_addr = io_imem_addr; // @[Ram.scala 76:21]
  assign mem_dmem_en = io_dmem_en; // @[Ram.scala 78:21]
  assign mem_dmem_addr = io_dmem_addr; // @[Ram.scala 79:21]
  assign mem_dmem_wdata = io_dmem_wdata; // @[Ram.scala 81:21]
  assign mem_dmem_wmask = io_dmem_wmask; // @[Ram.scala 82:21]
  assign mem_dmem_wen = io_dmem_wen; // @[Ram.scala 83:21]
endmodule
module SimTop(
  input   clock,
  input   reset
);
  wire  core_clock; // @[SimTop.scala 8:20]
  wire  core_reset; // @[SimTop.scala 8:20]
  wire  core_io_imem_en; // @[SimTop.scala 8:20]
  wire [63:0] core_io_imem_addr; // @[SimTop.scala 8:20]
  wire [63:0] core_io_imem_rdata; // @[SimTop.scala 8:20]
  wire  core_io_dmem_en; // @[SimTop.scala 8:20]
  wire [63:0] core_io_dmem_addr; // @[SimTop.scala 8:20]
  wire [63:0] core_io_dmem_rdata; // @[SimTop.scala 8:20]
  wire [63:0] core_io_dmem_wdata; // @[SimTop.scala 8:20]
  wire [63:0] core_io_dmem_wmask; // @[SimTop.scala 8:20]
  wire  core_io_dmem_wen; // @[SimTop.scala 8:20]
  wire  mem_clock; // @[SimTop.scala 10:19]
  wire  mem_io_imem_en; // @[SimTop.scala 10:19]
  wire [63:0] mem_io_imem_addr; // @[SimTop.scala 10:19]
  wire [63:0] mem_io_imem_rdata; // @[SimTop.scala 10:19]
  wire  mem_io_dmem_en; // @[SimTop.scala 10:19]
  wire [63:0] mem_io_dmem_addr; // @[SimTop.scala 10:19]
  wire [63:0] mem_io_dmem_rdata; // @[SimTop.scala 10:19]
  wire [63:0] mem_io_dmem_wdata; // @[SimTop.scala 10:19]
  wire [63:0] mem_io_dmem_wmask; // @[SimTop.scala 10:19]
  wire  mem_io_dmem_wen; // @[SimTop.scala 10:19]
  Core core ( // @[SimTop.scala 8:20]
    .clock(core_clock),
    .reset(core_reset),
    .io_imem_en(core_io_imem_en),
    .io_imem_addr(core_io_imem_addr),
    .io_imem_rdata(core_io_imem_rdata),
    .io_dmem_en(core_io_dmem_en),
    .io_dmem_addr(core_io_dmem_addr),
    .io_dmem_rdata(core_io_dmem_rdata),
    .io_dmem_wdata(core_io_dmem_wdata),
    .io_dmem_wmask(core_io_dmem_wmask),
    .io_dmem_wen(core_io_dmem_wen)
  );
  Ram2r1w mem ( // @[SimTop.scala 10:19]
    .clock(mem_clock),
    .io_imem_en(mem_io_imem_en),
    .io_imem_addr(mem_io_imem_addr),
    .io_imem_rdata(mem_io_imem_rdata),
    .io_dmem_en(mem_io_dmem_en),
    .io_dmem_addr(mem_io_dmem_addr),
    .io_dmem_rdata(mem_io_dmem_rdata),
    .io_dmem_wdata(mem_io_dmem_wdata),
    .io_dmem_wmask(mem_io_dmem_wmask),
    .io_dmem_wen(mem_io_dmem_wen)
  );
  assign core_clock = clock;
  assign core_reset = reset;
  assign core_io_imem_rdata = mem_io_imem_rdata; // @[SimTop.scala 11:15]
  assign core_io_dmem_rdata = mem_io_dmem_rdata; // @[SimTop.scala 12:15]
  assign mem_clock = clock;
  assign mem_io_imem_en = core_io_imem_en; // @[SimTop.scala 11:15]
  assign mem_io_imem_addr = core_io_imem_addr; // @[SimTop.scala 11:15]
  assign mem_io_dmem_en = core_io_dmem_en; // @[SimTop.scala 12:15]
  assign mem_io_dmem_addr = core_io_dmem_addr; // @[SimTop.scala 12:15]
  assign mem_io_dmem_wdata = core_io_dmem_wdata; // @[SimTop.scala 12:15]
  assign mem_io_dmem_wmask = core_io_dmem_wmask; // @[SimTop.scala 12:15]
  assign mem_io_dmem_wen = core_io_dmem_wen; // @[SimTop.scala 12:15]
endmodule
