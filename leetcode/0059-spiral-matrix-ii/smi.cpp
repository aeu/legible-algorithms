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

std::vector<std::vector<int>> cardinals = {
    {  0,  1 },
    {  1,  0 },
    {  0, -1 },
    { -1,  0 }}; 


bool isValid(int row, int col, int n)
{
    if( row < 0 )
        return false;
    if( col < 0 )
        return false;
    if( row >= n )
        return false;
    if( col >= n )
        return false;
    return true;
}

std::vector<std::vector<int>> generateMatrix(int n)
{
    std::vector<std::vector<int>> retval(n, std::vector<int>(n,0));
    int total = n*n;
    int current = 1;
    int row = 0;
    int col = -1;
    int nrow = 0;
    int ncol = 0;
    int cindex = 0;
    while( current <= total )
    {
        nrow = row + cardinals[0][0];
        ncol = col + cardinals[0][1];
        while( ( isValid ( nrow,ncol,n )) && ( retval[nrow][ncol] == 0 ))
        {
            retval[nrow][ncol] = current++;
            row =  nrow; col = ncol;
            nrow = row + cardinals[0][0];
            ncol = col + cardinals[0][1];
        }
        // unset because we went invalide.
        nrow = row;
        ncol = col;

        nrow = row + cardinals[1][0];
        ncol = col + cardinals[1][1];
        while( ( isValid ( nrow,ncol,n )) && ( retval[nrow][ncol] == 0 ))
        {
            retval[nrow][ncol] = current++;
            row =  nrow; col = ncol;
            nrow = row + cardinals[1][0];
            ncol = col + cardinals[1][1];
        }

        nrow = row;
        ncol = col;

        nrow = row + cardinals[2][0];
        ncol = col + cardinals[2][1];
        while( ( isValid ( nrow,ncol,n )) && ( retval[nrow][ncol] == 0 ))
        {
            retval[nrow][ncol] = current++;
            row =  nrow; col = ncol;
            nrow = row + cardinals[2][0];
            ncol = col + cardinals[2][1];
        }

        // unset because we went invalide.
        nrow = row;
        ncol = col;

        nrow = row + cardinals[3][0];
        ncol = col + cardinals[3][1];
        while( ( isValid ( nrow,ncol,n )) && ( retval[nrow][ncol] == 0 ))
        {
            retval[nrow][ncol] = current++;
            row =  nrow; col = ncol;
            nrow = row + cardinals[3][0];
            ncol = col + cardinals[3][1];
        }
    }
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "" << std::endl << std::endl;
    int test_case = 1;
    {
        int n = 3;
        std::vector<std::vector<int>> rmat = generateMatrix(n);
        for(const auto &curr : rmat )
        {
            std::cout << "[";
            for(const auto inner : curr )
            {
                std::cout << inner << " " ;
            }
            std::cout << "]";
        }
        std::cout << std::endl;
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        int n = 1;
        std::vector<std::vector<int>> rmat = generateMatrix(n);
        for(const auto &curr : rmat )
        {
            std::cout << "[";
            for(const auto inner : curr )
            {
                std::cout << inner << " " ;
            }
            std::cout << "]";
        }
        std::cout << std::endl;
        int expected = 0;
        int result = 0;
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
