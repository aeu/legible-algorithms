// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#import <Foundation/Foundation.h>
#import <stdio.h>

void dumpArray(NSMutableArray *data)
{
    for(int index=0;index<[data count];index++)
    {
        if( index > 0 )
            printf(", ");
        printf("%2i", [[data objectAtIndex:index] intValue] );
    }
    printf("\n");
}

int partition(NSMutableArray *data, int start_index, int end_index)
{
    int pivot_value      = [[data objectAtIndex:end_index] intValue];
    int pivot_index      = start_index - 1 ;
    for(int loop_pointer = start_index; loop_pointer < end_index; loop_pointer++)
    {
        int loop_value = [[data objectAtIndex:loop_pointer] intValue];
        if( loop_value <= pivot_value )
        {
            pivot_index++;
            [data exchangeObjectAtIndex:loop_pointer withObjectAtIndex:pivot_index];
        }
    }
    pivot_index++;
    [data exchangeObjectAtIndex:end_index withObjectAtIndex:pivot_index];
    return pivot_index;
}


void quicksort(NSMutableArray *data, int start_index, int end_index)
{
    int pivot;
    if( start_index < end_index )
    {
        pivot = partition( data, start_index, end_index );
        
        quicksort( data, start_index, pivot - 1 );
        quicksort( data, pivot+1,     end_index );
    }
}


int main(int argc, char **argv)
{
    NSMutableArray *candidate_array = [[NSMutableArray alloc] initWithObjects:@6, @10, @13, @5, @8, @3, @2, @11, nil];
    printf("Before:\n");
    dumpArray( candidate_array );
    quicksort( candidate_array, 0, [candidate_array count]-1 );
    printf("After:\n");
    dumpArray( candidate_array );
}


