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

std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
    // first initialize empty in-degree structure
    std::unordered_map<int,int> in_degree;
    for(int index=0;index<numCourses;index++)
    {
        in_degree[index] = 0;
    }

    // then build the graph
    std::unordered_map<int,std::vector<int>> graph;
    for(auto curr : prerequisites )
    {
        int course = curr[0];
        int prereq = curr[1];
        graph[prereq].push_back(course);
        in_degree[course]++;
    }
    // queue up all the courses that don't have dependencies
    std::queue<int> bfs_queue;
    for( auto it : in_degree )
    {
        if( it.second == 0 )
            bfs_queue.push( it.first );
    }
    std::vector<int> schedule;
    // now start processing them.
    while( ! bfs_queue.empty() )
    {
        int taken = bfs_queue.front();
        bfs_queue.pop();
        schedule.push_back(taken);
        // free up whatever courses will be freed when we take this one.
        auto it = graph.find(taken);
        if( it != graph.end() )
        {
            for( auto unlocked : it->second)
            {
                in_degree[unlocked]--;
                if( in_degree[unlocked] <= 0 )
                    bfs_queue.push(unlocked);
            }
        }
    }
    if( schedule.size() == numCourses )
        return schedule;
    std::vector<int> empty;
    return empty;
        
}



int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        int numCourses = 2;
        std::vector<std::vector<int>> prerequisites = {{1,0}};
        std::vector<int> result = findOrder(numCourses, prerequisites);
        std::vector<int> expected = {0,1};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        int numCourses = 4;
        std::vector<std::vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
        std::vector<int> result = findOrder(numCourses, prerequisites);
        std::vector<int> expected = {0,2,1,3};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        int numCourses = 1;
        std::vector<std::vector<int>> prerequisites = {};
        std::vector<int> result = findOrder(numCourses, prerequisites);
        std::vector<int> expected = {0};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
