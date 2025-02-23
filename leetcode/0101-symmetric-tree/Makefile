CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = stt.o

%.o: %.c
	$(CC) -o $@

stt: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f stt

