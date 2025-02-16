CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = jgg.o

%.o: %.c
	$(CC) -o $@

jgg: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f jgg
