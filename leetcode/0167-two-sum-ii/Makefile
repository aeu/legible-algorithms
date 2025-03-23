CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = tsi.o
#	other.o

%.o: %.c
	$(CC) -o $@

tsi: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f tsi

