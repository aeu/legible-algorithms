CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = cbt.o

%.o: %.c
	$(CC) -o $@

cbt: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f cbt

