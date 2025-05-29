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


bool threeConsecutiveOdds(std::vector<int>& arr)
{
    int count = 0;
    for(const auto &curr : arr )
    {
        if( curr % 2 )
        {
            count++;
            if( count >= 3 )
                return true;
        }
        else
        {
            count = 0;
        }
    }
    return false;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1550-three-consecutive-odds" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {2,4,6,1};
        bool expected = false;
        bool result = threeConsecutiveOdds(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {1,2,34,3,4,5,7,23,12};
        bool expected = true;
        bool result = threeConsecutiveOdds(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
