// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>
#include <vector>
#include <iostream>

void dumpValues(std::vector<int> &nums,
                int new_count)
{
    int count = 0;
    bool first_time = true;
    std::cout << "[" ;
    for(auto current : nums )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        count++;
        if( count >= new_count )
            break;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

int removeDuplicates(std::vector<int> &nums)
{
    if( nums.size() <=2 )
        return nums.size();
    
    int minus_two       = 0;
    int minus_one       = 1;
    int read_point      = 2;
    int insertion_point = 2;
    int new_length = 2;
    while( read_point < (int)nums.size() )
    {
        if(( nums[read_point] == nums[minus_one] ) && ( nums[read_point] == nums[minus_two] ))
        {
            read_point++;
            continue;
        }
        nums[insertion_point] = nums[read_point];
        minus_two++;
        minus_one++;
        read_point++;
        insertion_point++;
        new_length++;
    }
    return new_length;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode 0080 - Remove Duplicates from Sorted Array II" << std::endl;
    {
        std::cout << "Example 1" << std::endl;
        std::vector<int> vnums = {1,1,1,2,2,3};
        dumpValues(vnums,vnums.size());
        int new_count = removeDuplicates( vnums );
        dumpValues(vnums,new_count);
    }
    {
        std::cout << "Example 2" << std::endl;
        std::vector<int> vnums = { 0,0,1,1,1,1,2,3,3};
        dumpValues(vnums,vnums.size());
        int new_count = removeDuplicates( vnums );
        dumpValues(vnums,new_count);
    }
}
