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
#include <unordered_set>

void dumpNumbers(const std::vector<int> &numbers )
{ 
    std::cout << "[";
    bool first_time = true;
    for(int current : numbers )
    {
        if( ! first_time )
            std::cout << ", " ;
        std::cout << current ;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}   

std::vector<std::vector<int>> findDifference(std::vector<int>& nums1,
                                             std::vector<int>& nums2) 
{
    std::vector<std::vector<int>> retval;
    std::unordered_set<int> num1_set;
    std::unordered_set<int> num2_set;
    for(int current : nums1 )
    {
        num1_set.insert(current);
    }
    for(int current : nums2 )
    {
        num2_set.insert(current);
    }
    std::vector<int> num1_valids;
    for(int current : nums1 )
    {
        auto insertion_result = num2_set.insert(current);
        if( insertion_result.second )
        {
            num1_valids.push_back( current );
        }
    }
    std::vector<int> num2_valids;
    for(int current : nums2 )
    {
        auto insertion_result = num1_set.insert(current);
        if( insertion_result.second )
        {
            num2_valids.push_back( current );
        }
    }
    retval.push_back(num1_valids);
    retval.push_back(num2_valids);
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode 2215 - Find the Difference of Two Arrays" << std::endl;
    {
        std::vector<int> nums1 = {1,2,3};
        std::vector<int> nums2 = {2,4,6};
        std::vector<std::vector<int> > differences = findDifference(nums1,nums2);
        for( std::vector<int> current : differences )
        {
            dumpNumbers( current);
        }
    } 
    {
        std::vector<int> nums1 = {1,2,3,3};
        std::vector<int> nums2 = {1,1,2,2};
        std::vector<std::vector<int> > differences = findDifference(nums1,nums2);
        for( std::vector<int> current : differences )
        {
            dumpNumbers( current);
        }
    }
    {
    }
}
