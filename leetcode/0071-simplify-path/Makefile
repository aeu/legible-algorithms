CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = spp.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

spp: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f spp

