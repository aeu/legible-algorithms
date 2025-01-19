CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = llc.o \
	ListNode.o

%.o: %.c
	$(CC) -o $@

llc: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f llc

