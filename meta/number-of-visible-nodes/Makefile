CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = nvn.o
#	other.o

%.o: %.c
	$(CC) -o $@

nvn: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f nvn

