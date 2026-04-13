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


bool checkSubarraySum(std::vector<int> &nums, int k )
{
    std::unordered_map<int,int> prefix_sums;
    prefix_sums[0] = -1;
    int running_sum = 0;
    for(int index = 0; index < nums.size(); index++)
    {
        // check for the edge case that k = 0, which will be
        // satisfied by any two consecutive 0s.
        if( k == 0 && index > 0 )
        {
            if( ( nums[index] == 0 ) && ( nums[index-1] == 0 ))
                return true;
        }

        // calculate the running sum as we process each number.  each
        // step of the way we calculate the mod with k, and then
        // search in the prefix sums to see if that is in there
        // already.
        running_sum += nums[index];
        auto modres = running_sum % k;
        auto piter = prefix_sums.find(modres);
        if( piter != prefix_sums.end() )
        {
            // it is.  so that means that everything between that
            // point and now is a multiple of k
            if(( index - piter->second ) >= 2 )
                // make sure it's size is at least 2
                return true;
        }
        else
        {
            // store for next pass.  we put the store in an else
            // because we want to store the furthest index back.
            prefix_sums[modres] = index;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0523-continuous-subarray-sum" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {23,2,4,6,7};
        int k = 6;
        bool expected = true;
        bool result = checkSubarraySum(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {23,2,6,4,7};
        int k = 6;
        bool expected = true;
        bool result = checkSubarraySum(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {23,2,6,4,7};
        int k = 13;
        bool expected = false;
        bool result = checkSubarraySum(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
