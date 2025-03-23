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


void dumpValues(std::vector<int> values )
{
    bool first_time = true;
    std::cout << "[" ;
    for( int current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}


int findPeakElement(std::vector<int>& nums)
{
    int low = 0;
    int high = nums.size() - 1;
    while( low < high )
    {
        int mid = low + ((high-low)/2);
        if ( nums[mid] < nums[mid+1] )
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #162 - Find Peak Element" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = { 1,2,3,1 };
        int expected = 2;
        int result = findPeakElement(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 1,2,1,3,5,6,4};
        int expected = 5;
        int result = findPeakElement(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return -1;
}
