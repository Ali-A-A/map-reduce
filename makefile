all: program.out map.out

program.out: main.o utils.o 
	g++ main.o utils.o -o program.out

map.out: map.o utils.o 
	g++ map.o utils.o -o map.out

main.o: main.cpp utils.hpp
	g++ -c main.cpp  -o main.o

utils.o: utils.cpp utils.hpp
	g++ -c utils.cpp -o utils.o

map.o: map.cpp utils.hpp
	g++ -c map.cpp -o map.o

clean:
	rm *.o
	rm *.out