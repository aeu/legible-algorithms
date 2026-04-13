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

int backtrack(std::map<std::pair<int,int>,int> &memo,
              std::vector<int>& nums,
              int target,
              int running_total,
              int index)
{
    // first check to see if we have used every number in the input array.
    if( index == nums.size() )
    {
        // and then check to see if the running total is the goal
        if( running_total == target )
            // it was, return 1 (as this is one path to that goal)
            return 1;
        // return 0
        return 0;
    }

    auto miter = memo.find({ index,running_total} );
    if( miter != memo.end() )
        return miter->second;
    
    // grab the next number in the sequence.  since we can either add or subtract it
    // for the next step, do both.
    int next_number = nums[index];
    int plus  = backtrack(memo, nums, target, running_total + next_number, index+1);
    int minus = backtrack(memo, nums, target, running_total - next_number, index+1);
    int num_ways = plus + minus;
    // store our current result in the memo table
    memo[{index,running_total}] = num_ways;
    return num_ways;
}

int findTargetSumWays(std::vector<int>& nums, int target)
{
    std::map<std::pair<int,int>,int> memo;
    int count = backtrack(memo,nums,target,0,0);
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
