CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = reverse.o
#	other.o

%.o: %.c
	$(CC) -o $@

reverse: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f reverse

