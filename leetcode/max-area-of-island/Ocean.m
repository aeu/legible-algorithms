// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//

#import "Ocean.h"


@implementation Ocean

-(int)currentIslandId
{
    return current_island_id;
}

-(int)createIsland
{
    current_island_id++;
    return [self currentIslandId];
}

-(OceanNode)nodeForLocation:(OceanLocation)targetLocation
{
    OceanNode retval;
    retval.type         = UNDEFINED;
    retval.parentIsland = 0;
    
    if( targetLocation.row < 0 )
        return retval;

    if( targetLocation.row >= [ _grid count] )
        return retval;

    if( targetLocation.column < 0 )
        return retval;
    
    NSMutableArray *columns = [_grid objectAtIndex: targetLocation.row ];

    if( targetLocation.column >= [columns count] )
        return retval;

    NSValue *node_value = [columns objectAtIndex:targetLocation.column];
    [node_value getValue:&retval];

    return retval;
}


-(void)updateLocation:(OceanLocation)targetLocation
             withNode:(OceanNode)newNode
{
    NSValue *node_value = [NSValue valueWithBytes:&newNode objCType:@encode(OceanNode)];
    NSMutableArray *columns = [_grid objectAtIndex: targetLocation.row ];
    [columns replaceObjectAtIndex:targetLocation.column withObject:node_value];
}

-(OceanLocation)getNorth:(OceanLocation)currentLocation
{
    OceanLocation destination;
    destination.row     = currentLocation.row - 1;
    destination.column  = currentLocation.column;
    return destination;
}

-(OceanLocation)getSouth:(OceanLocation)currentLocation
{
    OceanLocation destination;
    destination.row     = currentLocation.row + 1;
    destination.column  = currentLocation.column;
    return destination;
}

-(OceanLocation)getEast:(OceanLocation)currentLocation
{
    OceanLocation destination;
    destination.row     = currentLocation.row;
    destination.column  = currentLocation.column + 1;
    return destination;
}

-(OceanLocation)getWest:(OceanLocation)currentLocation
{
    OceanLocation destination;
    destination.row     = currentLocation.row;
    destination.column  = currentLocation.column - 1;
    return destination;
}


-(int)surveyNode:(OceanLocation)node_location
        islandId:(int)islandId
{
    int retval = 0;
    OceanNode current_node = [self nodeForLocation:node_location];
    if( current_node.type == LAND )
    {
        if( current_node.parentIsland == 0 )
        {
            current_node.parentIsland = islandId;
            [self updateLocation:node_location withNode:current_node];
            retval++;

            // check the surrounding nodes
            OceanLocation north = [self getNorth:node_location];
            retval += [self surveyNode:north islandId:islandId];

            OceanLocation south = [self getSouth:node_location];
            retval += [self surveyNode:south islandId:islandId];
            
            OceanLocation east = [self getEast:node_location];
            retval += [self surveyNode:east islandId:islandId];
            
            OceanLocation west = [self getWest:node_location];
            retval += [self surveyNode:west islandId:islandId];
        }
    }
    return retval;
}

-(void)processNodes
{
    int biggest = 0;
    int size = 0;
    for(int row_index = 0; row_index < [ _grid count]; row_index++ )
    {
        NSMutableArray *current_row = [_grid objectAtIndex:row_index];
        for( int col_index = 0; col_index < [current_row count]; col_index++)
        {
            OceanNode current_node;
            NSValue *node_value = [current_row objectAtIndex:col_index];
            [node_value getValue:&current_node];
            if( current_node.type == LAND )
            {
                OceanLocation node_location;
                node_location.row    = row_index;
                node_location.column = col_index;
                int island_id = [self createIsland];
                size = [self surveyNode:node_location islandId:island_id];

                if( size > biggest )
                    biggest = size;
            }
        }
    }
    printf("The biggest island was %d nodes\n", biggest);
}




-(Ocean *)initWithValues:(int *)values numRows:(int)numRows numColumns:(int)numColumns
{
    if( self = [super init] )
    {
        current_island_id = 1000;
        NSMutableArray *rows = [[NSMutableArray alloc] init];
        for( int row_index = 0; row_index < numRows; row_index++ )
        {
            NSMutableArray *current_row = [[NSMutableArray alloc] init];
            for( int col_index = 0; col_index < numColumns; col_index++ )
            {
                int current_index = ( row_index * numColumns ) + col_index;
                OceanNode current_node;
                if( values[ current_index ] == 1 )
                    current_node.type = LAND;
                else
                    current_node.type = WATER;
                current_node.parentIsland = 0;
                //
                // we can't put a c struct into a obj-c container class, so make a NSValue
                //
                NSValue *node_value = [NSValue valueWithBytes:&current_node objCType:@encode(OceanNode)];
                [current_row addObject:node_value];
            }
            [rows addObject:current_row];
        }
        [self setGrid:rows];
    }
    return self;
}

-(void)dumpGrid
{
    for(int row_index = 0; row_index < [ _grid count]; row_index++ )
    {
        NSMutableArray *current_row = [_grid objectAtIndex:row_index];
        for( int col_index = 0; col_index < [current_row count]; col_index++)
        {
            OceanNode current_node;
            NSValue *node_value = [current_row objectAtIndex:col_index];
            [node_value getValue:&current_node];
            printf("%d ", current_node.type );
        }
        printf("\n");
    }
}

@end
