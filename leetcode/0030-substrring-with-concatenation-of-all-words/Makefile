CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = swc.o
#	other.o

%.o: %.c
	$(CC) -o $@

swc: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f swc

