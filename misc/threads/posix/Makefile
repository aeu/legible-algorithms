#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=clang
CPPFLAGS=-g -Wall -std=c11 -pthread -I.

OBJS = thread_sample.o
#	other.o

%.o: %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

thread_sample: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f thread_sample
