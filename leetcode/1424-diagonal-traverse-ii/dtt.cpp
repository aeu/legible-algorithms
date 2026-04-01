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
#include <algorithm>
#include <limits.h>

void dumpValues(std::vector<int> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << ", ";
        first = false;
        std::cout << std::setw(3) << curr ;
    }
    std::cout << std::endl;
}


// the trick here is that we know that on any diagonal in a matrix
// (going SW<->NE ), the sum of the row and column are equal.  So we
// walk through all the inputs and group the points by that sum, then
// traverse them out at the end.  A map would also have worked, but
// that would have been slower.

std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& nums)
{
    std::vector<std::vector<int>> grouped_values;
    grouped_values.resize(1);
    for(int row = 0; row<nums.size();row++)
    {
        for(int col = 0; col<nums[row].size();col++)
        {
            int index = row + col;
            if( index >= grouped_values.size() )
                grouped_values.resize(index+1);
            grouped_values[index].push_back( nums[row][col] );
        }
    }
    std::vector<int> retval;
    for(const auto &current_grouping : grouped_values )
    {
        for(int index = current_grouping.size()-1;index>=0;index--)
        {
            auto curr = current_grouping[index]; 
            retval.push_back( curr );
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1424-diagonal-traverse-ii" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> nums  = {{1,2,3},{4,5,6},{7,8,9}};
        std::vector<int> expected = { 1,4,2,7,5,3,8,6,9 };
        std::vector<int> result = findDiagonalOrder( nums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::vector<int>> nums  = {{1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16}};
        std::vector<int> expected = { 1,6,2,8,7,3,9,4,12,10,5,13,11,14,15,16};
        std::vector<int> result = findDiagonalOrder( nums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
