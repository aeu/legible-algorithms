CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = rtm.o
#	other.o

%.o: %.c
	$(CC) -o $@

rtm: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f rtm

