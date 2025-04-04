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

void dumpValues(std::vector<std::string> values)
{
    for( auto curr : values )
    {
        std::cout << curr << ", " ;
    }
    std::cout << std::endl;
}


bool isPalindrome(std::string candidate)
{
    int left = 0;
    int right = candidate.length()-1;
    while( left < right )
    {
        if( candidate[left] != candidate[right] )
            return false;
        left++;
        right--;
    }
    return true;
}


void backtrack(std::string s,
               int start_index,
               std::vector<std::string> &current,
               std::vector<std::vector<std::string>> &retval )
{
    if( start_index == s.length() )
    {
        retval.push_back( current );
    }
    for(int index = start_index;index<s.length();index++)
    {
        std::string candidate = s.substr( start_index, index - start_index + 1 ) ;
        if( isPalindrome( candidate ))
        {
            current.push_back(candidate);
            backtrack(s, index+1, current, retval );
            current.pop_back();
        }
    }
}


std::vector<std::vector<std::string>> partition(std::string s)
{
    std::vector<std::vector<std::string>> retval;
    std::vector<std::string> current;
    backtrack(s,0,current,retval);
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC 131 - Palindrome Partitioning" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "aab";
        std::vector<std::vector<std::string>> expected = {{"a","a","b"},{"aa","b"}};
        std::vector<std::vector<std::string>> result = partition(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::string s = "a";
        std::vector<std::vector<std::string>> expected = {{"a"}};
        std::vector<std::vector<std::string>> result = partition(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
