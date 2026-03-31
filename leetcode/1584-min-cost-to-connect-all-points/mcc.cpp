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


struct CheapestToConnect {
    // pair is ( cost to connect, node number )
    bool operator()(const std::pair<int,int> &lhs,
               const std::pair<int,int> &rhs)
    {
        return lhs.first > rhs.first;
    }
};

int manhattanDistance(int xi, int yi, int xj, int yj)
{
    return abs(xi-xj) + abs(yi-yj);
}

int minCostConnectPoints(std::vector<std::vector<int>>& points)
{
    int running_cost = 0;
    std::vector<int> min_costs( points.size(), INT_MAX );
    min_costs[0] = 0;
    std::vector<int> visited( points.size(), 0 );

    // here I make a priority queue that stores pairs of ints, in a
    // vector, and makes a min heap using the function cheapest to
    // connect.  The top will be cheapest known connection to the
    // current tree
    std::priority_queue<std::pair<int,int>,
                        std::vector<std::pair<int,int>>,
                        CheapestToConnect> candidates;

    // initialize the minimum cost to connect each node to the tree,
    // which initially contains only node 0

    for(int index=1;index<points.size();index++)
    {
        min_costs[index] = manhattanDistance( points[0][0], points[0][1],
                                              points[index][0], points[index][1] );
    }
    // push into the queue a pair consisting of the current best-known
    // cost to connect to each node to the tree
    for(int index=0;index<min_costs.size();index++)
    {
        candidates.push( { min_costs[index], index });
    }
    // repeatedly take the cheapest candidate edge that connects a new
    // node to the growing tree.  mark that node as visited (i.e. add
    // it to the tree), accumulate its connection cost, and then
    // update the min_cost array to all the remaining nodes with the
    // possibly cheaper connection costs through this new node
    while( ! candidates.empty() )
    {
        auto candidate = candidates.top();
        candidates.pop();
        int cindex = candidate.second; 
        if( visited[cindex] == 1 )
            continue;
        visited[cindex] = 1;
        running_cost += candidate.first;

        for(int index=0;index<points.size();index++)
        {
            int cost_from_curr = manhattanDistance( points[cindex][0], points[cindex][1],
                                                    points[index][0], points[index][1] );
            // the node has not been visited and we found a cheaper way to
            // connect it through the current node, update its minimum cost
            // and push the new candidate into the heap
            if(( visited[index] == 0 ) && ( min_costs[index] > cost_from_curr ))
            {
                // update the min cost to get to that node to the cost
                // from current
                min_costs[index] = cost_from_curr;
                candidates.push( { cost_from_curr, index } );
            }
        }
    }
    return running_cost;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1584 - Min Cost to Connect All Points" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
        int expected = 20;
        int result = minCostConnectPoints(points);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> points = {{3,12},{-2,5},{-4,1}};
        int expected = 18;
        int result = minCostConnectPoints(points);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
