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


std::vector<std::vector<char>> lookups =
    {{},
     {},
     {'a','b','c'},
     {'d','e','f'},
     {'g','h','i'},
     {'j','k','l'},
     {'m','n','o'},
     {'p','q','r','s'},
     {'t','u','v'},
     {'w','x','y','z'}};



// this follows the standard backtrace pattern, which is as follows:
//
// backtrace
//    exit condition
//    advance input data
//    push
//    backtrace
//    pop
//
// ion this case we are converting each digit to a number, then
// checking a lookup table for all the letters that go with that
// number.  each letter is in turn pushed on to the backtrace stack
// and popped.  When we have them all processed, push the resulting
// string on to the return stack

void backtrace(std::string digits,
               int start_point,
               std::vector<char> &path,
               std::vector<std::string> &retval)
{
    if( start_point == digits.length() )
    {
        if( path.size() > 0 )
            retval.push_back(std::string(path.begin(),path.end()));
        return;
    }
    long num = std::stol(digits.substr(start_point,1));
    for( auto current : lookups[num] )
    {
        path.push_back(current);
        backtrace(digits,start_point+1,path,retval);
        path.pop_back();
    }
}

std::vector<std::string> letterCombinations(std::string digits)
{
    int start_point = 0;
    std::vector<char> path;
    std::vector<std::string> retval;
    backtrace(digits,start_point,path,retval);
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0017-letter-combinations-of-a-phone-number" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string digits = "23";
        std::vector<std::string> result = letterCombinations(digits);
        std::vector<std::string> expected = {"ad","ae","af","bd","be","bf","cd","ce","cf"};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::string digits = "";
        std::vector<std::string> result = letterCombinations(digits);
        std::vector<std::string> expected = {};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::string digits = "2";
        std::vector<std::string> result = letterCombinations(digits);
        std::vector<std::string> expected = {"a","b","c"};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
