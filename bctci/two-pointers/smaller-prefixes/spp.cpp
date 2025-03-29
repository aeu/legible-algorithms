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
#include <stack>
#include <limits.h>

bool doWork(std::vector<int> &nums)
{
    int full_sum = 0;
    int half_sum = 0;
    for(int index=0;index<nums.size();index++)
    {
        if( index % 2 )
        {
            half_sum += nums[index];
            full_sum += nums[index];
        }
        else
        {
            full_sum += nums[index];
            if( half_sum > full_sum )
                return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "Smaller Prefixes" << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,2,-1};
        bool expected = true;
        bool result = doWork(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {1,2,-2,1,3,5};
        bool expected = false;
        bool result = doWork(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
