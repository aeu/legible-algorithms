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


int countSubstrings(std::string s)
{
    int count = 0;
    for(int center=0;center<s.length();center++)
    {
        int left = center;
        int right = center;
        while(( left >= 0 ) && ( right < s.length() ) && ( s[left] == s[right] ))
        {
            count++;
            left--;
            right++;
        }

        left = center;
        right = center+1;
        while(( left >= 0 ) && ( right < s.length() ) && ( s[left] == s[right] ))
        {
            count++;
            left--;
            right++;
        }
    }
    return count;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0647-palindromic-substrings" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "abc";
        int expected = 3;
        int result = countSubstrings(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "aaa";
        int expected = 6;
        int result = countSubstrings(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
