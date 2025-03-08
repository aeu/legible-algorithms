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
#include <queue>

// m = rows
// n = columns

std::pair<int,int> getNorth(int row, int column, int m, int n )
{
    if( row > 0 )
        return { row - 1 , column };
    return { -1,-1};
}
    
std::pair<int,int> getSouth(int row, int column, int m, int n )
{
    if( row < m - 1 )
        return { row + 1 , column };
    return { -1,-1};
}
    
std::pair<int,int> getEast(int row, int column, int m, int n )
{
    if( column < n - 1 )
        return { row, column+1 };
    return { -1,-1};
}
std::pair<int,int> getWest(int row, int column, int m, int n )
{
    if( column > 0 )
        return { row, column-1 };
    return { -1,-1};
}
    
struct IslandHop {
    int island_id;
    int row;
    int col;
};

int isVisited(std::vector<std::vector<int>> &visited, int row, int column)
{
    if( visited[row][column] != 0 )
    {
        return visited[row][column];
    }
    return 0;
}

void markAsVisited(std::vector<std::vector<int>> &visited, int row, int column,int island_id)
{
    visited[row][column] = island_id;
}


void exploreIsland(std::vector<std::vector<char>>& grid,
                   std::vector<std::vector<int>> &visited,
                   int island_id,
                   int row_index,
                   int col_index )
{
    int num_rows = grid.size();
    int num_cols = grid[0].size();

    std::queue<IslandHop> hop_queue;
    IslandHop start ;
    start.island_id = island_id;
    start.row = row_index;
    start.col = col_index;
    hop_queue.push( start );
    while( ! hop_queue.empty() )
    {
        IslandHop current = hop_queue.front();
        hop_queue.pop();
        markAsVisited( visited, current.row, current.col, current.island_id );

        std::pair<int,int> north = getNorth( current.row, current.col, num_rows, num_cols );
        if( north.first != -1 )
        {
            if(( grid[north.first][north.second] == '1') && ( ! isVisited( visited, north.first, north.second ) ))
            {
                markAsVisited( visited, north.first, north.second, current.island_id );
                hop_queue.push({island_id,north.first,north.second});
            }
        }
        std::pair<int,int> south = getSouth( current.row, current.col, num_rows, num_cols );
        if( south.first != -1 )
        {
            if((grid[south.first][south.second] == '1')&&( ! isVisited( visited, south.first, south.second ) ))
            {
                markAsVisited( visited, south.first, south.second, current.island_id );
                hop_queue.push({island_id,south.first,south.second});
            }
        }
        std::pair<int,int> east = getEast( current.row, current.col, num_rows, num_cols );
        if( east.first != -1 )
        {
            if((grid[east.first][east.second] == '1')&&( ! isVisited( visited, east.first, east.second ) ))
            {
                markAsVisited( visited, east.first, east.second, current.island_id );
                hop_queue.push({island_id,east.first,east.second});
            }
        }
        std::pair<int,int> west = getWest( current.row, current.col, num_rows, num_cols );
        if( west.first != -1 )
        {
            if((grid[west.first][west.second] == '1')&&( ! isVisited( visited, west.first, west.second ) ))
            {
                markAsVisited( visited, west.first, west.second, current.island_id );
                hop_queue.push({island_id,west.first,west.second});
            }
        }
    }
}
        
int numIslands(std::vector<std::vector<char>>& grid)
{
    int num_rows = grid.size();
    if( num_rows == 0 )
        return -1;
    
    int num_cols = grid[0].size();
    if( num_cols == 0 )
        return -1;
    
    int island_count = 1;
    std::vector<std::vector<int>> visited(num_rows, std::vector<int>(num_cols, 0 ));
    for(int row_index = 0; row_index<grid.size();row_index++)
    {
        for(int col_index = 0; col_index<grid[row_index].size();col_index++)
        {
            if( grid[row_index][col_index] == '1' )
            {
                if( ! isVisited (visited,row_index,col_index ))
                {
                    island_count++;
                    exploreIsland( grid, visited, island_count, row_index,col_index);
                }                
            }
        }
    }
    return island_count -1;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode 0200 - Number of Islands" << std::endl;
    {
        std::vector<std::vector<char>> grid =
            {{ '1','1','1','1','0' },
             { '1','1','0','1','0' },
             { '1','1','0','0','0' },
             { '0','0','0','0','0' }};
        int num_islands = numIslands( grid );
        int expected = 1;
        if( num_islands == expected )
        {
            std::cout << "pass" << std::endl;
        }
        else
        {
            std::cout << "fail. expected : " << expected << " got : " << num_islands << std::endl;
        }
    }
    {
        std::vector<std::vector<char>> grid =
           {{ '1','1','0','0','0' },
            { '1','1','0','0','0' },
            { '0','0','1','0','0' },
            { '0','0','0','1','1' }};
        int num_islands = numIslands( grid );
        int expected = 3;
        if( num_islands == expected )
        {
            std::cout << "pass" << std::endl;
        }
        else
        {
            std::cout << "fail. expected : " << expected << " got : " << num_islands << std::endl;
        }
    }

    
}
