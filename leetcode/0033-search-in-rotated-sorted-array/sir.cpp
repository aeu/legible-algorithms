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

int search(std::vector<int>& nums, int target)
{
    int low = 0;
    int high = nums.size()-1;
    int mid;
    while( low <= high )
    {
        mid = low + (( high - low ) / 2 );
        if( nums[mid] == target )
            return mid;
        
        if( nums[low] <= nums[mid] )
        {
            // low side is sorted
            if( ( nums[low] <= target ) && ( target <= nums[mid] ))
            {
                high = mid-1;
            }
            else
            {
                low = mid+1;
            }
        }
        else
        {
            // high side is sorted
            if( ( nums[mid] < target ) && ( target <= nums[high] ))
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
    }
    return -1;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #33 - Search in Rotated Sorted Array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = { 4,5,6,7,0,1,2};
        int target = 0;
        int expected = 4;
        int result = search(nums,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
    {
        std::vector<int> nums = { 4,5,6,7,0,1,2};
        int target = 3;
        int expected = 4;
        int result = search(nums,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 1 };
        int target = 0;
        int expected = -1;
        int result = search(nums,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return -1;
}
