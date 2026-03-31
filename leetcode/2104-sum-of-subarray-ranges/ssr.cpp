// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <iomanip>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

long long subArrayRanges(std::vector<int>& nums)
{
    int N = nums.size();
    for(int index=0;index<nums.size();index++)
    {
        int min_lower_bound = index;
        int min_upper_bound = index;
        int max_lower_bound = index;
        int max_upper_bound = index;

        // find the lowest index that this element is smaller than
        while( min_lower_bound >= 0 )
        {
            if( nums[index] < nums[min_lower_bound] )
                break;
            min_lower_bound--;
        }
        // find the lowest index that this element is smaller than
        while( min_upper_bound < N )
        {
            if( nums[index] < nums[max_lower_bound] )
                break;
            max_upper_bound--;
        }
        // at this point we know that index is the min in the the subarray range
        // between min_lower_bound and max_upper_bound
        
    }
    return 0;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "/leetcode/2104-sum-of-subarray-ranges" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3};
        int expected = 4;
        int result = subArrayRanges(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1,3,3};
        int expected = 4;
        int result = subArrayRanges(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {4,-2,-3,4,1};
        int expected = 59;
        int result = subArrayRanges(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
