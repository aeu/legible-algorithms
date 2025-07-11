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


bool containsDuplicate(std::vector<int> &nums)
{
    std::unordered_map<int,int> counts;
    for(const auto curr : nums )
    {
        counts[curr]++;
        if( counts[curr] > 1 )
            return true;
    }
    return false;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0217-contains-duplicate" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3,1};
        bool expected = true;
        bool result = containsDuplicate(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1,2,3,4};
        bool expected = false;
        bool result = containsDuplicate(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1,1,1,3,3,4,3,2,4,2};
        bool expected = true;
        bool result = containsDuplicate(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
