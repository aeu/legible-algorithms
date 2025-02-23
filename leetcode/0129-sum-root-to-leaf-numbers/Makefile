CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = srl.o

%.o: %.c
	$(CC) -o $@

srl: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f srl

