// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//

#import "Ranges.h"


@implementation Ranges

@synthesize rangesCounted;

-(bool)rangeAlreadyCounted:(int)start_index
                  endIndex:(int)end_index
{
    SubarrayRange temp;
    temp.start = start_index;
    temp.end   = end_index;
    NSValue *candidate = [NSValue valueWithBytes:&temp objCType:@encode(SubarrayRange)];
    if( [[ self rangesCounted] objectForKey: candidate] != nil )
    {
        return true;
    }
    [[self rangesCounted] setObject:@1 forKey:candidate];
    return false;
}

-(id)init
{
    if( self = [super init] )
    {
        NSMutableDictionary *new_dictionary = [[NSMutableDictionary alloc] init];
        [self setRangesCounted:new_dictionary];
    }
    return self;
}

-(int)sumSubarrays:(int [])data
        startIndex:(int)start_index
          endIndex:(int)end_index
{
    int retval = 0;

    if( ! [self rangeAlreadyCounted:start_index endIndex:end_index] )
    {
        int biggest  = data[start_index];
        int smallest = data[start_index];
        for(int loop_index = start_index; loop_index <= end_index; loop_index++)
        {
            if( data[loop_index] > biggest )
                biggest = data[loop_index];
            
            if( data[loop_index] < smallest )
                smallest = data[loop_index];
        }
        retval += biggest - smallest;
    }
    
    int new_start = start_index+1;
    if( new_start < end_index )
    {
        retval += [self sumSubarrays:data startIndex:new_start endIndex:end_index];
    }

    int new_end = end_index-1;
    if( new_end > start_index )
    {
        retval += [self sumSubarrays:data startIndex:start_index endIndex:new_end];
    }
    
    return retval;
}

@end
