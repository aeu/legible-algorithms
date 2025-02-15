CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = rdf.o

%.o: %.c
	$(CC) -o $@

rdf: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f rdf

