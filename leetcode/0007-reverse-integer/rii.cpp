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

int reverse(int x)
{
    long local = x;
    local = abs(x);
    bool first = true;
    long retval = 0;
    while( local > 0 )
    {
        int digit = local % 10;
        if( first == true )
        {
            retval = digit;
            first = false;
        }
        else
        {
            retval *= 10;
            retval += digit;
        }
        local /= 10;
    }
    if( x < 0 )
        retval *= -1;
    if( ( retval < INT_MIN ) || ( retval > INT_MAX ))
        return 0;
    return (int)retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        int x = 123;
        int expected = 321;
        int result = reverse(x);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int x = -123;
        int expected = -321;
        int result = reverse(x);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int x = 120;
        int expected = 21;
        int result = reverse(x);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
