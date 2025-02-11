CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = lca.o \
	TreeNode.o

%.o: %.c
	$(CC) -o $@

lca: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f lca

