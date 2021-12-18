#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=gcc

FRAMEWORKS:= -framework Foundation
LIBRARIES:= -lobjc

SOURCE=maxarea.m

OBJECTS = 	Ocean.o	\
		maxarea.o

CFLAGS=-g -v
LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
OUT=maxarea

maxarea	: $(OBJECTS)
	$(CC) -o maxarea $(OBJECTS) $(LDFLAGS)

Ocean.o	: Ocean.m Ocean.h
	$(CC) -c Ocean.m

clean	:
	rm maxarea $(OBJECTS)
