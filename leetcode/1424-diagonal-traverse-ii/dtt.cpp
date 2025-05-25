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


std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& nums)
{
    int nrows = nums.size();
    int ncols = 0;
    for(const auto &crow : nums )
    {
        int ccols = crow.size();
        ncols = std::max( ncols, ccols );
    }
    int max_index = 0;
    std::vector<std::vector<int>> list(100001,std::vector<int>());
    for(int row = 0; row<nrows;row++)
    {
        for(int col = 0; col<nums[row].size();col++)
        {
            int index = row + col;
            max_index = std::max(max_index,index);
            list[index].push_back( nums[row][col] );
        }
    }
    std::vector<int> retval;
    for(int lindex=0;lindex<=max_index;lindex++)
    {
        const std::vector<int> &values = list[lindex];
        for(int index = values.size()-1;index>=0;index--)
        {
            auto curr = values[index]; 
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
