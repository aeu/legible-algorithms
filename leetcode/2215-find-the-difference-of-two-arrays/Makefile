CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = ftd.o
#	other.o

%.o: %.c
	$(CC) -o $@

ftd: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f ftd

