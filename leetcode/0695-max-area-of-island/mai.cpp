// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>


std::vector<std::pair<int,int>> cardinals =
    {{  -1,  0 },  // north
     {   1,  0 },  // south
     {   0,  1 },  // east
     {   0, -1 }}; // west


bool isValid(int row,int col, std::vector<std::vector<int>>& grid)
{
    if( ( row < 0 ) || ( row >= grid.size() ) || ( col < 0 ) || ( col >= grid[0].size()))
        return false;
    return true;
}

void dfs(int row,int col, int island_id,
         std::vector<std::vector<int>> &grid,
         std::vector<std::vector<int>> &seen)
{
    if( seen[row][col] != 0 )
        return;

    seen[row][col] = island_id;
    
    for(auto curr : cardinals )
    {
        int nrow = row + curr.first;
        int ncol = col + curr.second;
        if( isValid( nrow,ncol,grid) )
        {
            if( grid[nrow][ncol] == 1 )
            {
                dfs(nrow,ncol,island_id,grid,seen);
            }
        }       
    }
}


int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
{
    int island_id = 1;
    std::vector<std::vector<int>> seen( grid.size(), std::vector<int>( grid[0].size(), 0 ));
    for(int row = 0; row<grid.size();row++)
    {
        for(int col = 0;col<grid[0].size();col++)
        {
            if(( grid[row][col] == 1 ) && ( seen[row][col] == 0 ))
            {
                dfs( row,col,island_id,grid,seen);
                island_id++;
            }
        }
    }
    int max_size = 0;
    std::unordered_map<int,int> counts;
    for(int row = 0; row<seen.size();row++)
    {
        for(int col = 0;col<seen[0].size();col++)
        {
            int island_id = seen[row][col];
            if( island_id != 0 )
            {
                counts[island_id]++;
                max_size = std::max(max_size, counts[island_id]);
            }
        }
    }
    return max_size;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC 695 - Max Area of Island" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> grid =
            {{0,0,1,0,0,0,0,1,0,0,0,0,0},
             {0,0,0,0,0,0,0,1,1,1,0,0,0},
             {0,1,1,0,1,0,0,0,0,0,0,0,0},
             {0,1,0,0,1,1,0,0,1,0,1,0,0},
             {0,1,0,0,1,1,0,0,1,1,1,0,0},
             {0,0,0,0,0,0,0,0,0,0,1,0,0},
             {0,0,0,0,0,0,0,1,1,1,0,0,0},
             {0,0,0,0,0,0,0,1,1,0,0,0,0}};

        int expected = 6;
        int result = maxAreaOfIsland(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> grid = {{0,0,0,0,0,0,0,0}};
        int expected = 0;
        int result = maxAreaOfIsland(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}

