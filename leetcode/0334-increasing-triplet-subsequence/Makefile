CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = its.o
#	other.o

%.o: %.c
	$(CC) -o $@

its: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f its

