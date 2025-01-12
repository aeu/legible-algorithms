// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>


void dumpHeights(const std::vector<int> &heights)
{
    bool first_time = true;
    for(int current : heights )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << std::endl;
}

int calculateMostWater(const std::vector<int> &heights)
{
    if( heights.size() < 2 )
        return 0;

    int max_volume = 0;
    int left = 0;
    int right = heights.size() - 1;
    while(left < right )
    {
        int current_volume = std::min( heights[left], heights[right] ) * ( right - left  );
        max_volume = std::max( max_volume, current_volume );
        if( heights[left] < heights[right] )
            left++;
        else
            right--;
    }
    return max_volume;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #11 - Container with Most Waters" << std::endl << std::endl;
    {
        std::vector<int> heights = { 1,8,6,2,5,4,8,3,7 };
        dumpHeights(heights);
        int most_water = calculateMostWater(heights);
        std::cout << "Most water is " << most_water << std::endl;
    }
    {
        std::vector<int> heights = { 1,1 };
        dumpHeights(heights);
        int most_water = calculateMostWater(heights);
        std::cout << "Most water is " << most_water << std::endl;
    }
}
