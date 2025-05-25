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
#include <stack>
#include <cmath>


bool isPossibleToEatAll(std::vector<int>& piles,
                        int bph,
                        int num_hours)
{
    int hours_needed = 0;
    for(const auto pile : piles )
    {
        int hours_for_pile = std::ceil ( static_cast<double>(pile) / static_cast<double>(bph) );
        hours_needed += hours_for_pile;
    }
    return hours_needed <= num_hours;
}

int minEatingSpeed(std::vector<int>& piles, int available_hours)
{
    int low  = 1;
    int high = *std::max_element(piles.begin(), piles.end());
    int mid;
    while( low < high )
    {
        mid = low + ( high - low ) / 2;
        if( isPossibleToEatAll( piles, mid, available_hours ))
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
    }
    return low;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "Leetcode #875 - Koko Eating Bananas" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> piles = {3,6,7,11};
        int h = 8;
        int expected = 4;
        int result = minEatingSpeed(piles,h);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> piles = {30,11,23,4,20};
        int h = 5;
        int expected = 30;
        int result = minEatingSpeed(piles,h);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> piles = {30,11,23,4,20};
        int h = 6;
        int expected = 23;
        int result = minEatingSpeed(piles,h);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return -1;
}
