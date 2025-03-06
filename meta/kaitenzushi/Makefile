CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = kai.o
#	other.o

%.o: %.c
	$(CC) -o $@

kai: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f kai

