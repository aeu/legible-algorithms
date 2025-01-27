CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = dfs.o \
	TreeNode.o

%.o: %.c
	$(CC) -o $@

dfs: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f dfs

