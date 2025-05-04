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


bool isDistinct(std::unordered_map<int,int> &counts)
{
    for(const auto &[key,count] : counts )
    {
        if( count > 1 )
            return false;
    }
    return true;
}

int minimumOperations(std::vector<int>& nums)
{
    std::unordered_map<int,int> counts;
    for(const auto curr : nums )
    {
        counts[curr]++;
    }
    int operations_needed = 0;
    if( isDistinct( counts ) )
        return operations_needed;
    int index=0;
    while( index < nums.size() )
    {
        operations_needed++;

        counts[nums[index++]]--;

        if( index<nums.size() )
        {
            counts[nums[index++]]--;
        }
        
        if( index<nums.size() )
        {
            counts[nums[index++]]--;
        }
        
        if( isDistinct( counts ) )
        {
            return operations_needed;
        }
    }
    return operations_needed;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "3396-minimum-number-of-operations-to-make-elements-in-array-distinct" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {12,14,13,7,1,15,15};
        int expected = 2;
        int result = minimumOperations(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {1,2,3,4,2,3,3,5,7};
        int expected = 2;
        int result = minimumOperations(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {4,5,6,4,4};
        int expected = 2;
        int result = minimumOperations(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {6,7,8,9};
        int expected = 0;
        int result = minimumOperations(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
