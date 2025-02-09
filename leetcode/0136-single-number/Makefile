CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = snu.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

snu: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f snu

