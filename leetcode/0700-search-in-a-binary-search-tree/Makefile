CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = sib.o \
	TreeNode.o

%.o: %.c
	$(CC) -o $@

sib: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f sib

