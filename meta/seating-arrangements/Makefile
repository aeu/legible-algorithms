CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = saa.o
#	other.o

%.o: %.c
	$(CC) -o $@

saa: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f saa

