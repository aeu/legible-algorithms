CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = gcd.o
#	other.o

%.o: %.c
	$(CC) -o $@

gcd: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f gcd

