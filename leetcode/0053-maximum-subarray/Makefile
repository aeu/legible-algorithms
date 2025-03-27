CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = mss.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

mss: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f mss

