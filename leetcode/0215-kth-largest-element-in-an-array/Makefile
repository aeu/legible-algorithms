CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = kle.o
#	other.o

%.o: %.c
	$(CC) -o $@

kle: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f kle

