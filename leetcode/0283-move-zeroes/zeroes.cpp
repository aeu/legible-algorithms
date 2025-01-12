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
#include <sstream>


void dumpNumbers(std::vector<int> numbers)
{
    bool first = true;
    for(int current : numbers )
    {
        if( ! first )
        {
            std::cout << ", ";
        }
        std::cout << current ;
        first = false;
    }
    std::cout << std::endl;
}

void moveZeroes(std::vector<int> &numbers)
{
    int seek = 0;
    int insert = 0;
    while(seek<numbers.size())
    {
        if( numbers[seek] == 0 )
        {
            seek++;
            continue;
        }   
        if( insert != seek )
        {
            numbers[insert++] = numbers[seek++];
        }
    }
    while(insert<numbers.size())
    {
        numbers[insert++] = 0;
    }
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #283 - Move Zeroes" << std::endl << std::endl;
    {
        std::vector<int> numbers = { 0,1,0,3,12 };
        dumpNumbers( numbers );
        moveZeroes(numbers);
        dumpNumbers( numbers );
    }
    {
        std::vector<int> numbers = { 0 };
        dumpNumbers( numbers );
        moveZeroes(numbers);
        dumpNumbers( numbers );
    }
}
