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


void dumpValues(std::vector<int> values)
{
    std::cout << "[" ;
    for(auto curr : values )
    {
        std::cout << curr << ", " ;
    }
    std::cout << "]" << std::endl;
}

void backtrack(std::vector<int> &nums,
               int start_index,
               std::vector<int> &path,
               std::vector<std::vector<int>> &retval)
{
    retval.push_back(path);

    for(int index=start_index;index<nums.size();index++)
    {
        if( (index > start_index ) && (nums[index] == nums[index-1] ))
            continue;
        path.push_back(nums[index]);
        backtrack(nums,index+1,path,retval);
        path.pop_back();
    }
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
{
    std::vector<std::vector<int>> retval;
    std::vector<int> path;
    std::sort(nums.begin(),nums.end());
    backtrack(nums,0,path,retval);
    return retval;
}


int main(int argc, char **argv)
{
    std::cout << std::endl << "LC90 - Subsets II" << std::endl << std::endl;
    int test_case = 1;
    {
        std::vector<int> nums  = {1,2,2};
        std::vector<std::vector<int>> expected = {{},{1},{1,2},{1,2,2},{2},{2,2}};
        std::vector<std::vector<int>> result = subsetsWithDup(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    {
        std::vector<int> nums  = {0};
        std::vector<std::vector<int>> expected = {{},{0}};
        std::vector<std::vector<int>> result = subsetsWithDup(nums);
        std::cout << std::endl;
        std::cout << "Test case : " << test_case++ << " : " << (expected == result ? "Pass" : "Fail")  << std::endl;
    }
    return 0;
}
