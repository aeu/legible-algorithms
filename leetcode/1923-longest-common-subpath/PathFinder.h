// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//
#ifndef PathFinder_h
#define PathFinder_h
#import <Foundation/Foundation.h>

@interface PathFinder : NSObject {


}

-(void)addPath:(Path *)path;
-(int)solve;
-(Path *)getShortestPath;

@property (nonatomic, retain) NSMutableArray *paths;

@end

#endif
