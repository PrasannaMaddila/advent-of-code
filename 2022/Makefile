CC=g++
FLAGS=-Wall -O2 -std=c++11
D=1

build: day_$(D).cpp
	@echo "Building Day ${D}"
	@$(CC) $(FLAGS) -o day_${D}.out day_${D}.cpp 

run: build day_${D}.out day_${D}.cpp
	@echo "Running Day ${D}"
	@echo "----------------------------------------"
	@ ./day_${D}.out inputs/input_${D}.txt
	@echo "----------------------------------------"

test: build day_${D}.out day_${D}.cpp
	@echo "Testing Day ${D}"
	@echo "----------------------------------------"
	@ ./day_${D}.out inputs/input_${D}_test.txt
	@echo "----------------------------------------"

day: 
	@echo "Creating template for Day ${D}"
	@cp .day_cpp day_${D}.cpp

clean:
	rm *.out
