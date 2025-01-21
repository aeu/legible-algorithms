CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = kgc.o
#	other.o

%.o: %.c
	$(CC) -o $@

kgc: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f kgc

