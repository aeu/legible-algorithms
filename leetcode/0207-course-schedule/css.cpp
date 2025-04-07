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

bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
{
    std::map<int,int> in_degrees;
    std::map<int,std::vector<int>> graph;
    int classes_taken = 0;

    // initialize requirements for all nodes (to zero)
    for(int index=0;index<numCourses;index++)
    {
        in_degrees[index] = 0;
    }
    
    // for all classes, set the pre-req {0,1} means to take 0 you hae to take 1
    for(auto current : prerequisites )
    {
        graph[current[1]].push_back(current[0]);
        in_degrees[current[0]]++;
    }

    // queue up all the classes that don't have any dependencies
    std::queue<int> class_queue;
    for( auto curr : in_degrees )
    {
        if( curr.second == 0 )
        {
            class_queue.push( curr.first );
        }
    }

    while( ! class_queue.empty() )
    {
        int taken = class_queue.front();
        class_queue.pop();
        classes_taken++;
        // find the class that depended on the one we just took
        auto it = graph.find( taken );
        if( it != graph.end() )
        {
            for( auto curr : it->second )
            {
                in_degrees[curr]--;
                // if they have no dependencies, queue them up.
                if( in_degrees[curr] <= 0 )
                {
                    class_queue.push( curr );
                }
            }
        }
    }
    // see if we took all the ones we were supposed to
    return ( classes_taken == numCourses );
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "LC207 - Course Schedule" << std::endl << std::endl;
    int test_case = 1;
    {
        int numCourses = 5;
        std::vector<std::vector<int>> prerequisites = {{1,4},{2,4},{3,1},{3,2}};
        bool expected = true;
        bool result = canFinish(numCourses, prerequisites);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
    {
        int numCourses = 2;
        std::vector<std::vector<int>> prerequisites = {{1,0}};
        bool expected = true;
        bool result = canFinish(numCourses, prerequisites);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int numCourses = 2;
        std::vector<std::vector<int>> prerequisites = {{1,0},{0,1}};
        bool expected = false;
        bool result = canFinish(numCourses, prerequisites);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
