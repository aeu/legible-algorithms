// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82


#import <limits.h>
#import <Foundation/Foundation.h>
#import "Merger.h"

@implementation Merger


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


-(NSMutableArray *)mergeLists:(NSMutableArray *)lists
                 startAtIndex:(int)index
{
    int current_index = index;
    if(( [lists count] - index ) >= 2 )
    {
        NSMutableArray *left_one = [lists objectAtIndex:current_index];
        current_index++;
        NSMutableArray *left_two = [lists objectAtIndex:current_index];
        current_index++;

        NSMutableArray *left = [self mergeList:left_one withList:left_two];
        NSMutableArray *right = [self mergeLists:lists startAtIndex:current_index];
        return [self mergeList:left withList:right];
    }
    else if(( [lists count] - index ) == 1 )
    {
        NSMutableArray *left_one = [lists objectAtIndex:current_index];
        return left_one;
    }
    return nil;
}



-(NSMutableArray *)mergeList:(NSMutableArray *)left
                    withList:(NSMutableArray *)right
{
    printf("merging : \n\t");
    dumpArray(left);
    printf("\t");
    dumpArray(right);
              
    NSMutableArray *retval = [[NSMutableArray alloc] init];
    int left_index  = 0;
    int right_index = 0;
    int left_max    = [left count];
    int right_max   = [right count];
    int total_items = [left count] + [right count];
    bool done       = false;

    int left_value, right_value;

    if(( left == nil ) && right == nil )
    {
        return nil;
    }

    if( left == nil )
        return right;
    if( right == nil )
        return left;
    
    while( ! done )
    {
        if(( left_index == left_max ) && ( right_index == right_max ))
        {
            done = true;
            break;
        }
        int left_value  = INT_MAX;
        if( left_index < left_max )
            left_value = [[ left objectAtIndex:left_index] intValue ];
        int right_value = INT_MAX;
        if( right_index < right_max )
            right_value = [[right objectAtIndex:right_index] intValue];
        
        if( left_value <= right_value )
        {
            [retval addObject:[left objectAtIndex:left_index]];
            left_index++;
        }
        else
        {
            [retval addObject:[right objectAtIndex:right_index]];
            right_index++;
        }
    }
    dumpArray(retval);
    return retval;
}


-(NSMutableArray *)mergeKLists:(NSMutableArray *)lists
{
    [self mergeLists:lists startAtIndex:0];
    return nil;
}

@end
