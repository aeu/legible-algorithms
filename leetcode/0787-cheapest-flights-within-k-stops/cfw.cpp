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

int dfs(int dst,
        int stops_left,
        int cost,
        std::vector<int> &path,
        std::unordered_set<int> &seen,
        std::unordered_map<int,std::vector<std::pair<int,int>>> &graph,
        std::unordered_map<int, std::unordered_map<int,int>> &memo)
{
    int last_city = path.back();
    if( last_city == dst )
        return cost;

    if( stops_left == 0 )
        return INT_MAX;


    // memo[dst][stops_left-1] = lowest_cost;
    auto oiter = memo.find(last_city); 
    if( oiter != memo.end() )
    {
        auto iiter = oiter->second.find(stops_left);
        if( iiter != oiter->second.end() )
        {
            return iiter->second;
        }
    }
    
    auto it = graph.find( last_city );
    int lowest_cost = INT_MAX;
    if( it != graph.end() )
    {
        for(auto curr : it->second )
        {
            int destination_city = curr.first;
            // // if( seen.count( destination_city  ) == 0 )
            // // {
            // //     seen.insert(destination_city);
            path.push_back( destination_city );
            int flight_cost = dfs( dst, stops_left - 1 , cost + curr.second, path,seen, graph,memo );
            lowest_cost = std::min(flight_cost, lowest_cost);
            path.pop_back();
            //     seen.erase(destination_city);
            // }
        }
    }
    if( lowest_cost != INT_MAX )
        memo[last_city][stops_left] = lowest_cost;
    return lowest_cost;
}
        
int findCheapestPrice(int n, std::vector<std::vector<int>>& flights, int src, int dst, int k)
{
    std::unordered_map<int, std::unordered_map<int,int>> memo;
    std::unordered_map<int,std::vector<std::pair<int,int>>> graph;
    for( auto curr : flights )
    {
        graph[curr[0]].push_back({ curr[1], curr[2] });
    }
    int cheapest = INT_MAX;
    std::unordered_set<int> seen;
    std::vector<int> path;
    path.push_back(src);
    int cost = dfs( dst, k + 1 , 0, path, seen, graph, memo );
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
    {
        int n = 15;
        int src = 1;
        int dst = 4;
        int k = 10;
        int expected = 169;
        std::vector<std::vector<int>> flights =
            {{10,14,43},{1,12,62},{4,2,62},{14,10,49},
             {9,5,29},{13,7,53},{4,12,90},{14,9,38},{11,2,64},
             {2,13,92},{11,5,42},{10,1,89},{14,0,32},{9,4,81},
             {3,6,97},{7,13,35},{11,9,63},{5,7,82},{13,6,57},
             {4,5,100},{2,9,34},{11,13,1},{14,8,1},{12,10,42},
             {2,4,41},{0,6,55},{5,12,1},{13,3,67},{3,13,36},
             {3,12,73},{7,5,72},{5,6,100},{7,6,52},{4,7,43},
             {6,3,67},{3,1,66},{8,12,30},{8,3,42},{9,3,57},
             {12,6,31},{2,7,10},{14,4,91},{2,3,29},{8,9,29},
             {2,11,65},{3,8,49},{6,14,22},{4,6,38},{13,0,78},
             {1,10,97},{8,14,40},{7,9,3},{14,6,4},{4,8,75},{1,6,56}};
        int result = findCheapestPrice(n, flights, src, dst, k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}


