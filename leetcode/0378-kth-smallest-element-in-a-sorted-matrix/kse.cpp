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


int kthSmallest(std::vector<std::vector<int>>& matrix, int k) 
{
    return 0;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "leetcode/0378-kth-smallest-element-in-a-sorted-matrix" << std::endl << std::endl;
    int test_case = 1;
    {
        //  1  5  9
        // 10 11 13
        // 12 13 15
        //  1  5  9 10 11 12 13 13 15
        //  0  1  2  3  4  5  6  7  8

       
        std::vector<std::vector<int>> nums  = {{1,5,9},{10,11,13},{12,13,15}};
        int k = 8;
        int expected = 13;
        int result = kthSmallest(nums,k);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
