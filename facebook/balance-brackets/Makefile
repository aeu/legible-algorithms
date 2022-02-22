#
# red82 // software
# Alfonso E. Urdaneta
# alfonso@red82.com
#
CC=gcc

FRAMEWORKS:= -framework Foundation
LIBRARIES:= -lobjc

SOURCE=balance-brackets.m

OBJECTS = 	balance-brackets.o

CFLAGS=-g -v
LDFLAGS=$(LIBRARIES) $(FRAMEWORKS)
OUT=balance-brackets

balance-brackets	: $(OBJECTS)
	$(CC) -o balance-brackets $(OBJECTS) $(LDFLAGS)

clean	:
	rm balance-brackets $(OBJECTS)
