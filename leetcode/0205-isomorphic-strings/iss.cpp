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


bool isIsomorphic(std::string s, std::string t)
{
    std::unordered_map<char,char> mappings;
    std::unordered_set<char> already_mapped;
    for(int i=0;i<s.length();i++)
    {
        char schar = s[i];
        char tchar = t[i];
        // check to see if schar is already mapped to something
        auto mit = mappings.find( schar );
        if( mit == mappings.end() )
        {
            if( already_mapped.find(tchar) != already_mapped.end() )
            {
                // tchar has been mapped by someone else.  fail out.
                return false;
            }
            mappings[schar] = tchar;
            already_mapped.insert(tchar);
        }
        else
        {
            if( mit->second != tchar )
            {
                // schar is already mapping to a different tchar. fail out
                return false;
            }
        }
    }
    return true;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #205 - Isomorphic Streings" << std::endl;
    int test_case = 1;
    {
        std::string s = "bbbaaaba";
        std::string t = "aaabbbba";
        bool expected = false;
        bool result = isIsomorphic(s,t);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "badc";
        std::string t = "baba";
        bool expected = false;
        bool result = isIsomorphic(s,t);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "egg";
        std::string t = "add";
        bool expected = true;
        bool result = isIsomorphic(s,t);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "foo";
        std::string t = "bar";
        bool expected = false;
        bool result = isIsomorphic(s,t);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "paper";
        std::string t = "title";
        bool expected = true;
        bool result = isIsomorphic(s,t);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return -1;
}
