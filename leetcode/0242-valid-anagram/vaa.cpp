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
#include <unordered_set>


bool isAnagram(std::string s, std::string t)
{
    if( s.length() != t.length() )
        return false;

    std::unordered_map<char,int> frequency_count;
    for( auto current : s )
    {
        frequency_count[current]++;
    }
    for( auto current : t )
    {
        frequency_count[current]--;
        if( frequency_count[current] < 0 )
            return false;
    }
    return true;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #242 - Valid Anagram" << std::endl;
    int test_case = 1;
    {
        std::string s = "anagram";
        std::string t = "nagaram";
        bool expected = true;
        bool result = isAnagram(s,t);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "rat";
        std::string t = "car";
        bool expected = false;
        bool result = isAnagram(s,t);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return -1;
}
