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


void dumpValues(std::vector<int> nums)
{
    for(int index=0;index<nums.size();index++)
    {
        std::cout << "[" << index << "] - " << nums[index] << std::endl;
    }
}

class NumArray
{
public:
    std::vector<int> prefix_sums;
    
    NumArray(std::vector<int>& nums)
    {
        prefix_sums.resize(nums.size()+1);
        int running_sum = 0;
        prefix_sums[0] = 0;
        for(int index=1;index<=nums.size();index++)
        {
            prefix_sums[index] = prefix_sums[index-1] + nums[index-1];
        }
    }

    
    int sumRange(int left, int right)
    {
        return prefix_sums[right+1] - prefix_sums[left];
    }
};


int main(int argc, char **argv)
{
    std::cout << std::endl << "0303-range-sum-query-immutable" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {-2,0,3,-5,2,-1};
        NumArray na(nums);
        int expected = 1;
        int result = na.sumRange(0,2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";

        expected = -1;
        result = na.sumRange(2,5);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";

        expected = -3;
        result = na.sumRange(0,5);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        

    }
    return 0;
}
