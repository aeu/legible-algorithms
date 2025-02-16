CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = btt.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

btt: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f btt

