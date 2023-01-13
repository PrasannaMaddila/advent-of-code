CC=g++
VER=c++20
FLAGS=
D=1

build: day_$(D).cpp
	$(CC) --std=$(VER) $(FLAGS) -o day_${D}.o day_${D}.cpp

run: build
	./day_${D}.o  < inputs/input_${D}.txt

clean:
	rm *.o
