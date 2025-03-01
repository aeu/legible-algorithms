CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = rot.o
#	other.o

%.o: %.c
	$(CC) -o $@

rot: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f rot

