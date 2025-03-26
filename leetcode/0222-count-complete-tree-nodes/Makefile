CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = cct.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

cct: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f cct

