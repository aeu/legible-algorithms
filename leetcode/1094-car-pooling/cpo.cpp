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


bool carPooling(std::vector<std::vector<int>>& trips, int capacity)
{
    std::vector<int> deltas(11,0);
    for(const auto curr : trips )
    {
        int pass = curr[0];
        int from = curr[1];
        int to   = curr[2];
        deltas[from] += pass;
        deltas[to]   -= pass;
    }
    int running_cap = 0;
    for( auto curr: deltas )
    {
        running_cap += curr;
        if( running_cap > capacity )
            return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1094-car-pooling" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> trips = {{2,1,5},{3,3,7}};
        int capacity = 4;
        bool expected = false;
        bool result = carPooling(trips,capacity);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> trips = {{2,1,5},{3,3,7}};
        int capacity = 5;
        bool expected = true;
        bool result = carPooling(trips,capacity);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> trips = {{2,1,5},{3,5,7}};
        int capacity = 3;
        bool expected = true;
        bool result = carPooling(trips,capacity);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
