CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = aol.o

%.o: %.c
	$(CC) -o $@

aol: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f aol

