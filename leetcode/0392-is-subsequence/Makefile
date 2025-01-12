CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = subsequence.o
#	other.o

%.o: %.c
	$(CC) -o $@

subsequence: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f subsequence

