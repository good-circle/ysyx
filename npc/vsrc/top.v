module top(
    input clk,
    input [31:0] inst,
    output reg [63:0] pc
);

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

wire br_taken;
wire [63:0] br_target;

wire [63:0] adder_src1;
wire [63:0] adder_src2;
wire [63:0] adder_result;

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

assign br_taken = jal | jalr;
assign br_target = jal ? pc + J_extension : {adder_result[63:1], 1'b0};

assign I_Type = addi | jalr;
//assign R_Type = 0;
assign S_Type = sd;
assign B_Type = 0;
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
assign rf_wdata  = {64{jal | jalr}} & (pc + 4)
				 | {64{lui}}        & U_extension
				 | {64{auipc}}      & (pc + U_extension)
				 | {64{addi}}       & adder_result;
regfile u_regfile(
    .clk    (clk      ),
    .raddr1 (rf_raddr1),
    .rdata1 (rf_rdata1),
    .raddr2 (rf_raddr2),
    .rdata2 (0),
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
