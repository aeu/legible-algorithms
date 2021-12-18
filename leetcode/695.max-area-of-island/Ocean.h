// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//
#ifndef Ocean_h
#define Ocean_h
#import <Foundation/Foundation.h>


typedef struct _OceanLocation {
    int row;
    int column;
} OceanLocation;

typedef struct _OceanNode {
    int land;
    int parentIsland;
} OceanNode;


@interface Ocean : NSObject {
    int current_island_id;
}

@property (nonatomic, retain) NSMutableArray *grid;


-(Ocean *)initWithValues:(int *)values numRows:(int)numRows numColumns:(int)numColumns;
-(void)dumpGrid;
-(void)processNodes;

-(void)updateLocation:(OceanLocation)targetLocation withNode:(OceanNode)newNode;
-(OceanNode)nodeForLocation:(OceanLocation)targetLocation;
-(OceanLocation)getNorth:(OceanLocation)currentLocation;
-(OceanLocation)getSouth:(OceanLocation)currentLocation;
-(OceanLocation)getEast:(OceanLocation)currentLocation;
-(OceanLocation)getWest:(OceanLocation)currentLocation;

-(int)currentIslandId;
-(int)createIsland;

@end


#endif
