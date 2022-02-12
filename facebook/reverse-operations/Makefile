#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=gcc

FRAMEWORKS:= -framework Foundation
LIBRARIES:= -lobjc

SOURCE=reverse_operations.m

OBJECTS = 	reverse_operations.o

CFLAGS=-g -v
LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
OUT=reverse_operations

reverse_operations	: $(OBJECTS)
	$(CC) -o reverse_operations $(OBJECTS) $(LDFLAGS)

clean	:
	rm reverse_operations $(OBJECTS)
