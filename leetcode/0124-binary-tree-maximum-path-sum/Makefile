CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = btm.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

btm: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f btm

