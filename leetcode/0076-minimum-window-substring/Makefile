CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = mws.o
#	other.o

%.o: %.c
	$(CC) -o $@

mws: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f mws

