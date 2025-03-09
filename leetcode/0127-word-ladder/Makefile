CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = wol.o
#	other.o

%.o: %.c
	$(CC) -o $@

wol: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f wol

