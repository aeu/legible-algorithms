// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//

#ifndef Graph_h
#define Graph_h
#import <Foundation/Foundation.h>
#import "Vertex.h"


@interface Graph : NSObject
{
    NSMutableDictionary *_vertexes;
}
@property (nonatomic, retain) NSMutableDictionary *vertexes;

-(Graph *)init;
-(void)addConnectionFrom:(NSString *)from to:(NSString *)to;
-(Vertex *)getVertex:(NSString *)vertex_name;
-(void)unvisit;


@end



#endif
