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


int romanToInt(std::string s)
{
    std::unordered_map<char,int> lookups;
    lookups['I'] = 1;
    lookups['V'] = 5;
    lookups['X'] = 10;
    lookups['L'] = 50;
    lookups['C'] = 100;
    lookups['D'] = 500;
    lookups['M'] = 1000;
    int total = 0;
    int N = s.length();
    for(int index=0;index<N;index++)
    {
        char curr = s[index];
        int val = lookups[curr];
        if( index < ( N - 1 ))
        {
            char next = s[index+1];
            int nval = lookups[next];
            if( nval > val )
                val *= -1;
        }
        total += val;
    }
    return total;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0013-roman-to-integer" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "III";
        int expected = 3;
        int result = romanToInt(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "LVIII";
        int expected = 58;
        int result = romanToInt(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::string s = "MCMXCIV";
        int expected = 1994;
        int result = romanToInt(s);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
