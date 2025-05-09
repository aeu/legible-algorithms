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


int flipFetch(int row, int col, std::vector<std::vector<int>>& matrix)
{
    int num_rows = matrix.size();
    int num_cols = matrix[0].size();
    int frow = num_rows - row - 1;
    return matrix[frow][col];
}


bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix)
{
    std::unordered_map<int,int> lookups;
    int num_rows = matrix.size();
    int num_cols = matrix[0].size();
    for(int row = 0; row<num_rows;row++)
    {
        for( int col = 0; col<num_cols;col++)
        {
            int csum = row + col;
            int val  = flipFetch(row,col,matrix);
            auto lit = lookups.find( csum );
            if( lit == lookups.end() )
            {
                lookups[csum] = val;
            }
            else
            {
                int existing = lit->second;
                if( existing != val )
                    return false;
            }
        }
    }
    return true;
}
              

int main(int argc, char **argv)
{
    std::cout << std::endl << "0766-toeplitz-matrix" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> matrix = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
        bool expected = true;
        bool result = isToeplitzMatrix(matrix);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> matrix = {{1,2},{2,2}};
        bool expected = false;
        bool result = isToeplitzMatrix(matrix);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
