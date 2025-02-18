CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = clw.o

%.o: %.c
	$(CC) -o $@

clw: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f clw
