CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = noi.o
#	other.o

%.o: %.c
	$(CC) -o $@

noi: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f noi

