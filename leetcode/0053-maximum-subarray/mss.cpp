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

// walk through the numbers and keep track of the biggest sum as we
// go.  if the current sum ever goes negative, restart the sum at
// where we are at now (because everything that has come before has
// already been captured) and keep going

int maxSubArray(std::vector<int> &nums )
{
    int max_sum = nums[0];
    int current_sum = nums[0];
    for(int index=1;index<nums.size();index++)
    {
        if( current_sum < 0 )
        {
            current_sum = nums[index];
        }
        else
        {
            current_sum += nums[index];
        }
        max_sum = std::max( current_sum, max_sum );
    }
    return max_sum;
}



int main(int argc, char **argv)
{
    std::cout << "Leetcode #53 - Maximum Subarray" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
        int expected = 6;
        int result = maxSubArray(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = {1};
        int expected = 1;
        int result = maxSubArray(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = {5,4,-1,7,8};
        int expected = 23;
        int result = maxSubArray(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
