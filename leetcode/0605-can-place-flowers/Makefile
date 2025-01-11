CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = flowers.o
#	other.o

%.o: %.c
	$(CC) -o $@

flowers: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f flowers

