CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = fpi.o
#	other.o

%.o: %.c
	$(CC) -o $@

fpi: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f fpi

