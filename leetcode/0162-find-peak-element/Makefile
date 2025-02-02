CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = fpe.o
#\
#	TreeNode.o

%.o: %.c
	$(CC) -o $@

fpe: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f fpe

