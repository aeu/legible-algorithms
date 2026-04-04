// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <iomanip>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

int longestMountain(std::vector<int>& arr)
{
    int max_hill = 0;
    int uphill = 0;
    int downhill = 0;
    bool going_down = false;
    for(int index = 1; index < arr.size(); index++)
    {
        if( arr[index] > arr[index-1] )
        {
            if( going_down == true )
            {
                // we were going downhill, so lets end the current
                // hill.
                going_down = false;
                if( ( uphill != 0 ) && ( downhill != 0 ))
                {
                    max_hill = std::max((uphill + downhill + 1), max_hill);
                }
                downhill = 0;
                uphill = 0;
            }
            uphill++;
        }
        else if( arr[index] < arr[index-1] )
        {
            // we can't have a down without an up before it
            if( uphill > 0 )
            {
                going_down = true;
                downhill++;
            }
        }
        else
        {
            // we are on a plateau so whatever hill we were on (if
            // any) just ended
            if( ( uphill != 0 ) && ( downhill != 0 ))
            {
                max_hill = std::max((uphill + downhill + 1), max_hill);
            }
            uphill = 0;
            downhill = 0;
        }
    }
    // because the loop may have anded on a downhill.
    if( ( uphill != 0 ) && ( downhill != 0 ))
    {
        max_hill = std::max(( uphill + downhill + 1 ),max_hill);
    }
    return max_hill;
}





int main(int argc, char **argv)
{
    std::cout << std::endl << "0845-longest-mountain-in-array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {0,1,2,3,4,5,4,3,2,1,0};
        int expected = 11;
        int result = longestMountain(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {2,1,4,7,3,2,5};
        int expected = 5;
        int result = longestMountain(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {2,2,2};
        int expected = 0;
        int result = longestMountain(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {7,4,8};
        int expected = 0;
        int result = longestMountain(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {0,2,0,2,1,2,3,4,4,1};
        int expected = 3;
        int result = longestMountain(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
