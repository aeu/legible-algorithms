CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = rlc.o
#	other.o

%.o: %.c
	$(CC) -o $@

rlc: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f rlc

