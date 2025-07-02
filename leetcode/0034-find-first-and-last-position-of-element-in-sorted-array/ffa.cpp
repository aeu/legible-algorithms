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


// do two binary searchines, one for the first occurrence, one for the
// last

std::vector<int> searchRange(std::vector<int> nums, int target)
{
    if( nums.size() == 0 )
        return { -1,-1 };
    
    int first = -1;
    int last = -1;
    { 
        int low = 0;
        int high = nums.size() -1;
        int mid;
        while( low <= high )
        {
            mid = low + (( high - low ) / 2 );
            if( nums[mid] == target )
            {
                first = mid;
                high = mid - 1;
            }
            else if ( nums[mid] < target )
            {
                low = mid+1;
            }
            else if ( nums[mid] > target )
            {
                high = mid - 1;
            }
        }
    }
    { 
        int low = 0;
        int high = nums.size() -1;
        int mid;
        while( low <= high )
        {
            mid = low + (( high - low ) / 2 );
            if( nums[mid] == target )
            {
                last = mid;
                low = mid + 1;
            }
            else if ( nums[mid] < target )
            {
                low = mid+1;
            }
            else if ( nums[mid] > target )
            {
                high = mid - 1;
            }
        }
    }
    return { first,last };
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #34 - Find First and Last Position of Element in Sorted Array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = {5,7,7,8,8,10};
        std::vector<int> expected = {3,4};
        int target = 8;
        std::vector<int> result = searchRange(nums, target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        // std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = {5,7,7,8,8,10};
        std::vector<int> expected = {-1,-1};
        int target = 6;
        std::vector<int> result = searchRange(nums, target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        // std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = {};
        std::vector<int> expected = {-1,-1};
        int target = 0;
        std::vector<int> result = searchRange(nums, target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        // std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
