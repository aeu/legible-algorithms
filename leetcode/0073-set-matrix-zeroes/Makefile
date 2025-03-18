CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = smz.o
#	other.o

%.o: %.c
	$(CC) -o $@

smz: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f smz

