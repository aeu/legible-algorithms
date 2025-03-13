CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = smm.o
#	other.o

%.o: %.c
	$(CC) -o $@

smm: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f smm

