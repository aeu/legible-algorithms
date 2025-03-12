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

        std::cout << "q: " << index << " " << qstart << " -> " << qend << std::endl;
        if(( graph.find(qstart) == graph.end() ) || ( graph.find(quend) == graph.end()))
        {
            //            queries.push_back( -1 );
            continue;
        }

        dpath query = { qstart, 1.0 };
        visited.insert( query.current_node );
        squeue.push( query );
        while( ! squeue.empty() )
        {
            query = squeue.front();
            squeue.pop();
            auto git = graph.find( query.current_node );
            if( git == graph.end() )
            {
                //                queries.push_back(-1);
            }
            else
            {
                //                if( git.second[
            }
        }
        
    }
    std::vector<double> retval;
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
            {{"a","c"},{"b","a"},{"a","e"},{"x","x"}};
        std::vector<double> expected = { 6.0,0.5,-1.0,1.0,-1.0};
        std::vector<double> calculated = calcEquation( equations, values, queries );
        // std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
        //           << " (expected " << expected << ", got " << result << ")\n";
    }
}
