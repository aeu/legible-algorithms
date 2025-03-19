CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = gol.o
#	other.o

%.o: %.c
	$(CC) -o $@

gol: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f gol

