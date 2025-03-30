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

bool doWork(std::string s,
            std::vector<std::string> &brackets)
{
    std::unordered_map<char,int> opens;
    std::unordered_map<char,int> closes;
    std::stack<int> bracket_stack;
    for(int index=0;index<brackets.size();index++)
    {
        opens[ brackets[index][0]] = index;
        closes[ brackets[index][1]] = index;
    }
    
    for(auto current : s )
    {
        auto open_iterator = opens.find(current);
        if( open_iterator != opens.end() )
        {
            bracket_stack.push( open_iterator->second );
            continue;
        }
        auto close_iterator = closes.find( current );
        if( close_iterator != closes.end() )
        {
            if( bracket_stack.empty() )
                return false;
            
            int last_open = bracket_stack.top();
            if( last_open == close_iterator->second )
            {
                bracket_stack.pop();
            }                
            else
                return false;
        }
    }
    if( bracket_stack.empty() )
        return true;
    return false;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "32.7 Custom Brackets" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "((a+b)*[c-d]-{e/f})";
        std::vector<std::string> brackets = { "()", "[]", "{}" };
        bool expected = true;
        bool result = doWork( s,brackets);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "()[}";
        std::vector<std::string> brackets = { "()", "[]", "{}" };
        bool expected = false;
        bool result = doWork( s,brackets);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "([)]";
        std::vector<std::string> brackets = { "()", "[]", "{}" };
        bool expected = false;
        bool result = doWork( s,brackets);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "<div> hello :) </div>";
        std::vector<std::string> brackets = { "<>", "()" };
        bool expected = false;
        bool result = doWork( s,brackets);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
