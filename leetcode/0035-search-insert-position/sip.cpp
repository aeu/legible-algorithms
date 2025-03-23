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

int searchInsert(std::vector<int>& nums, int target)
{
    int low = 0;
    int mid;
    int high = nums.size()-1;
    while( low < high )
    {
        mid = low + (( high - low ) / 2 );
        int current = nums[mid];
        if( current == target )
            return mid;
        if( current < target )
            low = mid+1;
        else
            high = mid;
    }
    if ( nums[low] < target )
        return low+1;
    return low;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode 15 - 3Sum" << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = { 1,3,5,6 };
        int target = 5;
        int expected = 2;
        int result = searchInsert(nums, target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 1,3,5,6 };
        int target = 2;
        int expected = 1;
        int result = searchInsert(nums, target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 1,3,5,6 };
        int target = 7;
        int expected = 4;
        int result = searchInsert(nums, target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
}
