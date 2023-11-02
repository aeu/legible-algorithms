// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#import <Foundation/Foundation.h>


@interface Merger : NSObject


-(NSMutableArray *)mergeLists:(NSMutableArray *)lists
                 startAtIndex:(int)index;

-(NSMutableArray *)mergeList:(NSMutableArray *)left
                    withList:(NSMutableArray *)right;

-(NSMutableArray *)mergeKLists:(NSMutableArray *)lists;

@end

