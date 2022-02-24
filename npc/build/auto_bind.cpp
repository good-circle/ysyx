#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top){
	nvboard_bind_input_pin(CLK, &top->clk);
	nvboard_bind_input_pin(RST, &top->rst);
	vector<uint16_t> led_pins{
		LD15, LD14, LD13, LD12, 
		LD11, LD10, LD9, LD8, 
		LD7, LD6, LD5, LD4, 
		LD3, LD2, LD1, LD0
	};
	nvboard_bind_output_pin(led_pins, &top->led);
}