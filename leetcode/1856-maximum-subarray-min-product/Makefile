#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=g++
CPPFLAGS=-g -Wall -std=c++20 -I.

OBJS = msm.o
#	other.o

%.o: %.c
	$(CC) -o $@

msm: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f msm
