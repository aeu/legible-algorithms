CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = kar.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

kar: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f kar

