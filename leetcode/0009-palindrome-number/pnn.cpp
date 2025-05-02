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

bool isPalindrome(int x)
{
    if( x < 0 )
        return false;
    std::string before = std::to_string(x);
    std::string rever = std::to_string(x);
    std::reverse(rever.begin(),rever.end());
    if( before == rever )
        return true;
    return false;
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
