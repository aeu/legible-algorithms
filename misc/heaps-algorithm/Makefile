CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = heaps.o
#	other.o

%.o: %.c
	$(CC) -o $@

heaps: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f heaps

