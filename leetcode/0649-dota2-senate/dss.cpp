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
#include <stack>
#include <limits.h>


std::string predictPartyVictory(std::string senate)
{
    std::stack<int> radiant_stack;
    std::stack<int> dire_stack;

    for(int index=0;index<senate.length();index++)
    {
        char current = senate[index];
        if( current == 'R' )
            radiant_stack.push(index);
        else
            dire_stack.push(index);
    }

    while( ( ! radiant_stack.empty() ) && ( ! dire_stack.empty() ))
    {
        int rtop = radiant_stack.top();
        int dtop = dire_stack.top();

        if( rtop < dtop )
        {
            dire_stack.pop();
            radiant_stack.push( rtop + senate.length() );
        }
        else
        {
            radiant_stack.pop();
            dire_stack.push( dtop + senate.length() );
        }
    }
    if( radiant_stack.empty() )
        return "Dire";
    return "Radiant";
}



int main(int argc, char **argv)
{
    std::cout << "Leetcode #649 - Dota2 Senate" << std::endl << std::endl;
    int test_case = 1;
    {
        std::string senate = "RD";
        std::string expected = "Radiant";
        std::string result = predictPartyVictory(senate);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        // std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string senate = "RD";
        std::string expected = "Radiant";
        std::string result = predictPartyVictory(senate);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        // std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::string senate = "RD";
        std::string expected = "Radiant";
        std::string result = predictPartyVictory(senate);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        // std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
