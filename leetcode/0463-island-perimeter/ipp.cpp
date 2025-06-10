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


std::vector<std::vector<int>> cardinals = 
{
    {  1, 0 },
    { -1, 0 },
    {  0, 1 },
    {  0, -1 }
};

int isValid(int row, int col, std::vector<std::vector<int>>& grid)
{
    if(( row < 0 ) || ( col < 0 )
       || ( row >= grid.size() ) || ( col >= grid[0].size() ))
        return false;
    return true;
}

int islandPerimeter(std::vector<std::vector<int>>& grid)
{
    int perimeter = 0;
    for( int row = 0; row<grid.size();row++)
    {
        for( int col = 0; col< grid[0].size();col++)
        {
            if( grid[row][col] == 1 )
            {
                for(const auto curr : cardinals )
                {
                    int nrow = row + curr[0];
                    int ncol = col + curr[1];
                    if( isValid(nrow,ncol,grid))
                    {
                        if( grid[nrow][ncol] == 0 )
                        {
                            perimeter++;
                        }
                    }
                    else
                    {
                        perimeter++;
                    }
                }
            }
        }
    }
    return perimeter;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0463-island-perimeter" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> grid  = {{1,1}};
        int expected = 6;
        int result = islandPerimeter(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::vector<int>> grid  = {{0,1,0,0},{1,1,1,0},{0,1,0,0},{1,1,0,0}};
        int expected = 16;
        int result = islandPerimeter(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::vector<int>> grid  = {{1}};
        int expected = 4;
        int result = islandPerimeter(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::vector<int>> grid  = {{1,0}};
        int expected = 4;
        int result = islandPerimeter(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
