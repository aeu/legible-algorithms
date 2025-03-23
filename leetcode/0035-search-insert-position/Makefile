CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = sip.o
#	other.o

%.o: %.c
	$(CC) -o $@

sip: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f sip

