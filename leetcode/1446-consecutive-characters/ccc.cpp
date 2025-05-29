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

int maxPower(std::string s)
{
    if( s.length() == 0 )
        return 0;
    int max_power = 1;
    int current_power = 1;
    for(int index=0;index<s.length();index++)
    {
        if( index > 0 )
        {
            if( s[index] == s[index-1] )
            {
                current_power++;
                max_power = std::max(current_power,max_power);
            }
            else
            {
                current_power = 1;
            }
        }
    }
    return max_power;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "1446-consecutive-characters" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string s = "leetcode";
        int result = maxPower(s);
        int expected = 2;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string s = "abbcccddddeeeeedcba";
        int result = maxPower(s);
        int expected = 5;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
