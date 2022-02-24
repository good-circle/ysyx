#include <nvboard.h>
#include "Vtop.h"

void nvboard_bind_all_pins(Vtop* top){
	nvboard_bind_input_pin(SW0, &top->a);
	nvboard_bind_input_pin(SW1, &top->b);
	nvboard_bind_output_pin(LD0, &top->f);
}