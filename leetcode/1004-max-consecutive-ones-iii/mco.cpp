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


int maxConsecutiveOnes(const std::vector<int> &numbers,
                       const int allowed_flips )
{
    size_t window_start = -1;
    size_t window_end = 0;
    int consecutive_ones = 0;
    int max_consecutive_ones = 0;
    int current_flips = allowed_flips;
    
    while( window_end < numbers.size() )
    {
        if( numbers[window_end] == 1 )
        {
            consecutive_ones++;
        }
        else
        {
            if( current_flips > 0 )
            {
                current_flips--;
                consecutive_ones++;
            }
            else
            {
                // we have no more flips.  capture the current consecutive_ones count
                max_consecutive_ones = std::max(max_consecutive_ones, consecutive_ones );
                window_start++;
                // bring tali of window forward until we hit a 0
                while ( numbers[window_start] != 0 )
                {
                    consecutive_ones--;
                    window_start++;
                }
                // we found a zero, so now we have one to spare and keep going forward.
                current_flips--;
            }
        }
        window_end++;
    }
    return max_consecutive_ones;
}


int main(int argc, char **argv)
{
    float max_consecutive_ones;

    std::cout << "Leetcode 1004 - Max Consecutive Ones III" << std::endl;
    {
        std::vector<int> numbers = { 1,1,1,0,0,0,1,1,1,1,0};
        int k = 2;
        dumpNumbers(numbers);
        std::cout << "Counting with k: " << k << std::endl;
        max_consecutive_ones = maxConsecutiveOnes(numbers, k );
        std::cout << "Max consecutive ones : " << max_consecutive_ones << std::endl;
    }
    {
        std::vector<int> numbers = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
        int k = 3;
        dumpNumbers(numbers);
        std::cout << "Counting with k: " << k << std::endl;
        max_consecutive_ones = maxConsecutiveOnes(numbers, k );
        std::cout << "Max consecutive ones : " << max_consecutive_ones << std::endl;
    }
}
