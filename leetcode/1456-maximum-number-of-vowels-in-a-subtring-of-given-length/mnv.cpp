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
            

int maximumNumberOfVowels(const std::string &data,
                          const int length )
{
    if( data.length() < length )
        return -1;
    if( length <= 0 )
        return -1;
    
    int vowel_count = 0;
    int max_vowels = 0;
    size_t start = 0;
    size_t end   = length - 1;
    for(int index=start;index<length;index++)
    {
        char current = data[index];
        if( isVowel( current ))
            vowel_count++;
    }
    max_vowels = vowel_count;
    //
    // if we already have as many vowels as k, no need to keep going
    //
    if ( max_vowels == length )
        return max_vowels;
    end++;
    while( end < data.length() )
    {
        if( isVowel(data[end]))
        {
            vowel_count++;
        }
        if( isVowel(data[start]))
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
        if ( max_vowels == length )
            return max_vowels;
    }
    
    return max_vowels;
}


int main(int argc, char **argv)
{
    float max_vowels;

    std::cout << "Leetcode 1456 - Maximum Number of Vowels in a Substring of Given Length" << std::endl;
    {
        std::string data = "abciiidef";
        int k = 3;
        std::cout << "Counting: " << data << ", with k: " << k << std::endl;
        max_vowels = maximumNumberOfVowels(data, k );
        std::cout << "Maximum Number of Vowels : " << max_vowels << std::endl;
    }
    {
        std::string data = "aeiou"; 
        int k = 2;
        std::cout << "Counting: " << data << ", with k: " << k << std::endl;
        max_vowels = maximumNumberOfVowels(data, k );
        std::cout << "Maximum Number of Vowels : " << max_vowels << std::endl;
    }
    {
        std::string data = "leetcode";
        int k = 3;
        std::cout << "Counting: " << data << ", with k: " << k << std::endl;
        max_vowels = maximumNumberOfVowels(data, k );
        std::cout << "Maximum Number of Vowels : " << max_vowels << std::endl;
    }
}
