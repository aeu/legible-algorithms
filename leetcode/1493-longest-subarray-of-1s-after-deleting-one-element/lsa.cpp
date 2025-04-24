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

int longestSubarray(std::vector<int>& nums)
{
    int left = 0;
    int right = 0;
    int longest_subarray = 0;
    int num_zeroes = 0;
    while(right < nums.size())
    {
        if( nums[right] == 0 )
        {
            num_zeroes++;
            if( num_zeroes > 1 )
            {
                while(left <= right )
                {
                    if( nums[left] == 0 )
                    {
                        num_zeroes--;
                        left++;
                        break;
                    }
                    left++;
                }
            }
        }
        int length = right - left;
        longest_subarray = std::max( longest_subarray, length );
        right++;
    }
    return longest_subarray;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = { 1,1,0,1};
        int expected = 3;
        int result = longestSubarray(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 0,1,1,1,0,1,1,0,1};
        int expected = 5;
        int result = longestSubarray(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 1,1,1};
        int expected = 2;
        int result = longestSubarray(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}




