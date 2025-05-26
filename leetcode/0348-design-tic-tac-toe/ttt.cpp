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


class TicTacToe {
public:
    int N;
    std::vector<std::vector<int>> board;
    TicTacToe(int n) : board( n, std::vector<int> ( n, 0 ))
    {
        N=n;
    }
    
    int move(int row, int col, int player)
    {
        bool win = true;
        board[row][col] = player;
        const auto &curr = board[row];
        for(const auto cell : curr )
        {
            if( cell != player )
            {
                win = false;
                break;
            }
        }
        if( win == true )
            return player;
        win = true;
        for(int index=0;index<N;index++)
        {
            if( board[index][col] != player )
            {
                win = false;
                break;
            }
        }
        if( win == true )
            return player;

        if( row == col )
        {
            win = true;
            for(int index=0;index<N;index++)
            {
                if( board[index][index] != player )
                {
                    win = false;
                    break;
                }
            }
            if( win == true )
                return player;
        }

        if( ( row + col ) == ( N - 1 ))
        {
            win = true;
            for(int index=0;index<N;index++)
            {
                if( board[index][N-index-1] != player )
                {
                    win = false;
                    break;
                }
            }
            if( win == true )
                return player;
        }
        return 0;
    }
};

int main(int argc, char **argv)
{
    std::cout << std::endl << "0348-design-tic-tac-toe" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3};
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
