// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82


#include <stdio.h>
#include "Board.hpp"

Board::Board (const int board_size)
{
  this->board_size = board_size;
}

Board::Board(const int board_size, const::std::string board_description)
    : Board(board_size)
{
    definition = { board_description };
}


void Board::dumpBoard()
{
    char current;
    std::string::iterator siter;
    int count = 0;
    for( siter=definition.begin(); siter != definition.end(); siter++)
    {
        if((( count % board_size ) == 0 ) && ( count > 0 ))
        {
            printf("\n" );
        }
        current = *siter;
        printf("%c", current );
        count++;
    }
    printf("\n\n" );
}

