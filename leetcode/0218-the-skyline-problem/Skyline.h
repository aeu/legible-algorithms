// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//
#ifndef Skyline_h
#define Skyline_h
#import <Foundation/Foundation.h>


@interface Skyline : NSObject {
    int lowest_x;
    int highest_x;
}

@property (nonatomic, retain) NSMutableDictionary *grid;

-(void)addBuilding:(NSArray *)building;
-(void)dumpSkyline;

@end


#endif
