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


int findMaxConsecutiveOnes(std::vector<int>& nums)
{
    int max = INT_MIN;
    int running = 0;
    for(const auto &curr: nums )
    {
        if ( curr == 1 )
        {
            running++;
            max = std::max(max,running);
        }
        else
        {
            running = 0;
        }
    }
    if( max != INT_MIN )
        return max;
    return 0;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0485-max-consecutive-ones" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,1,0,1,1,1};
        int expected = 3;
        int result = findMaxConsecutiveOnes(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1,0,1,1,0,1};
        int expected = 2;
        int result = findMaxConsecutiveOnes(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
