// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>

void dumpNumbers(const std::vector<int> &numbers )
{ 
    std::cout << "[";
    bool first_time = true;
    for(int current : numbers )
    {
        if( ! first_time )
            std::cout << ", " ;
        std::cout << current ;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}   

bool uniqueOccurrences(std::vector<int>& arr)
{
    std::map<int,int>counts;
    for(int current : arr )
    {
        if( counts.find(current) == counts.end() )
        {
            counts[current] = 1;
        }
        else
        {
            int existing = counts[current];
            existing++;
            counts[current] = existing;
        }
    }

    std::unordered_set<int> unique_check;
    for(auto pair : counts )
    {
        auto result = unique_check.insert( pair.second );
        if( ! result.second )
            return false;
    }
    return true;
}
int main(int argc, char **argv)
{
    std::cout << "Leetcode 1207 - Unique Number of Occurrences" << std::endl;
    {
        std::vector<int> numbers = {1,2,2,1,1,3};
        bool unique = uniqueOccurrences(numbers);
        dumpNumbers(numbers);
        std::cout << "uniques: " << ( unique ? "true" : "false" )<< std::endl;
    } 
    {
        std::vector<int> numbers = {1,2};
        bool unique = uniqueOccurrences(numbers);
        dumpNumbers(numbers);
        std::cout << "uniques: " << ( unique ? "true" : "false" )<< std::endl;
    }
    {
        std::vector<int> numbers = {-3,0,1,-3,1,1,1,-3,10,0};
        bool unique = uniqueOccurrences(numbers);
        dumpNumbers(numbers);
        std::cout << "uniques: " << ( unique ? "true" : "false" )<< std::endl;
    }
}
