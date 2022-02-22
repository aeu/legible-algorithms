#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=gcc

FRAMEWORKS:= -framework Foundation
LIBRARIES:= -lobjc

SOURCE=bfs.m

OBJECTS = 	Graph.o	\
		bfs.o

CFLAGS=-g -v
LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
OUT=bfs

bfs	: $(OBJECTS)
	$(CC) -o bfs $(OBJECTS) $(LDFLAGS)

Graph.o	: Graph.m Graph.h
	$(CC) -c Graph.m

clean	:
	rm bfs $(OBJECTS)
