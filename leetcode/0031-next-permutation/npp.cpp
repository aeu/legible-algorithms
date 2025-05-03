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


// Knuth's algorithm L.

void nextPermutation(std::vector<int>& nums)
{
    // Scan R to L until you find the first place where nums[i] <
    // nums[i+1];

    int ipivot = -1;
    for(int index=nums.size()-2;index>=0;index--)
    {
        if( nums[index] < nums[index+1] )
        {
            ipivot = index;
            break;
        }
    }

    // no pivot was found, so just reverse and exit

    if( ipivot == -1 )
    {
        std::reverse(nums.begin(), nums.end());
        return;
    }

    // scan R to L, stopping at ipivot, until you find the first place
    // where nums[j] is > nums[i], this is the j pivot.

    int jpivot = -1;
    for(int index = nums.size()-1;index>ipivot;index--)
    {
        if( nums[index] > nums[ipivot] )
        {
            jpivot = index;
            break;
        }
    }

    // swap the elements on the i and j pivot points.
    std::swap(nums[ipivot],nums[jpivot]);

    // now reverse everything from i+1 to the end of the sequence
    std::reverse( nums.begin()+ipivot+1, nums.end());
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> result  = {1,2,3};
        std::vector<int> expected = {1,3,2};
        nextPermutation(result);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> result  = {3,2,1};
        std::vector<int> expected = {1,2,3};
        nextPermutation(result);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> result  = {1,1,5};
        std::vector<int> expected = {1,5,1};
        nextPermutation(result);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
