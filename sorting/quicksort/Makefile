#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=gcc

FRAMEWORKS:= -framework Foundation
LIBRARIES:= -lobjc

SOURCE=quicksort.m

CFLAGS=-g -v $(SOURCE)
LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
OUT=-o quicksort

all:
	$(CC)		\
	$(CFLAGS)	\
	$(LDFLAGS)	\
	$(OUT)

clean:
	rm -rf	*.dSYM	quicksort
