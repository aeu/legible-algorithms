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
#include <stack>
#include <limits.h>


int min_path = INT_MAX;

std::pair<int,int> getLeft(std::vector<std::vector<int>> &triangle,
                           std::pair<int,int> current)
{
    int row = current.first + 1;
    int col = current.second;
    if( row >= triangle.size() )
        return { -1,-1 };
    return { row,col };
}

std::pair<int,int> getRight(std::vector<std::vector<int>> &triangle,
                            std::pair<int,int> current)
{
    int row = current.first + 1;
    int col = current.second + 1;
    if(( row >= triangle.size() ) || ( col >= triangle[row].size() ))
        return { -1,-1 };
    return { row,col };
}

int valueAt(std::vector<std::vector<int>> &triangle,
            std::pair<int,int> current)
{
    return triangle[current.first][current.second];
}

bool isValid(std::vector<std::vector<int>> &triangle,
             std::pair<int,int> position)
{
    if(( position.first == -1 ) || ( position.second == -1 ))
        return false;
    if(( position.first < 0 ) || ( position.first > triangle.size()-1 ))
        return false;
    if(( position.second < 0 ) || ( position.second > triangle[position.first].size()-1 ))
        return false;
    return true;
}

int dfs(std::vector<std::vector<int>> &triangle,
        std::pair<int,int> current,
        int value)
{
    if( ! isValid( triangle,current ) )
        return 0;

    std::pair<int,int> left = getLeft(triangle,current);
    std::pair<int,int> right = getRight(triangle,current);

    if(( ! isValid( triangle,left) && ( ! isValid(triangle,right ))))
    {
        int path_sum = value + valueAt( triangle,current );
        min_path = std::min( min_path, path_sum );
        return path_sum;
    }
    if( isValid(triangle,left))
        dfs( triangle,left,value+valueAt(triangle,current));
    if( isValid(triangle,right))
        dfs( triangle,right,value+valueAt(triangle,current));

    return 0;
}



int minimumTotal(std::vector<std::vector<int>> &triangle)
{
    dfs(triangle, { 0, 0 }, 0 );
    return min_path;
}



int main(int argc, char **argv)
{
    std::cout << "Leetcode #120 - Triangle" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
        int expected = 11;
        int result = minimumTotal(triangle);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
