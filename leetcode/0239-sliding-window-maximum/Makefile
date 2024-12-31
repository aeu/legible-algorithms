CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = swm.o

%.o: %.c
	$(CC) -o $@

swm: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f swm
