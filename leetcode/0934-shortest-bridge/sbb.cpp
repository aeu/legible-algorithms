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
    {{  1,  0 },
     { -1,  0 },
     {  0,  1 },
     {  0, -1}};



bool isValid(int row,int col, std::vector<std::vector<int>>& grid)
{
    if( ( row < 0 ) || ( col < 0 ) || ( row >= grid.size() ) || ( col >= grid[0].size()))
        return false;
    return true;
}
             

struct BfsInfo {
    int row;
    int col;
    int distance;
};

int shortestBridge(std::vector<std::vector<int>>& grid)
{
    std::vector<std::vector<int>> seen( grid.size(), std::vector<int>( grid[0].size(),0));
    // first make a starting island.
    std::queue<BfsInfo> bfs_queue;
    bool start_found = false;
    for(int row=0;row<grid.size();row++)
    {
        for(int col=0;col<grid[0].size();col++)
        {
            if( grid[row][col] == 1 )
            {
                bfs_queue.push({row,col,0});
                grid[row][col] = 2;
                seen[row][col] = 1;
                start_found = true;
                break;
            }
        }
        if( start_found )
            break;
    }
    // now we have a start point, populate the entire island.
    while( ! bfs_queue.empty() )
    {
        BfsInfo curr = bfs_queue.front();
        bfs_queue.pop();
        for(const auto card : cardinals )
        {
            int nrow = curr.row + card[0];
            int ncol = curr.col + card[1];
            if( isValid( nrow,ncol, grid ))
            {
                if( grid[nrow][ncol] == 1 )
                {
                    seen[nrow][ncol] = 1;
                    grid[nrow][ncol] = 2;
                    bfs_queue.push({nrow,ncol,0});
                }
            }
        }
    }
    for(int row=0;row<grid.size();row++)
    {
        for(int col=0;col<grid[0].size();col++)
        {
            seen[row][col] = 0;
            if( grid[row][col] == 2 )
            {
                bfs_queue.push({row,col,0});
            }
        }
    }
    // now we start from every spot on the first island, until we hit
    // the second island.  As soon as we hit that second island,
    // return out.  Whatever hits first will be the shortest path as
    // its a bfs.
    while( ! bfs_queue.empty() )
    {
        BfsInfo curr = bfs_queue.front();
        bfs_queue.pop();
        for(const auto card : cardinals )
        {
            int nrow = curr.row + card[0];
            int ncol = curr.col + card[1];
            if( isValid( nrow,ncol, grid ))
            {
                if( grid[nrow][ncol] == 1 )
                {
                    return curr.distance;
                }
                else if( grid[nrow][ncol] == 0 )
                {
                    if( seen[nrow][ncol] == 0 )
                    {
                        seen[nrow][ncol] = 1;
                        bfs_queue.push({nrow,ncol,curr.distance+1});
                    }
                }
            }
        }
    }
    return -1;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0934-shortest-bridge" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> nums  = {{0,1},{1,0}};
        int expected = 1;
        int result = shortestBridge(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> nums  = {{0,1,0},{0,0,0},{0,0,1}};
        int expected = 2;
        int result = shortestBridge(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> nums  = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
        int expected = 1;
        int result = shortestBridge(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
