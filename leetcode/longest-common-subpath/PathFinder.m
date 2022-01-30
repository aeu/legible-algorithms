// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//
//
#import <limits.h>
#import "Path.h"
#import "PathFinder.h"

@implementation PathFinder


-(id)init
{
    if( self = [super init] )
    {
        _paths = [[NSMutableArray alloc] init];
    }
    return self;
}


-(Path *)getShortestPath
{
    int shortest_length  = INT_MAX;
    int shortest_index   = 0;
    Path *retval         = nil;
    Path *current;
    for(int path_index = 0; path_index < [_paths count]; path_index++)
    {
        current = [_paths objectAtIndex:path_index];
        if( [current length] < shortest_length )
        {
            shortest_length = [current length];
            retval = current;
        }
    }
    return retval;
}



-(void)addPath:(Path *)path
{
    [_paths addObject:path];
}


-(int)solve
{
    Path *shortest = [self getShortestPath];
    NSArray *all_possible_subpaths = [shortest getAllPossibleSubpaths];
    Path *current;


    for(int subpath_index = 0; subpath_index < [all_possible_subpaths count]; subpath_index++ )
    {
        bool found_in_every_path = true;
        Path *candidate_subpath = (Path *)[all_possible_subpaths objectAtIndex:subpath_index];
        //        printf("Candidate : ");
        // [candidate_subpath dumpPath];
        for(int path_index = 0; path_index < [_paths count]; path_index++)
        {
            current = (Path *)[_paths objectAtIndex:path_index];
            //            printf("Testing against: ");
            // [current dumpPath];
            if( current == shortest )
            {
                continue;
            }
            if( ! [current containsSubpath:candidate_subpath] )
            {
                found_in_every_path = false;
                break;
            }
        }
        if( found_in_every_path == true )
        {
            return [candidate_subpath length];
        }
    }
    return 0;
}
             

@end
