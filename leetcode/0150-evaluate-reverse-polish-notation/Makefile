CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = erp.o
#	other.o

%.o: %.c
	$(CC) -o $@

erp: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f erp

