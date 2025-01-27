CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = cgn.o \
	TreeNode.o

%.o: %.c
	$(CC) -o $@

cgn: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f cgn

