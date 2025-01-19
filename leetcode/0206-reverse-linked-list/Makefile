CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = rll.o \
	ListNode.o

%.o: %.c
	$(CC) -o $@

rll: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f rll

