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
    for(size_t index = 0; index<numbers.size();index++)
    {
        if( ! first_time )
            printf(",");
        std::cout << numbers[index];
        first_time = false;
    }
    std::cout << std::endl;
}


float maximumAverageSubarray(const std::vector<int> &numbers,
                           const int array_length)
{
    if( numbers.size() < array_length )
        return 0;
    int start = 0;
    int end = array_length;
    float current_sum;
    float max_avs = 0;
    while( end <= numbers.size() )
    {
        current_sum = 0;
        for(int index=start;index<end;index++)
        {
            current_sum += numbers[index];
        }
        start++;
        end++;
        current_sum = current_sum / array_length;
        max_avs = std::max( max_avs, current_sum );
    }
    return max_avs;
}

int main(int argc, char **argv)
{
    float max_avs;

    std::cout << "Leetcode 0643 - Maximum Average Subarray I" << std::endl;
    {
        std::vector<int> numbers = { 1,12,-5,-6,50,3 };
        dumpNumbers(numbers);
        max_avs = maximumAverageSubarray(numbers, 4 );
        std::cout << "Maximum Average Subarray : " << max_avs << std::endl;
    }
    {
        std::vector<int> numbers = { 5 };
        dumpNumbers(numbers);
        max_avs = maximumAverageSubarray(numbers, 1 );
        std::cout << "Maximum Average Subarray : " << max_avs << std::endl;
    }
}
