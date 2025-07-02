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
#include <unordered_map>
#include <stack>
#include <limits.h>


// keep track of the furthest we can jump from any position.  as we
// walk through the numbers if we ever get to a loop index that is
// past the furthest we would have been able to jump to in the past,
// exit out false

bool canJump(std::vector<int>& nums)
{
    int furthest = 0;
    for(int index=0;index<nums.size();index++)
    {
        furthest = std::max( furthest, (index+nums[index]) );
        if((index >= furthest) && ( furthest < nums.size()-1))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0055-jump-game" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {0};
        bool expected = true;
        bool result = canJump(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {0,1};
        bool expected = false;
        bool result = canJump(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {2,3,1,1,4};
        bool expected = true;
        bool result = canJump(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {3,2,1,0,4};
        bool expected = false;
        bool result = canJump(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
