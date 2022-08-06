IMG ?=
override ARGS ?= -b -d $(REF_SO)

REF_SO := $(NEMU_HOME)/build/riscv64-nemu-interpreter-so

$(REF_SO):
	$(MAKE) -C $(NEMU_HOME) ISA=riscv64 SHARE=1 ENGINE=interpreter

CXXFLAGS += $(shell llvm-config --cxxflags) -fPIE
LIBS += $(shell llvm-config --libs)

all: sim wave

sim:
	$(call git_commit, "sim RTL") 
	verilator -Wno-lint --cc --exe --build --top-module SimTop -LDFLAGS "-lreadline -ldl $(LIBS)" -CFLAGS "$(CXXFLAGS)" $(wildcard ./csrc/*.cpp) $(wildcard ./csrc/*.cc) $(wildcard ./vsrc/*.v)
	./obj_dir/VTop $(ARGS) $(IMG) 

wave:
	$(call git_commit, "check waveform")
	gtkwave waveform.vcd

include ../Makefile
