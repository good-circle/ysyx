IMG ?=
override ARGS ?=

REF_SO := $(NEMU_HOME)/build/riscv64-nemu-so

all: sim wave

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall --cc --exe --build --trace --top-module top -LDFLAGS -lreadline $(wildcard ./csrc/*.cpp) $(wildcard ./vsrc/*.v)
	./obj_dir/Vtop $(ARGS) $(IMG) 

wave:
	$(call git_commit, "check waveform")
	gtkwave waveform.vcd

include ../Makefile
