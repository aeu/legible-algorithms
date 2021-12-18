// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//

#import <Foundation/Foundation.h>
#import <stdio.h>
#import "Ocean.h"

int main(int argc, char **argv)
{
    Ocean *deep_blue_sea = [[Ocean alloc] init];
    int grid[] = {0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,1,0,0,0,1,0,0,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0};

    [deep_blue_sea initWithValues:grid
                          numRows:8
                       numColumns:13];
    [deep_blue_sea dumpGrid];
    [deep_blue_sea processNodes];
}
