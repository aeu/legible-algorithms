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


bool isValid(int row, int col, std::vector<std::vector<int>> &grid)
{
    if(( row < 0 ) || ( col < 0 ) || ( row >= grid.size() ) || ( col >= grid[0].size() ))
    {
        return false;
    }
    return true;
}


std::vector<std::pair<int,int>> cardinals =
    {
        {  1,  0 }, // n
        {  1,  1 }, // ne
        {  0,  1 }, // e
        { -1,  1 }, // se
        { -1,  0 }, // s
        { -1, -1 }, // sw
        {  0, -1 }, // w
        {  1, -1 }  // nw
    };

    
int shortestPathBinaryMatrix(std::vector<std::vector<int> &grid)
{
    std::queue<BfsInfo> bqueue;
    bqueue.push( { 0, 0, 0 } );
    while( ! bqueue.empty() )
    {
        BfsInfo curr = bqueue.top();
        bqueue.pop();
        for( auto curr : cardinals )
        {
            int nrow = curr.row + curr.first;
            int ncol = curr.col + curr.second;
            if( isValid( nrow, ncol, grid ) )
            {
                if( grid[nrow][ncol] == 0 )
            }
        }
        
    }
    int retval = 0;
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> grid = {{0,1},{1,0}};
        int expected = 2;
        int result = shortestPathBinaryhMatrix(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
        int expected = 4;
        int result = shortestPathBinaryhMatrix(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> grid = {{1,0,0},{1,1,0},{1,1,0}};
        int expected = 1;
        int result = shortestPathBinaryhMatrix(grid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
