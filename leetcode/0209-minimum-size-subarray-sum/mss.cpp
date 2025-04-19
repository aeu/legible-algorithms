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
    // first build the prefix sums array
    std::vector<int> prefix_sums(nums.size()+1,0);
    prefix_sums[0] = 0;
    for(int index=1;index<=nums.size();index++)
    {
        prefix_sums[index] = prefix_sums[index-1] + nums[index-1];
    }
    int min_len = INT_MAX;
    // if there's a subarray that hits the sum, its got to start and
    // end somewhere.
    for(int index=0;index<prefix_sums.size();index++)
    {
        // for this start point
        int curr = prefix_sums[index];
        // calculate what the next sum has to be in order to hit the target
        int target_sum = curr + target;
        // do a binary search to find the first possible place where this hits
        int low  = index+1;
        int high = prefix_sums.size() -1;
        int mid;
        while( low < high )
        {
            mid = low + ( ( high - low ) / 2 );
            if( prefix_sums[mid] < target_sum )
                low = mid+1;
            else
                high = mid;
        }
        // now see if the binary search actually hit a valid point
        // (the subarray may not exist.  If it does, get the size of
        // the subarray and see if its smaller than what we have found
        // so far
        if(( low < prefix_sums.size() ) && ( prefix_sums[low] >= target_sum ))
        {
            int length = low - index;
            min_len = std::min(min_len, length);
        }
    }
    return ( min_len == INT_MAX ) ? 0 : min_len  ;
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
