#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = mno.o
#	other.o

%.o: %.c
	$(CC) -o $@

mno: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f mno
