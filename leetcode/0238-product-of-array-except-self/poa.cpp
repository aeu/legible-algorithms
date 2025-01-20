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
    std::cout << "[";
    for(int current : numbers )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current ;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}
    
std::vector<int> productOfArrayExceptSelf(const std::vector<int> &numbers)
{
    std::vector<int> results ( numbers.size(),1);

    for(int index=1;index<numbers.size();index++)
    {
        results[index] = numbers[index-1] * results[index-1];
    }

    int right_product = 1;
    for(int index=numbers.size()-2;index>=0;index--)
    {
        right_product *= numbers[index+1];
        results[index] *= right_product;
    }
    return results;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #238 - Product of Array Except Self" << std::endl;
    {
        std::vector<int> numbers = { 5,2,3,4};
        std::cout << "Input  : ";
        dumpNumbers( numbers );
        std::vector<int> results = productOfArrayExceptSelf(numbers);
        std::cout << "Results: ";
        dumpNumbers(results);
    }
    {
        std::vector<int> numbers = { -1,1,0,-3,3};
        std::cout << "Input  : ";
        dumpNumbers( numbers );
        std::vector<int> results = productOfArrayExceptSelf(numbers);
        std::cout << "Results: ";
        dumpNumbers(results);
    }
    return 1;
}
