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

const int Board::countQueensWithDirection(int row, int column, std::function<BoardPosition(int, int)> direction)
{
    int retval = 0;
    bool square_is_valid = true;

    int local_row = row;
    int local_column = column;
    
    while( square_is_valid )
    {
        auto new_coords = direction(local_row, local_column );
        local_row    = new_coords.row;
        local_column = new_coords.column;
        square_is_valid = coordinatesAreValid(local_row,local_column);
        if( square_is_valid )
        {
            char piece = getPieceAtPosition(local_row,local_column);
            if( piece == 'Q' )
                retval++;
        }
    }
    return retval;
}

const bool Board::coordinatesAreValid(const int row, const int column)
{
    if(( row < 0 ) || ( row >= board_size ))
        return false;
    
    if(( column < 0 ) || ( column >= board_size ))
        return false;

    return true;
}

const char Board::getPieceAtPosition(int row, int column)
{
    char retval = 'X';
    if( coordinatesAreValid(row,column))
    {
        int index = ( row * board_size ) + column;
        retval = definition[ index ];
    }
    return retval;
}

const bool Board::isNQueensSolution()
{
    bool retval = true;
    for(int row = 0; row < board_size; row++)
    {
        for(int column = 0; column < board_size; column++)
        {
            int index = ( row * board_size ) + column;
            int queen_count = 0;
            char piece = definition[ index ];
            if( piece == 'Q' )
            {
                auto north_east = [](int row, int column) { return BoardPosition{ row-1, column+1 }; };
                queen_count = countQueensWithDirection(row,column,north_east );
                if( queen_count > 0 )
                    return false;

                auto south_east = [](int row, int column) { return BoardPosition{ row+1, column+1 }; };
                queen_count = countQueensWithDirection(row,column,south_east );
                if( queen_count > 0 )
                    return false;

                auto south_west = [](int row, int column) { return BoardPosition{ row+1, column-1 }; };
                queen_count = countQueensWithDirection(row,column,south_west );
                if( queen_count > 0 )
                    return false;

                auto north_west = [](int row, int column) { return BoardPosition{ row-1, column-1 }; };
                queen_count = countQueensWithDirection(row,column,north_west );
                if( queen_count > 0 )
                    return false;
            }
        }
    }
    return retval;
}

void Board::dumpBoard()
{
    char current;
    std::string::iterator siter;
    int count = 0;
    printf("\n\nBoard\n");
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
    printf("\n" );
}

