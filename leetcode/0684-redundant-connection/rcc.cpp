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

bool pathExists(std::unordered_map<int,std::vector<int>> &graph,
                std::vector<int> candidate)
{
    std::unordered_set<int> seen;
    std::queue<int> bfs_queue;
    bfs_queue.push(candidate[0]);
    while( ! bfs_queue.empty())
    {
        int current = bfs_queue.front();
        bfs_queue.pop();
        auto miter = graph.find( current );
        if( miter == graph.end() )
            return false;
        for(auto neighbour : miter->second )
        {
            if( candidate[1] == neighbour )
                return true;
            if( seen.count(neighbour) == 0 )
            {
                bfs_queue.push( neighbour );
                seen.insert( neighbour );
            }
        }
    }
    return false;
}


std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges)
{
    std::vector<int> retval;
    std::unordered_map<int,std::vector<int>> graph;
    for(auto current : edges )
    {
        bool is_redundant = pathExists(graph,current);
        if( is_redundant == true )
            return current;
        graph[current[0]].push_back(current[1]);
        graph[current[1]].push_back(current[0]);
    }
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> edges = {{1,2},{1,3},{2,3}};
        std::vector<int> expected  = {2,3};
        std::vector<int> result = findRedundantConnection(edges);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
        std::vector<int> expected  = {1,4};
        std::vector<int> result = findRedundantConnection(edges);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
