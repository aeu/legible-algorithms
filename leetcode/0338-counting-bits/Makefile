CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = cob.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

cob: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f cob

