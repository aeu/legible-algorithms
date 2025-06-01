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


int lengthOfLongestSubstringTwoDistinct(std::string s)
{
    int maxlen = INT_MIN;
    int left = 0;
    int right = 0;
    std::unordered_map<char,int> ccounts;
    while( right < s.length() )
    {
        char curr = s[right];
        ccounts[curr]++;
        if( ccounts.size() <= 2 )
        {
            int curlen = right - left + 1;
            maxlen = std::max(maxlen,curlen);
        }
        while( ccounts.size() > 2 )
        {
            char lchar = s[left];
            ccounts[lchar]--;
            if( ccounts[lchar] == 0 )
            {
                ccounts.erase(lchar);
            }
            left++;
        }
        right++;
    }
    if( maxlen == INT_MIN )
        return 0;
    return maxlen;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0159-longest-substring-with-at-most-two-distinct-characters" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "eceba";
        int result = lengthOfLongestSubstringTwoDistinct(s);
        int expected = 3;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "ccaabbb";
        int result = lengthOfLongestSubstringTwoDistinct(s);
        int expected = 5;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
