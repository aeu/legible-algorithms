CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = mee.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

mee: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f mee

