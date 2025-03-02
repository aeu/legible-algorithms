CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = ctt.o
#	other.o

%.o: %.c
	$(CC) -o $@

ctt: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f ctt

