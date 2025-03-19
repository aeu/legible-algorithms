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

int liveAt(std::pair<int,int> cell,
            std::vector<std::vector<int>>& board)
{
    int row = cell.first;
    int col = cell.second;
    if(( row < 0 )
       || ( col < 0 )
       || ( row >= board.size() )
       || ( col >= board[0].size() ))
        return 0;

    return board[row][col];
}

int liveNeighbourCount(std::pair<int,int> cell,
                        std::vector<std::vector<int>>& board)
{
    int row = cell.first;
    int col = cell.second;

    std::pair<int,int> n  = std::make_pair( row-1, col );
    std::pair<int,int> ne = std::make_pair( row-1, col+1 );
    std::pair<int,int> e  = std::make_pair( row,   col+1 );
    std::pair<int,int> se = std::make_pair( row+1, col+1 );
    std::pair<int,int> s  = std::make_pair( row+1, col );
    std::pair<int,int> sw = std::make_pair( row+1, col-1 );
    std::pair<int,int> w  = std::make_pair( row,   col-1 );
    std::pair<int,int> nw = std::make_pair( row-1, col-1 );

    int live_neighbour_count =
        
        liveAt(n , board ) 
        + liveAt(ne, board )
        + liveAt(e , board ) 
        + liveAt(se, board )
        + liveAt(s , board ) 
        + liveAt(sw, board )
        + liveAt(w , board ) 
        + liveAt(nw, board )
        ;
    //    std::cout << "LNC is : " << live_neighbour_count << " at " << row << "," << col << std::endl;
    
    return live_neighbour_count;
}


void gameOfLife(std::vector<std::vector<int>>& board)
{
    std::vector<std::vector<int>> new_board ( board.size(), std::vector<int>( board[0].size(), 0 ));
    for(int row=0;row<board.size();row++)
    {
        for(int col=0;col<board[0].size();col++)
        {
            int current = liveAt(std::make_pair(row,col),board);
            int lnc = liveNeighbourCount(std::make_pair(row,col),board);
            int new_state = current;
            if( current == 1 )
            {
                if( lnc < 2 )
                    new_state = 0;
                else if ( lnc <= 3 )
                    new_state = 1;
                else
                    new_state = 0;
            }
            else
            {
                if( lnc == 3 )
                    new_state = 1;
            }
            new_board[row][col] = new_state;
        }
    }
    for(int row=0;row<board.size();row++)
    {
        for(int col=0;col<board[0].size();col++)
        {
            board[row][col] = new_board[row][col];
        }
    }
}



int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::vector<std::vector<int>> matrix   = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
        std::vector<std::vector<int>> expected = {{0,0,0},{1,0,1},{0,1,1},{0,1,0}};
        gameOfLife(matrix);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == matrix ? "Pass" : "Fail")  << std::endl;
        //                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> matrix   = {{1,1},{1,0}};
        std::vector<std::vector<int>> expected = {{1,1},{1,1}};
        gameOfLife(matrix);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == matrix ? "Pass" : "Fail")  << std::endl;
        //                  << " (expected " << expected << ", got " << result << ")\n";
    }
    return test_case;
}
