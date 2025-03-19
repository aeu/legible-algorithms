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


bool isOperator(std::string candidate)
{
    if( ( candidate == "+" )
        ||  ( candidate == "-" )
        ||  ( candidate == "/" )
        ||  ( candidate == "*" ))
    {
        return true;
    }
    return false;
}

int processOperation(int lhs, int rhs, std::string opr )
{
    
    if( opr == "+" )
        return lhs + rhs;
    if ( opr == "-" )
        return lhs - rhs;
    if ( opr == "/" )
        return lhs / rhs;
    if ( opr == "*" )
        return lhs * rhs;

    return 1; //
}

int evalRPN(std::vector<std::string>& tokens)
{
    std::stack<int> sstack;
    int res = 0;
    for(int index = 0; index<tokens.size();index++)
    {
        std::string current = tokens[index];
        if( isOperator ( current ) )
        {
            int rhs = sstack.top();
            sstack.pop();
            int lhs = sstack.top();
            sstack.pop();
            res = processOperation(lhs,rhs,current);
            sstack.push(res);
        }
        else
        {
            sstack.push( std::stoi(current));
        }
    }
    return sstack.top();
}

int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::vector<std::string> tokens = { "18" };
        int expected = 18;
        int result = evalRPN(tokens);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::string> tokens = { "2","1","+","3","*"};
        int expected = 9;
        int result = evalRPN(tokens);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::string> tokens = { "4","13","5","/","+"};
        int expected = 6;
        int result = evalRPN(tokens);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::string> tokens = { "10","6","9","3","+","-11","*","/","17","+","5","+"};
        int expected = 22;
        int result = evalRPN(tokens);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return test_case;
}
