CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = btz.o

%.o: %.c
	$(CC) -o $@

btz: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f btz

