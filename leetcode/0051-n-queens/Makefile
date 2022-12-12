#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=g++

OBJECTS = 	Board.o	\
		Solver.o

CFLAGS=-g -v -Wall -Wc++11-extensions -std=c++11

solver	: $(OBJECTS)
	$(CC) $(CFLAGS) -o solver $(OBJECTS)

Board.o	: Board.cpp Board.hpp
	$(CC) $(CFLAGS) -c Board.cpp

clean	:
	rm solver $(OBJECTS)
