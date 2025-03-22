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
#include <unordered_map>
#include <unordered_set>


bool containsNearbyDuplicate(std::vector<int>& nums, int k)
{
    std::unordered_map<int,int> seen;
    for(int index=0;index<nums.size();index++)
    {
        int current = nums[index];
        auto it = seen.find( current );
        if( it == seen.end() )
        {
            seen[current] = index;
        }
        else
        {
            int other_index = it->second;
            if( abs ( index - other_index ) <= k )
            {
                return true;
            }
            else
            {
                seen[current] = index;
            }
        }
    }
    return false;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #219 - Contains Duplicate II" << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = { 1,2,3,1};
        int k = 3;
        bool expected = true;
        bool result = containsNearbyDuplicate(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 1,0,1,1};
        int k = 1;
        bool expected = true;
        bool result = containsNearbyDuplicate(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 1,2,3,1,2,3};
        int k = 2;
        bool expected = false;
        bool result = containsNearbyDuplicate(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
}
