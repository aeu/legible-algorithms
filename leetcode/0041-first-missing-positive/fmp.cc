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

void dumpIndexes(std::vector<int> indexes )
{
    std::vector<int>::iterator indices_iterator;
    printf("[");
    int first = 1;
    for(  indices_iterator = indexes.begin();
          indices_iterator != indexes.end();
          indices_iterator++ )
    {
        if( ! first )
            printf(",");
        int current_index = (int)*indices_iterator;
        printf("%d",current_index );
        first = 0;
    }
    printf("]\n");
}


int firstMissingPositive(std::vector<int>& nums )
{
    int *temp_data = (int *)malloc( 100001 * sizeof(int));
    memset( temp_data, 0 , 100001 * sizeof(int));
    int retval = 0;

    std::vector<int>::iterator numiter;
    for(numiter = nums.begin();
        numiter != nums.end();
        numiter++)
    {
        int current = *numiter;
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
    free( temp_data );
    return retval;
}

int main(int argc, char **argv)
{
    int first_missing;

    printf("Leetcode 0041 - First Missing Positive\n");
    {
        std::vector<int> numbers;
        numbers.push_back( 1 );
        numbers.push_back( 2 );
        numbers.push_back( 0 );
        dumpIndexes( numbers );
        first_missing = firstMissingPositive( numbers );
        printf("First missing %d\n", first_missing);
    }

    {
        std::vector<int> numbers;
        numbers.push_back( 3 );
        numbers.push_back( 4 );
        numbers.push_back( -1 );
        numbers.push_back( 1 );
        dumpIndexes( numbers );
        first_missing = firstMissingPositive( numbers );
        printf("First missing %d\n", first_missing);
    }

    {
        std::vector<int> numbers;
        numbers.push_back( 7 );
        numbers.push_back( 8 );
        numbers.push_back( 9 );
        numbers.push_back( 11 );
        numbers.push_back( 12 );
        first_missing = firstMissingPositive( numbers );
        dumpIndexes( numbers );
        printf("First missing %d\n", first_missing);
    }
}
