CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = dop.o
#	other.o

%.o: %.c
	$(CC) -o $@

dop: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f dop

