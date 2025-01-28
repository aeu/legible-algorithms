CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = mls.o \
	TreeNode.o

%.o: %.c
	$(CC) -o $@

mls: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f mls

