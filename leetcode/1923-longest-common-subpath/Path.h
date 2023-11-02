// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//
#ifndef Path_h
#define Path_h
#import <Foundation/Foundation.h>

@interface Path : NSObject {

}

-(bool)containsSubpath:(Path *)candidate;
-(NSMutableArray *)getAllPossibleSubpaths;
-(id)initWithCityList:(NSArray *)cities;
-(int)cityAtStep:(int)step;
-(int)length;
-(void)dumpPath;

@property (nonatomic, retain) NSMutableArray *path;

@end

#endif
