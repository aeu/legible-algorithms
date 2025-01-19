CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = dmn.o \
	ListNode.o

%.o: %.c
	$(CC) -o $@

dmn: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f dmn

