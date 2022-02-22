#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=gcc

FRAMEWORKS:= -framework Foundation
LIBRARIES:= -lobjc

SOURCE=nvn.m

OBJECTS = 	nvn.o

CFLAGS=-g -v
LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
OUT=nvn

nvn	: $(OBJECTS)
	$(CC) -o nvn $(OBJECTS) $(LDFLAGS)

clean	:
	rm nvn $(OBJECTS)
