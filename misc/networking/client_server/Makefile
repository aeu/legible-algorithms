# -*- Mode: makefile; tab-width: 4; indent-tabs-mode: nil; -*-
#
#  red82 // software
#
#  This software may not be used or reproduced, in whole or in part,
#  without the express written permission of red82

CFLAGS = -Wall -Wextra -std=c99 -g
CC = gcc

all: client server

client: client.c
	$(CC) $(CFLAGS) -o client client.c

server: server.c
	$(CC) $(CFLAGS) -o server server.c

clean:
	rm -f *.o
	rm -rf *.dSYM
	rm -f *~
	rm -f *.*~
	rm -f client server
