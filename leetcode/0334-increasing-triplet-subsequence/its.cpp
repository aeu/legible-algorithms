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
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>

bool increasingTriplet(std::vector<int> &nums)
{
    int first  = INT_MAX;
    int second = INT_MAX;
    int third  = INT_MAX;
    
    for( auto current : nums )
    {
        if( current > second )
        {
            return true;
        }
        if( current < first )
        {
            first = current;
            continue;
        }
        if( current > first )
        {
            second = current;
            continue;
        }
    }
    return false;
}


int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::vector<int> nums = { 1,2,3,4,5 };
        bool expected = true;
        bool result = increasingTriplet( nums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 5,4,3,2,1 };
        bool expected = false;
        bool result = increasingTriplet( nums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 2,1,5,0,4,6 };
        bool expected = true;
        bool result = increasingTriplet( nums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 1,1,-2,6 };
        bool expected = false;
        bool result = increasingTriplet( nums );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
}
