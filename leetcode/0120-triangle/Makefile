CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = tri.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

tri: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f tri

