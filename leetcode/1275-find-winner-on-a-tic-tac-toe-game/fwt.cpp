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


std::string tictactoe(std::vector<std::vector<int>>& moves)
{
    std::string retval = "Draw";

    std::vector<int> rows (3,0);
    std::vector<int> cols (3,0);
    int down = 0;
    int up   = 0;

    int flipper = 1;
    
    for(const auto current_move : moves )
    {
        int row = current_move[0];
        int col = current_move[1];
        rows[row] += flipper;
        cols[col] += flipper;
        if( row == col )
            down += flipper;
        if(( row + col ) == 2 )
            up += flipper;

        for( const auto current_row : rows )
        {
            if( current_row == 3 )
                return "A";
            if( current_row == -3 )
                return "B";
        }
        
        for( const auto current_col : cols )
        {
            if( current_col == 3 )
                return "A";
            if( current_col == -3 )
                return "B";
        }
        if(( down == 3 ) || ( up == 3 ))
            return "A";
        if(( down == -3 ) || ( up == -3 ))
            return "B";
        flipper *= -1;
    }
    if( moves.size() < 9 )
        return "Pending";
    return "Draw";
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "1275-find-winner-on-a-tic-tac-toe-game" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> moves  = {{0,0},{2,0},{1,1},{2,1},{2,2}};
        std::string expected = "A";
        std::string result = tictactoe(moves);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::vector<int>> moves  = {{0,0},{1,1},{0,1},{0,2},{1,0},{2,0}};
        std::string expected = "B";
        std::string result = tictactoe(moves);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<std::vector<int>> moves  = {{0,0},{1,1},{2,0},{1,0},{1,2},{2,1},{0,1},{0,2},{2,2}};
        std::string expected = "Draw";
        std::string result = tictactoe(moves);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
