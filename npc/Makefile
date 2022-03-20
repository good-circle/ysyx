IMG ?=

all: sim wave

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall --cc --exe --build --trace --top-module top ./csrc/main.cpp ./vsrc/top.v 
	./obj_dir/Vtop $(IMG) 

wave:
	$(call git_commit, "check waveform")
	gtkwave waveform.vcd

include ../Makefile
