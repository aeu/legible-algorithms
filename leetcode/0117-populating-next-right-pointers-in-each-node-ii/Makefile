CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = pnr.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

pnr: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f pnr

