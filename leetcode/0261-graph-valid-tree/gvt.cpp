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
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>

bool validTree(int n, std::vector<std::vector<int>>& edges)
{
    if( ( n == 1 ) && ( edges.size() == 0 ))
        return true;
    if((n>0)&&(edges.size() != n-1 ))
        return false;
    std::map<int,std::vector<int>> adj_list;
    for( auto curr : edges )
    {
        int from = curr[0];
        int to   = curr[1];
        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }
    std::set<int> seen;
    std::queue<int> bfs;
    bfs.push(0);
    while( ! bfs.empty() )
    {
        int current_node = bfs.front();
        bfs.pop();
        if( adj_list.find(current_node) != adj_list.end() )
        {
            auto destinations = adj_list[current_node];
            for(auto dest_node : destinations )
            {
                if( seen.find(dest_node) == seen.end() )
                {
                    seen.insert(dest_node);
                    bfs.push(dest_node);
                }
            }
        }
    }
    if( seen.size() != n )
        return false;
    return true;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "/leetcode/0261-graph-valid-tree/" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 5;
        std::vector<std::vector<int>> edges = {{0,1},{0,2},{0,3},{1,4}};
        bool expected = true;
        bool result = validTree(n,edges);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int n = 5;
        std::vector<std::vector<int>> edges = {{0,1},{1,2},{2,3},{1,3},{1,4}};
        bool expected = false;
        bool result = validTree(n,edges);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int n = 1;
        std::vector<std::vector<int>> edges = {};
        bool expected = true;
        bool result = validTree(n,edges);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
