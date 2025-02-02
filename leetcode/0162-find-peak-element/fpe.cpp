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
#include <unordered_set>


void dumpValues(std::vector<int> values )
{
    bool first_time = true;
    std::cout << "[" ;
    for( int current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

int findPeakElement(std::vector<int>& nums)
{
    size_t mid;
    size_t low = 0;
    size_t hight = nums.size() - 1 ;
    while( low < hight )
    {
        mid = low + ( ( hight - low ) / 2 );
        if( nums[mid] > nums[mid+1] )
        {
            hight = mid;
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
    std::cout << "Leetcode #162 - Find Peak Element" << std::endl << std::endl;
    {
        std::cout << "Example 1" << std::endl;
        std::vector<int> values = {1,2,3,1};
        dumpValues(values);
        int peak = findPeakElement( values );
        std::cout << "Peak Element : " << peak << std::endl;
    }
    {
        std::cout << "Example 2" << std::endl;
        std::vector<int> values = {1,2,1,3,5,6,4};
        dumpValues(values);
        int peak = findPeakElement( values );
        std::cout << "Peak Element : " << peak << std::endl;
    }
    return -1;
}
