#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=gcc

FRAMEWORKS:= -framework Foundation
LIBRARIES:= -lobjc

SOURCE=lcs.m

OBJECTS = 	Path.o	\
		PathFinder.o	\
		lcs.o

CFLAGS=-g -v
LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
OUT=lcs

lcs	: $(OBJECTS)
	$(CC) -o lcs $(OBJECTS) $(LDFLAGS)

Path.o	: Path.m Path.h
	$(CC) -c Path.m

PathFinder.o	: PathFinder.m PathFinder.h
	$(CC) -c PathFinder.m

clean	:
	rm lcs $(OBJECTS)
