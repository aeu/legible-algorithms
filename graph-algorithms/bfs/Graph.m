// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//
#import <Foundation/Foundation.h>
#import "Graph.h"


@implementation Graph

@synthesize vertexes=_vertexes;

-(Graph *)init
{
    if( self == [super init] )
    {
        [self setVertexes:[[NSMutableDictionary alloc] init]];
    }
    return self;
}

-(void)unvisit
{
    NSEnumerator *enumerator = [[self vertexes] objectEnumerator];
    id value;
    
    while ((value = [enumerator nextObject]))
    {
        Vertex *current_vertex = (Vertex *)value;
        [current_vertex unvisit];
    }
}


-(Vertex *)getVertex:(NSString *)vertex_name
{
    Vertex *new_vertex;
    new_vertex = (Vertex *)[[self vertexes] objectForKey:vertex_name];
    if( new_vertex != nil )
    {
        NSLog(@"vertex %@ did exist, returning", vertex_name );
        return new_vertex;
    }

    NSLog(@"vertex %@ did not exist, creating", vertex_name );
    new_vertex = [[Vertex alloc] initWithName:vertex_name];
    [[self vertexes] setObject:new_vertex forKey:vertex_name];
    return new_vertex;
}

-(void)addConnectionFrom:(NSString *)from to:(NSString *)to
{
    Vertex *from_vertex = [self getVertex:from];
    Vertex *to_vertex   = [self getVertex:to];

    [from_vertex addConnection:to_vertex];
    [to_vertex addConnection:from_vertex];
}


-(void)findPathFrom:(NSString *)from to:(NSString *)to
{
    Vertex *from_vertex = [self getVertex:from];
    NSMutableArray *vertex_queue = [[NSMutableArray alloc] init];
    [vertex_queue insertObject:from_vertex atIndex:0];
}

@end
