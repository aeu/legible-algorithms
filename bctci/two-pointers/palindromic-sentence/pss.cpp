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
#include <cctype>


bool doWork(const std::string s)
{
    int left = 0;
    int right = s.length() -1 ;
    while( left < right )
    {
        if( ! isalpha( s[right] ))
        {
            right--;
        }
        else if( ! isalpha( s[left] ))
        {
            left++;
        }
        else
        {
            if( std::tolower( s[left] ) != std::tolower( s[right] ))
                return false;
            left++;right--;
        }
            
    }
    return true;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "27.4 Palindromic Sentence" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "Bob wondered, 'Now, Bob?'";
        bool expected = true;
        bool result = doWork(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
