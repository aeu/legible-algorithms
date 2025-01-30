CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = dnb.o \
	TreeNode.o

%.o: %.c
	$(CC) -o $@

dnb: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f dnb

