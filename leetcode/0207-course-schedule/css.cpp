// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82
//
#include <stdio.h>
#include <limits.h>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>


bool canBeTaken(int candidate,
                std::unordered_set<int> &untaken,
                std::unordered_map<int,std::vector<int>> &graph)
{
    auto rit = graph.find( candidate );
    if( rit == graph.end() )
    {
        return true;
    }
    std::vector<int> prereq_list = rit->second;
    for(auto current_prereq : prereq_list )
    {
        if( untaken.find( current_prereq ) != untaken.end())
        {
            return false;
        }
    }
    return true;
}

bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
    std::unordered_map<int,std::vector<int>> graph;
    std::vector<int> in_degree(numCourses, 0 );
    std::queue<int> c_queue;
    int taken_count = 0;
    
    for( auto current : prerequisites )
    {
        int course = current[0];
        int prereq = current[1];
        graph[prereq].push_back(course);
        in_degree[course]++;
    }

    for(int course=0;course<numCourses;course++)
    {
        if( in_degree[course] == 0 )
            c_queue.push( course );
    }

    while( ! c_queue.empty() )
    {
        int current = c_queue.front();
        c_queue.pop();
        taken_count++;

        for(int neighbour : graph[current] )
        {
            in_degree[neighbour]--;
            if( in_degree[neighbour] == 0 )
            {
                c_queue.push( neighbour );
            }
        }
    }
    return taken_count == numCourses;
}


int main(int argc, char **argv)
{
    int test_case = 1;
    {
        int numCourses = 2;
        std::vector<std::vector<int>> prerequisites = {{1,0}};
        bool expected = true;
        bool result = canFinish( numCourses, prerequisites);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int numCourses = 2;
        std::vector<std::vector<int>> prerequisites = {{1,0},{0,1}};
        bool expected = false;
        bool result = canFinish( numCourses, prerequisites);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int numCourses = 3;
        std::vector<std::vector<int>> prerequisites = {{1,0},{1,2},{0,1}};
        bool expected = false;
        bool result = canFinish( numCourses, prerequisites);
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    
}
