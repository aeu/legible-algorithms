// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//

#import "Skyline.h"


@implementation Skyline

-(id)init
{
    if( self = [super init] )
    {
        _grid = [[NSMutableDictionary alloc] init];
        lowest_x = INT_MAX;
        highest_x = INT_MIN;
    }
    return self;
}


-(void)addBuilding:(NSArray *)building
{
    if([building count] < 3 )
        return;
    int start_x = [[building objectAtIndex:0] intValue];
    int end_x   = [[building objectAtIndex:1] intValue];
    int height  = [[building objectAtIndex:2] intValue];


    if( start_x < lowest_x )
        lowest_x = start_x;

    if( end_x > highest_x )
        highest_x = end_x;
    
    for( int loop_index = start_x; loop_index<=end_x; loop_index++)
    {
        NSNumber *keyval = [NSNumber numberWithInt: loop_index];
        if( [_grid objectForKey:keyval] == nil )
        {
            [_grid setObject:[NSNumber numberWithInt:height] forKey:keyval];
        }
        else
        {
            int existing_height = [[_grid objectForKey:keyval] integerValue];
            if( height > existing_height )
                [_grid setObject:[NSNumber numberWithInt:height] forKey:keyval];
        }
    }
}


-(void)dumpSkyline
{
    int previous_height = 0;
    bool first_time = true;
    
    printf("[");
    // we go to +1 since this isn't an array, it's a collection of keys
    for(int loop_index = lowest_x; loop_index <= highest_x + 1 ; loop_index++ )
    {
        int height = 0;
        NSNumber *keyval = [NSNumber numberWithInt: loop_index];
        if( [_grid objectForKey:keyval] != nil )
        {
            height = [[_grid objectForKey:keyval] integerValue];
        }

        if( height == previous_height )
        {
            // skip
        }
        else if( height < previous_height )
        {
            if( ! first_time )
                printf(",");
            printf("[%d,%d]", loop_index-1, height );
            first_time = false;
        }
        else
        {
            if( ! first_time )
                printf(",");
            printf("[%d,%d]", loop_index, height );
            first_time = false;
        }
        previous_height = height;
    }
    
    printf("]\n");
}

@end
