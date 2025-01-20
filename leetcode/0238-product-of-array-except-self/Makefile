CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = poa.o
#	other.o

%.o: %.c
	$(CC) -o $@

poa: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f poa

