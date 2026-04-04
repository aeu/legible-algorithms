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


void dumpValues(std::vector<int> vals )
{
    for(auto current : vals )
    {
        std::cout << current << ", " << std::endl;
    }
    std::cout << std::endl;
}

enum Status {
    UNVISITED,
    PROCESSING,
    KNOWN_SAFE,
    KNOWN_UNSAFE
};

bool dfs(int current_node,
         std::vector<std::vector<int>>& graph,
         std::vector<int> &graph_state)
{
    if( graph_state[current_node] == Status::PROCESSING )
        return false;
    
    if( graph_state[current_node] == Status::KNOWN_UNSAFE )
        return false;

    if( graph_state[current_node] == Status::KNOWN_SAFE )
        return true;

    graph_state[current_node] = Status::PROCESSING;

    for(const auto neighbouring_node : graph[current_node] )
    {
        auto neighbour_was_safe = dfs( neighbouring_node, graph, graph_state );
        if( neighbour_was_safe == false )
        {
            graph_state[neighbouring_node] = Status::KNOWN_UNSAFE;
            return false;
        }
    }
    graph_state[current_node] = Status::KNOWN_SAFE;
    return true;

}

std::vector<int> eventualSafeNodes(std::vector<std::vector<int>>& graph)
{
    int num_nodes = graph.size();
    std::vector<int> safe_nodes;
    std::vector<int> graph_state(num_nodes, Status::UNVISITED);

    for(int current_node = 0; current_node<num_nodes;current_node++)
    {
        dfs(current_node,graph,graph_state);
    }
    for(int index=0;index<num_nodes;index++)
    {
        if( graph_state[index] == Status::KNOWN_SAFE )
            safe_nodes.push_back(index);
    }
    return safe_nodes;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC802 - Find Eventual Safe States" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> graph =
            {{2,3,6,8,13},{7},{7},{12},{9,19},{},{7,12,13,15,17},{5,12,19},{12,13,16,17},{11,14,15,16,17,19},{10,11,16,18},{},{},{15,16},{1,15,16,17,18,19},{16,17,18,19},{17,18,19},{18},{19},{}}    ;
        std::vector<int> expected = {0,1,2,3,4,5,6,7,8,9,11,12,13,14,15,16,17,18,19};
        std::vector<int> result   = eventualSafeNodes(graph);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> graph =
            {{1,2},{2,3},{5},{0},{5},{},{}};
        std::vector<int> expected = {2,4,5,6};
        std::vector<int> result   = eventualSafeNodes(graph);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> graph =
            {{1,2,3,4},{1,2},{3,4},{0,4},{}};
        std::vector<int> expected = {4};
        std::vector<int> result   = eventualSafeNodes(graph);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
