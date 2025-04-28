// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>

int majorityElement(std::vector<int>& nums)
{
    int candidate;
    int count = 0;
    for(int index = 0; index < nums.size();index++)
    {
        if( index == 0 )
        {
            candidate = nums[index];
            count++;
            continue;
        }
        if( nums[index] == candidate )
        {
            count++;
        }
        else
        {
            count--;
            if( count < 0 )
                candidate = nums[index];
        }
    }
    return candidate;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "Leetcode 169 - Majority Element" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> vnums = {3,2,3};
        int expected = 3;
        int result = majorityElement( vnums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> vnums = { 2,2,1,1,1,2,2};
        int expected = 2;
        int result = majorityElement( vnums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
}
