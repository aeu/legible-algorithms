// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//
#import "Path.h"

@implementation Path

-(int)cityAtStep:(int)step
{
    int retval = -1;
    if( step < [self length] )
    {
        retval = [(NSNumber *)[_path objectAtIndex:step] integerValue];
    }
    return retval;
}


-(bool)containsSubpath:(Path *)candidate
{
    int mylength = [self length];
    int candidate_length = [candidate length];
    int possible_fits = mylength - candidate_length + 1;
    for(int start_point = 0; start_point < possible_fits; start_point++)
    {
        bool all_matched = true;
        for(int candidate_index = 0; candidate_index < candidate_length; candidate_index++ )
        {
            int parent_index = start_point + candidate_index;
            if( [candidate cityAtStep:candidate_index] != [self cityAtStep:parent_index] )
            {
                all_matched = false;
                break;
            }
        }
        if( all_matched )
        {
            return true;
        }
    }
    return false;
}


-(NSMutableArray *)getAllPossibleSubpaths
{
    NSMutableArray *retval = [[NSMutableArray alloc] init];
    NSRange path_range;
    for(int lengths = [_path count]; lengths > 0; lengths-- )
    {
        path_range.length = lengths;
        int last_possible_start = [_path count] - lengths;
        for(int start_point = 0; start_point <= last_possible_start; start_point++)
        {
            path_range.location = start_point;
            NSArray *subpath_city_list = [_path subarrayWithRange:path_range];
            Path *subpath = [[Path alloc] initWithCityList:subpath_city_list];
            [retval addObject:subpath];
        }
    }
    return retval;
}


-(void)dumpPath
{
    int first_time = 1;
    for(int index=0;index<[_path count];index++)
    {
        if( first_time )
        {
            first_time = 0;
        }
        else
        {
            printf(", ");
        }
        NSNumber *current = [_path objectAtIndex:index];
        printf("%d", [ current intValue]);
    }
    printf("\n");
}

-(id)initWithCityList:(NSArray *)cities
{
    if( self = [super init] )
    {
        _path = [[NSMutableArray alloc] initWithArray:cities];
    }
    return self;
}

-(int)length
{
    return [_path count];
}


-(id)init
{
    if( self = [super init] )
    {
    }
    return self;
}


@end
