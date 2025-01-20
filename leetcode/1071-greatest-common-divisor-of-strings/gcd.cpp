// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>


std::string getNextPossibleSubstring(std::string source,
                                     int superstring_length,
                                     int last_substring_length)
{
    if( last_substring_length == 0 )
        return source;
    
    int current_substring_length = last_substring_length -1;

    while( current_substring_length > 0 )
    {
        if((( superstring_length % current_substring_length ) == 0  )
           && (( source.length() % current_substring_length ) == 0 ))
        {
            break;
        }
        current_substring_length--;
    }
    // std::cout << "trying next possible, which has length of " << current_substring_length << std::endl;
    return source.substr(0,current_substring_length);
}

bool isDenominator(std::string superstring,
                   std::string denominator)
{
    std::string candidate;
    int possible_occurrences = superstring.length() / denominator.length();
    for(int index=0;index<possible_occurrences;index++)
    {
        candidate += denominator;
    }
    if( candidate == superstring )
        return true;
    return false;
}


std::string gcdOfStrings(std::string str1, std::string str2)
{
    std::string longer;
    std::string shorter;
    std::string gcd;
    bool gcd_found = false;
    int last_substring_length = 0;

    if( str1.length() > str2.length() )
    {
        longer = str1;
        shorter = str2;
    }
    else
    {
        longer = str2;
        shorter = str1;
    }
    
    while( ! gcd_found )
    {
        std::string candidate = "";
        gcd = getNextPossibleSubstring( shorter, longer.length(), last_substring_length);
        last_substring_length = gcd.length();
        if( last_substring_length == 0 )
        {
            break;
        }
        if( isDenominator(longer,gcd) && isDenominator(shorter,gcd))
            gcd_found = true;
    }
    if( ! gcd_found )
        return "";
    return gcd;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #1071 - Greatest Common Divisor of Strings" << std::endl;


    {
        std::string str1 = "AAAAAAAAA";
        std::string str2 = "AAACCC";
        std::string gcd  = gcdOfStrings(str1,str2);
        std::cout << "Str1: " << str1 << " Str2: " << str2 << " GCD: \"" << gcd << "\"" << std::endl;
    }
    {
        std::string str1 = "ABCABC";
        std::string str2 = "ABC";
        std::string gcd  = gcdOfStrings(str1,str2);
        std::cout << "Str1: " << str1 << " Str2: " << str2 << " GCD: \"" << gcd << "\"" << std::endl;
    }
    {
        std::string str1 = "ABABAB";
        std::string str2 = "ABAB";
        std::string gcd  = gcdOfStrings(str1,str2);
        std::cout << "Str1: " << str1 << " Str2: " << str2 << " GCD: \"" << gcd << "\"" << std::endl;
    }
    {
        std::string str1 = "LEET";
        std::string str2 = "CODE";
        std::string gcd  = gcdOfStrings(str1,str2);
        std::cout << "Str1: " << str1 << " Str2: " << str2 << " GCD: \"" << gcd << "\"" << std::endl;
    }
    return 1;
}
