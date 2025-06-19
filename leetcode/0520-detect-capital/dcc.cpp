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
#include <cctype>
#include <limits.h>

bool detectCapitalUse(std::string word)
{
    int capital_count = 0;
    for(int index = 0; index<word.length();index++)
    {
        char curr = word[index];
        if( isupper( curr ) )
            capital_count++;
        // early exit for strings like FROggDID
        if(( capital_count > 1 ) && ( index - capital_count > 1 ))
            return false;
    }
    if( capital_count == word.length() )
        return true;
    if( capital_count == 1 )
        return true;
    if( capital_count == 0 )
        return true;
    
    return false;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0520-detect-capital" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string word = "USA";
        bool expected = true;
        bool result = detectCapitalUse(word);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string word = "NAchOs";
        bool expected = false;
        bool result = detectCapitalUse(word);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string word = "FlGa";
        bool expected = false;
        bool result = detectCapitalUse(word);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string word = "leetcode";
        bool expected = true;
        bool result = detectCapitalUse(word);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
