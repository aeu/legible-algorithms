CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = oel.o \
	ListNode.o

%.o: %.c
	$(CC) -o $@

oel: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f oel

