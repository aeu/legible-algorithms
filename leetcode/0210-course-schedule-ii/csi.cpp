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
    // First initialize empty in-degree structure.   This is the list of all
    // courses offered, with their dependencies.  Initialize to 0 because as of
    // now all we know is the number of courses.
    std::unordered_map<int,int> in_degree;
    for(int index=0;index<numCourses;index++)
    {
        in_degree[index] = 0;
    }

    // Now we build the graph of the data.  This is a list of all courses, and
    // for each course we have the classes that it is a pre-requisite for.
    // Finally for each course in the in degree structure, we increment the
    // number of prerequisites it has.

    std::unordered_map<int,std::vector<int>> graph;
    for(auto curr : prerequisites )
    {
        int course = curr[0];
        int prereq = curr[1];
        graph[prereq].push_back(course);
        in_degree[course]++;
    }
    // Now lets start up the BFS queue.  We first queue up all the courses that
    // don't have any dependencies that can be immediately taken.
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
        // For each course we take, find all the courses that will now become
        // available when this one is taken.  For each one, decrement the
        // in-degree count. If the in degree count is 0 (meaning that it can now
        // be taken freely) add it to the queue.
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
    // if we have been able to take all the courses, return that list.
    // Otherwise, return an empty vector.

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
