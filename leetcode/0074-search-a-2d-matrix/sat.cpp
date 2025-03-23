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
#include <unordered_set>
#include <unordered_map>

int elementAt(std::vector<std::vector<int>>& matrix, int index)
{
    int row = index / (int)matrix[0].size() ;
    int col = index % (int)matrix[0].size();
    //  std::cout << "r: " << row << " c: " << col << " R: " << matrix[row][col] << std::endl;
    return matrix[row][col];
}


bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
{
    int num_rows = matrix.size() ;
    int num_cols = matrix[0].size();
    if(( num_rows == 1 ) && ( num_cols == 1 ))
        return ( matrix[0][0] == target );
    int low=0;
    int high = ( num_rows * num_cols ) - 1;
    int mid;
    //    std::cout << "L: " << low << " H: " << high << std::endl;
    while( low <= high )
    {
        mid = low + ((high - low ) / 2 );
        int current = elementAt(matrix,mid);
        if( target == current )
            return true;
        else if( current < target )
            low = mid+1;
        else
            high = mid-1;
    }
    return false;
}


int main(int argc, char **argv)
{
    std::cout << "Leetcode 15 - 3Sum" << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> matrix = {{1,3}};
        int target = 3;
        bool expected = true;
        bool result = searchMatrix(matrix,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
        int target = 3;
        bool expected = true;
        bool result = searchMatrix(matrix,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
        int target = 13;
        bool expected = false;
        bool result = searchMatrix(matrix,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<std::vector<int>> matrix = {{1}};
        int target = 1;
        bool expected = true;
        bool result = searchMatrix(matrix,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
}
