STUID = ysyx_220091
STUNAME = 冯浩原

# DO NOT modify the following code!!!

GITFLAGS = -q --author='tracer-ysyx2204 <tracer@ysyx.org>' --no-verify --allow-empty

# prototype: git_commit(msg)
define git_commit
	-@git add .. -A --ignore-errors
	-@while (test -e .git/index.lock); do sleep 0.1; done
	-@(echo "> $(1)" && echo $(STUID) $(STUNAME) && uname -a && uptime) | git commit -F - $(GITFLAGS)
	-@sync
endef

run:
	@echo $(call git_commit, "sim RTL")
	verilator -Wall --cc --exe --build --trace ./csrc/main.cpp ./vsrc/top.v 
	./obj_dir/Vtop

wave:
	@echo $(call git_commit, "check waveform")
	gtkwave waveform.vcd