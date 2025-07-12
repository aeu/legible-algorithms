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


// the way this works is that we are walking from right to left
// through the array.  at each step of the way we are comparing the
// current number to what is on the top of the stack.  if the current
// number is greater than what is on the top of the stack (i.e. the
// current number is greater than some number to the right of it) then
// we save that number and keep popping.
//
// this means that we now have a number in nums and we also have a
// number to its right, that is lower.  if as we keep going, we then
// find a number that is lower than the one that was lower and to the
// right, then we have the 132 pattern.


bool find132pattern(std::vector<int>& nums)
{
    std::stack<int> mstack;
    int two_value = INT_MIN;
    for(int index=nums.size()-1;index>=0;index--)
    {
        if( nums[index] < two_value )
            return true;
        while( ! mstack.empty()
               && ( nums[index] > mstack.top() ))
        {
            two_value = mstack.top();
            mstack.pop();
        }
        mstack.push( nums[index] );
    }
    return false;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0456-132-pattern" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3,4};
        bool expected = false;
        bool result = find132pattern(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {3,1,4,2};
        bool expected = true;
        bool result = find132pattern(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {-1,3,2,0};
        bool expected = true;
        bool result = find132pattern(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
