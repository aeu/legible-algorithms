// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>

bool contains(std::unordered_map<char,int> &needle,
              std::unordered_map<char,int> &haystack)
{
    for(auto it : needle )
    {
        int hscount = haystack[ it.first];
        int ncount  = needle[ it.first];
        if( haystack[ it.first ] < needle[it.first] )
        {
            return false;
        }
    }
    return true;
}


std::string minWindow(std::string s, std::string t)
{
    if( s.length() < t.length() )
        return "";
    
    std::unordered_map<char,int> goal;
    std::unordered_map<char,int> sliding;
    for( auto current : t )
    {
        goal[current]++;
    }
    int left = 0;
    int right = 0;
    std::string mws = "";
    bool found = false;
    int min_win_sub = INT_MAX;
    int current_window_size = 0;
    while(right < s.size() )
    {
        sliding[ s[right] ]++;
        while( ( left <= right ) && ( contains ( goal, sliding )))
        {
            current_window_size = right - left + 1;
            if (current_window_size < min_win_sub)
            {
                min_win_sub = current_window_size;
                mws = s.substr(left, current_window_size);
            }
            sliding[s[left]]--;
            left++;
        }
        right++;
    }
    if ( min_win_sub != INT_MAX )
        return mws;
    return "";
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode 76 - Minimum Window Substring" << std::endl;
    int test_case = 1;
    {
        std::string s = "AD0BEC0DEBANC";
        std::string t = "ABC";
        std::string expected = "BANC";
        std::string result = minWindow(s,t);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << "Expected : " << expected << " Result: " << result << std::endl;
    }
    {
        std::string s = "a";
        std::string t = "a";
        std::string expected = "a";
        std::string result = minWindow(s,t);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << "Expected : " << expected << " Result: " << result << std::endl;
    }
    {
        std::string s = "a";
        std::string t = "aa";
        std::string expected = "";
        std::string result = minWindow(s,t);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << "Expected : " << expected << " Result: " << result << std::endl;
    }
}
