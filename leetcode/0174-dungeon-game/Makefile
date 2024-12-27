CC=g++
CPPFLAGS=-g -Wall -std=c++17 -I.

OBJS = dungeon_game.o
#	other.o

%.o: %.c
	$(CC) -o $@

dungeon_game: $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	find . -type f -name '*.o' -delete
	find . -type f -name "*~" -delete
	find . -type f -name "*.*~" -delete
	rm -f dungeon_game

