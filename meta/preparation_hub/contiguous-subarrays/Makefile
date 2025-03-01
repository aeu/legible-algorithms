CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = csu.o
#	other.o

%.o: %.c
	$(CC) -o $@

csu: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f csu

