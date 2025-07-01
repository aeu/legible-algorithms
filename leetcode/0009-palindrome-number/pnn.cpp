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

int doWork()
{
    return 1;
}

bool palindromicString(const std::string &candidate)
{
    if(( candidate.length() == 0 ) || ( candidate.length() == 1 ))
        return true;

    int left = 0;
    int right = candidate.length() - 1;

    while( left <= right )
    {
        if( candidate[left] != candidate[right] )
            return false;
        left++;
        right--;
    }
    return true;
}

bool isPalindrome(int x)
{
    if( x < 0 )
        return false;

    int local = x;
    std::string converted = "";
    while( local != 0 )
    {
        int digit = local % 10;
        converted.append( std::to_string( digit ));
        local /= 10;
        
    }
    return palindromicString( converted );
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0009-palindrome-number" << std::endl << std::endl;
    int test_case = 1;
    {
        int x = 121;
        bool expected = true;
        bool result = isPalindrome(x);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int x = -121;
        bool expected = false;
        bool result = isPalindrome(x);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int x = 10;
        bool expected = false;
        bool result = isPalindrome(x);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
