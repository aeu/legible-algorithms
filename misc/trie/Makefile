CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = ipt.o \
	Trie.o

%.o: %.c
	$(CC) -o $@

ipt: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f ipt

