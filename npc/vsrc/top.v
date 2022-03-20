module top(
    input clk,
    input [31:0] inst,
    output reg [63:0] pc
);

wire [6:0] funct7;
wire [4:0] rs2;
wire [4:0] rs1;
wire [2:0] funct3;
wire [4:0] rd;
wire [6:0] opcode;

wire [31:0] I_extension;
wire [31:0] S_extension;
wire [31:0] B_extension;
wire [31:0] U_extension;
wire [31:0] J_extension;
wire [31:0] imm_extension;

wire addi;  
wire auipc;
wire lui;
wire jal;
wire jalr;
wire sd;

wire br_taken;
wire [63:0] br_target;

wire [63:0] adder_src1;
wire [63:0] adder_src2;
wire [63:0] adder_result;

wire [ 4:0] rf_raddr1;
wire [31:0] rf_rdata1;
wire [ 4:0] rf_raddr2;
wire [31:0] rf_rdata2;
wire        rf_we    ;      
wire [ 4:0] rf_waddr ;
wire [31:0] rf_wdata ;

wire I_Type;
wire R_Type;
wire S_Type;
wire B_Type;
wire U_Type;
wire J_Type;

assign funct7  = inst[31:25];
assign rs2     = inst[24:20];
assign rs1     = inst[19:15];
assign funct3  = inst[14:12];
assign rd      = inst[11:7];
assign opcode  = inst[6:0];

assign addi = funct3 == 3'b000 && opcode == 7'b0010011;
assign auipc = opcode == 7'b0010111;
assign lui = opcode == 7'b0110111;
assign jal = opcode == 7'b1101111;
assign jalr = funct3 == 3'b000 && opcode == 7'b1100111;
assign sd = funct3 == 3'b011 && opcode == 7'b0100011;

assign br_taken = jal | jalr;
assign br_target = jal ? pc + J_extension : {adder_result[31:1], 1'b0};

assign I_Type = addi | jalr;
assign R_Type = 0;
assign S_Type = sd;
assign B_Type = 0;
assign U_Type = auipc | lui;
assign J_Type = jal;

assign I_extension = {{20{Instruction_Fact[31]}} , Instruction_Fact[31:20]};
assign S_extension = {{20{Instruction_Fact[31]}} , Instruction_Fact[31:25], Instruction_Fact[11:7]};
assign B_extension = {{20{Instruction_Fact[31]}} , Instruction_Fact[7],     Instruction_Fact[30:25], Instruction_Fact[11:8] , 1'b0};
assign J_extension = {{12{Instruction_Fact[31]}} , Instruction_Fact[19:12], Instruction_Fact[20],    Instruction_Fact[30:21], 1'b0};
assign U_extension = {    Instruction_Fact[31:12], 12'b0};
assign imm_extension = {32{I_Type}} & I_extension
					 | {32{S_Type}} & S_extension
					 | {32{B_Type}} & B_extension
					 | {32{J_Type}} & J_extension
					 | {32{U_Type}} & U_extension;


always @(posedge clk) begin
    pc <= br_taken ? br_target : pc + 4;
end

assign adder_src1 = jal ? pc : rf_rdata1;
assign adder_src2 = imm_extension;
adder u_adder(
    .src1 (adder_src1),
    .src2 (adder_src2),
    .result (adder_result)
);

assign rf_waddr  =  rd;
assign rf_raddr1 =  rs1;
assign rf_raddr2 =  rs2;
assign rf_we = !sd;
assign rf_wdata  = {32{jal | jalr}} & (pc + 4)
				 | {32{lui}}        & U_extension
				 | {32{auipc}}      & (pc + U_extension)
				 | {32{addi}}       & adder_result;
regfile u_regfile(
    .clk    (clk      ),
    .raddr1 (rf_raddr1),
    .rdata1 (rf_rdata1),
    .raddr2 (rf_raddr2),
    .rdata2 (rf_rdata2),
    .we     (rf_we    ),
    .waddr  (rf_waddr ),
    .wdata  (rf_wdata )
);

export "DPI-C" task finish;
task finish;
    output bit is_finish;
    is_finish = (inst == 32'h0);
endtask

endmodule

module regfile(
    input         clk,

    input  [ 4:0] raddr1,
    output [63:0] rdata1,

    input  [ 4:0] raddr2,
    output [63:0] rdata2,

    input         we    ,      
    input  [ 4:0] waddr ,
    input  [63:0] wdata
);

reg [63:0] rf [31:0];

always @(posedge clk) begin
    if (we) rf[waddr] <= wdata;
end

assign rdata1 = (raddr1 == 5'b0) ? 64'b0 : rf[raddr1];
assign rdata2 = (raddr2 == 5'b0) ? 64'b0 : rf[raddr2];

endmodule

module adder(
    input [63:0] src1,
    input [63:0] src2,
    output [63:0] result
);

assign result = src1 + src2;

endmodule