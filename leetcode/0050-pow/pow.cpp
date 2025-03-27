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
#include <stack>

//  8 ^ 4
//  ( 8 * 8 ) ^ 2



double myPow(double x, int n)
{
    long long N = n;
    
    if( N == 0 )
        return 1;

    if( N < 0 )
        return 1 / myPow(x,-N);

    
    if(( N % 2 ) == 0 )
        return myPow( ( x * x ), N / 2);
    return myPow( (x * x ), N / 2 ) * x;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #50 - Pow" << std::endl << std::endl;
    int test_case = 1;
    {
        double x = 2.0;
        int n = 10;
        double result = myPow(x,n);
        double expected = 1024;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        double x = 2.1;
        int n = 3;
        double result = myPow(x,n);
        double expected = 9.261;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        double x = 2.0;
        int n = -2;
        double result = myPow(x,n);
        double expected = 0.25;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
