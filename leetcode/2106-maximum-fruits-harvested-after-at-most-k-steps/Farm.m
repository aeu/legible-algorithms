// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//

#import "Farm.h"


@implementation Farm

-(id)init
{
    if( self = [super init] )
    {
        _crops = [[NSMutableDictionary alloc] init];
        _picks = [[NSMutableDictionary alloc] init];
        best_harvest_yield = 0;
    }
    return self;
}

-(void)addCrop:(NSArray *)crop
{
    if([crop count] != 2 )
        return;
    
    int location = [[crop objectAtIndex:0] intValue];
    int count    = [[crop objectAtIndex:1] intValue];

    NSNumber *keyval = [NSNumber numberWithInt: location];
    [_crops setObject:[NSNumber numberWithInt:count] forKey:keyval];
}

-(int)getStepFromPath:(int)path withStepCount:(int)step_count
{
    if( path & ( 1 << step_count ) )
        return 1;
    return -1 ;
}


-(void)replant
{
    [_picks removeAllObjects];
}


-(int)harvestForPosition:(int)position
{
    int harvest = 0;
    NSNumber *keyval = [NSNumber numberWithInt:position];
    if( [_picks objectForKey:keyval] == nil )
    {
        NSNumber *crop_count = [_crops objectForKey:keyval];
        if( crop_count != nil )
            harvest = [crop_count intValue];
        [_picks setObject:@1 forKey:keyval];
    }
    return harvest;
}    


-(void)harvestStartingAtPosition:(int)position withStepCount:(int)num_steps
{
    // from any position we can go either left or right, so we are
    // going to use some bitmasking to encode this logic, because
    // left/right fits perfectly in 1/0 bindary.  For n steps there's
    // going to be 2^n possible combinations.
    
    int path_upper_bound = pow(2,num_steps);
    for(int current_path = 0; current_path < path_upper_bound; current_path++)
    {
        [self replant];
        int current_position = position;
        int current_yield    = 0;
        for(int step_count = 0; step_count < num_steps; step_count++ )
        {
            int next_step    = [self getStepFromPath:current_path withStepCount:step_count];
            current_position += next_step;
            current_yield    += [self harvestForPosition: current_position ];
        }
        if( current_yield > best_harvest_yield )
        {
            best_harvest_yield = current_yield;
            best_harvest_path  = current_path;
        }
    }
    printf("Best harvest %d\n", best_harvest_yield );
}

@end
