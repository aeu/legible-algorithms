CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = mnv.o
#	other.o

%.o: %.c
	$(CC) -o $@

mnv: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f mnv

