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


// For this problem we have to find the minimum number of characters
// that need to be deleted from the string such that we end up with at
// most k distinct characters.
//
int minDeletion(std::string s, int k)
{
    // create an array with 26 slots initialized to 0.  Then walk
    // through the string and count all occurrences of every
    // character.
    std::vector<int> counts(26,0);
    for(const auto curr : s )
    {
        counts[ curr - 'a' ] ++;
    }
    // we want to find the minimum number of deletions necessary to
    // hit K, so we sort the array such that the low end has the
    // characters that we have the least of.
    std::sort( counts.begin(),counts.end(), std::greater<int>() );
    int deletions = 0;

    // walk through the array.  Once we get past k distinct
    // characters, we can then start deleting characters until we hit
    // the count.  As we go, increment the count of characters that
    // were deleted.

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
