// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#import <Foundation/Foundation.h>
#import <stdio.h>
#import "Farm.h"

int main(int argc, char **argv)
{
    printf("2106. Maximum Fruits Harvested After at Most K Steps\n");
    {
        NSMutableArray *crop_1 = [[NSMutableArray alloc] initWithObjects:@2,  @8,  nil ];
        NSMutableArray *crop_2 = [[NSMutableArray alloc] initWithObjects:@6,  @3,  nil ];
        NSMutableArray *crop_3 = [[NSMutableArray alloc] initWithObjects:@8,  @6, nil ];
        
        Farm *farm = [[Farm alloc] init];
        [farm addCrop: crop_1 ];
        [farm addCrop: crop_2 ];
        [farm addCrop: crop_3 ];
        
        [farm harvestStartingAtPosition:5 withStepCount:4];
    }
    {
        NSMutableArray *crop_1 = [[NSMutableArray alloc] initWithObjects:@0,  @9,  nil ];
        NSMutableArray *crop_2 = [[NSMutableArray alloc] initWithObjects:@4,  @1,  nil ];
        NSMutableArray *crop_3 = [[NSMutableArray alloc] initWithObjects:@5,  @7, nil ];
        NSMutableArray *crop_4 = [[NSMutableArray alloc] initWithObjects:@6,  @2, nil ];
        NSMutableArray *crop_5 = [[NSMutableArray alloc] initWithObjects:@7,  @4, nil ];
        NSMutableArray *crop_6 = [[NSMutableArray alloc] initWithObjects:@10,  @9, nil ];
        
        Farm *farm = [[Farm alloc] init];
        [farm addCrop: crop_1 ];
        [farm addCrop: crop_2 ];
        [farm addCrop: crop_3 ];
        [farm addCrop: crop_4 ];
        [farm addCrop: crop_5 ];
        [farm addCrop: crop_6 ];
        
        [farm harvestStartingAtPosition:5 withStepCount:4];
    }
    {
        NSMutableArray *crop_1 = [[NSMutableArray alloc] initWithObjects:@0,  @3,  nil ];
        NSMutableArray *crop_2 = [[NSMutableArray alloc] initWithObjects:@6,  @4,  nil ];
        NSMutableArray *crop_3 = [[NSMutableArray alloc] initWithObjects:@8,  @5, nil ];
        
        Farm *farm = [[Farm alloc] init];
        [farm addCrop: crop_1 ];
        [farm addCrop: crop_2 ];
        [farm addCrop: crop_3 ];
        
        [farm harvestStartingAtPosition:3 withStepCount:2];
    }
}


