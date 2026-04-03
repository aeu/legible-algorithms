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

std::string smallestSubsequence(std::string s)
{

    // first create two arrays.  one to count the occurrences of all
    // the characters, the other to keep track of what characters are
    // currently in the string already.

    std::array<int,26> counts;
    std::array<bool,26> in_stack;
    counts.fill(0);
    in_stack.fill(false);
    std::stack<char> subsequence;

    // loop through and count them alll
    for(auto curr : s )
    {
        int index = charToIndex(curr);
        counts[index]++;
    }

    // now go through the input string again.
    for(auto curr : s )
    {
        int index = charToIndex(curr);
        if( subsequence.size() == 0 )
        {
            // if the subsequence is empty, push it and keep going.
            // decrement the count (so we can keep track of how many
            // more of that char are coming) and mark it as currently
            // in the stack
            subsequence.push(curr);
            in_stack[index] = true;
            counts[index]--;
            continue;
        }
        if( in_stack[index] )
        {
            // its in the stack already, so we are presumably cool
            // with how its in there, so decrement the count and keep
            // going
            counts[index]--;
            continue;
        }
        auto curtop = subsequence.top();
        if( curr == curtop )
        {
            // its the same as the one on the top of the stack, so
            // decrement the coming count and keep goign
            counts[index]--;
            continue;
        }
        // now for the monotonic stack
        while( ! subsequence.empty() )
        {
            auto curtop = subsequence.top();
            int top_index = charToIndex(curtop);
            if( counts[top_index] == 0 )
                // there's no more of these characters coming, so we
                // can't do anything.
                break;
            if( curtop < curr )
                // the current top one is earlier in the alphabet than
                // the one we have in hand.  Remember we want the
                // string to be in lexicographic order, so we want
                // lower letters at the top of the stack
                break;
            
            // we made it this far, which means that the top of the stack is
            // a letter that is
            // 1. after the one we have in hand (like B is after A)
            // 2. we have more of them available in the source string
            //
            // pop it off, and mark it as not in the stack
            subsequence.pop();
            in_stack[top_index] = false;
        }
        // now push the one we have in hand onto the stack.
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
    // builld the string from the stack and reverse it.  The reason we
    // are reversing it is because we are popping off, which would put
    // the lower letters at the end.
    std::reverse(retval.begin(),retval.end());
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/1081-smallest-subsequence-of-distinct-characters" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "bcabc";
        std::string expected = "abc";
        std::string result = smallestSubsequence(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "cbacdcbc";
        std::string expected = "acdb";
        std::string result = smallestSubsequence(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
