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


struct FsInfo
{
    int island_id;
    int row;
    int col;
};


std::vector<std::vector<int>> cardinals =
    {
        {  0, 1 },
        {  0,-1 },
        {  1, 0 },
        { -1, 0 }
    };

bool isValid(int row,
             int col,
             std::vector<std::vector<int>> &grid)
{
    if((row<0)||(col<0)||(row>=grid.size())||(col>=grid[0].size()))
        return false;
    return true;
}
void islandDfs(FsInfo fs_info,
               std::vector<std::vector<int>> &grid,
               std::vector<std::vector<int>> &seen,
               std::unordered_map<int,int> &sizes)

{
    for(auto curr: cardinals )
    {
        int nrow = fs_info.row + curr[0];
        int ncol = fs_info.col + curr[1];
        if(isValid(nrow,ncol,grid))
        {
            if( seen[nrow][ncol] == 0 )
            {
                seen[nrow][ncol] = 1;
                // it's empty space, do nothing.
                if( grid[nrow][ncol] == 0 )
                {
                }
                // it's undiscovered land
                else if( grid[nrow][ncol] == 1 )
                {
                    grid[nrow][ncol] = fs_info.island_id;
                    sizes[fs_info.island_id]++;
                    islandDfs( {fs_info.island_id,nrow,ncol }, grid,seen,sizes );
                }
                // anything else is probably another island, do nothing
            }
        }
    }
}

int largestIsland(std::vector<std::vector<int>>& grid)
{
    int island_id = 2;
    std::unordered_map<int,int> sizes;
    std::vector<std::vector<int>> seen ( grid.size(), std::vector<int> ( grid[0].size(), 0 ));
    for(int row = 0; row < grid.size(); row++)
    {
        for(int col = 0; col < grid[0].size(); col++)
        {
            if( grid[row][col] == 1 )
            {
                seen[row][col] = 1;
                grid[row][col] = island_id;
                sizes[island_id]++;
                islandDfs({island_id,row,col},grid,seen,sizes);
                island_id++;
            }
        }
    }

    // now loop through all the zeros.  get the sizes of the islands
    // at its cardinals you would join if you made it a 1, and then
    // ctrack the running max.
    int largest = 1;
    int found_one = false;
    for(int row = 0; row < grid.size(); row++)
    {
        for(int col = 0; col < grid[0].size(); col++)
        {
            if( grid[row][col] == 0 )
            {
                found_one = true;
                int mysize = 1;
                std::unordered_set<int> my_neighbours;
                for( const auto cucard : cardinals )
                {
                    int nrow = row + cucard[0];
                    int ncol = col + cucard[1];
                    if( isValid( nrow,ncol,grid ))
                    {
                        int island_id = grid[nrow][ncol];
                        if( island_id  != 0 )
                        {
                            if( my_neighbours.count(island_id) == 0 )
                            {
                                my_neighbours.insert(island_id);
                                mysize += sizes[island_id];
                                largest = std::max(mysize,largest);
                            }
                        }
                    }
                }
            }
        }
    }
    if( found_one == false )
        return ( grid.size() * grid[0].size());
    return largest;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0827-making-a-large-island" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> grid = {{1,0},{0,1}};
        int expected = 3;
        int result = largestIsland(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> grid = {{1,1},{1,0}};
        int expected = 4;
        int result = largestIsland(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> grid = {{1,1},{1,1}};
        int expected = 4;
        int result = largestIsland(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
