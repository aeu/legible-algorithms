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


bool wordPattern(std::string pattern, std::string s)
{
    std::unordered_map<char, std::string> mappings;
    std::unordered_set<std::string> already_mapped;
    char *tstr = strdup( s.c_str());
    char *c = strtok(tstr, " ");
    int index = 0;
    while( c != NULL )
    {
        std::string current(c);
        std::cout << index << " " << pattern[index] << " : " << current << std::endl;
        c = strtok(NULL, " " );


        auto it = mappings.find( pattern[index] );
        if( it == mappings.end() )
        {
            if( already_mapped.find( current ) == already_mapped.end() )
            {
                mappings[pattern[index]] = current;
                already_mapped.insert( current );
            }
            else
            {
                return false;
            }
        }
        else
        {
            if( it->second != current )
                return false;
        }
        index++;
    }       
    free(tstr);
    if( index == pattern.length() )
        return true;
    return false;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #290 - Word Pattern" << std::endl;
    int test_case = 1;
    {
        std::string pattern = "jquery";
        std::string s = "jquery";
        bool expected = false;
        bool result = wordPattern(pattern,s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string pattern = "abba";
        std::string s = "dog cat cat dog";
        bool expected = true;
        bool result = wordPattern(pattern,s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string pattern = "abba";
        std::string s = "dog cat cat fish";
        bool expected = false;
        bool result = wordPattern(pattern,s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string pattern = "aaaa";
        std::string s = "dog cat cat dog";
        bool expected = false;
        bool result = wordPattern(pattern,s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return -1;
}
