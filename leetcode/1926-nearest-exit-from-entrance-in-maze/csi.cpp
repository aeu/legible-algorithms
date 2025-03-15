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

std::pair<int,int> getNorth(std::pair<int,int> current, std::vector<std::vector<char>> &maze)
{
    if( current.first <= 0 )
        return std::make_pair(-1,-1);
    std::pair<int,int> new_north = std::make_pair( current.first - 1, current.second );
    if( maze[new_north.first][new_north.second] == '+' )
        return std::make_pair(-1,-1);
    return new_north;
}

std::pair<int,int> getSouth(std::pair<int,int> current, std::vector<std::vector<char>> &maze)
{
    if( current.first >= maze.size() - 1  )
        return std::make_pair(-1,-1);
    std::pair<int,int> new_south = std::make_pair( current.first + 1, current.second );
    if( maze[new_south.first][new_south.second] == '+' )
        return std::make_pair(-1,-1);
    return new_south;
}
std::pair<int,int> getEast(std::pair<int,int> current, std::vector<std::vector<char>> &maze)
{
    if( current.second >= maze[0].size() - 1)
        return std::make_pair(-1,-1);
    std::pair<int,int> new_east =  std::make_pair( current.first, current.second + 1 );
    if( maze[new_east.first][new_east.second] == '+' )
        return std::make_pair(-1,-1);
    return new_east;
}
std::pair<int,int> getWest(std::pair<int,int> current, std::vector<std::vector<char>> &maze)
{
    if( current.second <= 0 )
        return std::make_pair(-1,-1);
    std::pair<int,int> new_west = std::make_pair( current.first, current.second - 1 );
    if( maze[new_west.first][new_west.second] == '+' )
        return std::make_pair(-1,-1);
    return new_west;
}

bool isValid(std::pair<int,int> coords )
{
    if(( coords.first == -1 ) || ( coords.second == - 1 ))
        return false;
    return true;
}

bool isExit(std::pair<int,int> coords, std::vector<std::vector<char>> &maze, std::pair<int,int> entrance)
{
    if( ! isValid( coords ))
        return false;
    if(( coords.first == entrance.first ) && ( coords.second == entrance.second ))
        return false;
    if( maze[coords.first][coords.second] == '+' )
        return false;
    if( ( coords.first == 0 )     || ( coords.first == maze.size() - 1 )
        || ( coords.second == 0 ) || ( coords.second == maze[0].size() - 1 ))
        return true;
    return false;
}

struct ExitStep {
    int num_steps;
    std::pair<int,int> position;
};

int nearestExit(std::vector<std::vector<char>> &maze,
                std::vector<int> &entrance)
{
    std::map<std::pair<int,int>,int> visited;
    std::queue<ExitStep> bqueue;
    int distance_to_exit = INT_MAX;

    ExitStep start_step;
    start_step.num_steps = 0;
    std::pair<int,int> entpair = std::make_pair( entrance[0],entrance[1] );
    start_step.position = entpair;
      
    bqueue.push( start_step );
    visited[ { entrance[0],entrance[1] } ] = 1;
    
    while( ! bqueue.empty() )
    {
        ExitStep current = bqueue.front();
        bqueue.pop();
        if( isExit( current.position, maze, entpair ))
        {
            distance_to_exit = std::min( distance_to_exit, current.num_steps );
            continue;
        }
        std::pair<int,int> north = getNorth( current.position, maze );
        std::pair<int,int> south = getSouth( current.position, maze );
        std::pair<int,int> east  = getEast( current.position, maze );
        std::pair<int,int> west  = getWest( current.position, maze );

        if( isValid( north ) )
        {
            if( visited.find( north ) == visited.end() )
            {
                visited[north] = 1;
                bqueue.push( { current.num_steps + 1 , north } );
            }
        }
        if( isValid( south ) )
        {
            if( visited.find( south ) == visited.end() )
            {
                visited[south] = 1;
                bqueue.push( { current.num_steps + 1 , south } );
            }
        }
        if( isValid( east ) )
        {
            if( visited.find( east ) == visited.end() )
            {
                visited[east] = 1;
                bqueue.push( { current.num_steps + 1 , east } );
            }
        }
        if( isValid( west ) )
        {
            if( visited.find( west ) == visited.end() )
            {
                visited[west] = 1 ;
                bqueue.push( { current.num_steps + 1 , west } );
            }
        }
    }
    if( distance_to_exit != INT_MAX)
        return distance_to_exit;
    return -1;
}


int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::vector<std::vector<char>> maze = 
        {{'+','+','.','+'},
         {'.','.','.','+'},
         {'+','+','+','.'}};
        std::vector<int> entrance = {1,2};
        int expected = 1;
        int result = nearestExit(maze,entrance);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<char>> maze = 
        {{'+','+','+'},
         {'.','.','.'},
         {'+','+','+'}};
        std::vector<int> entrance = {1,0};
        int expected = 2;
        int result = nearestExit(maze,entrance);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<char>> maze = 
        {{'.','+'}};
        std::vector<int> entrance = {0,0};
        int expected = -1;
        int result = nearestExit(maze,entrance);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<char>> maze = 
        {{'.','+','.'}};
        std::vector<int> entrance = {0,2};
        int expected = -1;
        int result = nearestExit(maze,entrance);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
}
