CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = edd.o
#	other.o

%.o: %.c
	$(CC) -o $@

edd: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f edd

