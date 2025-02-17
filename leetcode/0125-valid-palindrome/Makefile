CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = vpp.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

vpp: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f vpp

