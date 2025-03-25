CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = pss.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

pss: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f pss

