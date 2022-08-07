module Commit(
    input        valid ,
    input [31:0] pc    ,
    input        ebreak
);

export "DPI-C" function export_finish;
function byte export_finish();
    return ebreak;
endfunction

export "DPI-C" function export_commit;
function byte export_commit();
    return valid;
endfunction

import "DPI-C" function void set_pc(input longint pc);
initial set_pc(pc);

always begin
    $display("%lx\n", pc);
end

endmodule
