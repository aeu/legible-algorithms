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

void buildPermutations(std::vector<std::string> &permutations,
                       std::vector<std::string> &intermediates,
                       std::vector<std::string> &rows)
{
    if( ! rows.empty() )
    {
        std::string current_row = rows.back();
        rows.pop_back();
        if( intermediates.empty() )
        {
            intermediates.push_back( current_row );
            buildPermutations( permutations, intermediates, rows );
        }
        else
        {
            std::string current_intermediate;
            std::vector<std::string> next_intermediates;
            std::vector<std::string>::iterator inter_iter;
            for(inter_iter = intermediates.begin();
                inter_iter != intermediates.end();
                inter_iter++)
            {
                current_intermediate = (std::string)*inter_iter;
                std::string::size_type siter = 0;
                bool done = false;
                while( ! done )
                {
                    std::string next_intermediate = current_intermediate.insert( siter, current_row );
                    next_intermediates.push_back( next_intermediate );
                    siter += current_row.length();
                    current_intermediate = (std::string)*inter_iter;
                    if( siter > current_intermediate.size() )
                    {
                        done = true;
                    }
                }
            }
            buildPermutations( permutations, next_intermediates, rows );
        }
    }
    else
    {
        permutations = intermediates;
    }
}

std::vector<Board> buildAllPossibleBoards(int board_size)
{
    std::vector<Board> boards;
    std::vector<std::string> permutations;
    std::vector<std::string> intermediates;
    
    std::vector<std::string> rows = buildAllPossibleRows(board_size);
    buildPermutations( permutations, intermediates, rows );
    for( std::string current_board : permutations )
    {
        boards.push_back( Board(board_size, current_board ) );
    }
    return boards;
}

int main(int argc, char **argv)
{
    auto boards = buildAllPossibleBoards(1);
    for( Board current_board : boards )
    {
        if( current_board.isNQueensSolution())
        {
            current_board.dumpBoard();
            printf("is N queens solution\n");
        }
    }
}
