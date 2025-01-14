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

void dumpNumbers(const std::vector<int> &numbers )
{
    printf("[");
    bool first_time = true;
    for(size_t index = 0; index<numbers.size();index++)
    {
        if( ! first_time )
            printf(",");
        printf("%d", numbers[index] );
        first_time = false;
    }
    printf("]\n");
}


int firstMissingPositive(const std::vector<int> &numbers )
{
    std::vector<int> temp_data(100001,0);
    int retval = 0;

    for(int current : numbers )
    {
        if ( current > 0 )
            temp_data[current] = 1;
    }
    for(int index=1;index<100001;index++)
    {
        if( temp_data[index] == 0 )
        {
            retval = index;
            break;
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    int first_missing;

    printf("Leetcode 0041 - First Missing Positive\n");
    {
        std::vector<int> numbers = { 1,2, 0 };
        dumpNumbers( numbers );
        first_missing = firstMissingPositive( numbers );
        printf("First missing %d\n", first_missing);
    }

    {
        std::vector<int> numbers = { 3, 4, -1, 1 };
        dumpNumbers( numbers );
        first_missing = firstMissingPositive( numbers );
        printf("First missing %d\n", first_missing);
    }

    {
        std::vector<int> numbers = { 7,8,9,11,12};
        first_missing = firstMissingPositive( numbers );
        dumpNumbers( numbers );
        printf("First missing %d\n", first_missing);
    }
}
