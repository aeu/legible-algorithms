CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = msa.o

%.o: %.c
	$(CC) -o $@

msa: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f msa

