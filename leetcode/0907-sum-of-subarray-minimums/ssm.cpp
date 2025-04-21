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

int sumSubarrayMins(std::vector<int>& arr)
{
    
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0907-sum-of-subarray-minimums" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> arr  = {3,1,2,4};
        int expected = 17;
        int result = sumSubarrayMins(arr);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> arr  = {11,81,94,43,3};
        int expected = 444;
        int result = sumSubarrayMins(arr);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
