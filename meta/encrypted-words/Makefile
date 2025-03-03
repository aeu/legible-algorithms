CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = eww.o
#	other.o

%.o: %.c
	$(CC) -o $@

eww: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f eww

