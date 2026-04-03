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

void dumpValues(std::vector<int> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << ", ";
        first = false;
        std::cout << std::setw(3) << curr ;
    }
    std::cout << std::endl;
}

int missingElement(std::vector<int>& nums, int k)
{
    int N = nums.size();

    int low = 0;
    int high = N-1;
    int mid = 0; 

    // first figure out how many numbers are missing in general.
    // Since the input is sorted, we can just subtract the first
    // number from the last one and then subtract how many actual
    // numbers there are.
    // For example: Given the array [4,7,9,10] we can see that 5, 6
    // and 8 are missing.  10 - 4 - ( 4 - 1 ) = 3.
    
    int missing_number_count = nums[N - 1] - nums[0] - (N - 1);
    
    if (k > missing_number_count )
        // we want the kth missing number, but that is higher than
        // the number of numbers that are actually missing, so return
        // whatever number is after the last by that many.
        //
        // For example: Given the array [4,7,9,10] if we ask for the
        // 5th missing number, but we can see that 5, 6 and 8 are
        // missing, so the 5 missing number is 2 past the last, or 12.
        // (I think this is weird but it's what LC is asking for).
        return nums[N - 1] + (k - missing_number_count);


    // now do a binary search.  at each step, we calculate the number
    // of numbers missing between the 0th element and the current mid
    // in our binary search.
    while( low < high )
    {
        mid = low + ( high - low ) / 2;
        missing_number_count = nums[mid] - nums[0] - mid ;

        if( missing_number_count >= k )
        {
            high = mid;
        }
        else
        {
            low = mid+1;
        }
    }
    // at this point, we know that the kth missing number is greater
    // than nums[low-1] and less than or equal to nums[low], so first
    // lets calculate how many numbers are missing between nums[0] and
    // nums[low-1].  Then we add k to that number and subtract the
    // amount of numbers that were missing before nums[low-1] and that
    // will give us the actual missing number.
    //
    // Given the follwing
    // [5 6 8 9 12 13], k = 2
    // At the end of our search low would be 4
    // so we would be returning
    // 9 + 2 - 1 = 10
    missing_number_count = nums[low - 1] - nums[0] - (low - 1);
    return nums[low - 1] + k - missing_number_count;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1060-missing-element-in-sorted-array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {4,7,9,10};
        int k = 3;
        int expected = 8;
        int result = missingElement(nums,k);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    //    return 0;
    {
        std::vector<int> nums  = {4,7,9,10,14};
        int k = 1;
        int expected = 5;
        int result = missingElement(nums,k);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1,2,4};
        int k = 3;
        int expected = 6;
        int result = missingElement(nums,k);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
