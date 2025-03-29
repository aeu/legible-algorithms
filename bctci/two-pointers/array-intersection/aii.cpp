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

std::vector<int> doWork(std::vector<int> &arr1,
                        std::vector<int> &arr2)
{
    std::vector<int> output;
    int arr1_index = 0;
    int arr2_index = 0;

    while ( (arr1_index < arr1.size()) && (arr2_index < arr2.size() ))
    {
        if( arr1[arr1_index] == arr2[arr2_index] )
        {
            output.push_back( arr1[arr1_index]);
            arr1_index++; arr2_index++;
        }
        else if( arr1[arr1_index] < arr2[arr2_index] )
        {
            arr1_index++;
        }
        else
        {
            arr2_index++;
        }
    }
    return output;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "BCTCI - Array Intersection 27.3" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> arr1  = {1,2,3};
        std::vector<int> arr2  = {1,3,5};
        std::vector<int> expected = {1,3};
        std::vector<int> result = doWork(arr1,arr2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> arr1  = {1,1,1};
        std::vector<int> arr2  = {1,1};
        std::vector<int> expected = {1,1};
        std::vector<int> result = doWork(arr1,arr2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //    std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
