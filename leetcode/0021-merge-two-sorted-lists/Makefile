CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = mts.o

%.o: %.c
	$(CC) -o $@

mts: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f mts
