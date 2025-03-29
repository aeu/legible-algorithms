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

bool bordersPacific(int row, int col, std::vector<std::vector<int>> &heights)
{
    if(( row == 0 ) || ( col == 0 ))
        return true;
    return false;
}

bool bordersAtlantic(int row, int col, std::vector<std::vector<int>> &heights)
{
    if(( row == heights.size()-1) || ( col == heights[0].size()-1))
        return true;
    return false;
}

bool isValid(std::pair<int,int> coords)
{
    if( ( coords.first == -1 ) || (coords.second == -1 ))
        return false;
    return true;
}

std::pair<int,int> getNorth(int row, int col, std::vector<std::vector<int>> &heights)
{
    if( row <= 0 )
        return { -1,-1 };
    if( heights[row-1][col] <= heights[row][col] )
        return { ( row-1 ), col };
    return { -1, -1 };
}

std::pair<int,int> getSouth(int row, int col, std::vector<std::vector<int>> &heights)
{
    if( row >= heights.size()-1 )
        return { -1,-1 };
    if( heights[row+1][col] <= heights[row][col] )
        return { ( row+1 ), col };
    return { -1, -1 };
}

std::pair<int,int> getEast(int row, int col, std::vector<std::vector<int>> &heights)
{
    if( col >= heights[0].size()-1 )
        return { -1,-1 };
    if( heights[row][col+1] <= heights[row][col] )
        return { row, col+1 };
    return { -1, -1 };
}

std::pair<int,int> getWest(int row, int col, std::vector<std::vector<int>> &heights)
{
    if( col <= 0 )
        return { -1,-1 };
    if( heights[row][col-1] <= heights[row][col] )
        return { row, col-1 };
    return { -1, -1 };
}

enum Flows {
    UNKNOWN = 0,
    PACIFIC,
    ATLANTIC,
    BOTH,
    NEITHER
};

std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights)
{
    std::vector<std::vector<int>> flows ( heights.size(), std::vector<int>( heights[0].size(), 0 ));
    for(int row=0;row<heights.size();row++)
    {
        for(int col=0;col<heights[0].size();col++)
        {
            std::cout << "about to start BFS for (" << row << "," << col << ")" << std::endl;
        }
    }
    std::vector<std::vector<int>> retval;
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> heights =
            {{1,2,2,3,5},
             {3,2,3,4,4},
             {2,4,5,3,1},
             {6,7,1,4,5},
             {5,1,1,2,4}};

        std::vector<std::vector<int>> expected =
            {{0,4}, {1,3}, {1,4}, {2,2}, {3,0}, {3,1}, {4,0}};
             
        std::vector<std::vector<int>> result = pacificAtlantic(heights);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
