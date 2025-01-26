CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = lst.o \
	TreeNode.o

%.o: %.c
	$(CC) -o $@

lst: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f lst

