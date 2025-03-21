CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = iss.o

%.o: %.c
	$(CC) -o $@

iss: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f iss

