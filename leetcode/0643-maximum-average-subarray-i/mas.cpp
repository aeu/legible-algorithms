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

void dumpNumbers(const std::vector<int> &numbers )
{
    bool first_time = true;
    for(size_t index = 0; index<numbers.size();index++)
    {
        if( ! first_time )
            std::cout << "," ;
        std::cout << numbers[index];
        first_time = false;
    }
    std::cout << std::endl;
}


double findMaxAverage(std::vector<int>& nums, int k)
{
    if( nums.size() < k )
        return -1;

    if( k < 1 )
        return -1;
    
    int start = 0;
    int end = k-1;
    double current_sum;
    double max_avs = 0;

    current_sum = 0;
    for(int index=0;index<=end;index++)
    {
        current_sum += nums[index];
    }
    max_avs = current_sum;
    while( end < nums.size() - 1 )
    {
        end++;
        current_sum = current_sum + nums[end];
        current_sum = current_sum - nums[start];
        start++;
        max_avs = std::max( max_avs, current_sum );
    }
    return max_avs / k;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode 0643 - Maximum Average Subarray I" << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = { 1,12,-5,-6,50,3 };
        int k = 4;
        double expected = 12.75;
        double result = findMaxAverage(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 5 };
        int k = 1;
        double expected = 5.0;
        double result = findMaxAverage(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
}
