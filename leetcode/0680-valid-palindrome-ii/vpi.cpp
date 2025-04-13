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

bool isPalindrome(std::string s, int left, int right)
{
    while( left < right )
    {
        if( s[left] != s[right] )
            return false;
        left++;
        right--;
    }
    return true;
}


bool validPalindrome(std::string s)
{
    std::cout << s << std::endl;
    int skips_remaining = 1;
    int left = 0;
    int right = s.length() -1;

    while( ( left <= right ) && (skips_remaining >= 0) )
    {
        if( s[left] == s[right] )
        {
            left++;
            right--;
        }
        else
        {
            return isPalindrome( s, left+1, right ) || isPalindrome( s, left, right -1 );
        }
    }
    return true;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "680 Valid Palindrome II" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
        bool expected = true;
        bool result = validPalindrome(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "zryxeededexyz";
        bool expected = false;;
        bool result = validPalindrome(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "aba";
        bool expected = true;
        bool result = validPalindrome(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "abca";
        bool expected = true;
        bool result = validPalindrome(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "abc";
        bool expected = false;
        bool result = validPalindrome(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
