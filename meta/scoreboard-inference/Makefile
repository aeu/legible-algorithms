CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = sii.o
#	other.o

%.o: %.c
	$(CC) -o $@

sii: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*gg~
	rm -f sii

