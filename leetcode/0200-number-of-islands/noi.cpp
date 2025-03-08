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


void bfs(std::vector<std::vector<char>>& grid,
         std::vector<std::vector<int>> &visited,
         int island_id,
         int row_index,
         int col_index )
{
}

void exploreIsland(std::vector<std::vector<char>>& grid,
                   std::vector<std::vector<int>> &visited,
                   int island_id,
                   int row_index,
                   int col_index )
{
    std::queue<IslandHop> hop_queue;
    IslandHop start ;
    start.island_id = island_id;
    start.row = row_index;
    start.col = col_index;
    hop_queue.push_back( start );
    while( ! hop_queue.empty() )
    {
        IslandHop current = hop_queue.front();
        hop_queue.pop();
        markAsVisited
        
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
        std::vector<char> current_row = grid[row_index];
        for(int col_index = 0; col_index<current_row.size();col_index++)
        {
            if( current_row[col_index] == '1' )
            {
                if( ! isVisited (row_index,col_index ))
                {
                    island_count++;
                    exploreIsland( grid, visited, island_count, row_index,col_index);
                }                
            }
        }
    }
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
        numIslands( grid );
    }

    
}
