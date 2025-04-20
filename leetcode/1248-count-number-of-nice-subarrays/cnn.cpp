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

int numberOfSubarrays(std::vector<int>& nums, int k)
{
    std::unordered_map<int,int> psums;
    int running_sum    = 0;
    int subarray_count = 0;
    psums[0]++;
    for(int index=0;index<nums.size();index++)
    {
        running_sum += nums[index] % 2 ;
        int goal = running_sum - k;
        auto piter = psums.find( goal );
        if( piter != psums.end() )
        {
            subarray_count += piter->second;
        }
        psums[running_sum]++;
    }
    return subarray_count;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1248-count-number-of-nice-subarrays" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,1,2,1,1};
        int k = 3;
        int expected = 2;
        int result = numberOfSubarrays(nums, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {2,4,6};
        int k = 1;
        int expected = 0;
        int result = numberOfSubarrays(nums, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {2,2,2,1,2,2,1,2,2,2};
        int k = 2;
        int expected = 16;
        int result = numberOfSubarrays(nums, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
