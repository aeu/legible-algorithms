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
#include <sstream>

bool isSubsequence(const std::string &candidate,
                   const std::string &superstring)
{
    if( candidate.length() > superstring.length() )
        return false;

    if( candidate.length() == 0 )
        return true;
    
    int candidate_index = 0;
    for(size_t superstring_index=0;superstring_index<superstring.length();superstring_index++)
    {
        if( superstring[superstring_index] == candidate[candidate_index] )
            candidate_index++;

        if( candidate_index == candidate.length() )
        {
            return true;
        }
    }
    return false;
}


int main(int argc, char **argv)
{
    int test_case = 1;
    std::cout << "Leetcode #392 - Is Subsequence" << std::endl << std::endl;
    {
        std::string s   = "abc";
        std::string t = "ahbgdc";
        bool expected = true;
        bool result = isSubsequence( s, t );
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
    }
    {
        std::string s   = "axc";
        std::string t = "ahbgdc";
        bool expected = false;
        bool result = isSubsequence( s, t );
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
    }
    {
        std::string s   = "";
        std::string t = "ahbgdc";
        bool expected = true;
        bool result = isSubsequence( s, t );
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
    }
}
