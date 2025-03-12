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

struct dpath {
    std::string current_node;
    double weight;
};

std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations,
                                 std::vector<double>& values,
                                 std::vector<std::vector<std::string>>& queries)
{
    std::vector<double> retval;
    std::unordered_map<std::string, std::vector<std::pair<std::string, double>>> graph;
    for(int index=0;index<values.size();index++)
    {
        std::vector<std::string> &current_equation = equations[index];
        std::string start = current_equation[0];
        std::string end   = current_equation[1];
        double current_value = values[index];
        graph[start].push_back({ end, current_value });
        graph[end].push_back({ start, (1/current_value) });
        std::cout << "from " << start << " to : " << end << " weight : " << current_value << std::endl;
    }

    for(int index=0;index<queries.size();index++)
    {
        std::unordered_set<std::string> visited;
        std::queue<dpath> squeue;
        std::vector<std::string> &current_query = queries[index];
        std::string qstart = current_query[0];
        std::string qend   = current_query[1];
        bool found = false;

        std::cout << "q: " << index << " " << qstart << " -> " << qend << std::endl;
        
        if(( graph.find(qstart) == graph.end() ) || ( graph.find(qend) == graph.end()))
        {
            retval.push_back( -1 );
            continue;
        }

        if( qstart == qend )
        {
            retval.push_back( 1 );
            continue;
        }
        
        dpath query = { qstart, 1.0 };
        visited.insert( query.current_node );
        squeue.push( query );
        while( ! squeue.empty() )
        {
            query = squeue.front();
            squeue.pop();
            if( query.current_node == qend )
            {
                retval.push_back( query.weight );
                found = true;
                break;
            }
            else
            {
                auto it = graph.find( query.current_node );
                if( it != graph.end())
                {
                    for(auto edge : it->second )
                    {
                        std::string next_node = edge.first;
                        if( visited.find( next_node ) == visited.end())
                        {
                            visited.insert( next_node );
                            double new_weight = query.weight * edge.second;
                            squeue.push({next_node, new_weight});
                        }
                    }
                }
            }
        }
        if( found == false )
            retval.push_back( -1 );
        
    }
    return retval;
}


int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::vector<std::vector<std::string>> equations = {
            {"a","b"},{"b","c"}};
        std::vector<double> values = { 2.0, 3.0 };
        std::vector<std::vector<std::string>> queries =
            {{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}};
        std::vector<double> expected = { 6.0,0.5,-1.0,1.0,-1.0};
        std::vector<double> calculated = calcEquation( equations, values, queries );
        for(auto curr : calculated )
        {
            std::cout << curr << ", " ;
        }
        std::cout << std::endl;
        // std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
        //           << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<std::string>> equations = {
            {"a","b"},{"b","c"},{"bc","cd"}};
        std::vector<double> values = { 1.5,2.5,5.0 };
        std::vector<std::vector<std::string>> queries =
            {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}};
        std::vector<double> expected = { 3.75,0.4,5.0,0.2};
        std::vector<double> calculated = calcEquation( equations, values, queries );
        for(auto curr : calculated )
        {
            std::cout << curr << ", " ;
        }
        std::cout << std::endl;
        // std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
        //           << " (expected " << expected << ", got " << result << ")\n";
    }
}
