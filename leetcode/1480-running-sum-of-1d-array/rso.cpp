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

std::vector<int> runningSum(std::vector<int> &nums)
{
    std::vector<int> retval;
    retval.push_back(nums[0]);
    for(int index=1;index<nums.size();index++)
    {
        retval.push_back( nums[index] + retval.back() );
    }
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "1480-running-sum-of-1d-array/" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3,4};
        std::vector<int> expected = {1,3,6,10};
        std::vector<int> result = runningSum(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {1,1,1,1,1};
        std::vector<int> expected = {1,2,3,4,5};
        std::vector<int> result = runningSum(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {3,1,2,10,1};
        std::vector<int> expected = {3,4,6,16,17};
        std::vector<int> result = runningSum(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
