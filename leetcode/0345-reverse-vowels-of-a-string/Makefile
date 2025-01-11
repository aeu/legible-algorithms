CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = vowels.o
#	other.o

%.o: %.c
	$(CC) -o $@

vowels: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f vowels

