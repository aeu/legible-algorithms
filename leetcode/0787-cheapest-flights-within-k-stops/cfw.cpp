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


int dfs(int src,int dst, int k,
        std::unordered_map<int,std::pair<int,int>> &graph)
{
    return -1;
}
        


int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k)
{
    std::unordered_map<int,std::pair<int,int>> graph;
    for( auto curr : flights )
    {
        graph[curr[0]] = { curr[1], curr[2] };
    }
    int cheapest = INT_MAX;
    int cost = dfs( src, dst, k, graph );
    cheapest = std::min(cheapest,cost);
    return cheapest;
}        

int main(int argc, char **argv)
{
    std::cout << std::endl << "787. Cheapest Flights Within K Stops" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 4;
        int src = 0;
        int dst = 3;
        int k = 1;
        int expected = 700;
        std::vector<std::vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
        int result = findCheapestPrice(n, flights, src, dst, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int n = 3;
        int src = 0;
        int dst = 2;
        int k = 1;
        int expected = 200;
        std::vector<std::vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
        int result = findCheapestPrice(n, flights, src, dst, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int n = 3;
        int src = 0;
        int dst = 2;
        int k = 0;
        int expected = 500;
        std::vector<std::vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
        int result = findCheapestPrice(n, flights, src, dst, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
