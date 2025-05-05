// -*- Mode: c++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; -*-
//
//  red82 // software
//
//  This software may not be used or reproduced, in whole or in part,
//  without the express written permission of red82

#include <iostream>
#include <iomanip>
#include <optional>
#include <vector>
#include <queue>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <limits.h>


bool isValid(std::vector<std::vector<int>>& image,
             int row,
             int col)
{
    if(( row < 0 ) || ( col < 0 ) || ( row >= image.size() ) || ( col >= image[0].size()))
        return false;
    return true;
}

struct BfsInfo
{
    int row;
    int col;
    int old;
    int color;
};

std::vector<std::vector<int>> cardinals =
    {{ 1, 0},
     {-1, 0},
     { 0, 1},
     { 0,-1}};

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image,
                                        int sr,
                                        int sc,
                                        int color)
{
    std::vector<std::vector<int>> seen( image.size(), std::vector<int>(image[0].size()));
    std::vector<std::vector<int>> retval( image.size(), std::vector<int>(image[0].size()));
    int num_rows = image.size();
    int num_cols = image[0].size();
    for(int row = 0; row<num_rows;row++)
    {
        for(int col = 0; col<num_cols;col++)
        {
            retval[row][col] = image[row][col];
            seen[row][col] = 0;
        }
    }
        
    std::queue<BfsInfo> bqueue;
    seen[sr][sc] = 1;
    bqueue.push( { sr,sc,image[sr][sc],color } );
    while( ! bqueue.empty() )
    {
        BfsInfo curr = bqueue.front();
        bqueue.pop();
        if( retval[curr.row][curr.col] == curr.old )
        {
            if ( retval[curr.row][curr.col] != curr.color )
            {
                retval[curr.row][curr.col] = color;
            }
        }
        for( const auto &card : cardinals )
        {
            int nrow = curr.row + card[0];
            int ncol = curr.col + card[1];
            if( isValid( image,nrow,ncol ))
            {
                if( retval[nrow][ncol] == curr.old )
                {
                    if( seen[nrow][ncol] == 0 )
                    {
                        seen[nrow][ncol] = 1;
                        bqueue.push({nrow,ncol,curr.old,curr.color});
                    }
                }
            }
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "0733-flood-fill" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> image = {{0,0,0},{0,1,0}};
        int sr = 1;
        int sc = 1;
        int color = 2;
        std::vector<std::vector<int>> expected = {{0,0,0},{0,2,0}};
        std::vector<std::vector<int>> result = floodFill(image,sr,sc,color);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::vector<int>> image =
            {{1,1,1},{1,1,0},{1,0,1}};
        int sr = 1;
        int sc = 1;
        int color = 2;
        std::vector<std::vector<int>> expected =
            {{2,2,2},{2,2,0},{2,0,1}};
        std::vector<std::vector<int>> result = floodFill(image,sr,sc,color);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::vector<int>> image = {{0,0,0},{0,0,0}};
        int sr = 0;
        int sc = 0;
        int color = 0;
        std::vector<std::vector<int>> expected = {{0,0,0},{0,0,0}};
        std::vector<std::vector<int>> result = floodFill(image,sr,sc,color);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
