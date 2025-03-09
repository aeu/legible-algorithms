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


std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
    std::vector<int> retval;
    std::unordered_map<int,std::vector<int>> graph;
    std::unordered_map<int,int> in_degrees;
    std::queue<int> n_queue;

    for( auto curr : prerequisites )
    {
        int course = curr[0];
        int prereq = curr[1];
        graph[prereq].push_back(course);
        in_degrees[course]++;
    }
    for(int index = 0;index<numCourses;index++)
    {
        if( in_degrees[index] == 0 )
            n_queue.push( index );
    }
    while( ! n_queue.empty() )
    {
        int current_course = n_queue.front();
        n_queue.pop();
        retval.push_back( current_course );

        auto it = graph.find( current_course );
        if( it != graph.end() )
        {
            for( int neighbour : it->second )
            {
                in_degrees[neighbour]--;
                if( in_degrees[neighbour] == 0 )
                    n_queue.push( neighbour);
            }
        }
    }
    if ( retval.size() == numCourses )
        return retval;
    std::vector<int> empty;
    return empty;
}



int main(int argc, char **argv)
{
    int test_case = 1;
    {
        int numCourses = 2;
        std::vector<std::vector<int>> prerequisites = {{1,0}};
        std::vector<int> expected = {0,1};
        std::vector<int> res = findOrder( numCourses, prerequisites );
        for(auto curr : res )
        {
            std::cout << curr << ", " ;
        }
        std::cout << std::endl;
        //       bool result = canFinish( numCourses, prerequisites);
        //   std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
        //        << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int numCourses = 4;
        std::vector<std::vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};
        std::vector<int> expected = {0,2,1,3};
        std::vector<int> res = findOrder( numCourses, prerequisites );
        for(auto curr : res )
        {
            std::cout << curr << ", " ;
        }
        std::cout << std::endl;
        //       bool result = canFinish( numCourses, prerequisites);
        //   std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
        //        << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int numCourses = 1;
        std::vector<std::vector<int>> prerequisites = {};
        std::vector<int> expected = {0};
        std::vector<int> res = findOrder( numCourses, prerequisites );
        for(auto curr : res )
        {
            std::cout << curr << ", " ;
        }
        std::cout << std::endl;
        //       bool result = canFinish( numCourses, prerequisites);
        //   std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
        //        << " (expected " << expected << ", got " << result << ")\n";
    }
}
