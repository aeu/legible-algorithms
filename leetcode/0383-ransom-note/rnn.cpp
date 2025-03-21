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
#include <unordered_map>

bool canConstruct(std::string ransomNote, std::string magazine)
{
    std::unordered_map<char,int> letters;
    for( char current : magazine )
    {
        letters[current]++;
    }

    for( char current : ransomNote )
    {
        letters[current]--;
        if( letters[current] < 0 )
            return false;
    }
    return true;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #383 - Ransom Note" << std::endl;
    int test_case = 1;
    {
        std::string ransomNote = "a";
        std::string magazine   = "b";
        bool expected          = false;
        bool result = canConstruct(ransomNote, magazine);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string ransomNote = "aa";
        std::string magazine   = "ab";
        bool expected          = false;
        bool result = canConstruct(ransomNote, magazine);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string ransomNote = "aa";
        std::string magazine   = "aab";
        bool expected          = true;
        bool result = canConstruct(ransomNote, magazine);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return -1;
}
