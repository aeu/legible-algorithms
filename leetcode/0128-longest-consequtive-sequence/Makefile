CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = lcs.o

%.o: %.c
	$(CC) -o $@

lcs: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f lcs

