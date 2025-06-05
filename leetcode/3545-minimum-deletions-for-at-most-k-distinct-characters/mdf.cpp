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


void dumpValues(std::vector<int> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << ", ";
        first = false;
        std::cout << std::setw(2) << curr ;
    }

    std::cout << std::endl;
}


int minDeletion(std::string s, int k)
{
    std::vector<int> counts(26,0);
    for(const auto curr : s )
    {
        counts[ curr - 'a' ] ++;
    }
    std::sort( counts.begin(),counts.end(), std::greater<int>() );
    int deletions = 0;
    for(int index=25;index>=0;index--)
    {
        if( index >= k )
            deletions += counts[index];
    }
    return deletions;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "3545-minimum-deletions-for-at-most-k-distinct-characters" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "abc";
        int k = 2;
        int expected = 1;
        int result = minDeletion(s,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "aabb";
        int k = 2;
        int expected = 0;
        int result = minDeletion(s,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "yyyzz";
        int k = 1;
        int expected = 2;
        int result = minDeletion(s,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
