// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//

#import <Foundation/Foundation.h>
#import <stdio.h>
#import "Merger.h"

int main(int argc, char **argv)
{
  NSMutableArray *one   = [[NSMutableArray alloc] initWithObjects:@1, @4, @5, nil];
  NSMutableArray *two   = [[NSMutableArray alloc] initWithObjects:@1, @3, @4, nil];
  NSMutableArray *three = [[NSMutableArray alloc] initWithObjects:@2, @6, nil];
  NSMutableArray *four  = [[NSMutableArray alloc] initWithObjects:@2, @5, @8, nil];
  NSMutableArray *five  = [[NSMutableArray alloc] initWithObjects:@2, @5, @10, @12, nil];
  NSMutableArray *six   = [[NSMutableArray alloc] initWithObjects:@6, @7, @8, nil];
  NSMutableArray *seven = [[NSMutableArray alloc] initWithObjects:@1, @2, @45, nil];
  NSMutableArray *all   = [[NSMutableArray alloc] initWithObjects:one, two, three, four, five, six, seven, nil];

  Merger *merge = [[Merger alloc] init];
  [merge mergeKLists:all];
}
