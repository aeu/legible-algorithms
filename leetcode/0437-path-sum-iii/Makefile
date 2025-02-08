CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = pst.o \
	TreeNode.o

%.o: %.c
	$(CC) -o $@

pst: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f pst

