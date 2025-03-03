CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = cfc.o
#	other.o

%.o: %.c
	$(CC) -o $@

cfc: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f cfc

