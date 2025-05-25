// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <iomanip>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>


bool search(std::vector<int>& nums, int target)
{
    if( nums.size() == 0 )
        return false;
            
    if(( nums.size() == 1 ) && ( nums[0] == target ))
        return true;
    
    int mid;
    int low = 0;
    int high = nums.size() - 1;
    while( low < high )
    {
        mid = low + ( high - low ) / 2 ;
        int lval = nums[low];
        int mval = nums[mid];
        int hval = nums[high];
        if( ( lval == target ) || ( mval == target ) || ( hval == target ))
            return true;


        // if the middle value is less than the high value, then we
        // know that the right half is sorted increaseing, which means
        // there's no valley in there.  so just search it normally
        if( mval < hval )
        {
            // the target is on the high side
            if(( target > mval ) && ( target <= hval ))
            {
                low = mid+1;
            }
            // the target is on the low side
            else
            {
                high = mid;
            }
        }
        // the high side is decreasing, which means the low side is
        // decreasing
        else if( mval > hval )
        {
            // the target is somewhere between low and middle
            if(( lval <= target ) && ( target < mval ))
            {
                high = mid;
            }
            // the target is somewhere btween middle and high
            else
            {
                low = mid+1;
            }
        }
        // we can't tell what direction the array is going, so just
        // shrink it a bit until we can figure it out.
        else if( mval == hval )
        {
            high--;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0081-search-in-rotated-sorted-array-ii" << std::endl << std::endl;
    int test_case = 1;
    {
        int target = 0;
        std::vector<int> nums  = {2,5,6,0,0,1,2};
        bool expected = true;
        bool result = search(nums,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int target = 3;
        std::vector<int> nums  = {2,5,6,0,0,1,2};
        bool expected = false;
        bool result = search(nums,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
