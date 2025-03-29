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


struct bfs_info
{
    int distance;
    int row;
    int col;
};


bool isValid(std::pair<int,int> pos, std::vector<std::vector<int>>& mat)
{
    if(( pos.first >= 0 ) && ( pos.first < mat.size() ) && ( pos.second >= 0 ) && ( pos.second < mat[0].size() ))
        return true;
    return false;
}

std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat)
{
    std::queue<bfs_info> bfs_queue;
    std::vector<std::vector<int>> seen ( mat.size(), std::vector<int>( mat[0].size(), 0 ));
    std::vector<std::vector<int>> retval( mat.size(), std::vector<int>( mat[0].size(), 0 ));
    for(int row = 0; row < mat.size(); row++)
    {
        for(int col = 0; col < mat[0].size(); col++)
        {
            retval[row][col] = mat[row][col];
            if( mat[row][col] == 0 )
            {
                seen[row][col] = 1;
                bfs_queue.push( { 1, row, col } );

            }
        }
    }

    std::vector<std::pair<int,int>> directions =
        {{ -1,  0 }, // north
         {  1,  0 }, // south
         {  0, -1 }, // east
         {  0,  1 }}; // west
    std::pair<int,int> next;
    while( ! bfs_queue.empty() )
    {
        bfs_info current = bfs_queue.front();
        bfs_queue.pop();
        for( auto current_direction : directions )
        {
            next.first  = current.row + current_direction.first;
            next.second = current.col + current_direction.second;
            if(( isValid(next,mat)) && ( seen[next.first][next.second] != 1 ))
            {
                retval[next.first][next.second] = current.distance;
                seen[next.first][next.second] = 1;
                bfs_queue.push({ current.distance + 1, next.first, next.second});
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



