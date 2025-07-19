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

int divide(int dividend, int divisor) 
{
    if ( dividend == 0 )
        return 0;
    int sign = 1;
    if( ( dividend > 0 ) && ( divisor > 0))
    {
        sign = 1;
    }
    else if ( ( dividend < 0) && ( divisor < 0 ))
    {
        sign = 1;
    }
    else
    { 
        sign = -1;
    }
    long retval = 0;
    long ldividend = abs((long)dividend);
    long ldivisor = abs((long)divisor);

    while( ldividend >= ldivisor ) 
    {
        long temp = ldivisor;
        long multiple = 1;
        while((ldividend >= ( temp << 1 )))
        {
            temp <<= 1;
            multiple <<= 1;
        }
        ldividend -= temp;
        retval += multiple;
    }
    return retval * sign    ;        
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0029-divide-two-integers" << std::endl << std::endl;
    int test_case = 1;
    {
        int expected = 3;
        int dividend = 10;
        int divisor = 3;
        int result = divide(dividend,divisor);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int expected = -2;
        int dividend = 7;
        int divisor = -3;
        int result = divide(dividend,divisor);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int expected = 4;
        int dividend = 30;
        int divisor = 7;
        int result = divide(dividend,divisor);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
