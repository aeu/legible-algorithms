CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = ror.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

ror: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f ror

