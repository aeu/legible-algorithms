CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = fha.o
#	other.o

%.o: %.c
	$(CC) -o $@

fha: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f fha

