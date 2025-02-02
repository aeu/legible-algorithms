CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = keb.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

keb: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f keb

