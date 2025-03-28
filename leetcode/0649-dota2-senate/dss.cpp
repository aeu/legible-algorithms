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
    std::queue<int> radiant_queue;
    std::queue<int> dire_queue;

    for(int index=0;index<senate.length();index++)
    {
        char current = senate[index];
        if( current == 'R' )
            radiant_queue.push(index);
        else
            dire_queue.push(index);
    }
    while( ( ! radiant_queue.empty() ) && ( ! dire_queue.empty() ))
    {
        int rtop = radiant_queue.front();
        int dtop = dire_queue.front();

        if( rtop < dtop )
        {
            dire_queue.pop();
            radiant_queue.push( rtop + senate.length() );
        }
        else
        {
            radiant_queue.pop();
            dire_queue.push( dtop + senate.length() );
        }
    }
    if( radiant_queue.empty() )
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
        std::string senate = "RDD";
        std::string expected = "Dire";
        std::string result = predictPartyVictory(senate);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        // std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
