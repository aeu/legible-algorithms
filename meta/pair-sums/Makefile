CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = psu.o
#	other.o

%.o: %.c
	$(CC) -o $@

psu: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f psu

