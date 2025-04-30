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


std::string customSortString(const std::string order, const std::string s)
{
    std::unordered_map<char,int> counts;
    for(const auto &curr : s )
    {
        counts[curr]++;
    }
    std::string builder;
    for(const auto &curr : order )
    {
        auto citer = counts.find( curr );
        if( citer != counts.end() )
        {
            int count = citer->second;
            while(count > 0 )
            {
                builder.push_back(curr);
                count--;
            }
            counts.erase(curr);
        }
    }
    for(const auto &curr : counts )
    {
        char letter = curr.first;
        int count  = curr.second;
        while( count > 0 )
        {
            builder.push_back(letter);
            count--;
        }
    }
    return builder;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0791-custom-sort-string" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string order    = "cba";
        std::string s        = "abcd";
        std::string result   = customSortString(order,s);
        std::string expected = "cbad";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string order    = "bcafg";
        std::string s        = "abcd";
        std::string result   = customSortString(order,s);
        std::string expected = "bcad";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
