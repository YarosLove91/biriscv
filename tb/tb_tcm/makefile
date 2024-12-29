###############################################################################
## Tool paths
###############################################################################
VERILATOR_SRC ?= /usr/share/verilator/include
SYSTEMC_HOME  ?= /usr/local/systemc-3.0.1

TEST_IMAGE ?= $(abspath ./test.elf)

# Use with caution ! It is recommended to use setup_environmant.h with settings 
# for your system
#LD_LIBRARY_PATH ?= $(SYSTEMC_HOME)/lib-linux64
#export LD_LIBRARY_PATH

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
.PHONY: build set_path get_path clean run all

all: build

print_help:
	@echo " Using make:"
	@echo " make build - Build project"
	@echo " make clean - Clean the generated files"
	@echo " make set_path - Set environment variables"
	@echo " make get_path - Show current environment variables"
	@echo " make help - Show this message"

set_path:
	@echo "Running setup_environment.sh..."
	@./setup_environment.sh
	@echo "Environment setup complete."

get_path:
	@echo "Current environment variables:"
	@echo "LD_LIBRARY_PATH=$(LD_LIBRARY_PATH)"

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

.DEFAULT_GOAL := print_help