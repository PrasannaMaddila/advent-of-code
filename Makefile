# Makefile: Advent-of-Code
# Author  : Prasanna M.S.S 
# Date    : 5 Feb, 2022
# This Makefile is meant to simplify my builds for Advent of Code.

# Manage the compiler flags.
CC=g++
FLAGS=-Wall -O2 -fmessage-length=100 -march=native -fdiagnostics-show-location=every-line

DAY=1
YEAR=2022
TUNIT=ms

# Define the input/output directories
UTILS_DIR=utils
BUILD_DIR=build
INPUT_DIR=inputs

.PHONY: build run test build_bench bench perf

build: ./$(YEAR)/day_$(DAY).hpp
	@echo "Building Day $(DAY)"
	@$(CC) $(FLAGS) ./$(UTILS_DIR)/exec_main.cpp \
		 -DHEADER=\"../$(YEAR)/day_$(DAY).hpp\"  \
		 -o ./$(BUILD_DIR)/day_$(DAY).out

run: build 
	@echo "Running Day $(DAY)"
	@echo "-----------------------------------------------------"
	@ ./$(BUILD_DIR)/day_$(DAY).out ./$(YEAR)/$(INPUT_DIR)/input_$(DAY).txt
	@echo "-----------------------------------------------------"

test: build 
	@echo "Testing Day $(DAY)"
	@echo "-----------------------------------------------------"
	@ ./$(BUILD_DIR)/day_$(DAY).out ./$(YEAR)/$(INPUT_DIR)/input_$(DAY)_test.txt
	@echo "-----------------------------------------------------"

build_bench: ./$(YEAR)/day_$(DAY).hpp
	@echo "Building bench version for Day $(DAY)"
	@$(CC) $(UTILS_DIR)/bench_main.cpp          \
		$(FLAGS) -isystem benchmark/include     \
		-DHEADER=\"../$(YEAR)/day_$(DAY).hpp\"  \
		-Lbenchmark/build/src -lbenchmark       \
		-lpthread -o ./$(BUILD_DIR)/day_bench_$(DAY).out

bench: build_bench 
	@echo "Running bench version for Day $(DAY)\n"
	@sudo cpupower frequency-set --governor performance > /dev/null
	@echo "-----------------------------------------------------"
	@./$(BUILD_DIR)/day_bench_$(DAY).out ./$(YEAR)/$(INPUT_DIR)/input_$(DAY).txt \
		--benchmark_time_unit=$(TUNIT) \
	@echo "-----------------------------------------------------"
	@sudo cpupower frequency-set --governor performance > /dev/null

perf: ./$(BUILD_DIR)/day_$(DAY).out
	@echo "Running performance tests"
	perf record -g ./$(BUILD_DIR)/day_$(DAY).out $(YEAR)/$(INPUT_DIR)/input_$(DAY).txt
	perf report -g

day: 
	@echo "Creating template for Day $(YEAR)/$(DAY)"
	@cp .day_template $(YEAR)/day_$(DAY).hpp

clean:
	rm ./$(BUILD_DIR)/*.out
	rm ./perf.data*
	rm ./*.annotation
