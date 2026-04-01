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


// so what we are doing here is simplifying the tictactoe board.
// There are 3 rows, 3 columns and two diagonals, one diagonal up and
// another diagonal down.
//
// We don't actually have to track the matrix, just the sum of the
// values on a per col and per row basis as we go.  We either add or
// reduce by one the total for the row or column as we advance.  When
// we are done, if the row count is 3 (or -3) then we have 3 of that
// particular symbol, so that player won.
//
// For the down diagonals, if row & col are equal then they are on the
// NW->SE diagonal.  If the row and column add up to 2, then they are
// on the NE->SW diagonal.

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

        if (rows[row] == 3 || cols[col] == 3 || down == 3 || up == 3)
            return "A";
        if (rows[row] == -3 || cols[col] == -3 || down == -3 || up == -3)
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
