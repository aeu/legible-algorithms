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


void dumpValues(std::vector<int> values)
{
    for(auto curr : values )
    {
        std::cout << curr << ", " ;
    }
    std::cout << std::endl;
}


bool dfs(int current_node,
         std::vector<std::vector<int>>& graph,
         std::vector<int> &path,
         std::vector<std::vector<int>> &retval)
{
    if( current_node == graph.size() - 1 )
    {
        retval.push_back( std::vector<int>( path ));
        return true;
    }
    for(auto neighbour : graph[current_node] )
    {
        path.push_back( neighbour );
        dfs(neighbour,graph,path,retval);
        path.pop_back();
    }
    return true;
}

std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph)
{
    std::vector<std::vector<int>> retval;
    std::vector<int> path;
    path.push_back(0);
    dfs(0, graph, path, retval);
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC797 - All Paths from Source to Target" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> graph = {{1,2},{3},{3},{}};
        std::vector<std::vector<int>> expected = {{0,1,3},{0,2,3}};
        std::vector<std::vector<int>> result = allPathsSourceTarget(graph);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};
        std::vector<std::vector<int>> expected = {{0,4},{0,3,4},{0,1,3,4},{0,1,2,3,4},{0,1,4}};
        std::vector<std::vector<int>> result = allPathsSourceTarget(graph);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
