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

int fib(int n)
{
    if ( n == 1 )
        return 1;
    if( n == 2 )
        return 1;
    
    long long curr = 1;
    long long prev = 1;
    long long next = 0; //
    
    int local = n;
    while ( local > 2 )
    {
        next = curr + prev;
        prev = curr;
        curr = next;
        local--;
    }
    return next;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0509-fibonacci-number" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 2;
        int expected = 1;
        int result = fib(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int n = 3;
        int expected = 2;
        int result = fib(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int n = 4;
        int expected = 3;
        int result = fib(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
