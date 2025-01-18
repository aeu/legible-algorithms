CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = dcs.o
#	other.o

%.o: %.c
	$(CC) -o $@

dcs: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f dcs

