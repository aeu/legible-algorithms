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

int singleNonDuplicate(std::vector<int>& nums)
{
    if( nums.size() == 1 )
        return nums[0];
    if( nums.size() == 0 )
        return 0;
    
    int low = 0;
    int high = nums.size()-1;
    int mid;
    while( low < high )
    {
        mid = low + (( high - low ) / 2 ) ;
        std::cout << "low: " << low << " mid: " << mid << " high: " << high << std::endl;
        if( mid % 2 )
            mid--;
        if( nums[mid] == nums[mid+1] )
        {
            low = mid+2;
        }
        else
        {
            high = mid;
        }
    }
    std::cout << "DONE low: " << low << " mid: " << mid << " high: " << high << std::endl;
    return nums[low];
}

//    std::cout << "DONE low: " << low << " mid: " << mid << " high: " << high << std::endl;

int main(int argc, char **argv)
{
    std::cout << std::endl << "0540-single-element-in-sorted-array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,1,2,3,3,4,4,8,8};
        int expected = 2;
        int result = singleNonDuplicate(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {3,3,7,7,10,11,11};
        int expected = 10;
        int result = singleNonDuplicate(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1,1,2,2,3,4,4,5,5,6,6,7,7,10,10,11,11};
        int expected = 3;
        int result = singleNonDuplicate(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1,1,2,3,3};
        int expected = 2;
        int result = singleNonDuplicate(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
