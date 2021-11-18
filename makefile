main.o: main.cpp utils.hpp
	g++ -c main.cpp  -o main.o

utils.o: utils.cpp utils.hpp
	g++ -c utils.cpp -o utils.o

clean:
	rm *.o
	rm *.out