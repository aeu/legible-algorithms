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
#include <set>
#include <limits.h>

int doWork()
{
    return 1;
}

std::vector<std::pair<int,int>> directions =
    { { -1,  0 }, // north
      {  1,  0 }, // south
      {  0,  1 }, // east
      {  0, -1 }  // west
    };

struct BfsNode {
    int row;
    int col;
    int steps;
};

bool isValid(int row, int col, 
             std::vector<std::vector<char>> &G)
{
    int num_rows  = G.size();
    int num_cols  = G[0].size();
    if( ( row < 0 ) || ( row >= num_rows ) || ( col < 0 ) || ( col >= num_cols ))
        return false;
    return true;
}

int getSecondsRequired(int R, int C, std::vector<std::vector<char>> &G)
{
    int min_steps = INT_MAX;
    std::queue<BfsNode> bfs_queue;
    std::vector<std::vector<int>> seen(R, std::vector<int>(C,0));
    for(int row = 0;row<R;row++)
    {
        for(int col=0;col<C;col++)
        {
            if( G[row][col] == 'S' )
            {
                seen[row][col] = 1;
                bfs_queue.push( { row,col,0 });
                break;
            }
        }
    }

    std::set<char> portals_seen;
    
    while( ! bfs_queue.empty() )
    {
        BfsNode now = bfs_queue.front();
        bfs_queue.pop();
        char current = G[now.row][now.col];
        if(  current == 'E' )
        {
            min_steps = std::min( min_steps, now.steps );
            continue;
        }

        if(( current >= 'a' ) && ( current <= 'z' ))
        {
            if( portals_seen.count(current) == 0 )
            {
                portals_seen.insert(current);
                for(int ir = 0; ir < R; ir++)
                {
                    for(int ic=0;ic<C;ic++)
                    {
                        if( G[ir][ic] == current )
                        {
                            if( seen[ir][ic] == 0 )
                            {
                                seen[ir][ic] = 1;
                                bfs_queue.push( { ir, ic, now.steps+1 });
                            }
                        }
                    }
                }
            }
        }
        
        for(auto dir : directions )
        {
            int row = now.row + dir.first;
            int col = now.col + dir.second;
            if( isValid( row,col,G ))
            {
                if( seen[row][col] == 0 )
                {
                    seen[row][col] = 1;
                    
                    if( G[row][col] == '#' )
                        continue;
                    if(( G[row][col] == 'E' )
                       || ( G[row][col] == '.' )
                       || ((G[row][col] >= 'a' && G[row][col] <= 'z') ))
                    {
                        bfs_queue.push( { row, col, now.steps + 1 } );
                        continue;
                    }
                }
            }
        }
    }
    if( min_steps == INT_MAX )
        return -1;
    return min_steps;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        int R = 3;
        int C = 3;
        std::vector<std::vector<char>> G =
            {{'.','E','.'},
             {'.','#','E'},
             {'.','S','#'}};
        int expected = 4;
        int result = getSecondsRequired(R, C, G);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int R = 3;
        int C = 4;
        std::vector<std::vector<char>> G =
            {{'a','.','S','a'},
             {'#','#','#','#'},
             {'E','b','.','b'}};
        int expected = -1;
        int result = getSecondsRequired(R, C, G);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int R = 3;
        int C = 4;
        std::vector<std::vector<char>> G =
            {{'a','S','.','b'},
             {'#','#','#','#'},
             {'E','b','.','a'}};
        int expected = 4;
        int result = getSecondsRequired(R, C, G);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        int R = 1;
        int C = 9;
        std::vector<std::vector<char>> G =
            {{'x','S','.','.','x','.','.','E','x'}};
        int expected = 3;
        int result = getSecondsRequired(R, C, G);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
