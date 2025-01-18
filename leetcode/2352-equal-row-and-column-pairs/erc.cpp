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
#include <unordered_set>

void dumpNumbers(const std::vector<int> &numbers )
{ 
    std::cout << "[";
    bool first_time = true;
    for(int current : numbers )
    {
        if( ! first_time )
            std::cout << ", " ;
        std::cout << current ;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}   

bool compareRowAndColumn(std::vector<std::vector<int>>& grid,
                         const int row_number,
                         const int column_number)
{
    for(size_t row_index=0;row_index<grid.size();row_index++)
    {
        if ( grid[row_number][row_index] != grid[row_index][column_number] )
            return false;
    }
    return true;
}

int equalPairs(std::vector<std::vector<int>>& grid)
{
    int equal_pairs = 0;
    for(size_t index=0;index<grid.size();index++)
    {
        for(size_t column_index=0;column_index<grid.size();column_index++)
        {
            if( compareRowAndColumn(grid,index,column_index))
                equal_pairs++;
        }
    }
    return equal_pairs;
}
int main(int argc, char **argv)
{
    std::cout << "Leetcode 2352 - Equal Row and Column Pairs" << std::endl;
    {
        std::vector<std::vector<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};
        int num_equal_pairs = equalPairs(grid);
        for(auto current_row : grid )
        {
            dumpNumbers(current_row);
        }
        std::cout << "Equal pairs : " << num_equal_pairs << std::endl;
    } 
    {
        std::vector<std::vector<int>> grid = {{3,1,2,2},{1,4,4,5},{2,4,2,2},{2,4,2,2}};
        int num_equal_pairs = equalPairs(grid);
        for(auto current_row : grid )
        {
            dumpNumbers(current_row);
        }
        std::cout << "Equal pairs : " << num_equal_pairs << std::endl;
    }
}
