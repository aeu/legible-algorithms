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


std::vector<std::vector<int>> findMissingRanges(std::vector<int>& nums, int lower, int upper)
{
    std::vector<std::vector<int>> retval;
    if( nums.size() == 0 )
    {
        retval.push_back({lower,upper});
        return retval;
    }
    if( ( nums[0] - lower ) >= 1 )
    {
        retval.push_back({lower,nums[0]-1});
    }
    for(int index=1;index<nums.size();index++)
    {
        if(( nums[index] - nums[index-1] ) > 1 )
            retval.push_back({nums[index-1]+1,nums[index]-1});
    }
    if(( upper - nums.back() ) >= 1 )
    {
        retval.push_back({nums.back()+1,upper});
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0163-missing-ranges" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2};
        int lower = 0;
        int upper = 9;
        std::vector<std::vector<int>> expected = {{0,0},{3,9}};
        std::vector<std::vector<int>> result   = findMissingRanges(nums,lower,upper);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {0};
        int lower = 0;
        int upper = 9;
        std::vector<std::vector<int>> expected = {{1,9}};
        std::vector<std::vector<int>> result   = findMissingRanges(nums,lower,upper);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {0,1,3,50,75};
        int lower = -10;
        int upper = 99;
        std::vector<std::vector<int>> expected = {{2,2},{4,49},{51,74},{76,99}};
        std::vector<std::vector<int>> result   = findMissingRanges(nums,lower,upper);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {-1};
        int lower = -1;
        int upper = -1;
        std::vector<std::vector<int>> expected = {{}};
        std::vector<std::vector<int>> result   = findMissingRanges(nums,lower,upper);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {};
        int lower = 1;
        int upper = 1;
        std::vector<std::vector<int>> expected = {{1,1}};
        std::vector<std::vector<int>> result   = findMissingRanges(nums,lower,upper);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {-1};
        int lower = -2;
        int upper = -1;
        std::vector<std::vector<int>> expected = {{-2,-2}};
        std::vector<std::vector<int>> result   = findMissingRanges(nums,lower,upper);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
