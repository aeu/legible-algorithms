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
#include <set>
#include <unordered_map>
#include <stack>
#include <limits.h>

int climbStairs(int n)
{
    if( n == 0 )
        return 1;
    if( n == 1 )
        return 1;

    int curr = 1;
    int prev = 1;
    int next;
    for(int count=2;count<=n;count++)
    {
        next = curr + prev;
        prev = curr;
        curr = next;
    }
    return next;

}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0070-climbing-stairs" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 2;
        int expected = 2;
        int result = climbStairs(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int n = 3;
        int expected = 3;
        int result = climbStairs(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
