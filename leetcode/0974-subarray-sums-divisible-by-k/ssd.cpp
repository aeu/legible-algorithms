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

int subarraysDivByK(std::vector<int>& nums, int k)
{
    std::unordered_map<int,int> mod_counts;
    std::vector<int> prefix_sums(nums.size()+1,0);
    prefix_sums[0] = 0;
    mod_counts[0]++;
    for(int index=1;index<=nums.size();index++)
    {
        prefix_sums[index] = prefix_sums[index-1] + nums[index-1];
        // here we are handling negative sums, which would then in turn
        // have negative mods.
        int mod = (( prefix_sums[index] % k ) + k ) % k ;
        mod_counts[mod]++;
    }
    int subarray_count = 0;
    for(auto it : mod_counts )
    {
        // If there's more than 2 subarrays with same mod value, so
        // there difference would be mod 0, matching the requirement.
        // So we calculate how many combinations of them there are.

        if( it.second >= 2 )
            subarray_count += ( it.second * ( it.second - 1 )) / 2;
    }
    return subarray_count;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0974-subarray-sums-divisible-by-k" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {4,5,0,-2,-3,1};
        int k = 5;
        int expected = 7;
        int result = subarraysDivByK(nums, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {5};
        int k = 9;
        int expected = 0;
        int result = subarraysDivByK(nums, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
