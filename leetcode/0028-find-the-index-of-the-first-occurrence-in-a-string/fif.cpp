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

int strStr(std::string haystack, std::string needle) 
{
    auto pos = haystack.find(needle);
    if( pos == std::string::npos )
        return -1;
    return pos;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0028-find-the-index-of-the-first-occurrence-in-a-string" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string haystack = "sadbutsad";
        std::string needle = "sad";
        int expected = 0;
        int result = strStr( haystack, needle );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string haystack = "leetcode";
        std::string needle = "leeto";
        int expected = -1;
        int result = strStr( haystack, needle );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
