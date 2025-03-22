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


bool isVowel(const char candidate)
{
    const std::string vowels = "aeiouAEIOU";
    return vowels.find(candidate) != std::string::npos;
}
            
int maxVowels(std::string s, int k)
{
    if( s.length() < k )
        return -1;
    if( k <= 0 )
        return -1;
    
    int vowel_count = 0;
    int max_vowels = 0;
    size_t start = 0;
    size_t end   = k - 1;
    for(int index=start;index<k;index++)
    {
        char current = s[index];
        if( isVowel( current ))
            vowel_count++;
    }
    max_vowels = vowel_count;
    //
    // if we already have as many vowels as k, no need to keep going
    //
    if ( max_vowels == k )
        return max_vowels;
    end++;
    while( end < s.length() )
    {
        if( isVowel(s[end]))
        {
            vowel_count++;
        }
        if( isVowel(s[start]))
        {
            vowel_count--;
        }
        start++;
        end++;
        max_vowels = std::max( max_vowels, vowel_count );
        //
        // if we already have as many vowels as k, no need to keep
        // going
        //
        if ( max_vowels == k )
            return max_vowels;
    }
    
    return max_vowels;
    
}


int main(int argc, char **argv)
{
    float max_vowels;

    std::cout << "Leetcode 1456 - Maximum Number of Vowels in a Substring of Given Length" << std::endl;
    int test_case = 1;
    {
        std::string s = "abciiidef";
        int k = 3;
        int expected = 3; 
        int result = maxVowels(s,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "aeiou";
        int k = 2;
        int expected = 2; 
        int result = maxVowels(s,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "leetcode";
        int k = 3;
        int expected = 2; 
        int result = maxVowels(s,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
}
