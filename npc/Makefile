IMG ?=
override ARGS ?= -b -d $(REF_SO)

REF_SO := $(NEMU_HOME)/build/riscv64-nemu-interpreter-so

SIMULATOR_FILE := $(wildcard ./csrc/*.cpp) $(wildcard ./csrc/*.cc)
VERILOG_FILE := $(wildcard ./vsrc/*.v)

$(REF_SO):
	$(MAKE) -C $(NEMU_HOME) ISA=riscv64 SHARE=1 ENGINE=interpreter

CXXFLAGS += $(shell llvm-config --cxxflags) -fPIE -Wall
LIBS += $(shell llvm-config --libs)

all: sim wave

# verilator -Wno-lint --cc --exe --build --top-module MySimTop --trace -LDFLAGS "-lreadline -ldl -lSDL2 $(LIBS)" -CFLAGS "$(CXXFLAGS)" $(wildcard ./csrc/*.cpp) $(wildcard ./csrc/*.cc) $(wildcard ./vsrc/*.v)


sim:
	$(call git_commit, "sim RTL")
	verilator -Wno-lint --cc --exe --build --top-module MySimTop --trace-fst -LDFLAGS "-lreadline -ldl -lSDL2 $(LIBS)" -CFLAGS "$(CXXFLAGS)" $(SIMULATOR_FILE) $(VERILOG_FILE)
	./obj_dir/VMySimTop $(ARGS) $(IMG)

wave:
	$(call git_commit, "check waveform")
	gtkwave waveform.fst

clean:
	-rm -rf ./obj_dir
	-rm waveform.fst

include ../Makefile
