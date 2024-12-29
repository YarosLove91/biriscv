###############################################################################
## Tool paths
###############################################################################
VERILATOR_SRC ?= /usr/share/verilator/include
SYSTEMC_HOME  ?= /usr/local/systemc-3.0.1

TEST_IMAGE ?= $(abspath ./test.elf)

export VERILATOR_SRC
export SYSTEMC_HOME

ifeq (,$(wildcard $(VERILATOR_SRC)))
	${error VERILATOR_SRC must be set to VERILATOR_INSTALL/include}
endif
ifeq (,$(wildcard $(SYSTEMC_HOME)))
	${error SYSTEMC_HOME must be set}
endif

###############################################################################
## Multithreading
###############################################################################

NUM_THREADS := $(shell nproc)

ifeq ($(NUM_THREADS), 0)
	NUM_THREADS := 2
else
	NUM_THREADS := $(shell echo "$$(( $(NUM_THREADS) - 2 ))")
endif

###############################################################################
## Makefile
###############################################################################
.PHONY: build
all: build

build:
	make -f makefile.generate_verilated	-j $(NUM_THREADS)
	make -f makefile.build_verilated	-j $(NUM_THREADS)
	make -f makefile.build_sysc_tb		-j $(NUM_THREADS)

clean:
	make -f makefile.generate_verilated
	make -f makefile.build_verilated $@
	make -f makefile.build_sysc_tb $@
	-rm -rf *.vcd verilated

run: build
	./build/test.x -f $(TEST_IMAGE)