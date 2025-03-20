CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = btl.o

%.o: %.c
	$(CC) -o $@

btl: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f btl

