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

int longestOnes(std::vector<int>& nums, int k)
{
    int head = 0;
    int tail = 0;
    int num_flips = 0;
    int mco = 0;
    while( head < nums.size() )
    {
        if( nums[head] == 0 )
            num_flips++;

        while( num_flips > k )
        {
            if( nums[tail] == 0 )
            {
                num_flips--;
            }
            tail++;
        }
        mco = std::max(mco,head-tail+1);
        head++;
    }
    return mco;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,1,1,0,0,0,1,1,1,1,0};
        int k = 2;
        int expected = 6;
        int result = longestOnes(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
        int k = 3;
        int expected = 10;
        int result = longestOnes(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
