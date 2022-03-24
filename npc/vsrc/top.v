module top(
    input clk,
    input rst,
    output reg [63:0] pc
);

wire [63:0] inst_2;
wire [31:0] inst;
//wire [6:0] funct7;
wire [4:0] rs2;
wire [4:0] rs1;
wire [2:0] funct3;
wire [4:0] rd;
wire [6:0] opcode;

wire [63:0] I_extension;
wire [63:0] S_extension;
wire [63:0] B_extension;
wire [63:0] U_extension;
wire [63:0] J_extension;
wire [63:0] imm_extension;

wire addi;  
wire auipc;
wire lui;
wire jal;
wire jalr;
wire sd;
wire ebreak;
wire sltiu;
wire beq;
wire bne;

wire br_taken;
wire [63:0] br_target;

wire [63:0] alu_src1;
wire [63:0] alu_src2;
wire [63:0] alu_result;

wire [ 4:0] rf_raddr1;
wire [63:0] rf_rdata1;
wire [ 4:0] rf_raddr2;
wire [63:0] rf_rdata2;
wire        rf_we    ;      
wire [ 4:0] rf_waddr ;
wire [63:0] rf_wdata ;

wire I_Type;
//wire R_Type;
wire S_Type;
wire B_Type;
wire U_Type;
wire J_Type;

//assign funct7  = inst[31:25];
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
assign ebreak = inst == 32'h00100073;

assign sltiu = funct3 == 3'b011 && opcode == 7'b0010011;
assign beq = funct3 == 3'b000 && opcode == 7'b1100011;
assign bne = funct3 == 3'b001 && opcode == 7'b1100011;

assign br_taken = jal | jalr
                | beq & (rf_rdata1 == rf_rdata2)
                | bne & (rf_rdata1 != rf_rdata2);
assign br_target = jalr ? {alu_result[63:1], 1'b0} : pc + imm_extension;

assign I_Type = addi | jalr | sltiu;
//assign R_Type = 0;
assign S_Type = sd;
assign B_Type = beq | bne;
assign U_Type = auipc | lui;
assign J_Type = jal;

assign I_extension = {{52{inst[31]}} , inst[31:20]};
assign S_extension = {{52{inst[31]}} , inst[31:25], inst[11:7]};
assign B_extension = {{52{inst[31]}} , inst[7],     inst[30:25], inst[11:8] , 1'b0};
assign J_extension = {{44{inst[31]}} , inst[19:12], inst[20],    inst[30:21], 1'b0};
assign U_extension = {{32{inst[31]}} , inst[31:12], 12'b0};
assign imm_extension = {64{I_Type}} & I_extension
					 | {64{S_Type}} & S_extension
					 | {64{B_Type}} & B_extension
					 | {64{J_Type}} & J_extension
					 | {64{U_Type}} & U_extension;


always @(posedge clk) begin
    if(rst) pc <= 64'h0000000080000000;
    else pc <= br_taken ? br_target : pc + 4;
end

wire inst_ready = !rst;


assign inst = pc[2] ? inst_2[63:32] : inst_2[31:0];


assign alu_src1 = jal ? pc : rf_rdata1;
assign alu_src2 = imm_extension;
wire [1:0] aluop;
assign aluop[0] = addi | jalr | S_Type;
assign aluop[1] = sltiu;
alu u_alu(
    .src1 (alu_src1),
    .src2 (alu_src2),
    .aluop (aluop),
    .result (alu_result)
);

assign rf_waddr  =  rd;
assign rf_raddr1 =  rs1;
assign rf_raddr2 =  rs2;
assign rf_we = !S_Type && !B_Type;
assign rf_wdata  = {64{jal | jalr}} & (pc + 4)
				 | {64{lui}}        & U_extension
				 | {64{auipc}}      & (pc + U_extension)
				 | {64{addi}}       & alu_result
                 | {64{sltiu}}      & alu_result;
                 
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



wire [63:0] mem_raddr;
wire mem_read;
wire [63:0] mem_waddr;
wire [63:0] mem_wdata;
wire [7:0] mem_wmask;
wire mem_write;
assign mem_raddr = 64'h0000000080001000;
assign mem_read = !rst;
assign mem_waddr = 64'h0000000080001000;
assign mem_wdata = I_Type ? 64'h1234567887654321 : S_Type ? 64'h8765432112345678 : U_Type ? 64'h0000000000000000 : 64'h1111111111111111;
assign mem_wmask = I_Type ? 8'b01010101 : S_Type ? 8'b10101010 : U_Type ? 8'b00111100 : 8'b11000011;
assign mem_write = !rst;

wire [63:0] mem_rdata;

always @(*) begin
  $display("%h",mem_rdata);
end

blackbox u_blackbox(
    .mem_raddr (mem_raddr),
    .mem_read  (mem_read),
    .mem_waddr (mem_waddr),
    .mem_wdata (mem_wdata),
    .mem_wmask (mem_wmask),
    .mem_write (mem_write),
    .mem_rdata (mem_rdata),
    .inst_ready(inst_ready),
    .pc        (pc),
    .inst_2    (inst_2),
    .ebreak    (ebreak)
);

endmodule
