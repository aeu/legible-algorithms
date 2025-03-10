// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>

int minReorder(int n, std::vector<std::vector<int>> &connections)
{
    std::unordered_map<int,std::vector<std::pair<int,int>>> graph;
    std::unordered_set<int> visited;
    std::queue<int> traversal_queue;
    int needed_to_be_reversed = 0;
    for(auto current : connections )
    {
        int start = current[0];
        int end   = current[1];
        graph[start].push_back( {end,1} );
        graph[end].push_back({start,0});
    }

    traversal_queue.push(0);
    visited.insert(0);
    while( ! traversal_queue.empty())
    {
        int current_city = traversal_queue.front();
        traversal_queue.pop();
        auto graph_iter = graph.find( current_city );
        if( graph_iter != graph.end() )
        {
            for( auto current_edge : graph_iter->second )
            {
                int destination = current_edge.first;
                int direction   = current_edge.second;
                if( visited.count(destination) == 0 )
                {
                    visited.insert(destination);
                    traversal_queue.push( destination );
                    if( direction == 1 )
                        needed_to_be_reversed++;
                }
            }
        }
    }
    return needed_to_be_reversed;
}


int main(int argc, char **argv)
{
    int test_case = 1;
    {
        int N = 6;
        std::vector<std::vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
        int expected = 3;
        int result = minReorder(N, connections);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int N = 5;
        std::vector<std::vector<int>> connections = {{1,0},{1,2},{3,2},{3,4}};
        int expected = 2;
        int result = minReorder(N, connections);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int N = 3;
        std::vector<std::vector<int>> connections = {{1,0},{2,0}};
        int expected = 0;
        int result = minReorder(N, connections);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
}
