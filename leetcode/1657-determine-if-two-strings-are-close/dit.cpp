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
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>


bool closeStrings(std::string word1, std::string word2)
{
    if( word1.length() != word2.length() )
        return false;
    
    std::map<char,int> word1_dist;
    std::map<char,int> word2_dist;
    for(char current : word1 )
    {
        word1_dist[current]++;
    }
    for(char current : word2 )
    {
        word2_dist[current]++;
    }
    auto it1 = word1_dist.begin();
    auto it2 = word2_dist.begin();
    while( it1 != word1_dist.end() )
    {
        if( it1->first != it2->first )
            return false;
        it1++;
        it2++;
    }

    std::vector<int> word1_freq;
    std::vector<int> word2_freq;
    for(auto it : word1_dist )
    {
        word1_freq.push_back( it.second );
    }
    for(auto it : word2_dist )
    {
        word2_freq.push_back( it.second );
    }
    std::sort(word1_freq.begin(), word1_freq.end());
    std::sort(word2_freq.begin(), word2_freq.end());
    for(int index=0;index<word1_freq.size();index++)
    {
        if(( word1_freq[index] != word2_freq[index] ))
            return false;
    }
    
    return true;
}

int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::string word1 = "abc";
        std::string word2 = "bca";
        bool expected = true;
        bool result = closeStrings(word1,word2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string word1 = "a";
        std::string word2 = "aa";
        bool expected = false;
        bool result = closeStrings(word1,word2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string word1 = "cabbba";
        std::string word2 = "abbccc";
        bool expected = true;
        bool result = closeStrings(word1,word2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
}
