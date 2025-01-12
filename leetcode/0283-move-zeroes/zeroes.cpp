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
    int num_zeroes = 0;
    while(seek<numbers.size())
    {
        if( numbers[seek] == 0 )
        {
            seek++;
            num_zeroes++;
            continue;
        }   
        if( insert != seek )
        {
            numbers[insert] = numbers[seek];
            insert++;
        }
        if( seek > ( numbers.size() - num_zeroes - 1 ))
        {
            numbers[seek] = 0;
        }
        seek++;
    }
}

#if 0
void moveZeroes(std::vector<int> &numbers)
{
    int last = numbers.size() - 1;
    for(int index=0;index<last;index++)
    {
        if( numbers[index] == 0 )
        {
            for(int current=index;current<last;current++)
            {
                numbers[current] = numbers[current+1];
            }
            numbers[last] = 0;
            last--;
        }
    }
}
#endif

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
