CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = hin.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

hin: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f hin

