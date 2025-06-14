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

int mySqrt(int x)
{
    if( ( x == 0 ) || ( x == 1 ))
        return x;
    
    int low = 1;
    int high = x;
    int mid;
    int answer = 0;
    while( low <= high )
    {
        mid = low + (( high - low ) / 2);
        if( mid <= ( x / mid ) )
        {
            answer = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    return answer;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0069-sqrt" << std::endl << std::endl;
    int test_case = 1;
    {
        int expected = 2;
        int x = 4;
        int result = mySqrt(x);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int expected = 2;
        int x = 8;
        int result = mySqrt(x);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
