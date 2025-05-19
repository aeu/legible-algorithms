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

std::pair<int,std::string> palindromeAtStartIndex(std::string s,
                                                  int start_index )
{
    // an empty string is not a palindrome
    std::string retval = "";
    if( s.length() == 0 )
        return { -1, "" };

    // the worst case is that the very first char is the palindrome so
    // make that the default return.
    int max_length = 1;
    retval += s[0];

    if( s.length() == 1 )
        return { max_length, retval };

    // edge case handing - if our starting index is 0, the longest
    // possible palindrome is of length two, so check for that.
    if( start_index == 0 )
    {
        if( s.length() >= 2 )
        {
            if( s[0] == s[1] )
                return { 2, s.substr(0,2) };
        }
    }

    // palindrome can either have an isolated middle char or not.
    // Check first for isolated middle by starting at our current
    // position and expanding outwards.
    //
    // Example:     abcba
    //
    int left = start_index-1;
    int right = start_index+1;
    int pairs = 0;
    while(( left >= 0 ) && ( right < s.length() ))
    {
        if( s[left] == s[right] )
        {
            pairs++;
            left--;
            right++;
        }
        else
            break;
    }
    if( pairs > 0 )
    {
        int length = 1 + ( pairs * 2 );
        int start = start_index - pairs;
        if( length > max_length )
        {
            max_length = length;
            retval = s.substr(start,length);
        }
    }

    // now check for the non-isolated middle
    // Example:  cbaabc
    //
    left = start_index;
    right = start_index+1;
    int start_point = start_index;
    int nimlen = 0;
    while(( left >= 0 ) && ( right < s.length() ))
    {
        if( s[left] == s[right] )
        {
            start_point = left;
            nimlen+=2;
            left--;
            right++;
        }
        else
        {
            break;
        }
    }    
    if( nimlen > max_length )
    {
        max_length = nimlen;
        retval = s.substr(start_point,nimlen );
    }
    return { max_length, retval };
}

std::string longestPalindrome(std::string s)
{
    std::string longest = "";
    int max_length = INT_MIN;
    // loop through the entire string, and for every possible start
    // point within the string, check to see what is the longest
    // possible palindrome at that start point.  And then accumulate
    // the best answer.  That is the key insight of this problem,
    // which allows us to solve it in one pass.

    for(int index=0;index<s.length();index++)
    {
        std::pair<int,std::string> curr = palindromeAtStartIndex(s,index);
        if( curr.first > max_length )
        {
            max_length = curr.first;
            longest = curr.second;
        }
    }
    return longest;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC0005 - Longest Palindromic Substring" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "abb";
        std::string expected = "bb";
        std::string result = longestPalindrome(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "ccc";
        std::string expected = "ccc";
        std::string result = longestPalindrome(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "babad";
        std::string expected = "bab";
        std::string result = longestPalindrome(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "cbbd";
        std::string expected = "bb";
        std::string result = longestPalindrome(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "a";
        std::string expected = "a";
        std::string result = longestPalindrome(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "ac";
        std::string expected = "a";
        std::string result = longestPalindrome(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
