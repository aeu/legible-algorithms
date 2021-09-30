// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//

#import <Foundation/Foundation.h>

NSMutableArray *merge(NSMutableArray *left, NSMutableArray *right);

void dumpArray(NSArray *data)
{
    for( int index = 0; index < [data count]; index++)
    {
        NSNumber *current = [data objectAtIndex:index];
        printf( "%2d " , [current intValue]);
    }
    printf("\n");
}

/**
 * Takes the array, divides it into two, and then sorts each
 * individually
 * 
 * @param array_being_sorted the array that is going to be sorted
 * @return the result of the sorting
 */
NSMutableArray *mergeSort(NSMutableArray *array_being_sorted)
{
    NSMutableArray *sorted_left;
    NSMutableArray *sorted_right;
    int array_length = [array_being_sorted count];
    if( array_length >= 2 )
    {
        int left_end = array_length / 2;
        int right_start = left_end;
        
        NSRange left_range = NSMakeRange( 0, left_end );
        NSMutableArray *left_side = [[NSMutableArray alloc] initWithArray:[array_being_sorted subarrayWithRange:left_range]];
        
        sorted_left = mergeSort( left_side );
              
        NSRange right_range = NSMakeRange( right_start, array_length - right_start );
        NSMutableArray *right_side = [[NSMutableArray alloc] initWithArray:[array_being_sorted subarrayWithRange:right_range]];
        
        sorted_right = mergeSort( right_side );
        
        NSMutableArray *merged = merge( sorted_left, sorted_right );
        return merged;
    }
    //
    // An array with a length of 1 we can assume is already sorted, so
    // we don't have do anything.
    //
    return array_being_sorted;
}

/**
 * Given two arrays, merges them in order of lowest to highest.
 * 
 * @param left the left side array
 * @param right the right side array
 * @return the arrays, merged in sized order.
 */
NSMutableArray *merge(NSMutableArray *left, NSMutableArray *right)
{
    //
    // Add sentinels to the arrays to simplify the code.
    //
    [left addObject:[NSNumber numberWithInt:INT_MAX]];
    [right addObject:[NSNumber numberWithInt:INT_MAX]];
    
    NSMutableArray *retval = [[NSMutableArray alloc] init];
    int left_index = 0;
    int right_index = 0;
    int total_items = [left count] + [right count];
    for(int item_count = 0; item_count < total_items; item_count++ )
    {
        NSNumber *left_num = [left objectAtIndex:left_index];
        NSNumber *right_num = [right objectAtIndex:right_index];

        if( [left_num integerValue] < [right_num integerValue] )
        {
            if( left_index < ( [left count] - 1 ))
            {
                [retval addObject:left_num];
                left_index++;
            }
        }
        else
        {
            if( right_index < ( [right count] - 1 ) )
            {
                [retval addObject:right_num];
                right_index++;
            }
        }
    }
    return retval;
}


int main(int argc, char **argv)
{
    int number_count = 1000000;
    NSMutableArray *to_be_sorted = [[NSMutableArray alloc] init];
    for(int nindex=0;nindex<number_count;nindex++ )
    {
        [to_be_sorted addObject:[NSNumber numberWithInt:arc4random_uniform(INT_MAX)]];
    }
    NSTimeInterval sort_time;
    NSDate *start = [NSDate date];
    NSMutableArray *sorted = mergeSort( to_be_sorted );
    sort_time = fabs([start timeIntervalSinceNow]);
    printf("Merge sort of %d integers took %.3fs\n", number_count, sort_time );

#if 0
    //
    // uncomment this to test.  Will sort a small array of itegers.
    //
    number_count = 17;
    to_be_sorted = [[NSMutableArray alloc] init];
    for(int nindex=0;nindex<number_count;nindex++ )
    {
        [to_be_sorted addObject:[NSNumber numberWithInt:arc4random_uniform(20)]];
    }
    dumpArray( to_be_sorted );
    sorted = mergeSort( to_be_sorted );
    dumpArray( sorted );
#endif

}

