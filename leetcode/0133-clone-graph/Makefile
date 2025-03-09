CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = cgr.o
#	other.o

%.o: %.c
	$(CC) -o $@

cgr: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f cgr

