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


int charToIndex(char candidate)
{
    int index = (int)candidate - (int)'a';
    return index;
}    

std::string removeDuplicateLetters(std::string s)
{
    std::array<int,26> counts;
    std::array<bool,26> in_stack;
    counts.fill(0);
    in_stack.fill(false);
    std::stack<char> subsequence;
    for(auto curr : s )
    {
        int index = charToIndex(curr);
        counts[index]++;
    }

    for(auto curr : s )
    {
        int index = charToIndex(curr);
        if( subsequence.size() == 0 )
        {
            subsequence.push(curr);
            in_stack[index] = true;
            counts[index]--;
            continue;
        }
        if( in_stack[index] )
        {
            counts[index]--;
            continue;
        }
        auto curtop = subsequence.top();
        if( curr == curtop )
        {
            counts[index]--;
            continue;
        }
        while( ! subsequence.empty() )
        {
            auto curtop = subsequence.top();
            int top_index = charToIndex(curtop);
            if( counts[top_index] == 0 )
                break;
            if( curtop < curr )
                break;
            
            subsequence.pop();
            in_stack[top_index] = false;
        }
        subsequence.push(curr);
        in_stack[index] = true;
        counts[index]--;
    }
    std::string retval;
    while( !subsequence.empty() )
    {
        char top = subsequence.top();
        subsequence.pop();
        retval += top;
    }
    std::reverse(retval.begin(),retval.end());
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "/leetcode/0316-remove-duplicate-letters/" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "bcabc";
        std::string expected = "abc";
        std::string result = removeDuplicateLetters(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "cbacdcbc";
        std::string expected = "acdb";
        std::string result = removeDuplicateLetters(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
