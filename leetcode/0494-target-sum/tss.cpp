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

int dfs(std::unordered_map<int, std::unordered_map<int,int>> &memo,
        std::vector<int>& nums,
        int target,
        int total,
        int index)
{
    if( index == nums.size() )
    {
        if( total == target )
            return 1;
        return 0;
    }

    if( memo.count(index) && memo[index].count(total) )
        return memo[index][total];

    
    int plus  = dfs(memo,nums,target,total+nums[index],index+1);
    int minus = dfs(memo,nums,target,total-nums[index],index+1);
    int num_ways = plus + minus;
    memo[index][total] = num_ways;
    return num_ways;
}

int findTargetSumWays(std::vector<int>& nums, int target)
{
    std::unordered_map<int, std::unordered_map<int,int>> memo;
    int count = dfs(memo,nums,target,0,0);
    return count;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "0494-target-sum" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,1,1,1,1};
        int target = 3;
        int expected = 5;
        int result = findTargetSumWays(nums,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    {
        std::vector<int> nums  = {1};
        int target = 1;
        int expected = 1;
        int result = findTargetSumWays(nums,target);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        std::cout << " (expected " << expected << ", got " << result << ")\n";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    return 0;
}
