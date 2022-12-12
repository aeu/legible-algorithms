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


const int Board::countQueensNorthEast(int row, int column)
{
    int retval = 0;
    bool square_is_valid = true;
    while( square_is_valid )
    {
        row = row - 1;
        column = column + 1;
        square_is_valid = coordinatesAreValid(row,column);
        if( square_is_valid )
        {
            char piece = getPieceAtPosition(row,column);
            if( piece == 'Q' )
                retval++;
        }
    }
    return retval;
}
const int Board::countQueensNorthWest(int row, int column)
{
    int retval = 0;
    bool square_is_valid = true;
    while( square_is_valid )
    {
        row = row - 1;
        column = column - 1;
        square_is_valid = coordinatesAreValid(row,column);
        if( square_is_valid )
        {
            char piece = getPieceAtPosition(row,column);
            if( piece == 'Q' )
                retval++;
        }
    }
    return retval;
}
const int Board::countQueensSouthWest(int row, int column)
{
    int retval = 0;
    bool square_is_valid = true;
    while( square_is_valid )
    {
        row = row + 1;
        column = column - 1;
        square_is_valid = coordinatesAreValid(row,column);
        if( square_is_valid )
        {
            char piece = getPieceAtPosition(row,column);
            if( piece == 'Q' )
                retval++;
        }
    }
    return retval;
}
const int Board::countQueensSouthEast(int row, int column)
{
    int retval = 0;
    bool square_is_valid = true;
    while( square_is_valid )
    {
        row = row + 1;
        column = column + 1;
        square_is_valid = coordinatesAreValid(row,column);
        if( square_is_valid )
        {
            char piece = getPieceAtPosition(row,column);
            if( piece == 'Q' )
                retval++;
        }
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
                queen_count = countQueensNorthEast(row,column);
                if( queen_count > 0 )
                    return false;
                
                queen_count = countQueensNorthWest(row,column);
                if( queen_count > 0 )
                    return false;
                
                queen_count = countQueensSouthEast(row,column);
                if( queen_count > 0 )
                    return false;
                
                queen_count = countQueensSouthWest(row,column);
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

