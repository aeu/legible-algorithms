// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

// sort the input array immediately.  then that gives us an
// increaseing array to work with.  Starting with the first number, we
// can now left/right the remaining numbers, and if the sum is less
// than 0 increase left and if its greater than 0 decrease right.
// There's some extra logic in there for duplicates as well.

std::vector<std::vector<int>> threeSum(std::vector<int>& nums)
{
    std::vector<std::vector<int>> retval;
    int left;
    int right;
    std::sort(nums.begin(),nums.end());
    for(int index=0;index<nums.size()-2;index++)
    {
        if(( index > 0 ) && ( nums[index] == nums[index-1] ))
            continue;
        
        left = index+1;
        right = nums.size()-1;
        while( left < right ) 
        {
            int sum = nums[index] + nums[left] + nums[right];
            if( sum == 0 )
            {
                retval.push_back ({ nums[index] , nums[left], nums[right] });
                left++;
                right--;
                while( ( nums[left] == nums[left-1] ) && ( left < right ))
                {
                    left++;
                }
                while( ( nums[right] == nums[right+1] ) && ( left < right ))
                {
                    right--;
                }
            }
            else if ( sum < 0 )
                left++;
            else
                right--;
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode 15 - 3Sum" << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = { -1,0,1,2,-1,-4};
        std::vector<std::vector<int>> expected = {{-1,-1,2},{-1,0,1}};
        std::vector<std::vector<int>> result = threeSum(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums = { 0,1,1};
        std::vector<std::vector<int>> expected = {};
        std::vector<std::vector<int>> result = threeSum(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums = { 0,0,0 };
        std::vector<std::vector<int>> expected = {{0,0,0}};
        std::vector<std::vector<int>> result = threeSum(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums = { 2,-3,0,-2,-5,-5,-4,1,2,-2,2,0,2,-4,5,5,-10 };
        std::vector<std::vector<int>> expected = {{-10,5,5},{-5,0,5},{-4,2,2},{-3,-2,5},{-3,1,2},{-2,0,2}};
        std::vector<std::vector<int>> result = threeSum(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
}
