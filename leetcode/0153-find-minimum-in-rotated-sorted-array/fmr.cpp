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

// 0 1 2 3 4 5 6
// 3 4 5 1 2 
// 4 5 6 7 0 1 2

int findMin(std::vector<int>& nums)
{
    int low = 0;
    int high = nums.size()-1;
    int mid = low + (( high - low ) / 2 );
    while( low < high )
    {
        if( nums[mid] > nums[high] )
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
        mid = low + (( high - low ) / 2 );
    }
    return nums[low];
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0153-find-minimum-in-rotated-sorted-array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {3,4,5,1,2};
        int expected = 1;
        int result = findMin(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {4,5,6,7,0,1,2};
        int expected = 0;
        int result = findMin(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {11,13,15,17};
        int expected = 11;
        int result = findMin(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
