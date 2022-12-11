// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>
#include <string>
#include <vector>
#include "Board.hpp"


/**
 * Builds a vector of every possible row of a solution to the nqueens
 * problem, which is a collection of rows all of which have exactly
 * one queen, and none of which have the queen in a repeated column
 */
std::vector<std::string> buildAllPossibleRows(int board_size)
{
    std::vector<std::string> rows;
    for(int index = 0; index < board_size; index++ )
    {
        std::string current;
        for(int length = 0; length < board_size; length++ )
        {
            current.append(".");
        }
        current[index] = 'Q';
        rows.push_back( current );
    }
    return rows;
}


int main(int argc, char **argv)
{
  auto fred = new Board(3);
  fred->dumpBoard();
  auto rows = buildAllPossibleRows(3);
  for( std::string current_row : rows )
  {
      printf("%s\n", current_row.c_str() );
  }
}
