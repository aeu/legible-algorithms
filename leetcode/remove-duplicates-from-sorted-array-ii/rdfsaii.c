// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize)
{
    if( numsSize <=2 )
        return numsSize;
    
    int *minus_one, *minus_two, *read_point, *insertion_point;
    minus_two       = nums;
    minus_one       = nums+1;
    read_point      = nums+2;
    insertion_point = nums+2;
    int new_length = 2;
    while( read_point < nums + numsSize )
    {
        if(( *read_point == *minus_one ) && ( *read_point == *minus_two ))
        {
            read_point++;
            continue;
        }
        *insertion_point = *read_point;
        minus_two++;
        minus_one++;
        read_point++;
        insertion_point++;
        new_length++;
    }
    return new_length;
}  

int main(int argc, char **argv)
{
    {
        int nums[6] = { 1,1,1,2,2,3 };
        int new_count = removeDuplicates( &nums[0], 6 );
        printf("Output %d, ", new_count );
        printf("[");
        for(int looper = 0; looper<6;looper++ )
        {
            if( looper > 0 )
                printf(",");
            if( looper < new_count )
                printf("%d", nums[looper] );
            else
                printf("_" );
        }
        printf("]\n");
    }
    {
        int nums[12] = { 1,1,1,2,2,3,3,3,3,4,5,6 };
        int new_count = removeDuplicates( &nums[0], 12 );
        printf("Output %d, ", new_count );
        printf("[");
        for(int looper = 0; looper<12;looper++ )
        {
            if( looper > 0 )
                printf(",");
            if( looper < new_count )
                printf("%d", nums[looper] );
            else
                printf("_" );
        }
        printf("]\n");
    }
    {
        int nums[4] = { 1,1,1,1 };
        int new_count = removeDuplicates( &nums[0], 4 );
        printf("Output %d, ", new_count );
        printf("[");
        for(int looper = 0; looper<4;looper++ )
        {
            if( looper > 0 )
                printf(",");
            if( looper < new_count )
                printf("%d", nums[looper] );
            else
                printf("_" );
        }
        printf("]\n");
    }
}
