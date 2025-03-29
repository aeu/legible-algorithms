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
    bool did_reset = false;
    int last_reset = 0;
    int current_tank =  0;
    int net_tank = 0;
    for(int index=0;index<gas.size();index++)
    {
        current_tank += gasFromCurrentStation(index,gas) - costToNextGasStation(index,cost);
        net_tank +=  (gasFromCurrentStation(index,gas) - costToNextGasStation(index,cost));
        if( current_tank < 0 )
        {
            last_reset = index;
            current_tank = 0;
            did_reset = true;
        }
    }
    if( did_reset == false )
        return 0;

    if( net_tank >= 0 )
        return last_reset+1;
    
    return -1;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #134 - Gas Station" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> gas  = {3,1,1};
        std::vector<int> cost = {1,2,2};
        int expected = 0;
        int result = canCompleteCircuit(gas,cost);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
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
