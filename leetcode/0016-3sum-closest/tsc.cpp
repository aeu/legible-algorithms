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
#include <algorithm>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>


int threeSumClosestBinary(std::vector<int> &nums, int target)
{
    int best_delta_so_far = INT_MAX;
    int closest_to_date = 0;
    int retval = 0;
    if( nums.size() == 3 )
    {
        for(const auto curr : nums )
        {
            retval += curr;
        }
        return retval;
    }
    std::sort( nums.begin(), nums.end() );
    for(int lowest = 0; lowest<nums.size()-2;lowest++)
    {
        for(int second = lowest+1; second<nums.size()-1;second++)
        {
            int base = nums[lowest] + nums[second];
            int low = second+1;
            int high = nums.size()-1;
            while( low <= high )
            {
                 int mid = low + ((high - low ) / 2);
                 int sum = base + nums[mid];
                 int delta = abs( target - sum );
                 if( sum == target )
                     return sum;
                 
                 if( delta < best_delta_so_far )
                 {
                     best_delta_so_far = delta;
                     closest_to_date = sum;
                 }
              
                 if( sum >= target )
                     high = mid-1;
                 else
                     low = mid+1;
            }
        }
    }
    return closest_to_date;
}

int threeSumClosest(std::vector<int> &nums, int target)
{
    int best_delta_so_far = INT_MAX;
    int closest_to_date = 0;
    if( nums.size() == 3 )
    {
        int sum = 0;
        for(const auto curr : nums )
        {
            sum += curr;
        }
        return sum;
    }
    std::sort( nums.begin(), nums.end() );
    for(int index = 0; index<nums.size()-2;index++)
    {
        int low = index+1;
        int high = nums.size()-1;
        while( low < high )
        {
            int sum= nums[index] + nums[low] + nums[high];
            if( sum == target )
                return sum;

            int delta = abs( target - sum );
            if( delta < best_delta_so_far )
            {
                best_delta_so_far = delta;
                closest_to_date = sum;
            }
            
            if( sum >= target )
                high--;
            else
                low++;
        }
    }
    return closest_to_date;
}

// -4 -1 1 2
int main(int argc, char **argv)
{
    std::cout << std::endl << "0016-3sum-closest" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {-1,2,1,-4};
        int target   = 1;
        int expected = 2;
        int result   = threeSumClosest(nums, target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {0,0,0};
        int target   = 1;
        int expected = 0;
        int result   = threeSumClosest(nums, target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
