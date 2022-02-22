#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=gcc

FRAMEWORKS:= -framework Foundation
LIBRARIES:= -lobjc

SOURCE=balanced_split.m

OBJECTS = 	balanced_split.o

CFLAGS=-g -v
LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
OUT=balanced_split

balanced_split	: $(OBJECTS)
	$(CC) -o balanced_split $(OBJECTS) $(LDFLAGS)

clean	:
	rm balanced_split $(OBJECTS)
