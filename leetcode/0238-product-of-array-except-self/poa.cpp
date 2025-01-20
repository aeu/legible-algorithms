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
    std::vector<int> products ( numbers.size(),1);
    std::vector<int> left_products ( numbers.size(),1);
    std::vector<int> right_products ( numbers.size(),0);
    right_products[numbers.size()-1] = 1;
    for(int index=numbers.size()-2;index>=0;index--)
    {
        right_products[index] = right_products[index+1] * numbers[index+1] ;
    }
    left_products[0] = 1;
    for(int index=1;index<numbers.size();index++)
    {
        left_products[index] = numbers[index-1] * left_products[index-1];
    }
    for(int index=0;index<numbers.size();index++)
    {
        products[index] = left_products[index] * right_products[index];
    }
    dumpNumbers(left_products);
    dumpNumbers(right_products);
    dumpNumbers(products);

    
    return products;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #238 - Product of Array Except Self" << std::endl;
    {
        std::vector<int> numbers = { 5,2,3,4};
        dumpNumbers( numbers );
        productOfArrayExceptSelf(numbers);
    }
    return 1;
}
