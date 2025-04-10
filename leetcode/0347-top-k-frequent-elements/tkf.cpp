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
#include <algorithm>
#include <limits.h>

struct pairLess {
    bool operator()(const std::pair<int,int> &lhs, const std::pair<int,int> &rhs)
    {
        return lhs.second < rhs.second;
    }
};

std::vector<int> topKFrequent(std::vector<int>& nums, int k)
{
    std::vector<int> retval;
    std::unordered_map<int,int> count;
    for( auto curr : nums )
    {
        count[curr]++;
    }
    std::priority_queue<std::pair<int,int>, std::vector<std::pair<int,int>>, pairLess> topheap;
    for(auto it: count )
    {
        topheap.push( { it.first,it.second });
    }
    while( ! topheap.empty() )
    {
        if( k == 0 )
            break;
        k--;
        std::pair<int,int> curr = topheap.top();
        topheap.pop();
        retval.push_back( curr.first );
    }
    std::cout << std::endl;
    
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "347. Top K Frequent Elements" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,1,1,2,2,3};
        int k = 2;
        std::vector<int> result = topKFrequent(nums, k);
        std::vector<int> expected = {1,2};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {1};
        int k = 1;
        std::vector<int> result = topKFrequent(nums, k);
        std::vector<int> expected = {1};
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
