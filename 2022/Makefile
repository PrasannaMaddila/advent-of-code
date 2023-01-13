CC=g++
VER=c++20
FLAGS=
D=1

build: day_$(D).cpp
	@echo "Building Day ${D}"
	@$(CC) --std=$(VER) $(FLAGS) -o day_${D}.o day_${D}.cpp

run: build
	@echo "Running Day ${D}"
	@echo "----------------------------------------"
	@./day_${D}.o  < inputs/input_${D}.txt
	@echo "----------------------------------------"

clean:
	rm *.o
