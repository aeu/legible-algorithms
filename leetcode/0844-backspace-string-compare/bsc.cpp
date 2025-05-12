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


bool backspaceCompare(std::string s, std::string t)
{
    std::string safter;
    int index = s.size()-1;
    int should_skip = 0;
    while( index>=0)
    {
        if( s[index] == '#' )
        {
            should_skip++;
        }
        else
        {
            if( should_skip )
            {
                should_skip--;
            }
            else
            {
                safter.push_back( s[index] );
            }
        }
        index--;
    }
    std::string tafter;
    index = t.size()-1;
    should_skip = 0;
    while( index>=0)
    {
        if( t[index] == '#' )
        {
            should_skip++;
        }
        else
        {
            if( should_skip )
            {
                should_skip--;
            }
            else
            {
                tafter.push_back( t[index] );
            }
        }
        index--;
    }
    return ( tafter == safter );
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0844-backspace-string-compare" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "a##c";
        std::string t = "#a#c";
        bool expected = true;
        bool result = backspaceCompare(s,t);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "ab#c";
        std::string t = "ad#c";
        bool expected = true;
        bool result = backspaceCompare(s,t);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "ab##";
        std::string t = "c#d#";
        bool expected = true;
        bool result = backspaceCompare(s,t);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "a#c";
        std::string t = "b";
        bool expected = false;
        bool result = backspaceCompare(s,t);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
