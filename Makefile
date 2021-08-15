#gcc_options = -std=c++17 -Wall --pedantic-error

main:
	g++ -g -Wall main.cpp -o main

test:
	g++ -g -Wall test.cpp -o test

# run : program
#	./program

clean :
	rm -f ./test
	rm -f test.o
	rm -f ./main
	rm -f main.o