all: sim wave

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall --cc --exe --build --trace ./csrc/main.cpp ./vsrc/top.v 
	./obj_dir/Vtop

wave:
	$(call git_commit, "check waveform")
	gtkwave waveform.vcd

include ../Makefile
