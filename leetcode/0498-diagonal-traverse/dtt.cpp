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
#include <algorithm>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

void dumpValues(std::vector<int> values)
{
    bool first = false;
    for( const auto &curr : values )
    {
        if( !first)
            std::cout << ", ";
        first = false;
        std::cout << curr ;
    }
    std::cout << std::endl;
}

std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat)
{
    std::map<int,std::vector<int>> storage;
    for(int row = 0; row<mat.size();row++)
    {
        for(int col = 0;col<mat[0].size();col++)
        {
            storage[row+col].push_back(mat[row][col]);
        }
    }
    std::vector<int> retval;
    int flipper = 1;
    for(const auto citer : storage )
    {
        std::vector<int> nums = citer.second;
        if( flipper % 2 )
        {
            std::reverse(nums.begin(), nums.end());
        }
        for( const auto curr : nums )
        {
            retval.push_back(curr);
        }
        flipper++;
    }
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0498-diagonal-traverse" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
        std::vector<int> expected  = {1,2,4,7,5,3,6,8,9};
        std::vector<int> result = findDiagonalOrder(mat);
        dumpValues(result);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
    {
        std::vector<std::vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
        std::vector<int> expected  = {1,2,4,7,5,3,6,8,9};
        std::vector<int> result = findDiagonalOrder(mat);
        dumpValues(result);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::vector<int>> mat = {{1,2},{3,4}};
        std::vector<int> expected  = {1,2,3,4};
        std::vector<int> result = findDiagonalOrder(mat);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
