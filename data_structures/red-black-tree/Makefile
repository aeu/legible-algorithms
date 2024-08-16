CC=g++
CFLAGS=-g -Wall -std=c++17 -I.

DEPS = TreeNode.h \
	RedBlackTree.h

OBJ = rbt.o \
	TreeNode.o \
	RedBlackTree.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

rbt: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f rbt
