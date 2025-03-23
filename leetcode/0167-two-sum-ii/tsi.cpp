// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& numbers, int target)
{
    int low = 0;
    int high = numbers.size()-1;
    while( low < high )
    {
        int sum = numbers[low] + numbers[high];
        if( sum == target )
        {
            return { low+1,high+1};
        }
        else if( sum > target )
            high--;
        else
            low++;
    }
    return {} ;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode 167 - Two Sum II, Input Array is Sorted" << std::endl;
    int test_case = 1;
    {
        std::vector<int> numbers = { 2,7,11,15 };
        std::vector<int> expected = { 1, 2 };
        int target = 9;
        std::vector<int> result = twoSum(numbers, target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> numbers = { 2,3,4 };
        std::vector<int> expected = { 1, 3 };
        int target = 6;
        std::vector<int> result = twoSum(numbers, target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> numbers = { -1,0 };
        std::vector<int> expected = { 1, 2 };
        int target = -1;
        std::vector<int> result = twoSum(numbers, target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
}
