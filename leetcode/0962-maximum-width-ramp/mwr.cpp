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
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>


// we are trying to find the biggest distance between i and j where
// nums[i] <= nums[j]

int maxWidthRamp(std::vector<int>& nums)
{
    std::stack<int>  gstack;
    // loop through all the nymbers going from left to right
    for(int index=0;index<nums.size();index++)
    {
        // push to the stack if the stack is empty (because any number
        // will do in that case) or if the current number is less than
        // the number pointed to by whats on the top of the stack.  So
        // by the time we are done the stack will have all the indexes
        // that were lower than every number before them
        if ( gstack.empty() || nums[index] < nums[gstack.top()] )
        {
            gstack.push(index);
        }
    }
    int maxwramp = 0;
    // now go through all the numbers, this time from right to left.
    for(int index = nums.size() -1 ; index >= 0 ; index--)
    {
        // here we check to see if the current number is greater than
        // the number at the top of the stack.  If it is, calculate
        // the difference between the current index and the index on
        // the top of the stack (which is the index of the latest candidate
        // in the series whose value is lower than all earlier candidates
        while( ! gstack.empty() &&
               ( nums[gstack.top()] <= nums[index]) )
        {
            // get the distance between these numbers and track the
            // biggest so far.
            maxwramp = std::max( maxwramp, index - gstack.top());
            gstack.pop();
        }
    }
    return maxwramp;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = {6,0,8,2,1,5};
        int expected = 4;
        int result   = maxWidthRamp(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums = {9,8,1,0,1,9,4,0,4,1};
        int expected = 7;
        int result   = maxWidthRamp(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
