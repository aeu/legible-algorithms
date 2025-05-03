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

std::string mergeAlternately(std::string word1, std::string word2)
{
    std::string retval;
    int w1index = 0;
    int w2index = 0;
    while( ( w1index < word1.length() ) && ( w2index < word2.length() ))
    {
        retval.push_back( word1[w1index++] );
        retval.push_back( word2[w2index++] );
    }

    if( w1index < word1.length() )
        retval.append( word1.substr(w1index));

    if( w2index < word2.length() )
        retval.append( word2.substr(w1index));

    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1768-merge-strings-alternately" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string word1 = "abc";
        std::string word2 = "pqr";
        std::string expected = "apbqcr";
        std::string result = mergeAlternately(word1,word2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string word1 = "ab";
        std::string word2 = "pqrs";
        std::string expected = "apbqrs";
        std::string result = mergeAlternately(word1,word2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string word1 = "abcd";
        std::string word2 = "pq";
        std::string expected = "apbqcd";
        std::string result = mergeAlternately(word1,word2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
