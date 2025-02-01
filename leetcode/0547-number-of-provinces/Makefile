CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = nop.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

nop: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f nop

