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


//    1 2 3 4 5 8 9 7 6 4 3 6 
//    0 1 2 3 4 5 6 7 8 9 10 11
int peakIndexInMountainArray(std::vector<int>& arr)
{
    int low = 0;
    int high = arr.size() - 1;
    int mid;
    while( low < high )
    {
        mid = low + ((high-low)/2);
        int mid_height = arr[mid];
        int next_height = arr[mid+1];
        
        if( mid_height < next_height )
        {
            low = mid+1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0852-peak-index-in-a-mountain-array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {18,29,38,59,98,100,99,98,90};
        int expected = 5;
        int result = peakIndexInMountainArray(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {40,48,61,75,100,99,98,39,30,10};
        int expected = 4;
        int result = peakIndexInMountainArray(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {0,1,0};
        int result = peakIndexInMountainArray(nums);
        int expected = 1;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {0,2,1,0};
        int result = peakIndexInMountainArray(nums);
        int expected = 1;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {0,10,5,2};
        int expected = 1;
        int result = peakIndexInMountainArray(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = { 1, 2, 3, 4, 5, 8, 9, 7, 6, 4, 3, 2 };
        int expected = 6;
        int result = peakIndexInMountainArray(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
