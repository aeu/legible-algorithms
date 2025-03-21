CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = gaa.o

%.o: %.c
	$(CC) -o $@

gaa: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f gaa

