// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>

int pick;

int guess(int num)
{
    if( num > pick )
        return -1;
    else if (num < pick )
        return 1;
    return 0;
}


int guessNumber(int n )
{
    int low = 0;
    int high = n;
    int mid = low + ( high - low ) / 2 ;
    int guess_response;
    while( low <= high )
    {
        guess_response = guess( mid );
        if( guess_response == 0 )
            return mid;
        if( guess_response == -1 )
        {
            high = mid;
        }
        else if ( guess_response == 1 )
        {
            low = mid + 1;
        }
        mid = low + ( high - low ) / 2 ;
    }
    return low;
}


int main(int argc, char **argv)
{
    int test_case = 1;
    {
        pick = 6;
        int n = 10;
        int expected = 6;
        int result = guessNumber(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        pick = 1;
        int n = 1;
        int expected = 1;
        int result = guessNumber(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        pick = 1;
        int n = 2;
        int expected = 1;
        int result = guessNumber(n);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return test_case;
}
