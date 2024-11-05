CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = best.o

%.o: %.c
	$(CC) -o $@

best: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f rbt
