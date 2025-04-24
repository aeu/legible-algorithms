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


int largestAltitude(const std::vector<int> &gain)
{
    int highest_altitude = 0;
    int current_altitude = 0;
    for( const auto &current : gain )
    {
        current_altitude += current;
        highest_altitude = std::max( highest_altitude, current_altitude );
    }
    return highest_altitude;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "Leetcode 1732 - Find The Highest Altitude" << std::endl << std::endl;
    int test_case = 1;
    { 
        std::vector<int> numbers = {-5,1,5,0,-7};
        int expected = 1;
        int result = largestAltitude(numbers);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    { 
        std::vector<int> numbers = {-4,-3,-2,-1,4,3,2};
        int expected = 0;
        int result = largestAltitude(numbers);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
}
