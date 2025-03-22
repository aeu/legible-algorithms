CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = cdi.o

%.o: %.c
	$(CC) -o $@

cdi: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f cdi

