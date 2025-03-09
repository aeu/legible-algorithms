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
    std::unordered_set<int> untaken;
    //    std::unordered_set<int> taken;
    std::queue<int> c_queue;

    for( auto current : prerequisites )
    {
        graph[current[0]].push_back(current[1]);
    }

    for(int index=0;index<numCourses;index++)
    {
        untaken.insert( index );
    }

    bool did_push = false;
    while( ! untaken.empty() )
    {
        did_push = false;
        for( auto candidate : untaken )
        {
            if( canBeTaken( candidate, untaken, graph ))
            {
                did_push = true;
                c_queue.push( candidate );
            }
        }
        if( did_push == false )
            break;

        while( ! c_queue.empty () )
        {
            int current = c_queue.front();
            c_queue.pop();
            auto uit = untaken.find(current);
            if( uit != untaken.end() )
                untaken.erase(uit);
        }
    }
    if( untaken.empty() )
        return true;
    return false;
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
