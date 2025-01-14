CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = maxk.o
#	other.o

%.o: %.c
	$(CC) -o $@

maxk: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f maxk

