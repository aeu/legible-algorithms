CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = nodo.o

%.o: %.c
	$(CC) -o $@

nodo: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f rbt
