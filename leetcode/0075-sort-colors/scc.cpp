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
#include <unordered_map>
#include <stack>
#include <limits.h>

void sortColors(std::vector<int>& nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size()-1;

    while( mid <= high )
    {
        if( nums[mid] == 0 )
        {
            std::swap( nums[mid], nums[low] );
            low++;mid++;
        }
        else if ( nums[mid] == 1 )
        {
            mid++;
        }
        else
        {
            std::swap( nums[mid], nums[high] );
            high--;
        }
    }
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC75 Sort Colours" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {2,0,2,1,1,0};
        std::vector<int> expected = { 0,0,1,1,2,2};
        sortColors(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == nums ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {2,0,1};
        std::vector<int> expected = { 0,1,2};
        sortColors(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == nums ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
