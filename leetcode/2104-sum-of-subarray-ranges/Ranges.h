// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//
#ifndef Ranges_h
#define Ranges_h
#import <Foundation/Foundation.h>


typedef struct _SubarrayRange {
    int start;
    int end;
} SubarrayRange;


@interface Ranges : NSObject
{
}

@property (nonatomic, retain) NSMutableDictionary *rangesCounted;

-(bool)rangeAlreadyCounted:(int)start_index endIndex:(int)end_index;

-(int)sumSubarrays:(int [])data
        startIndex:(int)start_index
          endIndex:(int)end_index;

@end


#endif
