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


int findHighestAltitude(const std::vector<int> &numbers)
{
    int highest_altitude = 0;
    int current_altitude = 0;
    for( int current : numbers )
    {
        current_altitude += current;
        highest_altitude = std::max( highest_altitude, current_altitude );
    }
    return highest_altitude;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode 1732 - Find The Highest Altitude" << std::endl;
    {
        std::vector<int> numbers = {-5,1,5,0,-7};
        int highest_altitude = findHighestAltitude(numbers);
        dumpNumbers( numbers);
        std::cout << "Highest Altitude: " << highest_altitude << std::endl;
    }
    {
        std::vector<int> numbers = {-4,-3,-2,-1,4,3,2};
        int highest_altitude = findHighestAltitude(numbers);
        dumpNumbers( numbers);
        std::cout << "Highest Altitude: " << highest_altitude << std::endl;
    }
}
