CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = gnh.o
#	other.o

%.o: %.c
	$(CC) -o $@

gnh: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f gnh

