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
    int local = x;
    bool first = true;
    int retval = 0;
    while( local != 0 )
    {
        int digit = local % 10;
        if( first == true )
        {
            retval = digit;
            first = false;
        }
        else
        {
            if( retval != 0 )
            {
                // we are going to mutitply retval * 10 and add the digit,
                // which may cause an overflow, so check for that first

                if(( retval > INT_MAX / 10 ) || ( retval == ( INT_MAX / 10 ) && ( digit > ( INT_MAX % 10 ) )))
                    return 0;
                
                if(( retval < INT_MIN / 10 ) || ( retval == ( INT_MIN / 10 ) && ( digit < ( INT_MIN % 10 ) )))
                    return 0;
            }
            retval *= 10;
            retval += digit;
        }
        local /= 10;
    }
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        int x = 901000;
        int expected = 109;
        int result = reverse(x);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl << std::endl << std::endl;
    }
    {
        int x = 123;
        int expected = 321;
        int result = reverse(x);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl << std::endl << std::endl;
    }
    {
        int x = -123;
        int expected = -321;
        int result = reverse(x);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl << std::endl << std::endl;
    }
    {
        int x = 120;
        int expected = 21;
        int result = reverse(x);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl << std::endl << std::endl;
    }
    return 0;
}
