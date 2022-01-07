#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=gcc

FRAMEWORKS:= -framework Foundation
LIBRARIES:= -lobjc

SOURCE=heapsort.m

CFLAGS=-g -v $(SOURCE)
LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
OUT=-o heapsort

all:
	$(CC)		\
	$(CFLAGS)	\
	$(LDFLAGS)	\
	$(OUT)

clean:
	rm -rf	*.dSYM	heapsort
