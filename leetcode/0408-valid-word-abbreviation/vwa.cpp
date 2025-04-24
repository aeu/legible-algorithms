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

bool validWordAbbreviation(std::string word,
                           std::string abbr)
{
    std::vector<char> tester;
    std::string digits = "";
    for(char curr : abbr )
    {
        if( std::isdigit( curr ) )
            digits += curr;
        else
        {
            if( digits.length() )
            {
                if(( digits.length() > 2 ) || ( digits[0] == '0'))
                    return false;
                int num_skips = std::stoi( digits );
                while( num_skips > 0 )
                {
                    tester.push_back('.');
                    num_skips--;
                }
                digits = "";
            }
            tester.push_back(curr);
        }
    }
    if( digits.length() )
    {
        if(( digits.length() > 2 ) || ( digits[0] == '0'))
            return false;
        int num_skips = std::stoi( digits );
        while( num_skips > 0 )
        {
            tester.push_back('.');
            num_skips--;
        }
        digits = "";
    }
    
    if( word.length() != tester.size() )
        return false;
    
    for(int index=0;index<word.length();index++)
    {
        if( tester[index] == '.' )
            continue;
        if( word[index] != tester[index] )
            return false;
    }
    return true;
}



int main(int argc, char **argv)
{
    std::cout << std::endl << "0408-valid-word-abbreviation" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string word = "abbde";
        std::string abbr = "a1b01e";
        bool expected = false;
        bool result = validWordAbbreviation(word,abbr);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string word = "internationalization";
        std::string abbr = "i12iz4n";
        bool expected = true;
        bool result = validWordAbbreviation(word,abbr);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string word = "internationalization";
        std::string abbr = "i5a11o1";
        bool expected = true;
        bool result = validWordAbbreviation(word,abbr);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string word = "apple";
        std::string abbr = "a2e";
        bool expected = false;
        bool result = validWordAbbreviation(word,abbr);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;



}
