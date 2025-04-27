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
#include <unordered_map>
#include <stack>
#include <limits.h>

std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
{
    std::vector<int> retval(temperatures.size(),0);
    std::stack<int> mstack;
    
    for(int index=0;index<temperatures.size();index++)
    {
        int current = temperatures[index];
        while(( ! mstack.empty() ) &&
              ( current > temperatures[mstack.top()] ))
        {
            int previous_index = mstack.top();
            mstack.pop();
            retval[previous_index] = index - previous_index;
        }
        mstack.push(index);
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0739-daily-temperatures" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> temperatures = {73,74,75,71,69,72,76,73};
        std::vector<int> expected     = {1,1,4,2,1,1,0,0};
        std::vector<int> result       = dailyTemperatures(temperatures);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> temperatures = {30,40,50,60};
        std::vector<int> expected     = {1,1,1,0};
        std::vector<int> result       = dailyTemperatures(temperatures);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> temperatures = {30,60,90};
        std::vector<int> expected     = {1,1,0};
        std::vector<int> result       = dailyTemperatures(temperatures);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
