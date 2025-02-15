// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <vector>
#include <queue>


void dumpValues(std::vector<int> values)
{
    bool first_time = true;
    std::cout << "[" ;
    for(auto current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current ;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

void merge(std::vector<int>& nums1,
           int m,
           std::vector<int>& nums2,
           int n)
{
    int n1_index = m - 1;
    int n2_index = n - 1;
    int insertion_point = nums1.size() - 1 ;
    while( ( n1_index >= 0 ) && ( n2_index >= 0 ))
    {
        int left = nums1[n1_index];
        int right = nums2[n2_index];
        if( right > left )
        {
            nums1[insertion_point] = nums2[n2_index];
            n2_index--;
        }
        else
        {
            nums1[insertion_point] = nums1[n1_index];
            n1_index--;
        }
        insertion_point--;
    }
    while( n2_index >= 0 )
    {
        nums1[insertion_point--] = nums2[n2_index--];
    }
    return;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode 88 - Merge Sorted Array" << std::endl;
    {
        std::cout << "Example 1" << std::endl;
        std::vector<int> nums1 = {1,2,3,0,0,0};
        int m = 3;
        std::vector<int> nums2 = {2,5,6};
        int n = 3;
        std::cout << "nums1: " ;
        dumpValues(nums1);
        std::cout << "nums2: " ;
        dumpValues(nums2);
        merge(nums1,m,nums2,n);
        std::cout << "after : ";
        dumpValues(nums1);
    }
    {
        std::cout << "Example 2" << std::endl;
        std::vector<int> nums1 = {1};
        int m = 1;
        std::vector<int> nums2 = {};
        int n = 0;
        std::cout << "nums1: " ;
        dumpValues(nums1);
        std::cout << "nums2: " ;
        dumpValues(nums2);
        merge(nums1,m,nums2,n);
        std::cout << "after : ";
        dumpValues(nums1);
    }
    {
        std::cout << "Example 3" << std::endl;
        std::vector<int> nums1 = {0};
        int m = 0;
        std::vector<int> nums2 = {1};
        int n = 1;
        std::cout << "nums1: " ;
        dumpValues(nums1);
        std::cout << "nums2: " ;
        dumpValues(nums2);
        merge(nums1,m,nums2,n);
        std::cout << "after : ";
        dumpValues(nums1);
    }
    return 0;
}
