// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>

void dumpNumbers(const std::vector<int> &numbers )
{
    bool first_time = true;
    for(int current : numbers )
    {
        if( ! first_time )
            std::cout << ", " ;
        std::cout << current ;
        first_time = false;
    }
    std::cout << std::endl;
}   


int longestSubarrayOfOnes(const std::vector<int> &numbers)
{
    int longest_subarray = 0;
    int current_subarray = 0;
    int start_index = -1;
    size_t end_index = 0;
    int required_drops = 1;
    int did_at_least_one_drop = false;
    while(end_index<numbers.size())
    {
        if( numbers[end_index] == 1 )
        {
            current_subarray++;
        }
        else
        {
            required_drops--;
            did_at_least_one_drop = true;
            if( required_drops != 0 )
            {
                longest_subarray = std::max(longest_subarray, current_subarray );
                start_index++;
                while( numbers[start_index] == 1 )
                {
                    current_subarray--;
                    start_index++;
                }
                required_drops++;
            }
        }
        end_index++;
    }
    longest_subarray = std::max(longest_subarray, current_subarray);
    // covers the case where we didn't hit any zeroes
    if( did_at_least_one_drop == false )
        longest_subarray--;
    return longest_subarray;
}


int main(int argc, char **argv)
{
    float max_consecutive_ones;

    std::cout << "Leetcode 1493 - Longest Subarray of 1's After Deleting One Element" << std::endl;
    {
        std::vector<int> numbers = { 1,1,0,1};
        dumpNumbers(numbers);
        max_consecutive_ones = longestSubarrayOfOnes(numbers);
        std::cout << "Longest Subarray of 1's : " << max_consecutive_ones << std::endl;
    }
    {
        std::vector<int> numbers = { 0,1,1,1,0,1,1,0,1};
        dumpNumbers(numbers);
        max_consecutive_ones = longestSubarrayOfOnes(numbers);
        std::cout << "Longest Subarray of 1's : " << max_consecutive_ones << std::endl;

    }
    {
        std::vector<int> numbers = { 1,1,1};
        dumpNumbers(numbers);
        max_consecutive_ones = longestSubarrayOfOnes(numbers);
        std::cout << "Longest Subarray of 1's : " << max_consecutive_ones << std::endl;

    }
}
