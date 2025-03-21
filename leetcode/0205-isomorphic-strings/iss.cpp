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
        if( schar == tchar )
            continue;
        auto mit = mappings.find( schar );
        if( mit != mappings.end() )
        {
            // check to see if it's been mapped to another char.  If it has, fail out
            if( mit->second != tchar )
            {
                return false;
            }
        }
        else
        {
            // make sure tchar hasn't been mapped already by someone else
            if( already_mapped.find(tchar) != already_mapped.end() )
                return false;

            mappings[schar] = tchar;
            already_mapped.insert(tchar);
        }
    }
    return true;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #205 - Isomorphic Streings" << std::endl;
    int test_case = 1;
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
