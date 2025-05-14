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

int maxSubArrayLen(std::vector<int>& nums, int k)
{
    int max_size = 0;
    std::unordered_map<long long,int> prefix_sums;
    prefix_sums[0]  = -1;
    long long running_sum =  0;
    for(int index=0;index<nums.size();index++)
    {
        running_sum +=nums[index];
        auto psiter = prefix_sums.find(running_sum);
        // store the first location of the prefix sum
        if( psiter == prefix_sums.end() )
            prefix_sums[running_sum] = index;
        // see if there's a prefix sum stored that allows for an
        // existence of a subarray
        psiter = prefix_sums.find( running_sum - k );
        if( psiter != prefix_sums.end() )
        {
            // its location was
            int prefix_location = psiter->second;
            // so the current subarray length is
            int current_size = index - prefix_location;
            max_size = std::max( max_size, current_size );
        }
    }
    return max_size;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0325-maxium-size-subarray-sum-equals-k" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,-1,5,-2,3};
        int k = 3;
        int expected = 4;
        int result = maxSubArrayLen(nums, k);

        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n\n";
    }
    {
        std::vector<int> nums  = {-2,-1,2,1};
        int k =1;
        int expected = 2;
        int result = maxSubArrayLen(nums, k);

        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n\n";
    }
    return 0;
}
