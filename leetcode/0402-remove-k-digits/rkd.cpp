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
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

std::string removeKdigits(std::string num, int k)
{
    if( k >= num.length() )
        return "0";

    std::string result;
    for(const auto curr : num )
    {
        // if the last char in the string that we have buillt so far
        // is greater than the current char, pop it (and keep going
        // until either thats not true or we hit k removals)
        while( result.length() != 0 &&
               k > 0 &&
               result.back() > curr )
        {
            result.pop_back();
            k--;
        }
        result.push_back(curr);
    }
    // in case we have pops left to go
    while (k > 0 && !result.empty())
    {
        result.pop_back();
        k--;
    }
    bool found_digit = false;
    std::string retval;
    for(const auto curr : result )
    {
        if( curr == '0' && found_digit == false )
        {
            continue;
        }
        found_digit = true;
        retval += curr;
    }
    if( retval.length() == 0 )
        return "0";
    // remove leading 0s (if any)
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0402-remove-k-digits" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string num = "1432219";
        int k = 3;
        std::string expected = "1219";
        std::string result = removeKdigits(num,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string num = "10200";
        int k = 1;
        std::string expected = "200";
        std::string result = removeKdigits(num,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string num = "10";
        int k = 2;
        std::string expected = "0";
        std::string result = removeKdigits(num,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
