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

bool uniqueOccurrences(std::vector<int>& arr)
{
    if( arr.size() == 0 )
        return false;
    std::map<int,int>counts;
    for(int current : arr )
    {
        counts[current]++;
    }

    // handle the edge case of all uniques
    if( arr.size() == counts.size() )
        return true;
    
    std::unordered_set<int> unique_check;
    for(auto pair : counts )
    {
        auto result = unique_check.insert( pair.second );
        if( ! result.second )
            return false;
    }
    return true;
}

std::vector<int> getColumn(std::vector<std::vector<int>>& grid,
                           int column_number)
{
    std::vector<int> column;
    for(auto current_row : grid )
    {
        column.push_back( current_row[column_number] );
    }
    return column;
}    

int equalPairs(std::vector<std::vector<int>>& grid)
{
    int equal_pairs = 0;
    for(size_t index=0;index<grid.size();index++)
    {
        std::vector<int> row = grid[index];
        for(size_t column_index=0;column_index<grid.size();column_index++)
        {
            std::vector<int> column = getColumn(grid,column_index);
            if( row == column )
            {
                equal_pairs++;
            }
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
