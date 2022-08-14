// -*- Mode: objc; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//  alfonso e. urdaneta
//  alfonso@red82.com
//

#include <stdio.h>
#import "Graph.h"


int main(int argc, char **argv)
{
    printf("BFS!\n");
    Graph *mygraph = [[Graph alloc] init];
    [mygraph addConnectionFrom:@"Orlando" to:@"Miami"];
    [mygraph addConnectionFrom:@"Orlando" to:@"Jacksonville"];
    [mygraph addConnectionFrom:@"Orlando" to:@"Tampa"];
    [mygraph addConnectionFrom:@"Miami" to:@"Key West"];
}
