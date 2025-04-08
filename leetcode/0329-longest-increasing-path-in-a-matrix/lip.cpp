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
    { {  1,  0 }, // N
      { -1,  0 }, // S
      {  0,  1 }, // E
      {  0, -1 }}; // W

bool isValid(int row, int col, std::vector<std::vector<int>> &matrix)
{
    if( ( row < 0 ) || ( col < 0 ) || ( row >= matrix.size() ) || ( col >= matrix[0].size() ))
        return false;
    return true;
}


void dumpPath(std::vector<std::pair<int,int>> &path,
              std::vector<std::vector<int>> &matrix)
{
    int count = 0;
    for( auto curr : path )
    {
        int row = curr.first;
        int col = curr.second;
        std::cout << count++ << ": (" << row << "," << col << ") - " << matrix[row][col] << std::endl; 
    }
}

int dfs(std::vector<std::pair<int,int>> &path,
        std::vector<std::vector<int>> &memo,
        std::vector<std::vector<int>> &matrix)
{
    auto last = path.back();
    int row = last.first;
    int col = last.second;

    if( memo[row][col] != -1 )
        return memo[row][col];

    int max_len = 1;
    
    for(auto curr : cardinals )
    {
        int nrow = row + curr.first;
        int ncol = col + curr.second;
        if( isValid( nrow,ncol, matrix ) )
        {
            if( matrix[nrow][ncol] > matrix[row][col] )
            {
                path.push_back({nrow,ncol});
                int len = 1 + dfs(path,memo,matrix);
                max_len = std::max(max_len,len);
                path.pop_back();
            }
        }
    }
    memo[row][col] = max_len;
    return max_len;
    
}

int longestIncreasingPath(std::vector<std::vector<int>>& matrix)
{
    int longest = INT_MIN;
    std::vector<std::vector<int>> memo( matrix.size(), std::vector<int>( matrix[0].size() , -1 ));
    for(int row=0;row<matrix.size();row++)
    {
        for(int col=0;col<matrix[0].size();col++)
        {
            std::vector<std::pair<int,int>> path;
            path.push_back({row,col});
            int path_length = dfs(path,memo,matrix);
            longest = std::max(longest, path_length);
        }
    }
    return longest;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> matrix =
            {{9,9,4},
             {6,6,8},
             {2,1,1}};
        int expected = 4;
        int result = longestIncreasingPath(matrix);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> matrix =
            {{3,4,5},
             {3,2,6},
             {2,2,1}};
        int expected = 4;
        int result = longestIncreasingPath(matrix);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> matrix =
            {{1}};
        int expected = 1;
        int result = longestIncreasingPath(matrix);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
