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

int rob(std::vector<int> &nums)
{
    if( nums.size() == 0 )
        return 0;
    if( nums.size() == 1 )
        return nums[0];
    
    int back_two = nums[0];
    int back_one = std::max(nums[0],nums[1]);

    for( int index=2;index<nums.size();index++)
    {
        int loot = std::max( back_one, back_two + nums[index] );
        back_two = back_one;
        back_one = loot;
    }
    return back_one;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0198-house-robber" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3,1};
        int expected = 4;
        int result = rob(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {2,7,9,3,1};
        int expected = 12;
        int result = rob(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
