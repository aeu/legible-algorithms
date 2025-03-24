CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = sir.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

sir: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f sir

