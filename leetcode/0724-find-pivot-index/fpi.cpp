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

void dumpNumbers(const std::vector<int> &numbers )
{
    bool first_time = true;
    for(int current : numbers )
    {
        if( ! first_time )
            std::cout << ", " ;
        std::cout << current ;
        first_time = false;
    }
    std::cout << std::endl;
}   


int findPivotIndex(const std::vector<int> &numbers)
{
    if( numbers.size() == 0 )
        return -1;
    int total = 0;
    for( int current : numbers )
    {
        total += current;
    }
    int left_side = 0;
    int right_side = total;
    for(size_t index=0;index<numbers.size();index++)
    {
        right_side -= numbers[index];
        if( left_side == right_side )
        {
            return index;
        }
        left_side+=numbers[index];
    }
    return -1;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode 0724 - Find Pivot Index" << std::endl;
    {
        std::vector<int> numbers = {1,7,3,6,5,6};
        int pivot_index = findPivotIndex(numbers);
        dumpNumbers( numbers);
        std::cout << "Pivot Index: " << pivot_index << std::endl;
    }
    {
        std::vector<int> numbers = {1,2,3};
        int pivot_index = findPivotIndex(numbers);
        dumpNumbers( numbers);
        std::cout << "Pivot Index: " << pivot_index << std::endl;
    }
    {
        std::vector<int> numbers = {2,1,-1};
        int pivot_index = findPivotIndex(numbers);
        dumpNumbers( numbers);
        std::cout << "Pivot Index: " << pivot_index << std::endl;
    }
}
