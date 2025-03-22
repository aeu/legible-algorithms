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


void dumpValues(std::vector<int> values)
{
    for(auto current : values )
    {
        std::cout << current << ", " ;
    }
    std::cout << std::endl;
}

std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::unordered_map<int,int> comps;
    std::vector<int> retval;
    for(int index=0;index<nums.size();index++)
    {
        int complement = target - nums[index];
        auto it = comps.find( complement );
        if( it == comps.end() )
        {
            comps[ nums[index] ] = index;
        }
        else
        {
            retval.push_back( index );
            retval.push_back( it->second );
            return retval;
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #1 - Two Sum" << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = {2,7,11,15};
        std::vector<int> expected = { 0,1 };
        int target = 9;
        std::vector<int> result = twoSum(nums,target);
        std::sort(result.begin(),result.end());
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //  std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = {3,2,4};
        std::vector<int> expected = { 1,2 };
        int target = 6;
        std::vector<int> result = twoSum(nums,target);
        std::sort(result.begin(),result.end());
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //  std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = {3,3};
        std::vector<int> expected = { 0,1 };
        int target = 6;
        std::vector<int> result = twoSum(nums,target);
        std::sort(result.begin(),result.end());
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //  std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return -1;
}
