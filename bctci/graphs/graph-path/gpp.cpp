// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

struct bfs_node {
    int node;
    std::vector<int> path;
};

void dumpValues(std::vector<int> vals)
{
    for(auto cur : vals )
    {
        std::cout << cur << ", " ;
    }
    std::cout << std::endl;
}

std::vector<int> doWork(std::vector<std::vector<int>> adjacency_list, int node1, int node2)
{
    std::vector<int> retval;
    std::unordered_map<int,std::vector<int>> graph;
    std::unordered_set<int> seen;
    std::queue<bfs_node> bfs_queue;
    for(int index=0;index<adjacency_list.size();index++)
    {
        for(auto current : adjacency_list[index] )
        {
            graph[index].push_back( current );
        }
    }
    bfs_queue.push({node1,{node1}});
    seen.insert(node1);
    while( ! bfs_queue.empty() )
    {
        bfs_node current = bfs_queue.front();
        bfs_queue.pop();
        if( current.node == node2 )
        {
            return current.path;
        }
        auto git = graph.find( current.node );
        if( git != graph.end() )
        {
            for(int index=0;index<git->second.size();index++)
            {
                int neighbour = git->second[index];
                if( seen.count( neighbour ) == 0 )
                {
                    std::vector<int> newpath = current.path;
                    newpath.push_back(neighbour );
                    seen.insert( neighbour );
                    bfs_queue.push({ neighbour, newpath });
                }
            }
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "36.2 - Graph Path" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> adjacency_list =
            { { 1 } ,
              { 0, 2, 5, 4 },
              { 1, 4, 5 },
              { },
              { 5, 2, 1 },
              { 1, 2, 4 }};
        int node1 = 0;
        int node2 = 4;
        std::vector<int> expected = {0,1,4};
        std::vector result = doWork(adjacency_list,node1,node2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::vector<int>> adjacency_list =
            { { 1 } ,
              { 0, 2, 5, 4 },
              { 1, 4, 5 },
              { },
              { 5, 2, 1 },
              { 1, 2, 4 }};
        int node1 = 0;
        int node2 = 3;
        std::vector<int> expected = {};
        std::vector result = doWork(adjacency_list,node1,node2);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
