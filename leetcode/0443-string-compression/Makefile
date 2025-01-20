CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = sco.o
#	other.o

%.o: %.c
	$(CC) -o $@

sco: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f sco

