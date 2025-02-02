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
#include <stack>

void dumpValues(std::vector<int> &values)
{
    bool first_time = true;
    std::cout << "[";
    for(int current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

typedef struct ValuePostitionPair
{
    int value;
    int position;
} ValuePositionPair;


std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
{
    std::vector<int> answer( temperatures.size(),0);
    std::stack<ValuePositionPair> vpps;
    for(int index=temperatures.size()-1;index>=0;index--)
    {
        while (!vpps.empty() && vpps.top().value <= temperatures[index])
        {
            vpps.pop();
        }

        if (!vpps.empty())
        {
            int offset = vpps.top().position - index;
            answer[index] = offset;
        }

        ValuePositionPair current;
        current.value = temperatures[index];
        current.position = index;
        vpps.push(current);
    }
    return answer;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #739 - Daily Temperatures" << std::endl << std::endl;
    {
        std::cout << "Example 1" << std::endl;
        std::vector<int> temperatures = {73,74,75,71,69,72,76,73};
        std::cout << "Temps: " ;
        dumpValues(temperatures);
        std::vector<int> answer = dailyTemperatures(temperatures);
        std::cout << "Wait Days: " ;
        dumpValues(answer);
    }
    {
        std::cout << "Example 2" << std::endl;
        std::vector<int> temperatures = {30,40,50,60};
        std::cout << "Temps: " ;
        dumpValues(temperatures);
        std::vector<int> answer = dailyTemperatures(temperatures);
        std::cout << "Wait Days: " ;
        dumpValues(answer);
    }
    {
        std::cout << "Example 3" << std::endl;
        std::vector<int> temperatures = {30,60,90};
        std::cout << "Temps: " ;
        dumpValues(temperatures);
        std::vector<int> answer = dailyTemperatures(temperatures);
        std::cout << "Wait Days: " ;
        dumpValues(answer);
    }
    return -1;
}
