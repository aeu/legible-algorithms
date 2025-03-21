CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = wpp.o

%.o: %.c
	$(CC) -o $@

wpp: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f wpp

