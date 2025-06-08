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

bool validateStackSequences(std::vector<int>& pushed,
                            std::vector<int>& popped)
{
    std::stack<int> pustack;
    int popped_index = 0;
    
    for(const auto &curr : pushed )
    {
        pustack.push(curr);
        while( ( ! pustack.empty() ) && ( pustack.top() == popped[popped_index] ))
        {
            pustack.pop();
            popped_index++;
        }
    }
    return pustack.empty();
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0946-validate-stack-sequences" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> pushed = { 1,0,2};
        std::vector<int> popped = { 2,1,0};
        bool expected = false;
        bool result = validateStackSequences(pushed,popped);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> pushed = { 1,2,3,4,5 };
        std::vector<int> popped = { 4,5,3,2,1 };
        bool expected = true;
        bool result = validateStackSequences(pushed,popped);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> pushed = { 1,2,3,4,5 };
        std::vector<int> popped = { 4,3,5,1,2 };
        bool expected = false;
        bool result = validateStackSequences(pushed,popped);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
