// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>

void dumpValues(std::vector<int> &nums)
{
    bool first_time = true;
    std::cout << "[" ;
    for(auto current : nums )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}



int majorityElement(std::vector<int>& nums)
{
    int majority_count = 0;
    int majority_element = 0;
    std::unordered_map<int,int> counts;
    for(int index=0;index<nums.size();index++)
    {
        int current = nums[index];
        counts[current]++;
        if( counts[current] > majority_count )
        {
            majority_count = counts[current];
            majority_element = current;
        }
    }
    return majority_element;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode 169 - Majority Element" << std::endl;
    {
        std::cout << "Example 1" << std::endl;
        std::vector<int> vnums = {3,2,3};
        int majority_element = majorityElement( vnums );
        dumpValues(vnums);
        std::cout << "Majority element: " << majority_element << std::endl;
    }
    {
        std::cout << "Example 2" << std::endl;
        std::vector<int> vnums = { 2,2,1,1,1,2,2};
        int majority_element = majorityElement( vnums );
        dumpValues(vnums);
        std::cout << "Majority element: " << majority_element << std::endl;
    }
}
