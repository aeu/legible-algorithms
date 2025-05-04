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


int longestMountain(std::vector<int>& arr)
{
    int max_width = 0;
    for(int index=1;index<arr.size()-1;index++)
    {
        if(( arr[index-1] < arr[index]) && (arr[index] > arr[index+1]))
        {
            int left = index-1;
            int right = index+1;
            while(( (left-1) >= 0 ) && ( arr[left-1] < arr[left] ))
            {
                left--;
            }
            while(((right+1) < arr.size() ) && ( arr[right+1] < arr[right] ))
            {
                right++;
            }
            int width = right - left + 1;
            max_width = std::max( max_width, width );
        }       
    }
    return max_width;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0845-longest-mountain-in-array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {0,1,2,3,4,5,4,3,2,1,0};
        int expected = 11;
        int result = longestMountain(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {2,1,4,7,3,2,5};
        int expected = 5;
        int result = longestMountain(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {2,2,2};
        int expected = 0;
        int result = longestMountain(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
