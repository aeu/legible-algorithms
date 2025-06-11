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

bool isMonotonic(std::vector<int>& nums)
{
    if(( nums.size() == 0 ) || ( nums.size() == 1 ))
        return true;
    
    bool mono_increasing     = true;
    bool did_fail_increasing = false;
    bool mono_decreasing     = true;
    bool did_fail_decreasing = false;
    
    for(int index=1;index<nums.size();index++)
    {
        if(( ! did_fail_increasing ) && ( nums[index] < nums[index-1] ))
        {
            mono_increasing = false;
            did_fail_increasing = true;
        }
        if(( ! did_fail_decreasing) && ( nums[index] > nums[index-1] ))
        {
            mono_decreasing = false;
            did_fail_decreasing = true;
        }
    }
    return ( mono_decreasing || mono_increasing );
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0896-monotonic-array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,2,3};
        bool expected = true;
        bool result = isMonotonic( nums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {6,5,4,4};
        bool expected = true;
        bool result = isMonotonic( nums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1,3,2};
        bool expected = false;
        bool result = isMonotonic( nums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
