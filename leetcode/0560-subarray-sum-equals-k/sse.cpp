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

int subarraySum(std::vector<int>& nums, int k)
{
    std::unordered_map<int,int> prefixes;
    int running_sum = 0;
    int subarray_count = 0;
    prefixes[0]++;
    for(const auto &curr: nums )
    {
        running_sum += curr;
        int goal_prefix = running_sum - k;
        auto siter = prefixes.find( goal_prefix );
        if( siter != prefixes.end() )
        {
            subarray_count += siter->second;
        }
        prefixes[running_sum]++;
    }
    return subarray_count;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0560-subarray-sum-equals-k" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,1,1};
        int k = 2;
        int expected = 2;
        int result = subarraySum(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {1,2,3};
        int k = 3;
        int expected = 2;
        int result = subarraySum(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {1,-1,0};
        int k = 0;
        int expected = 3;
        int result = subarraySum(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
