#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=gcc

FRAMEWORKS:= -framework Foundation
LIBRARIES:= -lobjc

SOURCE=mksl.m

OBJECTS = 	Merger.o \
		mksl.o

CFLAGS=-g -v
LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
OUT=mksl

mksl	: $(OBJECTS)
	$(CC) -o mksl $(OBJECTS) $(LDFLAGS)

Merger.o	: Merger.m Merger.h
	$(CC) -c Merger.m

clean	:
	rm mksl $(OBJECTS)
