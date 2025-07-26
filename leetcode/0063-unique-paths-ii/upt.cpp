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
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

int backtrack(int m, int n, 
               int curr_m, int curr_n,
               std::vector<std::vector<int>> &memo,
               std::vector<std::vector<int>> &obstacleGrid)
{
    if(( curr_m == m-1 ) && ( curr_n == n-1))
    {
        if( obstacleGrid[curr_m][curr_n] != 1 )
            return 1;
    }
    if(( curr_m >= m ) || ( curr_n >= n ))
        return 0;

    if( obstacleGrid[curr_m][curr_n] == 1 )
        return 0;
    
    if( memo[curr_m][curr_n] != -1 )
        return memo[curr_m][curr_n];

    int down  = backtrack(m,n,curr_m+1,curr_n,  memo,obstacleGrid);
    int right = backtrack(m,n,  curr_m,curr_n+1,memo,obstacleGrid);

    memo[curr_m][curr_n] = down + right;
    return memo[curr_m][curr_n];
}


int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) 
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    std::vector<std::vector<int>> memo( m, std::vector<int> (n,-1));
    int res = backtrack(m,n,0,0,memo,obstacleGrid);
    return res;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0063-unique-paths-ii" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> obstacleGrid = 
          {{0,0,0},{0,1,0},{0,0,0}};
        int expected = 2;
        int result = uniquePathsWithObstacles(obstacleGrid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::vector<int>> obstacleGrid = 
          {{0,1},{0,0}};
        int expected = 1;
        int result = uniquePathsWithObstacles(obstacleGrid);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
