CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = mpa.o
#	other.o

%.o: %.c
	$(CC) -o $@

mpa: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f mpa

