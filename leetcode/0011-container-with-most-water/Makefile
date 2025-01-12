CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = water.o
#	other.o

%.o: %.c
	$(CC) -o $@

water: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f water

