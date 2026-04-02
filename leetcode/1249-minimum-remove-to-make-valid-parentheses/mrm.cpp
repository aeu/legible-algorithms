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

std::string minRemoveToMakeValid(std::string s)
{
    int open = 0;
    std::vector<char> first_pass.reserve(s.size());

    // and there isn't an open that goes for it, skip it and keep going.
    // every open paren we append to the growing string.  If we find a close,
    // we are first going through the string in the normal direction, and
    for(auto curr : s )
    {
        if( curr == '(' )
        {
            open++;
            first_pass.push_back(curr);
            continue;
        }
        if( curr == ')' )
        {
            if( open > 0 )
            {
                open--;
                first_pass.push_back(curr);
            }
            continue;
        }
        first_pass.push_back(curr);
    }

    // now we go through the string that we just made and go
    // backwards.  The reason we are doing this is because it's
    // possible that there's too many opens, so we walk from the end
    // in increment the close count every time we find a close.  We
    // decrement the close count every time we push on an open.  In
    // the event that we find an open, and our close count is 0, then
    // that was an unclosed open, so we toss it.
    std::vector<char> second_pass.reserve(first_pass.size());
    int close = 0;
    for(int index=first_pass.size()-1;index>=0;index--)
    {
        char curr = first_pass[index];
        if( curr == ')' )
        {
            close++;
            second_pass.push_back(curr);
            continue;
        }
        if( curr == '(' )
        {
            if( close > 0 )
            {
                close--;
                second_pass.push_back(curr);
            }
            continue;
        }
        second_pass.push_back(curr);
    }
    std::reverse(second_pass.begin(),second_pass.end());
    std::string retval(second_pass.begin(),second_pass.end());
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1249. Minimum Remove to Make Valid Parentheses" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "lee(t(c)o)de)";
        std::string expected = "lee(t(c)o)de";
        std::string result = minRemoveToMakeValid(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "a)b(c)d";
        std::string expected = "ab(c)d";
        std::string result = minRemoveToMakeValid(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "))((";
        std::string expected = "";
        std::string result = minRemoveToMakeValid(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
