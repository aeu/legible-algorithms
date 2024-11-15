CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = rbt.o \
	TreeNode.o \
	RedBlackTree.o

%.o: %.c
	$(CC) -o $@

rbt: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f rbt

dotclean:
	rm -f *.dot
	rm -f *.png
	rm -f *.ps
