CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = ree.o

%.o: %.c
	$(CC) -o $@

ree: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f ree

