CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = erc.o
#	other.o

%.o: %.c
	$(CC) -o $@

erc: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f erc

