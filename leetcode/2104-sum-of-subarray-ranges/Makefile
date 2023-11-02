#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=gcc

FRAMEWORKS:= -framework Foundation
LIBRARIES:= -lobjc

SOURCE=subarraysums.m

OBJECTS = 	Ranges.o	\
		subarraysums.o

CFLAGS=-g -v
LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
OUT=subarraysums

subarraysums	: $(OBJECTS)
	$(CC) -o subarraysums $(OBJECTS) $(LDFLAGS)

Ranges.o	: Ranges.m Ranges.h
	$(CC) -c Ranges.m

clean	:
	rm subarraysums $(OBJECTS)
