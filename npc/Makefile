IMG ?=
override ARGS ?=

all: sim wave

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall --cc --exe --build --trace --top-module top -FI $(wildcard ./csrc/include/*.h) $(wildcard ./csrc/*.cpp) $(wildcard ./vsrc/*.v)
	./obj_dir/Vtop $(ARGS) $(IMG) 

wave:
	$(call git_commit, "check waveform")
	gtkwave waveform.vcd

include ../Makefile
