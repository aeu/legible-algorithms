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


int partition(std::vector<int> &nums, int left, int right)
{
    int pivot = nums[right];
    int i = left;
    int j;

    for(j = left; j < right; j++ )
    {
        if( nums[j] <= pivot )
        {
            std::swap( nums[i], nums[j] );
            i++;
        }
    }       
    std::swap( nums[i], nums[j] );
    return i;
}


int quickSelect(std::vector<int> &nums, int left, int right, int k )
{
    if( left == right )
        return nums[left];

    int pivot_index = partition(nums,left,right);

    if( pivot_index == k )
        return nums[k];
    
    if ( k < pivot_index )
        return quickSelect(nums,left,pivot_index-1,k);
    
    return quickSelect(nums,pivot_index+1,right,k);
}

int findKthLargest(std::vector<int>& nums, int k)
{
    return quickSelect(nums,0,nums.size()-1,nums.size()-k);
}

int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::vector<int> nums = { 3,2,1,5,6,4};
        int k = 2;
        int expected = 5;
        int result = findKthLargest(nums, k );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 3,2,3,1,2,4,5,5,6};
        int k = 4;
        int expected = 4;
        int result = findKthLargest(nums, k );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
}
