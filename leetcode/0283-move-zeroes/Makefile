CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = zeroes.o
#	other.o

%.o: %.c
	$(CC) -o $@

zeroes: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f zeroes

