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
#include <set>

void rotate(std::vector<std::vector<int>> &matrix)
{
    int num_rows = matrix.size();
    int num_cols = matrix[0].size();
    for(int i = 0; i<num_rows;i++)
    {
        for(int j = i+1;j<num_cols;j++)
        {
            std::swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int i=0;i<num_rows;i++)
    {
        std::reverse(matrix[i].begin(),matrix[i].end());
    }
}

int main(int argc, char **argv)
{
    int test_case = 1;
    {
        std::vector<std::vector<int>> matrix   = { { 1,2,3 } , { 4,5,6} , { 7,8,9 }};
        std::vector<std::vector<int>> expected = { { 7,4,1}, {8,5,2},{9,6,3}};
        rotate(matrix);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == matrix ? "Pass" : "Fail") << std::endl;
        //                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> matrix   = { {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
        std::vector<std::vector<int>> expected = { {15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}};
        rotate(matrix);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == matrix ? "Pass" : "Fail") << std::endl;
        //                  << " (expected " << expected << ", got " << result << ")\n";
    }
}
