module Commit(
    input        valid ,
    input [31:0] pc    ,
    input        ebreak
);

export "DPI-C" function finish;
function bit finish();
    return ebreak;
endfunction

export "DPI-C" function commit;
function bit commit();
    return valid;
endfunction

import "DPI-C" function void set_pc(input logic [31:0] a);
initial set_pc(pc);

endmodule
