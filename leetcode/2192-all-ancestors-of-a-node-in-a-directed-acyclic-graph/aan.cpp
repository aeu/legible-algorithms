// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <iomanip>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

void dumpValues(std::vector<int> values)
{
    bool first = true;
    for(const auto &curr : values )
    {
        if( ! first )
            std::cout << ", ";
        first = false;
        std::cout << std::setw(3) << curr ;
    }
    std::cout << std::endl;
}


std::vector<std::vector<int>> getAncestors(int n, std::vector<std::vector<int>>& edges)
{
    std::vector<std::unordered_set<int>> storage( n, std::unordered_set<int>() );
    std::unordered_map<int,std::vector<int>> graph;
    for(const auto &curr_edge : edges )
    {
        int from = curr_edge[0];
        int to   = curr_edge[1];
        graph[to].push_back(from);
    }

    for(int node = 0;node<n;node++)
    {
        std::unordered_set<int> seen;
        std::queue<int> bfs_queue;
        bfs_queue.push(node);
        while( ! bfs_queue.empty() )
        {
            int current = bfs_queue.front();
            bfs_queue.pop();
            auto giter = graph.find( current );
            if( giter != graph.end() )
            {
                const auto &nodelist = giter->second;
                for( auto dest : nodelist )
                {
                    if( seen.count(dest) == 0 )
                    {
                        seen.insert(dest);
                        storage[node].insert(dest);
                        bfs_queue.push(dest);
                    }
                }
            }
        }
    }

    // convert from our temp storage stucture into the final return value

    std::vector<std::vector<int>> retval( n, std::vector<int>() );
    for(int index=0;index<n;index++)
    {
        std::vector<int> values = std::vector<int> ( storage[index].begin(), storage[index].end() );
        std::sort(values.begin(),values.end());
        retval[index] = values;
        
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "2192-all-ancestors-of-a-node-in-a-directed-acyclic-graph" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 8;
        std::vector<std::vector<int>> edges = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};
        std::vector<std::vector<int>> expected = {{},{},{},{0,1},{0,2},{0,1,3},{0,1,2,3,4,},{0,1,2,3}};
        std::vector<std::vector<int>> result = getAncestors(n,edges);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
