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

int findMaxLength(std::vector<int>& nums)
{
    int max_size = 0;
    std::unordered_map<int,int> prefix_sums;
    int running_sum = 0;
    prefix_sums[0] = -1;
    for(int index=0;index<nums.size();index++)
    {
        int current = nums[index];
        // convert 0s to neg 1
        if( current == 0 )
            running_sum += -1;
        else
            running_sum += nums[index];

        // check to see if this runing sum has already been found
        auto psiter = prefix_sums.find( running_sum );
        if( psiter == prefix_sums.end() )
            prefix_sums[running_sum] = index;

        // what prefix sum would need to exist to allow the current
        // sum to be 0 ?  (equal # of 1s and 0s )
        // see if its already been found
        psiter = prefix_sums.find(running_sum);
        if( psiter != prefix_sums.end() )
        {
            // which means our current subarray size is...
            int current_size = index - psiter->second;
            max_size = std::max(current_size, max_size);
        }
    }
    return max_size;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0525-contiguous-array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {0,1};
        int expected = 2;
        int result = findMaxLength(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {0,1,0};
        int expected = 2;
        int result = findMaxLength(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {0,1,1,1,1,1,0,0,0};
        int expected = 6;
        int result = findMaxLength(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
