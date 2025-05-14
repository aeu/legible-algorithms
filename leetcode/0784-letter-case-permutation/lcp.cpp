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


void dumpStrings(std::vector<std::string> strings)
{
    for(const auto &curr : strings )
    {
        std::cout << curr << " " ;
    }
    std::cout << std::endl;
}


void backtrack(std::string s,
               int start,
               std::unordered_set<std::string> &seen)
{
    if( seen.count( s ) == 0 )
    {
        seen.insert(s);
    }

    for(int index=start;index<s.length();index++)
    {
        char curr = s[index];
        char upper = toupper(curr);
        char lower = tolower(curr);
        s[index] = upper;
        backtrack(s,index+1,seen);
        s[index] = lower;
        backtrack(s,index+1,seen);
    }
}


std::vector<std::string> letterCasePermutation(std::string s)
{
    std::unordered_set<std::string> seen;
    backtrack(s,0,seen);
    std::vector<std::string> retval(seen.begin(),seen.end());
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0784-letter-case-permutation" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "a1b2";
        std::vector<std::string> result = letterCasePermutation(s);
        std::vector<std::string> expected = {"a1b2", "a1B2", "A1b2", "A1B2" };
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::string s = "3z4";
        std::vector<std::string> result = letterCasePermutation(s);
        std::vector<std::string> expected = {"3z4", "3Z4"};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
