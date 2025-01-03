CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = merge.o
#	other.o

%.o: %.c
	$(CC) -o $@

merge: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f merge

