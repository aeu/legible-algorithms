CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = fmp.o
#	other.o

%.o: %.c
	$(CC) -o $@

fmp: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f fmp

