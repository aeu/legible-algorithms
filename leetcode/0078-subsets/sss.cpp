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


void dumpValues(std::vector<int> values)
{
    for(auto curr : values )
    {
        std::cout << curr << ", " ;
    }
    std::cout << std::endl;
}

// standard backtracking pattern
//
// setup
//    retval which will contain all possible subsets
//    the current path (solution) being built
//
// backtrack
//    no exit condition, just add the current path as we are taking all
//    push the next possible
//    backtrack, but increment the start point
//    pop


void backtrack(std::vector<int> &nums,
               int start_index,
               std::vector<int> &path,
               std::vector<std::vector<int>> &retval)
{
    retval.push_back(path);
    
    for(int index = start_index;index<nums.size();index++)
    {
        path.push_back( nums[index] );
        backtrack(nums,index+1,path,retval);
        path.pop_back();
    }
}

std::vector<std::vector<int>> subsets(std::vector<int>& nums)
{
    std::vector<std::vector<int>> retval;
    std::vector<int> path;
    backtrack(nums,0,path,retval);
    return retval;
}

int main(int argc, char **argv)
{
    std::cout << std::endl << "LC 78 - Subsets" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,3};
        std::vector<std::vector<int>> expected = {{},{1},{2},{1,2},{3},{1,3},{2,3},{1,2,3}};
        std::vector<std::vector<int>> result = subsets(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    {
        std::vector<int> nums  = {0};
        std::vector<std::vector<int>> expected = {{},{0}};
        std::vector<std::vector<int>> result = subsets(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
        //        std::cout << " (expected " << expected << ", got " << result << ")\n";
    }
    return 0;
}

