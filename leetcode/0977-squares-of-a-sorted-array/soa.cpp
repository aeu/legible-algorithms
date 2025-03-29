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

void dumpValues(std::vector<int> nums)
{
    for(auto curr : nums )
    {
        std::cout << curr << ", " ;
    }
    std::cout << std::endl;
}

std::vector<int> sortedSquares(std::vector<int> &nums)
{
    std::vector<int> retval(nums.size());
    int left = 0;
    int right = nums.size()-1;
    int lsquared;
    int rsquared;
    int writer = nums.size()-1;
    lsquared = nums[left] * nums[left];
    rsquared = nums[right] * nums[right];

    while( left <= right )
    {
        if( rsquared >= lsquared )
        {
            retval[writer] = rsquared;
            writer--;
            right--;
            if( left <= right )
                rsquared = nums[right] * nums[right];
        }
        else if ( lsquared >= rsquared )
        {
            retval[writer] = lsquared;
            writer--;
            left++;
            if( left <= right )
                lsquared = nums[left] * nums[left];
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "Leetcode 977 - Squares of a Sorted Array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {-4,-1,0,3,10};
        std::vector<int> expected  = {0,1,9,16,100};
        std::vector<int> result  = sortedSquares(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {1};
        std::vector<int> expected  = {1};
        std::vector<int> result  = sortedSquares(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
