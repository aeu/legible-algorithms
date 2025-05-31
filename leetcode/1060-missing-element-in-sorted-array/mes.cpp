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

int mmissingElement(std::vector<int>& nums, int k)
{
    int current = nums[0];
    int missing = k;
    int index = 1;

    while(( missing > 0 ) && ( index < nums.size()))
    {
        current += 1;
        if( current < nums[index] )
        {
            missing--;
        }
        else
        {
            index++;
        }
    }
    if( missing > 0 )
        current += missing;
    return current;
}


void dumpValues(std::vector<int> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << ", ";
        first = false;
        std::cout << std::setw(3) << curr ;
    }
    std::cout << std::endl;
}

int missingElement(std::vector<int>& nums, int k)
{
    int N = nums.size();

    int low = 0;
    int high = N-1;
    int mid = 0; 

    int missing = nums[N - 1] - nums[0] - (N - 1);
    
    if (k > missing )
        return nums[N - 1] + (k - missing);
    
    while( low < high )
    {
        mid = low + ( high - low ) / 2;
        missing = nums[mid] - nums[0] - mid ;

        if( missing >= k )
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
    }
    // at this point, we know that the missing number is after
    // nums[low-1].  so first lets calculate how many numbers are
    // missing between nums[0] and nums[low-1]

    missing = nums[low - 1] - nums[0] - (low - 1);
    return nums[low - 1] + k - missing;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1060-missing-element-in-sorted-array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {4,7,9,10};
        int k = 3;
        int expected = 8;
        int result = missingElement(nums,k);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    //    return 0;
    {
        std::vector<int> nums  = {4,7,9,10,14};
        int k = 1;
        int expected = 5;
        int result = missingElement(nums,k);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1,2,4};
        int k = 3;
        int expected = 6;
        int result = missingElement(nums,k);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
