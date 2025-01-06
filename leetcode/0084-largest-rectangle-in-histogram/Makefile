CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = Solver.o
#	other.o

%.o: %.c
	$(CC) -o $@

solver: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f solver

