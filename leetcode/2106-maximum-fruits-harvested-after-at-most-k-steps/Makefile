#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=gcc

FRAMEWORKS:= -framework Foundation
LIBRARIES:= -lobjc

SOURCE=max_fruit.m

OBJECTS = 	Farm.o	\
		max_fruit.o

CFLAGS=-g -v
LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
OUT=max_fruit

max_fruit	: $(OBJECTS)
	$(CC) -o max_fruit $(OBJECTS) $(LDFLAGS)

Farm.o	: Farm.m Farm.h
	$(CC) -c Farm.m

clean	:
	rm max_fruit $(OBJECTS)
