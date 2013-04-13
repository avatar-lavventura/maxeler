CPU_CODE_DIR="../../CPUCode"

# delegates any target to the CPU Code Makefile
%:
	make -C $(CPU_CODE_DIR) RUNRULE="DfeLargeHeap" $@

# default target
all:
	make -C $(CPU_CODE_DIR) RUNRULE="DfeLargeHeap"
