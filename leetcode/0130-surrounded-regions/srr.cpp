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

// m = rows
// n = columns

std::pair<int,int> getNorth(std::vector<std::vector<char>>& board, int m, int n )
{
    if( m == 0 )
        return std::make_pair(-1,-1);
    return std::make_pair(m-1,n);
}
std::pair<int,int> getSouth(std::vector<std::vector<char>>& board, int m, int n )
{
    if( m + 1 == board.size() )
        return std::make_pair(-1,-1);
    return std::make_pair(m+1,n);
}
std::pair<int,int> getWest(std::vector<std::vector<char>>& board, int m, int n )
{
    if( n == 0 )
        return std::make_pair(-1,-1);
    return std::make_pair(m,n-1);
}
std::pair<int,int> getEast(std::vector<std::vector<char>>& board, int m, int n )
{
    if( n + 1 == board[0].size() )
        return std::make_pair(-1,-1);
    return std::make_pair(m,n+1);
}

char getSquare(std::vector<std::vector<char>>& board, int m, int n )
{
    if(( m >= 0 ) && ( m < board.size() ) && ( n >= 0 ) && ( n < board[0].size() ))
        return board[m][n];
    return '-';
}

char getSquare(std::vector<std::vector<char>>& board, std::pair<int,int> pos )
{
    return getSquare(board, pos.first, pos.second );
}

struct IslandHop {
    //    int safe; // -1 unknown
    int row;
    int col;
};




void solve(std::vector<std::vector<char>>& board)
{
    // first mark all the os that are safe
    
    std::map<std::pair<int,int>, int> safe_os;
    std::map<std::pair<int,int>, int> visited;
    std::queue<IslandHop> bfs_queue;
    for(int row = 0;row<board.size();row++)
    {
        for(int col=0;col<board[row].size();col++)
        {
            char current = board[row][col];
            if( current == 'O' )
            {
                if( row == 0 )
                {
                    visited[{row,col}] = 1;
                    safe_os[ std::make_pair(row,col) ] = 1;
                    bfs_queue.push({row,col});
                }
                else if (row==board.size()-1)
                {
                    visited[{row,col}] = 1;
                    safe_os[ std::make_pair(row,col) ] = 1;
                    bfs_queue.push({row,col});
                }
                else if( ( col == 0 ) || ( col == board[row].size()-1))
                {
                    visited[{row,col}] = 1;
                    safe_os[ std::make_pair(row,col) ] = 1;
                    bfs_queue.push({row,col});
                }
            }
        }
    }

    while( ! bfs_queue.empty() )
    {
        IslandHop current = bfs_queue.front();
        bfs_queue.pop();

        std::pair<int,int> npair = getNorth( board, current.row, current.col );
        std::pair<int,int> spair = getSouth( board, current.row, current.col );
        std::pair<int,int> epair = getEast( board, current.row, current.col );
        std::pair<int,int> wpair = getWest( board, current.row, current.col );

        char nchar = getSquare(board,npair);
        char schar = getSquare(board,spair);
        char echar = getSquare(board,epair);
        char wchar = getSquare(board,wpair);

        if(( nchar == 'O' ) && visited.find( npair ) == visited.end() )
        {
            visited[npair] = 1;
            safe_os[npair] = 1;
            bfs_queue.push({npair.first,npair.second});
        }
        if(( schar == 'O' ) && visited.find( spair ) == visited.end() )
        {
            visited[spair] = 1;
            safe_os[spair] = 1;
            bfs_queue.push({spair.first,spair.second});
        }
        if(( echar == 'O' ) && visited.find( epair ) == visited.end() )
        {
            visited[epair] = 1;
            safe_os[epair] = 1;
            bfs_queue.push({epair.first,epair.second});
        }
        if(( wchar == 'O' ) && visited.find( wpair ) == visited.end() )
        {
            visited[wpair] = 1;
            safe_os[wpair] = 1;
            bfs_queue.push({wpair.first,wpair.second});
        }
    }

    for(int row = 0;row<board.size();row++)
    {
        for(int col=0;col<board[row].size();col++)
        {
            char current = board[row][col];
            if( current == 'O' )
            {
                if( safe_os.find({row,col}) == safe_os.end() )
                {
                    board[row][col] = 'X';
                }
            }
        }
    }
}


int main(int argc, char **argv)
{
    {
        std::vector<std::vector<char>> board =
        {{'X','X','X','X'},
            {'X','O','O','X'},
            {'X','X','O','X'},
            {'X','O','X','X'}};
    }
}
