CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = nor.o
#	other.o

%.o: %.c
	$(CC) -o $@

nor: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f nor

