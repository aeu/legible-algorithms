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

int maximumSwap(int num)
{
    std::map<char,int> last_seen;
    std::string snum = std::to_string(num);
    for(int index=0;index<snum.length();index++)
    {
        auto curr = snum[index];
        last_seen[curr] = index;
    }
    std::string candidates = "987654321";
    for(int index=0;index<snum.length();index++)
    {
        auto curr = snum[index];
        if( curr == '9' )
            continue;
        for(auto cand : candidates )
        {
            auto lit = last_seen.find(cand);
            if( lit == last_seen.end() )
                continue;
            int lspos = lit->second;
            if(( cand > curr ) && ( lspos > index ))
            {
                std::cout << "before: " << snum << std::endl;
                std::swap( snum[index], snum[lspos]);
                std::cout << "after: " << snum << std::endl;
                int retval = std::stol(snum);
                return retval;
            }
        }
    }
    return num;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC 670 - Maximum Swap" << std::endl << std::endl;
    int test_case = 1;
    {
        int num = 2736;
        int expected = 7236;
        int result = maximumSwap(num);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int num = 9973;
        int expected = 9973;
        int result = maximumSwap(num);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
