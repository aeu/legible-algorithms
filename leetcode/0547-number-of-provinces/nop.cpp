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


void dumpValues(std::vector<int> values )
{
    bool first_time = true;
    std::cout << "[" ;
    for( int current : values )
    {
        if( ! first_time )
            std::cout << ", ";
        std::cout << current;
        first_time = false;
    }
    std::cout << "]" << std::endl;
}

void dumpAdjacencyList(std::map<int, std::vector<int>> adjacency_list)
{
    for(auto current : adjacency_list )
    {
        std::cout << "City: " << current.first << " -> " ;
        std::vector<int> connections = current.second;
        for( auto conn : connections )
        {
            std::cout << conn << " ";
        }
        std::cout << std::endl;
    }
}

void dfs(int node,
         std::unordered_set<int> &visited,
         std::map<int, std::vector<int>> adjacency_list)
{
    visited.insert(node);
    std::vector<int> connections = adjacency_list.at(node);
    for(int connection : connections )
    {
        if( visited.find( connection ) == visited.end())
        {
            dfs(connection, visited, adjacency_list);
        }
    }
}

int countGroups(std::map<int, std::vector<int>> adjacency_list)
{
    int num_groups = 0;
    std::unordered_set<int> visited;
    for(auto list_pair : adjacency_list )
    {
        int current_node = list_pair.first;
        if( visited.find( current_node ) == visited.end())
        {
            dfs( current_node, visited, adjacency_list );
            num_groups++;
        }
    }
    return num_groups;
}


std::map<int, std::vector<int>> buildAdjacencyList(std::vector<std::vector<int>>& connection_matrix)
{
    std::map<int, std::vector<int>> adjacency_list;
    for(size_t city_index = 0; city_index < connection_matrix.size(); city_index++)
    {
        std::vector<int> city_connections = connection_matrix[city_index];
        for(size_t connection_index = 0; connection_index < city_connections.size(); connection_index++ )
        {
            if( city_connections[connection_index] == 1 )
            {
                adjacency_list[city_index].push_back(connection_index);
            }

        }
    }
    return adjacency_list;
}

int countProvinces(std::vector<std::vector<int>>& connection_matrix)
{
    std::map<int, std::vector<int>> adjacency_list = buildAdjacencyList(connection_matrix);
    dumpAdjacencyList( adjacency_list );
    int num_groups = countGroups(adjacency_list);
    return num_groups;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode #547 - Number of Provines" << std::endl << std::endl;
    {
        std::cout << "Example 1" << std::endl;
        std::vector<std::vector<int>> rooms = {{1,1,0},{1,1,0},{0,0,1}};
        int circle_num = countProvinces( rooms );
        std::cout << "Number of provinces : " << circle_num << std::endl << std::endl;
    }
    {
        std::cout << "Example 2" << std::endl;
        std::vector<std::vector<int>> rooms = {{1,0,0},{0,1,0},{0,0,1}};
        int circle_num = countProvinces( rooms );
        std::cout << "Number of provinces : " << circle_num << std::endl << std::endl;
    }
    return -1;
}
