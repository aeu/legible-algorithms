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

NS_INLINE int getLeft(int index)
{
    return index * 2;
}

NS_INLINE int getRight(int index)
{
    return index * 2 + 1;
}

void dumpArray(NSMutableArray *data)
{
    for(int index=1;index<[data count];index++)
    {
        if( index > 1 )
            printf(", ");
        printf("%2i", [[data objectAtIndex:index] intValue] );
    }
    printf("\n");
}


/**
 *
 * given a base index and an array, re-arranges the data so that the
 * tree whose root is at the index is max heaped.
 *
 * @param data array of integers being sorted
 * @param index of the root of the tree
 *
 */
void maxHeapify( NSMutableArray *data, int index )
{
    int heap_size;
    int parent, left, right, left_index, right_index;
    int largest = 0;

    if( [[data objectAtIndex:0] intValue ] != 0 )
        heap_size = [[data objectAtIndex:0] intValue ] ;
    else
        heap_size = [data count];
    
    left_index  = getLeft(index);
    right_index = getRight(index);
    
    parent = [[data objectAtIndex:index] intValue ];

    if( left_index < heap_size )
    {
        if( [[data objectAtIndex:left_index] intValue ] > [[data objectAtIndex:index] intValue ] )
        {
            largest = left_index;
        }
        else
        {
            largest = index;
        }
    }

    if( right_index < heap_size )
    {
        if( [[data objectAtIndex:right_index] intValue ] > [[data objectAtIndex:largest] intValue ] )
        {
            largest = right_index;
        }
    }

    if(( largest != 0 ) && (largest != index ))
    {
        [data exchangeObjectAtIndex:largest withObjectAtIndex:index ];
        maxHeapify( data, largest );
    }
}


/**
 * buids a max heap of the entire data array 
 *
 * @param data the data we're heaping
 */
void buildMaxHeap( NSMutableArray *data)
{
    for( int index = [ data count ] / 2 ; index >= 1; index-- )
    {
        maxHeapify( data, index );
    }
}


/**
 * Does a heapsort on the array of data.
 * Note that we are using the 0th element of the array to store the
 * heap size, which we can do because the data structure assumes a
 * root index that starts at 1 and c arrays start at 0.
 * 
 * @param data the data to be sorted
 *
 */

void doHeapsort( NSMutableArray *data )
{
    printf("before: \n");
    // insert the heap size at the 0th array position
    [data replaceObjectAtIndex:0 withObject:[NSNumber numberWithInt:[data count]]];
    dumpArray( data );
    
    buildMaxHeap( data );
    for(int index = [data count] -1 ; index >= 2; index-- )
    {
        [data exchangeObjectAtIndex:1 withObjectAtIndex:index];
        int heap_size = [[data objectAtIndex:0] intValue];
        heap_size--;
        [data replaceObjectAtIndex:0 withObject:[NSNumber numberWithInt:heap_size]];
        maxHeapify( data, 1);
    }
    printf("after: \n");
    dumpArray( data );
}


int main(int argc, char **argv)
{
    NSMutableArray *candidate_array = [[NSMutableArray alloc] initWithObjects:@0, @4, @1, @3, @2, @16, @9, @10, @14, @8, @7, nil];
    doHeapsort( candidate_array );
}
