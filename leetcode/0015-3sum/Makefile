CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = tss.o
#	other.o

%.o: %.c
	$(CC) -o $@

tss: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f tss

