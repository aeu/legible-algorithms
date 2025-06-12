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


int findKthLargest(std::vector<int>& nums, int k)
{
    std::priority_queue<int,std::vector<int>,std::greater<int>> pqueue;
    for(const auto &current_number : nums )
    {
        pqueue.push(current_number);
        if( pqueue.size() > k )
            pqueue.pop();
    }

    return pqueue.top();
}

int main(int argc, char **argv)
{


    std::cout << std::endl << "0215-kth-largest-element-in-an-array" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums = { 3,2,1,5,6,4};
        int k = 2;
        int expected = 5;
        int result = findKthLargest(nums, k );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums = { 3,2,3,1,2,4,5,5,6};
        int k = 4;
        int expected = 4;
        int result = findKthLargest(nums, k );
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail") 
                  << " (expected " << expected << ", got " << result << ")\n";
    }
}
