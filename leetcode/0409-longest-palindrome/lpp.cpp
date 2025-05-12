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


int longestPalindrome(std::string s)
{
    std::unordered_map<char,int> dist;
    for(const auto &curr : s )
    {
        dist[curr]++;
    }
    int retval = 0;
    int max_odd = 0;
    for(auto &[letter, count] : dist )
    {
        if(( count % 2 ) == 0 )
        {
            retval += count;
        }
        else
        {
            max_odd = std::max(max_odd,count);
            retval += count-1;
        }
    }
    if( max_odd != 0 )
    {
        retval += 1;
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0409-longest-palindrome" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "bananas";
        int expected = 5;
        int result = longestPalindrome(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "abccccdd";
        int expected = 7;
        int result = longestPalindrome(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "a";
        int expected = 1;
        int result = longestPalindrome(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
