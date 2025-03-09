CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = atn.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

atn: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -rf *.dSYM
	rm -f atn

