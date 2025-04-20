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

int numSubarraysWithSum(std::vector<int>& nums, int goal)
{
    std::vector<int> prefix_sums(nums.size(), 0);
    prefix_sums[0] = 0;
    for(int index=1;index<nums.size();index++)
    {
        prefix_sums[index] = prefix_sums[index-1] + nums[index-1];
    }
    std::unordered_map<int,int> prefix_counts;
    prefix_counts[0] = 1;
    int num_subarrays = 0;
    int running_sum = 0;
    for(int index=0;index<nums.size();index++)
    {
        running_sum += nums[index];
        int prefix_goal = running_sum - goal;
        auto piter = prefix_counts.find( prefix_goal );
        if( piter != prefix_counts.end() )
        {
            num_subarrays += piter->second;
        }
        prefix_counts[running_sum]++;
    }
    return num_subarrays;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0930-binary-subarrays-with-sum" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,0,1,0,1};
        int goal = 2;
        int expected = 4;
        int result = numSubarraysWithSum(nums, goal);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {0,0,0,0,0};
        int goal = 0;
        int expected = 15;
        int result = numSubarraysWithSum(nums, goal);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
