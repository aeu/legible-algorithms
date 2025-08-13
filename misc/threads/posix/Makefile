#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=clang
CPPFLAGS=-g -Wall -std=c11 -pthread -I.

OBJS = posix_threads.o
#	other.o

%.o: %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

posix_threads: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f posix_threads
