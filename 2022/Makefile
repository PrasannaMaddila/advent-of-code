CC=g++
FLAGS=-Wall -O2
D=1

build: day_$(D).cpp
	@echo "Building Day ${D}"
	@$(CC) day_${D}.cpp $(FLAGS) -o day_${D}.o 
run: build day_${D}.o day_${D}.cpp
	@echo "Running Day ${D}"
	@echo "----------------------------------------"
	@ ./day_${D}.o  < inputs/input_${D}.txt
	@echo "----------------------------------------"

test: build day_${D}.o day_${D}.cpp
	@echo "Running Day ${D}"
	@echo "----------------------------------------"
	@ ./day_${D}.o  < inputs/input_${D}_test.txt
	@echo "----------------------------------------"

clean:
	rm *.o
