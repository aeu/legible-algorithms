// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

void dumpNumbers(const std::vector<int> &numbers)
{
    bool first_time = true;
    std::cout << "[" ;
    for(int current : numbers )
    {
        if( ! first_time )
            std::cout << ", " ;
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

void dumpBooleans(const std::vector<bool> &booleans)
{
    bool first_time = true;
    std::cout << "[" ;
    for(bool current : booleans )
    {
        if( ! first_time )
            std::cout << ", " ;
        std::cout << ( current == true ? "true" : "false" ) ;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

std::vector<bool> kidsWithCandies(std::vector<int>& candies,
                                  int extra_candies) 
{
    std::vector<bool> greatests;
    int max_candies = *std::max_element(candies.begin(), candies.end());
    for(int current : candies )
    {
        if( ( current + extra_candies) >= max_candies )
            greatests.push_back( true );
        else
            greatests.push_back( false );
    }
    return greatests;
}
    
int main(int argc, char **argv)
{
    std::cout << "Leetcode #1431 - Kids With the Greatest Number of Candies" << std::endl;
    {
        int extra_candies = 3;
        std::vector<int> candies = { 2,3,5,1,3 };
        std::vector<bool> results = kidsWithCandies(candies, extra_candies);
        dumpNumbers(candies);
        dumpBooleans(results);
    }
    {
        int extra_candies = 1;
        std::vector<int> candies = { 4,2,1,1,2 };
        std::vector<bool> results = kidsWithCandies(candies, extra_candies);
        dumpNumbers(candies);
        dumpBooleans(results);
    }
    {
        int extra_candies = 10;
        std::vector<int> candies = { 12,1,12 };
        std::vector<bool> results = kidsWithCandies(candies, extra_candies);
        dumpNumbers(candies);
        dumpBooleans(results);
    }
    return 1;
}
