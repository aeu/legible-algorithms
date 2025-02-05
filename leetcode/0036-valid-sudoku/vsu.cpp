// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

bool isValidRow(std::vector<char> &row)
{
    std::map<char,int> hits;
    for(auto current : row )
    {
        if ( current == '.' )
            continue;
        if( hits.find(current) == hits.end() )
        {
            hits[current] = 1;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool isValidColumn(std::vector<std::vector<char>> &board ,
                   int column_number)
{
    std::map<char,int> hits;
    for(int index=0;index<board.size();index++)
    {
        auto current = board[index][column_number];
        if ( current == '.' )
            continue;
        if( hits.find(current) == hits.end() )
        {
            hits[current] = 1;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool isValidBox(std::vector<std::vector<char>> &board ,
                int box_number)
{

    int base_x_offset;
    int base_y_offset;

    if( box_number == 0 )
    {
        base_x_offset = 0;
        base_y_offset = 0;
    }
    else if( box_number == 1 )
    {
        base_x_offset = 3;
        base_y_offset = 0;
    }
    else if( box_number == 2 )
    {
        base_x_offset = 6;
        base_y_offset = 0;
    }
    else if( box_number == 3 )
    {
        base_x_offset = 0;
        base_y_offset = 3;
    }
    else if( box_number == 4 )
    {
        base_x_offset = 3;
        base_y_offset = 3;
    }
    else if( box_number == 5 )
    {
        base_x_offset = 6;
        base_y_offset = 3;
    }
    else if( box_number == 6 )
    {
        base_x_offset = 0;
        base_y_offset = 6;
    }
    else if( box_number == 7 )
    {
        base_x_offset = 3;
        base_y_offset = 6;
    }
    else 
    {
        base_x_offset = 6;
        base_y_offset = 6;
    }
    std::map<char,int> hits;
    for(int x_offset = 0; x_offset < 3 ; x_offset++)
    {
        for(int y_offset = 0; y_offset < 3 ; y_offset++)
        {
            int x_index = base_x_offset+x_offset;
            int y_index = base_y_offset+y_offset;
            auto current = board[x_index][y_index];
            if ( current == '.' )
                continue;
            if( hits.find(current) == hits.end() )
            {
                hits[current] = 1;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}


bool isValidSudoku(std::vector<std::vector<char>> &board )
{
    for(auto row : board )
    {
        if( ! isValidRow( row ))
            return false;
    }
    for(int column=0;column<board.size();column++)
    {
        if( ! isValidColumn(board,column))
            return false;
        if( ! isValidBox(board,column))
            return false;
    }
    return true;
}




int main(int argc, char **argv)
{
    std::cout << "Leetcode 0036 - Valid Sukoku" << std::endl;
    {
        std::cout << "Example 1" << std::endl;
        std::vector<std::vector<char>> board = 
            {{'5','3','.','.','7','.','.','.','.'}
             ,{'6','.','.','1','9','5','.','.','.'}
             ,{'.','9','8','.','.','.','.','6','.'}
             ,{'8','.','.','.','6','.','.','.','3'}
             ,{'4','.','.','8','.','3','.','.','1'}
             ,{'7','.','.','.','2','.','.','.','6'}
             ,{'.','6','.','.','.','.','2','8','.'}
             ,{'.','.','.','4','1','9','.','.','5'}
             ,{'.','.','.','.','8','.','.','7','9'}};
        bool valid = isValidSudoku(board);
        std::cout << "Is valid : " << valid << std::endl;
    }
    {
        std::cout << "Example 2" << std::endl;
        std::vector<std::vector<char>> board = 
            {{'8','3','.','.','7','.','.','.','.'}
             ,{'6','.','.','1','9','5','.','.','.'}
             ,{'.','9','8','.','.','.','.','6','.'}
             ,{'8','.','.','.','6','.','.','.','3'}
             ,{'4','.','.','8','.','3','.','.','1'}
             ,{'7','.','.','.','2','.','.','.','6'}
             ,{'.','6','.','.','.','.','2','8','.'}
             ,{'.','.','.','4','1','9','.','.','5'}
             ,{'.','.','.','.','8','.','.','7','9'}};
        bool valid = isValidSudoku(board);
        std::cout << "Is valid : " << valid << std::endl;
    }
}
