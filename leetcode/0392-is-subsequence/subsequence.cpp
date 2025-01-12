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
    std::cout << "Leetcode #392 - Is Subsequence" << std::endl << std::endl;
    {
        std::string candidate   = "abc";
        std::string superstring = "ahbgdc";
        bool is_subsequence = isSubsequence( candidate, superstring );
        std::cout << candidate << " is " << ( is_subsequence ? "" : "not " ) << "a subsequence of " << superstring << std::endl;
    }
    {
        std::string candidate   = "axc";
        std::string superstring = "ahbgdc";
        bool is_subsequence = isSubsequence( candidate, superstring );
        std::cout << candidate << " is " << ( is_subsequence ? "" : "not " ) << "a subsequence of " << superstring << std::endl;
    }
}
