// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>


int minSubArrayLen(int target, std::vector<int>& nums)
{
    int min_length = INT_MAX;
    int left = -1;
    int right = 0;
    int running_sum = 0;

    while(( left < right ) && ( right < nums.size() ))
    {
        running_sum += nums[right];
        while( running_sum >= target )
        {
            min_length = std::min( min_length, ( right - left ) );
            left++;
            running_sum -= nums[left];
        }
        right++;
    }
    if( min_length != INT_MAX )
        return min_length;
    return 0;
}



int main(int argc, char **argv)
{
    std::cout << "Leetcode 209 - Minimum Size Subarray Sum" << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = { 2,3,1,2,4,3 };
        int expected = 2;
        int target = 7;
        int result = minSubArrayLen(target,nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 1,4,4 };
        int expected = 1;
        int target = 4;
        int result = minSubArrayLen(target,nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 1,1,1,1,1,1,1,1};
        int expected = 0;
        int target = 11;
        int result = minSubArrayLen(target,nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
}
