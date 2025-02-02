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


int freshOrangeCount(std::vector<std::vector<int>>& grid)
{
    int foc = 0;
    for(auto row : grid )
    {
        for( auto orange : row )
        {
            if( orange == 1 )
                foc++;
        }
    }
    return foc;
}

typedef struct OrangeLocation
{
    int row;
    int col;
} OrangeLocation;

OrangeLocation up(OrangeLocation current)
{
    OrangeLocation retval;
    retval.row = current.row-1;
    retval.col = current.col;
    return retval;
}

OrangeLocation down(OrangeLocation current)
{
    OrangeLocation retval;
    retval.row = current.row+1;
    retval.col = current.col;
    return retval;
}
OrangeLocation left(OrangeLocation current)
{
    OrangeLocation retval;
    retval.row = current.row;
    retval.col = current.col-1;
    return retval;
}
OrangeLocation right(OrangeLocation current)
{
    OrangeLocation retval;
    retval.row = current.row;
    retval.col = current.col+1;
    return retval;
}

int markAsRotten(std::vector<std::vector<int>>& grid,
                  OrangeLocation current)
{
    int num_rows = grid.size();
    int num_cols = grid[0].size();
    if(( current.row >= 0 ) && ( current.row < num_rows ))
    {
        if(( current.col >= 0 ) && ( current.col < num_cols ))
        {
            int orange = grid[current.row][current.col];
            if( orange == 1 )
            {
                grid[current.row][current.col] = 2;
                return 1;
            }
        }
    }
    return 0;
}

int minuteTick(std::vector<std::vector<int>>& grid)
{
    std::vector<OrangeLocation> rottens;
    int num_rows = grid.size();
    int num_cols = grid[0].size();
    for(int row = 0; row<num_rows;row++)
    {
        for(int col=0; col<num_cols;col++)
        {
            std::vector<int> orange_row = grid[row];
            int orange = orange_row[col];
            if( orange == 2 )
            {
                OrangeLocation pos;
                pos.row = row;
                pos.col = col;
                rottens.push_back(pos);
            }
        }
    }
    int changed = 0;
    for(auto rotten : rottens )
    {
        changed += markAsRotten( grid, up( rotten ));
        changed += markAsRotten( grid, down( rotten ));
        changed += markAsRotten( grid, left( rotten ));
        changed += markAsRotten( grid, right( rotten ));
    }
    return changed;
}

int orangesRotting(std::vector<std::vector<int>>& grid)
{
    int fresh_orange_count = freshOrangeCount(grid);
    if( fresh_orange_count == 0 )
        return 0;

    int tick_count = 0;
    int oranges_changed = minuteTick( grid );
    tick_count++;
    while( oranges_changed != 0 )
    {
        oranges_changed = minuteTick( grid );
        tick_count++;
    }
    if( freshOrangeCount(grid) == 0 )
        return tick_count-1;
    return -1;
}

int main(int argc, char **argv)
{
    std::cout << "Leetcode #994 - Rotting Oranges" << std::endl << std::endl;
    {
        std::vector<std::vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
        std::cout << "Example 1" << std::endl;
        int ora = orangesRotting(grid);
        std::cout << "Minutes : " << ora << std::endl;
    }
    {
        std::vector<std::vector<int>> grid = {{2,1,1},{0,1,1},{1,0,1}};
        std::cout << "Example 2" << std::endl;
        int ora = orangesRotting(grid);
        std::cout << "Minutes : " << ora << std::endl;
    }
    {
        std::vector<std::vector<int>> grid =  {{0,2}};
        std::cout << "Example 3" << std::endl;
        int ora = orangesRotting(grid);
        std::cout << "Minutes : " << ora << std::endl;
    }
    return -1;
}
