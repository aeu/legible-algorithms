// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82


#include <vector>
#include <algorithm>
#include <stdio.h>


void dumpValues(std::vector<char> &values )
{
    for( auto current : values )
    {
        printf("%c", current );
    }
    printf("\n");
}

void generatePermutations( std::vector<char> &values, int size )
{
    if( size == 1 )
    {
        dumpValues( values );
    }
    else
    {
        for(int index=0;index<size;index++)
        {
            generatePermutations( values, size - 1 );
            if( size & 1 )
            {
                std::swap( values[0], values[ size - 1 ] );
            }
            else
            {
                std::swap( values[index], values[ size - 1 ] );
            }
        }
    }
}

int main(int argc, char **argv)
{
    printf("Heap's algorithm for generating permutations\n");

    std::vector<char> values = { 'a', 'b', 'c', 'd' };

    printf("Generating all permutations for: ");
    dumpValues( values );
    
    generatePermutations(values,  (int)values.size() );
}
