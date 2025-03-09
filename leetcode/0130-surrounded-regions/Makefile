CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = srr.o
#	other.o

%.o: %.c
	$(CC) -o $@

srr: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f srr

