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

std::vector<std::vector<int>> doWork(int n)
{
    std::vector<std::vector<int>> retval(n,std::vector<int>(n,0));

    int row = n / 2;
    int col = n / 2; 

    // clockwise starting south.  s, w, n, e
    int dr[4] = {  1,  0, -1,  0 };
    int dc[4] = {  0, -1,  0,  1 };

    int increment = 1;
    int index = 0;
    int total = 0;


    int direction = 0;
    int step_increment = 1;
    int steps = 1;
    int change_count = 0;

    total++;
    while(total < (n*n) )
    {
        row += dr[direction%4];
        col += dc[direction%4];
        retval[row][col] = total;
        steps--;
        if( steps == 0 )
        {
            steps = step_increment;
            direction++;
            change_count++;
            if( change_count % 2 != 0 )
                step_increment++;
        }
        total++;
    }
    
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "BTCI - 28.3 Spiral Order" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<std::vector<int>> expected = {
            { 16, 17, 18, 19, 20 },
            { 15,  4,  5,  6, 21 },
            { 14,  3,  0,  7, 22 },
            { 13,  2,  1,  8, 23 },
            { 12, 11, 10,  9, 24 }};
        std::vector<std::vector<int>> result = doWork(5);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}
