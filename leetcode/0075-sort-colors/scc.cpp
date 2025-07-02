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


// define a low and high pointer to point to the start and the end of
// the array, and a seeker to walk through the array left to right if
// the seeker finds a low push it low if it finds a high, push it high
// (and adjust output pointers appropriately).  if its middle, leave
// as is.

void sortColors(std::vector<int>& nums)
{
    int low_insertion_point = 0;
    int seeker = 0;
    int high_insertion_point = nums.size()-1;

    while( seeker <= high_insertion_point )
    {
        if( nums[seeker] == 0 )
        {
            std::swap( nums[seeker], nums[low_insertion_point] );
            low_insertion_point++;seeker++;
        }
        else if ( nums[seeker] == 1 )
        {
            seeker++;
        }
        else
        {
            std::swap( nums[seeker], nums[high_insertion_point] );
            high_insertion_point--;
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
