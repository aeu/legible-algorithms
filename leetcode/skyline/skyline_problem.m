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
#import "Skyline.h"

int main(int argc, char **argv)
{
    printf("Skyline Problem:\n");
    NSMutableArray *building_1 = [[NSMutableArray alloc] initWithObjects:@2,  @9,  @10, nil ];
    NSMutableArray *building_2 = [[NSMutableArray alloc] initWithObjects:@3,  @7,  @15, nil ];
    NSMutableArray *building_3 = [[NSMutableArray alloc] initWithObjects:@5,  @12, @12, nil ];
    NSMutableArray *building_4 = [[NSMutableArray alloc] initWithObjects:@15, @20, @10, nil ];
    NSMutableArray *building_5 = [[NSMutableArray alloc] initWithObjects:@19, @24, @8, nil ];


    Skyline *skyline = [[Skyline alloc] init];
    [skyline addBuilding: building_1 ];
    [skyline addBuilding: building_2 ];
    [skyline addBuilding: building_3 ];
    [skyline addBuilding: building_4 ];
    [skyline addBuilding: building_5 ];
    [skyline dumpSkyline];
    
    
    skyline = [[Skyline alloc] init];
    building_1 = [[NSMutableArray alloc] initWithObjects:@0,  @2,  @3, nil ];
    building_2 = [[NSMutableArray alloc] initWithObjects:@2,  @5,  @3, nil ];
    [skyline addBuilding: building_1 ];
    [skyline addBuilding: building_2 ];
    [skyline dumpSkyline];
}


