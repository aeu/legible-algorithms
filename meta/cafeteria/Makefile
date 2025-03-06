CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = caf.o
#	other.o

%.o: %.c
	$(CC) -o $@

caf: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f caf

