CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = csi.o
#	other.o

%.o: %.c
	$(CC) -o $@

csi: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f csi

