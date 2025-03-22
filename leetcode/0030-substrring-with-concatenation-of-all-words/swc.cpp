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

bool isConcatenation(std::string test_string,
                     int wordlen,
                     std::unordered_map<std::string, int> target_map)
{
    std::unordered_map<std::string,int> test_map;
    for(int index=0;index<=test_string.length()-wordlen;index+=wordlen)
    {
        std::string curr = test_string.substr(index,wordlen);
        test_map[curr]++;
    }
    if( target_map == test_map )
        return true;
    return false;
}



std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
{
    std::unordered_map<std::string,int> target_map;
    std::vector<int> found;
    if( words.size() == 0 )
        return found;
    int window_length = words.size() * words[0].length();
    if( s.length() < window_length )
        return found;
    int wordlen  = words[0].length();
    for( auto current : words )
    {
        target_map[current]++;
    }
    
    std::sort( words.begin(), words.end() );
    int left = 0;
    int right = window_length;
    while( left + window_length <= s.length () )
    {
        std::string curr_window = s.substr(left,window_length);
        //       std::cout << "curr: " << curr_window << std::endl;
        bool iscat = isConcatenation( curr_window, wordlen, target_map );
        if( iscat )
        {
            //            std::cout << "HIT at position " << left << " for : " << curr_window << std::endl;
            found.push_back(left);
        }
        left++;
    }
    return found;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode 30 - Substring with Concatenation of All Words" << std::endl;
    int test_case = 1;
    {
        std::string s = "barfoothefoobarman";
        std::vector<std::string> words = { "foo", "bar" };
        std::vector<int> expected = { 0,9 };
        std::vector<int> result = findSubstring(s,words);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::string s = "wordgoodgoodgoodbestword";
        std::vector<std::string> words = { "word", "good", "best", "word" };
        std::vector<int> expected = { };
        std::vector<int> result = findSubstring(s,words);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::string s = "barfoofoobarthefoobarman";
        std::vector<std::string> words = { "bar", "foo", "the" };
        std::vector<int> expected = { 6,9,12 };
        std::vector<int> result = findSubstring(s,words);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
}
