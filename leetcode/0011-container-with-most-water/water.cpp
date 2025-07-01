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


void dumpHeight(const std::vector<int> &height)
{
    bool first_time = true;
    for(int current : height )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << std::endl;
}

int maxArea(const std::vector<int> &height)
{
    if( height.size() < 2 )
        return 0;

    int max_volume = 0;
    int left = 0;
    int right = height.size() - 1;
    while(left < right )
    {
        int current_volume = std::min( height[left], height[right] ) * ( right - left  );
        max_volume = std::max( max_volume, current_volume );
        if( height[left] < height[right] )
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
        std::vector<int> height = { 1,8,6,2,5,4,8,3,7 };
        dumpHeight(height);
        int most_water = maxArea(height);
        std::cout << "Most water is " << most_water << std::endl;
    }
    {
        std::vector<int> height = { 1,1 };
        dumpHeight(height);
        int most_water = maxArea(height);
        std::cout << "Most water is " << most_water << std::endl;
    }
}
