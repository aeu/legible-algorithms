// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//


#import <Foundation/Foundation.h>
#import <limits.h>

void dumpArray(NSArray *data)
{
    for( int index = 0; index < [data count]; index++)
    {
        NSNumber *current = [data objectAtIndex:index];
        printf( "%2d " , [current intValue]);
    }
    printf("\n");
}



NSArray *reverse(NSArray *input)
{
    NSMutableArray *retval = [[NSMutableArray alloc] init];
    NSMutableArray *stack  = [[NSMutableArray alloc] init];

    for(int index=0;index<[input count];index++)
    {
        NSNumber *current = [input objectAtIndex:index];
        if( [current intValue] & 1 )
        {
            for(int stack_index=0;stack_index<[stack count];stack_index++)
            {
                [retval addObject:[stack objectAtIndex:stack_index]];
            }
            [stack removeAllObjects];
            [retval addObject:current];
        }
        else
        {
            [stack insertObject:current atIndex:0];
        }
    }
    for(int stack_index=0;stack_index<[stack count];stack_index++)
    {
        [retval addObject:[stack objectAtIndex:stack_index]];
    }
    return retval;
}


int main(int argc, char **argv)
{
    NSArray *input = [[NSArray alloc] initWithObjects:@1, @2, @8, @9, @12, @16, nil];
    NSArray *output = reverse(input);
    dumpArray(input);
    dumpArray(output);
}
