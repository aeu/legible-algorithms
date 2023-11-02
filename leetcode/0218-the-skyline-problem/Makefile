#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=gcc

FRAMEWORKS:= -framework Foundation
LIBRARIES:= -lobjc

SOURCE=skyline_problem.m

OBJECTS = 	Skyline.o	\
		skyline_problem.o

CFLAGS=-g -v
LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
OUT=skyline_problem

skyline_problem	: $(OBJECTS)
	$(CC) -o skyline_problem $(OBJECTS) $(LDFLAGS)

Skyline.o	: Skyline.m Skyline.h
	$(CC) -c Skyline.m

clean	:
	rm skyline_problem $(OBJECTS)
