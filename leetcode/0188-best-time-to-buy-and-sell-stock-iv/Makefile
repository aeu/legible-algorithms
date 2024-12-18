CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = best_time.o	\
	Trade.o

%.o: %.c
	$(CC) -o $@

best_time: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^


clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f best_time

