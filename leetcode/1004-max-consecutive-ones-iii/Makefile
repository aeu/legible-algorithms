CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = mco.o
#	other.o

%.o: %.c
	$(CC) -o $@

mco: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f mco

