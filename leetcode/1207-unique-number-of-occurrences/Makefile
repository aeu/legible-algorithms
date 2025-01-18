CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = uno.o
#	other.o

%.o: %.c
	$(CC) -o $@

uno: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f uno

