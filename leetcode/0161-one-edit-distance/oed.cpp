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
#include <limits.h>

bool isOneEditDistance(std::string s, std::string t) 
{
    if( s.length() == t.length() )
    {
        int diffs = 0;
        for(int index = 0; index < s.length(); index++)
        {
            if( s[index] != t[index])
                diffs++;
            if( diffs > 1 )
                return false;
        }
        if( diffs == 1 )
            return true;
    }
    else if( s.length() == t.length() + 1 )
    {
        int tindex  = 0;
        int sindex  = 0;
        int skips = 0;
        while(( tindex < t.length()) && ( sindex < s.length()))
        {
            if( s[sindex] == t[tindex])
            {
                tindex++;
                sindex++;
            }
            else
            {
                sindex++;
                skips++;
                if( skips > 1 )
                    return false;
            }
        }
        if(( skips == 1 ) || (skips == 0 ))
           return true;
    }
    else if ( s.length() == t.length() - 1 )
    {
        int tindex  = 0;
        int sindex  = 0;
        int skips = 0;
        while(( tindex < t.length()) && ( sindex < s.length()))
        {
            if( s[sindex] == t[tindex])
            {
                tindex++;
                sindex++;
            }
            else
            {
                tindex++;
                skips++;
                if( skips > 1 )
                    return false;
            }
        }
        if(( skips == 1 ) || (skips == 0 ))
           return true;
    }
    else
    {
        return false;
    }
    return false;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0161-one-edit-distance" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "ab";
        std::string t = "acb";

        bool expected = true;
        bool result = isOneEditDistance(s,t);
        
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "";
        std::string t = "";

        bool expected = false;
        bool result = isOneEditDistance(s,t);
        
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
