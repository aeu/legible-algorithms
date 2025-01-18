CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = aco.o
#	other.o

%.o: %.c
	$(CC) -o $@

aco: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f aco

