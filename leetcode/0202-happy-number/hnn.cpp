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

bool isHappy(int n)
{
    std::unordered_set<int> seen;
    bool keep_going = true;
    int current = n;
    while( keep_going )
    {
        int next = 0;
        while( current )
        {
            int digit = current % 10 ;
            next += ( digit * digit );
            current /= 10;
        }
        if( next == 1 )
            return true;
        if( seen.count( next ) )
            return false;
        seen.insert(next);
        current = next;
    }
    return false;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0202-happy-number" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 19;
        bool expected = true;
        bool result = isHappy(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int n = 2;
        bool expected = false;
        bool result = isHappy(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
