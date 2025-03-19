// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>


bool arePair(const char lhs, const char rhs)
{
    if( ( lhs == '(' ) && ( rhs == ')' ))
        return true;
    if( ( lhs == '{' ) && ( rhs == '}' ))
        return true;
    if( ( lhs == '[' ) && ( rhs == ']' ))
        return true;
    return false;
}

bool isOpener(const char candidate)
{
    if( ( candidate == '(' ) || ( candidate == '{' ) || ( candidate == '[' ))
        return true;
    return false;
}

bool isValid(std::string s)
{
    std::stack<char> cstack;
    for(char current : s )
    {
        char tos;
        if( isOpener( current ))
        {
            cstack.push( current );
            continue;
        }
        
        if( cstack.empty() )
            return false;
        
        tos = cstack.top();
        if( arePair( tos,current) )
        {
            cstack.pop();
        }
        else
        {
            return false;
        }
    }
    if( cstack.size() == 0 )
        return true;
    return false;
}


int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::string input = "()";
        bool expected = true;
        bool result   = isValid(input);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string input = "()[]{}";
        bool expected = true;
        bool result   = isValid(input);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string input = "(]";
        bool expected = false;
        bool result   = isValid(input);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string input = "([])";
        bool expected = true;
        bool result   = isValid(input);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return test_case;
}
