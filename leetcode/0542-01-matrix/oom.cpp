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


bool isValid(std::pair<int,int> pos)
{
    if(( pos.first == -1 ) || ( pos.second == -1 ))
        return false;
    return true;
}

std::pair<int,int> getNorth(int row,int col, std::vector<std::vector<int>>& mat)
{
    if( row == 0 )
        return { -1, -1 };
    return { row - 1 , col };
}

std::pair<int,int> getSouth(int row,int col, std::vector<std::vector<int>>& mat)
{
    if( row >= mat.size() - 1 )
        return { -1, -1 };
    return { row + 1 , col };
}

std::pair<int,int> getEast(int row,int col, std::vector<std::vector<int>>& mat)
{
    if( col >= mat[0].size() - 1 )
        return { -1, -1 };
    return { row , col + 1 };
}

std::pair<int,int> getWest(int row,int col, std::vector<std::vector<int>>& mat)
{
    if( col == 0 )
        return { -1, -1 };
    return { row , col -1 };
}

struct dfs_info
{
    int depth;
    int row;
    int col;
    int origin_row;
    int origin_col;
};


bool dfs( dfs_info di,
          std::vector<std::vector<int>>& mat,
          std::vector<std::vector<int>>& seen,
          std::vector<std::vector<int>>& retval)
{
    std::pair<int,int> next = getNorth(di.row,di.col,mat);
    if( isValid(next) )
    {
        if( mat[next.first][next.second] == 0 )
        {
            retval[di.origin_row][di.origin_col] = std::min(retval[di.origin_row][di.origin_col], di.depth ); 
        }
        else
        {
            if( seen[next.first][next.second] == 0 )
            {
                seen[next.first][next.second] = 1;
                dfs( { di.depth+1,next.first,next.second,di.origin_row,di.origin_col }, mat, seen,retval );
            }
        }
    }
    next = getSouth(di.row,di.col,mat);
    if( isValid(next) )
    {
        if( mat[next.first][next.second] == 0 )
        {
            retval[di.origin_row][di.origin_col] = std::min(retval[di.origin_row][di.origin_col], di.depth ); 
        }
        else
        {
            if( seen[next.first][next.second] == 0 )
            {
                seen[next.first][next.second] = 1;
                dfs( { di.depth+1,next.first,next.second,di.origin_row, di.origin_col }, mat, seen,retval );
            }
        }
    }
    next = getEast(di.row,di.col,mat);
    if( isValid(next) )
    {
        if( mat[next.first][next.second] == 0 )
        {
            retval[di.origin_row][di.origin_col] = std::min(retval[di.origin_row][di.origin_col], di.depth ); 
        }
        else
        {
            if( seen[next.first][next.second] == 0 )
            {
                seen[next.first][next.second] = 1;
                dfs( { di.depth+1,next.first,next.second,di.origin_row,di.origin_col }, mat, seen,retval );
            }
        }
    }
    next = getWest(di.row,di.col,mat);
    if( isValid(next) )
    {
        if( mat[next.first][next.second] == 0 )
        {
            retval[di.origin_row][di.origin_col] = std::min(retval[di.origin_row][di.origin_col], di.depth ); 
        }
        else
        {
            if( seen[next.first][next.second] == 0 )
            {
                seen[next.first][next.second] = 1;
                dfs( { di.depth+1,next.first,next.second,di.origin_row,di.origin_col }, mat, seen,retval );
            }
        }
    }
    return true;
}

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat)
{
    std::vector<std::vector<int>> retval( mat.size(), std::vector<int>( mat[0].size(), 0 ));
    for(int row = 0; row < mat.size(); row++)
    {
        for(int col = 0; col < mat[0].size(); col++)
        {
            retval[row][col] = mat[row][col];
        }
    }
    for(int row = 0; row < mat.size(); row++)
    {
        for(int col = 0; col < mat[0].size(); col++)
        {
            if( mat[row][col] == 1 )
            {
                std::vector<std::vector<int>> seen ( mat.size(), std::vector<int>( mat[0].size(), 0 ));
                retval[row][col] = INT_MAX;
                dfs({1,row,col,row,col},mat,seen,retval);
            }
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> mat  = {{0,0,0},{0,1,0},{0,0,0}};
        std::vector<std::vector<int>> expected = {{0,0,0},{0,1,0},{0,0,0}};
        std::vector<std::vector<int>> result = updateMatrix(mat);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<std::vector<int>> mat  = {{0,1,0,1,1},{1,1,0,0,1},{0,0,0,1,0},{1,0,1,1,1},{1,0,0,0,1}};
        std::vector<std::vector<int>> expected = {{0,1,0,1,2},{1,1,0,0,1},{0,0,0,1,0},{1,0,1,1,1},{1,0,0,0,1}};
        std::vector<std::vector<int>> result = updateMatrix(mat);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}



