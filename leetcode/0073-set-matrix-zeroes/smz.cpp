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


void setZeroes(std::vector<std::vector<int>> &matrix)
{
    std::vector<std::pair<int,int>> found_zeroes;
    for(int row = 0;row<matrix.size();row++)
    {
        for(int col = 0; col<matrix[0].size();col++)
        {
            if( matrix[row][col] == 0 )
            {
                found_zeroes.push_back( std::make_pair(row,col));
            }
        }
    }
    std::cout << "zeroes found " << found_zeroes.size() << std::endl;
    for(auto current : found_zeroes )
    {
        std::fill( matrix[current.first].begin(), matrix[current.first].end(),0);
        for(int i = 0;i<matrix.size();i++)
        {
            matrix[i][current.second] = 0;
        }
    }
}    


int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::vector<std::vector<int>> matrix   = {{1,1,1},{1,0,1},{1,1,1}};
        std::vector<std::vector<int>> expected = {{1,0,1},{0,0,0},{1,0,1}};
        setZeroes(matrix);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == matrix ? "Pass" : "Fail")  << std::endl;
        //                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> matrix   = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
        std::vector<std::vector<int>> expected = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
        setZeroes(matrix);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == matrix ? "Pass" : "Fail")  << std::endl;
        //                  << " (expected " << expected << ", got " << result << ")\n";
    }
    return test_case;
}
