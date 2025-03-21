CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = vaa.o

%.o: %.c
	$(CC) -o $@

vaa: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f vaa

