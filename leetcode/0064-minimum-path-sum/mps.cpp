// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <iomanip>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

int backtrack(int current_row,
                int current_col,
                int &min_path,
                std::vector<std::vector<int>> &grid,
                std::vector<std::vector<int>> &memo )
{
    int num_rows = grid.size();
    int num_cols = grid[0].size();
    if(( current_row == num_rows) || ( current_col == num_cols))
        return INT_MAX;

    if(( current_row == num_rows - 1 ) && ( current_col == num_cols - 1))
    {
        return grid[current_row][current_col];
    }
    if( memo[current_row][current_col] != -1 )
        return memo[current_row][current_col];

    int down  = backtrack(current_row+1,current_col,  min_path,grid,memo);
    int right = backtrack(current_row,  current_col+1,min_path,grid,memo);

    int best = grid[current_row][current_col] + std::min(down,right);
    memo[current_row][current_col] = best;
    return memo[current_row][current_col];
}

int minPathSum(std::vector<std::vector<int>>& grid) 
{
    int num_rows = grid.size();
    int num_cols = grid[0].size();
    int min_path     = INT_MAX;
    int current_row = 0;
    int current_col = 0;
    std::vector<std::vector<int>> memo ( num_rows, std::vector<int>(num_cols, -1));
    return backtrack(current_row,current_col,min_path,grid,memo);
  //  return min_path;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0064-minimum-path-sum" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> grid = 
           {{1,3,1},{1,5,1},{4,2,1}};
        int expected = 7;
        int result = minPathSum(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
