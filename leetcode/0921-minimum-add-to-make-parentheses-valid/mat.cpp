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



int minAddToMakeValid(std::string s)
{
    int unclosed_opens=0;
    int closes_without_opens=0;

    for(const auto &curr : s )
    {
        if( curr == '(' )
        {
            unclosed_opens++;
        }
        else if( curr == ')' )
        {
            if( unclosed_opens > 0 )
            {
                unclosed_opens--;
            }
            else
            {
                closes_without_opens++;
            }
        }
    }
    return unclosed_opens + closes_without_opens;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0921-minimum-add-to-make-parentheses-valid" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "())";
        int expected = 1;
        int result = minAddToMakeValid(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "(((";
        int expected = 3;
        int result = minAddToMakeValid(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
