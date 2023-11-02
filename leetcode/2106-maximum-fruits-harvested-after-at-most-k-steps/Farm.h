// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//
#ifndef Farm_h
#define Farm_h
#import <Foundation/Foundation.h>


@interface Farm : NSObject {
    int best_harvest_yield;
    int best_harvest_path;
}

@property (nonatomic, retain) NSMutableDictionary *crops;
@property (nonatomic, retain) NSMutableDictionary *picks;

-(void)addCrop:(NSArray *)crop;
-(void)harvestStartingAtPosition:(int)position withStepCount:(int)num_steps;

@end


#endif
