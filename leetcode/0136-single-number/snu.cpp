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


void dumpValues(std::vector<int> &values)
{
    bool first_time = true;
    std::cout << "[" ;
    for(auto current : values )
    {
        if( ! first_time )
            std::cout << ",";
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

int singleNumber(std::vector<int>& nums) {
     int retval = 0;
     for(auto current : nums )
     {
         retval ^= current;
     }
     return retval;
 }

int main(int argc, char **argv)
{
    std::cout << "Leetcode #136 - Single Number" << std::endl;
    {
        std::cout << "Example 1 " << std::endl;
        std::vector<int> nums = { 2,2,1 };
        int sn = singleNumber(nums);
        std::cout << "SN: " << sn << std::endl;

    }
    {
        std::cout << "Example 2 " << std::endl;
        std::vector<int> nums = { 4,1,2,1,2};
        int sn = singleNumber(nums);
        std::cout << "SN: " << sn << std::endl;

    }
    {
        std::cout << "Example 3 " << std::endl;
        std::vector<int> nums = { 1 };
        int sn = singleNumber(nums);
        std::cout << "SN: " << sn << std::endl;

    }
    return -1;
}
