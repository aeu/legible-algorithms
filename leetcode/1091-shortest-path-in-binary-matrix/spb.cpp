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

int doWork()
{
    return 1;
}

struct BfsInfo {
    int steps;
    int row;
    int col;
};


bool isValid(int row, int col, const std::vector<std::vector<int>> &grid)
{
    if(( row < 0 ) || ( col < 0 ) || ( row >= grid.size() ) || ( col >= grid[0].size() ))
    {
        return false;
    }
    return true;
}


std::vector<std::pair<int,int>> cardinals =
    {
        {  1,  0 },
        {  1,  1 },
        {  0,  1 },
        { -1,  1 },
        { -1,  0 },
        { -1, -1 },
        {  0, -1 },
        {  1, -1 }
    };

    
int shortestPathBinaryMatrix(std::vector<std::vector<int>> &grid)
{
    if( grid[0][0] == 1 )
        return -1;

    std::vector<std::vector<int>> seen ( grid.size(), std::vector<int>( grid[0].size(), 0 ));
    std::queue<BfsInfo> bqueue;
    bqueue.push( { 1, 0, 0 } );
    seen[0][0] = 1;
    while( ! bqueue.empty() )
    {
        BfsInfo curr = bqueue.front();
        bqueue.pop();
        if(( curr.row == grid.size() -1 ) && ( curr.col == grid[0].size() -1 ))
        {
            return curr.steps;
        }
        for( const auto &card : cardinals )
        {
            int nrow = curr.row + card.first;
            int ncol = curr.col + card.second;
            if( isValid( nrow, ncol, grid ) )
            {
                if(( grid[nrow][ncol] == 0 ) && ( seen[nrow][ncol] == 0 ))
                {
                    seen[nrow][ncol] = 1;
                    bqueue.push({ curr.steps + 1, nrow, ncol });
                }
            }
        }
    }
    return -1;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1091-shortest-path-in-binary-matrix" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> grid = {{0,1},{1,0}};
        int expected = 2;
        int result = shortestPathBinaryMatrix(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
        int expected = 4;
        int result = shortestPathBinaryMatrix(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> grid = {{1,0,0},{1,1,0},{1,1,0}};
        int expected = -1;
        int result = shortestPathBinaryMatrix(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
