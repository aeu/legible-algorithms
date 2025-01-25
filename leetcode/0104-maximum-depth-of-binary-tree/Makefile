CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = mdb.o \
	TreeNode.o

%.o: %.c
	$(CC) -o $@

mdb: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f mdb

