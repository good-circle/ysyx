all:
	@echo "Write this Makefile by your self."

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall --cc --exe --build --trace ./csrc/main.cpp ./vsrc/top.v 
	./obj_dir/Vtop

include ../Makefile
