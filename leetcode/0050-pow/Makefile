CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = pow.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

pow: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f pow

