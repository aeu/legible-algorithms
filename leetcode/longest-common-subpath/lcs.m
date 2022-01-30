// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//

#import <Foundation/Foundation.h>
#import "Path.h"
#import "PathFinder.h"


int main(int argc, char **argv)
{
    {
        Path *path_one   = [[Path alloc] initWithCityList:[NSArray arrayWithObjects:@0, @1, @2, @3, @4, nil]];
        Path *path_two   = [[Path alloc] initWithCityList:[NSArray arrayWithObjects:@2, @3, @4, nil]];
        Path *path_three = [[Path alloc] initWithCityList:[NSArray arrayWithObjects:@4, @0, @1, @2, @3, nil]];
        
        PathFinder *path_finder = [[PathFinder alloc] init];
        [path_finder addPath:path_one];
        [path_finder addPath:path_two];
        [path_finder addPath:path_three];
        printf("Output: %d\n", [path_finder solve]);
    }

    {
        Path *path_one   = [[Path alloc] initWithCityList:[NSArray arrayWithObjects:@0, nil]];
        Path *path_two   = [[Path alloc] initWithCityList:[NSArray arrayWithObjects:@1, nil]];
        Path *path_three = [[Path alloc] initWithCityList:[NSArray arrayWithObjects:@2, nil]];
        
        PathFinder *path_finder = [[PathFinder alloc] init];
        [path_finder addPath:path_one];
        [path_finder addPath:path_two];
        [path_finder addPath:path_three];
        printf("Output: %d\n", [path_finder solve]);
    }

    {
        Path *path_one   = [[Path alloc] initWithCityList:[NSArray arrayWithObjects:@0, @1, @2, @3, @4, nil]];
        Path *path_two   = [[Path alloc] initWithCityList:[NSArray arrayWithObjects:@4, @3, @2, @1, @0, nil]];
        
        PathFinder *path_finder = [[PathFinder alloc] init];
        [path_finder addPath:path_one];
        [path_finder addPath:path_two];
        printf("Output: %d\n", [path_finder solve]);
    }
}
