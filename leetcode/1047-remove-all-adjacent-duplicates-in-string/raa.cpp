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
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

std::string removeDuplicates(std::string s)
{
    std::string retval;
    std::stack<char> builder;
    for( const auto &curr : s )
    {
        bool did_pop = false;
        if( builder.empty() )
        {
            builder.push(curr);
            continue;
        }
        while(( ! builder.empty()) && ( builder.top() == curr ))
        {
            builder.pop();
            did_pop = true;
        }
        if( ! did_pop )
            builder.push(curr);
    }
    while( ! builder.empty() )
    {
        retval.push_back( builder.top() );
        builder.pop();
    }
    std::reverse(retval.begin(),retval.end());
    return retval;
    
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "1047-remove-all-adjacent-duplicates-in-string" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "abbaca";
        std::string result = removeDuplicates(s);
        std::string expected = "ca";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "azxxzy";
        std::string result = removeDuplicates(s);
        std::string expected = "ay";
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
