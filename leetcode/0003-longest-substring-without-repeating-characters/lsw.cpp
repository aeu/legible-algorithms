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
#include <unordered_set>

int lengthOfLongestSubstring(std::string s) {

    if( s.length() == 0 )
        return 0;
    
    int longest_substring = INT_MIN;
    int left = 0;
    int right = 0;
    std::unordered_set<char> seen;
    int current_length = 0;
    while( ( left <= right ) && ( right < s.length() ))
    {
        auto it = seen.find( s[right] );
        if( it == seen.end() )
        {
            current_length = right - left + 1;
            longest_substring = std::max( longest_substring, current_length );
            seen.insert(s[right]);
            right++;
        }
        else
        {
            // bring left foward until you hit the same char as right
            // (which caused the duplicate in the first place).
            while( s[left] != s[right] )
            {
                seen.erase( s[left] );
                left++;
            }
            // and then go one more to remove the duplicate.
            seen.erase( s[left] );
            left++;
        }
    }
    if( longest_substring == INT_MIN )
        return 0;
    return longest_substring;
}
int main(int argc, char **argv)
{
    std::cout << "Leetcode 3 - Longest Substring Without Repeating Characters" << std::endl;
    int test_case = 1;
    {
        std::string s = "aab";
        int expected = 2;
        int result = lengthOfLongestSubstring(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "abcabcbb";
        int expected = 3;
        int result = lengthOfLongestSubstring(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "bbbbb";
        int expected = 1;
        int result = lengthOfLongestSubstring(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "pwwkew";
        int expected = 3;
        int result = lengthOfLongestSubstring(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
}
