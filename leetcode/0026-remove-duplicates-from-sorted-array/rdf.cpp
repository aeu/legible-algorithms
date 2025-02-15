// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <vector>
#include <queue>


void dumpValues(std::vector<int> values,
                int count)
{
    bool first_time = true;
    std::cout << "[" ;
    int dumped = 0;
    for(auto current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current ;
        first_time = false;
        dumped++;
        if( dumped == count )
            break;
    }
    std::cout << "]" << std::endl;
}

int removeDuplicates(std::vector<int>& nums)
{
    int count = 0;
    int seek_point = 0;
    int insertion_point = 0;
    while(seek_point < nums.size() )
    {
        if( seek_point == 0 )
        {
            nums[insertion_point++] = nums[seek_point];
            count++;
        }
        else if ( nums[seek_point] != nums[seek_point-1] )
        {
            nums[insertion_point++] = nums[seek_point];
            count++;
        }
        seek_point++;
    }
    return count;
}
int main(int argc, char **argv)
{
    std::cout << "Leetcode 26 - Remove Duplicates" << std::endl;
    {
        std::cout << "Example 1" << std::endl;
        std::vector<int> nums = {1,1,2};
        std::cout << "Nums: " ;
        dumpValues(nums,nums.size());
        int count = removeDuplicates(nums);
        std::cout << "After : ";
        dumpValues(nums,count);
    }
    {
        std::cout << "Example 2" << std::endl;
        std::vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
        std::cout << "Nums: " ;
        dumpValues(nums,nums.size());
        int count = removeDuplicates(nums);
        std::cout << "After : ";
        dumpValues(nums, count);
    }
    {
        std::cout << "Example 3" << std::endl;
        std::vector<int> nums = {1,2};
        std::cout << "Nums: " ;
        dumpValues(nums,nums.size());
        int count = removeDuplicates(nums);
        std::cout << "After : ";
        dumpValues(nums, count);
    }
    return 0;
}
