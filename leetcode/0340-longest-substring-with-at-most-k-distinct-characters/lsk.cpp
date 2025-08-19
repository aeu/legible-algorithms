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

int lengthOfLongestSubstringKDistinct(std::string s, int k) 
{
    std::unordered_map<char,int> frequency_distribution;
    int len_longest = 0;
    int left = 0;
    int right = 0;
    while( right < s.length())
    {
        char current = s[right];
        frequency_distribution[current]++;
        int length = right - left + 1;
        if( frequency_distribution.size() <= k )
        {
            len_longest = std::max(len_longest,length);
        }
        else
        {
            while( frequency_distribution.size() > k )
            {
                char lchar = s[left];
                frequency_distribution[lchar]--;
                if( frequency_distribution[lchar] == 0 )
                {
                    auto fiter = frequency_distribution.find(lchar);
                    frequency_distribution.erase(fiter);
                }
                left++;
            }
        }
        right++;
    }
    return len_longest;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0340-longest-substring-with-at-most-k-distinct-characters" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "eceba";
        int k = 2;
        int expected = 3;
        int result = lengthOfLongestSubstringKDistinct(s,k); 
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "aa";
        int k = 1;
        int expected = 2;
        int result = lengthOfLongestSubstringKDistinct(s,k); 
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
