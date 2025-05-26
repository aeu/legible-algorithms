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
    std::vector<int> rows;
    std::vector<int> cols;
    int down_diag;
    int up_diag;
    TicTacToe(int n) :
        rows(n,0),
        cols(n,0),
        down_diag(0),
        up_diag(0)
    {
        N=n;
    }
    
    int move(int row, int col, int player)
    {
        int add = player;
        if( player == 2 )
            add = -1;

        rows[row] += add;
        if( abs( rows[row] ) == N )
            return player;
        
        cols[col] += add;
        if( abs ( cols[col] ) == N )
            return player;
        
        if( row == col )
        {
            down_diag += add;
            if( abs( down_diag ) == N )
                return player;
        }
        if( ( row + col ) == ( N - 1 ) )
        {
            up_diag += add;
            if( abs ( up_diag ) == N )
                return player;
        }
        return 0;
    }
};

int main(int argc, char **argv)
{
    std::cout << std::endl << "0N48-design-tic-tac-toe" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,N};
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
