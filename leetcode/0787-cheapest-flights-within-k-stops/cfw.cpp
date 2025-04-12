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


void dumpPath(std::vector<int> &path)
{
    for( auto curr : path )
    {
        std::cout << curr << " -> " ;
    }
    std::cout << std::endl;
}

int dfs(int dst, int k, int cost,
        std::vector<int> &path,
        std::unordered_set<int> &seen,
        std::unordered_map<int,std::vector<std::pair<int,int>>> &graph)
{
    int last_city = path.back();
    if( last_city == dst )
    {
        return cost;
    }
    if( path.size() > k + 1 )
        return INT_MAX;

    if( path.size() == 0 )
        return INT_MAX;
    
    auto it = graph.find( last_city );
    int lowest_cost = INT_MAX;
    if( it != graph.end() )
    {
        for(auto curr : it->second )
        {
            int destination_city = curr.first;
            if( seen.count( destination_city  ) == 0 )
            {
                seen.insert(destination_city);
                path.push_back( destination_city );
                int flight_cost = dfs( dst, k, cost + curr.second, path,seen, graph );
                lowest_cost = std::min(flight_cost, lowest_cost);
                path.pop_back();
                seen.erase(destination_city);
            }
        }
    }
    return lowest_cost;
}
        
int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k)
{
    std::unordered_map<int,std::vector<std::pair<int,int>>> graph;
    for( auto curr : flights )
    {
        graph[curr[0]].push_back({ curr[1], curr[2] });
    }
    int cheapest = INT_MAX;
    std::unordered_set<int> seen;
    std::vector<int> path;
    path.push_back(src);
    int cost = dfs( dst, k, 0, path, seen, graph );
    cheapest = std::min(cheapest,cost);
    if( cheapest == INT_MAX )
        return -1;
    return cheapest;
}        

int main(int argc, char **argv)
{
    std::cout << std::endl << "787. Cheapest Flights Within K Stops" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 10;
        int src = 6;
        int dst = 0;
        int k = 7;
        int expected = 14;
        std::vector<std::vector<int>> flights =
            {{3,4,4},{2,5,6},{4,7,10},{9,6,5},{7,4,4},{6,2,10},{6,8,6},
             {7,9,4},{1,5,4},{1,0,4},{9,7,3},{7,0,5},{6,5,8},{1,7,6},
             {4,0,9},{5,9,1},{8,7,3},{1,2,6},{4,1,5},{5,2,4},{1,9,1},{7,8,10},{0,4,2},{7,2,8}};
        int result = findCheapestPrice(n, flights, src, dst, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
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


