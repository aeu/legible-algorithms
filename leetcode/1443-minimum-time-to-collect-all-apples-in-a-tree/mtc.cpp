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

int dfs(int node,
        int parent,
        std::unordered_map<int,std::vector<int>> &graph,
        std::vector<bool> &hasApple)
{
    int total_time = 0;

    for(int neighbour : graph[node] )
    {
        if( neighbour == parent )
            continue;

        int child_time = dfs(neighbour,node,graph,hasApple);
        if( ( child_time > 0 ) || hasApple[ neighbour ] )
        {
            total_time += child_time + 2;
        }
    }
    return total_time;
}

int minTime(int n, std::vector<std::vector<int>>& edges, std::vector<bool>& hasApple)
{
    std::unordered_map<int,std::vector<int>> graph;
    for( const auto &edge : edges )
    {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    int time = dfs(0,-1,graph,hasApple);
    return time;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "1443-minimum-time-to-collect-all-apples-in-a-tree" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
        std::vector<bool> hasApple = {false,false,true,false,true,true,false};
        int n = 7;
        int expected = 8;
        int result = minTime(n,edges,hasApple);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
        std::vector<bool> hasApple = {false,false,true,false,false,true,false};
        int n = 7;
        int expected = 6;
        int result = minTime(n,edges,hasApple);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::vector<int>> edges = {{0,1},{0,2},{1,4},{1,5},{2,3},{2,6}};
        std::vector<bool> hasApple = {false,false,false,false,false,false,false};
        int expected = 0;
        int n = 7;
        int result = minTime(n,edges,hasApple);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
