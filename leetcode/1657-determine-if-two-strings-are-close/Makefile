CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = dit.o
#	other.o

%.o: %.c
	$(CC) -o $@

dit: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f dit

