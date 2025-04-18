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

int pivotIndex(std::vector<int>& nums)
{
    int allsum = 0;
    for(const auto &curr : nums )
    {
        allsum += curr;
    }
    int strictly_left = 0;
    for(int index=0;index<nums.size();index++)
    {
        int strictly_right = allsum - strictly_left - nums[index];
        if( strictly_left == strictly_right )
            return index;
        strictly_left += nums[index];
    }
    return -1;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0724-find-pivot-index" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,7,3,6,5,6};
        int expected = 3;
        int result = pivotIndex(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {1,2,3};
        int expected = -1;
        int result = pivotIndex(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {2,1,-1};
        int expected = 0;
        int result = pivotIndex(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
