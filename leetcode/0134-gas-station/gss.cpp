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


int gasFromCurrentStation(int current, std::vector<int> &gas)
{
    return gas[current];
}

int costToNextGasStation(int current, std::vector<int> &cost)
{
    return cost[current];
}

int canCompleteCircuit(std::vector<int> &gas,
                       std::vector<int> &cost)
{
    int did_complete = false;
    int index;
    for(index = 0;index< gas.size();index++)
    {
        int current_gas = 0;
        int start_position = index;
        int current_position = index;
        bool full_loop = false;
        while( ! full_loop )
        {
            current_gas += gasFromCurrentStation(current_position,gas);
            current_gas -= costToNextGasStation(current_position,cost);
            if( current_gas <  0 )
                break;
            current_position = (( current_position + 1 ) % gas.size() );
            if( current_position == start_position )
                full_loop = true;
        }
        if( full_loop )
        {
            did_complete = true;
            break;
        }
    }
    if( did_complete )
        return index;
    return -1;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #134 - Gas Station" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> gas  = {1,2,3,4,5};
        std::vector<int> cost = {3,4,5,1,2};
        int expected = 3;
        int result = canCompleteCircuit(gas,cost);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> gas  = {2,3,4};
        std::vector<int> cost = {3,4,3};
        int expected = -1;
        int result = canCompleteCircuit(gas,cost);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
