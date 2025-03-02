CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = rmi.o
#	other.o

%.o: %.c
	$(CC) -o $@

rmi: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f rmi

