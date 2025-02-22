CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = rnn.o
#	other.o

%.o: %.c
	$(CC) -o $@

rnn: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f rnn

