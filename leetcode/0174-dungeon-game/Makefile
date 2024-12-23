CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = dungeon_game.o
#	other.o

%.o: %.c
	$(CC) -o $@

dungeon_game: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	rm -f *.o
	rm -f *~
	rm -f *.*~
	rm -f dungeon_game

