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


void dumpStrings(std::vector<std::string> retval)
{
    for(auto curr : retval )
    {
        std::cout << curr << ", ";
    }
    std::cout << std::endl;
}


void backtrack(int n,
               int open,
               int close,
               std::vector<char> &path,
               std::vector<std::string> &retval)
{
    if( path.size() == n * 2 )
    {
        retval.push_back(std::string(path.begin(), path.end()));
        return;
    }

    if( open < n )
    {
        path.push_back('(');
        backtrack(n,open+1,close,path,retval);
        path.pop_back();
    }

    if(( open > close ) && ( close < n ))
    {
        path.push_back(')');
        backtrack(n,open,close+1,path,retval);
        path.pop_back();
    }
}


std::vector<std::string> generateParenthesis(int n)
{
    std::vector<std::string> retval;
    std::vector<char> path;
    int open = 0;
    int close = 0;
    backtrack(n,open,close,path,retval);
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC 22 - Generate Parentheses" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 3;
        std::vector<std::string> result =  generateParenthesis(n);
        std::vector<std::string> expected = {"((()))","(()())","(())()","()(())","()()()"};
        
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        int n = 1;
        std::vector<std::string> result =  generateParenthesis(n);
        std::vector<std::string> expected = {"()"};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
