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



bool isValid(int row, int col, std::vector<std::vector<char>>& board)
{
    if(( row < 0 )
       || ( row >= board.size() )
       || ( col < 0 )
       || ( col >= board[0].size()))
        return false;
    return true;
}

std::vector<std::vector<int>> directions =
    {
        { -1,  0 }, // north
        {  1,  0 }, // south
        {  0,  1 }, // east
        {  0, -1 }  // west
    };

// standard backtrack.  we build a seen and pass it in, along with the word and the current
// index into the word
//
// backtrack
//     exit out if the current char isn't the next char in the word
//
//     pick the next char based on cardinals, if not seen
//     backtrack, updating the candidate to the next char in the word
//        if found, return out
//     pop

bool backtrack(std::vector<std::vector<char>>& board,
               std::vector<std::vector<int>>& seen,
               int row,
               int col,
               std::string &word,
               int word_index)
{
    if( board[row][col] != word[word_index] )
        return false;
    
    if( word_index == word.length() -1 )
        return true;
    
    seen[row][col] = 1;
    for( auto curr : directions )
    {
        int nrow = row + curr[0];
        int ncol = col + curr[1];
        if(( isValid( nrow,ncol,board )) && (seen[nrow][ncol] == 0))
        {
            bool found = backtrack( board,seen,nrow,ncol,word,word_index+1 );
            if( found )
                return true;
        }
    }
    seen[row][col] = 0;
    return false;
}

bool exist(std::vector<std::vector<char>>& board,
           std::string word)
{
    std::map<char,int> counts;
    for(int row = 0;row<board.size();row++)
    {
        for(int col = 0; col < board[0].size(); col++)
        {
            counts[board[row][col]]++;
        }
    }
    for( auto curr : word )
    {
        counts[curr]--;
        if( counts[curr] < 0 )
            return false;
    }


    bool found = false;
    for(int row = 0;row<board.size();row++)
    {
        for(int col = 0; col < board[0].size(); col++)
        {
            if( board[row][col] == word[0] )
            {
                std::vector<std::vector<int>> seen ( board.size(), std::vector<int>( board[0].size(), 0 ));
                seen[row][col] = 1;
                found = backtrack(board,seen,row,col,word,0);
                if( found == true )
                    return true;
            }
        }
    }
    return found;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC79 - Word Search" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        std::string word = "ABCCED";
        bool expected = true;
        bool result = exist(board,word);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        std::string word = "SEE";
        bool expected = true;
        bool result = exist(board,word);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
        std::string word = "ABCB";
        bool expected = false;
        bool result = exist(board,word);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}

